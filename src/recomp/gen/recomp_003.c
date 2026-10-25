#include "recomp_all.h"

void fn_0727D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0727D");
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0xB7E, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xB7E), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0xB7E] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB7E)); /* mov ax, word ds:[0xB7E] */
    flags_cmp16(cpu, cpu->ax, 0x3);          /* cmp ax, 0x3 */
    if (cc_l(cpu)) goto L_fn_0727D_000012;   /* jl 0x0012 */
    mem_write16(cpu, cpu->ds, 0xB7E, (uint16_t)(0x0)); /* mov word ds:[0xB7E], 0x0 */
L_fn_0727D_000012:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07298(cpu);                           /* call 0x001B */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB7E)); /* mov ax, word ds:[0xB7E] */
    goto L_fn_0727D_00001A;                  /* jmp 0x001A */
L_fn_0727D_00001A:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_07298(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07298");
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB7E)); /* mov ax, word ds:[0xB7E] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC0EE); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC0EE + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC0EE] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x6))); /* mov ax, word es:[bx+0x6] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0F0)); /* mov cx, word ds:[0xC0F0] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0EE)); /* mov bx, word ds:[0xC0EE] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0xA6);              /* mov ax, 0xA6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x98);              /* mov ax, 0x98 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x9131 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB7E), 0x2); /* cmp word ds:[0xB7E], 0x2 */
    if (cc_ne(cpu)) goto L_fn_07298_00005D;  /* jne 0x005D */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB80)); /* mov ax, word ds:[0xB80] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC0EE); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC0EE + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC0EE] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC))); /* mov ax, word es:[bx+0xC] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0F0)); /* mov cx, word ds:[0xC0F0] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0EE)); /* mov bx, word ds:[0xC0EE] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0xAE);              /* mov ax, 0xAE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA6);              /* mov ax, 0xA6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x9131 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_07298_00005D:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC0FA), 0x0); /* cmp word ds:[0xC0FA], 0x0 */
    if (cc_e(cpu)) goto L_fn_07298_00007A;   /* je 0x007A */
    cpu->ax = (uint16_t)(0x1C);              /* mov ax, 0x1C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2C);              /* mov ax, 0x2C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA6);              /* mov ax, 0xA6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x98);              /* mov ax, 0x98 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x9107 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_07298_00007A:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_07313(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07313");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->ds, 0xB80, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xB80), cpu->ax))); /* add word ds:[0xB80], ax */
    if (cc_ge(cpu)) goto L_fn_07313_000019;  /* jge 0x0019 */
    mem_write16(cpu, cpu->ds, 0xB80, (uint16_t)(0x0)); /* mov word ds:[0xB80], 0x0 */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_07313_00002E;                  /* jmp 0x002E */
    goto L_fn_07313_000026;                  /* jmp 0x0026 */
L_fn_07313_000019:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB80), 0x4); /* cmp word ds:[0xB80], 0x4 */
    if (cc_le(cpu)) goto L_fn_07313_000026;  /* jle 0x0026 */
    mem_write16(cpu, cpu->ds, 0xB80, (uint16_t)(0x4)); /* mov word ds:[0xB80], 0x4 */
L_fn_07313_000026:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07298(cpu);                           /* call 0xFF85 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB80)); /* mov ax, word ds:[0xB80] */
    goto L_fn_07313_00002E;                  /* jmp 0x002E */
L_fn_07313_00002E:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07343(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07343");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov al, byte ss:[bp+0x4] */
    mem_write8(cpu, cpu->ds, 0xB82, (uint8_t)(cpu->al)); /* mov byte ds:[0xB82], al */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0734E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0734E");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 0x0); /* cmp word ss:[bp+0x4], 0x0 */
    if (cc_e(cpu)) goto L_fn_0734E_000034;   /* je 0x0034 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xB82), 0x2); /* cmp byte ds:[0xB82], 0x2 */
    if (cc_ne(cpu)) goto L_fn_0734E_00001E;  /* jne 0x001E */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 0x0); /* cmp word ss:[bp+0x4], 0x0 */
    if (cc_ge(cpu)) goto L_fn_0734E_00001E;  /* jge 0x001E */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D4B3(cpu);                           /* call 0x6165 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0734E_00001E:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov al, byte ss:[bp+0x4] */
    mem_write8(cpu, cpu->ds, 0xB82, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, 0xB82), cpu->al))); /* add byte ds:[0xB82], al */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xB82)); /* mov al, byte ds:[0xB82] */
    flags_cmp8(cpu, cpu->al, 0x4);           /* cmp al, 0x4 */
    if (cc_le(cpu)) goto L_fn_0734E_000031;  /* jle 0x0031 */
    mem_write8(cpu, cpu->ds, 0xB82, (uint8_t)(0x4)); /* mov byte ds:[0xB82], 0x4 */
L_fn_0734E_000031:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0738A(cpu);                           /* call 0x003C */
L_fn_0734E_000034:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xB82)); /* mov al, byte ds:[0xB82] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    goto L_fn_0734E_00003A;                  /* jmp 0x003A */
L_fn_0734E_00003A:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0738A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0738A");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0020F(cpu);                           /* call 0x8E85 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xB82)); /* mov al, byte ds:[0xB82] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->si; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->si = (uint16_t)(_r); } } /* shl si, cl */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x2); /* cmp byte ds:[0xBFCD], 0x2 */
    if (cc_ne(cpu)) goto L_fn_0738A_000022;  /* jne 0x0022 */
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8E44 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0738A_00002A;                  /* jmp 0x002A */
L_fn_0738A_000022:;
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8E44 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0738A_00002A:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_le(cpu)) goto L_fn_0738A_000041;  /* jle 0x0041 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0xA4);              /* mov ax, 0xA4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x901E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_0738A_000041:;
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8E44 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, cpu->si, 0x40);         /* cmp si, 0x40 */
    if (cc_ge(cpu)) goto L_fn_0738A_000068;  /* jge 0x0068 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x40);              /* mov ax, 0x40 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->si)); /* sub ax, si */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA4);              /* mov ax, 0xA4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xF4)); /* add ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x901E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_0738A_000068:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC0FA), 0x0); /* cmp word ds:[0xC0FA], 0x0 */
    if (cc_e(cpu)) goto L_fn_0738A_000085;   /* je 0x0085 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x40);              /* mov ax, 0x40 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA4);              /* mov ax, 0xA4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x9015 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_0738A_000085:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8E44 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07417(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07417");
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EB4(cpu);                           /* call 0xAA9D */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC0EE); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC0EE + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC0EE] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x16))); /* mov ax, word es:[bx+0x16] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0F0)); /* mov cx, word ds:[0xC0F0] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0EE)); /* mov bx, word ds:[0xC0EE] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0xAF);              /* mov ax, 0xAF */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x8FB2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07443(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07443");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EA5(cpu);                           /* call 0xAA62 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC0EE); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC0EE + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC0EE] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x20))); /* mov ax, word es:[bx+0x20] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0F0)); /* mov cx, word ds:[0xC0F0] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0EE)); /* mov bx, word ds:[0xC0EE] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0xBA);              /* mov ax, 0xBA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xF4)); /* add ax, 0xF4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x8F86 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0747B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0747B");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0020F(cpu);                           /* call 0x8D94 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8D53 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xBA);              /* mov ax, 0xBA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xD);               /* mov ax, 0xD */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x8F2A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0xBA);              /* mov ax, 0xBA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xD);               /* mov ax, 0xD */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x13F);             /* mov ax, 0x13F */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x8F2A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC7);              /* mov ax, 0xC7 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x8F27 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x8F27 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA0);              /* mov ax, 0xA0 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x8F27 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x8F2A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x7);               /* mov ax, 0x7 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x8F2A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x138);             /* mov ax, 0x138 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x8F2A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x139);             /* mov ax, 0x139 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x8F2A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x24);              /* mov ax, 0x24 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA2);              /* mov ax, 0xA2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x8F2A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x24);              /* mov ax, 0x24 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA2);              /* mov ax, 0xA2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x7);               /* mov ax, 0x7 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x8F2A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x24);              /* mov ax, 0x24 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA2);              /* mov ax, 0xA2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x138);             /* mov ax, 0x138 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x8F2A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x24);              /* mov ax, 0x24 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA2);              /* mov ax, 0xA2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x139);             /* mov ax, 0x139 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x8F2A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8D53 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x13E);             /* mov ax, 0x13E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xD);               /* mov ax, 0xD */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x8F27 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x13E);             /* mov ax, 0x13E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xE);               /* mov ax, 0xE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x8F27 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA1);              /* mov ax, 0xA1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x8F27 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x13E);             /* mov ax, 0x13E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC6);              /* mov ax, 0xC6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x8F27 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0xBA);              /* mov ax, 0xBA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x5);               /* mov ax, 0x5 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xD);               /* mov ax, 0xD */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x8F2D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xBA);              /* mov ax, 0xBA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x5);               /* mov ax, 0x5 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xD);               /* mov ax, 0xD */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x13A);             /* mov ax, 0x13A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x8F2D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8D53 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_075F3(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_075F3");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x10)); /* sub sp, 0x10 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x10)); /* lea ax, word ss:[bp+-0x10] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xB87);             /* mov ax, 0xB87 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->cx = (uint16_t)(0xF);               /* mov cx, 0xF */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F937(cpu);                           /* call 0000:F937 */
    mem_write16(cpu, cpu->ds, 0xB83, (uint16_t)(0x2)); /* mov word ds:[0xB83], 0x2 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0020F(cpu);                           /* call 0x8C1C */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CEA(cpu);                           /* call 0xF6F7 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x2); /* cmp byte ds:[0xBFCD], 0x2 */
    if (cc_ne(cpu)) goto L_fn_075F3_00003B;  /* jne 0x003B */
    cpu->ax = (uint16_t)(0x5);               /* mov ax, 0x5 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8BDB */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_075F3_000043;                  /* jmp 0x0043 */
L_fn_075F3_00003B:;
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8BDB */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_075F3_000043:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CA6(cpu);                           /* call 0xF6B3 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x10)); /* lea ax, word ss:[bp+-0x10] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xBC);              /* mov ax, 0xBC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xF749 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x94);              /* mov ax, 0x94 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xBC);              /* mov ax, 0xBC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x8DAC */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8BDB */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CA6(cpu);                           /* call 0xF6B3 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07676(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07676");
    cpu->ax = (uint16_t)(0xBC);              /* mov ax, 0xBC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x94);              /* mov ax, 0x94 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x184);             /* mov ax, 0x184 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09F40(cpu);                           /* call 0x28CA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07695(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07695");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0xE)); /* sub sp, 0xE */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0xE)); /* lea ax, word ss:[bp+-0xE] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xB96);             /* mov ax, 0xB96 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->cx = (uint16_t)(0xD);               /* mov cx, 0xD */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F937(cpu);                           /* call 0000:F937 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0020F(cpu);                           /* call 0x8B7A */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CEA(cpu);                           /* call 0xF655 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    mem_write16(cpu, cpu->ds, 0xB83, (uint16_t)(0x3)); /* mov word ds:[0xB83], 0x3 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->ds, 0xC0F8, (uint16_t)(cpu->es)); /* mov word ds:[0xC0F8], es */
    mem_write16(cpu, cpu->ds, 0xC0F6, (uint16_t)(cpu->bx)); /* mov word ds:[0xC0F6], bx */
    mem_write16(cpu, cpu->ds, 0xC0FC, (uint16_t)(0x0)); /* mov word ds:[0xC0FC], 0x0 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8B39 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xBC);              /* mov ax, 0xBC */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x8D13 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8B39 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CA6(cpu);                           /* call 0xF611 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(0xBD);              /* mov ax, 0xBD */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xF6A7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0xE)); /* lea ax, word ss:[bp+-0xE] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xBD);              /* mov ax, 0xBD */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xAA);              /* mov ax, 0xAA */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xF6A7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xBC);              /* mov ax, 0xBC */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x8D0A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8B39 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CA6(cpu);                           /* call 0xF611 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07747(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07747");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0792C(cpu);                           /* call 0x01E5 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07925(cpu);                           /* call 0x01DE */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0778B(cpu);                           /* call 0x0044 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
L_fn_07747_000027:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B1A(cpu);                           /* call 0xF3D3 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    flags_cmp16(cpu, cpu->si, 0xD);          /* cmp si, 0xD */
    if (cc_e(cpu)) goto L_fn_07747_000036;   /* je 0x0036 */
    flags_cmp16(cpu, cpu->si, 0x1B);         /* cmp si, 0x1B */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_07747_000027;  /* jne 0x0027 */
L_fn_07747_000036:;
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    if (cc_e(cpu)) goto L_fn_07747_00003D;   /* je 0x003D */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0791E(cpu);                           /* call 0x01D7 */
L_fn_07747_00003D:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06FDA(cpu);                           /* call 0xF893 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0778B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0778B");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x10)); /* sub sp, 0x10 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x10)); /* lea ax, word ss:[bp+-0x10] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xBA3);             /* mov ax, 0xBA3 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->cx = (uint16_t)(0xF);               /* mov cx, 0xF */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F937(cpu);                           /* call 0000:F937 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0020F(cpu);                           /* call 0x8A84 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CEA(cpu);                           /* call 0xF55F */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    mem_write16(cpu, cpu->ds, 0xB83, (uint16_t)(0x4)); /* mov word ds:[0xB83], 0x4 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    mem_write16(cpu, cpu->ds, 0xC0FC, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0FC], ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8A43 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x24);              /* mov ax, 0x24 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA2);              /* mov ax, 0xA2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00355(cpu);                           /* call 0x8BCA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8A43 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x22);              /* mov ax, 0x22 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x130);             /* mov ax, 0x130 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA3);              /* mov ax, 0xA3 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x8C1D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8A43 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* push word ss:[bp+0xC] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CA6(cpu);                           /* call 0xF51B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(0xA5);              /* mov ax, 0xA5 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xF5B1 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE)), 0x0); /* cmp word ss:[bp+0xE], 0x0 */
    if (cc_e(cpu)) goto L_fn_0778B_0000A5;   /* je 0x00A5 */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x10)); /* lea ax, word ss:[bp+-0x10] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xB9);              /* mov ax, 0xB9 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xAA);              /* mov ax, 0xAA */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xF5B1 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_0778B_0000A5:;
    cpu->ax = (uint16_t)(0x24);              /* mov ax, 0x24 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA2);              /* mov ax, 0xA2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x8C14 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8A43 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CA6(cpu);                           /* call 0xF51B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07856(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07856");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    mem_write16(cpu, cpu->ds, 0xB83, (uint16_t)(0x5)); /* mov word ds:[0xB83], 0x5 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->ds, 0xC0F4, (uint16_t)(cpu->es)); /* mov word ds:[0xC0F4], es */
    mem_write16(cpu, cpu->ds, 0xC0F2, (uint16_t)(cpu->bx)); /* mov word ds:[0xC0F2], bx */
    mem_write16(cpu, cpu->ds, 0xC0FC, (uint16_t)(0x1)); /* mov word ds:[0xC0FC], 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov ax, word ss:[bp+0x8] */
    mem_write16(cpu, cpu->ds, 0xC0EC, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0EC], ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(0xA2);              /* mov ax, 0xA2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x8B73 */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)), 0x0); /* cmp word ss:[bp+0x8], 0x0 */
    if (cc_e(cpu)) goto L_fn_07856_000056;   /* je 0x0056 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x8978 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6A);              /* mov ax, 0x6A */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xB5);              /* mov ax, 0xB5 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xD);               /* mov ax, 0xD */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x8B52 */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
L_fn_07856_000056:;
    cpu->ax = (uint16_t)(0x24);              /* mov ax, 0x24 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA2);              /* mov ax, 0xA2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x8B49 */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_078C3(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_078C3");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x0)); /* mov word ss:[bp+-0x2], 0x0 */
    goto L_fn_078C3_000051;                  /* jmp 0x0051 */
L_fn_078C3_00000D:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov ax, word ss:[bp+0x8] */
    cpu->dx = (uint16_t)(0x1);               /* mov dx, 0x1 */
    cpu->cl = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov cl, byte ss:[bp+-0x2] */
    { uint16_t _v = cpu->dx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shl dx, cl */
    flags_logic16(cpu, cpu->ax & cpu->dx);   /* test ax, dx */
    if (cc_e(cpu)) goto L_fn_078C3_00004E;   /* je 0x004E */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC0EE); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC0EE + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC0EE] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x28))); /* mov ax, word es:[bx+0x28] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0F0)); /* mov cx, word ds:[0xC0F0] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0EE)); /* mov bx, word ds:[0xC0EE] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add ax, word ss:[bp+0x4] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x8B06 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_078C3_00004E:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x2] */
L_fn_078C3_000051:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x4); /* cmp word ss:[bp+-0x2], 0x4 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_078C3_00000D;   /* jl 0x000D */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0791E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0791E");
    mem_write16(cpu, cpu->ds, 0xBB2, (uint16_t)(0x1)); /* mov word ds:[0xBB2], 0x1 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07925(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07925");
    mem_write16(cpu, cpu->ds, 0xBB2, (uint16_t)(0x0)); /* mov word ds:[0xBB2], 0x0 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0792C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0792C");
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBB2)); /* mov ax, word ds:[0xBB2] */
    goto L_fn_0792C_000005;                  /* jmp 0x0005 */
