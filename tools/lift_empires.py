#!/usr/bin/env python3
"""
lift_empires.py - lift AEPROG.EXE (Ancient Empires) to C with pcrecomp's lift16.

Model (MS C 5.x/6.x small-ish: one code segment, DGROUP separate, separate stack):
  * image-offset space: linear = seg*16 + off, relocations NOT applied (link-time
    segment values: code = 0x0000, DGROUP = 0x0FA3, stack = 0x1C50).
  * the whole C-runtime startup [0, first_func) is lifted as fn_00000 so its
    internal jumps stay labels; its call targets are also exposed as functions.
  * every function in work/functions.json is lifted individually.
  * work/misses.txt (written by the runtime after a run) feeds the next round:
    addresses the guest jumped/called to that no function covered.

Output: src/recomp/gen/recomp_NNN.c, recomp_all.h, recomp_dispatch.c

Usage: PCRECOMP_HOME=../pcrecomp python3 tools/lift_empires.py
"""
import json
import re
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HOME = os.environ.get("PCRECOMP_HOME") or os.path.join(ROOT, "..", "pcrecomp")
sys.path.insert(0, os.path.join(HOME, "tools", "disasm"))
sys.path.insert(0, os.path.join(HOME, "tools", "lift"))

from decode16 import Decoder, OpType  # noqa: E402
import lift16                          # noqa: E402
from lift16 import Lifter              # noqa: E402

HDR = 0x200
EXE = os.path.join(ROOT, "original", "AEPROG.EXE")
OUT = os.path.join(ROOT, "src", "recomp", "gen")
CHUNK = 50
LOAD_SEG = 0x1000                      # where the DOS loader puts the image (PSP is 0x0FF0)
LINK_CS = 0x0000                       # the code segment's link-time value (image space)
CODE_SEG = LINK_CS                     # symbolic name used in generated C: SEG_0000 (= LOAD_SEG at run time)

# Functions implemented natively in src/recomp/empires_impl.c instead of lifted.
OVERRIDES = {}


def jump_tables(data, insns, cs, offs):
    """Arms of each `jmp word cs:[bx+table]` -- a compiler switch.

    The table is a run of near offsets in the code segment; nothing names the
    arms but this one instruction. The preceding `cmp bx, N` / `jbe` bounds it;
    failing that, take entries while they still land on an instruction
    boundary of this function.  Returns {jmp address: [absolute arm addresses]}.
    (adapted from sp00nznet/dinopark tools/lift_full.py, MIT)
    """
    out = {}
    base = cs * 16
    for idx, ins in enumerate(insns):
        o = ins.op1
        if ins.mnemonic != 'jmp' or not o or o.type != OpType.MEM:
            continue
        if o.base != 'bx' or o.seg != 'cs':
            continue
        bound = bx_imm = cx_imm = None
        odisp = o.disp & 0xFFFF            # displacements print signed; wrap to the 16-bit offset
        for j in insns[max(0, idx - 10):idx]:
            if not (j.op1 and j.op1.type == OpType.REG16 and j.op2
                    and j.op2.type in (OpType.IMM8, OpType.IMM16)):
                continue
            reg = repr(j.op1)
            if j.mnemonic == 'cmp':
                bound = j.op2.disp + 1
            elif j.mnemonic == 'mov' and reg == 'bx':
                bx_imm = j.op2.disp
            elif j.mnemonic == 'mov' and reg == 'cx':
                cx_imm = j.op2.disp
        if bx_imm is not None and cx_imm and odisp == cx_imm * 2:
            bound, start = cx_imm, base + bx_imm + odisp
        else:
            start = base + odisp
        arms, tbl = [], start
        for k in range(bound if bound else 256):
            a = tbl + k * 2 + HDR
            if a + 2 > len(data):
                break
            t = base + int.from_bytes(data[a:a + 2], 'little')
            if t not in offs:
                break
            arms.append(t)
        if arms and (bound is None or len(arms) == bound):
            out[ins.address] = arms
        else:
            # Tolerant read: bx here is often already a byte offset (no shl),
            # so `cmp bx, N` bounds N/2+1 words. Stop at the first word that is
            # not an instruction boundary of this function.
            words = (bound - 1) // 2 + 1 if bound else 64
            arms2, tbl2 = [], base + odisp
            for k in range(words):
                a = tbl2 + k * 2 + HDR
                if a + 2 > len(data):
                    break
                t = base + int.from_bytes(data[a:a + 2], 'little')
                if t not in offs:
                    break
                arms2.append(t)
            if arms2:
                out[ins.address] = arms2
    return out


