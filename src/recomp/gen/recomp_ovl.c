#include "recomp_all.h"

void ovl_0039C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_0039C");
    ovl_003D8(cpu); return; /* tail-jmp 0x0003D8 */ /* jmp 0x003C */
    /* nop */                                /* nop */
    ovl_0039F(cpu); return;                  /* fallthrough 0x00039F */
}

void ovl_0039F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_0039F");
    ovl_003DE(cpu); return; /* tail-jmp 0x0003DE */ /* jmp 0x003F */
    /* nop */                                /* nop */
    ovl_003A2(cpu); return;                  /* fallthrough 0x0003A2 */
}

void ovl_003A2(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003A2");
    ovl_00425(cpu); return; /* tail-jmp 0x000425 */ /* jmp 0x0083 */
}

void ovl_003A5(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003A5");
    ovl_00447(cpu); return; /* tail-jmp 0x000447 */ /* jmp 0x00A2 */
}

void ovl_003A8(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003A8");
    ovl_0046F(cpu); return; /* tail-jmp 0x00046F */ /* jmp 0x00C7 */
}

void ovl_003AB(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003AB");
    ovl_004A0(cpu); return; /* tail-jmp 0x0004A0 */ /* jmp 0x00F5 */
}

void ovl_003AE(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003AE");
    ovl_004D4(cpu); return; /* tail-jmp 0x0004D4 */ /* jmp 0x0126 */
}

void ovl_003B1(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003B1");
    ovl_0050B(cpu); return; /* tail-jmp 0x00050B */ /* jmp 0x015A */
}

void ovl_003B4(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003B4");
    ovl_0053C(cpu); return; /* tail-jmp 0x00053C */ /* jmp 0x0188 */
}

void ovl_003B7(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003B7");
    ovl_005A7(cpu); return; /* tail-jmp 0x0005A7 */ /* jmp 0x01F0 */
}

void ovl_003BA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003BA");
    ovl_005F5(cpu); return; /* tail-jmp 0x0005F5 */ /* jmp 0x023B */
}

void ovl_003BD(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003BD");
    ovl_0063E(cpu); return; /* tail-jmp 0x00063E */ /* jmp 0x0281 */
}

void ovl_003C0(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003C0");
    ovl_00694(cpu); return; /* tail-jmp 0x000694 */ /* jmp 0x02D4 */
}

void ovl_003C3(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003C3");
    ovl_006DB(cpu); return; /* tail-jmp 0x0006DB */ /* jmp 0x0318 */
}

void ovl_003C6(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003C6");
    ovl_0072C(cpu); return; /* tail-jmp 0x00072C */ /* jmp 0x0366 */
}

void ovl_003C9(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003C9");
    ovl_0087C(cpu); return; /* tail-jmp 0x00087C */ /* jmp 0x04B3 */
}

void ovl_003CC(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003CC");
    ovl_008F2(cpu); return; /* tail-jmp 0x0008F2 */ /* jmp 0x0526 */
}

void ovl_003CF(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003CF");
    ovl_007E4(cpu); return; /* tail-jmp 0x0007E4 */ /* jmp 0x0415 */
}

void ovl_003D2(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003D2");
    ovl_00AC5(cpu); return; /* tail-jmp 0x000AC5 */ /* jmp 0x06F3 */
}

void ovl_003D5(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003D5");
    ovl_00AE0(cpu); return; /* tail-jmp 0x000AE0 */ /* jmp 0x070B */
}