L_fn_0792C_000005:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_07932(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07932");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _r = cpu->ax | mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, word ss:[bp+0x6] */
    if (cc_e(cpu)) goto L_fn_07932_000023;   /* je 0x0023 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->ds, 0xC100, (uint16_t)(cpu->es)); /* mov word ds:[0xC100], es */
    mem_write16(cpu, cpu->ds, 0xC0FE, (uint16_t)(cpu->bx)); /* mov word ds:[0xC0FE], bx */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07BFC(cpu);                           /* call 0x02CA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0791E(cpu);                           /* call 0xFFEC */
    goto L_fn_07932_000030;                  /* jmp 0x0030 */
L_fn_07932_000023:;
    mem_write16(cpu, cpu->ds, 0xC100, (uint16_t)(cpu->ds)); /* mov word ds:[0xC100], ds */
    mem_write16(cpu, cpu->ds, 0xC0FE, (uint16_t)(0xBB4)); /* mov word ds:[0xC0FE], 0xBB4 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07925(cpu);                           /* call 0xFFF3 */
L_fn_07932_000030:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07964(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07964");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x14)); /* sub sp, 0x14 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_l(cpu)) goto L_fn_07964_00001A;   /* jl 0x001A */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC0FE); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC0FE + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC0FE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    flags_cmp16(cpu, cpu->ax, cpu->si);      /* cmp ax, si */
    if (cc_g(cpu)) goto L_fn_07964_00001D;   /* jg 0x001D */
L_fn_07964_00001A:;
    goto L_fn_07964_000292;                  /* jmp 0x0292 */
L_fn_07964_00001D:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0792C(cpu);                           /* call 0xFFC8 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x12], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07925(cpu);                           /* call 0xFFC1 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B74(cpu);                           /* call 0xF210 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x14], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06990(cpu);                           /* call 0xF02C */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xF202 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0703E(cpu);                           /* call 0xF6DA */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D593(cpu);                           /* call 0x5C2F */
    goto L_fn_07964_000267;                  /* jmp 0x0267 */
L_fn_07964_00003B:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(cpu->si)); /* mov word ss:[bp+-0x10], si */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC0FE); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC0FE + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC0FE] */
    { uint16_t _o = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)((uint16_t)(cpu->bx + 0x2) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx+0x2] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x14);              /* mov dx, 0x14 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0xC], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0xE], bx */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07BFC(cpu);                           /* call 0x0298 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC))); /* push word ss:[bp+-0xC] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* push word ss:[bp+-0xE] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07D91(cpu);                           /* call 0x042D */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x0)); /* mov word ss:[bp+-0x2], 0x0 */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(0x0)); /* mov word ss:[bp+-0x8], 0x0 */
    goto L_fn_07964_000255;                  /* jmp 0x0255 */
L_fn_07964_000074:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(cpu->di)); /* mov word ss:[bp+-0xA], di */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0xE) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0xE] */
    push16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x10))); /* push word es:[bx+0x10] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0xA);               /* mov dx, 0xA */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x11)); /* add ax, 0x11 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0xE) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x12))); /* mov ax, word es:[bx+0x12] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03AB);                           /* call 0x8A47 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0xE) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0xE] */
L_fn_07964_0000A5:;
    push16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x10))); /* push word es:[bx+0x10] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0xA);               /* mov dx, 0xA */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x11)); /* add ax, 0x11 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0xE) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x12))); /* mov ax, word es:[bx+0x12] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x8A3B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B1A(cpu);                           /* call 0xF1B6 */
L_fn_07964_0000C8:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    cpu->cx = (uint16_t)(0x10);              /* mov cx, 0x10 */
    cpu->bx = (uint16_t)(0x7A48);            /* mov bx, 0x7A48 */
L_fn_07964_0000D4:;
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, SEG_0000, cpu->bx)); /* cmp ax, word cs:[bx] */
    if (cc_e(cpu)) goto L_fn_07964_0000E0;   /* je 0x00E0 */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_07964_0000D4; /* loop 0x00D4 */
L_fn_07964_0000DD:;
    goto L_fn_07964_0001FF;                  /* jmp 0x01FF */
L_fn_07964_0000E0:;
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x20))); return; /* jmp word cs:[bx+0x20] */
    { uint16_t _r = cpu->ax | 0x1B00; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, 0x1B00 */
L_fn_07964_0000E7:;
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di)), cpu->bh))); /* add byte ss:[bp+di], bh */
L_fn_07964_0000E9:;
    mem_write16(cpu, cpu->ds, cpu->si, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, cpu->si), cpu->di))); /* add word ds:[si], di */
L_fn_07964_0000EB:;
    mem_write16(cpu, cpu->ds, cpu->di, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, cpu->di), cpu->di))); /* add word ds:[di], di */
L_fn_07964_0000ED:;
    mem_write16(cpu, cpu->ds, 0x3F01, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x3F01), cpu->di))); /* add word ds:[0x3F01], di */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1)), cpu->ax))); /* add word ds:[bx+si+0x1], ax */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->si + 0x1), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->si + 0x1)), cpu->ax))); /* add word ss:[bp+si+0x1], ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x1), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x1)), cpu->ax))); /* add word ds:[si+0x1], ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di + 0x1), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di + 0x1)), cpu->cx))); /* add word ss:[bp+di+0x1], cx */
    { int _cf = cf(cpu); cpu->bp = (uint16_t)(flags_sub16(cpu, cpu->bp, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec bp */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1)), cpu->dx))); /* add word ds:[bx+si+0x1], dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFB7B)); /* add ax, 0xFB7B */
    RECOMP_TICK(cpu);
    if (cc_p(cpu)) goto L_fn_07964_0000DD;   /* jp 0x00DD */
    if (cc_p(cpu)) { recomp_dispatch(cpu, 0x7A4, 0x3); return; } /* tail-jcc 0x007A43 */ /* jp 0x00DF */
    if (cc_p(cpu)) { recomp_dispatch(cpu, 0x7A4, 0x5); return; } /* tail-jcc 0x007A45 */ /* jp 0x00E1 */
    if (cc_p(cpu)) { recomp_dispatch(cpu, 0x7A4, 0x7); return; } /* tail-jcc 0x007A47 */ /* jp 0x00E3 */
    if (cc_p(cpu)) { recomp_dispatch(cpu, 0x7A4, 0x9); return; } /* tail-jcc 0x007A49 */ /* jp 0x00E5 */
    RECOMP_TICK(cpu);
    if (cc_p(cpu)) goto L_fn_07964_0000E7;   /* jp 0x00E7 */
    RECOMP_TICK(cpu);
    if (cc_p(cpu)) goto L_fn_07964_0000E9;   /* jp 0x00E9 */
    RECOMP_TICK(cpu);
    if (cc_p(cpu)) goto L_fn_07964_0000EB;   /* jp 0x00EB */
    RECOMP_TICK(cpu);
    if (cc_p(cpu)) goto L_fn_07964_0000ED;   /* jp 0x00ED */
    if (cc_p(cpu)) { recomp_dispatch(cpu, 0x7A5, 0x3); return; } /* tail-jcc 0x007A53 */ /* jp 0x00EF */
    RECOMP_TICK(cpu);
    if (cc_p(cpu)) goto L_fn_07964_0000A5;   /* jp 0x00A5 */
    RECOMP_TICK(cpu);
    if (cc_p(cpu)) goto L_fn_07964_0000C8;   /* jp 0x00C8 */
    RECOMP_TICK(cpu);
    if (cc_p(cpu)) goto L_fn_07964_0000DD;   /* jp 0x00DD */
    if (cc_p(cpu)) { recomp_dispatch(cpu, 0x7A1, 0xD); return; } /* tail-jcc 0x007A1D */ /* jp 0x00B9 */
    if (cc_p(cpu)) { recomp_dispatch(cpu, 0x7AD, 0x8); return; } /* tail-jcc 0x007AD8 */ /* jp 0x0174 */
    if (cc_ge(cpu)) goto L_fn_07964_00012F;  /* jge 0x012F */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0xE) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0xE] */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x6))); /* mov di, word es:[bx+0x6] */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
L_fn_07964_00012F:;
    goto L_fn_07964_0001FF;                  /* jmp 0x01FF */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0xE) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x6))); /* mov ax, word es:[bx+0x6] */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->dx = (uint16_t)(cpu->di);           /* mov dx, di */
    flags_cmp16(cpu, cpu->ax, cpu->dx);      /* cmp ax, dx */
    if (cc_g(cpu)) goto L_fn_07964_000142;   /* jg 0x0142 */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
L_fn_07964_000142:;
    goto L_fn_07964_0001FF;                  /* jmp 0x01FF */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
    if (cc_ge(cpu)) goto L_fn_07964_000150;  /* jge 0x0150 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC0FE); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC0FE + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC0FE] */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov si, word es:[bx] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
L_fn_07964_000150:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(0x1)); /* mov word ss:[bp+-0x8], 0x1 */
    goto L_fn_07964_0001FF;                  /* jmp 0x01FF */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC0FE); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC0FE + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC0FE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->dx = (uint16_t)(cpu->si);           /* mov dx, si */
    flags_cmp16(cpu, cpu->ax, cpu->dx);      /* cmp ax, dx */
    if (cc_g(cpu)) goto L_fn_07964_000168;   /* jg 0x0168 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
L_fn_07964_000168:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(0x1)); /* mov word ss:[bp+-0x8], 0x1 */
    goto L_fn_07964_0001FF;                  /* jmp 0x01FF */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov si, word ss:[bp+-0x6] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0xFEC5)); /* add si, 0xFEC5 */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_l(cpu)) goto L_fn_07964_000186;   /* jl 0x0186 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC0FE); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC0FE + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC0FE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    flags_cmp16(cpu, cpu->ax, cpu->si);      /* cmp ax, si */
    if (cc_g(cpu)) goto L_fn_07964_00018B;   /* jg 0x018B */
L_fn_07964_000186:;
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* mov si, word ss:[bp+-0x10] */
    goto L_fn_07964_000195;                  /* jmp 0x0195 */
L_fn_07964_00018B:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* cmp si, word ss:[bp+-0x10] */
    if (cc_e(cpu)) goto L_fn_07964_000195;   /* je 0x0195 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(0x1)); /* mov word ss:[bp+-0x8], 0x1 */
L_fn_07964_000195:;
    goto L_fn_07964_0001FF;                  /* jmp 0x01FF */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(0x1)); /* mov word ss:[bp+-0x8], 0x1 */
    cpu->si = (uint16_t)(0xFFFF);            /* mov si, 0xFFFF */
    goto L_fn_07964_0001FF;                  /* jmp 0x01FF */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08453(cpu);                           /* call 0x0AEF */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x1)); /* mov word ss:[bp+-0x2], 0x1 */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07BFC(cpu);                           /* call 0x0298 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0xE) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0xE] */
    { uint16_t _o = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC)); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)((uint16_t)(cpu->bx + 0xC) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx+0xC] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->es, cpu->bx), 0x0); /* cmp word es:[bx], 0x0 */
    if (cc_e(cpu)) goto L_fn_07964_0001D9;   /* je 0x01D9 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0xE) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0xE] */
    { uint16_t _o = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC)); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)((uint16_t)(cpu->bx + 0xC) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx+0xC] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu,0xFFFF); dispatch_near(cpu, SEG_0000, mem_read16(cpu, cpu->es, cpu->bx)); /* call word es:[bx] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    goto L_fn_07964_0001DE;                  /* jmp 0x01DE */
L_fn_07964_0001D9:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x1)); /* mov word ss:[bp+-0x4], 0x1 */
L_fn_07964_0001DE:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_07964_0001EC;   /* je 0x01EC */
    flags_cmp16(cpu, cpu->ax, 0x1);          /* cmp ax, 0x1 */
    if (cc_e(cpu)) goto L_fn_07964_0001F6;   /* je 0x01F6 */
    goto L_fn_07964_0001EC;                  /* jmp 0x01EC */
L_fn_07964_0001EC:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(0x1)); /* mov word ss:[bp+-0x8], 0x1 */
    cpu->si = (uint16_t)(0xFFFF);            /* mov si, 0xFFFF */
    goto L_fn_07964_0001FD;                  /* jmp 0x01FD */
L_fn_07964_0001F6:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(0x1)); /* mov word ss:[bp+-0x8], 0x1 */
    goto L_fn_07964_0001FD;                  /* jmp 0x01FD */
L_fn_07964_0001FD:;
    goto L_fn_07964_0001FF;                  /* jmp 0x01FF */
L_fn_07964_0001FF:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x0); /* cmp word ss:[bp+-0x8], 0x0 */
    if (cc_ne(cpu)) goto L_fn_07964_000255;  /* jne 0x0255 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0xE) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0xE] */
    push16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x10))); /* push word es:[bx+0x10] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* mov ax, word ss:[bp+-0xA] */
    cpu->dx = (uint16_t)(0xA);               /* mov dx, 0xA */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x11)); /* add ax, 0x11 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0xE) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x12))); /* mov ax, word es:[bx+0x12] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03AB);                           /* call 0x8A47 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0xE) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0xE] */
    push16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x10))); /* push word es:[bx+0x10] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* mov ax, word ss:[bp+-0xA] */
    cpu->dx = (uint16_t)(0xA);               /* mov dx, 0xA */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x11)); /* add ax, 0x11 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0xE) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x12))); /* mov ax, word es:[bx+0x12] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x8A3B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_07964_000255:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x0); /* cmp word ss:[bp+-0x8], 0x0 */
    if (cc_ne(cpu)) goto L_fn_07964_00025E;  /* jne 0x025E */
    RECOMP_TICK(cpu);
    goto L_fn_07964_000074;                  /* jmp 0x0074 */
L_fn_07964_00025E:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x0); /* cmp word ss:[bp+-0x2], 0x0 */
    if (cc_ne(cpu)) goto L_fn_07964_000267;  /* jne 0x0267 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08453(cpu);                           /* call 0x0AEF */
L_fn_07964_000267:;
    flags_cmp16(cpu, cpu->si, 0xFFFF);       /* cmp si, 0xFFFF */
    if (cc_e(cpu)) goto L_fn_07964_00026F;   /* je 0x026F */
    RECOMP_TICK(cpu);
    goto L_fn_07964_00003B;                  /* jmp 0x003B */
L_fn_07964_00026F:;
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07BFC(cpu);                           /* call 0x0298 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12)), 0x0); /* cmp word ss:[bp+-0x12], 0x0 */
    if (cc_e(cpu)) goto L_fn_07964_000280;   /* je 0x0280 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0791E(cpu);                           /* call 0xFFBA */
L_fn_07964_000280:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5A6(cpu);                           /* call 0x5C42 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07162(cpu);                           /* call 0xF7FE */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14)), 0x0); /* cmp word ss:[bp+-0x14], 0x0 */
    if (cc_ne(cpu)) goto L_fn_07964_00028F;  /* jne 0x028F */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06997(cpu);                           /* call 0xF033 */
L_fn_07964_00028F:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xF202 */
L_fn_07964_000292:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07BFC(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07BFC");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x1E)); /* sub sp, 0x1E */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0020F(cpu);                           /* call 0x8613 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1E), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x1E], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CEA(cpu);                           /* call 0xF0EE */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1C), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x1C], ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CA6(cpu);                           /* call 0xF0AA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x85D2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xD);               /* mov ax, 0xD */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x87AC */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x85D2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x13E);             /* mov ax, 0x13E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x87AC */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC0FE); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC0FE + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC0FE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1A), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x1A], ax */
    goto L_fn_07BFC_000164;                  /* jmp 0x0164 */
L_fn_07BFC_000062:;
    cpu->bx = (uint16_t)((uint16_t)(cpu->bp - 0x16)); /* lea bx, word ss:[bp+-0x16] */
    push16(cpu, cpu->ss);                    /* push ss */
    push16(cpu, cpu->bx);                    /* push bx */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC0FE); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC0FE + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC0FE] */
    { uint16_t _o = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)((uint16_t)(cpu->bx + 0x2) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx+0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1A))); /* mov ax, word ss:[bp+-0x1A] */
    cpu->dx = (uint16_t)(0x14);              /* mov dx, 0x14 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->cx = (uint16_t)(0x14);              /* mov cx, 0x14 */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F937(cpu);                           /* call 0000:F937 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12))); /* mov ax, word ss:[bp+-0x12] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov si, word ss:[bp+-0x4] */
    cpu->di = (uint16_t)(0x2);               /* mov di, 0x2 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1A))); /* mov ax, word ss:[bp+-0x1A] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* cmp ax, word ss:[bp+0x4] */
    if (cc_ne(cpu)) goto L_fn_07BFC_0000CD;  /* jne 0x00CD */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x85D2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x87AC */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x85D2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* push word ss:[bp+-0x14] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16))); /* push word ss:[bp+-0x16] */
    push16(cpu, cpu->di);                    /* push di */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xF140 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    goto L_fn_07BFC_000161;                  /* jmp 0x0161 */
L_fn_07BFC_0000CD:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18), (uint16_t)(0x0)); /* mov word ss:[bp+-0x18], 0x0 */
    goto L_fn_07BFC_00011A;                  /* jmp 0x011A */
L_fn_07BFC_0000D4:;
    cpu->ax = (uint16_t)(0x7);               /* mov ax, 0x7 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x85D2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x87A9 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x9)); /* add ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x87A6 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x85D2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x9)); /* add ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x87A6 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x18] */
