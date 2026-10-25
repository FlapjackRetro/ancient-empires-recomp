#include "recomp_all.h"

void fn_0984C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0984C");
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x6982 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x32);              /* mov ax, 0x32 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x96);              /* mov ax, 0x96 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x168);             /* mov ax, 0x168 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x6B5C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x6982 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->sp += 2; return;                    /* ret */
}

void fn_099E2(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_099E2");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x1271)); /* add bx, 0x1271 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    mem_write16(cpu, cpu->ds, 0xC34E, (uint16_t)(cpu->ax)); /* mov word ds:[0xC34E], ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x1271)); /* add bx, 0x1271 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov ax, word es:[bx+0x2] */
    mem_write16(cpu, cpu->ds, 0xC350, (uint16_t)(cpu->ax)); /* mov word ds:[0xC350], ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_09A0E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_09A0E");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_099E2(cpu);                           /* call 0xFFD4 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0984C(cpu);                           /* call 0xFE3E */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC359)); /* cmp ax, word ds:[0xC359] */
    if (cc_ne(cpu)) goto L_fn_09A0E_000052;  /* jne 0x0052 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC354), 0x0); /* cmp word ds:[0xC354], 0x0 */
    if (cc_ne(cpu)) goto L_fn_09A0E_000052;  /* jne 0x0052 */
    cpu->ax = (uint16_t)(0x5);               /* mov ax, 0x5 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x67C0 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5C6); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5C6 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x122))); /* mov ax, word es:[bx+0x122] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C8)); /* mov cx, word ds:[0xC5C8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C6)); /* mov bx, word ds:[0xC5C6] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC350)); /* push word ds:[0xC350] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC34E)); /* push word ds:[0xC34E] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CF);                           /* call 0x69C1 */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x67C0 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_09A0E_0000B7;                  /* jmp 0x00B7 */
L_fn_09A0E_000052:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC35D)); /* mov ax, word ds:[0xC35D] */
    cpu->dx = (uint16_t)(0x18);              /* mov dx, 0x18 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xDCC)); /* add bx, 0xDCC */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5C6); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5C6 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5C6] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C8)); /* mov cx, word ds:[0xC5C8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C6)); /* mov bx, word ds:[0xC5C6] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0x168);             /* mov ax, 0x168 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CF);                           /* call 0x69C1 */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC35D)); /* mov ax, word ds:[0xC35D] */
    cpu->dx = (uint16_t)(0x18);              /* mov dx, 0x18 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xDCC)); /* add bx, 0xDCC */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu,0xFFFF); dispatch_near(cpu, SEG_0000, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x12A1))); /* call word ds:[bx+0x12A1] */
L_fn_09A0E_0000B7:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_09AC7(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_09AC7");
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_09AC7_00008F;                  /* jmp 0x008F */
L_fn_09AC7_000006:;
    cpu->ax = (uint16_t)(0x15);              /* mov ax, 0x15 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x302A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x30);              /* mov dx, 0x30 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x10)); /* add ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x23);              /* mov ax, 0x23 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x30);              /* mov ax, 0x30 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x30);              /* mov dx, 0x30 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x158)); /* add ax, 0x158 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x68ED */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x23);              /* mov ax, 0x23 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x30);              /* mov ax, 0x30 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x30);              /* mov dx, 0x30 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x10)); /* add ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x68D8 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x30);              /* mov dx, 0x30 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC8)); /* add ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x23);              /* mov ax, 0x23 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x30);              /* mov ax, 0x30 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x30);              /* mov dx, 0x30 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x158)); /* add ax, 0x158 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x68ED */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x78);              /* mov ax, 0x78 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C26(cpu);                           /* call 0xD15F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0x3081 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_09AC7_00008F:;
    flags_cmp16(cpu, cpu->si, 0x3);          /* cmp si, 0x3 */
    if (cc_ge(cpu)) goto L_fn_09AC7_000097;  /* jge 0x0097 */
    RECOMP_TICK(cpu);
    goto L_fn_09AC7_000006;                  /* jmp 0x0006 */
L_fn_09AC7_000097:;
    cpu->ax = (uint16_t)(0x5);               /* mov ax, 0x5 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D4B3(cpu);                           /* call 0x39EC */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_09B68(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_09B68");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x6)); /* sub sp, 0x6 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x0)); /* mov word ss:[bp+-0x2], 0x0 */
    goto L_fn_09B68_000043;                  /* jmp 0x0043 */
L_fn_09B68_000012:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    cpu->dx = (uint16_t)(0x30);              /* mov dx, 0x30 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x10)); /* add ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x23);              /* mov ax, 0x23 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x30);              /* mov ax, 0x30 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    cpu->dx = (uint16_t)(0x30);              /* mov dx, 0x30 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC8)); /* add ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x684C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x2] */
L_fn_09B68_000043:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x3); /* cmp word ss:[bp+-0x2], 0x3 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_09B68_000012;   /* jl 0x0012 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0xC35B, (uint16_t)(cpu->ax)); /* mov word ds:[0xC35B], ax */
    mem_write16(cpu, cpu->ds, 0xC354, (uint16_t)(cpu->ax)); /* mov word ds:[0xC354], ax */
    mem_write16(cpu, cpu->ds, 0xC35B, (uint16_t)(cpu->ax)); /* mov word ds:[0xC35B], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ACE7(cpu);                           /* call 0x117F */
    cpu->dx = (uint16_t)(0x14);              /* mov dx, 0x14 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->si)); /* add ax, si */
    mem_write16(cpu, cpu->ds, 0xC35D, (uint16_t)(cpu->ax)); /* mov word ds:[0xC35D], ax */
    goto L_fn_09B68_000063;                  /* jmp 0x0063 */
L_fn_09B68_000063:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC35D)); /* mov ax, word ds:[0xC35D] */
    cpu->dx = (uint16_t)(0x18);              /* mov dx, 0x18 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xDCC)); /* add bx, 0xDCC */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x16))); /* mov al, byte es:[bx+0x16] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F90F(cpu);                           /* call 0x5DA7 */
    cpu->bx = (uint16_t)(0x8);               /* mov bx, 0x8 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0080; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->si = (uint16_t)(cpu->dx);           /* mov si, dx */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(cpu->al);            /* mov cl, al */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    flags_logic16(cpu, cpu->dx & cpu->ax);   /* test dx, ax */
    RECOMP_TICK(cpu);
    if (cc_e(cpu)) goto L_fn_09B68_000063;   /* je 0x0063 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    mem_write16(cpu, cpu->ds, 0xC359, (uint16_t)(cpu->ax)); /* mov word ds:[0xC359], ax */
    cpu->ax = (uint16_t)(0x1022);            /* mov ax, 0x1022 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xCA04 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_09B68_00012B;                  /* jmp 0x012B */
L_fn_09B68_0000A5:;
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x1271)); /* add bx, 0x1271 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x1271)); /* add bx, 0x1271 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov ax, word es:[bx+0x2] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x6666 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2E);              /* mov ax, 0x2E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00355(cpu);                           /* call 0x67ED */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x7);               /* mov ax, 0x7 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x6666 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1F);              /* mov ax, 0x1F */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2C);              /* mov ax, 0x2C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00355(cpu);                           /* call 0x67ED */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x6666 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1D);              /* mov ax, 0x1D */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2A);              /* mov ax, 0x2A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x6840 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_09B68_00012B:;
    flags_cmp16(cpu, cpu->di, 0xC);          /* cmp di, 0xC */
    if (cc_ge(cpu)) goto L_fn_09B68_000133;  /* jge 0x0133 */
    RECOMP_TICK(cpu);
    goto L_fn_09B68_0000A5;                  /* jmp 0x00A5 */
L_fn_09B68_000133:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_09B68_00013F;                  /* jmp 0x013F */
L_fn_09B68_000137:;
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09A0E(cpu);                           /* call 0xFEA6 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_09B68_00013F:;
    flags_cmp16(cpu, cpu->si, 0x9);          /* cmp si, 0x9 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_09B68_000137;   /* jl 0x0137 */
    mem_write8(cpu, cpu->ds, 0xC356, (uint8_t)(0x9)); /* mov byte ds:[0xC356], 0x9 */
    mem_write8(cpu, cpu->ds, 0xC357, (uint8_t)(0xA)); /* mov byte ds:[0xC357], 0xA */
    mem_write8(cpu, cpu->ds, 0xC358, (uint8_t)(0xB)); /* mov byte ds:[0xC358], 0xB */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F90F(cpu);                           /* call 0x5DA7 */
    cpu->bx = (uint16_t)(0x3);               /* mov bx, 0x3 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x015A; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->si = (uint16_t)(cpu->dx);           /* mov si, dx */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x9)); /* add ax, 0x9 */
    mem_write16(cpu, cpu->ds, 0xC352, (uint16_t)(cpu->ax)); /* mov word ds:[0xC352], ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC359)); /* push word ds:[0xC359] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC352)); /* push word ds:[0xC352] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09A0E(cpu);                           /* call 0xFEA6 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC358)); /* mov al, byte ds:[0xC358] */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si - 0x3CAA), (uint8_t)(cpu->al)); /* mov byte ds:[si+-0x3CAA], al */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F90F(cpu);                           /* call 0x5DA7 */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0181; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->si = (uint16_t)(cpu->dx);           /* mov si, dx */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->si - 0x3CAA))); /* mov al, byte ds:[si+-0x3CAA] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09A0E(cpu);                           /* call 0xFEA6 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _r = cpu->bx ^ 0x1; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, 0x1 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3CAA))); /* mov al, byte ds:[bx+-0x3CAA] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09A0E(cpu);                           /* call 0xFEA6 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_09B68_000206;                  /* jmp 0x0206 */
L_fn_09B68_0001AD:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x30);              /* mov dx, 0x30 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x158)); /* add ax, 0x158 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x23);              /* mov ax, 0x23 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x30);              /* mov ax, 0x30 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x30);              /* mov dx, 0x30 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC8)); /* add ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x684C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x30);              /* mov dx, 0x30 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC8)); /* add ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x23);              /* mov ax, 0x23 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x30);              /* mov ax, 0x30 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x30);              /* mov dx, 0x30 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x10)); /* add ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x684C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_09B68_000206:;
    flags_cmp16(cpu, cpu->si, 0x3);          /* cmp si, 0x3 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_09B68_0001AD;   /* jl 0x01AD */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_09D79(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_09D79");
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0x2DCF */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x2D78 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_09D79_00000D;                  /* jmp 0x000D */
L_fn_09D79_00000D:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1770), 0x0); /* cmp word ds:[0x1770], 0x0 */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_09D79_00000D;  /* jne 0x000D */
    cpu->sp += 2; return;                    /* ret */
}

void fn_09D8E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_09D8E");
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x6440 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x91);              /* mov ax, 0x91 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x130);             /* mov ax, 0x130 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x661A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x91);              /* mov ax, 0x91 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x130);             /* mov ax, 0x130 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x6611 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x125D);            /* mov ax, 0x125D */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_086C9(cpu);                           /* call 0xE93B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->sp += 2; return;                    /* ret */
}

void fn_09DCC(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_09DCC");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0xC35B, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC35B), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0xC35B] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x9)); /* add ax, 0x9 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC352)); /* cmp ax, word ds:[0xC352] */
    if (cc_e(cpu)) goto L_fn_09DCC_000079;   /* je 0x0079 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09D79(cpu);                           /* call 0xFFAD */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC35B), 0x1); /* cmp word ds:[0xC35B], 0x1 */
    if (cc_ne(cpu)) goto L_fn_09DCC_000053;  /* jne 0x0053 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC35D)); /* mov ax, word ds:[0xC35D] */
    cpu->dx = (uint16_t)(0x18);              /* mov dx, 0x18 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xDCC)); /* add bx, 0xDCC */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x17))); /* mov al, byte es:[bx+0x17] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1023)); /* add ax, 0x1023 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xC7A0 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5CC)); /* mov dx, word ds:[0xC5CC] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5CA)); /* mov ax, word ds:[0xC5CA] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07747(cpu);                           /* call 0xD97B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_09DCC_0000F3;                  /* jmp 0x00F3 */
    goto L_fn_09DCC_000079;                  /* jmp 0x0079 */
L_fn_09DCC_000053:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09D8E(cpu);                           /* call 0xFFC2 */
    cpu->al = (uint8_t)(0x4);                /* mov al, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x15), (uint8_t)(cpu->al)); /* mov byte es:[bx+0x15], al */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07343(cpu);                           /* call 0xD577 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_09DCC_0000F3;                  /* jmp 0x00F3 */
L_fn_09DCC_000079:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC35B), 0x1); /* cmp word ds:[0xC35B], 0x1 */
    if (cc_ne(cpu)) goto L_fn_09DCC_00009E;  /* jne 0x009E */
    cpu->al = (uint8_t)(0x4);                /* mov al, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x15), (uint8_t)(cpu->al)); /* mov byte es:[bx+0x15], al */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0734E(cpu);                           /* call 0xD582 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_09DCC_00009E:;
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC359)); /* push word ds:[0xC359] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_099E2(cpu);                           /* call 0xFC16 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC34E)); /* mov si, word ds:[0xC34E] */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC350)); /* mov di, word ds:[0xC350] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC352)); /* push word ds:[0xC352] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_099E2(cpu);                           /* call 0xFC16 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0xC354, (uint16_t)(0x1)); /* mov word ds:[0xC354], 0x1 */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFF48)); /* add ax, 0xFF48 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x1D);              /* mov ax, 0x1D */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x28);              /* mov ax, 0x28 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC350)); /* push word ds:[0xC350] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC34E)); /* push word ds:[0xC34E] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x65E8 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x1D);              /* mov ax, 0x1D */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x28);              /* mov ax, 0x28 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFF48)); /* add ax, 0xFF48 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x65D3 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC35B)); /* mov ax, word ds:[0xC35B] */
    goto L_fn_09DCC_0000F3;                  /* jmp 0x00F3 */
L_fn_09DCC_0000F3:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_09EC3(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_09EC3");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
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
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov dx, word ss:[bp+0x8] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov cx, word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x12))); /* mov ax, word ss:[bp+0x12] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->dx)); /* sub ax, dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x10))); /* mov ax, word ss:[bp+0x10] */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->bx = (uint16_t)(0x1FA3);            /* mov bx, 0x1FA3 */
    cpu->ds = (uint16_t)(cpu->bx);           /* mov ds, bx */
    cpu->bx = (uint16_t)(0x12B0);            /* lea bx, word ds:[0x12B0] */
    cpu->al = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
L_fn_09EC3_000043:;
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->bx = (uint16_t)(0x1FA3);            /* mov bx, 0x1FA3 */
    cpu->ds = (uint16_t)(cpu->bx);           /* mov ds, bx */
    cpu->bx = (uint16_t)(0x12C0);            /* lea bx, word ds:[0x12C0] */
    cpu->al = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
L_fn_09EC3_00004F:;
    flags_cmp16(cpu, cpu->dx, cpu->ax);      /* cmp dx, ax */
    if (cc_le(cpu)) goto L_fn_09EC3_000067;  /* jle 0x0067 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0xF)); /* add si, 0xF */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->ax)); /* sub si, ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0xF)); /* add di, 0xF */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, cpu->ax)); /* sub di, ax */
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 0x10)); /* sub dx, 0x10 */
    RECOMP_TICK(cpu);
    if (cc_g(cpu)) goto L_fn_09EC3_00004F;   /* jg 0x004F */
L_fn_09EC3_000067:;
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->dx)); /* add si, dx */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->dx)); /* add di, dx */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov dx, word ss:[bp+0x8] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)))); /* add si, word ss:[bp+-0x2] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)))); /* add di, word ss:[bp+-0x2] */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_09EC3_000043; /* loop 0x0043 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_09F40(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_09F40");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov di, word ss:[bp+0x8] */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_09F40_0000B8;                  /* jmp 0x00B8 */
L_fn_09F40_00000D:;
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0xCD17 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x5); /* cmp byte ds:[0xBFCD], 0x5 */
    if (cc_ne(cpu)) goto L_fn_09F40_000039;  /* jne 0x0039 */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* push word ss:[bp+0xE] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* push word ss:[bp+0xC] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09EC3(cpu);                           /* call 0xFF83 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x10)); /* add sp, 0x10 */
    goto L_fn_09F40_0000A4;                  /* jmp 0x00A4 */