void ovl_003D8(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003D8");
    cpu->ax = (uint16_t)(0x13);              /* mov ax, 0x13 */
    bios_int10(cpu);                         /* int 0x10 */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_003DE(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_003DE");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->ax = (uint16_t)(0xA000);            /* mov ax, 0xA000 */
    cpu->es = (uint16_t)(cpu->ax);           /* mov es, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->di + 0x3924) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[di+0x3924] */
    { uint16_t _t = cpu->ah; cpu->ah = (uint8_t)(cpu->al); cpu->al = (uint8_t)(_t); } /* xchg ah, al */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
L_ovl_003DE_000037:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_003DE_000037; /* jne 0x0037 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_00425(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_00425");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add di, word ss:[bp+0x4] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov cx, word ss:[bp+0x8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40C8)); /* mov ax, word ds:[0x40C8] */
    while (cpu->cx != 0) { cpu->cx--;        /* rep stosb */
        mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    }
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_00447(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_00447");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add di, word ss:[bp+0x4] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov cx, word ss:[bp+0x8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40C8)); /* mov ax, word ds:[0x40C8] */
    cpu->bx = (uint16_t)(0x13F);             /* mov bx, 0x13F */
L_ovl_00447_00001E:;
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_00447_00001E; /* loop 0x001E */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_0046F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_0046F");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add di, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40C8)); /* mov ax, word ds:[0x40C8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->si = (uint16_t)(0x140);             /* mov si, 0x140 */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->bx)); /* sub si, bx */
L_ovl_0046F_000023:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    while (cpu->cx != 0) { cpu->cx--;        /* rep stosb */
        mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    }
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->si)); /* add di, si */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_0046F_000023; /* jne 0x0023 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_004A0(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_004A0");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add di, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->al = (uint8_t)(0xF);                /* mov al, 0xF */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->si = (uint16_t)(0x140);             /* mov si, 0x140 */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->bx)); /* sub si, bx */
L_ovl_004A0_000022:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
L_ovl_004A0_000024:;
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) ^ cpu->al; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* xor byte es:[di], al */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_004A0_000024; /* loop 0x0024 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->si)); /* add di, si */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_004A0_000022; /* jne 0x0022 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_004D4(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_004D4");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[bx+0x3924] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add si, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0xC) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ss:[bp+0xC] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov ax, word ss:[bp+0x8] */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->dx = (uint16_t)(cpu->ax);           /* mov dx, ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
L_ovl_004D4_000029:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_004D4_000029; /* jne 0x0029 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_0050B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_0050B");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add di, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ss:[bp+0x8] */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->dx = (uint16_t)(cpu->ax);           /* mov dx, ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
L_ovl_0050B_000023:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_0050B_000023; /* jne 0x0023 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_0053C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_0053C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov bx, word ss:[bp+0xE] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC)))); /* add di, word ss:[bp+0xC] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[bx+0x3924] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add si, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
L_ovl_0053C_00002F:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_0053C_00002F; /* jne 0x002F */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xBC), 0x1); /* cmp word ds:[0xBC], 0x1 */
    if (cc_ne(cpu)) goto L_ovl_0053C_000066; /* jne 0x0066 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov bx, word ss:[bp+0xE] */
    flags_cmp16(cpu, cpu->bx, 0xC8);         /* cmp bx, 0xC8 */
    if (cc_ae(cpu)) goto L_ovl_0053C_000066; /* jae 0x0066 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40C4 + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[0x40C4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov ax, word ss:[bp+0xC] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov ax, word ss:[bp+0x8] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov bx, word ss:[bp+0xA] */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->di)); /* mov word ds:[0x40C4], di */