L_fn_07BFC_00011A:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18)), 0x2); /* cmp word ss:[bp+-0x18], 0x2 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_07BFC_0000D4;   /* jl 0x00D4 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00355(cpu);                           /* call 0x8759 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x85D2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x87AC */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x85D2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* push word ss:[bp+-0x14] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16))); /* push word ss:[bp+-0x16] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xF140 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_07BFC_000161:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1A), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1A)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ss:[bp+-0x1A] */
L_fn_07BFC_000164:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1A)), 0x0); /* cmp word ss:[bp+-0x1A], 0x0 */
    if (cc_l(cpu)) goto L_fn_07BFC_00016D;   /* jl 0x016D */
    RECOMP_TICK(cpu);
    goto L_fn_07BFC_000062;                  /* jmp 0x0062 */
L_fn_07BFC_00016D:;
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x87A3 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1E))); /* push word ss:[bp+-0x1E] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x85D2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1C))); /* push word ss:[bp+-0x1C] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CA6(cpu);                           /* call 0xF0AA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07D91(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07D91");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x14)); /* sub sp, 0x14 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14), (uint16_t)(0x2)); /* mov word ss:[bp+-0x14], 0x2 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x8)); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)((uint16_t)(cpu->bx + 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx+0x8] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xB), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0xB], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xD), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0xD], bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(0x0)); /* mov word ss:[bp+-0x10], 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12), (uint16_t)(0x0)); /* mov word ss:[bp+-0x12], 0x0 */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint8_t)(0x1)); /* mov byte ss:[bp+-0xE], 0x1 */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9), (uint8_t)(0x0)); /* mov byte ss:[bp+-0x9], 0x0 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x12))); /* mov ax, word es:[bx+0x12] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(0xD)); /* mov word ss:[bp+-0x6], 0xD */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x10))); /* mov ax, word es:[bx+0x10] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x6))); /* mov ax, word es:[bx+0x6] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x14)); /* lea ax, word ss:[bp+-0x14] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08480(cpu);                           /* call 0x06EF */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07DF1(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07DF1");
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xD36);             /* mov ax, 0xD36 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07932(cpu);                           /* call 0xFB41 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07DFC(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07DFC");
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xD78);             /* mov ax, 0xD78 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07932(cpu);                           /* call 0xFB36 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07E07(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07E07");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x8)); /* sub sp, 0x8 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x12))); /* mov ax, word es:[bx+0x12] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    flags_cmp16(cpu, cpu->ax, 0xFFFF);       /* cmp ax, 0xFFFF */
    if (cc_ne(cpu)) goto L_fn_07E07_000050;  /* jne 0x0050 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(0x1)); /* mov word ss:[bp+-0x6], 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x7)); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)((uint16_t)(cpu->bx + 0x7) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx+0x7] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    goto L_fn_07E07_000047;                  /* jmp 0x0047 */
L_fn_07E07_00002F:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0xA); /* cmp byte es:[bx], 0xA */
    if (cc_e(cpu)) goto L_fn_07E07_000041;   /* je 0x0041 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0xD); /* cmp byte es:[bx], 0xD */
    if (cc_ne(cpu)) goto L_fn_07E07_000044;  /* jne 0x0044 */
L_fn_07E07_000041:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x6] */
L_fn_07E07_000044:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x4] */
L_fn_07E07_000047:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0x0); /* cmp byte es:[bx], 0x0 */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_07E07_00002F;  /* jne 0x002F */
L_fn_07E07_000050:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    cpu->dx = (uint16_t)(0xA);               /* mov dx, 0xA */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xA)); /* add ax, 0xA */
    mem_write16(cpu, cpu->ds, 0xC11A, (uint16_t)(cpu->ax)); /* mov word ds:[0xC11A], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->es, cpu->bx), 0x2); /* cmp word es:[bx], 0x2 */
    if (cc_ne(cpu)) goto L_fn_07E07_00006C;  /* jne 0x006C */
    mem_write16(cpu, cpu->ds, 0xC11A, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0xC11A), 0x2))); /* sub word ds:[0xC11A], 0x2 */
L_fn_07E07_00006C:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov ax, word es:[bx+0x2] */
    { uint16_t _r = cpu->ax | mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4)); flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, word es:[bx+0x4] */
    if (cc_ne(cpu)) goto L_fn_07E07_000083;  /* jne 0x0083 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    mem_write16(cpu, cpu->ds, 0xC108, (uint16_t)(cpu->ax)); /* mov word ds:[0xC108], ax */
    goto L_fn_07E07_00009E;                  /* jmp 0x009E */
L_fn_07E07_000083:;
    mem_write16(cpu, cpu->ds, 0xC11A, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC11A), 0xE))); /* add word ds:[0xC11A], 0xE */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
L_fn_07E07_00008B:;
    push16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4))); /* push word es:[bx+0x4] */
    push16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* push word es:[bx+0x2] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CF6(cpu);                           /* call 0xEEEF */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    mem_write16(cpu, cpu->ds, 0xC108, (uint16_t)(cpu->ax)); /* mov word ds:[0xC108], ax */
L_fn_07E07_00009E:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x6))); /* mov al, byte es:[bx+0x6] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_07E07_0000B6;   /* je 0x00B6 */
    flags_cmp16(cpu, cpu->ax, 0x1);          /* cmp ax, 0x1 */
    if (cc_e(cpu)) goto L_fn_07E07_0000BE;   /* je 0x00BE */
    flags_cmp16(cpu, cpu->ax, 0x2);          /* cmp ax, 0x2 */
    if (cc_e(cpu)) goto L_fn_07E07_0000CE;   /* je 0x00CE */
    goto L_fn_07E07_0000DE;                  /* jmp 0x00DE */
L_fn_07E07_0000B6:;
    mem_write16(cpu, cpu->ds, 0xC104, (uint16_t)(0x0)); /* mov word ds:[0xC104], 0x0 */
    goto L_fn_07E07_0000DE;                  /* jmp 0x00DE */
L_fn_07E07_0000BE:;
    mem_write16(cpu, cpu->ds, 0xC11A, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC11A), 0xD))); /* add word ds:[0xC11A], 0xD */
    mem_write16(cpu, cpu->ds, 0xC104, (uint16_t)(0xD7E)); /* mov word ds:[0xC104], 0xD7E */
    cpu->si = (uint16_t)(0x78);              /* mov si, 0x78 */
    goto L_fn_07E07_0000DE;                  /* jmp 0x00DE */
L_fn_07E07_0000CE:;
    mem_write16(cpu, cpu->ds, 0xC11A, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC11A), 0xD))); /* add word ds:[0xC11A], 0xD */
L_fn_07E07_0000D3:;
    mem_write16(cpu, cpu->ds, 0xC104, (uint16_t)(0xD8B)); /* mov word ds:[0xC104], 0xD8B */
    cpu->si = (uint16_t)(0x94);              /* mov si, 0x94 */
    goto L_fn_07E07_0000DE;                  /* jmp 0x00DE */
L_fn_07E07_0000DE:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    flags_cmp16(cpu, cpu->ax, 0x7);          /* cmp ax, 0x7 */
    if (cc_be(cpu)) goto L_fn_07E07_0000EC;  /* jbe 0x00EC */
    recomp_dispatch(cpu, 0x805, 0xB); return; /* tail-jmp 0x00805B */ /* jmp 0x0254 */
L_fn_07E07_0000EC:;
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x7EFC))); return; /* jmp word cs:[bx+0x7EFC] */
    { uint8_t _r = cpu->al | 0x7F; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, 0x7F */
    { uint8_t _r = cpu->al | 0x7F; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, 0x7F */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc dx */
    if (cc_g(cpu)) { recomp_dispatch(cpu, 0x7F4, 0x5); return; } /* tail-jcc 0x007F45 */ /* jg 0x013E */
    if (cc_g(cpu)) { recomp_dispatch(cpu, 0x7F5, 0xC); return; } /* tail-jcc 0x007F5C */ /* jg 0x0155 */
    RECOMP_TICK(cpu);
    if (cc_g(cpu)) goto L_fn_07E07_00008B;   /* jg 0x008B */
    RECOMP_TICK(cpu);
    if (cc_g(cpu)) goto L_fn_07E07_0000D3;   /* jg 0x00D3 */
    if (cc_g(cpu)) { recomp_dispatch(cpu, 0x7F2, 0x1); return; } /* tail-jcc 0x007F21 */ /* jg 0x011A */
    recomp_dispatch(cpu, 0x7F0, 0xB); return; /* fallthrough 0x007F0B */
}

void fn_07F0C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07F0C");
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov ax, word es:[bx+0x2] */
    { uint16_t _r = cpu->ax | mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4)); flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, word es:[bx+0x4] */
    if (cc_ne(cpu)) goto L_fn_07F0C_000021;  /* jne 0x0021 */
    mem_write16(cpu, cpu->ds, 0xC12A, (uint16_t)(0x4)); /* mov word ds:[0xC12A], 0x4 */
    mem_write16(cpu, cpu->ds, 0xC128, (uint16_t)(0x6)); /* mov word ds:[0xC128], 0x6 */
    mem_write16(cpu, cpu->ds, 0xC102, (uint16_t)(0x7)); /* mov word ds:[0xC102], 0x7 */
    goto L_fn_07F0C_000033;                  /* jmp 0x0033 */
L_fn_07F0C_000021:;
    mem_write16(cpu, cpu->ds, 0xC12A, (uint16_t)(0x8)); /* mov word ds:[0xC12A], 0x8 */
    mem_write16(cpu, cpu->ds, 0xC128, (uint16_t)(0x4)); /* mov word ds:[0xC128], 0x4 */
    mem_write16(cpu, cpu->ds, 0xC102, (uint16_t)(0x9)); /* mov word ds:[0xC102], 0x9 */
L_fn_07F0C_000033:;
    goto L_fn_07F0C_00014F;                  /* jmp 0x014F */
    mem_write16(cpu, cpu->ds, 0xC12A, (uint16_t)(0x0)); /* mov word ds:[0xC12A], 0x0 */
    mem_write16(cpu, cpu->ds, 0xC128, (uint16_t)(0x2)); /* mov word ds:[0xC128], 0x2 */
    mem_write16(cpu, cpu->ds, 0xC102, (uint16_t)(0x4)); /* mov word ds:[0xC102], 0x4 */
    goto L_fn_07F0C_00014F;                  /* jmp 0x014F */
    mem_write16(cpu, cpu->ds, 0xC12A, (uint16_t)(0x6)); /* mov word ds:[0xC12A], 0x6 */
    mem_write16(cpu, cpu->ds, 0xC128, (uint16_t)(0x4)); /* mov word ds:[0xC128], 0x4 */
    mem_write16(cpu, cpu->ds, 0xC102, (uint16_t)(0xB)); /* mov word ds:[0xC102], 0xB */
    mem_write16(cpu, cpu->ds, 0xC112, (uint16_t)(0xDA9)); /* mov word ds:[0xC112], 0xDA9 */
    mem_write16(cpu, cpu->ds, 0xC116, (uint16_t)(0x78)); /* mov word ds:[0xC116], 0x78 */
    mem_write16(cpu, cpu->ds, 0xC124, (uint16_t)(0xD)); /* mov word ds:[0xC124], 0xD */
    cpu->si = (uint16_t)(0x8C);              /* mov si, 0x8C */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC124)); /* mov ax, word ds:[0xC124] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x3)); /* add ax, 0x3 */
    mem_write16(cpu, cpu->ds, 0xC11A, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC11A), cpu->ax))); /* add word ds:[0xC11A], ax */
    goto L_fn_07F0C_00014F;                  /* jmp 0x014F */
    mem_write16(cpu, cpu->ds, 0xC12A, (uint16_t)(0x6)); /* mov word ds:[0xC12A], 0x6 */
    mem_write16(cpu, cpu->ds, 0xC128, (uint16_t)(0x4)); /* mov word ds:[0xC128], 0x4 */
    mem_write16(cpu, cpu->ds, 0xC102, (uint16_t)(0xB)); /* mov word ds:[0xC102], 0xB */
    mem_write16(cpu, cpu->ds, 0xC112, (uint16_t)(0xD9A)); /* mov word ds:[0xC112], 0xD9A */
    mem_write16(cpu, cpu->ds, 0xC114, (uint16_t)(0xDA9)); /* mov word ds:[0xC114], 0xDA9 */
    mem_write16(cpu, cpu->ds, 0xC116, (uint16_t)(0x78)); /* mov word ds:[0xC116], 0x78 */
    mem_write16(cpu, cpu->ds, 0xC118, (uint16_t)(0x78)); /* mov word ds:[0xC118], 0x78 */
    mem_write16(cpu, cpu->ds, 0xC124, (uint16_t)(0xD)); /* mov word ds:[0xC124], 0xD */
    mem_write16(cpu, cpu->ds, 0xC126, (uint16_t)(0xD)); /* mov word ds:[0xC126], 0xD */
    cpu->si = (uint16_t)(0x10E);             /* mov si, 0x10E */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC124)); /* mov ax, word ds:[0xC124] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x3)); /* add ax, 0x3 */
    mem_write16(cpu, cpu->ds, 0xC11A, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC11A), cpu->ax))); /* add word ds:[0xC11A], ax */
    goto L_fn_07F0C_00014F;                  /* jmp 0x014F */
    mem_write16(cpu, cpu->ds, 0xC12A, (uint16_t)(0x6)); /* mov word ds:[0xC12A], 0x6 */
    mem_write16(cpu, cpu->ds, 0xC128, (uint16_t)(0x4)); /* mov word ds:[0xC128], 0x4 */
    mem_write16(cpu, cpu->ds, 0xC102, (uint16_t)(0xB)); /* mov word ds:[0xC102], 0xB */
    mem_write16(cpu, cpu->ds, 0xC112, (uint16_t)(0xD9A)); /* mov word ds:[0xC112], 0xD9A */
    mem_write16(cpu, cpu->ds, 0xC114, (uint16_t)(0xDB7)); /* mov word ds:[0xC114], 0xDB7 */
    mem_write16(cpu, cpu->ds, 0xC116, (uint16_t)(0x78)); /* mov word ds:[0xC116], 0x78 */
    mem_write16(cpu, cpu->ds, 0xC118, (uint16_t)(0x78)); /* mov word ds:[0xC118], 0x78 */
    mem_write16(cpu, cpu->ds, 0xC124, (uint16_t)(0xD)); /* mov word ds:[0xC124], 0xD */
    mem_write16(cpu, cpu->ds, 0xC126, (uint16_t)(0xD)); /* mov word ds:[0xC126], 0xD */
    cpu->si = (uint16_t)(0x10E);             /* mov si, 0x10E */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC124)); /* mov ax, word ds:[0xC124] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x3)); /* add ax, 0x3 */
    mem_write16(cpu, cpu->ds, 0xC11A, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC11A), cpu->ax))); /* add word ds:[0xC11A], ax */
    goto L_fn_07F0C_00014F;                  /* jmp 0x014F */
    mem_write16(cpu, cpu->ds, 0xC12A, (uint16_t)(0x8)); /* mov word ds:[0xC12A], 0x8 */
    mem_write16(cpu, cpu->ds, 0xC128, (uint16_t)(0x4)); /* mov word ds:[0xC128], 0x4 */
    mem_write16(cpu, cpu->ds, 0xC102, (uint16_t)(0x4)); /* mov word ds:[0xC102], 0x4 */
    mem_write16(cpu, cpu->ds, 0xC112, (uint16_t)(0xDC0)); /* mov word ds:[0xC112], 0xDC0 */
    mem_write16(cpu, cpu->ds, 0xC114, (uint16_t)(0xDBC)); /* mov word ds:[0xC114], 0xDBC */
    mem_write16(cpu, cpu->ds, 0xC116, (uint16_t)(0x28)); /* mov word ds:[0xC116], 0x28 */
    mem_write16(cpu, cpu->ds, 0xC118, (uint16_t)(0x28)); /* mov word ds:[0xC118], 0x28 */
    mem_write16(cpu, cpu->ds, 0xC124, (uint16_t)(0xB)); /* mov word ds:[0xC124], 0xB */
    mem_write16(cpu, cpu->ds, 0xC126, (uint16_t)(0xB)); /* mov word ds:[0xC126], 0xB */
    cpu->si = (uint16_t)(0x6E);              /* mov si, 0x6E */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC124)); /* mov ax, word ds:[0xC124] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    mem_write16(cpu, cpu->ds, 0xC11A, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC11A), cpu->ax))); /* add word ds:[0xC11A], ax */
    goto L_fn_07F0C_00014F;                  /* jmp 0x014F */
L_fn_07F0C_00014F:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC108)); /* mov ax, word ds:[0xC108] */
    flags_cmp16(cpu, cpu->ax, cpu->si);      /* cmp ax, si */
    if (cc_ge(cpu)) goto L_fn_07F0C_00015A;  /* jge 0x015A */
    mem_write16(cpu, cpu->ds, 0xC108, (uint16_t)(cpu->si)); /* mov word ds:[0xC108], si */
L_fn_07F0C_00015A:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC128)); /* mov ax, word ds:[0xC128] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC102))); /* add ax, word ds:[0xC102] */
    mem_write16(cpu, cpu->ds, 0xC11A, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC11A), cpu->ax))); /* add word ds:[0xC11A], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x10))); /* mov di, word es:[bx+0x10] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    flags_cmp16(cpu, cpu->ax, 0xFFFF);       /* cmp ax, 0xFFFF */
    if (cc_ne(cpu)) goto L_fn_07F0C_00018E;  /* jne 0x018E */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    push16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x9))); /* push word es:[bx+0x9] */
    push16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x7))); /* push word es:[bx+0x7] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CF6(cpu);                           /* call 0xEDEA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC12A)); /* mov ax, word ds:[0xC12A] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_07F0C_00018E:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC108)); /* mov ax, word ds:[0xC108] */
    flags_cmp16(cpu, cpu->ax, cpu->di);      /* cmp ax, di */
    if (cc_ge(cpu)) goto L_fn_07F0C_000199;  /* jge 0x0199 */
    mem_write16(cpu, cpu->ds, 0xC108, (uint16_t)(cpu->di)); /* mov word ds:[0xC108], di */