def load_relocs(data):
    """Image offsets of every MZ-relocated 16-bit word."""
    import struct
    nrel = struct.unpack_from('<H', data, 6)[0]
    roff = struct.unpack_from('<H', data, 0x18)[0]
    return {seg * 16 + off for off, seg in
            (struct.unpack_from('<2H', data, roff + 4 * i) for i in range(nrel))}


def decode_range(data, io, end):
    """Decode [io,end) and rewrite near call/jmp displacements so that
    io + disp is the wrap-correct 16-bit target (code lives in one segment)."""
    insns = Decoder(data[io + HDR:end + HDR], base_offset=io).decode_all()
    for ins in insns:
        o = ins.op1
        if ins.mnemonic in ("call", "jmp") and o and o.type == OpType.REL16:
            t = (io + o.disp) & 0xFFFF
            o.disp = t - io
    return insns


def flow_end(data, t, cap):
    """Where the function at t ends, by following its control flow: decode
    forward and stop after the first ret/retf/iret -- or unconditional jmp --
    that no earlier in-range forward branch jumps past. Bytes after that are
    data or another function. Branch targets outside [t, cap) are tail calls
    and do not extend the function."""
    try:
        insns = decode_range(data, t, cap)
    except Exception:
        return None
    reach = t
    for ins in insns:
        o = ins.op1
        is_br = (ins.mnemonic.startswith(('j', 'loop')) and o
                 and o.type in (OpType.REL8, OpType.REL16))
        if is_br:
            tgt = t + o.disp
            if t <= tgt < cap:
                reach = max(reach, tgt)      # includes this jmp's own target
        if ins.mnemonic == 'jmp' and is_br:
            if ins.offset >= reach:
                return ins.offset + ins.length          # nothing jumps past it
        elif ins.mnemonic in ('ret', 'ret far', 'retf', 'iret') and ins.offset >= reach:
            return ins.offset + ins.length
    return None



# ---- runtime-loaded video driver overlay -------------------------------------
# The EXE reserves cs:[0x39C, 0xAFA) for a graphics driver that the game
# decompresses from AE000.DAT at start-up (the bytes in the file are a stub).
# The recompiler cannot see code that does not exist until run time, so the
# loaded driver is captured once from a running game (work/overlay_vga.bin;
# the same bytes load for VGA and EGA) and lifted here as a second code set.
# Calls into the range go through ovl_call(), which checks the driver that is
# really in memory before running the lifted copy.
OVL_LO, OVL_HI = 0x39C, 0xAFA
OVL_SIG_LEN = 48


def overlay_functions(buf):
    """Entry points of the captured driver: its thunk table, its targets, the
    MS C prologues, and every near call target found while decoding."""
    def b(a):
        return buf[HDR + a]
    starts = set()
    a = OVL_LO
    while a < OVL_HI:
        if b(a) == 0xEB:
            t = a + 2 + (b(a + 1) - 256 if b(a + 1) >= 128 else b(a + 1))
        elif b(a) == 0xE9:
            t = (a + 3 + int.from_bytes(buf[HDR + a + 1:HDR + a + 3], "little", signed=True)) & 0xFFFF
        else:
            break
        if not (OVL_LO <= t < OVL_HI):
            break
        starts.add(a)
        starts.add(t)
        a += 3
    starts.add(a)                                  # first routine after the table
    for j in range(OVL_LO, OVL_HI - 2):
        if buf[HDR + j:HDR + j + 3] == b"\x55\x8b\xec":
            starts.add(j)
    for _ in range(8):                             # fixed point over call targets
        order = sorted(starts)
        new = set()
        for i, st in enumerate(order):
            en = order[i + 1] if i + 1 < len(order) else OVL_HI
            try:
                insns = decode_range(buf, st, en)
            except Exception:
                continue
            for ins in insns:
                o = ins.op1
                if ins.mnemonic == "call" and o and o.type == OpType.REL16:
                    t = (st + o.disp) & 0xFFFF
                    if OVL_LO <= t < OVL_HI and t not in starts:
                        new.add(t)
        if not new:
            break
        starts |= new
    order = sorted(starts)
    return [(f"ovl_{st:05X}", st, order[i + 1] if i + 1 < len(order) else OVL_HI)
            for i, st in enumerate(order)]


# Textual patches for idioms the dummy-return-address convention cannot express.
# The C startup (fn_0E65C) pops its return address into cs:[0xE656], builds the
# argv/envp arrays by lowering SP, then `jmp cs:[0xE656]`. Lifted calls push a
# dummy return word, so the saved value is meaningless; the jump is just a
# return that leaves SP lowered, which is exactly a C `return` here.
PATCHES = [
    ("recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, 0xE656)); return;",
     "return; /* jmp cs:[0xE656] == return to the caller, SP stays lowered */"),
]