L_ovl_0053C_000066:;
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_005A7(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_005A7");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov bx, word ss:[bp+0xE] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC)))); /* add di, word ss:[bp+0xC] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[bx+0x3924] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add si, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    cpu->dx = (uint16_t)(cpu->ax);           /* mov dx, ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    { uint16_t _t = cpu->al; cpu->al = (uint8_t)(cpu->ah); cpu->ah = (uint8_t)(_t); } /* xchg al, ah */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
L_ovl_005A7_000036:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x140)); /* add si, 0x140 */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->bx)); /* sub si, bx */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 0x140)); /* sub di, 0x140 */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, cpu->bx)); /* sub di, bx */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_005A7_000036; /* jne 0x0036 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_005F5(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_005F5");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags |= FLAG_DF;                   /* std */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov bx, word ss:[bp+0xE] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC)))); /* add di, word ss:[bp+0xC] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[bx+0x3924] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add si, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
L_ovl_005F5_00002C:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
L_ovl_005F5_00002E:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, cpu->si)); /* mov al, byte ds:[si] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_005F5_00002E; /* loop 0x002E */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x140)); /* add si, 0x140 */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->bx)); /* sub si, bx */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x140)); /* add di, 0x140 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_005F5_00002C; /* jne 0x002C */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_0063E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_0063E");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov bx, word ss:[bp+0xE] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC)))); /* add di, word ss:[bp+0xC] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[bx+0x3924] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add si, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    cpu->dx = (uint16_t)(cpu->ax);           /* mov dx, ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    { uint16_t _t = cpu->al; cpu->al = (uint8_t)(cpu->ah); cpu->ah = (uint8_t)(_t); } /* xchg al, ah */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
L_ovl_0063E_00003E:;
    push16(cpu, cpu->di);                    /* push di */
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
L_ovl_0063E_000041:;
    mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 0x2)); /* sub di, 0x2 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_0063E_000041; /* loop 0x0041 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 0x140)); /* sub di, 0x140 */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_0063E_00003E; /* jne 0x003E */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_00694(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_00694");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov bx, word ss:[bp+0xE] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC)))); /* add di, word ss:[bp+0xC] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[bx+0x3924] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add si, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->dx)); /* add di, dx */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
L_ovl_00694_000031:;
    push16(cpu, cpu->di);                    /* push di */
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
L_ovl_00694_000034:;
    mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x13F)); /* add di, 0x13F */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_00694_000034; /* loop 0x0034 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_00694_000031; /* jne 0x0031 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_006DB(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_006DB");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov bx, word ss:[bp+0xE] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC)))); /* add di, word ss:[bp+0xC] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[bx+0x3924] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add si, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov ax, word ss:[bp+0x8] */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    { uint16_t _t = cpu->al; cpu->al = (uint8_t)(cpu->ah); cpu->ah = (uint8_t)(_t); } /* xchg al, ah */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
L_ovl_006DB_00003B:;
    push16(cpu, cpu->di);                    /* push di */
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
L_ovl_006DB_00003E:;
    mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 0x141)); /* sub di, 0x141 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_006DB_00003E; /* loop 0x003E */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_006DB_00003B; /* jne 0x003B */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_0072C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_0072C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0E0)); /* mov ax, word ds:[0xC0E0] */
    cpu->es = (uint16_t)(cpu->ax);           /* mov es, ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0E4)); /* mov di, word ds:[0xC0E4] */
    cpu->cl = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->di))); /* mov cl, byte es:[bx+di] */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0E6)); /* mov di, word ds:[0xC0E6] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->di))); /* mov al, byte es:[bx+di] */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0E2)); /* mov di, word ds:[0xC0E2] */
    cpu->ah = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->di))); /* mov ah, byte es:[bx+di] */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0DE)); /* mov si, word ds:[0xC0DE] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0E8)); /* mov dx, word ds:[0xC0E8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40C8)); /* mov ax, word ds:[0x40C8] */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    push16(cpu, cpu->es);                    /* push es */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add di, word ss:[bp+0x4] */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->bl = (uint8_t)(cpu->cl);            /* mov bl, cl */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
L_ovl_0072C_000047:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    push16(cpu, cpu->di);                    /* push di */
L_ovl_0072C_00004A:;
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_0072C_000052; /* jae 0x0052 */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_0072C_000052:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_0072C_000057; /* loop 0x0057 */
    goto L_ovl_0072C_0000A9;                 /* jmp 0x00A9 */
L_ovl_0072C_000057:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_0072C_00005E; /* jae 0x005E */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_0072C_00005E:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_0072C_000063; /* loop 0x0063 */
    goto L_ovl_0072C_0000A9;                 /* jmp 0x00A9 */
L_ovl_0072C_000063:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_0072C_00006A; /* jae 0x006A */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_0072C_00006A:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_0072C_00006F; /* loop 0x006F */
    goto L_ovl_0072C_0000A9;                 /* jmp 0x00A9 */
L_ovl_0072C_00006F:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_0072C_000076; /* jae 0x0076 */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_0072C_000076:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_0072C_00007B; /* loop 0x007B */
    goto L_ovl_0072C_0000A9;                 /* jmp 0x00A9 */
L_ovl_0072C_00007B:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_0072C_000082; /* jae 0x0082 */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_0072C_000082:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_0072C_000087; /* loop 0x0087 */
    goto L_ovl_0072C_0000A9;                 /* jmp 0x00A9 */