L_fn_07F0C_000199:;
    mem_write16(cpu, cpu->ds, 0xC108, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC108), 0xA))); /* add word ds:[0xC108], 0xA */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC))); /* mov ax, word es:[bx+0xC] */
    mem_write16(cpu, cpu->ds, 0xC10A, (uint16_t)(cpu->ax)); /* mov word ds:[0xC10A], ax */
    flags_cmp16(cpu, cpu->ax, 0xFFFF);       /* cmp ax, 0xFFFF */
    if (cc_ne(cpu)) goto L_fn_07F0C_0001BD;  /* jne 0x01BD */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC108))); /* sub ax, word ds:[0xC108] */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x01B8; recomp_div0("idiv16"); } } /* idiv bx */
    mem_write16(cpu, cpu->ds, 0xC10A, (uint16_t)(cpu->ax)); /* mov word ds:[0xC10A], ax */
L_fn_07F0C_0001BD:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xE))); /* mov ax, word es:[bx+0xE] */
    mem_write16(cpu, cpu->ds, 0xC106, (uint16_t)(cpu->ax)); /* mov word ds:[0xC106], ax */
    flags_cmp16(cpu, cpu->ax, 0xFFFF);       /* cmp ax, 0xFFFF */
    if (cc_ne(cpu)) goto L_fn_07F0C_0001DC;  /* jne 0x01DC */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC11A))); /* sub ax, word ds:[0xC11A] */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x01D7; recomp_div0("idiv16"); } } /* idiv bx */
    mem_write16(cpu, cpu->ds, 0xC106, (uint16_t)(cpu->ax)); /* mov word ds:[0xC106], ax */
L_fn_07F0C_0001DC:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC108)); /* mov ax, word ds:[0xC108] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)))); /* sub ax, word ss:[bp+-0x8] */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x01E9; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC10A))); /* add ax, word ds:[0xC10A] */
    mem_write16(cpu, cpu->ds, 0xC122, (uint16_t)(cpu->ax)); /* mov word ds:[0xC122], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC108)); /* mov ax, word ds:[0xC108] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->si)); /* sub ax, si */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x01FE; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC10A))); /* add ax, word ds:[0xC10A] */
    mem_write16(cpu, cpu->ds, 0xC120, (uint16_t)(cpu->ax)); /* mov word ds:[0xC120], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    flags_cmp16(cpu, cpu->ax, 0x7);          /* cmp ax, 0x7 */
    if (cc_be(cpu)) goto L_fn_07F0C_000215;  /* jbe 0x0215 */
    recomp_dispatch(cpu, 0x820, 0x4); return; /* tail-jmp 0x008204 */ /* jmp 0x02F8 */
L_fn_07F0C_000215:;
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx - 0x7ED6))); return; /* jmp word cs:[bx+-0x7ED6] */
    flags_cmp8(cpu, cpu->al, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di - 0x7EC6))); /* cmp al, byte ds:[bx+di+-0x7EC6] */
    flags_cmp8(cpu, cpu->al, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di - 0x7EC6))); /* cmp al, byte ds:[bx+di+-0x7EC6] */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->di - 0x7F), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di - 0x7F)), 0x819B))); /* sub word ds:[di+-0x7F], 0x819B */
    cpu->sp = cpu->bp; cpu->bp = pop16(cpu); /* leave */
    recomp_dispatch(cpu, 0x813, 0x9); return; /* fallthrough 0x008139 */
}

void fn_0813A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0813A");
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC106)); /* mov ax, word ds:[0xC106] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC11A))); /* add ax, word ds:[0xC11A] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFEF)); /* add ax, 0xFFEF */
    mem_write16(cpu, cpu->ds, 0xC110, (uint16_t)(cpu->ax)); /* mov word ds:[0xC110], ax */
    goto L_fn_0813A_0000CA;                  /* jmp 0x00CA */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC10A)); /* mov ax, word ds:[0xC10A] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC108))); /* add ax, word ds:[0xC108] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFF78)); /* add ax, 0xFF78 */
    mem_write16(cpu, cpu->ds, 0xC11C, (uint16_t)(cpu->ax)); /* mov word ds:[0xC11C], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC106)); /* mov ax, word ds:[0xC106] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC11A))); /* add ax, word ds:[0xC11A] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC124)); /* mov dx, word ds:[0xC124] */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 0x7)); /* add dx, 0x7 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->dx)); /* sub ax, dx */
    mem_write16(cpu, cpu->ds, 0xC10C, (uint16_t)(cpu->ax)); /* mov word ds:[0xC10C], ax */
    goto L_fn_0813A_0000CA;                  /* jmp 0x00CA */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC10A)); /* mov ax, word ds:[0xC10A] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xE)); /* add ax, 0xE */
    mem_write16(cpu, cpu->ds, 0xC11C, (uint16_t)(cpu->ax)); /* mov word ds:[0xC11C], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC10A)); /* mov ax, word ds:[0xC10A] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC108))); /* add ax, word ds:[0xC108] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFF78)); /* add ax, 0xFF78 */
    mem_write16(cpu, cpu->ds, 0xC11E, (uint16_t)(cpu->ax)); /* mov word ds:[0xC11E], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC106)); /* mov ax, word ds:[0xC106] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC11A))); /* add ax, word ds:[0xC11A] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC124)); /* mov dx, word ds:[0xC124] */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 0x7)); /* add dx, 0x7 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->dx)); /* sub ax, dx */
    mem_write16(cpu, cpu->ds, 0xC10E, (uint16_t)(cpu->ax)); /* mov word ds:[0xC10E], ax */
    mem_write16(cpu, cpu->ds, 0xC10C, (uint16_t)(cpu->ax)); /* mov word ds:[0xC10C], ax */
    goto L_fn_0813A_0000CA;                  /* jmp 0x00CA */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC10A)); /* mov ax, word ds:[0xC10A] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xE)); /* add ax, 0xE */
    mem_write16(cpu, cpu->ds, 0xC11C, (uint16_t)(cpu->ax)); /* mov word ds:[0xC11C], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC10A)); /* mov ax, word ds:[0xC10A] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC108))); /* add ax, word ds:[0xC108] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFF78)); /* add ax, 0xFF78 */
    mem_write16(cpu, cpu->ds, 0xC11E, (uint16_t)(cpu->ax)); /* mov word ds:[0xC11E], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC106)); /* mov ax, word ds:[0xC106] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC11A))); /* add ax, word ds:[0xC11A] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC124)); /* mov dx, word ds:[0xC124] */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 0x7)); /* add dx, 0x7 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->dx)); /* sub ax, dx */
    mem_write16(cpu, cpu->ds, 0xC10E, (uint16_t)(cpu->ax)); /* mov word ds:[0xC10E], ax */
    mem_write16(cpu, cpu->ds, 0xC10C, (uint16_t)(cpu->ax)); /* mov word ds:[0xC10C], ax */
    goto L_fn_0813A_0000CA;                  /* jmp 0x00CA */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC106)); /* mov ax, word ds:[0xC106] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC11A))); /* add ax, word ds:[0xC11A] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFEF)); /* add ax, 0xFFEF */
    mem_write16(cpu, cpu->ds, 0xC110, (uint16_t)(cpu->ax)); /* mov word ds:[0xC110], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC10A)); /* mov ax, word ds:[0xC10A] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC108))); /* add ax, word ds:[0xC108] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFC8)); /* add ax, 0xFFC8 */
    mem_write16(cpu, cpu->ds, 0xC11C, (uint16_t)(cpu->ax)); /* mov word ds:[0xC11C], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC11C)); /* mov ax, word ds:[0xC11C] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFCE)); /* add ax, 0xFFCE */
    mem_write16(cpu, cpu->ds, 0xC11E, (uint16_t)(cpu->ax)); /* mov word ds:[0xC11E], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC106)); /* mov ax, word ds:[0xC106] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC11A))); /* add ax, word ds:[0xC11A] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC124)); /* mov dx, word ds:[0xC124] */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 0x17)); /* add dx, 0x17 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->dx)); /* sub ax, dx */
    mem_write16(cpu, cpu->ds, 0xC10E, (uint16_t)(cpu->ax)); /* mov word ds:[0xC10E], ax */
    mem_write16(cpu, cpu->ds, 0xC10C, (uint16_t)(cpu->ax)); /* mov word ds:[0xC10C], ax */
    goto L_fn_0813A_0000CA;                  /* jmp 0x00CA */
L_fn_0813A_0000CA:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 0x4)); /* sub ax, 0x4 */
    flags_cmp16(cpu, cpu->ax, 0x3);          /* cmp ax, 0x3 */
    if (cc_a(cpu)) goto L_fn_0813A_000127;   /* ja 0x0127 */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx - 0x7DE5))); return; /* jmp word cs:[bx+-0x7DE5] */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc cx */
    { uint8_t _r = mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di)) & 0x82; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di), (uint8_t)(_r)); } /* and byte ss:[bp+di], 0x82 */
    { uint16_t _r = cpu->ax & mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->si - 0x7DDD)); flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, word ss:[bp+si+-0x7DDD] */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC114)); /* push word ds:[0xC114] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CF6(cpu);                           /* call 0xEBBC */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC118)); /* mov ax, word ds:[0xC118] */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->dx)); /* sub ax, dx */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x00FE; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC11E))); /* add ax, word ds:[0xC11E] */
    mem_write16(cpu, cpu->ds, 0xC12E, (uint16_t)(cpu->ax)); /* mov word ds:[0xC12E], ax */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC112)); /* push word ds:[0xC112] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CF6(cpu);                           /* call 0xEBBC */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC116)); /* mov ax, word ds:[0xC116] */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->dx)); /* sub ax, dx */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x011C; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC11C))); /* add ax, word ds:[0xC11C] */
    mem_write16(cpu, cpu->ds, 0xC12C, (uint16_t)(cpu->ax)); /* mov word ds:[0xC12C], ax */
    goto L_fn_0813A_000127;                  /* jmp 0x0127 */
L_fn_0813A_000127:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_08267(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_08267");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3EE4))); /* mov di, word ds:[bx+-0x3EE4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3EF4))); /* mov si, word ds:[bx+-0x3EF4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3EEA))); /* mov ax, word ds:[bx+-0x3EEA] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3EDC))); /* mov ax, word ds:[bx+-0x3EDC] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x813B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)))); /* add ax, word ss:[bp+-0x2] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x813B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x813E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)))); /* add ax, word ss:[bp+-0x4] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x813E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x813B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)))); /* add ax, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x813B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)))); /* add ax, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x813B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)))); /* add ax, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)))); /* add ax, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x813B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3EEE))); /* push word ds:[bx+-0x3EEE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFF6)); /* add ax, 0xFFF6 */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x00F6; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->si)); /* add ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3ED4))); /* push word ds:[bx+-0x3ED4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xEAD5 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_08378(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_08378");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3EE4))); /* mov si, word ds:[bx+-0x3EE4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3EF4))); /* mov di, word ds:[bx+-0x3EF4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3EEA))); /* mov ax, word ds:[bx+-0x3EEA] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3EDC))); /* mov ax, word ds:[bx+-0x3EDC] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFC)); /* add ax, 0xFFFC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03AB);                           /* call 0x8033 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFC)); /* add ax, 0xFFFC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03AB);                           /* call 0x8033 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFC)); /* add ax, 0xFFFC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)))); /* add ax, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03AB);                           /* call 0x8033 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x8027 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_08414(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_08414");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_08414_000018;                  /* jmp 0x0018 */
L_fn_08414_000008:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08378(cpu);                           /* call 0xFF64 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xE);               /* mov ax, 0xE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C26(cpu);                           /* call 0xE812 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_08414_000018:;
    flags_cmp16(cpu, cpu->si, 0x4);          /* cmp si, 0x4 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_08414_000008;   /* jl 0x0008 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_08434(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_08434");
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5CC)); /* push word ds:[0xC5CC] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5CA)); /* push word ds:[0xC5CA] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC11A)); /* push word ds:[0xC11A] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC108)); /* push word ds:[0xC108] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC106)); /* push word ds:[0xC106] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC10A)); /* push word ds:[0xC10A] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03AE);                           /* call 0x7F7A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->sp += 2; return;                    /* ret */
}

void fn_08453(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_08453");
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5CC)); /* push word ds:[0xC5CC] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5CA)); /* push word ds:[0xC5CA] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC106)); /* push word ds:[0xC106] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC10A)); /* push word ds:[0xC10A] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B1);                           /* call 0x7F5E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC11A)); /* push word ds:[0xC11A] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC108)); /* push word ds:[0xC108] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC106)); /* push word ds:[0xC106] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC10A)); /* push word ds:[0xC10A] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x7F4C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_08480(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_08480");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0xA)); /* sub sp, 0xA */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0020F(cpu);                           /* call 0x7D8F */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xA], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CEA(cpu);                           /* call 0xE86A */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CA6(cpu);                           /* call 0xE826 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07E07(cpu);                           /* call 0xF987 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)), 0x0); /* cmp word ss:[bp+0x8], 0x0 */
    if (cc_e(cpu)) goto L_fn_08480_00002F;   /* je 0x002F */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08434(cpu);                           /* call 0xFFB4 */
L_fn_08480_00002F:;
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x7D4E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC11A)); /* push word ds:[0xC11A] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC108)); /* push word ds:[0xC108] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC106)); /* push word ds:[0xC106] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC10A)); /* push word ds:[0xC10A] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x7F28 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC10A)); /* mov ax, word ds:[0xC10A] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC106)); /* mov si, word ds:[0xC106] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->es, cpu->bx), 0x2); /* cmp word es:[bx], 0x2 */
    if (cc_e(cpu)) goto L_fn_08480_000067;   /* je 0x0067 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_08480_000067:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC108)); /* mov ax, word ds:[0xC108] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFF6)); /* add ax, 0xFFF6 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC11A)); /* mov ax, word ds:[0xC11A] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFF8)); /* add ax, 0xFFF8 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->es, cpu->bx), 0x2); /* cmp word es:[bx], 0x2 */
    if (cc_e(cpu)) goto L_fn_08480_000086;   /* je 0x0086 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x2))); /* sub word ss:[bp+-0x2], 0x2 */
L_fn_08480_000086:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x7D4E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_08480_0000B1;                  /* jmp 0x00B1 */
L_fn_08480_000091:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x2))); /* add word ss:[bp+-0x4], 0x2 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x2))); /* add word ss:[bp+-0x2], 0x2 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    push16(cpu, cpu->ax);                    /* push ax */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ss:[bp+-0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00355(cpu);                           /* call 0x7ED5 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_08480_0000B1:;
    flags_cmp16(cpu, cpu->di, 0x2);          /* cmp di, 0x2 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_08480_000091;   /* jl 0x0091 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x7D4E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_08480_0000D9;                  /* jmp 0x00D9 */
L_fn_08480_0000C1:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)))); /* add ax, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->di)); /* add ax, di */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x7F25 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_08480_0000D9:;
    flags_cmp16(cpu, cpu->di, 0x2);          /* cmp di, 0x2 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_08480_0000C1;   /* jl 0x00C1 */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_08480_0000FA;                  /* jmp 0x00FA */
L_fn_08480_0000E2:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)))); /* add ax, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->di)); /* add ax, di */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x7F22 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_08480_0000FA:;
    flags_cmp16(cpu, cpu->di, 0x2);          /* cmp di, 0x2 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_08480_0000E2;   /* jl 0x00E2 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6)), 0x2))); /* add word ss:[bp+-0x6], 0x2 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x4))); /* sub word ss:[bp+-0x4], 0x4 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov ax, word es:[bx+0x2] */
    { uint16_t _r = cpu->ax | mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4)); flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, word es:[bx+0x4] */
    if (cc_e(cpu)) goto L_fn_08480_00014C;   /* je 0x014C */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x7D4E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    push16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4))); /* push word es:[bx+0x4] */
    push16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* push word es:[bx+0x2] */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC122)); /* push word ds:[0xC122] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xE8BC */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0xB)); /* add si, 0xB */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x7D4E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x7F22 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_08480_00014C:;
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, mem_read16(cpu, cpu->ds, 0xC128))); /* add si, word ds:[0xC128] */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x7D4E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    push16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x9))); /* push word es:[bx+0x9] */
    push16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x7))); /* push word es:[bx+0x7] */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC12A))); /* add ax, word ds:[0xC12A] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xE8BC */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC104), 0x0); /* cmp word ds:[0xC104], 0x0 */
    if (cc_e(cpu)) goto L_fn_08480_0001AC;   /* je 0x01AC */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x7D4E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC110)); /* mov ax, word ds:[0xC110] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x7F22 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x7D4E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC104)); /* push word ds:[0xC104] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC110)); /* push word ds:[0xC110] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC120)); /* push word ds:[0xC120] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0xE8BC */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_08480_0001AC:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->es, cpu->bx), 0x4); /* cmp word es:[bx], 0x4 */
    if (cc_e(cpu)) goto L_fn_08480_0001C7;   /* je 0x01C7 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->es, cpu->bx), 0x5); /* cmp word es:[bx], 0x5 */
    if (cc_e(cpu)) goto L_fn_08480_0001C7;   /* je 0x01C7 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->es, cpu->bx), 0x6); /* cmp word es:[bx], 0x6 */
    if (cc_ne(cpu)) goto L_fn_08480_0001E1;  /* jne 0x01E1 */