L_fn_09F40_000039:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x2); /* cmp byte ds:[0xBFCD], 0x2 */
    if (cc_ne(cpu)) goto L_fn_09F40_000073;  /* jne 0x0073 */
    cpu->ax = (uint16_t)(0x50);              /* mov ax, 0x50 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* push word ss:[bp+0xE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov ax, word ss:[bp+0xC] */
    cpu->bx = (uint16_t)(0x4);               /* mov bx, 0x4 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x004F; recomp_div0("idiv16"); } } /* idiv bx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->bx = (uint16_t)(0x4);               /* mov bx, 0x4 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x005B; recomp_div0("idiv16"); } } /* idiv bx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(0x4);               /* mov bx, 0x4 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0068; recomp_div0("idiv16"); } } /* idiv bx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09EC3(cpu);                           /* call 0xFF83 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x10)); /* add sp, 0x10 */
    goto L_fn_09F40_0000A4;                  /* jmp 0x00A4 */
L_fn_09F40_000073:;
    cpu->ax = (uint16_t)(0xA0);              /* mov ax, 0xA0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* push word ss:[bp+0xE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov ax, word ss:[bp+0xC] */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0082; recomp_div0("idiv16"); } } /* idiv bx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x008E; recomp_div0("idiv16"); } } /* idiv bx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x009B; recomp_div0("idiv16"); } } /* idiv bx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09EC3(cpu);                           /* call 0xFF83 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x10)); /* add sp, 0x10 */
L_fn_09F40_0000A4:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* push word ss:[bp+0xE] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* push word ss:[bp+0xC] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x645F */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C6F(cpu);                           /* call 0xCD2F */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_09F40_0000B8:;
    flags_cmp16(cpu, cpu->si, 0x10);         /* cmp si, 0x10 */
    if (cc_ge(cpu)) goto L_fn_09F40_0000C0;  /* jge 0x00C0 */
    RECOMP_TICK(cpu);
    goto L_fn_09F40_00000D;                  /* jmp 0x000D */
L_fn_09F40_0000C0:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A004(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A004");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0A004_000008;                  /* jmp 0x0008 */
L_fn_0A004_000008:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x8] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+0x4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    { uint8_t _r = cpu->al | cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, al */
    if (cc_e(cpu)) goto L_fn_0A004_000026;   /* je 0x0026 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    flags_cmp16(cpu, cpu->ax, 0x3E8);        /* cmp ax, 0x3E8 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0A004_000008;   /* jl 0x0008 */
L_fn_0A004_000026:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    goto L_fn_0A004_00002F;                  /* jmp 0x002F */
L_fn_0A004_00002F:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A036(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A036");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x8)); /* sub sp, 0x8 */
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    cpu->bx = (uint16_t)(cpu->ss);           /* mov bx, ss */
    cpu->es = (uint16_t)(cpu->bx);           /* mov es, bx */
    cpu->bx = (uint16_t)((uint16_t)(cpu->bp + 0x8)); /* lea bx, word ss:[bp+0x8] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x6], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x8], bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    goto L_fn_0A036_000041;                  /* jmp 0x0041 */
L_fn_0A036_000021:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x4))); /* add word ss:[bp+-0x8], 0x4 */
    push16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* push word es:[bx+0x2] */
    push16(cpu, mem_read16(cpu, cpu->es, cpu->bx)); /* push word es:[bx] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A004(cpu);                           /* call 0xFFCE */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
L_fn_0A036_000041:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    { uint16_t _r = cpu->ax | mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)); flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, word es:[bx+0x2] */
    if (cc_e(cpu)) goto L_fn_0A036_000055;   /* je 0x0055 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    flags_cmp16(cpu, cpu->ax, 0x7D0);        /* cmp ax, 0x7D0 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0A036_000021;   /* jl 0x0021 */
L_fn_0A036_000055:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* sub ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(flags_sbb(cpu, cpu->dx, 0x0, 16)); /* sbb dx, 0x0 */
    goto L_fn_0A036_000062;                  /* jmp 0x0062 */
L_fn_0A036_000062:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A09D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A09D");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC470);            /* mov ax, 0xC470 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x3D);              /* mov ax, 0x3D */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0xC80D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC360);            /* mov ax, 0xC360 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x3E);              /* mov ax, 0x3E */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0xC80D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x3C);              /* mov ax, 0x3C */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xC4CF */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0A09D_000059;                  /* jmp 0x0059 */
L_fn_0A09D_00002B:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5C6); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5C6 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5C6] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C8)); /* mov cx, word ds:[0xC5C8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C6)); /* mov bx, word ds:[0xC5C6] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0x190);             /* mov ax, 0x190 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x12);              /* mov dx, 0x12 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x632C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0A09D_000059:;
    flags_cmp16(cpu, cpu->si, 0x3);          /* cmp si, 0x3 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0A09D_00002B;   /* jl 0x002B */
    cpu->ax = (uint16_t)(0x3B);              /* mov ax, 0x3B */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xC4CF */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(0x1B8);             /* mov ax, 0x1B8 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x632C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x3A);              /* mov ax, 0x3A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xC4CF */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(0x1C9);             /* mov ax, 0x1C9 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x632C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x39);              /* mov ax, 0x39 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xC4CF */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A13F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A13F");
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC470);            /* mov ax, 0xC470 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x3D);              /* mov ax, 0x3D */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0643A(cpu);                           /* call 0xC2FB */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC360);            /* mov ax, 0xC360 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x3E);              /* mov ax, 0x3E */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0643A(cpu);                           /* call 0xC2FB */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A15E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A15E");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF5);              /* mov ax, 0xF5 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(0xB);               /* mov dx, 0xB */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x3C)); /* add ax, 0x3C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x28);              /* mov ax, 0x28 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03AB);                           /* call 0x624D */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF5);              /* mov ax, 0xF5 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(0xB);               /* mov dx, 0xB */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x3C)); /* add ax, 0x3C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x28);              /* mov ax, 0x28 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x6241 */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A19D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A19D");
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xEE);              /* mov ax, 0xEE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x7E);              /* mov ax, 0x7E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x28);              /* mov ax, 0x28 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03AB);                           /* call 0x620E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xEE);              /* mov ax, 0xEE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x88);              /* mov ax, 0x88 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x28);              /* mov ax, 0x28 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03AB);                           /* call 0x620E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x14);              /* mov ax, 0x14 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xEE);              /* mov ax, 0xEE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x7E);              /* mov ax, 0x7E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x28);              /* mov ax, 0x28 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x6202 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A1E0(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A1E0");
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xDA);              /* mov ax, 0xDA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x67);              /* mov ax, 0x67 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x32);              /* mov ax, 0x32 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03AB);                           /* call 0x61CB */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xDA);              /* mov ax, 0xDA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x71);              /* mov ax, 0x71 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x32);              /* mov ax, 0x32 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03AB);                           /* call 0x61CB */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x14);              /* mov ax, 0x14 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xDA);              /* mov ax, 0xDA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x67);              /* mov ax, 0x67 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x32);              /* mov ax, 0x32 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x61BF */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A223(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A223");
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0A223_00001F;                  /* jmp 0x001F */
L_fn_0A223_000005:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0x0); /* cmp byte es:[bx], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0A223_00001E;  /* jne 0x001E */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    goto L_fn_0A223_000029;                  /* jmp 0x0029 */
L_fn_0A223_00001E:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0A223_00001F:;
    flags_cmp16(cpu, cpu->si, 0xA);          /* cmp si, 0xA */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0A223_000005;   /* jl 0x0005 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    goto L_fn_0A223_000029;                  /* jmp 0x0029 */
L_fn_0A223_000029:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A24E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A24E");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    goto L_fn_0A24E_000032;                  /* jmp 0x0032 */
L_fn_0A24E_00000A:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->cx = (uint16_t)(0x1B);              /* mov cx, 0x1B */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F937(cpu);                           /* call 0000:F937 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0A24E_000032:;
    flags_cmp16(cpu, cpu->si, 0xA);          /* cmp si, 0xA */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0A24E_00000A;   /* jl 0x000A */
    mem_write8(cpu, cpu->ds, 0xC563, (uint8_t)(0x0)); /* mov byte ds:[0xC563], 0x0 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A28D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A28D");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0xA)); /* sub sp, 0xA */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov si, word ss:[bp+0x8] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0x0); /* cmp byte es:[bx], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0A28D_000017;  /* jne 0x0017 */
    goto L_fn_0A28D_0000AC;                  /* jmp 0x00AC */
L_fn_0A28D_000017:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x2B);              /* mov ax, 0x2B */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xCAAF */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    flags_logic8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xB)) & 0x10); /* test byte es:[bx+0xB], 0x10 */
    if (cc_e(cpu)) goto L_fn_0A28D_00003B;   /* je 0x003B */
    cpu->bx = (uint16_t)(cpu->ds);           /* mov bx, ds */
    cpu->es = (uint16_t)(cpu->bx);           /* mov es, bx */
    cpu->bx = (uint16_t)(0x1650);            /* mov bx, 0x1650 */
    goto L_fn_0A28D_000042;                  /* jmp 0x0042 */
L_fn_0A28D_00003B:;
    cpu->bx = (uint16_t)(cpu->ds);           /* mov bx, ds */
    cpu->es = (uint16_t)(cpu->bx);           /* mov es, bx */
    cpu->bx = (uint16_t)(0x1659);            /* mov bx, 0x1659 */
L_fn_0A28D_000042:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x92);              /* mov ax, 0x92 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xCAAF */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA)), 0x0); /* cmp word ss:[bp+0xA], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0A28D_000098;  /* jne 0x0098 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0xA)); /* lea ax, word ss:[bp+-0xA] */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x9))); /* mov ax, word es:[bx+0x9] */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F25E(cpu);                           /* call 0x4FD1 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0xA)); /* lea ax, word ss:[bp+-0xA] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CF6(cpu);                           /* call 0xCA69 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0xA)); /* lea ax, word ss:[bp+-0xA] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x102);             /* mov ax, 0x102 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->di)); /* sub ax, di */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xCAAF */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    goto L_fn_0A28D_0000AC;                  /* jmp 0x00AC */
L_fn_0A28D_000098:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xB))); /* mov al, byte es:[bx+0xB] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0xDD);              /* mov ax, 0xDD */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_078C3(cpu);                           /* call 0xD636 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_0A28D_0000AC:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A33F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A33F");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x6075 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x5E8F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(0x31);              /* mov di, 0x31 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0A33F_000048;                  /* jmp 0x0048 */
L_fn_0A33F_00002B:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0xB)); /* add di, 0xB */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC470)); /* add ax, 0xC470 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A28D(cpu);                           /* call 0xFF4E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0A33F_000048:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ds, 0xC57E)); /* cmp si, word ds:[0xC57E] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0A33F_00002B;   /* jl 0x002B */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC46E), 0x0); /* cmp word ds:[0xC46E], 0x0 */
    if (cc_e(cpu)) goto L_fn_0A33F_0000AA;   /* je 0x00AA */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x12D9);            /* mov ax, 0x12D9 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07695(cpu);                           /* call 0xD356 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x5E8F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x26);              /* mov ax, 0x26 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x42);              /* mov ax, 0x42 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x11);              /* mov ax, 0x11 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC0);              /* mov ax, 0xC0 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC46E)); /* mov ax, word ds:[0xC46E] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    cpu->dx = (uint16_t)(0x11);              /* mov dx, 0x11 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1B8)); /* add ax, 0x1B8 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x6075 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC46E), 0x1); /* cmp word ds:[0xC46E], 0x1 */
    if (cc_ne(cpu)) goto L_fn_0A33F_0000A8;  /* jne 0x00A8 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x1660);            /* mov ax, 0x1660 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB)); /* add ax, 0xB */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2B);              /* mov ax, 0x2B */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xC9FD */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_0A33F_0000A8:;
    goto L_fn_0A33F_0000B4;                  /* jmp 0x00B4 */
L_fn_0A33F_0000AA:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC57E), 0x0); /* cmp word ds:[0xC57E], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0A33F_0000B4;  /* jne 0x00B4 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06FC3(cpu);                           /* call 0xCC84 */
L_fn_0A33F_0000B4:;
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x6060 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A40A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A40A");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x5DC4 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x5F9E */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x5F95 */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A43C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A43C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(0xF);               /* mov di, 0xF */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    cpu->ax = (uint16_t)(0x17);              /* mov ax, 0x17 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0xC81B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0A43C_0000C6;                  /* jmp 0x00C6 */
L_fn_0A43C_000015:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C87(cpu);                           /* call 0xC84B */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_0A43C_00001F;  /* jne 0x001F */
    goto L_fn_0A43C_0000C6;                  /* jmp 0x00C6 */
L_fn_0A43C_00001F:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_sub16(cpu, 0, cpu->ax)); /* neg ax */
    cpu->ax = (uint16_t)(flags_sbb(cpu, cpu->ax, cpu->ax, 16)); /* sbb ax, ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_0A43C_00003F;   /* je 0x003F */
    { uint16_t _r = cpu->di ^ 0xF; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, 0xF */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A40A(cpu);                           /* call 0xFFCE */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_0A43C_00003F:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x13EF, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x13EF), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x13EF] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13EF)); /* mov ax, word ds:[0x13EF] */
    flags_cmp16(cpu, cpu->ax, 0x3);          /* cmp ax, 0x3 */
    if (cc_l(cpu)) goto L_fn_0A43C_000051;   /* jl 0x0051 */
    mem_write16(cpu, cpu->ds, 0x13EF, (uint16_t)(0x0)); /* mov word ds:[0x13EF], 0x0 */
L_fn_0A43C_000051:;
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12);              /* mov ax, 0x12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x190);             /* mov ax, 0x190 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13EF)); /* mov ax, word ds:[0x13EF] */
    cpu->dx = (uint16_t)(0x12);              /* mov dx, 0x12 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x5F78 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12A);             /* mov ax, 0x12A */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12);              /* mov ax, 0x12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03BA);                           /* call 0x5F7E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12);              /* mov ax, 0x12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x5F63 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12);              /* mov ax, 0x12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12A);             /* mov ax, 0x12A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x5F63 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x17);              /* mov ax, 0x17 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0xC81B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0A43C_0000C6:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B4A(cpu);                           /* call 0xC70E */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_0A43C_0000D0;  /* jne 0x00D0 */
    RECOMP_TICK(cpu);
    goto L_fn_0A43C_000015;                  /* jmp 0x0015 */
L_fn_0A43C_0000D0:;
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A40A(cpu);                           /* call 0xFFCE */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B1A(cpu);                           /* call 0xC6DE */
    goto L_fn_0A43C_0000E5;                  /* jmp 0x00E5 */
L_fn_0A43C_0000E5:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A525(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A525");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(0x5F);              /* mov ax, 0x5F */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x12D0);            /* mov ax, 0x12D0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F304(cpu);                           /* call 0x4DDF */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x64)); /* mov word ss:[bp+-0x2], 0x64 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0A525_00012A;                  /* jmp 0x012A */
L_fn_0A525_000025:;
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x5CA9 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x64);              /* mov ax, 0x64 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x64);              /* mov ax, 0x64 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x60);              /* mov ax, 0x60 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x5E83 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x5CA9 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x12D0);            /* mov ax, 0x12D0 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x64);              /* mov ax, 0x64 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x60);              /* mov ax, 0x60 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xC817 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x64);              /* mov ax, 0x64 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x64);              /* mov ax, 0x64 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x60);              /* mov ax, 0x60 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x5E7A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->si + 0x12D0))); /* mov al, byte ds:[si+0x12D0] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si + 0x12D0), (uint8_t)(0x0)); /* mov byte ds:[si+0x12D0], 0x0 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x12D0);            /* mov ax, 0x12D0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CF6(cpu);                           /* call 0xC7D1 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x61)); /* add di, 0x61 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov al, byte ss:[bp+-0x4] */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si + 0x12D0), (uint8_t)(cpu->al)); /* mov byte ds:[si+0x12D0], al */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A43C(cpu);                           /* call 0xFF17 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    cpu->cx = (uint16_t)(0x4);               /* mov cx, 0x4 */
    cpu->bx = (uint16_t)(0xA5DF);            /* mov bx, 0xA5DF */
L_fn_0A525_0000AB:;
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, SEG_0000, cpu->bx)); /* cmp ax, word cs:[bx] */
    if (cc_e(cpu)) goto L_fn_0A525_0000B6;   /* je 0x00B6 */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0A525_0000AB; /* loop 0x00AB */
    goto L_fn_0A525_0000FE;                  /* jmp 0x00FE */