def main():
    data = open(EXE, "rb").read()
    relocs = load_relocs(data)
    fmap = json.load(open(os.path.join(ROOT, "work", "functions.json")))["functions"]
    starts = {f["start"] - HDR for f in fmap}
    det_end = {f["start"] - HDR: f["end"] - HDR for f in fmap}
    first_det = min(starts)

    # ---- the C startup region [0, first_det) ---------------------------------
    call_tgts = set()
    forced = set()
    for ins in decode_range(data, 0, first_det):
        o = ins.op1
        t = None
        if ins.mnemonic == "call" and o and o.type == OpType.REL16:
            t = o.disp & 0xFFFF
        elif ins.mnemonic in ("call", "call far") and o and o.type == OpType.FAR:
            t = (o.far_seg * 16 + o.disp) & 0xFFFFF
        if t is None:
            continue
        if 0 < t < first_det:
            call_tgts.add(t)
        elif t not in starts and t < len(data) - HDR:
            forced.add(t)

    # ---- forced entry points from a previous run's dispatch misses -----------
    miss_path = os.path.join(ROOT, "work", "misses.txt")
    if os.path.exists(miss_path):
        for line in open(miss_path):
            line = line.strip()
            if line:
                t = int(line, 16)
                if t not in starts and t != 0xFFFF and 0 < t < len(data) - HDR:
                    forced.add(t)

    # ---- far/near call targets that are not yet functions ---------------------
    for s in sorted(starts):
        try:
            insns = decode_range(data, s, det_end[s])
        except Exception:
            continue
        for ins in insns:
            o = ins.op1
            if ins.mnemonic in ("call", "call far") and o and o.type == OpType.FAR:
                t = (o.far_seg * 16 + o.disp) & 0xFFFFF
                if 0 < t < first_det:
                    call_tgts.add(t)
                elif t not in starts and t < len(data) - HDR:
                    forced.add(t)
            elif ins.mnemonic == "call" and o and o.type == OpType.REL16:
                t = (s + o.disp) & 0xFFFF   # disp already wrap-corrected
                if 0 < t < first_det:
                    call_tgts.add(t)
                elif t not in starts and t < len(data) - HDR:
                    forced.add(t)

    # ---- the function list --------------------------------------------------
    # Boundaries: union of pcrecomp's detected starts, Ghidra's independent
    # procedure list (work/ghidra_functions.json), startup subroutines and
    # forced call/dispatch targets. Each function ends where the next known
    # start begins, so none can swallow a neighbour (or a thunk table).
    ghidra = set()
    gpath = os.path.join(ROOT, "work", "ghidra_functions.json")
    if os.path.exists(gpath):
        ghidra = {a for a in json.load(open(gpath))["starts"] if first_det <= a < len(data) - HDR}
    code_end = max(det_end.values())

    # A start that lands inside one of pcrecomp's function bodies is only
    # accepted if no branch inside that body crosses it. Ghidra (and a runtime
    # miss) sometimes name a loop head or a shared tail as a "function";
    # splitting there turns a plain loop into mutual tail calls that overflow
    # the C stack. Thunk tables and appended routines have no crossing branches
    # and are split as before.
    ranges = sorted((a, det_end[a]) for a in starts)
    cross_cache = {}

    def crossing_branches(a, e):
        if (a, e) in cross_cache:
            return cross_cache[(a, e)]
        spans = []
        try:
            insns = decode_range(data, a, e)
            offs = {x.offset for x in insns}
            for ins in insns:
                o = ins.op1
                if ins.mnemonic.startswith(("j", "loop")) and o and o.type in (OpType.REL8, OpType.REL16):
                    spans.append((ins.offset, a + o.disp))
            for addr, arms in jump_tables(data, insns, LINK_CS, offs).items():
                spans += [(addr, t) for t in arms]
        except Exception:
            spans = None
        cross_cache[(a, e)] = spans
        return spans

    def split_ok(c):
        for a, e in ranges:
            if a < c < e:
                spans = crossing_branches(a, e)
                if spans is None:
                    return True
                return not any((src < c <= tgt) or (tgt < c <= src) for src, tgt in spans if a <= tgt < e)
        return True

    # Call targets and runtime misses are real entry points and always stand;
    # only Ghidra's independent opinion is filtered.
    rejected = {c for c in ghidra - set(starts) - forced if not split_ok(c)}
    ghidra -= rejected
    print(f"  rejected {len(rejected)} candidate starts that would cut a loop/branch in half")
    all_starts = sorted(set(starts) | ghidra | forced)
    funcs = [("fn_00000", 0, first_det)]
    ct = sorted(call_tgts)
    for i, s in enumerate(ct):
        funcs.append((f"fn_{s:05X}", s, ct[i + 1] if i + 1 < len(ct) else first_det))
    for i, s in enumerate(all_starts):
        nxt = all_starts[i + 1] if i + 1 < len(all_starts) else code_end
        end = min(det_end.get(s, nxt), nxt) if s in det_end else nxt
        if s not in det_end or end == nxt:
            fe = flow_end(data, s, nxt)
            if fe and fe < end:
                end = fe
        funcs.append((f"fn_{s:05X}", s, end))
    seen = {}
    for name, s, e in funcs:
        seen.setdefault(s, (name, s, e))
    funcs = sorted(seen.values(), key=lambda t: t[1])
    ovl_path = os.path.join(ROOT, "work", "overlay_vga.bin")
    ovl_funcs, data_ovl = [], None
    if os.path.exists(ovl_path):
        blob = open(ovl_path, "rb").read()
        assert len(blob) == OVL_HI - OVL_LO, "overlay blob size"
        data_ovl = bytearray(data)
        data_ovl[HDR + OVL_LO:HDR + OVL_HI] = blob
        data_ovl = bytes(data_ovl)
        ovl_funcs = overlay_functions(data_ovl)
        # the stub bytes in the file are not the code that runs: drop their functions
        funcs = [(n, s_, (OVL_LO if s_ < OVL_LO < e_ else e_)) for n, s_, e_ in funcs
                 if not (OVL_LO <= s_ < OVL_HI)]
    known = {io: name for name, io, _ in funcs}
    exe_known = dict(known)
    for n_, a_, _ in ovl_funcs:                      # exe -> overlay calls are rewritten below
        known[a_] = f"fn_{a_:05X}"
    print(f"  overlay: {len(ovl_funcs)} driver functions in [0x{OVL_LO:X},0x{OVL_HI:X})")
    print(f"  startup fn_00000=[0,0x{first_det:X}) + {len(ct)} subroutines; "
          f"{len(starts)} detected + {len(ghidra)} ghidra + {len(forced)} forced = {len(funcs)} functions")

    os.makedirs(OUT, exist_ok=True)
    bodies, all_calls, lifted, failed = [], set(), 0, []
    for name, io, end in funcs:
        if io in OVERRIDES:
            continue
        try:
            insns = decode_range(data, io, end)
            lifter = Lifter(hdr_size=HDR, known_funcs=known, reloc_words=relocs, load_seg=LOAD_SEG)
            lifter.dispatch = True
            lifter.iret_frame = True
            lifter.far_base = 0
            lift16._CODE_SEG = f"{CODE_SEG:04X}"
            lifter.jump_tables = jump_tables(data, insns, LINK_CS, {x.offset for x in insns})
            body = lifter.lift_function(name, insns, io, is_far=True)
            body = body.replace("(CPU *cpu)\n{", f"(CPU *cpu)\n{{\n    cpu->cs = SEG_{CODE_SEG:04X};", 1)
            for old, new in PATCHES:
                body = body.replace(old, new)
            body = re.sub(r"\bfn_([0-9A-F]{5})\(cpu\)",
                          lambda m: (f"ovl_call(cpu, 0x{int(m.group(1), 16):04X})"
                                     if OVL_LO <= int(m.group(1), 16) < OVL_HI and ovl_funcs else m.group(0)), body)
            bodies.append(body)
            all_calls |= lifter.func_calls
            lifted += 1
        except Exception as e:  # keep going; report
            failed.append((name, str(e)))
            bodies.append(f"/* {name}: lift failed: {e} */\nvoid {name}(CPU*cpu){{(void)cpu;}}")

    ovl_bodies = []
    ovl_known = dict(exe_known)
    for n_, a_, _ in ovl_funcs:
        ovl_known[a_] = n_
    for name, io, end in ovl_funcs:
        try:
            insns = decode_range(data_ovl, io, end)
            lifter = Lifter(hdr_size=HDR, known_funcs=ovl_known, reloc_words=relocs, load_seg=LOAD_SEG)
            lifter.dispatch = True
            lifter.iret_frame = True
            lifter.far_base = 0
            lift16._CODE_SEG = f"{CODE_SEG:04X}"
            lifter.jump_tables = jump_tables(data_ovl, insns, LINK_CS, {x.offset for x in insns})
            body = lifter.lift_function(name, insns, io, is_far=True)
            body = body.replace("(CPU *cpu)\n{", f"(CPU *cpu)\n{{\n    cpu->cs = SEG_{CODE_SEG:04X};", 1)
            ovl_bodies.append(body)
            all_calls |= lifter.func_calls
            lifted += 1
        except Exception as e:
            failed.append((name, str(e)))
            ovl_bodies.append(f"/* {name}: lift failed: {e} */\nvoid {name}(CPU*cpu){{(void)cpu;}}")

    names = [n for n, _, _ in funcs]
    nameset = set(names) | {n for n, _, _ in ovl_funcs}
    ovl_addrs = {a for _, a, _ in ovl_funcs}
    stubs = sorted(c for c in all_calls if c not in nameset and not (c.startswith("fn_") and int(c[3:], 16) in ovl_addrs))

    for old in os.listdir(OUT):
        if old.startswith("recomp_") and old.endswith(".c"):
            os.remove(os.path.join(OUT, old))
    for i in range(0, len(bodies), CHUNK):
        with open(os.path.join(OUT, f"recomp_{i // CHUNK:03d}.c"), "w") as f:
            f.write('#include "recomp_all.h"\n\n')
            f.write("\n\n".join(bodies[i:i + CHUNK]) + "\n")

    if ovl_bodies:
        with open(os.path.join(OUT, "recomp_ovl.c"), "w") as f:
            f.write('#include "recomp_all.h"\n\n')
            f.write("\n\n".join(ovl_bodies) + "\n")

    with open(os.path.join(OUT, "recomp_all.h"), "w") as f:
        f.write("#ifndef RECOMP_ALL_H\n#define RECOMP_ALL_H\n")
        f.write('#include "../cpu.h"\n#include "../runtime.h"\n\n')
        f.write(f"#define SEG_{CODE_SEG:04X} 0x{LOAD_SEG + CODE_SEG:04X}\n\n")
        for n in names:
            f.write(f"void {n}(CPU *cpu);\n")
        for n_, _, _ in ovl_funcs:
            f.write(f"void {n_}(CPU *cpu);\n")
        for s in stubs:
            f.write(f"void {s}(CPU *cpu);\n")
        f.write("\n#endif\n")

    with open(os.path.join(OUT, "recomp_dispatch.c"), "w") as f:
        f.write('#include "recomp_all.h"\n#include <stdio.h>\n#include <stdlib.h>\n\n')
        f.write("typedef void (*recomp_fn)(CPU *);\n")
        f.write("typedef struct { unsigned addr; recomp_fn fn; } DispEntry;\n")
        f.write(f"const DispEntry g_disp[{len(names)}] = {{\n")
        for name, io, _ in funcs:
            f.write(f"  {{0x{io:05X}, {name}}},\n")
        f.write("};\n")
        f.write(f"const int g_disp_count = {len(names)};\n")
        f.write(f"const unsigned g_code_top = 0x{max(io for _, io, _ in funcs):05X}u;\n")
        f.write(f"const unsigned g_ovl_lo = 0x{OVL_LO:X}u, g_ovl_hi = 0x{OVL_HI:X}u;\n")
        if ovl_funcs:
            sig = data_ovl[HDR + OVL_LO:HDR + OVL_LO + OVL_SIG_LEN]
            f.write(f"const unsigned char g_ovl_sig[{OVL_SIG_LEN}] = {{{', '.join('0x%02X' % c for c in sig)}}};\n")
            f.write(f"const DispEntry g_ovl_disp[{len(ovl_funcs)}] = {{\n")
            for n_, a_, _ in ovl_funcs:
                f.write(f"  {{0x{a_:05X}, {n_}}},\n")
            f.write("};\n")
            f.write(f"const int g_ovl_count = {len(ovl_funcs)};\n")
        else:
            f.write("const unsigned char g_ovl_sig[1] = {0};\nconst DispEntry g_ovl_disp[1] = {{0, 0}};\nconst int g_ovl_count = 0;\n")
        # unresolved direct targets become aborting stubs
        for s in stubs:
            f.write(f'void {s}(CPU *cpu) {{ (void)cpu; fprintf(stderr, "unresolved call {s}\\n"); abort(); }}\n')

    print(f"  lifted {lifted}/{len(funcs)}; {len(failed)} failed; {len(stubs)} unresolved call targets")
    for n, e in failed[:20]:
        print(f"    FAILED {n}: {e}")
    for s in stubs[:20]:
        print(f"    STUB   {s}")


if __name__ == "__main__":
    main()