L_fn_08480_0001C7:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x7D4E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC10C)); /* mov ax, word ds:[0xC10C] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x7F22 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_08480_0001E1:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 0x4)); /* sub ax, 0x4 */
    flags_cmp16(cpu, cpu->ax, 0x3);          /* cmp ax, 0x3 */
    if (cc_a(cpu)) goto L_fn_08480_00021F;   /* ja 0x021F */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx - 0x7988))); return; /* jmp word cs:[bx+-0x7988] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x7980), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x7980], al */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x7980), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x7980)), 0xB8))); /* add byte ss:[bp+-0x7980], 0xB8 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si)), cpu->ax))); /* add word ds:[bx+si], ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08267(cpu);                           /* call 0xFDE7 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08267(cpu);                           /* call 0xFDE7 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xB))); /* mov al, byte es:[bx+0xB] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08378(cpu);                           /* call 0xFEF8 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_08480_00021F;                  /* jmp 0x021F */
L_fn_08480_00021F:;
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC11A)); /* push word ds:[0xC11A] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC108)); /* push word ds:[0xC108] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC106)); /* push word ds:[0xC106] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC10A)); /* push word ds:[0xC10A] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x7F1F */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* push word ss:[bp+-0xA] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x7D4E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CA6(cpu);                           /* call 0xE826 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_086C9(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_086C9");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x6)); /* sub sp, 0x6 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B74(cpu);                           /* call 0xE4AB */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06990(cpu);                           /* call 0xE2C7 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0703E(cpu);                           /* call 0xE975 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D593(cpu);                           /* call 0x4ECA */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0792C(cpu);                           /* call 0xF263 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07925(cpu);                           /* call 0xF25C */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xE49D */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xB))); /* mov al, byte es:[bx+0xB] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08480(cpu);                           /* call 0xFDB7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    goto L_fn_086C9_000112;                  /* jmp 0x0112 */
L_fn_086C9_000043:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B1A(cpu);                           /* call 0xE451 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    flags_cmp16(cpu, cpu->ax, 0x1);          /* cmp ax, 0x1 */
    if (cc_e(cpu)) goto L_fn_086C9_00005C;   /* je 0x005C */
    flags_cmp16(cpu, cpu->ax, 0x7);          /* cmp ax, 0x7 */
    if (cc_e(cpu)) goto L_fn_086C9_000073;   /* je 0x0073 */
    goto L_fn_086C9_000112;                  /* jmp 0x0112 */
L_fn_086C9_00005C:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    flags_cmp16(cpu, cpu->ax, 0xD);          /* cmp ax, 0xD */
    if (cc_e(cpu)) goto L_fn_086C9_00006B;   /* je 0x006B */
    flags_cmp16(cpu, cpu->ax, 0x1B);         /* cmp ax, 0x1B */
    if (cc_e(cpu)) goto L_fn_086C9_00006B;   /* je 0x006B */
    goto L_fn_086C9_000070;                  /* jmp 0x0070 */
L_fn_086C9_00006B:;
    cpu->di = (uint16_t)(0x1);               /* mov di, 0x1 */
    goto L_fn_086C9_000070;                  /* jmp 0x0070 */
L_fn_086C9_000070:;
    goto L_fn_086C9_000112;                  /* jmp 0x0112 */
L_fn_086C9_000073:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    cpu->cx = (uint16_t)(0xB);               /* mov cx, 0xB */
    cpu->bx = (uint16_t)(0x8755);            /* mov bx, 0x8755 */
L_fn_086C9_00007C:;
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, SEG_0000, cpu->bx)); /* cmp ax, word cs:[bx] */
    if (cc_e(cpu)) goto L_fn_086C9_000088;   /* je 0x0088 */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_086C9_00007C; /* loop 0x007C */
    goto L_fn_086C9_000110;                  /* jmp 0x0110 */
L_fn_086C9_000088:;
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x16))); return; /* jmp word cs:[bx+0x16] */
    { uint16_t _r = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si)) | cpu->ax; flags_logic16(cpu, _r); mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si), (uint16_t)(_r)); } /* or word ds:[bx+si], ax */
    { uint16_t _r = cpu->ax | 0x1B00; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, 0x1B00 */
    mem_write8(cpu, cpu->ss, cpu->bp, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ss, cpu->bp), cpu->cl))); /* add byte ss:[bp], cl */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write8(cpu, cpu->ss, cpu->bp, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ss, cpu->bp), cpu->ch))); /* add byte ss:[bp], ch */
    if (cc_ns(cpu)) goto L_fn_086C9_00009A;  /* jns 0x009A */
L_fn_086C9_00009A:;
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di + 0x1), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di + 0x1)), cpu->cx))); /* add word ss:[bp+di+0x1], cx */
    { int _cf = cf(cpu); cpu->bp = (uint16_t)(flags_sub16(cpu, cpu->bp, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec bp */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1)), cpu->dx))); /* add word ds:[bx+si+0x1], dx */
    cpu->dl = (uint8_t)(0x87);               /* mov dl, 0x87 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x782F), (uint16_t)(0x8781)); /* mov word ds:[bx+-0x782F], 0x8781 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { uint16_t _t = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di - 0x6679)); mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di - 0x6679), (uint16_t)(cpu->ax)); cpu->ax = (uint16_t)(_t); } /* xchg word ds:[bx+di+-0x6679], ax */
    { uint16_t _t = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->si - 0x4D79)); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->si - 0x4D79), (uint16_t)(cpu->si)); cpu->si = (uint16_t)(_t); } /* xchg word ss:[bp+si+-0x4D79], si */
    { uint16_t _t = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->si - 0x4D79)); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->si - 0x4D79), (uint16_t)(cpu->si)); cpu->si = (uint16_t)(_t); } /* xchg word ss:[bp+si+-0x4D79], si */
    { uint16_t _t = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di + 0x1FE)); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di + 0x1FE), (uint16_t)(cpu->ax)); cpu->ax = (uint16_t)(_t); } /* xchg word ss:[bp+di+0x1FE], ax */
    if (cc_ne(cpu)) goto L_fn_086C9_0000C2;  /* jne 0x00C2 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08378(cpu);                           /* call 0xFCAF */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_086C9_0000C2:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08414(cpu);                           /* call 0xFD4B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(0x1);               /* mov di, 0x1 */
    goto L_fn_086C9_000110;                  /* jmp 0x0110 */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_ne(cpu)) goto L_fn_086C9_0000D9;  /* jne 0x00D9 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08378(cpu);                           /* call 0xFCAF */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_086C9_0000D9:;
    cpu->si = (uint16_t)(0x1);               /* mov si, 0x1 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08414(cpu);                           /* call 0xFD4B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(0x1);               /* mov di, 0x1 */
    goto L_fn_086C9_000110;                  /* jmp 0x0110 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08378(cpu);                           /* call 0xFCAF */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_sub16(cpu, 0, cpu->ax)); /* neg ax */
    cpu->ax = (uint16_t)(flags_sbb(cpu, cpu->ax, cpu->ax, 16)); /* sbb ax, ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08378(cpu);                           /* call 0xFCAF */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_086C9_000110;                  /* jmp 0x0110 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08414(cpu);                           /* call 0xFD4B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(0x1);               /* mov di, 0x1 */
    goto L_fn_086C9_000110;                  /* jmp 0x0110 */
    cpu->si = (uint16_t)(0xFFFF);            /* mov si, 0xFFFF */
    cpu->di = (uint16_t)(0x1);               /* mov di, 0x1 */
    goto L_fn_086C9_000110;                  /* jmp 0x0110 */
L_fn_086C9_000110:;
    goto L_fn_086C9_000112;                  /* jmp 0x0112 */
L_fn_086C9_000112:;
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    if (cc_ne(cpu)) goto L_fn_086C9_000119;  /* jne 0x0119 */
    RECOMP_TICK(cpu);
    goto L_fn_086C9_000043;                  /* jmp 0x0043 */
L_fn_086C9_000119:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08453(cpu);                           /* call 0xFD8A */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x0); /* cmp word ss:[bp+-0x4], 0x0 */
    if (cc_e(cpu)) goto L_fn_086C9_000125;   /* je 0x0125 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0791E(cpu);                           /* call 0xF255 */
L_fn_086C9_000125:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5A6(cpu);                           /* call 0x4EDD */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07162(cpu);                           /* call 0xEA99 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6)), 0x0); /* cmp word ss:[bp+-0x6], 0x0 */
    if (cc_ne(cpu)) goto L_fn_086C9_000134;  /* jne 0x0134 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06997(cpu);                           /* call 0xE2CE */
L_fn_086C9_000134:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xE49D */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    goto L_fn_086C9_00013B;                  /* jmp 0x013B */
L_fn_086C9_00013B:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0880A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0880A");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x1E)); /* sub sp, 0x1E */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(0x1)); /* mov word ss:[bp+-0x6], 0x1 */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B74(cpu);                           /* call 0xE36A */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xA], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06990(cpu);                           /* call 0xE186 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xE35C */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0703E(cpu);                           /* call 0xE834 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D593(cpu);                           /* call 0x4D89 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0792C(cpu);                           /* call 0xF122 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07925(cpu);                           /* call 0xF11B */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->es, cpu->bx); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1A), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x1A], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1C), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x1C], bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4))); /* mov al, byte es:[bx+0x4] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x18], al */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xA))); /* mov ax, word es:[bx+0xA] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x12], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC))); /* mov ax, word es:[bx+0xC] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x10], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xE))); /* mov ax, word es:[bx+0xE] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xE], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x10))); /* mov ax, word es:[bx+0x10] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    goto L_fn_0880A_0001E7;                  /* jmp 0x01E7 */
L_fn_0880A_00006D:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_ne(cpu)) goto L_fn_0880A_000081;  /* jne 0x0081 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1E), (uint16_t)(0x4)); /* mov word ss:[bp+-0x1E], 0x4 */
    cpu->al = (uint8_t)(0x0);                /* mov al, 0x0 */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x13), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x13], al */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    goto L_fn_0880A_0000A3;                  /* jmp 0x00A3 */
L_fn_0880A_000081:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x9))); /* mov al, byte es:[bx+0x9] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    flags_cmp16(cpu, cpu->ax, cpu->si);      /* cmp ax, si */
    if (cc_le(cpu)) goto L_fn_0880A_000095;  /* jle 0x0095 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1E), (uint16_t)(0x5)); /* mov word ss:[bp+-0x1E], 0x5 */
    goto L_fn_0880A_00009A;                  /* jmp 0x009A */
L_fn_0880A_000095:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1E), (uint16_t)(0x6)); /* mov word ss:[bp+-0x1E], 0x6 */
L_fn_0880A_00009A:;
    cpu->al = (uint8_t)(0x1);                /* mov al, 0x1 */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x13), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x13], al */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
L_fn_0880A_0000A3:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x5)); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)((uint16_t)(cpu->bx + 0x5) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx+0x5] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { uint16_t _o = mem_read16(cpu, cpu->es, cpu->bx); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x15), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x15], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x17), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x17], bx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x1E)); /* lea ax, word ss:[bp+-0x1E] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08480(cpu);                           /* call 0xFC76 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(0x0)); /* mov word ss:[bp+-0x6], 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x0)); /* mov word ss:[bp+-0x4], 0x0 */
    goto L_fn_0880A_0001A7;                  /* jmp 0x01A7 */
L_fn_0880A_0000D6:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B1A(cpu);                           /* call 0xE310 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    cpu->cx = (uint16_t)(0xA);               /* mov cx, 0xA */
    cpu->bx = (uint16_t)(0x88FF);            /* mov bx, 0x88FF */
L_fn_0880A_0000E5:;
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, SEG_0000, cpu->bx)); /* cmp ax, word cs:[bx] */
    if (cc_e(cpu)) goto L_fn_0880A_0000F1;   /* je 0x00F1 */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0880A_0000E5; /* loop 0x00E5 */
    goto L_fn_0880A_0001A7;                  /* jmp 0x01A7 */
L_fn_0880A_0000F1:;
    { uint16_t _t = mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x14)); /* jmp word cs:[bx+0x14] */
      switch (_t) {
        case 0x8927: goto L_fn_0880A_00011D;
        case 0x8941: goto L_fn_0880A_000137;
        case 0x894D: goto L_fn_0880A_000143;
        case 0x8957: goto L_fn_0880A_00014D;
        case 0x8961: goto L_fn_0880A_000157;
        case 0x897E: goto L_fn_0880A_000174;
        default: recomp_dispatch(cpu, SEG_0000, _t); return;
      } }
    { uint16_t _r = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si)) | cpu->ax; flags_logic16(cpu, _r); mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si), (uint16_t)(_r)); } /* or word ds:[bx+si], ax */
    { uint16_t _r = cpu->ax | 0x1B00; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, 0x1B00 */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di)), cpu->bh))); /* add byte ss:[bp+di], bh */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1)), cpu->cx))); /* add word ds:[bx+si+0x1], cx */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di + 0x1), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di + 0x1)), cpu->cx))); /* add word ss:[bp+di+0x1], cx */
    { int _cf = cf(cpu); cpu->bp = (uint16_t)(flags_sub16(cpu, cpu->bp, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec bp */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1)), cpu->dx))); /* add word ds:[bx+si+0x1], dx */
    push16(cpu, cpu->cx);                    /* push cx */
    mem_write16(cpu, cpu->ds, cpu->bx, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, cpu->bx), cpu->sp))); /* add word ds:[bx], sp */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di - 0x77), (uint16_t)(cpu->ax)); /* mov word ds:[bx+di+-0x77], ax */
    { int _cf = cf(cpu); cpu->bp = (uint16_t)(flags_sub16(cpu, cpu->bp, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec bp */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x77), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x77], dx */
    bcd_daa(cpu);                            /* daa */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di - 0x77), (uint16_t)(cpu->sp)); /* mov word ds:[bx+di+-0x77], sp */
    bcd_daa(cpu);                            /* daa */
    mem_write16(cpu, cpu->ds, cpu->bx, (uint16_t)(cpu->sp)); /* mov word ds:[bx], sp */
    mem_write16(cpu, cpu->ds, cpu->bx, (uint16_t)(cpu->sp)); /* mov word ds:[bx], sp */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x77), (uint16_t)(cpu->di)); /* mov word ss:[bp+-0x77], di */
L_fn_0880A_00011D:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_le(cpu)) goto L_fn_0880A_000134;  /* jle 0x0134 */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08378(cpu);                           /* call 0xFB6E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_sub16(cpu, 0, cpu->ax)); /* neg ax */
    cpu->ax = (uint16_t)(flags_sbb(cpu, cpu->ax, cpu->ax, 16)); /* sbb ax, ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08378(cpu);                           /* call 0xFB6E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0880A_000134:;
    goto L_fn_0880A_0001A7;                  /* jmp 0x01A7 */
L_fn_0880A_000137:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08414(cpu);                           /* call 0xFC0A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x1)); /* mov word ss:[bp+-0x4], 0x1 */
    goto L_fn_0880A_0001A7;                  /* jmp 0x01A7 */
L_fn_0880A_000143:;
    cpu->di = (uint16_t)(0xFFFF);            /* mov di, 0xFFFF */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x1)); /* mov word ss:[bp+-0x4], 0x1 */
    goto L_fn_0880A_0001A7;                  /* jmp 0x01A7 */
L_fn_0880A_00014D:;
    cpu->di = (uint16_t)(0x2);               /* mov di, 0x2 */
L_fn_0880A_000150:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x1)); /* mov word ss:[bp+-0x4], 0x1 */
    goto L_fn_0880A_0001A7;                  /* jmp 0x01A7 */
L_fn_0880A_000157:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_le(cpu)) goto L_fn_0880A_000172;  /* jle 0x0172 */
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    if (cc_le(cpu)) goto L_fn_0880A_000164;  /* jle 0x0164 */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08378(cpu);                           /* call 0xFB6E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0880A_000164:;
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08414(cpu);                           /* call 0xFC0A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x1)); /* mov word ss:[bp+-0x4], 0x1 */
L_fn_0880A_000172:;
    goto L_fn_0880A_0001A7;                  /* jmp 0x01A7 */
L_fn_0880A_000174:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_ne(cpu)) goto L_fn_0880A_000188;  /* jne 0x0188 */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08414(cpu);                           /* call 0xFC0A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x1)); /* mov word ss:[bp+-0x4], 0x1 */
    goto L_fn_0880A_0001A5;                  /* jmp 0x01A5 */
L_fn_0880A_000188:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x9))); /* mov al, byte es:[bx+0x9] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    flags_cmp16(cpu, cpu->ax, cpu->si);      /* cmp ax, si */
    if (cc_le(cpu)) goto L_fn_0880A_0001A5;  /* jle 0x01A5 */
    cpu->di = (uint16_t)(0x1);               /* mov di, 0x1 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08414(cpu);                           /* call 0xFC0A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x1)); /* mov word ss:[bp+-0x4], 0x1 */
L_fn_0880A_0001A5:;
    goto L_fn_0880A_0001A7;                  /* jmp 0x01A7 */
L_fn_0880A_0001A7:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x0); /* cmp word ss:[bp+-0x4], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0880A_0001B0;  /* jne 0x01B0 */
    RECOMP_TICK(cpu);
    goto L_fn_0880A_0000D6;                  /* jmp 0x00D6 */