L_fn_0A525_0000B6:;
    { uint16_t _t = mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x8)); /* jmp word cs:[bx+0x8] */
      switch (_t) {
        case 0xA5FC: goto L_fn_0A525_0000D7;
        case 0xA5EF: goto L_fn_0A525_0000CA;
        case 0xA608: goto L_fn_0A525_0000E3;
        case 0xA612: goto L_fn_0A525_0000ED;
        default: recomp_dispatch(cpu, SEG_0000, _t); return;
      } }
    { uint8_t _r = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si)) | cpu->al; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si), (uint8_t)(_r)); } /* or byte ds:[bx+si], al */
    { uint16_t _r = cpu->ax | 0x1B00; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, 0x1B00 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si)), cpu->ah))); /* add byte ds:[bx+si], ah */
    cpu->ah = (uint8_t)(flags_add8(cpu, cpu->ah, cpu->bh)); /* add ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, mem_read16(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -2 : 2; cpu->di += df(cpu) ? -2 : 2; /* movsw */
    port_out16(cpu, cpu->dx, cpu->ax);       /* out dx, ax */
    mem_write16(cpu, cpu->es, cpu->di, mem_read16(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -2 : 2; cpu->di += df(cpu) ? -2 : 2; /* movsw */
    { uint8_t _r = mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x59EE)) | cpu->ah; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x59EE), (uint8_t)(_r)); } /* or byte ss:[bp+-0x59EE], ah */
L_fn_0A525_0000CA:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_e(cpu)) goto L_fn_0A525_0000D7;   /* je 0x00D7 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si + 0x12D0), (uint8_t)(0x0)); /* mov byte ds:[si+0x12D0], 0x0 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0A525_00012D;                  /* jmp 0x012D */
L_fn_0A525_0000D7:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_le(cpu)) goto L_fn_0A525_0000E1;  /* jle 0x00E1 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si + 0x12D0), (uint8_t)(0x5F)); /* mov byte ds:[si+0x12D0], 0x5F */
L_fn_0A525_0000E1:;
    goto L_fn_0A525_00012A;                  /* jmp 0x012A */
L_fn_0A525_0000E3:;
    mem_write8(cpu, cpu->ds, 0x12D0, (uint8_t)(0x0)); /* mov byte ds:[0x12D0], 0x0 */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_0A525_00012D;                  /* jmp 0x012D */
L_fn_0A525_0000ED:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_e(cpu)) goto L_fn_0A525_0000FC;   /* je 0x00FC */
    flags_cmp16(cpu, cpu->si, 0x8);          /* cmp si, 0x8 */
    if (cc_ge(cpu)) goto L_fn_0A525_0000FC;  /* jge 0x00FC */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si + 0x12D0), (uint8_t)(0x20)); /* mov byte ds:[si+0x12D0], 0x20 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0A525_0000FC:;
    goto L_fn_0A525_00012A;                  /* jmp 0x012A */
L_fn_0A525_0000FE:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x100); /* cmp word ss:[bp+-0x4], 0x100 */
    if (cc_ge(cpu)) goto L_fn_0A525_00012A;  /* jge 0x012A */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov bx, word ss:[bp+-0x4] */
    flags_logic8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x37CB)) & 0xE); /* test byte ds:[bx+0x37CB], 0xE */
    if (cc_e(cpu)) goto L_fn_0A525_00012A;   /* je 0x012A */
    flags_cmp16(cpu, cpu->si, 0x8);          /* cmp si, 0x8 */
    if (cc_ge(cpu)) goto L_fn_0A525_00012A;  /* jge 0x012A */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_ne(cpu)) goto L_fn_0A525_000122;  /* jne 0x0122 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F9BE(cpu);                           /* call 0x5499 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
L_fn_0A525_000122:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov al, byte ss:[bp+-0x4] */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si + 0x12D0), (uint8_t)(cpu->al)); /* mov byte ds:[si+0x12D0], al */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0A525_00012A:;
    RECOMP_TICK(cpu);
    goto L_fn_0A525_000025;                  /* jmp 0x0025 */
L_fn_0A525_00012D:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A658(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A658");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->si = (uint16_t)(0x10);              /* mov si, 0x10 */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B74(cpu);                           /* call 0xC51C */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06990(cpu);                           /* call 0xC338 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xC50E */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0703E(cpu);                           /* call 0xC9E6 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D593(cpu);                           /* call 0x2F3B */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0792C(cpu);                           /* call 0xD2D4 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07925(cpu);                           /* call 0xD2CD */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x5D47 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x13C5);            /* mov ax, 0x13C5 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08480(cpu);                           /* call 0xDE28 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x5B76 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x73);              /* mov ax, 0x73 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x26);              /* mov ax, 0x26 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x5D4A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF6);              /* mov ax, 0xF6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x73);              /* mov ax, 0x73 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x24);              /* mov ax, 0x24 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x5D47 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xEE);              /* mov ax, 0xEE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x7E);              /* mov ax, 0x7E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x28);              /* mov ax, 0x28 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03AB);                           /* call 0x5D53 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x14);              /* mov ax, 0x14 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xEE);              /* mov ax, 0xEE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x7E);              /* mov ax, 0x7E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x28);              /* mov ax, 0x28 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x5D47 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    goto L_fn_0A658_0000E4;                  /* jmp 0x00E4 */
L_fn_0A658_0000A8:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0AF45(cpu);                           /* call 0x08ED */
    cpu->cx = (uint16_t)(0x4);               /* mov cx, 0x4 */
    cpu->bx = (uint16_t)(0xA718);            /* mov bx, 0xA718 */
L_fn_0A658_0000B1:;
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, SEG_0000, cpu->bx)); /* cmp ax, word cs:[bx] */
    if (cc_e(cpu)) goto L_fn_0A658_0000BC;   /* je 0x00BC */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0A658_0000B1; /* loop 0x00B1 */
    goto L_fn_0A658_0000E4;                  /* jmp 0x00E4 */
L_fn_0A658_0000BC:;
    { uint16_t _t = mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x8)); /* jmp word cs:[bx+0x8] */
      switch (_t) {
        case 0xA738: goto L_fn_0A658_0000E0;
        case 0xA728: goto L_fn_0A658_0000D0;
        case 0xA72F: goto L_fn_0A658_0000D7;
        default: recomp_dispatch(cpu, SEG_0000, _t); return;
      } }
    { uint16_t _r = cpu->ax | 0x1B00; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, 0x1B00 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1)), cpu->cl))); /* add byte ds:[bx+si+0x1], cl */
    push16(cpu, cpu->ax);                    /* push ax */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si)), cpu->di))); /* add word ds:[bx+si], di */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, cpu->si), mem_read16(cpu, cpu->es, cpu->di)); cpu->si += df(cpu) ? -2 : 2; cpu->di += df(cpu) ? -2 : 2; /* cmpsw */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x58D1), (uint8_t)(flags_sub8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x58D1)), cpu->ah))); /* sub byte ds:[bx+-0x58D1], ah */
    bcd_das(cpu);                            /* das */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, cpu->si), mem_read16(cpu, cpu->es, cpu->di)); cpu->si += df(cpu) ? -2 : 2; cpu->di += df(cpu) ? -2 : 2; /* cmpsw */
L_fn_0A658_0000D0:;
    cpu->di = (uint16_t)(0x1);               /* mov di, 0x1 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0A658_0000E4;                  /* jmp 0x00E4 */
L_fn_0A658_0000D7:;
    { uint16_t _r = cpu->si ^ 0x30; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, 0x30 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A19D(cpu);                           /* call 0xFB45 */
    goto L_fn_0A658_0000E4;                  /* jmp 0x00E4 */
L_fn_0A658_0000E0:;
    cpu->di = (uint16_t)(cpu->si);           /* mov di, si */
    goto L_fn_0A658_0000E4;                  /* jmp 0x00E4 */
L_fn_0A658_0000E4:;
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    RECOMP_TICK(cpu);
    if (cc_e(cpu)) goto L_fn_0A658_0000A8;   /* je 0x00A8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08453(cpu);                           /* call 0xDDFB */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x0); /* cmp word ss:[bp+-0x2], 0x0 */
    if (cc_e(cpu)) goto L_fn_0A658_0000F4;   /* je 0x00F4 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0791E(cpu);                           /* call 0xD2C6 */
L_fn_0A658_0000F4:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5A6(cpu);                           /* call 0x2F4E */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07162(cpu);                           /* call 0xCB0A */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x0); /* cmp word ss:[bp+-0x4], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0A658_000103;  /* jne 0x0103 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06997(cpu);                           /* call 0xC33F */
L_fn_0A658_000103:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xC50E */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    goto L_fn_0A658_00010A;                  /* jmp 0x010A */
L_fn_0A658_00010A:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A768(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A768");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    cpu->di = (uint16_t)(0xFFFF);            /* mov di, 0xFFFF */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B74(cpu);                           /* call 0xC40C */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D593(cpu);                           /* call 0x2E2B */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0792C(cpu);                           /* call 0xD1C4 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07925(cpu);                           /* call 0xD1BD */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06990(cpu);                           /* call 0xC228 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0703E(cpu);                           /* call 0xC8D6 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x13D9);            /* mov ax, 0x13D9 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08480(cpu);                           /* call 0xDD18 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x5A66 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xDA);              /* mov ax, 0xDA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x5F);              /* mov ax, 0x5F */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x32);              /* mov ax, 0x32 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x5C3A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xDA);              /* mov ax, 0xDA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x5F);              /* mov ax, 0x5F */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x32);              /* mov ax, 0x32 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x5C37 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xDA);              /* mov ax, 0xDA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x67);              /* mov ax, 0x67 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x32);              /* mov ax, 0x32 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03AB);                           /* call 0x5C43 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x14);              /* mov ax, 0x14 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xDA);              /* mov ax, 0xDA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x67);              /* mov ax, 0x67 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x32);              /* mov ax, 0x32 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x5C37 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    goto L_fn_0A768_0000CD;                  /* jmp 0x00CD */
L_fn_0A768_000091:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B1A(cpu);                           /* call 0xC3B2 */
    cpu->cx = (uint16_t)(0x4);               /* mov cx, 0x4 */
    cpu->bx = (uint16_t)(0xA811);            /* mov bx, 0xA811 */
L_fn_0A768_00009A:;
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, SEG_0000, cpu->bx)); /* cmp ax, word cs:[bx] */
    if (cc_e(cpu)) goto L_fn_0A768_0000A5;   /* je 0x00A5 */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0A768_00009A; /* loop 0x009A */
    goto L_fn_0A768_0000CD;                  /* jmp 0x00CD */
L_fn_0A768_0000A5:;
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x8))); return; /* jmp word cs:[bx+0x8] */
    { uint16_t _r = cpu->ax | 0x1B00; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, 0x1B00 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1)), cpu->cl))); /* add byte ds:[bx+si+0x1], cl */
    push16(cpu, cpu->ax);                    /* push ax */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di)), cpu->si))); /* add word ds:[bx+di], si */
    flags_logic8(cpu, cpu->al & 0x21);       /* test al, 0x21 */
    flags_logic8(cpu, cpu->al & 0x28);       /* test al, 0x28 */
    flags_logic8(cpu, cpu->al & 0x28);       /* test al, 0x28 */
    flags_logic8(cpu, cpu->al & 0xBF);       /* test al, 0xBF */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si)), cpu->ax))); /* add word ds:[bx+si], ax */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0A768_0000CD;                  /* jmp 0x00CD */
    { uint16_t _r = cpu->si ^ 0x1; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, 0x1 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A1E0(cpu);                           /* call 0xFA78 */
    goto L_fn_0A768_0000CD;                  /* jmp 0x00CD */
    cpu->di = (uint16_t)(cpu->si);           /* mov di, si */
    goto L_fn_0A768_0000CD;                  /* jmp 0x00CD */
L_fn_0A768_0000CD:;
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0A768_000091;   /* jl 0x0091 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08453(cpu);                           /* call 0xDCEB */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07162(cpu);                           /* call 0xC9FA */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x0); /* cmp word ss:[bp+-0x4], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0A768_0000E0;  /* jne 0x00E0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06997(cpu);                           /* call 0xC22F */
L_fn_0A768_0000E0:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x0); /* cmp word ss:[bp+-0x2], 0x0 */
    if (cc_e(cpu)) goto L_fn_0A768_0000E9;   /* je 0x00E9 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0791E(cpu);                           /* call 0xD1B6 */
L_fn_0A768_0000E9:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5A6(cpu);                           /* call 0x2E3E */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    goto L_fn_0A768_0000F0;                  /* jmp 0x00F0 */
L_fn_0A768_0000F0:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0A85E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0A85E");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC57E), 0xA); /* cmp word ds:[0xC57E], 0xA */
    if (cc_ne(cpu)) goto L_fn_0A85E_000025;  /* jne 0x0025 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x1389);            /* mov ax, 0x1389 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_086C9(cpu);                           /* call 0xDE6B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0xC46E, (uint16_t)(0x2)); /* mov word ds:[0xC46E], 0x2 */
    cpu->ax = (uint16_t)(0xFFFE);            /* mov ax, 0xFFFE */
    goto L_fn_0A85E_0001BB;                  /* jmp 0x01BB */
L_fn_0A85E_000025:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B74(cpu);                           /* call 0xC316 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06990(cpu);                           /* call 0xC132 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xC308 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0703E(cpu);                           /* call 0xC7E0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D593(cpu);                           /* call 0x2D35 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0792C(cpu);                           /* call 0xD0CE */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07925(cpu);                           /* call 0xD0C7 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x1375);            /* mov ax, 0x1375 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08480(cpu);                           /* call 0xDC22 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x5970 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x13);              /* mov ax, 0x13 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x78);              /* mov ax, 0x78 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x5F);              /* mov ax, 0x5F */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x58);              /* mov ax, 0x58 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00355(cpu);                           /* call 0x5AF7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x13);              /* mov ax, 0x13 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x78);              /* mov ax, 0x78 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x5F);              /* mov ax, 0x5F */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x58);              /* mov ax, 0x58 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x5B41 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A525(cpu);                           /* call 0xFCC7 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08453(cpu);                           /* call 0xDBF5 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x0); /* cmp word ss:[bp+-0x2], 0x0 */
    if (cc_e(cpu)) goto L_fn_0A85E_000092;   /* je 0x0092 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0791E(cpu);                           /* call 0xD0C0 */
L_fn_0A85E_000092:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5A6(cpu);                           /* call 0x2D48 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07162(cpu);                           /* call 0xC904 */
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    if (cc_ne(cpu)) goto L_fn_0A85E_00009F;  /* jne 0x009F */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06997(cpu);                           /* call 0xC139 */
L_fn_0A85E_00009F:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xC308 */
    flags_cmp16(cpu, cpu->si, 0xFFFF);       /* cmp si, 0xFFFF */
    if (cc_g(cpu)) goto L_fn_0A85E_0000AA;   /* jg 0x00AA */
    goto L_fn_0A85E_0001A7;                  /* jmp 0x01A7 */
L_fn_0A85E_0000AA:;
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC57E)); /* mov si, word ds:[0xC57E] */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1B);              /* mov ax, 0x1B */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(0xC470);            /* mov bx, 0xC470 */
    cpu->cx = (uint16_t)(cpu->ds);           /* mov cx, ds */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F304(cpu);                           /* call 0x4AA6 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A658(cpu);                           /* call 0xFDFA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xB), (uint8_t)(cpu->al)); /* mov byte es:[bx+0xB], al */
    { uint8_t _r = cpu->al | cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, al */
    if (cc_ne(cpu)) goto L_fn_0A85E_0000EA;  /* jne 0x00EA */
    goto L_fn_0A85E_00019C;                  /* jmp 0x019C */
L_fn_0A85E_0000EA:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x15), (uint8_t)(0x4)); /* mov byte es:[bx+0x15], 0x4 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x9), (uint16_t)(0x1)); /* mov word es:[bx+0x9], 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x176E)); /* mov ax, word ds:[0x176E] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xD), (uint16_t)(cpu->ax)); /* mov word es:[bx+0xD], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1772)); /* mov ax, word ds:[0x1772] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xF), (uint16_t)(cpu->ax)); /* mov word es:[bx+0xF], ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xB)), 0x10); /* cmp byte es:[bx+0xB], 0x10 */
    if (cc_ne(cpu)) goto L_fn_0A85E_00016E;  /* jne 0x016E */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x11), (uint16_t)(0x1)); /* mov word es:[bx+0x11], 0x1 */
L_fn_0A85E_00016E:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x13), (uint16_t)(0xFFFF)); /* mov word es:[bx+0x13], 0xFFFF */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x12D0);            /* mov ax, 0x12D0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC470)); /* add ax, 0xC470 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F2DB(cpu);                           /* call 0x4A7D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    goto L_fn_0A85E_0001A5;                  /* jmp 0x01A5 */
L_fn_0A85E_00019C:;
    mem_write16(cpu, cpu->ds, 0xC46E, (uint16_t)(0x1)); /* mov word ds:[0xC46E], 0x1 */
    cpu->si = (uint16_t)(0xFFFE);            /* mov si, 0xFFFE */
L_fn_0A85E_0001A5:;
    goto L_fn_0A85E_0001B7;                  /* jmp 0x01B7 */