L_ovl_0072C_000087:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_0072C_00008E; /* jae 0x008E */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_0072C_00008E:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_0072C_000093; /* loop 0x0093 */
    goto L_ovl_0072C_0000A9;                 /* jmp 0x00A9 */
L_ovl_0072C_000093:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_0072C_00009A; /* jae 0x009A */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_0072C_00009A:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_0072C_00009F; /* loop 0x009F */
    goto L_ovl_0072C_0000A9;                 /* jmp 0x00A9 */
L_ovl_0072C_00009F:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_0072C_0000A6; /* jae 0x00A6 */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_0072C_0000A6:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_0072C_00004A; /* loop 0x004A */
L_ovl_0072C_0000A9:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x140)); /* add di, 0x140 */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_0072C_000047; /* jne 0x0047 */
    cpu->ax = (uint16_t)(cpu->bx);           /* mov ax, bx */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_007E4(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_007E4");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40C8)); /* mov cx, word ds:[0x40C8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add di, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ss:[bp+0x8] */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->dx = (uint16_t)(cpu->bx);           /* mov dx, bx */
    cpu->bl = (uint8_t)(cpu->al);            /* mov bl, al */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->dl = (uint8_t)(cpu->ah);            /* mov dl, ah */
    cpu->ah = (uint8_t)(cpu->cl);            /* mov ah, cl */
L_ovl_007E4_000029:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    push16(cpu, cpu->di);                    /* push di */
L_ovl_007E4_00002C:;
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_007E4_000034; /* jae 0x0034 */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_007E4_000034:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_007E4_000039; /* loop 0x0039 */
    goto L_ovl_007E4_00008B;                 /* jmp 0x008B */
L_ovl_007E4_000039:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_007E4_000040; /* jae 0x0040 */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_007E4_000040:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_007E4_000045; /* loop 0x0045 */
    goto L_ovl_007E4_00008B;                 /* jmp 0x008B */
L_ovl_007E4_000045:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_007E4_00004C; /* jae 0x004C */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_007E4_00004C:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_007E4_000051; /* loop 0x0051 */
    goto L_ovl_007E4_00008B;                 /* jmp 0x008B */
L_ovl_007E4_000051:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_007E4_000058; /* jae 0x0058 */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_007E4_000058:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_007E4_00005D; /* loop 0x005D */
    goto L_ovl_007E4_00008B;                 /* jmp 0x008B */
L_ovl_007E4_00005D:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_007E4_000064; /* jae 0x0064 */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_007E4_000064:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_007E4_000069; /* loop 0x0069 */
    goto L_ovl_007E4_00008B;                 /* jmp 0x008B */
L_ovl_007E4_000069:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_007E4_000070; /* jae 0x0070 */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_007E4_000070:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_007E4_000075; /* loop 0x0075 */
    goto L_ovl_007E4_00008B;                 /* jmp 0x008B */
L_ovl_007E4_000075:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_007E4_00007C; /* jae 0x007C */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_007E4_00007C:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_007E4_000081; /* loop 0x0081 */
    goto L_ovl_007E4_00008B;                 /* jmp 0x008B */
L_ovl_007E4_000081:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_ovl_007E4_000088; /* jae 0x0088 */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->ah)); /* mov byte es:[di], ah */
L_ovl_007E4_000088:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_007E4_00002C; /* loop 0x002C */
L_ovl_007E4_00008B:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x140)); /* add di, 0x140 */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_007E4_000029; /* jne 0x0029 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_0087C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_0087C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add di, word ss:[bp+0x4] */
    push16(cpu, cpu->ds);                    /* push ds */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ss:[bp+0x8] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x10)); /* add si, 0x10 */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x10)); /* add si, 0x10 */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->cx = (uint16_t)(cpu->dx);           /* mov cx, dx */
    cpu->cl = (uint8_t)(cpu->al);            /* mov cl, al */
    cpu->dl = (uint8_t)(cpu->ah);            /* mov dl, ah */
    push16(cpu, cpu->dx);                    /* push dx */