L_fn_0880A_0001B0:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    flags_cmp16(cpu, cpu->ax, 0x3);          /* cmp ax, 0x3 */
    if (cc_a(cpu)) goto L_fn_0880A_0001E7;   /* ja 0x01E7 */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx - 0x7635))); return; /* jmp word cs:[bx+-0x7635] */
    { uint16_t _v = (uint16_t)mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di - 0x7628)); uint8_t _n = (cpu->cl) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v >> _c) | (_v << (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (((_r >> (16 - 1)) & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ (_r >> (16 - 2))) & 1) ? FLAG_OF : 0); mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di - 0x7628), (uint16_t)(_r)); } } /* ror word ds:[bx+di+-0x7628], cl */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0880A_000150; /* loop 0x0150 */
    cpu->ax = (uint16_t)(port_in16(cpu, 0x89)); /* in ax, 0x89 */
    cpu->si = (uint16_t)(0xFFFF);            /* mov si, 0xFFFF */
    goto L_fn_0880A_0001E7;                  /* jmp 0x01E7 */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_ne(cpu)) goto L_fn_0880A_0001D5;  /* jne 0x01D5 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    goto L_fn_0880A_0001D6;                  /* jmp 0x01D6 */
L_fn_0880A_0001D5:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
L_fn_0880A_0001D6:;
    goto L_fn_0880A_0001E7;                  /* jmp 0x01E7 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    goto L_fn_0880A_0001E7;                  /* jmp 0x01E7 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x9))); /* mov al, byte es:[bx+0x9] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    goto L_fn_0880A_0001E7;                  /* jmp 0x01E7 */
L_fn_0880A_0001E7:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_l(cpu)) goto L_fn_0880A_0001FA;   /* jl 0x01FA */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x9))); /* mov al, byte es:[bx+0x9] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    flags_cmp16(cpu, cpu->ax, cpu->si);      /* cmp ax, si */
    if (cc_le(cpu)) goto L_fn_0880A_0001FA;  /* jle 0x01FA */
    RECOMP_TICK(cpu);
    goto L_fn_0880A_00006D;                  /* jmp 0x006D */
L_fn_0880A_0001FA:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08453(cpu);                           /* call 0xFC49 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x0); /* cmp word ss:[bp+-0x8], 0x0 */
    if (cc_e(cpu)) goto L_fn_0880A_000206;   /* je 0x0206 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0791E(cpu);                           /* call 0xF114 */
L_fn_0880A_000206:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5A6(cpu);                           /* call 0x4D9C */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07162(cpu);                           /* call 0xE958 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)), 0x0); /* cmp word ss:[bp+-0xA], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0880A_000215;  /* jne 0x0215 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06997(cpu);                           /* call 0xE18D */
L_fn_0880A_000215:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xE35C */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_ge(cpu)) goto L_fn_0880A_000222;  /* jge 0x0222 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0880A_000227;                  /* jmp 0x0227 */
    goto L_fn_0880A_000227;                  /* jmp 0x0227 */
L_fn_0880A_000222:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_0880A_000227;                  /* jmp 0x0227 */
L_fn_0880A_000227:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_08A37(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_08A37");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    mem_write16(cpu, cpu->ds, 0xC130, (uint16_t)(0x0)); /* mov word ds:[0xC130], 0x0 */
    mem_write8(cpu, cpu->ds, 0xC134, (uint8_t)(0x0)); /* mov byte ds:[0xC134], 0x0 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_08A37_00004F;                  /* jmp 0x004F */
L_fn_08A37_000011:;
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_08A37_000049;                  /* jmp 0x0049 */
L_fn_08A37_000015:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(0xFF)); /* mov byte es:[bx], 0xFF */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1), (uint8_t)(0x0)); /* mov byte es:[bx+0x1], 0x0 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_08A37_000049:;
    flags_cmp16(cpu, cpu->di, 0x6);          /* cmp di, 0x6 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_08A37_000015;   /* jl 0x0015 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_08A37_00004F:;
    flags_cmp16(cpu, cpu->si, 0x4);          /* cmp si, 0x4 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_08A37_000011;   /* jl 0x0011 */
    mem_write8(cpu, cpu->ds, 0xC132, (uint8_t)(0xFF)); /* mov byte ds:[0xC132], 0xFF */
    mem_write8(cpu, cpu->ds, 0xC133, (uint8_t)(0x0)); /* mov byte ds:[0xC133], 0x0 */
    mem_write8(cpu, cpu->ds, 0xC346, (uint8_t)(0x0)); /* mov byte ds:[0xC346], 0x0 */
    mem_write8(cpu, cpu->ds, 0xC135, (uint8_t)(0x0)); /* mov byte ds:[0xC135], 0x0 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_08AA2(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_08AA2");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x8)); /* sub sp, 0x8 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    cpu->di = (uint16_t)(0xFFFF);            /* mov di, 0xFFFF */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x0)); /* mov word ss:[bp+-0x2], 0x0 */
    goto L_fn_08AA2_0000E1;                  /* jmp 0x00E1 */
L_fn_08AA2_000015:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC130)); /* mov ax, word ds:[0xC130] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0xC130, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC130), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0xC130] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    flags_cmp16(cpu, cpu->ax, 0xC);          /* cmp ax, 0xC */
    if (cc_l(cpu)) goto L_fn_08AA2_00002A;   /* jl 0x002A */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_08AA2_0000FD;                  /* jmp 0x00FD */
L_fn_08AA2_00002A:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F90F(cpu);                           /* call 0x6E6D */
    cpu->bx = (uint16_t)(0xC);               /* mov bx, 0xC */
    cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)))); /* sub bx, word ss:[bp+-0x8] */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0034; recomp_div0("idiv16"); } } /* idiv bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x6], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x0)); /* mov word ss:[bp+-0x4], 0x0 */
    goto L_fn_08AA2_000072;                  /* jmp 0x0072 */
L_fn_08AA2_000040:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    flags_cmp16(cpu, cpu->ax, 0x3);          /* cmp ax, 0x3 */
    if (cc_ne(cpu)) goto L_fn_08AA2_000054;  /* jne 0x0054 */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    flags_cmp16(cpu, cpu->ax, 0x4);          /* cmp ax, 0x4 */
    if (cc_ne(cpu)) goto L_fn_08AA2_000054;  /* jne 0x0054 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
L_fn_08AA2_000054:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0xFF); /* cmp byte es:[bx], 0xFF */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_08AA2_000040;  /* jne 0x0040 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x4] */
L_fn_08AA2_000072:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* cmp ax, word ss:[bp+-0x6] */
    RECOMP_TICK(cpu);
    if (cc_le(cpu)) goto L_fn_08AA2_000040;  /* jle 0x0040 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov al, byte ss:[bp+-0x8] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ACE7(cpu);                           /* call 0x2245 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_08AA2_0000C4;   /* je 0x00C4 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F90F(cpu);                           /* call 0x6E6D */
    cpu->bx = (uint16_t)(0x4);               /* mov bx, 0x4 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x00A5; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->bx = (uint16_t)(0xC);               /* mov bx, 0xC */
    push16(cpu, cpu->dx);                    /* push dx */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->bx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul bx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1), (uint8_t)(cpu->al)); /* mov byte es:[bx+0x1], al */
    goto L_fn_08AA2_0000DE;                  /* jmp 0x00DE */
L_fn_08AA2_0000C4:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1), (uint8_t)(0x0)); /* mov byte es:[bx+0x1], 0x0 */
L_fn_08AA2_0000DE:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x2] */
L_fn_08AA2_0000E1:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x2); /* cmp word ss:[bp+-0x2], 0x2 */
    if (cc_ge(cpu)) goto L_fn_08AA2_0000EA;  /* jge 0x00EA */
    RECOMP_TICK(cpu);
    goto L_fn_08AA2_000015;                  /* jmp 0x0015 */
L_fn_08AA2_0000EA:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07202(cpu);                           /* call 0xE760 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC130), 0xC); /* cmp word ds:[0xC130], 0xC */
    if (cc_ne(cpu)) goto L_fn_08AA2_0000F9;  /* jne 0x00F9 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_08AA2_0000FB;                  /* jmp 0x00FB */
L_fn_08AA2_0000F9:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_08AA2_0000FB:;
    goto L_fn_08AA2_0000FD;                  /* jmp 0x00FD */
L_fn_08AA2_0000FD:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_08BA5(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_08BA5");
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC130)); /* mov ax, word ds:[0xC130] */
    goto L_fn_08BA5_000005;                  /* jmp 0x0005 */
L_fn_08BA5_000005:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_08BAB(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_08BAB");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x16)); /* sub sp, 0x16 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14), (uint16_t)(0x0)); /* mov word ss:[bp+-0x14], 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12), (uint16_t)(0x1)); /* mov word ss:[bp+-0x12], 0x1 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(0x1)); /* mov word ss:[bp+-0x10], 0x1 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x0)); /* mov word ss:[bp+-0x4], 0x0 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x237E)); /* mov ax, word ds:[0x237E] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0020F(cpu);                           /* call 0x7664 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xE], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CEA(cpu);                           /* call 0xE13F */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0792C(cpu);                           /* call 0xED81 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B74(cpu);                           /* call 0xDFC9 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xA], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06990(cpu);                           /* call 0xDDE5 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xDFBB */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EA5(cpu);                           /* call 0x92FA */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_090A6(cpu);                           /* call 0x04FB */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ACE7(cpu);                           /* call 0x213C */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_08BAB_00005A;   /* je 0x005A */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D4B3(cpu);                           /* call 0x4908 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_08BAB_000062;                  /* jmp 0x0062 */
L_fn_08BAB_00005A:;
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D4B3(cpu);                           /* call 0x4908 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_08BAB_000062:;
    goto L_fn_08BAB_0004BA;                  /* jmp 0x04BA */
L_fn_08BAB_000065:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC134), 0x0); /* cmp byte ds:[0xC134], 0x0 */
    if (cc_e(cpu)) goto L_fn_08BAB_0000BA;   /* je 0x00BA */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07925(cpu);                           /* call 0xED7A */
    goto L_fn_08BAB_0000A6;                  /* jmp 0x00A6 */
L_fn_08BAB_000071:;
    cpu->ax = (uint16_t)(0x76);              /* mov ax, 0x76 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C26(cpu);                           /* call 0xE07B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xDFBB */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B1A(cpu);                           /* call 0xDF6F */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x16], ax */
    flags_cmp16(cpu, cpu->ax, 0xD);          /* cmp ax, 0xD */
    if (cc_ne(cpu)) goto L_fn_08BAB_00009B;  /* jne 0x009B */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    flags_cmp16(cpu, cpu->ax, 0x2);          /* cmp ax, 0x2 */
    if (cc_ge(cpu)) goto L_fn_08BAB_000099;  /* jge 0x0099 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09440(cpu);                           /* call 0x0895 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_08BAB_000099:;
    goto L_fn_08BAB_0000A6;                  /* jmp 0x00A6 */
L_fn_08BAB_00009B:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16)), 0x1B); /* cmp word ss:[bp+-0x16], 0x1B */
    if (cc_ne(cpu)) goto L_fn_08BAB_0000A6;  /* jne 0x00A6 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x2)); /* mov word ss:[bp+-0x4], 0x2 */
L_fn_08BAB_0000A6:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x2); /* cmp word ss:[bp+-0x4], 0x2 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_08BAB_000071;   /* jl 0x0071 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x0); /* cmp word ss:[bp+-0x8], 0x0 */
    if (cc_e(cpu)) goto L_fn_08BAB_0000B5;   /* je 0x00B5 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0791E(cpu);                           /* call 0xED73 */
L_fn_08BAB_0000B5:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14), (uint16_t)(0x1)); /* mov word ss:[bp+-0x14], 0x1 */
L_fn_08BAB_0000BA:;
    goto L_fn_08BAB_000257;                  /* jmp 0x0257 */
L_fn_08BAB_0000BD:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09466(cpu);                           /* call 0x08BB */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0950C(cpu);                           /* call 0x0961 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0963E(cpu);                           /* call 0x0A93 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B1A(cpu);                           /* call 0xDF6F */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x16], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16))); /* mov ax, word ss:[bp+-0x16] */
    cpu->cx = (uint16_t)(0x6);               /* mov cx, 0x6 */
    cpu->bx = (uint16_t)(0x8CCF);            /* mov bx, 0x8CCF */
L_fn_08BAB_000114:;
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, SEG_0000, cpu->bx)); /* cmp ax, word cs:[bx] */
    if (cc_e(cpu)) goto L_fn_08BAB_000120;   /* je 0x0120 */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_08BAB_000114; /* loop 0x0114 */
    goto L_fn_08BAB_00020C;                  /* jmp 0x020C */
L_fn_08BAB_000120:;
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0xC))); return; /* jmp word cs:[bx+0xC] */
    { uint16_t _r = cpu->ax | 0x1B00; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, 0x1B00 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1)), cpu->cl))); /* add byte ds:[bx+si+0x1], cl */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec bx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x1), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x1)), cpu->cx))); /* add word ds:[di+0x1], cx */
    push16(cpu, cpu->ax);                    /* push ax */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di)), cpu->bp))); /* add word ds:[bx+di], bp */
    cpu->si = (uint16_t)((uint16_t)(cpu->bp + cpu->si - 0x1873)); /* lea si, word ss:[bp+si+-0x1873] */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si), (uint16_t)(SEG_0000)); /* mov word ds:[bx+si], cs */
    cpu->dx = (uint16_t)(0xF58D);            /* lea dx, word ds:[0xF58D] */
    cpu->si = (uint16_t)(cpu->ds);           /* mov si, ds */
    push16(cpu, SEG_0000);                   /* push cs */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->sp += 2; return;                    /* ret */
    if (cc_ge(cpu)) goto L_fn_08BAB_000147;  /* jge 0x0147 */
    mem_write8(cpu, cpu->ds, 0xC346, (uint8_t)(0x3)); /* mov byte ds:[0xC346], 0x3 */
L_fn_08BAB_000147:;
    goto L_fn_08BAB_00020C;                  /* jmp 0x020C */
    { int _cf = cf(cpu); mem_write8(cpu, cpu->ds, 0xC346, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, 0xC346), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc byte ds:[0xC346] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    flags_cmp8(cpu, cpu->al, 0x4);           /* cmp al, 0x4 */
    if (cc_l(cpu)) goto L_fn_08BAB_00015A;   /* jl 0x015A */
    mem_write8(cpu, cpu->ds, 0xC346, (uint8_t)(0x0)); /* mov byte ds:[0xC346], 0x0 */
L_fn_08BAB_00015A:;
    goto L_fn_08BAB_00020C;                  /* jmp 0x020C */
    { int _cf = cf(cpu); mem_write8(cpu, cpu->ds, 0xC135, (uint8_t)(flags_sub8(cpu, mem_read8(cpu, cpu->ds, 0xC135), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec byte ds:[0xC135] */
    if (cc_ge(cpu)) goto L_fn_08BAB_000168;  /* jge 0x0168 */
    mem_write8(cpu, cpu->ds, 0xC135, (uint8_t)(0x5)); /* mov byte ds:[0xC135], 0x5 */
L_fn_08BAB_000168:;
    goto L_fn_08BAB_00020C;                  /* jmp 0x020C */
    { int _cf = cf(cpu); mem_write8(cpu, cpu->ds, 0xC135, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, 0xC135), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc byte ds:[0xC135] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    flags_cmp8(cpu, cpu->al, 0x6);           /* cmp al, 0x6 */
    if (cc_l(cpu)) goto L_fn_08BAB_00017B;   /* jl 0x017B */
    mem_write8(cpu, cpu->ds, 0xC135, (uint8_t)(0x0)); /* mov byte ds:[0xC135], 0x0 */
L_fn_08BAB_00017B:;
    goto L_fn_08BAB_00020C;                  /* jmp 0x020C */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0xFF); /* cmp byte es:[bx], 0xFF */
    if (cc_ne(cpu)) goto L_fn_08BAB_0001A7;  /* jne 0x01A7 */
    cpu->ax = (uint16_t)(0x17);              /* mov ax, 0x17 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x3F46 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_08BAB_000205;                  /* jmp 0x0205 */
L_fn_08BAB_0001A7:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    mem_write16(cpu, cpu->ds, 0xC132, (uint16_t)(cpu->ax)); /* mov word ds:[0xC132], ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(0xFF)); /* mov byte es:[bx], 0xFF */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12), (uint16_t)(0x1)); /* mov word ss:[bp+-0x12], 0x1 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(0x1)); /* mov word ss:[bp+-0x10], 0x1 */
    cpu->ax = (uint16_t)(0x76);              /* mov ax, 0x76 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0xE0AC */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xE);               /* mov ax, 0xE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x3F46 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09402(cpu);                           /* call 0x0857 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_08BAB_000205:;
    goto L_fn_08BAB_00020C;                  /* jmp 0x020C */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CE2A(cpu);                           /* call 0x427F */
    goto L_fn_08BAB_00020C;                  /* jmp 0x020C */
L_fn_08BAB_00020C:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09466(cpu);                           /* call 0x08BB */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC132), 0xFF); /* cmp byte ds:[0xC132], 0xFF */
    if (cc_ne(cpu)) goto L_fn_08BAB_00022B;  /* jne 0x022B */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0963E(cpu);                           /* call 0x0A93 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_08BAB_000257;                  /* jmp 0x0257 */