L_fn_0A85E_0001A7:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC57E), 0x0); /* cmp word ds:[0xC57E], 0x0 */
    if (cc_e(cpu)) goto L_fn_0A85E_0001B7;   /* je 0x01B7 */
    mem_write16(cpu, cpu->ds, 0xC46E, (uint16_t)(0x1)); /* mov word ds:[0xC46E], 0x1 */
    cpu->si = (uint16_t)(0xFFFE);            /* mov si, 0xFFFE */
L_fn_0A85E_0001B7:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    goto L_fn_0A85E_0001BB;                  /* jmp 0x01BB */
L_fn_0A85E_0001BB:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0AA1F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0AA1F");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0xCC)); /* sub sp, 0xCC */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC46E), 0x1); /* cmp word ds:[0xC46E], 0x1 */
    if (cc_ne(cpu)) goto L_fn_0AA1F_000019;  /* jne 0x0019 */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC57E)); /* mov si, word ds:[0xC57E] */
    cpu->di = (uint16_t)(cpu->si);           /* mov di, si */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    goto L_fn_0AA1F_00001F;                  /* jmp 0x001F */
L_fn_0AA1F_000019:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC57E)); /* mov di, word ds:[0xC57E] */
L_fn_0AA1F_00001F:;
    goto L_fn_0AA1F_00013E;                  /* jmp 0x013E */
L_fn_0AA1F_000022:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xCC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xCC], ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A15E(cpu);                           /* call 0xF73F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xC147 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0AF45(cpu);                           /* call 0x0526 */
    cpu->cx = (uint16_t)(0x5);               /* mov cx, 0x5 */
    cpu->bx = (uint16_t)(0xAA68);            /* mov bx, 0xAA68 */
L_fn_0AA1F_000039:;
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, SEG_0000, cpu->bx)); /* cmp ax, word cs:[bx] */
    if (cc_e(cpu)) goto L_fn_0AA1F_000045;   /* je 0x0045 */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0AA1F_000039; /* loop 0x0039 */
    goto L_fn_0AA1F_000136;                  /* jmp 0x0136 */
L_fn_0AA1F_000045:;
    { uint16_t _t = mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0xA)); /* jmp word cs:[bx+0xA] */
      switch (_t) {
        case 0xAAB5: goto L_fn_0AA1F_000096;
        case 0xAB3B: goto L_fn_0AA1F_00011C;
        case 0xAA94: goto L_fn_0AA1F_000075;
        case 0xAA87: goto L_fn_0AA1F_000068;
        case 0xAA7C: goto L_fn_0AA1F_00005D;
        default: recomp_dispatch(cpu, SEG_0000, _t); return;
      } }
    { uint16_t _r = cpu->ax | 0x1200; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, 0x1200 */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di)), cpu->bl))); /* add byte ss:[bp+di], bl */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1)), cpu->cl))); /* add byte ds:[bx+si+0x1], cl */
    push16(cpu, cpu->ax);                    /* push ax */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x3BAA), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x3BAA)), cpu->si))); /* add word ds:[di+0x3BAA], si */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    { uint16_t _t = cpu->ax; cpu->ax = (uint16_t)(cpu->sp); cpu->sp = (uint16_t)(_t); } /* xchg ax, sp */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    { uint16_t _t = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->si - 0x5584)); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->si - 0x5584), (uint16_t)(cpu->bp)); cpu->bp = (uint16_t)(_t); } /* xchg word ss:[bp+si+-0x5584], bp */
L_fn_0AA1F_00005D:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->di; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0061; recomp_div0("idiv16"); } } /* idiv di */
    cpu->si = (uint16_t)(cpu->dx);           /* mov si, dx */
    goto L_fn_0AA1F_000136;                  /* jmp 0x0136 */
L_fn_0AA1F_000068:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->di)); /* add ax, di */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->di; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x006E; recomp_div0("idiv16"); } } /* idiv di */
    cpu->si = (uint16_t)(cpu->dx);           /* mov si, dx */
    goto L_fn_0AA1F_000136;                  /* jmp 0x0136 */
L_fn_0AA1F_000075:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xCC))); /* push word ss:[bp+-0xCC] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A15E(cpu);                           /* call 0xF73F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC46E), 0x1); /* cmp word ds:[0xC46E], 0x1 */
    if (cc_ne(cpu)) goto L_fn_0AA1F_00008A;  /* jne 0x008A */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_0AA1F_000141;                  /* jmp 0x0141 */
L_fn_0AA1F_00008A:;
    mem_write16(cpu, cpu->ds, 0xC46E, (uint16_t)(0x1)); /* mov word ds:[0xC46E], 0x1 */
    cpu->ax = (uint16_t)(0xFFFE);            /* mov ax, 0xFFFE */
    goto L_fn_0AA1F_000141;                  /* jmp 0x0141 */
L_fn_0AA1F_000096:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xCC))); /* push word ss:[bp+-0xCC] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A15E(cpu);                           /* call 0xF73F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ds, 0xC57E)); /* cmp si, word ds:[0xC57E] */
    if (cc_ne(cpu)) goto L_fn_0AA1F_0000B2;  /* jne 0x00B2 */
    mem_write16(cpu, cpu->ds, 0xC46E, (uint16_t)(0x0)); /* mov word ds:[0xC46E], 0x0 */
    cpu->ax = (uint16_t)(0xFFFE);            /* mov ax, 0xFFFE */
    goto L_fn_0AA1F_000141;                  /* jmp 0x0141 */
    goto L_fn_0AA1F_000118;                  /* jmp 0x0118 */
L_fn_0AA1F_0000B2:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC46E), 0x2); /* cmp word ds:[0xC46E], 0x2 */
    if (cc_ne(cpu)) goto L_fn_0AA1F_000118;  /* jne 0x0118 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x1356);            /* mov ax, 0x1356 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC470)); /* add ax, 0xC470 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x12E5);            /* mov ax, 0x12E5 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0xC8)); /* lea ax, word ss:[bp+-0xC8] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A036(cpu);                           /* call 0xF617 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x14)); /* add sp, 0x14 */
    cpu->bx = (uint16_t)(cpu->ss);           /* mov bx, ss */
    cpu->es = (uint16_t)(cpu->bx);           /* mov es, bx */
    cpu->bx = (uint16_t)((uint16_t)(cpu->bp - 0xC8)); /* lea bx, word ss:[bp+-0xC8] */
    mem_write16(cpu, cpu->ds, 0x13BA, (uint16_t)(cpu->es)); /* mov word ds:[0x13BA], es */
    mem_write16(cpu, cpu->ds, 0x13B8, (uint16_t)(cpu->bx)); /* mov word ds:[0x13B8], bx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x13B1);            /* mov ax, 0x13B1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_086C9(cpu);                           /* call 0xDCAA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xCA), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xCA], ax */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_l(cpu)) goto L_fn_0AA1F_000113;   /* jl 0x0113 */
    mem_write16(cpu, cpu->ds, 0xC46E, (uint16_t)(0x1)); /* mov word ds:[0xC46E], 0x1 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xCA)), 0x0); /* cmp word ss:[bp+-0xCA], 0x0 */
    if (cc_e(cpu)) goto L_fn_0AA1F_000113;   /* je 0x0113 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A24E(cpu);                           /* call 0xF82F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0AA1F_000113:;
    cpu->ax = (uint16_t)(0xFFFE);            /* mov ax, 0xFFFE */
    goto L_fn_0AA1F_000141;                  /* jmp 0x0141 */
L_fn_0AA1F_000118:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    goto L_fn_0AA1F_000141;                  /* jmp 0x0141 */
L_fn_0AA1F_00011C:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC46E), 0x1); /* cmp word ds:[0xC46E], 0x1 */
    if (cc_ne(cpu)) goto L_fn_0AA1F_000136;  /* jne 0x0136 */
    mem_write16(cpu, cpu->ds, 0xC46E, (uint16_t)(0x2)); /* mov word ds:[0xC46E], 0x2 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xCC))); /* push word ss:[bp+-0xCC] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A15E(cpu);                           /* call 0xF73F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xFFFE);            /* mov ax, 0xFFFE */
    goto L_fn_0AA1F_000141;                  /* jmp 0x0141 */
L_fn_0AA1F_000136:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xCC))); /* push word ss:[bp+-0xCC] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A15E(cpu);                           /* call 0xF73F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0AA1F_00013E:;
    RECOMP_TICK(cpu);
    goto L_fn_0AA1F_000022;                  /* jmp 0x0022 */
L_fn_0AA1F_000141:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0AB66(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0AB66");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B74(cpu);                           /* call 0xC00E */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07925(cpu);                           /* call 0xCDBF */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0x1FE2 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C834(cpu);                           /* call 0x1CCE */
    mem_write16(cpu, cpu->ds, 0x237E, (uint16_t)(0xFFFF)); /* mov word ds:[0x237E], 0xFFFF */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D593(cpu);                           /* call 0x2A2D */
    mem_write16(cpu, cpu->ds, 0x98, (uint16_t)(0x0)); /* mov word ds:[0x98], 0x0 */
    mem_write16(cpu, cpu->ds, 0x9A, (uint16_t)(0x9F)); /* mov word ds:[0x9A], 0x9F */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A09D(cpu);                           /* call 0xF537 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x5863 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x5668 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A223(cpu);                           /* call 0xF6BD */
    mem_write16(cpu, cpu->ds, 0xC57E, (uint16_t)(cpu->ax)); /* mov word ds:[0xC57E], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0xF9)); /* mov word ss:[bp+-0x4], 0xF9 */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_0AB66_000079;                  /* jmp 0x0079 */
L_fn_0AB66_00005A:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0xB))); /* add word ss:[bp+-0x4], 0xB */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC470)); /* add ax, 0xC470 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A28D(cpu);                           /* call 0xF727 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_0AB66_000079:;
    flags_cmp16(cpu, cpu->di, mem_read16(cpu, cpu->ds, 0xC57E)); /* cmp di, word ds:[0xC57E] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0AB66_00005A;   /* jl 0x005A */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09F40(cpu);                           /* call 0xF3DA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x5863 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    mem_write16(cpu, cpu->ds, 0xC46E, (uint16_t)(0x1)); /* mov word ds:[0xC46E], 0x1 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06990(cpu);                           /* call 0xBE2A */
L_fn_0AB66_0000B8:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A223(cpu);                           /* call 0xF6BD */
    mem_write16(cpu, cpu->ds, 0xC57E, (uint16_t)(cpu->ax)); /* mov word ds:[0xC57E], ax */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_0AB66_0000C8;  /* jne 0x00C8 */
    mem_write16(cpu, cpu->ds, 0xC46E, (uint16_t)(0x0)); /* mov word ds:[0xC46E], 0x0 */
L_fn_0AB66_0000C8:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xC000 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A33F(cpu);                           /* call 0xF7D9 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC46E), 0x0); /* cmp word ds:[0xC46E], 0x0 */
    if (cc_e(cpu)) goto L_fn_0AB66_0000DC;   /* je 0x00DC */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0AA1F(cpu);                           /* call 0xFEB9 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    goto L_fn_0AB66_0000E1;                  /* jmp 0x00E1 */
L_fn_0AB66_0000DC:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A85E(cpu);                           /* call 0xFCF8 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
L_fn_0AB66_0000E1:;
    flags_cmp16(cpu, cpu->si, 0xFFFF);       /* cmp si, 0xFFFF */
    if (cc_ne(cpu)) goto L_fn_0AB66_0000F8;  /* jne 0x00F8 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x139D);            /* mov ax, 0x139D */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_086C9(cpu);                           /* call 0xDB63 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, cpu->ax, 0x1);          /* cmp ax, 0x1 */
    if (cc_e(cpu)) goto L_fn_0AB66_0000F8;   /* je 0x00F8 */
    cpu->si = (uint16_t)(0xFFFE);            /* mov si, 0xFFFE */
L_fn_0AB66_0000F8:;
    flags_cmp16(cpu, cpu->si, 0xFFFF);       /* cmp si, 0xFFFF */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0AB66_0000B8;   /* jl 0x00B8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A13F(cpu);                           /* call 0xF5D9 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x0); /* cmp word ss:[bp+-0x2], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0AB66_000109;  /* jne 0x0109 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06997(cpu);                           /* call 0xBE31 */
L_fn_0AB66_000109:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x5668 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x5842 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x5839 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    mem_write16(cpu, cpu->ds, 0x98, (uint16_t)(0x4)); /* mov word ds:[0x98], 0x4 */
    mem_write16(cpu, cpu->ds, 0x9A, (uint16_t)(0x9B)); /* mov word ds:[0x9A], 0x9B */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xD))); /* mov ax, word es:[bx+0xD] */
    mem_write16(cpu, cpu->ds, 0x176E, (uint16_t)(cpu->ax)); /* mov word ds:[0x176E], ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xF))); /* mov ax, word es:[bx+0xF] */
    mem_write16(cpu, cpu->ds, 0x1772, (uint16_t)(cpu->ax)); /* mov word ds:[0x1772], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5A6(cpu);                           /* call 0x2A40 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    mem_write16(cpu, cpu->ds, 0x13ED, (uint16_t)(cpu->ax)); /* mov word ds:[0x13ED], ax */
    goto L_fn_0AB66_00017B;                  /* jmp 0x017B */
L_fn_0AB66_00017B:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0ACE7(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0ACE7");
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xB))); /* mov al, byte es:[bx+0xB] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _r = cpu->ax & 0x20; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x20 */
    flags_cmp16(cpu, cpu->ax, 0x20);         /* cmp ax, 0x20 */
    if (cc_ne(cpu)) goto L_fn_0ACE7_000022;  /* jne 0x0022 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_0ACE7_000024;                  /* jmp 0x0024 */
L_fn_0ACE7_000022:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_0ACE7_000024:;
    goto L_fn_0ACE7_000026;                  /* jmp 0x0026 */
L_fn_0ACE7_000026:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_0AD0E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0AD0E");
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xB))); /* mov al, byte es:[bx+0xB] */
    goto L_fn_0AD0E_000016;                  /* jmp 0x0016 */
L_fn_0AD0E_000016:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_0AD25(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0AD25");
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0AD25_000044;                  /* jmp 0x0044 */
L_fn_0AD25_000005:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC360)); /* add bx, 0xC360 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0x0); /* cmp byte es:[bx], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0AD25_000043;  /* jne 0x0043 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC360)); /* add bx, 0xC360 */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->cx = (uint16_t)(0x1B);              /* mov cx, 0x1B */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F937(cpu);                           /* call 0000:F937 */
    goto L_fn_0AD25_000049;                  /* jmp 0x0049 */
L_fn_0AD25_000043:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0AD25_000044:;
    flags_cmp16(cpu, cpu->si, 0xA);          /* cmp si, 0xA */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0AD25_000005;   /* jl 0x0005 */
L_fn_0AD25_000049:;
    flags_cmp16(cpu, cpu->si, 0xA);          /* cmp si, 0xA */
    if (cc_ne(cpu)) goto L_fn_0AD25_00009D;  /* jne 0x009D */
    cpu->si = (uint16_t)(0x1);               /* mov si, 0x1 */
    goto L_fn_0AD25_00007B;                  /* jmp 0x007B */
L_fn_0AD25_000053:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC360)); /* add bx, 0xC360 */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC360)); /* add bx, 0xC360 */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->cx = (uint16_t)(0x1B);              /* mov cx, 0x1B */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F937(cpu);                           /* call 0000:F937 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0AD25_00007B:;
    flags_cmp16(cpu, cpu->si, 0xA);          /* cmp si, 0xA */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0AD25_000053;   /* jl 0x0053 */
    cpu->bx = (uint16_t)(0xC453);            /* mov bx, 0xC453 */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->cx = (uint16_t)(0x1B);              /* mov cx, 0x1B */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F937(cpu);                           /* call 0000:F937 */
L_fn_0AD25_00009D:;
    push16(cpu, mem_read16(cpu, cpu->ds, 0x13ED)); /* push word ds:[0x13ED] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A24E(cpu);                           /* call 0xF529 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A13F(cpu);                           /* call 0xF41A */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0ADCF(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0ADCF");
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0ADCF_000044;                  /* jmp 0x0044 */
L_fn_0ADCF_000005:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC360)); /* add bx, 0xC360 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0x0); /* cmp byte es:[bx], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0ADCF_000043;  /* jne 0x0043 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC360)); /* add bx, 0xC360 */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->cx = (uint16_t)(0x1B);              /* mov cx, 0x1B */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F937(cpu);                           /* call 0000:F937 */
    goto L_fn_0ADCF_000049;                  /* jmp 0x0049 */
L_fn_0ADCF_000043:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0ADCF_000044:;
    flags_cmp16(cpu, cpu->si, 0xA);          /* cmp si, 0xA */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0ADCF_000005;   /* jl 0x0005 */