L_ovl_0087C_00002B:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->cx);                    /* push cx */
L_ovl_0087C_00002D:;
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    { uint8_t _r = cpu->al & 0xF; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0xF */
    cpu->al = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    { uint16_t _t = cpu->ah; cpu->ah = (uint8_t)(cpu->al); cpu->al = (uint8_t)(_t); } /* xchg ah, al */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    cpu->al = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_0087C_00002D; /* loop 0x002D */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x140)); /* add di, 0x140 */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_0087C_00002B; /* jne 0x002B */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xBC), 0x1); /* cmp word ds:[0xBC], 0x1 */
    if (cc_ne(cpu)) goto L_ovl_0087C_000071; /* jne 0x0071 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    flags_cmp16(cpu, cpu->bx, 0xC8);         /* cmp bx, 0xC8 */
    if (cc_ae(cpu)) goto L_ovl_0087C_000071; /* jae 0x0071 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40C4 + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[0x40C4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->cl);            /* mov al, cl */
    cpu->ah = (uint8_t)(cpu->dl);            /* mov ah, dl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->di)); /* mov word ds:[0x40C4], di */
L_ovl_0087C_000071:;
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_008F2(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_008F2");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->si = _o; cpu->es = _s; } /* les si, word ss:[bp+0x8] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x10)); /* add si, 0x10 */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x10)); /* add si, 0x10 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->si)); /* mov ax, word es:[si] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x2)); /* add si, 0x2 */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->cx = (uint16_t)(cpu->dx);           /* mov cx, dx */
    cpu->cl = (uint8_t)(cpu->al);            /* mov cl, al */
    cpu->dl = (uint8_t)(cpu->ah);            /* mov dl, ah */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov di, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x96)); /* mov ax, word ds:[0x96] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->di)); /* sub ax, di */
    if (cc_s(cpu)) goto L_ovl_008F2_00006E;  /* js 0x006E */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    flags_cmp16(cpu, cpu->dx, cpu->ax);      /* cmp dx, ax */
    if (cc_be(cpu)) goto L_ovl_008F2_00002F; /* jbe 0x002F */
    cpu->dx = (uint16_t)(cpu->ax);           /* mov dx, ax */
L_ovl_008F2_00002F:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x94)); /* mov ax, word ds:[0x94] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->di)); /* sub ax, di */
    if (cc_le(cpu)) goto L_ovl_008F2_000040; /* jle 0x0040 */
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, cpu->ax)); /* sub dx, ax */
    if (cc_be(cpu)) goto L_ovl_008F2_00006E; /* jbe 0x006E */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { uint16_t _r = (uint16_t)cpu->al * cpu->cl; cpu->ax = _r; cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (_r > 0xFF ? FLAG_CF|FLAG_OF : 0); } /* mul cl */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
L_ovl_008F2_000040:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC)), 0x0); /* cmp word ss:[bp+0xC], 0x0 */
    if (cc_e(cpu)) goto L_ovl_008F2_00004C;  /* je 0x004C */
    goto L_ovl_008F2_000107;                 /* jmp 0x0107 */
L_ovl_008F2_00004C:;
    { int16_t _v = (int16_t)cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->bx = (uint16_t)((uint16_t)_r); } } /* sar bx, 0x1 */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    { uint16_t _r = cpu->bp ^ cpu->bp; flags_logic16(cpu, _r); cpu->bp = (uint16_t)(_r); } /* xor bp, bp */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x9A)); /* mov ax, word ds:[0x9A] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
    if (cc_s(cpu)) goto L_ovl_008F2_00006E;  /* js 0x006E */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    flags_cmp16(cpu, cpu->cx, cpu->ax);      /* cmp cx, ax */
    if (cc_be(cpu)) goto L_ovl_008F2_000063; /* jbe 0x0063 */
    cpu->bp = (uint16_t)(cpu->cx);           /* mov bp, cx */
    cpu->bp = (uint16_t)(flags_sub16(cpu, cpu->bp, cpu->ax)); /* sub bp, ax */
    cpu->cx = (uint16_t)(cpu->ax);           /* mov cx, ax */
L_ovl_008F2_000063:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x98)); /* mov ax, word ds:[0x98] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
    if (cc_le(cpu)) goto L_ovl_008F2_000078; /* jle 0x0078 */
    cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, cpu->ax)); /* sub cx, ax */
    if (cc_a(cpu)) goto L_ovl_008F2_000072;  /* ja 0x0072 */