L_fn_08BAB_00022B:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, mem_read16(cpu, cpu->es, cpu->bx)); /* push word es:[bx] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0929E(cpu);                           /* call 0x06F3 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_08BAB_000257:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC132), 0xFF); /* cmp byte ds:[0xC132], 0xFF */
    if (cc_ne(cpu)) goto L_fn_08BAB_000267;  /* jne 0x0267 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14)), 0x0); /* cmp word ss:[bp+-0x14], 0x0 */
    if (cc_ne(cpu)) goto L_fn_08BAB_000267;  /* jne 0x0267 */
    RECOMP_TICK(cpu);
    goto L_fn_08BAB_0000BD;                  /* jmp 0x00BD */
L_fn_08BAB_000267:;
    goto L_fn_08BAB_0004AA;                  /* jmp 0x04AA */
L_fn_08BAB_00026A:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12)), 0x0); /* cmp word ss:[bp+-0x12], 0x0 */
    if (cc_e(cpu)) goto L_fn_08BAB_0002DC;   /* je 0x02DC */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09466(cpu);                           /* call 0x08BB */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC132)); /* push word ds:[0xC132] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0929E(cpu);                           /* call 0x06F3 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09466(cpu);                           /* call 0x08BB */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* push word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0950C(cpu);                           /* call 0x0961 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0963E(cpu);                           /* call 0x0A93 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12), (uint16_t)(0x0)); /* mov word ss:[bp+-0x12], 0x0 */
L_fn_08BAB_0002DC:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C87(cpu);                           /* call 0xE0DC */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_08BAB_000334;   /* je 0x0334 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09466(cpu);                           /* call 0x08BB */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* mov ax, word ss:[bp+-0x10] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, 0, cpu->ax)); /* neg ax */
    cpu->ax = (uint16_t)(flags_sbb(cpu, cpu->ax, cpu->ax, 16)); /* sbb ax, ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x10], ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* push word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
L_fn_08BAB_000310:;
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0950C(cpu);                           /* call 0x0961 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0963E(cpu);                           /* call 0x0A93 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x76);              /* mov ax, 0x76 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0xE0AC */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_08BAB_000334:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B4A(cpu);                           /* call 0xDF9F */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_08BAB_00033E;  /* jne 0x033E */
    goto L_fn_08BAB_0004AA;                  /* jmp 0x04AA */
L_fn_08BAB_00033E:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B1A(cpu);                           /* call 0xDF6F */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x16], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16))); /* mov ax, word ss:[bp+-0x16] */
    cpu->cx = (uint16_t)(0x8);               /* mov cx, 0x8 */
    cpu->bx = (uint16_t)(0x8F14);            /* mov bx, 0x8F14 */
L_fn_08BAB_000359:;
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, SEG_0000, cpu->bx)); /* cmp ax, word cs:[bx] */
    if (cc_e(cpu)) goto L_fn_08BAB_000365;   /* je 0x0365 */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_08BAB_000359; /* loop 0x0359 */
    goto L_fn_08BAB_000449;                  /* jmp 0x0449 */
L_fn_08BAB_000365:;
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x10))); return; /* jmp word cs:[bx+0x10] */
    { uint16_t _r = cpu->ax | 0x1B00; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, 0x1B00 */
    mem_write8(cpu, cpu->ss, cpu->bp, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ss, cpu->bp), cpu->al))); /* add byte ss:[bp], al */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si + 0x1)), cpu->cl))); /* add byte ds:[bx+si+0x1], cl */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec bx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x1), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x1)), cpu->cx))); /* add word ds:[di+0x1], cx */
    push16(cpu, cpu->ax);                    /* push ax */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x1071), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x1071)), cpu->cx))); /* add word ds:[bx+-0x1071], cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x71), (uint16_t)(pop16(cpu))); /* pop word ss:[bp+-0x71] */
    RECOMP_TICK(cpu);
    if (cc_be(cpu)) goto L_fn_08BAB_000310;  /* jbe 0x0310 */
    { uint8_t _r = cpu->al ^ 0x8F; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* xor al, 0x8F */
    push16(cpu, cpu->bp);                    /* push bp */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di - 0x71), (uint16_t)(pop16(cpu))); /* pop word ss:[bp+di+-0x71] */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc dx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    push16(cpu, SEG_0000);                   /* push cs */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->sp += 2; return;                    /* ret */
    if (cc_ge(cpu)) goto L_fn_08BAB_000394;  /* jge 0x0394 */
    mem_write8(cpu, cpu->ds, 0xC346, (uint8_t)(0x3)); /* mov byte ds:[0xC346], 0x3 */
L_fn_08BAB_000394:;
    goto L_fn_08BAB_000449;                  /* jmp 0x0449 */
    { int _cf = cf(cpu); mem_write8(cpu, cpu->ds, 0xC346, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, 0xC346), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc byte ds:[0xC346] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    flags_cmp8(cpu, cpu->al, 0x4);           /* cmp al, 0x4 */
    if (cc_l(cpu)) goto L_fn_08BAB_0003A7;   /* jl 0x03A7 */
    mem_write8(cpu, cpu->ds, 0xC346, (uint8_t)(0x0)); /* mov byte ds:[0xC346], 0x0 */
L_fn_08BAB_0003A7:;
    goto L_fn_08BAB_000449;                  /* jmp 0x0449 */
    { int _cf = cf(cpu); mem_write8(cpu, cpu->ds, 0xC135, (uint8_t)(flags_sub8(cpu, mem_read8(cpu, cpu->ds, 0xC135), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec byte ds:[0xC135] */
    if (cc_ge(cpu)) goto L_fn_08BAB_0003B5;  /* jge 0x03B5 */
    mem_write8(cpu, cpu->ds, 0xC135, (uint8_t)(0x5)); /* mov byte ds:[0xC135], 0x5 */
L_fn_08BAB_0003B5:;
    goto L_fn_08BAB_000449;                  /* jmp 0x0449 */
    { int _cf = cf(cpu); mem_write8(cpu, cpu->ds, 0xC135, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, 0xC135), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc byte ds:[0xC135] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    flags_cmp8(cpu, cpu->al, 0x6);           /* cmp al, 0x6 */
    if (cc_l(cpu)) goto L_fn_08BAB_0003C8;   /* jl 0x03C8 */
    mem_write8(cpu, cpu->ds, 0xC135, (uint8_t)(0x0)); /* mov byte ds:[0xC135], 0x0 */
L_fn_08BAB_0003C8:;
    goto L_fn_08BAB_000449;                  /* jmp 0x0449 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ACE7(cpu);                           /* call 0x213C */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_08BAB_0003E2;   /* je 0x03E2 */
    { int _cf = cf(cpu); mem_write8(cpu, cpu->ds, 0xC133, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, 0xC133), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc byte ds:[0xC133] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC133)); /* mov al, byte ds:[0xC133] */
    flags_cmp8(cpu, cpu->al, 0x3);           /* cmp al, 0x3 */
    if (cc_le(cpu)) goto L_fn_08BAB_0003E2;  /* jle 0x03E2 */
    mem_write8(cpu, cpu->ds, 0xC133, (uint8_t)(0x0)); /* mov byte ds:[0xC133], 0x0 */
L_fn_08BAB_0003E2:;
    goto L_fn_08BAB_000449;                  /* jmp 0x0449 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0xFF); /* cmp byte es:[bx], 0xFF */
    if (cc_e(cpu)) goto L_fn_08BAB_00040D;   /* je 0x040D */
    cpu->ax = (uint16_t)(0x17);              /* mov ax, 0x17 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x3F46 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_08BAB_000442;                  /* jmp 0x0442 */
L_fn_08BAB_00040D:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC132)); /* mov ax, word ds:[0xC132] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC346)); /* mov al, byte ds:[0xC346] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC135)); /* mov al, byte ds:[0xC135] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(cpu->ax)); /* mov word es:[bx], ax */
    mem_write8(cpu, cpu->ds, 0xC132, (uint8_t)(0xFF)); /* mov byte ds:[0xC132], 0xFF */
    cpu->ax = (uint16_t)(0x1A);              /* mov ax, 0x1A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x3F46 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09402(cpu);                           /* call 0x0857 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_08BAB_000442:;
    goto L_fn_08BAB_000449;                  /* jmp 0x0449 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CE2A(cpu);                           /* call 0x427F */
    goto L_fn_08BAB_000449;                  /* jmp 0x0449 */
L_fn_08BAB_000449:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC132), 0xFF); /* cmp byte ds:[0xC132], 0xFF */
    if (cc_e(cpu)) goto L_fn_08BAB_000468;   /* je 0x0468 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09466(cpu);                           /* call 0x08BB */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0963E(cpu);                           /* call 0x0A93 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_08BAB_0004A5;                  /* jmp 0x04A5 */
L_fn_08BAB_000468:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09466(cpu);                           /* call 0x08BB */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0963E(cpu);                           /* call 0x0A93 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0969D(cpu);                           /* call 0x0AF2 */
    mem_write8(cpu, cpu->ds, 0xC134, (uint8_t)(cpu->al)); /* mov byte ds:[0xC134], al */
    { uint8_t _r = cpu->al | cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, al */
    if (cc_e(cpu)) goto L_fn_08BAB_0004A5;   /* je 0x04A5 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xDFBB */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09440(cpu);                           /* call 0x0895 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_093AA(cpu);                           /* call 0x07FF */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0x3F9D */
    cpu->ax = (uint16_t)(0x1B);              /* mov ax, 0x1B */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x3F46 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_08BAB_0004A5:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12), (uint16_t)(0x1)); /* mov word ss:[bp+-0x12], 0x1 */
L_fn_08BAB_0004AA:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC132), 0xFF); /* cmp byte ds:[0xC132], 0xFF */
    if (cc_e(cpu)) goto L_fn_08BAB_0004BA;   /* je 0x04BA */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14)), 0x0); /* cmp word ss:[bp+-0x14], 0x0 */
    if (cc_ne(cpu)) goto L_fn_08BAB_0004BA;  /* jne 0x04BA */
    RECOMP_TICK(cpu);
    goto L_fn_08BAB_00026A;                  /* jmp 0x026A */
L_fn_08BAB_0004BA:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14)), 0x0); /* cmp word ss:[bp+-0x14], 0x0 */
    if (cc_ne(cpu)) goto L_fn_08BAB_0004C3;  /* jne 0x04C3 */
    RECOMP_TICK(cpu);
    goto L_fn_08BAB_000065;                  /* jmp 0x0065 */
L_fn_08BAB_0004C3:;
    cpu->ax = (uint16_t)(0x7);               /* mov ax, 0x7 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D4B3(cpu);                           /* call 0x4908 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09259(cpu);                           /* call 0x06AE */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* push word ss:[bp+-0xE] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x7623 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC))); /* push word ss:[bp+-0xC] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CA6(cpu);                           /* call 0xE0FB */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)), 0x0); /* cmp word ss:[bp+-0xA], 0x0 */
    if (cc_ne(cpu)) goto L_fn_08BAB_0004E5;  /* jne 0x04E5 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06997(cpu);                           /* call 0xDDEC */
L_fn_08BAB_0004E5:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B66(cpu);                           /* call 0xDFBB */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5F9(cpu);                           /* call 0x4A4E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC134)); /* mov al, byte ds:[0xC134] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    goto L_fn_08BAB_0004F5;                  /* jmp 0x04F5 */
L_fn_08BAB_0004F5:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_090A6(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_090A6");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EA5(cpu);                           /* call 0x8DFF */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xDC4);             /* mov ax, 0xDC4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EB4(cpu);                           /* call 0x8E0E */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ACE7(cpu);                           /* call 0x1C41 */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->ax)); /* add dx, ax */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 0x1069)); /* add dx, 0x1069 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0xD7A4 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x103F);            /* mov ax, 0x103F */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xD4C6 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x7323 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xCA);              /* mov ax, 0xCA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x130);             /* mov ax, 0x130 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x730E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EB4(cpu);                           /* call 0x8E0E */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EA5(cpu);                           /* call 0x8DFF */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->ax)); /* add dx, ax */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ACE7(cpu);                           /* call 0x1C41 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->ax)); /* add dx, ax */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 0x1041)); /* add dx, 0x1041 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xD4C6 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5C6); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5C6 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C8)); /* mov cx, word ds:[0xC5C8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C6)); /* mov bx, word ds:[0xC5C6] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0x158);             /* mov ax, 0x158 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x7323 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5C6); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5C6 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov ax, word es:[bx+0x2] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C8)); /* mov cx, word ds:[0xC5C8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C6)); /* mov bx, word ds:[0xC5C6] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0x2C);              /* mov ax, 0x2C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8C);              /* mov ax, 0x8C */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x7326 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x0)); /* mov word ss:[bp+-0x2], 0x0 */
    goto L_fn_090A6_00010D;                  /* jmp 0x010D */
L_fn_090A6_0000DA:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5C6); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5C6 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5C6] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4))); /* mov ax, word es:[bx+0x4] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C8)); /* mov cx, word ds:[0xC5C8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C6)); /* mov bx, word ds:[0xC5C6] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    cpu->dx = (uint16_t)(0xF0);              /* mov dx, 0xF0 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC136)); /* add ax, 0xC136 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F2DB(cpu);                           /* call 0x6235 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x2] */
L_fn_090A6_00010D:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x2); /* cmp word ss:[bp+-0x2], 0x2 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_090A6_0000DA;   /* jl 0x00DA */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xDC8);             /* mov ax, 0xDC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1040);            /* mov ax, 0x1040 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0xD7A4 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC134), 0x0); /* cmp byte ds:[0xC134], 0x0 */
    if (cc_e(cpu)) goto L_fn_090A6_000133;   /* je 0x0133 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09440(cpu);                           /* call 0x039A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_090A6_000146;                  /* jmp 0x0146 */
L_fn_090A6_000133:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC132), 0xFF); /* cmp byte ds:[0xC132], 0xFF */
    if (cc_e(cpu)) goto L_fn_090A6_00013F;   /* je 0x013F */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_090A6_000141;                  /* jmp 0x0141 */
L_fn_090A6_00013F:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_090A6_000141:;
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09402(cpu);                           /* call 0x035C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_090A6_000146:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_090A6_000175;                  /* jmp 0x0175 */
L_fn_090A6_00014A:;
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_090A6_00016F;                  /* jmp 0x016F */
L_fn_090A6_00014E:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, mem_read16(cpu, cpu->es, cpu->bx)); /* push word es:[bx] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0929E(cpu);                           /* call 0x01F8 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_090A6_00016F:;
    flags_cmp16(cpu, cpu->di, 0x6);          /* cmp di, 0x6 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_090A6_00014E;   /* jl 0x014E */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_090A6_000175:;
    flags_cmp16(cpu, cpu->si, 0x4);          /* cmp si, 0x4 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_090A6_00014A;   /* jl 0x014A */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_090A6_000184;                  /* jmp 0x0184 */
L_fn_090A6_00017E:;
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_093AA(cpu);                           /* call 0x0304 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_090A6_000184:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* cmp si, word ss:[bp+-0x4] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_090A6_00017E;   /* jl 0x017E */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC134), 0x0); /* cmp byte ds:[0xC134], 0x0 */
    if (cc_e(cpu)) goto L_fn_090A6_000197;   /* je 0x0197 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_093AA(cpu);                           /* call 0x0304 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_090A6_000197:;
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x130);             /* mov ax, 0x130 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x72F9 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_09259(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_09259");
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xDC8)); /* mov ax, word ds:[0xDC8] */
    { uint16_t _r = cpu->ax | mem_read16(cpu, cpu->ds, 0xDCA); flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, word ds:[0xDCA] */
    if (cc_e(cpu)) goto L_fn_09259_000022;   /* je 0x0022 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xDCA)); /* push word ds:[0xDCA] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xDC8)); /* push word ds:[0xDC8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F3F7(cpu);                           /* call 0x619E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0xDCA, (uint16_t)(0x0)); /* mov word ds:[0xDCA], 0x0 */
    mem_write16(cpu, cpu->ds, 0xDC8, (uint16_t)(0x0)); /* mov word ds:[0xDC8], 0x0 */
L_fn_09259_000022:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xDC4)); /* mov ax, word ds:[0xDC4] */
    { uint16_t _r = cpu->ax | mem_read16(cpu, cpu->ds, 0xDC6); flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, word ds:[0xDC6] */
    if (cc_e(cpu)) goto L_fn_09259_000044;   /* je 0x0044 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xDC6)); /* push word ds:[0xDC6] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xDC4)); /* push word ds:[0xDC4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F3F7(cpu);                           /* call 0x619E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0xDC6, (uint16_t)(0x0)); /* mov word ds:[0xDC6], 0x0 */
    mem_write16(cpu, cpu->ds, 0xDC4, (uint16_t)(0x0)); /* mov word ds:[0xDC4], 0x0 */
L_fn_09259_000044:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_0929E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0929E");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)), 0x3); /* cmp word ss:[bp+0x8], 0x3 */
    if (cc_ge(cpu)) goto L_fn_0929E_00002A;  /* jge 0x002A */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov ax, word ss:[bp+0x8] */
    cpu->dx = (uint16_t)(0x24);              /* mov dx, 0x24 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x1C)); /* add si, 0x1C */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    cpu->dx = (uint16_t)(0x1C);              /* mov dx, 0x1C */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x2B)); /* add di, 0x2B */
    goto L_fn_0929E_000046;                  /* jmp 0x0046 */