L_fn_0ADCF_000049:;
    flags_cmp16(cpu, cpu->si, 0xA);          /* cmp si, 0xA */
    if (cc_ne(cpu)) goto L_fn_0ADCF_00009D;  /* jne 0x009D */
    cpu->si = (uint16_t)(0x1);               /* mov si, 0x1 */
    goto L_fn_0ADCF_00007B;                  /* jmp 0x007B */
L_fn_0ADCF_000053:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC360)); /* add bx, 0xC360 */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC360)); /* add bx, 0xC360 */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->cx = (uint16_t)(0x1B);              /* mov cx, 0x1B */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F937(cpu);                           /* call 0000:F937 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0ADCF_00007B:;
    flags_cmp16(cpu, cpu->si, 0xA);          /* cmp si, 0xA */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0ADCF_000053;   /* jl 0x0053 */
    cpu->bx = (uint16_t)(0xC453);            /* mov bx, 0xC453 */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->cx = (uint16_t)(0x1B);              /* mov cx, 0x1B */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F937(cpu);                           /* call 0000:F937 */
L_fn_0ADCF_00009D:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xB), (uint8_t)(0x20)); /* mov byte es:[bx+0xB], 0x20 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x15), (uint8_t)(0x4)); /* mov byte es:[bx+0x15], 0x4 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x9), (uint16_t)(0x1)); /* mov word es:[bx+0x9], 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x11), (uint16_t)(0x0)); /* mov word es:[bx+0x11], 0x0 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC), (uint8_t)(0x0)); /* mov byte es:[bx+0xC], 0x0 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x16), (uint8_t)(0x0)); /* mov byte es:[bx+0x16], 0x0 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x17), (uint8_t)(0x0)); /* mov byte es:[bx+0x17], 0x0 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x18), (uint8_t)(0x0)); /* mov byte es:[bx+0x18], 0x0 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x19), (uint8_t)(0x0)); /* mov byte es:[bx+0x19], 0x0 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1A), (uint8_t)(0x0)); /* mov byte es:[bx+0x1A], 0x0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A13F(cpu);                           /* call 0xF370 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0AF45(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0AF45");
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12);              /* mov ax, 0x12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x190);             /* mov ax, 0x190 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13EF)); /* mov ax, word ds:[0x13EF] */
    cpu->dx = (uint16_t)(0x12);              /* mov dx, 0x12 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x546F */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12A);             /* mov ax, 0x12A */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12);              /* mov ax, 0x12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03BA);                           /* call 0x5475 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x11D);             /* mov ax, 0x11D */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12);              /* mov ax, 0x12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x546F */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x11D);             /* mov ax, 0x11D */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12A);             /* mov ax, 0x12A */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12);              /* mov ax, 0x12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12A);             /* mov ax, 0x12A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x546F */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12);              /* mov ax, 0x12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x545A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12);              /* mov ax, 0x12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12A);             /* mov ax, 0x12A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x545A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x17);              /* mov ax, 0x17 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0xBD12 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0AF45_000145;                  /* jmp 0x0145 */
L_fn_0AF45_0000B4:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C87(cpu);                           /* call 0xBD42 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_0AF45_0000BE;  /* jne 0x00BE */
    goto L_fn_0AF45_000145;                  /* jmp 0x0145 */
L_fn_0AF45_0000BE:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x13EF, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x13EF), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x13EF] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13EF)); /* mov ax, word ds:[0x13EF] */
    flags_cmp16(cpu, cpu->ax, 0x3);          /* cmp ax, 0x3 */
    if (cc_l(cpu)) goto L_fn_0AF45_0000D0;   /* jl 0x00D0 */
    mem_write16(cpu, cpu->ds, 0x13EF, (uint16_t)(0x0)); /* mov word ds:[0x13EF], 0x0 */
L_fn_0AF45_0000D0:;
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12);              /* mov ax, 0x12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x190);             /* mov ax, 0x190 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13EF)); /* mov ax, word ds:[0x13EF] */
    cpu->dx = (uint16_t)(0x12);              /* mov dx, 0x12 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x546F */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12A);             /* mov ax, 0x12A */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12);              /* mov ax, 0x12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03BA);                           /* call 0x5475 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12);              /* mov ax, 0x12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x545A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12);              /* mov ax, 0x12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12A);             /* mov ax, 0x12A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x545A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x17);              /* mov ax, 0x17 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0xBD12 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0AF45_000145:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B4A(cpu);                           /* call 0xBC05 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_0AF45_00014F;  /* jne 0x014F */
    RECOMP_TICK(cpu);
    goto L_fn_0AF45_0000B4;                  /* jmp 0x00B4 */
L_fn_0AF45_00014F:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B1A(cpu);                           /* call 0xBBD5 */
    goto L_fn_0AF45_000154;                  /* jmp 0x0154 */
L_fn_0AF45_000154:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_0B09A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0B09A");
    cpu->ax = (uint16_t)(0x47);              /* mov ax, 0x47 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xB4D2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x532F */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x158);             /* mov ax, 0x158 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x531A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x48);              /* mov ax, 0x48 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xB4D2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x190)); /* mov word ds:[0x96], 0x190 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(0xD3);              /* mov ax, 0xD3 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x72);              /* mov ax, 0x72 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x5332 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x9F)); /* mov word ds:[0x96], 0x9F */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x531A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0B122(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0B122");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    cpu->ax = (uint16_t)(0x52);              /* mov ax, 0x52 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xB44A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x54);              /* mov ax, 0x54 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9BFC);            /* mov ax, 0x9BFC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F39C(cpu);                           /* call 0x427A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->ax = (uint16_t)(0x53);              /* mov ax, 0x53 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xB44A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x54);              /* mov ax, 0x54 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xBF66);            /* mov ax, 0xBF66 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F39C(cpu);                           /* call 0x427A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC5A8);            /* mov ax, 0xC5A8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x49);              /* mov ax, 0x49 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0xB728 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0B122_000082;                  /* jmp 0x0082 */
L_fn_0B122_000055:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5A8); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5A8 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5A8] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5AA)); /* mov cx, word ds:[0xC5AA] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5A8)); /* mov bx, word ds:[0xC5A8] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F82), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4F82], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F84), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4F84], ax */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0B122_000082:;
    flags_cmp16(cpu, cpu->si, 0xC);          /* cmp si, 0xC */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B122_000055;   /* jl 0x0055 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC580);            /* mov ax, 0xC580 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4A);              /* mov ax, 0x4A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0xB728 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0B122_0000C7;                  /* jmp 0x00C7 */
L_fn_0B122_00009A:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC580); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC580 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC580] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC582)); /* mov cx, word ds:[0xC582] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC580)); /* mov bx, word ds:[0xC580] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F82), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4F82], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F84), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4F84], ax */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0B122_0000C7:;
    flags_cmp16(cpu, cpu->si, 0x8);          /* cmp si, 0x8 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B122_00009A;   /* jl 0x009A */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC5AC);            /* mov ax, 0xC5AC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4B);              /* mov ax, 0x4B */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0xB728 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0B122_00010C;                  /* jmp 0x010C */
L_fn_0B122_0000DF:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5AC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5AC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5AC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5AE)); /* mov cx, word ds:[0xC5AE] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5AC)); /* mov bx, word ds:[0xC5AC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F82), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4F82], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F84), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4F84], ax */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0B122_00010C:;
    flags_cmp16(cpu, cpu->si, 0xA);          /* cmp si, 0xA */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B122_0000DF;   /* jl 0x00DF */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC59A);            /* mov ax, 0xC59A */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4C);              /* mov ax, 0x4C */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0xB728 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0B122_000151;                  /* jmp 0x0151 */
L_fn_0B122_000124:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC59A); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC59A + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC59A] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC59C)); /* mov cx, word ds:[0xC59C] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC59A)); /* mov bx, word ds:[0xC59A] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F82), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4F82], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F84), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4F84], ax */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0B122_000151:;
    flags_cmp16(cpu, cpu->si, 0x11);         /* cmp si, 0x11 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B122_000124;   /* jl 0x0124 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC5A4);            /* mov ax, 0xC5A4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4D);              /* mov ax, 0x4D */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0xB728 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0B122_000196;                  /* jmp 0x0196 */
L_fn_0B122_000169:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5A4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5A4 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5A4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5A6)); /* mov cx, word ds:[0xC5A6] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5A4)); /* mov bx, word ds:[0xC5A4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F82), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4F82], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F84), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4F84], ax */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0B122_000196:;
    flags_cmp16(cpu, cpu->si, 0x4);          /* cmp si, 0x4 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B122_000169;   /* jl 0x0169 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC58A);            /* mov ax, 0xC58A */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4E);              /* mov ax, 0x4E */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0xB728 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC58C)); /* mov dx, word ds:[0xC58C] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC58A)); /* mov ax, word ds:[0xC58A] */
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F82), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4F82], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F84), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4F84], ax */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC58E);            /* mov ax, 0xC58E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4F);              /* mov ax, 0x4F */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0xB728 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0B122_000200;                  /* jmp 0x0200 */
L_fn_0B122_0001D3:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC58E); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC58E + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC58E] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC590)); /* mov cx, word ds:[0xC590] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC58E)); /* mov bx, word ds:[0xC58E] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F82), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4F82], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F84), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4F84], ax */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0B122_000200:;
    flags_cmp16(cpu, cpu->si, 0xC);          /* cmp si, 0xC */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B122_0001D3;   /* jl 0x01D3 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC584);            /* mov ax, 0xC584 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x50);              /* mov ax, 0x50 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0xB728 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0B122_000245;                  /* jmp 0x0245 */
L_fn_0B122_000218:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC584); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC584 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC584] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC586)); /* mov cx, word ds:[0xC586] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC584)); /* mov bx, word ds:[0xC584] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F82), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4F82], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F84), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4F84], ax */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0B122_000245:;
    flags_cmp16(cpu, cpu->si, 0x4);          /* cmp si, 0x4 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B122_000218;   /* jl 0x0218 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC59E);            /* mov ax, 0xC59E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x51);              /* mov ax, 0x51 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0xB728 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0B122_00028A;                  /* jmp 0x028A */
L_fn_0B122_00025D:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC59E); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC59E + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC59E] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5A0)); /* mov cx, word ds:[0xC5A0] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC59E)); /* mov bx, word ds:[0xC59E] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F82), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4F82], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F84), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4F84], ax */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0B122_00028A:;
    flags_cmp16(cpu, cpu->si, 0x1);          /* cmp si, 0x1 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B122_00025D;   /* jl 0x025D */
    goto L_fn_0B122_0002A7;                  /* jmp 0x02A7 */
L_fn_0B122_000291:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB07E)); /* mov dx, word ds:[0xB07E] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB07C)); /* mov ax, word ds:[0xB07C] */
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F82), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4F82], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F84), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4F84], ax */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_0B122_0002A7:;
    flags_cmp16(cpu, cpu->di, 0x54);         /* cmp di, 0x54 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B122_000291;   /* jl 0x0291 */
    mem_write16(cpu, cpu->ds, 0x720, (uint16_t)(0x2)); /* mov word ds:[0x720], 0x2 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0B3D7(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0B3D7");
    cpu->ax = (uint16_t)(0x54);              /* mov ax, 0x54 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xB195 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x4FF2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x4FDD */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0B40F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0B40F");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    cpu->ax = (uint16_t)(0x57);              /* mov ax, 0x57 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xB15D */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x54);              /* mov ax, 0x54 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9BFC);            /* mov ax, 0x9BFC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F39C(cpu);                           /* call 0x3F8D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->ax = (uint16_t)(0x58);              /* mov ax, 0x58 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xB15D */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x54);              /* mov ax, 0x54 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xBF66);            /* mov ax, 0xBF66 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F39C(cpu);                           /* call 0x3F8D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC592);            /* mov ax, 0xC592 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x55);              /* mov ax, 0x55 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0xB43B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_0B40F_000082;                  /* jmp 0x0082 */
L_fn_0B40F_000055:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC592); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC592 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC592] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC594)); /* mov cx, word ds:[0xC594] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC592)); /* mov bx, word ds:[0xC592] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F82), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4F82], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F84), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4F84], ax */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_0B40F_000082:;
    flags_cmp16(cpu, cpu->di, 0x2);          /* cmp di, 0x2 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B40F_000055;   /* jl 0x0055 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC596);            /* mov ax, 0xC596 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x56);              /* mov ax, 0x56 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0xB43B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_0B40F_0000C7;                  /* jmp 0x00C7 */
L_fn_0B40F_00009A:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC596); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC596 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC596] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC598)); /* mov cx, word ds:[0xC598] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC596)); /* mov bx, word ds:[0xC596] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F82), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4F82], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F84), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4F84], ax */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_0B40F_0000C7:;
    flags_cmp16(cpu, cpu->di, 0xC);          /* cmp di, 0xC */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B40F_00009A;   /* jl 0x009A */
    goto L_fn_0B40F_0000E4;                  /* jmp 0x00E4 */
L_fn_0B40F_0000CE:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB07E)); /* mov dx, word ds:[0xB07E] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB07C)); /* mov ax, word ds:[0xB07C] */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F82), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4F82], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F84), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4F84], ax */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0B40F_0000E4:;
    flags_cmp16(cpu, cpu->si, 0x54);         /* cmp si, 0x54 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B40F_0000CE;   /* jl 0x00CE */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0B4FB(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0B4FB");
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2A0);             /* mov ax, 0x2A0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x40D4);            /* mov ax, 0x40D4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F304(cpu);                           /* call 0x3E09 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    mem_write8(cpu, cpu->ds, 0x411C, (uint8_t)(0x3)); /* mov byte ds:[0x411C], 0x3 */
    mem_write8(cpu, cpu->ds, 0x411D, (uint8_t)(0x9)); /* mov byte ds:[0x411D], 0x9 */
    mem_write8(cpu, cpu->ds, 0x411E, (uint8_t)(0xD)); /* mov byte ds:[0x411E], 0xD */
    mem_write8(cpu, cpu->ds, 0x411F, (uint8_t)(0x11)); /* mov byte ds:[0x411F], 0x11 */
    mem_write8(cpu, cpu->ds, 0x4120, (uint8_t)(0x6)); /* mov byte ds:[0x4120], 0x6 */
    mem_write8(cpu, cpu->ds, 0x4121, (uint8_t)(0x9)); /* mov byte ds:[0x4121], 0x9 */
    mem_write8(cpu, cpu->ds, 0x4122, (uint8_t)(0x10)); /* mov byte ds:[0x4122], 0x10 */
    mem_write8(cpu, cpu->ds, 0x4123, (uint8_t)(0x11)); /* mov byte ds:[0x4123], 0x11 */
    mem_write8(cpu, cpu->ds, 0x4274, (uint8_t)(0xF)); /* mov byte ds:[0x4274], 0xF */
    mem_write8(cpu, cpu->ds, 0x4275, (uint8_t)(0x5)); /* mov byte ds:[0x4275], 0x5 */
    mem_write8(cpu, cpu->ds, 0x4276, (uint8_t)(0x2F)); /* mov byte ds:[0x4276], 0x2F */
    mem_write8(cpu, cpu->ds, 0x4277, (uint8_t)(0x22)); /* mov byte ds:[0x4277], 0x22 */
    mem_write8(cpu, cpu->ds, 0x4278, (uint8_t)(0xC)); /* mov byte ds:[0x4278], 0xC */
    mem_write8(cpu, cpu->ds, 0x4279, (uint8_t)(0x5)); /* mov byte ds:[0x4279], 0x5 */
    mem_write8(cpu, cpu->ds, 0x427A, (uint8_t)(0x2C)); /* mov byte ds:[0x427A], 0x2C */
    mem_write8(cpu, cpu->ds, 0x427B, (uint8_t)(0x22)); /* mov byte ds:[0x427B], 0x22 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0B55E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0B55E");
    push16(cpu, mem_read16(cpu, cpu->ds, 0x7354)); /* push word ds:[0x7354] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x7352)); /* push word ds:[0x7352] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x4165 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x7358)); /* push word ds:[0x7358] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x7356)); /* push word ds:[0x7356] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x4165 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x735C)); /* push word ds:[0x735C] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x735A)); /* push word ds:[0x735A] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x4165 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xBFCA)); /* push word ds:[0xBFCA] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xBFC8)); /* push word ds:[0xBFC8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x4165 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0B593(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0B593");
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5AA)); /* push word ds:[0xC5AA] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5A8)); /* push word ds:[0xC5A8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x4130 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC582)); /* push word ds:[0xC582] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC580)); /* push word ds:[0xC580] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x4130 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5AE)); /* push word ds:[0xC5AE] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5AC)); /* push word ds:[0xC5AC] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x4130 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC59C)); /* push word ds:[0xC59C] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC59A)); /* push word ds:[0xC59A] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x4130 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5A6)); /* push word ds:[0xC5A6] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5A4)); /* push word ds:[0xC5A4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x4130 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC58C)); /* push word ds:[0xC58C] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC58A)); /* push word ds:[0xC58A] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x4130 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC590)); /* push word ds:[0xC590] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC58E)); /* push word ds:[0xC58E] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x4130 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC586)); /* push word ds:[0xC586] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC584)); /* push word ds:[0xC584] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x4130 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5A0)); /* push word ds:[0xC5A0] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC59E)); /* push word ds:[0xC59E] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x4130 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x720, (uint16_t)(0x0)); /* mov word ds:[0x720], 0x0 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0B60F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0B60F");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0xA)); /* sub sp, 0xA */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ds)); /* mov word ss:[bp+-0x2], ds */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0xB3AF)); /* mov word ss:[bp+-0x4], 0xB3AF */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(0x0)); /* mov word ss:[bp+-0xA], 0x0 */
    goto L_fn_0B60F_0000AB;                  /* jmp 0x00AB */