L_ovl_008F2_00006E:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    goto L_ovl_008F2_0001CD;                 /* jmp 0x01CD */
L_ovl_008F2_000072:;
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->bp = (uint16_t)(flags_add16(cpu, cpu->bp, cpu->ax)); /* add bp, ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
L_ovl_008F2_000078:;
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->di);                    /* push di */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xBC), 0x1); /* cmp word ds:[0xBC], 0x1 */
    if (cc_ne(cpu)) goto L_ovl_008F2_00009B; /* jne 0x009B */
    flags_cmp16(cpu, cpu->di, 0xC8);         /* cmp di, 0xC8 */
    if (cc_ae(cpu)) goto L_ovl_008F2_00009B; /* jae 0x009B */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    cpu->al = (uint8_t)(cpu->bl);            /* mov al, bl */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40C4 + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[0x40C4] */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->cl);            /* mov al, cl */
    cpu->ah = (uint8_t)(cpu->dl);            /* mov ah, dl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->di)); /* mov word ds:[0x40C4], di */
L_ovl_008F2_00009B:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->di + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[di+0x3924] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
L_ovl_008F2_0000AA:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->cx);                    /* push cx */
L_ovl_008F2_0000AC:;
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    { uint8_t _r = cpu->al & 0xF; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0xF */
    if (cc_e(cpu)) goto L_ovl_008F2_0000E4;  /* je 0x00E4 */
    cpu->al = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    if (cc_e(cpu)) goto L_ovl_008F2_0000D2;  /* je 0x00D2 */
    { uint16_t _t = cpu->ah; cpu->ah = (uint8_t)(cpu->al); cpu->al = (uint8_t)(_t); } /* xchg ah, al */
    cpu->al = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_008F2_0000AC; /* loop 0x00AC */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x140)); /* add di, 0x140 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->bp)); /* add si, bp */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_008F2_0000AA; /* jne 0x00AA */
    goto L_ovl_008F2_0001CD;                 /* jmp 0x01CD */
L_ovl_008F2_0000D2:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_008F2_0000AC; /* loop 0x00AC */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x140)); /* add di, 0x140 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->bp)); /* add si, bp */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_008F2_0000AA; /* jne 0x00AA */
    goto L_ovl_008F2_0001CD;                 /* jmp 0x01CD */
L_ovl_008F2_0000E4:;
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    if (cc_e(cpu)) goto L_ovl_008F2_0000F4;  /* je 0x00F4 */
    cpu->al = (uint8_t)(cpu->ah);            /* mov al, ah */
    cpu->al = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->al)); /* mov byte es:[di], al */
L_ovl_008F2_0000F4:;
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x2)); /* add di, 0x2 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_008F2_0000AC; /* loop 0x00AC */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x140)); /* add di, 0x140 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->bp)); /* add si, bp */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_008F2_0000AA; /* jne 0x00AA */
    goto L_ovl_008F2_0001CD;                 /* jmp 0x01CD */
L_ovl_008F2_000107:;
    cpu->flags |= FLAG_DF;                   /* std */
    { uint16_t _r = cpu->bp ^ cpu->bp; flags_logic16(cpu, _r); cpu->bp = (uint16_t)(_r); } /* xor bp, bp */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->cx)); /* add bx, cx */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->cx)); /* add bx, cx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec bx */
    cpu->ax = (uint16_t)(cpu->bx);           /* mov ax, bx */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x98))); /* sub ax, word ds:[0x98] */
    if (cc_s(cpu)) goto L_ovl_008F2_000130;  /* js 0x0130 */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    flags_cmp16(cpu, cpu->cx, cpu->ax);      /* cmp cx, ax */
    if (cc_be(cpu)) goto L_ovl_008F2_000124; /* jbe 0x0124 */
    cpu->bp = (uint16_t)(cpu->cx);           /* mov bp, cx */
    cpu->bp = (uint16_t)(flags_sub16(cpu, cpu->bp, cpu->ax)); /* sub bp, ax */
    cpu->cx = (uint16_t)(cpu->ax);           /* mov cx, ax */