L_fn_0929E_00002A:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)), 0x3))); /* sub word ss:[bp+0x8], 0x3 */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov si, word ss:[bp+0x8] */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->si; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->si = (uint16_t)(_r); } } /* shl si, cl */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x8C)); /* add si, 0x8C */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    cpu->dx = (uint16_t)(0x18);              /* mov dx, 0x18 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x36)); /* add di, 0x36 */
L_fn_0929E_000046:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 0xFF); /* cmp byte ss:[bp+0x4], 0xFF */
    if (cc_ne(cpu)) goto L_fn_0929E_000066;  /* jne 0x0066 */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xBA)); /* add ax, 0xBA */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x7116 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    goto L_fn_0929E_000106;                  /* jmp 0x0106 */
L_fn_0929E_000066:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov al, byte ss:[bp+0x4] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->bx = (uint16_t)(0x3);               /* mov bx, 0x3 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x006E; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->dx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shl dx, cl */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x4], dx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov al, byte ss:[bp+0x4] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->bx = (uint16_t)(0x3);               /* mov bx, 0x3 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x007F; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->dx = (uint16_t)(0x18);              /* mov dx, 0x18 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x158)); /* add ax, 0x158 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x5))); /* mov al, byte ss:[bp+0x5] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    flags_cmp16(cpu, cpu->ax, 0x3);          /* cmp ax, 0x3 */
    if (cc_a(cpu)) goto L_fn_0929E_000106;   /* ja 0x0106 */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx - 0x6CC4))); return; /* jmp word cs:[bx+-0x6CC4] */
    { int _cf = cf(cpu); cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc sp */
    { uint16_t _t = cpu->ax; cpu->ax = (uint16_t)(cpu->bx); cpu->bx = (uint16_t)(_t); } /* xchg ax, bx */
    cpu->sp = (uint16_t)(pop16(cpu));        /* pop sp */
    { uint16_t _t = cpu->ax; cpu->ax = (uint16_t)(cpu->bx); cpu->bx = (uint16_t)(_t); } /* xchg ax, bx */
    if (cc_e(cpu)) { recomp_dispatch(cpu, 0x92D, 0x5); return; } /* tail-jcc 0x0092D5 */ /* je 0x0037 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di + 0x5657), (uint16_t)(cpu->ss)); /* mov word ss:[bp+di+0x5657], ss */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x7116 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    goto L_fn_0929E_000106;                  /* jmp 0x0106 */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03BA);                           /* call 0x711C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    goto L_fn_0929E_000106;                  /* jmp 0x0106 */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03BD);                           /* call 0x711F */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    goto L_fn_0929E_000106;                  /* jmp 0x0106 */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B7);                           /* call 0x7119 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    goto L_fn_0929E_000106;                  /* jmp 0x0106 */
L_fn_0929E_000106:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_093AA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_093AA");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xDC4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xDC4 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xDC4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xDC6)); /* mov cx, word ds:[0xDC6] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xDC4)); /* mov bx, word ds:[0xDC4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1B)); /* add ax, 0x1B */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x108);             /* mov ax, 0x108 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x7022 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1C);              /* mov ax, 0x1C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1B)); /* add ax, 0x1B */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x108);             /* mov ax, 0x108 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x6FF5 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_09402(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_09402");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 0x0); /* cmp word ss:[bp+0x4], 0x0 */
    if (cc_e(cpu)) goto L_fn_09402_000016;   /* je 0x0016 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ACE7(cpu);                           /* call 0x18E5 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_09402_000016;  /* jne 0x0016 */
    cpu->si = (uint16_t)(0x1);               /* mov si, 0x1 */
    goto L_fn_09402_000018;                  /* jmp 0x0018 */
L_fn_09402_000016:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
L_fn_09402_000018:;
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xDC8); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xDC8 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xDC8] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xDCA)); /* mov cx, word ds:[0xDCA] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xDC8)); /* mov bx, word ds:[0xDC8] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07856(cpu);                           /* call 0xE454 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_09440(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_09440");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xB);               /* mov ax, 0xB */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(0xF0);              /* mov dx, 0xF0 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC136)); /* add ax, 0xC136 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0778B(cpu);                           /* call 0xE34B */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_09466(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_09466");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)), 0x3); /* cmp word ss:[bp+0x6], 0x3 */
    if (cc_ge(cpu)) goto L_fn_09466_00002A;  /* jge 0x002A */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    cpu->dx = (uint16_t)(0x24);              /* mov dx, 0x24 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x1A)); /* add si, 0x1A */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(0x1C);              /* mov dx, 0x1C */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x29)); /* add di, 0x29 */
    goto L_fn_09466_000046;                  /* jmp 0x0046 */
L_fn_09466_00002A:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)), 0x3))); /* sub word ss:[bp+0x6], 0x3 */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov si, word ss:[bp+0x6] */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->si; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->si = (uint16_t)(_r); } } /* shl si, cl */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x8A)); /* add si, 0x8A */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(0x18);              /* mov dx, 0x18 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x34)); /* add di, 0x34 */
L_fn_09466_000046:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov ax, word ss:[bp+0x8] */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_09466_000054;   /* je 0x0054 */
    flags_cmp16(cpu, cpu->ax, 0x1);          /* cmp ax, 0x1 */
    if (cc_e(cpu)) goto L_fn_09466_000060;   /* je 0x0060 */
    goto L_fn_09466_00006C;                  /* jmp 0x006C */
L_fn_09466_000054:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x60)); /* mov word ss:[bp+-0x4], 0x60 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x158)); /* mov word ss:[bp+-0x2], 0x158 */
    goto L_fn_09466_00006C;                  /* jmp 0x006C */
L_fn_09466_000060:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x8C)); /* mov word ss:[bp+-0x4], 0x8C */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x158)); /* mov word ss:[bp+-0x2], 0x158 */
    goto L_fn_09466_00006C;                  /* jmp 0x006C */
L_fn_09466_00006C:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA)), 0x0); /* cmp word ss:[bp+0xA], 0x0 */
    if (cc_ne(cpu)) goto L_fn_09466_00008A;  /* jne 0x008A */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2A);              /* mov ax, 0x2A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x6F4E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    goto L_fn_09466_0000A0;                  /* jmp 0x00A0 */
L_fn_09466_00008A:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2A);              /* mov ax, 0x2A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x6F4E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
L_fn_09466_0000A0:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0950C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0950C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0xE)); /* sub sp, 0xE */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)), 0x3); /* cmp word ss:[bp+0x6], 0x3 */
    if (cc_ge(cpu)) goto L_fn_0950C_00002B;  /* jge 0x002B */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    cpu->dx = (uint16_t)(0x24);              /* mov dx, 0x24 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x1C)); /* add di, 0x1C */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(0x1C);              /* mov dx, 0x1C */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x2B)); /* add ax, 0x2B */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xE], ax */
    goto L_fn_0950C_000048;                  /* jmp 0x0048 */
L_fn_0950C_00002B:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)), 0x3))); /* sub word ss:[bp+0x6], 0x3 */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov di, word ss:[bp+0x6] */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->di; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, cl */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x8C)); /* add di, 0x8C */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(0x18);              /* mov dx, 0x18 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x36)); /* add ax, 0x36 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xE], ax */
L_fn_0950C_000048:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(0x20)); /* mov word ss:[bp+-0xC], 0x20 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(0x18)); /* mov word ss:[bp+-0xA], 0x18 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0020F(cpu);                           /* call 0x6D03 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)), 0x0); /* cmp word ss:[bp+0x8], 0x0 */
    if (cc_e(cpu)) goto L_fn_0950C_000063;   /* je 0x0063 */
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    goto L_fn_0950C_000065;                  /* jmp 0x0065 */
L_fn_0950C_000063:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_0950C_000065:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA)), 0x0); /* cmp word ss:[bp+0xA], 0x0 */
    if (cc_e(cpu)) goto L_fn_0950C_000073;   /* je 0x0073 */
    cpu->ax = (uint16_t)(0x5);               /* mov ax, 0x5 */
    goto L_fn_0950C_000075;                  /* jmp 0x0075 */
L_fn_0950C_000073:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_0950C_000075:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA)), 0x0); /* cmp word ss:[bp+0xA], 0x0 */
    if (cc_e(cpu)) goto L_fn_0950C_000083;   /* je 0x0083 */
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    goto L_fn_0950C_000085;                  /* jmp 0x0085 */
L_fn_0950C_000083:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_0950C_000085:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x2); /* cmp byte ds:[0xBFCD], 0x2 */
    if (cc_ne(cpu)) goto L_fn_0950C_000099;  /* jne 0x0099 */
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x6CC2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0950C_0000B1;                  /* jmp 0x00B1 */
L_fn_0950C_000099:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x3); /* cmp byte ds:[0xBFCD], 0x3 */
    if (cc_ne(cpu)) goto L_fn_0950C_0000A9;  /* jne 0x00A9 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x6CC2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0950C_0000B1;                  /* jmp 0x00B1 */
L_fn_0950C_0000A9:;
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x6CC2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0950C_0000B1:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0950C_0000D5;                  /* jmp 0x00D5 */
L_fn_0950C_0000B5:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC)), 0x2))); /* add word ss:[bp+-0xC], 0x2 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)), 0x2))); /* add word ss:[bp+-0xA], 0x2 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* push word ss:[bp+-0xA] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC))); /* push word ss:[bp+-0xC] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* mov ax, word ss:[bp+-0xE] */
    push16(cpu, cpu->ax);                    /* push ax */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00355(cpu);                           /* call 0x6E49 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0950C_0000D5:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* cmp si, word ss:[bp+-0x6] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0950C_0000B5;   /* jl 0x00B5 */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x6CC2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0950C_0000FE;                  /* jmp 0x00FE */
L_fn_0950C_0000E6:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* push word ss:[bp+-0xA] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* mov ax, word ss:[bp+-0xE] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC)))); /* add ax, word ss:[bp+-0xC] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->si)); /* add ax, si */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x6E99 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0950C_0000FE:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* cmp si, word ss:[bp+-0x4] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0950C_0000E6;   /* jl 0x00E6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0950C_000120;                  /* jmp 0x0120 */
L_fn_0950C_000107:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC))); /* push word ss:[bp+-0xC] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* mov ax, word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)))); /* add ax, word ss:[bp+-0xA] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->si)); /* add ax, si */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x5)); /* add ax, 0x5 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x6E96 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0950C_000120:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* cmp si, word ss:[bp+-0x2] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0950C_000107;   /* jl 0x0107 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x6CC2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0963E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0963E");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov si, word ss:[bp+0x6] */
    flags_cmp16(cpu, cpu->si, 0x3);          /* cmp si, 0x3 */
    if (cc_ge(cpu)) goto L_fn_0963E_00002C;  /* jge 0x002C */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x24);              /* mov dx, 0x24 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x1A)); /* add di, 0x1A */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(0x1C);              /* mov dx, 0x1C */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x29)); /* add ax, 0x29 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    goto L_fn_0963E_000047;                  /* jmp 0x0047 */
L_fn_0963E_00002C:;
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 0x3)); /* sub si, 0x3 */
    cpu->di = (uint16_t)(cpu->si);           /* mov di, si */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->di; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, cl */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x8A)); /* add di, 0x8A */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(0x18);              /* mov dx, 0x18 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x34)); /* add ax, 0x34 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
L_fn_0963E_000047:;
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2A);              /* mov ax, 0x2A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x6D61 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0969D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0969D");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x1)); /* mov word ss:[bp+-0x4], 0x1 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC31D)); /* mov al, byte ds:[0xC31D] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    flags_cmp16(cpu, cpu->ax, 0x3);          /* cmp ax, 0x3 */
    if (cc_be(cpu)) goto L_fn_0969D_000019;  /* jbe 0x0019 */
    goto L_fn_0969D_0001A4;                  /* jmp 0x01A4 */
L_fn_0969D_000019:;
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx - 0x6941))); return; /* jmp word cs:[bx+-0x6941] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x68DA), (uint16_t)(0x9785)); /* mov word ss:[bp+-0x68DA], 0x9785 */
    if (cpu->cx == 0) { recomp_dispatch(cpu, 0x1965, 0xE); return; } /* jcxz tail 0x01965E */ /* jcxz 0xFFC1 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x0)); /* mov word ss:[bp+-0x2], 0x0 */
    goto L_fn_0969D_000081;                  /* jmp 0x0081 */
L_fn_0969D_000033:;
    cpu->di = (uint16_t)(0x3);               /* mov di, 0x3 */
    goto L_fn_0969D_00007B;                  /* jmp 0x007B */
L_fn_0969D_000038:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* cmp ax, word ss:[bp+-0x2] */
    if (cc_ne(cpu)) goto L_fn_0969D_000072;  /* jne 0x0072 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1)), 0x0); /* cmp byte es:[bx+0x1], 0x0 */
    if (cc_e(cpu)) goto L_fn_0969D_000077;   /* je 0x0077 */
L_fn_0969D_000072:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x0)); /* mov word ss:[bp+-0x4], 0x0 */
L_fn_0969D_000077:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x2] */
L_fn_0969D_00007B:;
    flags_cmp16(cpu, cpu->di, 0x6);          /* cmp di, 0x6 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0969D_000038;   /* jl 0x0038 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0969D_000081:;
    flags_cmp16(cpu, cpu->si, 0x4);          /* cmp si, 0x4 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0969D_000033;   /* jl 0x0033 */
    goto L_fn_0969D_0001A4;                  /* jmp 0x01A4 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x0)); /* mov word ss:[bp+-0x2], 0x0 */
    goto L_fn_0969D_0000E0;                  /* jmp 0x00E0 */
L_fn_0969D_000092:;
    cpu->di = (uint16_t)(0x5);               /* mov di, 0x5 */
    goto L_fn_0969D_0000DA;                  /* jmp 0x00DA */
L_fn_0969D_000097:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* cmp ax, word ss:[bp+-0x2] */
    if (cc_ne(cpu)) goto L_fn_0969D_0000D1;  /* jne 0x00D1 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1)), 0x1); /* cmp byte es:[bx+0x1], 0x1 */
    if (cc_e(cpu)) goto L_fn_0969D_0000D6;   /* je 0x00D6 */
L_fn_0969D_0000D1:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x0)); /* mov word ss:[bp+-0x4], 0x0 */
L_fn_0969D_0000D6:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x2] */
L_fn_0969D_0000DA:;
    flags_cmp16(cpu, cpu->di, 0x3);          /* cmp di, 0x3 */
    RECOMP_TICK(cpu);
    if (cc_ge(cpu)) goto L_fn_0969D_000097;  /* jge 0x0097 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0969D_0000E0:;
    flags_cmp16(cpu, cpu->si, 0x4);          /* cmp si, 0x4 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0969D_000092;   /* jl 0x0092 */
    goto L_fn_0969D_0001A4;                  /* jmp 0x01A4 */
    cpu->si = (uint16_t)(0x3);               /* mov si, 0x3 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x0)); /* mov word ss:[bp+-0x2], 0x0 */
    goto L_fn_0969D_000140;                  /* jmp 0x0140 */
L_fn_0969D_0000F2:;
    cpu->di = (uint16_t)(0x5);               /* mov di, 0x5 */
    goto L_fn_0969D_00013A;                  /* jmp 0x013A */
L_fn_0969D_0000F7:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* cmp ax, word ss:[bp+-0x2] */
    if (cc_ne(cpu)) goto L_fn_0969D_000131;  /* jne 0x0131 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1)), 0x2); /* cmp byte es:[bx+0x1], 0x2 */
    if (cc_e(cpu)) goto L_fn_0969D_000136;   /* je 0x0136 */
L_fn_0969D_000131:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x0)); /* mov word ss:[bp+-0x4], 0x0 */
L_fn_0969D_000136:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x2] */
L_fn_0969D_00013A:;
    flags_cmp16(cpu, cpu->di, 0x3);          /* cmp di, 0x3 */
    RECOMP_TICK(cpu);
    if (cc_ge(cpu)) goto L_fn_0969D_0000F7;  /* jge 0x00F7 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
L_fn_0969D_000140:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    RECOMP_TICK(cpu);
    if (cc_ge(cpu)) goto L_fn_0969D_0000F2;  /* jge 0x00F2 */
    goto L_fn_0969D_0001A4;                  /* jmp 0x01A4 */
    cpu->si = (uint16_t)(0x3);               /* mov si, 0x3 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x0)); /* mov word ss:[bp+-0x2], 0x0 */
    goto L_fn_0969D_00019E;                  /* jmp 0x019E */
L_fn_0969D_000150:;
    cpu->di = (uint16_t)(0x3);               /* mov di, 0x3 */
    goto L_fn_0969D_000198;                  /* jmp 0x0198 */
L_fn_0969D_000155:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* cmp ax, word ss:[bp+-0x2] */
    if (cc_ne(cpu)) goto L_fn_0969D_00018F;  /* jne 0x018F */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC316)); /* add bx, 0xC316 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1)), 0x3); /* cmp byte es:[bx+0x1], 0x3 */
    if (cc_e(cpu)) goto L_fn_0969D_000194;   /* je 0x0194 */
L_fn_0969D_00018F:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x0)); /* mov word ss:[bp+-0x4], 0x0 */
L_fn_0969D_000194:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x2] */
L_fn_0969D_000198:;
    flags_cmp16(cpu, cpu->di, 0x6);          /* cmp di, 0x6 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0969D_000155;   /* jl 0x0155 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
L_fn_0969D_00019E:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    RECOMP_TICK(cpu);
    if (cc_ge(cpu)) goto L_fn_0969D_000150;  /* jge 0x0150 */
    goto L_fn_0969D_0001A4;                  /* jmp 0x01A4 */
L_fn_0969D_0001A4:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    goto L_fn_0969D_0001A9;                  /* jmp 0x01A9 */
L_fn_0969D_0001A9:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}