L_fn_0B60F_000018:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x8)), 0x0); /* cmp byte es:[bx+0x8], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B60F_000025;   /* je 0x0025 */
    goto L_fn_0B60F_0000A4;                  /* jmp 0x00A4 */
L_fn_0B60F_000025:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xBFBA)); /* cmp ax, word ds:[0xBFBA] */
    if (cc_ne(cpu)) goto L_fn_0B60F_0000A4;  /* jne 0x00A4 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov si, word es:[bx+0x2] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x6))); /* mov al, byte es:[bx+0x6] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x6404))); /* mov al, byte ds:[bx+-0x6404] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->ax)); /* add dx, ax */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x8], dx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4))); /* mov di, word es:[bx+0x4] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x6))); /* mov al, byte es:[bx+0x6] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x409A))); /* mov al, byte ds:[bx+-0x409A] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->ax)); /* add dx, ax */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x6], dx */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_ge(cpu)) goto L_fn_0B60F_00007B;  /* jge 0x007B */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
L_fn_0B60F_00007B:;
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    if (cc_ge(cpu)) goto L_fn_0B60F_000081;  /* jge 0x0081 */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
L_fn_0B60F_000081:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x0); /* cmp word ss:[bp+-0x8], 0x0 */
    if (cc_l(cpu)) goto L_fn_0B60F_0000A4;   /* jl 0x00A4 */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->di)); /* sub ax, di */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->si)); /* sub ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC8)); /* add ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x4DA5 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
L_fn_0B60F_0000A4:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0xA] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x20))); /* add word ss:[bp+-0x4], 0x20 */
L_fn_0B60F_0000AB:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xB3AE)); /* mov al, byte ds:[0xB3AE] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* cmp ax, word ss:[bp+-0xA] */
    if (cc_le(cpu)) goto L_fn_0B60F_0000B8;  /* jle 0x00B8 */
    RECOMP_TICK(cpu);
    goto L_fn_0B60F_000018;                  /* jmp 0x0018 */
L_fn_0B60F_0000B8:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0B6CD(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0B6CD");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07925(cpu);                           /* call 0xC258 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06FC3(cpu);                           /* call 0xB8F6 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0x8FE, (uint16_t)(cpu->ax)); /* mov word ds:[0x8FE], ax */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(cpu->ax)); /* mov word ds:[0xBC], ax */
    mem_write16(cpu, cpu->ds, 0xBFBA, (uint16_t)(cpu->ax)); /* mov word ds:[0xBFBA], ax */
    mem_write16(cpu, cpu->ds, 0x40CE, (uint16_t)(0x1)); /* mov word ds:[0x40CE], 0x1 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0x98, (uint16_t)(cpu->ax)); /* mov word ds:[0x98], ax */
    mem_write16(cpu, cpu->ds, 0x94, (uint16_t)(cpu->ax)); /* mov word ds:[0x94], ax */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x1E8)); /* mov word ds:[0x96], 0x1E8 */
    mem_write16(cpu, cpu->ds, 0x9A, (uint16_t)(0xA0)); /* mov word ds:[0x9A], 0xA0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0B3D7(cpu);                           /* call 0xFD0A */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0B40F(cpu);                           /* call 0xFD42 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04EEB(cpu);                           /* call 0x981E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x4CD2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x1)); /* mov word ds:[0xBC], 0x1 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
L_fn_0B6CD_000055:;
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0xB58A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5CA] */
    mem_write16(cpu, cpu->ds, 0x40C6, (uint16_t)(cpu->es)); /* mov word ds:[0x40C6], es */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->bx)); /* mov word ds:[0x40C4], bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0B60F(cpu);                           /* call 0xFF42 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04B0C(cpu);                           /* call 0x943F */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40C6)); /* mov dx, word ds:[0x40C6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40C4)); /* mov ax, word ds:[0x40C4] */
    flags_cmp16(cpu, cpu->dx, mem_read16(cpu, cpu->ds, 0xC5CC)); /* cmp dx, word ds:[0xC5CC] */
    if (cc_ne(cpu)) goto L_fn_0B6CD_000082;  /* jne 0x0082 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC5CA)); /* cmp ax, word ds:[0xC5CA] */
    if (cc_e(cpu)) goto L_fn_0B6CD_000085;   /* je 0x0085 */
L_fn_0B6CD_000082:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01ECD(cpu);                           /* call 0x6800 */
L_fn_0B6CD_000085:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C6F(cpu);                           /* call 0xB5A2 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    flags_cmp16(cpu, cpu->ax, 0xC8);         /* cmp ax, 0xC8 */
    if (cc_ne(cpu)) goto L_fn_0B6CD_000096;  /* jne 0x0096 */
    mem_write16(cpu, cpu->ds, 0x1776, (uint16_t)(0x0)); /* mov word ds:[0x1776], 0x0 */
L_fn_0B6CD_000096:;
    flags_cmp16(cpu, cpu->si, 0xC8);         /* cmp si, 0xC8 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B6CD_000055;   /* jl 0x0055 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1784), 0x0); /* cmp word ds:[0x1784], 0x0 */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_0B6CD_000055;  /* jne 0x0055 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0B772(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0B772");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x6)); /* sub sp, 0x6 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->al = (uint8_t)(0x0);                /* mov al, 0x0 */
    mem_write8(cpu, cpu->ds, 0xB52F, (uint8_t)(cpu->al)); /* mov byte ds:[0xB52F], al */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ds, 0xC588, (uint16_t)(cpu->ax)); /* mov word ds:[0xC588], ax */
    mem_write16(cpu, cpu->ds, 0xC5A2, (uint16_t)(0xD)); /* mov word ds:[0xC5A2], 0xD */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xB3AE)); /* mov al, byte ds:[0xB3AE] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov di, word ss:[bp+-0x2] */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->di; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, cl */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->si = (uint16_t)(0x5);               /* mov si, 0x5 */
    goto L_fn_0B772_00007C;                  /* jmp 0x007C */
L_fn_0B772_00002D:;
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, cl */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4C51)), 0x0); /* cmp byte ds:[bx+-0x4C51], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0B772_00007A;  /* jne 0x007A */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, cl */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4C4B)), 0x9); /* cmp byte ds:[bx+-0x4C4B], 0x9 */
    if (cc_ne(cpu)) goto L_fn_0B772_00007A;  /* jne 0x007A */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, cl */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xB3BC)); /* add bx, 0xB3BC */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x4], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x6], bx */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFB)); /* add ax, 0xFFFB */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0062; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->dx = (uint16_t)(0x3);               /* mov dx, 0x3 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->di)); /* add ax, di */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x6) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x6] */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(cpu->ax)); /* mov word es:[bx], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x6) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x6] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4), (uint16_t)(0x0)); /* mov word es:[bx+0x4], 0x0 */
L_fn_0B772_00007A:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0B772_00007C:;
    flags_cmp16(cpu, cpu->si, 0xB);          /* cmp si, 0xB */
    RECOMP_TICK(cpu);
    if (cc_le(cpu)) goto L_fn_0B772_00002D;  /* jle 0x002D */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0B7F9(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0B7F9");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(0x48);              /* mov ax, 0x48 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xAD73 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x0)); /* mov word ds:[0xBC], 0x0 */
    mem_write8(cpu, cpu->ds, 0xB437, (uint8_t)(0x1)); /* mov byte ds:[0xB437], 0x1 */
    mem_write8(cpu, cpu->ds, 0xB477, (uint8_t)(0x1)); /* mov byte ds:[0xB477], 0x1 */
    mem_write8(cpu, cpu->ds, 0xB4B7, (uint8_t)(0x1)); /* mov byte ds:[0xB4B7], 0x1 */
    mem_write8(cpu, cpu->ds, 0xB4F7, (uint8_t)(0x1)); /* mov byte ds:[0xB4F7], 0x1 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0x134F */
    mem_write16(cpu, cpu->ds, 0x1774, (uint16_t)(0x1)); /* mov word ds:[0x1774], 0x1 */
    cpu->ax = (uint16_t)(0x19);              /* mov ax, 0x19 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x12F8 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(0x76);              /* mov si, 0x76 */
    goto L_fn_0B7F9_0000BD;                  /* jmp 0x00BD */
L_fn_0B7F9_00003B:;
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0xB45E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1B);              /* mov ax, 0x1B */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFC)); /* add ax, 0xFFFC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x75);              /* mov ax, 0x75 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x5C);              /* mov ax, 0x5C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x163);             /* mov ax, 0x163 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFC)); /* add ax, 0xFFFC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x4BBB */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(0x1B);              /* mov ax, 0x1B */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x4BD3 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ds, 0xB571, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xB571), 0x4))); /* add word ds:[0xB571], 0x4 */
    mem_write16(cpu, cpu->ds, 0xB591, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xB591), 0x4))); /* add word ds:[0xB591], 0x4 */
    mem_write16(cpu, cpu->ds, 0xB5B1, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xB5B1), 0x4))); /* add word ds:[0xB5B1], 0x4 */
    mem_write16(cpu, cpu->ds, 0xB5F1, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xB5F1), 0x4))); /* add word ds:[0xB5F1], 0x4 */
    mem_write16(cpu, cpu->ds, 0xB631, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xB631), 0x4))); /* add word ds:[0xB631], 0x4 */
    mem_write16(cpu, cpu->ds, 0xB671, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xB671), 0x4))); /* add word ds:[0xB671], 0x4 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04B0C(cpu);                           /* call 0x9313 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02269(cpu);                           /* call 0x6A70 */
    cpu->ax = (uint16_t)(0x75);              /* mov ax, 0x75 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x60);              /* mov ax, 0x60 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1B);              /* mov ax, 0x1B */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFC)); /* add ax, 0xFFFC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x4BA6 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C6F(cpu);                           /* call 0xB476 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x4)); /* add si, 0x4 */
L_fn_0B7F9_0000BD:;
    flags_cmp16(cpu, cpu->si, 0xC6);         /* cmp si, 0xC6 */
    if (cc_g(cpu)) goto L_fn_0B7F9_0000C6;   /* jg 0x00C6 */
    RECOMP_TICK(cpu);
    goto L_fn_0B7F9_00003B;                  /* jmp 0x003B */
L_fn_0B7F9_0000C6:;
    mem_write16(cpu, cpu->ds, 0x1774, (uint16_t)(0x0)); /* mov word ds:[0x1774], 0x0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0x134F */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02269(cpu);                           /* call 0x6A70 */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x1E8)); /* mov word ds:[0x96], 0x1E8 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(0x163);             /* mov ax, 0x163 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFC)); /* add ax, 0xFFFC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x4BD3 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x158);             /* mov ax, 0x158 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x4BBB */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x9F)); /* mov word ds:[0x96], 0x9F */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x1)); /* mov word ds:[0xBC], 0x1 */
    mem_write8(cpu, cpu->ds, 0xB6CF, (uint8_t)(0x0)); /* mov byte ds:[0xB6CF], 0x0 */
    cpu->ax = (uint16_t)(0x45);              /* mov ax, 0x45 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5F9(cpu);                           /* call 0x1E00 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_0B7F9_000152;                  /* jmp 0x0152 */
L_fn_0B7F9_00012E:;
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0xB45E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5CA] */
    mem_write16(cpu, cpu->ds, 0x40C6, (uint16_t)(cpu->es)); /* mov word ds:[0x40C6], es */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->bx)); /* mov word ds:[0x40C4], bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04E9F(cpu);                           /* call 0x96A6 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04B0C(cpu);                           /* call 0x9313 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02269(cpu);                           /* call 0x6A70 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01ECD(cpu);                           /* call 0x66D4 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C6F(cpu);                           /* call 0xB476 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_0B7F9_000152:;
    flags_cmp16(cpu, cpu->di, 0x14);         /* cmp di, 0x14 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B7F9_00012E;   /* jl 0x012E */
    cpu->di = (uint16_t)(0x1B1);             /* mov di, 0x1B1 */
    goto L_fn_0B7F9_000165;                  /* jmp 0x0165 */
L_fn_0B7F9_00015C:;
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->di), (uint8_t)(0x7)); /* mov byte es:[bx+di], 0x7 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_0B7F9_000165:;
    flags_cmp16(cpu, cpu->di, 0x1B8);        /* cmp di, 0x1B8 */
    RECOMP_TICK(cpu);
    if (cc_le(cpu)) goto L_fn_0B7F9_00015C;  /* jle 0x015C */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0B967(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0B967");
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(0x7)); /* mov byte es:[bx], 0x7 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04B0C(cpu);                           /* call 0x91A5 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01ECD(cpu);                           /* call 0x6566 */
    goto L_fn_0B967_000030;                  /* jmp 0x0030 */
L_fn_0B967_000010:;
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0xB2F0 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5CA] */
    mem_write16(cpu, cpu->ds, 0x40C6, (uint16_t)(cpu->es)); /* mov word ds:[0x40C6], es */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->bx)); /* mov word ds:[0x40C4], bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04E9F(cpu);                           /* call 0x9538 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04B0C(cpu);                           /* call 0x91A5 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01ECD(cpu);                           /* call 0x6566 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C6F(cpu);                           /* call 0xB308 */
L_fn_0B967_000030:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xB6CF), 0x0); /* cmp byte ds:[0xB6CF], 0x0 */
    RECOMP_TICK(cpu);
    if (cc_e(cpu)) goto L_fn_0B967_000010;   /* je 0x0010 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0B99F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0B99F");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x94)); /* sub sp, 0x94 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0x8FE, (uint16_t)(cpu->ax)); /* mov word ds:[0x8FE], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    mem_write16(cpu, cpu->ds, 0xC5A2, (uint16_t)(cpu->ax)); /* mov word ds:[0xC5A2], ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(cpu->ax)); /* mov word ds:[0xBC], ax */
    mem_write16(cpu, cpu->ds, 0xC588, (uint16_t)(cpu->ax)); /* mov word ds:[0xC588], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(0x2)); /* mov word ss:[bp+-0xA], 0x2 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0B99F_000061;                  /* jmp 0x0061 */
L_fn_0B99F_000032:;
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    cpu->cx = (uint16_t)(cpu->ss);           /* mov cx, ss */
    cpu->bx = (uint16_t)((uint16_t)(cpu->bp - 0x90)); /* lea bx, word ss:[bp+-0x90] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    cpu->bx = (uint16_t)(0xB3AF);            /* mov bx, 0xB3AF */
    cpu->cx = (uint16_t)(cpu->ds);           /* mov cx, ds */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0x39A9 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0B99F_000061:;
    flags_cmp16(cpu, cpu->si, 0x4);          /* cmp si, 0x4 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B99F_000032;   /* jl 0x0032 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5A2)); /* mov bx, word ds:[0xC5A2] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x1684))); /* mov bx, word ds:[bx+0x1684] */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, cl */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4C51), (uint8_t)(0x0)); /* mov byte ds:[bx+-0x4C51], 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x92), (uint16_t)(0x0)); /* mov word ss:[bp+-0x92], 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x94), (uint16_t)(0x0)); /* mov word ss:[bp+-0x94], 0x0 */
L_fn_0B99F_000085:;
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0xB2B8 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(cpu->di)); /* mov word ss:[bp+-0x10], di */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    mem_write16(cpu, cpu->ds, 0x40CE, (uint16_t)(cpu->ax)); /* mov word ds:[0x40CE], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)), 0x0); /* cmp word ss:[bp+-0xA], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_0000DE;   /* je 0x00DE */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5A2)); /* mov bx, word ds:[0xC5A2] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x1684))); /* mov bx, word ds:[bx+0x1684] */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, cl */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4C51)), 0x0); /* cmp byte ds:[bx+-0x4C51], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_0000DC;   /* je 0x00DC */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0xC5A2, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC5A2), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0xC5A2] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5A2)); /* mov bx, word ds:[0xC5A2] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x1684)), 0x0); /* cmp word ds:[bx+0x1684], 0x0 */
    if (cc_ge(cpu)) goto L_fn_0B99F_0000C9;  /* jge 0x00C9 */
    mem_write16(cpu, cpu->ds, 0xC5A2, (uint16_t)(0x0)); /* mov word ds:[0xC5A2], 0x0 */