L_ovl_008F2_000124:;
    cpu->ax = (uint16_t)(cpu->bx);           /* mov ax, bx */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x9A))); /* sub ax, word ds:[0x9A] */
    if (cc_be(cpu)) goto L_ovl_008F2_00013A; /* jbe 0x013A */
    cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, cpu->ax)); /* sub cx, ax */
    if (cc_a(cpu)) goto L_ovl_008F2_000134;  /* ja 0x0134 */
L_ovl_008F2_000130:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    goto L_ovl_008F2_0001CD;                 /* jmp 0x01CD */
L_ovl_008F2_000134:;
    cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, cpu->ax)); /* sub bx, ax */
    cpu->bp = (uint16_t)(flags_add16(cpu, cpu->bp, cpu->ax)); /* add bp, ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
L_ovl_008F2_00013A:;
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->di);                    /* push di */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xBC), 0x1); /* cmp word ds:[0xBC], 0x1 */
    if (cc_ne(cpu)) goto L_ovl_008F2_000163; /* jne 0x0163 */
    flags_cmp16(cpu, cpu->di, 0xC8);         /* cmp di, 0xC8 */
    if (cc_ae(cpu)) goto L_ovl_008F2_000163; /* jae 0x0163 */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    cpu->al = (uint8_t)(cpu->bl);            /* mov al, bl */
    cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, cpu->cl)); /* sub al, cl */
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc al */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40C4 + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[0x40C4] */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->cl);            /* mov al, cl */
    cpu->ah = (uint8_t)(cpu->dl);            /* mov ah, dl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->flags |= FLAG_DF;                   /* std */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->di)); /* mov word ds:[0x40C4], di */
L_ovl_008F2_000163:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->di + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[di+0x3924] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
L_ovl_008F2_000172:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->cx);                    /* push cx */
L_ovl_008F2_000174:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, cpu->si)); /* mov al, byte ds:[si] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    if (cc_e(cpu)) goto L_ovl_008F2_0001B2;  /* je 0x01B2 */
    cpu->al = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    { uint8_t _r = cpu->ah & 0xF; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* and ah, 0xF */
    if (cc_e(cpu)) goto L_ovl_008F2_00019C;  /* je 0x019C */
    { uint16_t _t = cpu->ah; cpu->ah = (uint8_t)(cpu->al); cpu->al = (uint8_t)(_t); } /* xchg ah, al */
    cpu->al = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_008F2_000174; /* loop 0x0174 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x140)); /* add di, 0x140 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->bp)); /* add si, bp */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_008F2_000172; /* jne 0x0172 */
    goto L_ovl_008F2_0001CD;                 /* jmp 0x01CD */
L_ovl_008F2_00019C:;
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->di + 0x1), (uint8_t)(cpu->al)); /* mov byte es:[di+0x1], al */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 0x2)); /* sub di, 0x2 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_008F2_000174; /* loop 0x0174 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x140)); /* add di, 0x140 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->bp)); /* add si, bp */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_008F2_000172; /* jne 0x0172 */
    goto L_ovl_008F2_0001CD;                 /* jmp 0x01CD */
L_ovl_008F2_0001B2:;
    { uint8_t _r = cpu->ah & 0xF; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* and ah, 0xF */
    if (cc_e(cpu)) goto L_ovl_008F2_0001BD;  /* je 0x01BD */
    cpu->al = (uint8_t)(cpu->ah);            /* mov al, ah */
    cpu->al = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->al)); /* mov byte es:[di], al */
L_ovl_008F2_0001BD:;
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 0x2)); /* sub di, 0x2 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_ovl_008F2_000174; /* loop 0x0174 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x140)); /* add di, 0x140 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->bp)); /* add si, bp */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_ovl_008F2_000172; /* jne 0x0172 */
L_ovl_008F2_0001CD:;
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_00AC5(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_00AC5");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add di, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40C8)); /* mov ax, word ds:[0x40C8] */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->al)); /* mov byte es:[di], al */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void ovl_00AE0(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("ovl_00AE0");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add di, word ss:[bp+0x4] */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->di)); /* mov al, byte es:[di] */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}