L_fn_0B99F_0000C9:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5A2)); /* mov bx, word ds:[0xC5A2] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x1684))); /* mov bx, word ds:[bx+0x1684] */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, cl */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4C51), (uint8_t)(0x0)); /* mov byte ds:[bx+-0x4C51], 0x0 */
L_fn_0B99F_0000DC:;
    goto L_fn_0B99F_000145;                  /* jmp 0x0145 */
L_fn_0B99F_0000DE:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x0); /* cmp word ss:[bp+-0x8], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0B99F_0000F7;  /* jne 0x00F7 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xB6AF), 0x0); /* cmp byte ds:[0xB6AF], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0B99F_0000F7;  /* jne 0x00F7 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(0x1)); /* mov word ss:[bp+-0x8], 0x1 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(0x14)); /* mov word ss:[bp+-0x6], 0x14 */
    goto L_fn_0B99F_000145;                  /* jmp 0x0145 */
L_fn_0B99F_0000F7:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6)), 0x0); /* cmp word ss:[bp+-0x6], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_000145;   /* je 0x0145 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ss:[bp+-0x6] */
    if (cc_ne(cpu)) goto L_fn_0B99F_000145;  /* jne 0x0145 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ACE7(cpu);                           /* call 0xF348 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_0B99F_00010E;   /* je 0x010E */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0B7F9(cpu);                           /* call 0xFE5A */
    goto L_fn_0B99F_000145;                  /* jmp 0x0145 */
L_fn_0B99F_00010E:;
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x0)); /* mov word ds:[0xBC], 0x0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ADCF(cpu);                           /* call 0xF430 */
    mem_write16(cpu, cpu->ds, 0x1776, (uint16_t)(0x0)); /* mov word ds:[0x1776], 0x0 */
    goto L_fn_0B99F_00011F;                  /* jmp 0x011F */
L_fn_0B99F_00011F:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1784), 0x0); /* cmp word ds:[0x1784], 0x0 */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_0B99F_00011F;  /* jne 0x011F */
    mem_write16(cpu, cpu->ds, 0x1776, (uint16_t)(0x1)); /* mov word ds:[0x1776], 0x1 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x1670);            /* mov ax, 0x1670 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_086C9(cpu);                           /* call 0xCD2A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x8BFE);            /* mov ax, 0x8BFE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F98B(cpu);                           /* call 0x3FEC */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_0B99F_000145:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B4A(cpu);                           /* call 0xB1AB */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_0B99F_000172;   /* je 0x0172 */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x0)); /* mov word ds:[0xBC], 0x0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B1A(cpu);                           /* call 0xB17B */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x10], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 0xD); /* cmp word ss:[bp+-0x10], 0xD */
    if (cc_ne(cpu)) goto L_fn_0B99F_000163;  /* jne 0x0163 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0727D(cpu);                           /* call 0xB8DE */
    goto L_fn_0B99F_00016C;                  /* jmp 0x016C */
L_fn_0B99F_000163:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 0x1B); /* cmp word ss:[bp+-0x10], 0x1B */
    if (cc_ne(cpu)) goto L_fn_0B99F_00016C;  /* jne 0x016C */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CE2A(cpu);                           /* call 0x148B */
L_fn_0B99F_00016C:;
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x1)); /* mov word ds:[0xBC], 0x1 */
L_fn_0B99F_000172:;
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5CA] */
    mem_write16(cpu, cpu->ds, 0x40C6, (uint16_t)(cpu->es)); /* mov word ds:[0x40C6], es */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->bx)); /* mov word ds:[0x40C4], bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_022B1(cpu);                           /* call 0x6912 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04E9F(cpu);                           /* call 0x9500 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x8FE), 0x0); /* cmp word ds:[0x8FE], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_00018E;   /* je 0x018E */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05E98(cpu);                           /* call 0xA4F9 */
L_fn_0B99F_00018E:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB6E), 0x0); /* cmp word ds:[0xB6E], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0B99F_000198;  /* jne 0x0198 */
    goto L_fn_0B99F_000221;                  /* jmp 0x0221 */
L_fn_0B99F_000198:;
    mem_write16(cpu, cpu->ds, 0x73A, (uint16_t)(0x0)); /* mov word ds:[0x73A], 0x0 */
    cpu->ax = (uint16_t)(0x27);              /* mov ax, 0x27 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1C)); /* add ax, 0x1C */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F91(cpu);                           /* call 0x65F2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_0B99F_00021E;  /* jne 0x021E */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x734)); /* mov ax, word ds:[0x734] */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x736), cpu->ax))); /* add word ds:[0x736], ax */
    cpu->di = (uint16_t)(0x1);               /* mov di, 0x1 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x72E), 0x8); /* cmp word ds:[0x72E], 0x8 */
    if (cc_g(cpu)) goto L_fn_0B99F_0001DC;   /* jg 0x01DC */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x72E), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x72E] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x72E)); /* mov ax, word ds:[0x72E] */
    flags_cmp16(cpu, cpu->ax, 0x8);          /* cmp ax, 0x8 */
    if (cc_le(cpu)) goto L_fn_0B99F_0001DC;  /* jle 0x01DC */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0x1)); /* mov word ds:[0x72E], 0x1 */
L_fn_0B99F_0001DC:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC588), 0x0); /* cmp word ds:[0xC588], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_00021E;   /* je 0x021E */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0B99F_000216;                  /* jmp 0x0216 */
L_fn_0B99F_0001E7:;
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    cpu->bx = (uint16_t)(0xB3AF);            /* mov bx, 0xB3AF */
    cpu->cx = (uint16_t)(cpu->ds);           /* mov cx, ds */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    cpu->cx = (uint16_t)(cpu->ss);           /* mov cx, ss */
    cpu->bx = (uint16_t)((uint16_t)(cpu->bp - 0x90)); /* lea bx, word ss:[bp+-0x90] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0x39A9 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0B99F_000216:;
    flags_cmp16(cpu, cpu->si, 0x4);          /* cmp si, 0x4 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B99F_0001E7;   /* jl 0x01E7 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0B772(cpu);                           /* call 0xFDD3 */
L_fn_0B99F_00021E:;
    goto L_fn_0B99F_0002AE;                  /* jmp 0x02AE */
L_fn_0B99F_000221:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB6C), 0x0); /* cmp word ds:[0xB6C], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0B99F_00022B;  /* jne 0x022B */
    goto L_fn_0B99F_0002AE;                  /* jmp 0x02AE */
L_fn_0B99F_00022B:;
    mem_write16(cpu, cpu->ds, 0x73A, (uint16_t)(0x1)); /* mov word ds:[0x73A], 0x1 */
    cpu->ax = (uint16_t)(0x27);              /* mov ax, 0x27 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x736)); /* push word ds:[0x736] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F91(cpu);                           /* call 0x65F2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_0B99F_0002AE;  /* jne 0x02AE */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x734)); /* mov ax, word ds:[0x734] */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x736), cpu->ax))); /* sub word ds:[0x736], ax */
    cpu->di = (uint16_t)(0xFFFF);            /* mov di, 0xFFFF */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x72E), 0x8); /* cmp word ds:[0x72E], 0x8 */
    if (cc_g(cpu)) goto L_fn_0B99F_00026C;   /* jg 0x026C */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x72E), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x72E] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x72E)); /* mov ax, word ds:[0x72E] */
    flags_cmp16(cpu, cpu->ax, 0x8);          /* cmp ax, 0x8 */
    if (cc_le(cpu)) goto L_fn_0B99F_00026C;  /* jle 0x026C */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0x1)); /* mov word ds:[0x72E], 0x1 */
L_fn_0B99F_00026C:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC588), 0x0); /* cmp word ds:[0xC588], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_0002AE;   /* je 0x02AE */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0B99F_0002A6;                  /* jmp 0x02A6 */
L_fn_0B99F_000277:;
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    cpu->bx = (uint16_t)(0xB3AF);            /* mov bx, 0xB3AF */
    cpu->cx = (uint16_t)(cpu->ds);           /* mov cx, ds */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    cpu->cx = (uint16_t)(cpu->ss);           /* mov cx, ss */
    cpu->bx = (uint16_t)((uint16_t)(cpu->bp - 0x90)); /* lea bx, word ss:[bp+-0x90] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0x39A9 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0B99F_0002A6:;
    flags_cmp16(cpu, cpu->si, 0x4);          /* cmp si, 0x4 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0B99F_000277;   /* jl 0x0277 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0B772(cpu);                           /* call 0xFDD3 */
L_fn_0B99F_0002AE:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x730), 0x0); /* cmp word ds:[0x730], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_000309;   /* je 0x0309 */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F17(cpu);                           /* call 0x6578 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_0B99F_000300;  /* jne 0x0300 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x730)); /* mov bx, word ds:[0x730] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x740))); /* mov al, byte ds:[bx+0x740] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x738), cpu->ax))); /* sub word ds:[0x738], ax */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x730, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x730), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ds:[0x730] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x72E), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x72E] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x72E)); /* mov ax, word ds:[0x72E] */
    flags_cmp16(cpu, cpu->ax, 0xB);          /* cmp ax, 0xB */
    if (cc_le(cpu)) goto L_fn_0B99F_0002F4;  /* jle 0x02F4 */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0xB)); /* mov word ds:[0x72E], 0xB */
L_fn_0B99F_0002F4:;
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    if (cc_ne(cpu)) goto L_fn_0B99F_0002FE;  /* jne 0x02FE */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0xA)); /* mov word ds:[0x72E], 0xA */
L_fn_0B99F_0002FE:;
    goto L_fn_0B99F_000306;                  /* jmp 0x0306 */
L_fn_0B99F_000300:;
    mem_write16(cpu, cpu->ds, 0x730, (uint16_t)(0x0)); /* mov word ds:[0x730], 0x0 */
L_fn_0B99F_000306:;
    goto L_fn_0B99F_000494;                  /* jmp 0x0494 */
L_fn_0B99F_000309:;
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x2F)); /* add ax, 0x2F */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F17(cpu);                           /* call 0x6578 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_0B99F_00034D;  /* jne 0x034D */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x732), 0x0); /* cmp word ds:[0x732], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_000334;   /* je 0x0334 */
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x738), 0x8))); /* add word ds:[0x738], 0x8 */
    goto L_fn_0B99F_00033F;                  /* jmp 0x033F */
L_fn_0B99F_000334:;
    mem_write16(cpu, cpu->ds, 0x732, (uint16_t)(0x1)); /* mov word ds:[0x732], 0x1 */
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x738), 0x2))); /* add word ds:[0x738], 0x2 */
L_fn_0B99F_00033F:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _r = cpu->ax & 0x1; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xA)); /* add ax, 0xA */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(cpu->ax)); /* mov word ds:[0x72E], ax */
    goto L_fn_0B99F_000494;                  /* jmp 0x0494 */
L_fn_0B99F_00034D:;
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x28)); /* add ax, 0x28 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F17(cpu);                           /* call 0x6578 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_0B99F_0003A5;  /* jne 0x03A5 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x30)); /* add ax, 0x30 */
    cpu->bx = (uint16_t)(0x8);               /* mov bx, 0x8 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0374; recomp_div0("idiv16"); } } /* idiv bx */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov dx, word ds:[0x738] */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 0x28)); /* add dx, 0x28 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->dx)); /* sub ax, dx */
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x738), cpu->ax))); /* add word ds:[0x738], ax */
    mem_write16(cpu, cpu->ds, 0x732, (uint16_t)(0x0)); /* mov word ds:[0x732], 0x0 */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _r = cpu->ax & 0x1; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xA)); /* add ax, 0xA */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(cpu->ax)); /* mov word ds:[0x72E], ax */
    cpu->ax = (uint16_t)(0xB);               /* mov ax, 0xB */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x1152 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0B99F_000494;                  /* jmp 0x0494 */
L_fn_0B99F_0003A5:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 0x20); /* cmp word ss:[bp+-0x10], 0x20 */
    if (cc_ne(cpu)) goto L_fn_0B99F_0003FC;  /* jne 0x03FC */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07277(cpu);                           /* call 0xB8D8 */
    flags_cmp16(cpu, cpu->ax, 0x1);          /* cmp ax, 0x1 */
    if (cc_ne(cpu)) goto L_fn_0B99F_0003F7;  /* jne 0x03F7 */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F17(cpu);                           /* call 0x6578 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_0B99F_0003F3;  /* jne 0x03F3 */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x1152 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x730, (uint16_t)(0x8)); /* mov word ds:[0x730], 0x8 */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0x9)); /* mov word ds:[0x72E], 0x9 */
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    if (cc_e(cpu)) goto L_fn_0B99F_0003EB;   /* je 0x03EB */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    goto L_fn_0B99F_0003EE;                  /* jmp 0x03EE */
L_fn_0B99F_0003EB:;
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
L_fn_0B99F_0003EE:;
    mem_write16(cpu, cpu->ds, 0x734, (uint16_t)(cpu->ax)); /* mov word ds:[0x734], ax */
    goto L_fn_0B99F_0003F5;                  /* jmp 0x03F5 */
L_fn_0B99F_0003F3:;
    goto L_fn_0B99F_000450;                  /* jmp 0x0450 */
L_fn_0B99F_0003F5:;
    goto L_fn_0B99F_0003F9;                  /* jmp 0x03F9 */
L_fn_0B99F_0003F7:;
    goto L_fn_0B99F_000450;                  /* jmp 0x0450 */
L_fn_0B99F_0003F9:;
    goto L_fn_0B99F_000494;                  /* jmp 0x0494 */
L_fn_0B99F_0003FC:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB68), 0x0); /* cmp word ds:[0xB68], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_000450;   /* je 0x0450 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB70), 0x0); /* cmp word ds:[0xB70], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_000450;   /* je 0x0450 */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F17(cpu);                           /* call 0x6578 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_0B99F_000450;  /* jne 0x0450 */
    mem_write16(cpu, cpu->ds, 0xB70, (uint16_t)(0x0)); /* mov word ds:[0xB70], 0x0 */
    mem_write16(cpu, cpu->ds, 0x730, (uint16_t)(0x5)); /* mov word ds:[0x730], 0x5 */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0x9)); /* mov word ds:[0x72E], 0x9 */
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    if (cc_e(cpu)) goto L_fn_0B99F_000440;   /* je 0x0440 */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    goto L_fn_0B99F_000443;                  /* jmp 0x0443 */
L_fn_0B99F_000440:;
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
L_fn_0B99F_000443:;
    mem_write16(cpu, cpu->ds, 0x734, (uint16_t)(cpu->ax)); /* mov word ds:[0x734], ax */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x1152 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0B99F_000494;                  /* jmp 0x0494 */
L_fn_0B99F_000450:;
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    if (cc_e(cpu)) goto L_fn_0B99F_000463;   /* je 0x0463 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x72E), 0x8); /* cmp word ds:[0x72E], 0x8 */
    if (cc_le(cpu)) goto L_fn_0B99F_000461;  /* jle 0x0461 */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0x1)); /* mov word ds:[0x72E], 0x1 */
L_fn_0B99F_000461:;
    goto L_fn_0B99F_000469;                  /* jmp 0x0469 */
L_fn_0B99F_000463:;
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0x0)); /* mov word ds:[0x72E], 0x0 */
L_fn_0B99F_000469:;
    mem_write16(cpu, cpu->ds, 0x734, (uint16_t)(0x4)); /* mov word ds:[0x734], 0x4 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x738), 0x46); /* cmp word ds:[0x738], 0x46 */
    if (cc_ge(cpu)) goto L_fn_0B99F_000494;  /* jge 0x0494 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x736), 0x5A); /* cmp word ds:[0x736], 0x5A */
    if (cc_le(cpu)) goto L_fn_0B99F_000494;  /* jle 0x0494 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x736), 0xD2); /* cmp word ds:[0x736], 0xD2 */
    if (cc_ge(cpu)) goto L_fn_0B99F_000494;  /* jge 0x0494 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0B967(cpu);                           /* call 0xFFC8 */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x0)); /* mov word ds:[0xBC], 0x0 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_0B99F_00073B;                  /* jmp 0x073B */
L_fn_0B99F_000494:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 0x20); /* cmp word ss:[bp+-0x10], 0x20 */
    if (cc_ne(cpu)) goto L_fn_0B99F_0004F8;  /* jne 0x04F8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07277(cpu);                           /* call 0xB8D8 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    flags_cmp16(cpu, cpu->ax, 0x2);          /* cmp ax, 0x2 */
    if (cc_ne(cpu)) goto L_fn_0B99F_0004D8;  /* jne 0x04D8 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x72C), 0x0); /* cmp word ds:[0x72C], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0B99F_0004D8;  /* jne 0x04D8 */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07313(cpu);                           /* call 0xB974 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, cpu->ax, 0xFFFF);       /* cmp ax, 0xFFFF */
    if (cc_e(cpu)) goto L_fn_0B99F_0004CE;   /* je 0x04CE */
    mem_write16(cpu, cpu->ds, 0x72C, (uint16_t)(0x3A)); /* mov word ds:[0x72C], 0x3A */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x0)); /* mov word ss:[bp+-0x4], 0x0 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x1152 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0B99F_0004D6;                  /* jmp 0x04D6 */
L_fn_0B99F_0004CE:;
    cpu->ax = (uint16_t)(0x11);              /* mov ax, 0x11 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x1152 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0B99F_0004D6:;
    goto L_fn_0B99F_0004F8;                  /* jmp 0x04F8 */
L_fn_0B99F_0004D8:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_ne(cpu)) goto L_fn_0B99F_0004F8;  /* jne 0x04F8 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x8FE), 0x0); /* cmp word ds:[0x8FE], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0B99F_0004F0;  /* jne 0x04F0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05A3B(cpu);                           /* call 0xA09C */
    cpu->ax = (uint16_t)(0x14);              /* mov ax, 0x14 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x1152 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0B99F_0004F8;                  /* jmp 0x04F8 */
L_fn_0B99F_0004F0:;
    cpu->ax = (uint16_t)(0x17);              /* mov ax, 0x17 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x1152 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0B99F_0004F8:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x72C), 0x1); /* cmp word ds:[0x72C], 0x1 */
    if (cc_ne(cpu)) goto L_fn_0B99F_000505;  /* jne 0x0505 */
    mem_write16(cpu, cpu->ds, 0x72C, (uint16_t)(0x0)); /* mov word ds:[0x72C], 0x0 */
L_fn_0B99F_000505:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04B0C(cpu);                           /* call 0x916D */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x0); /* cmp word ss:[bp+-0x2], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_00054B;   /* je 0x054B */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC588), 0x0); /* cmp word ds:[0xC588], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0B99F_00054B;  /* jne 0x054B */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xB52F), 0x0); /* cmp byte ds:[0xB52F], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_00054B;   /* je 0x054B */
    mem_write8(cpu, cpu->ds, 0xB537, (uint8_t)(0x1)); /* mov byte ds:[0xB537], 0x1 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x0)); /* mov word ss:[bp+-0x2], 0x0 */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x190)); /* mov word ds:[0x96], 0x190 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xB0F2)); /* push word ds:[0xB0F2] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xB0F0)); /* push word ds:[0xB0F0] */
    cpu->ax = (uint16_t)(0x112);             /* mov ax, 0x112 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA0);              /* mov ax, 0xA0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x4A2D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x9F)); /* mov word ds:[0x96], 0x9F */
L_fn_0B99F_00054B:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x40CE), 0x0); /* cmp word ds:[0x40CE], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_000569;   /* je 0x0569 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC))); /* mov ax, word ss:[bp+-0xC] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x40CE)); /* cmp ax, word ds:[0x40CE] */
    if (cc_e(cpu)) goto L_fn_0B99F_000569;   /* je 0x0569 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xB3AE)); /* mov al, byte ds:[0xB3AE] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x40CE))); /* sub ax, word ds:[0x40CE] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xE], ax */
    goto L_fn_0B99F_00056E;                  /* jmp 0x056E */
L_fn_0B99F_000569:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(0xFFFF)); /* mov word ss:[bp+-0xE], 0xFFFF */
L_fn_0B99F_00056E:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40CE)); /* mov ax, word ds:[0x40CE] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x736), 0x8); /* cmp word ds:[0x736], 0x8 */
    if (cc_ge(cpu)) goto L_fn_0B99F_000583;  /* jge 0x0583 */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(0x8)); /* mov word ds:[0x736], 0x8 */
    goto L_fn_0B99F_000591;                  /* jmp 0x0591 */
L_fn_0B99F_000583:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x736), 0x110); /* cmp word ds:[0x736], 0x110 */
    if (cc_le(cpu)) goto L_fn_0B99F_000591;  /* jle 0x0591 */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(0x110)); /* mov word ds:[0x736], 0x110 */
L_fn_0B99F_000591:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x8FE), 0x0); /* cmp word ds:[0x8FE], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_00059B;   /* je 0x059B */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05AC3(cpu);                           /* call 0xA124 */
L_fn_0B99F_00059B:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x0); /* cmp word ss:[bp+-0x4], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_0005FA;   /* je 0x05FA */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ss:[bp+-0x4] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x1A); /* cmp word ss:[bp+-0x4], 0x1A */
    if (cc_le(cpu)) goto L_fn_0B99F_0005CA;  /* jle 0x05CA */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x73A)); /* push word ds:[0x73A] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D4)); /* mov dx, word ds:[0x99D4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D2)); /* mov ax, word ds:[0x99D2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x39EC)); /* add ax, 0x39EC */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x738)); /* push word ds:[0x738] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x736)); /* push word ds:[0x736] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x4A2D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    goto L_fn_0B99F_0005F7;                  /* jmp 0x05F7 */
L_fn_0B99F_0005CA:;
    flags_logic16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)) & 0x1); /* test word ss:[bp+-0x4], 0x1 */
    if (cc_e(cpu)) goto L_fn_0B99F_0005F7;   /* je 0x05F7 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x73A)); /* push word ds:[0x73A] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x72E)); /* mov ax, word ds:[0x72E] */
    cpu->dx = (uint16_t)(0x2A2);             /* mov dx, 0x2A2 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D4)); /* mov cx, word ds:[0x99D4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D2)); /* mov bx, word ds:[0x99D2] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x738)); /* push word ds:[0x738] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x736)); /* push word ds:[0x736] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x4A2D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_0B99F_0005F7:;
    goto L_fn_0B99F_0006C9;                  /* jmp 0x06C9 */
L_fn_0B99F_0005FA:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x72C), 0x0); /* cmp word ds:[0x72C], 0x0 */
    if (cc_e(cpu)) goto L_fn_0B99F_000644;   /* je 0x0644 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x96EE);            /* mov ax, 0x96EE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x738)); /* push word ds:[0x738] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x736)); /* push word ds:[0x736] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x4A2D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x72C, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x72C), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ds:[0x72C] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x73A)); /* push word ds:[0x73A] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x72E)); /* mov ax, word ds:[0x72E] */
    cpu->dx = (uint16_t)(0x2A2);             /* mov dx, 0x2A2 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D4)); /* mov cx, word ds:[0x99D4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D2)); /* mov bx, word ds:[0x99D2] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x738)); /* push word ds:[0x738] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x736)); /* push word ds:[0x736] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x4A2D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    goto L_fn_0B99F_0006C9;                  /* jmp 0x06C9 */
L_fn_0B99F_000644:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)), 0x4); /* cmp word ss:[bp+-0xE], 0x4 */
    if (cc_le(cpu)) goto L_fn_0B99F_0006A3;  /* jle 0x06A3 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)), 0xB); /* cmp word ss:[bp+-0xE], 0xB */
    if (cc_g(cpu)) goto L_fn_0B99F_0006A3;   /* jg 0x06A3 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x73A)); /* push word ds:[0x73A] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D4)); /* mov dx, word ds:[0x99D4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D2)); /* mov ax, word ds:[0x99D2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x39EC)); /* add ax, 0x39EC */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x738)); /* push word ds:[0x738] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x736)); /* push word ds:[0x736] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x4A2D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x1E)); /* mov word ss:[bp+-0x4], 0x1E */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x1152 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01ECD(cpu);                           /* call 0x652E */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x0)); /* mov word ds:[0xBC], 0x0 */
    cpu->ax = (uint16_t)(0xFFFE);            /* mov ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0734E(cpu);                           /* call 0xB9AF */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_g(cpu)) goto L_fn_0B99F_000698;   /* jg 0x0698 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_03986(cpu);                           /* call 0x7FE7 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0B99F_00073B;                  /* jmp 0x073B */
L_fn_0B99F_000698:;
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x1)); /* mov word ds:[0xBC], 0x1 */
    goto L_fn_0B99F_00072A;                  /* jmp 0x072A */
    goto L_fn_0B99F_0006C9;                  /* jmp 0x06C9 */
L_fn_0B99F_0006A3:;
    push16(cpu, mem_read16(cpu, cpu->ds, 0x73A)); /* push word ds:[0x73A] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x72E)); /* mov ax, word ds:[0x72E] */
    cpu->dx = (uint16_t)(0x2A2);             /* mov dx, 0x2A2 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D4)); /* mov cx, word ds:[0x99D4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D2)); /* mov bx, word ds:[0x99D2] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x738)); /* push word ds:[0x738] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x736)); /* push word ds:[0x736] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x4A2D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_0B99F_0006C9:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)), 0xD); /* cmp word ss:[bp+-0xE], 0xD */
    if (cc_ne(cpu)) goto L_fn_0B99F_000727;  /* jne 0x0727 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB78)); /* mov dx, word ds:[0xB78] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB76)); /* mov ax, word ds:[0xB76] */
    flags_cmp16(cpu, cpu->dx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x92))); /* cmp dx, word ss:[bp+-0x92] */
    if (cc_b(cpu)) goto L_fn_0B99F_000712;   /* jb 0x0712 */
    if (cc_a(cpu)) goto L_fn_0B99F_0006E4;   /* ja 0x06E4 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x94))); /* cmp ax, word ss:[bp+-0x94] */
    if (cc_be(cpu)) goto L_fn_0B99F_000712;  /* jbe 0x0712 */
L_fn_0B99F_0006E4:;
    cpu->al = (uint8_t)(0x0);                /* mov al, 0x0 */
    mem_write8(cpu, cpu->ds, 0xB54F, (uint8_t)(cpu->al)); /* mov byte ds:[0xB54F], al */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ds, 0x730, (uint16_t)(cpu->ax)); /* mov word ds:[0x730], ax */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ss:[bp+-0xA] */
    if (cc_ge(cpu)) goto L_fn_0B99F_0006F8;  /* jge 0x06F8 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(0x0)); /* mov word ss:[bp+-0xA], 0x0 */
L_fn_0B99F_0006F8:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)), 0x0); /* cmp word ss:[bp+-0xA], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0B99F_000712;  /* jne 0x0712 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ACE7(cpu);                           /* call 0xF348 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_0B99F_000712;  /* jne 0x0712 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01ECD(cpu);                           /* call 0x652E */
    cpu->ax = (uint16_t)(0x45);              /* mov ax, 0x45 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5F9(cpu);                           /* call 0x1C5A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0B99F_00072A;                  /* jmp 0x072A */
L_fn_0B99F_000712:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB78)); /* mov dx, word ds:[0xB78] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB76)); /* mov ax, word ds:[0xB76] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1F4)); /* add ax, 0x1F4 */
    cpu->dx = (uint16_t)(flags_adc(cpu, cpu->dx, 0x0, 16)); /* adc dx, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x92), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x92], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x94), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x94], ax */
L_fn_0B99F_000727:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01ECD(cpu);                           /* call 0x652E */
L_fn_0B99F_00072A:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C6F(cpu);                           /* call 0xB2D0 */
    RECOMP_TICK(cpu);
    goto L_fn_0B99F_000085;                  /* jmp 0x0085 */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x0)); /* mov word ds:[0xBC], 0x0 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_0B99F_00073B;                  /* jmp 0x073B */
L_fn_0B99F_00073B:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C0E0(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C0E0");
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0x8FE, (uint16_t)(cpu->ax)); /* mov word ds:[0x8FE], ax */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(cpu->ax)); /* mov word ds:[0xBC], ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    mem_write16(cpu, cpu->ds, 0xBFBA, (uint16_t)(cpu->ax)); /* mov word ds:[0xBFBA], ax */
    cpu->dx = (uint16_t)(0x3E8);             /* mov dx, 0x3E8 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x43B4)); /* add bx, 0x43B4 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->ds, 0xBFBE, (uint16_t)(cpu->es)); /* mov word ds:[0xBFBE], es */
    mem_write16(cpu, cpu->ds, 0xBFBC, (uint16_t)(cpu->bx)); /* mov word ds:[0xBFBC], bx */
    mem_write16(cpu, cpu->ds, 0x40CE, (uint16_t)(0x1)); /* mov word ds:[0x40CE], 0x1 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0B55E(cpu);                           /* call 0xF47E */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0B09A(cpu);                           /* call 0xEFBA */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0B122(cpu);                           /* call 0xF042 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0B4FB(cpu);                           /* call 0xF41B */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04EEB(cpu);                           /* call 0x8E0B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(0x10)); /* mov word ds:[0x736], 0x10 */
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(0x70)); /* mov word ds:[0x738], 0x70 */
    mem_write16(cpu, cpu->ds, 0x73A, (uint16_t)(0x0)); /* mov word ds:[0x73A], 0x0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02269(cpu);                           /* call 0x6189 */
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x130);             /* mov ax, 0x130 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x42BF */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x43);              /* mov ax, 0x43 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5F9(cpu);                           /* call 0x1519 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0B99F(cpu);                           /* call 0xF8BF */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0B593(cpu);                           /* call 0xF4B3 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    goto L_fn_0C0E0_00007C;                  /* jmp 0x007C */
L_fn_0C0E0_00007C:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C15E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C15E");
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0726A(cpu);                           /* call 0xB10C */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ACE7(cpu);                           /* call 0xEB89 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_0C15E_000014;  /* jne 0x0014 */
    cpu->ax = (uint16_t)(0xFFFD);            /* mov ax, 0xFFFD */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07313(cpu);                           /* call 0xB1B5 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0C15E_00001C;                  /* jmp 0x001C */
L_fn_0C15E_000014:;
    cpu->ax = (uint16_t)(0xFFFC);            /* mov ax, 0xFFFC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07313(cpu);                           /* call 0xB1B5 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0C15E_00001C:;
    mem_write16(cpu, cpu->ds, 0x9ADE, (uint16_t)(0x2A)); /* mov word ds:[0x9ADE], 0x2A */
    mem_write16(cpu, cpu->ds, 0x722, (uint16_t)(0x0)); /* mov word ds:[0x722], 0x0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0462E(cpu);                           /* call 0x84D0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C0E0(cpu);                           /* call 0xFF82 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_0C15E_000036;  /* jne 0x0036 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0C15E_000041;                  /* jmp 0x0041 */
L_fn_0C15E_000036:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0B6CD(cpu);                           /* call 0xF56F */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C834(cpu);                           /* call 0x06D6 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_0C15E_000041;                  /* jmp 0x0041 */
L_fn_0C15E_000041:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C1A0(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C1A0");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->es);                    /* push es */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0x177C, (uint16_t)(cpu->ax)); /* mov word ds:[0x177C], ax */
    mem_write16(cpu, cpu->ds, 0x177E, (uint16_t)(cpu->ax)); /* mov word ds:[0x177E], ax */
    mem_write16(cpu, cpu->ds, 0x1780, (uint16_t)(cpu->ax)); /* mov word ds:[0x1780], ax */
    mem_write16(cpu, cpu->ds, 0x1782, (uint16_t)(cpu->ax)); /* mov word ds:[0x1782], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1770), 0x0); /* cmp word ds:[0x1770], 0x0 */
    if (cc_e(cpu)) goto L_fn_0C1A0_000040;   /* je 0x0040 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C8E2(cpu);                           /* call 0x0742 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1784), 0x0); /* cmp word ds:[0x1784], 0x0 */
    if (cc_e(cpu)) goto L_fn_0C1A0_00004E;   /* je 0x004E */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x0); /* cmp word ds:[0x1778], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0C1A0_000036;  /* jne 0x0036 */
    mem_write16(cpu, cpu->ds, 0x177C, (uint16_t)(0x1)); /* mov word ds:[0x177C], 0x1 */
L_fn_0C1A0_000036:;
    cpu->es = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1764)); /* mov es, word ds:[0x1764] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C1F7(cpu);                           /* call 0x0057 */
    goto L_fn_0C1A0_00004E;                  /* jmp 0x004E */
    /* nop */                                /* nop */
L_fn_0C1A0_000040:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1784), 0x0); /* cmp word ds:[0x1784], 0x0 */
    if (cc_e(cpu)) goto L_fn_0C1A0_00004E;   /* je 0x004E */
    cpu->es = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1764)); /* mov es, word ds:[0x1764] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C1F7(cpu);                           /* call 0x0057 */
L_fn_0C1A0_00004E:;
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}
