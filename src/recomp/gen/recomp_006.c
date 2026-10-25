#include "recomp_all.h"

void fn_0D1C9(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D1C9");
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D0D1(cpu);                           /* call 0xFF08 */
    goto L_fn_0D1C9_00000C;                  /* jmp 0x000C */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CE2A(cpu);                           /* call 0xFC61 */
    goto L_fn_0D1C9_00000A;                  /* jmp 0x000A */
L_fn_0D1C9_00000A:;
    recomp_dispatch(cpu, 0x1D16, 0x4); return; /* tail-jmp 0x01D164 */ /* jmp 0xFF9B */
L_fn_0D1C9_00000C:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D1D8(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D1D8");
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(0x98);              /* mov si, 0x98 */
    goto L_fn_0D1D8_00005A;                  /* jmp 0x005A */
L_fn_0D1D8_000006:;
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xD);               /* mov ax, 0xD */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x31DC */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC)); /* add ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xD4)); /* add ax, 0xD4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x31DC */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x31C7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
L_fn_0D1D8_00005A:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    RECOMP_TICK(cpu);
    if (cc_g(cpu)) goto L_fn_0D1D8_000006;   /* jg 0x0006 */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xD4);              /* mov ax, 0xD4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x31DC */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x31C7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D26C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D26C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B74(cpu);                           /* call 0x9908 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D089(cpu);                           /* call 0xFE1D */
    cpu->ax = (uint16_t)(0x31);              /* mov ax, 0x31 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5F9(cpu);                           /* call 0x038D */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CE68(cpu);                           /* call 0xFBFC */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CF3C(cpu);                           /* call 0xFCD0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07DFC(cpu);                           /* call 0xAB90 */
    mem_write16(cpu, cpu->ds, 0x1776, (uint16_t)(0x1)); /* mov word ds:[0x1776], 0x1 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5A6(cpu);                           /* call 0x033A */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x3148 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x2F62 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x184);             /* mov ax, 0x184 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x313C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC), (uint8_t)(0x0)); /* mov byte es:[bx+0xC], 0x0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06990(cpu);                           /* call 0x9724 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC5B0), 0x4); /* cmp word ds:[0xC5B0], 0x4 */
    if (cc_e(cpu)) goto L_fn_0D26C_0000B1;   /* je 0x00B1 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x22D2);            /* mov ax, 0x22D2 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07695(cpu);                           /* call 0xA429 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0xC5BA, (uint16_t)(0x0)); /* mov word ds:[0xC5BA], 0x0 */
    goto L_fn_0D26C_0000A5;                  /* jmp 0x00A5 */
L_fn_0D26C_000092:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5BA)); /* mov bx, word ds:[0xC5BA] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3A4E)), 0x0); /* cmp word ds:[bx+-0x3A4E], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0D26C_0000A1;  /* jne 0x00A1 */
    goto L_fn_0D26C_0000AC;                  /* jmp 0x00AC */
L_fn_0D26C_0000A1:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0xC5BA, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC5BA), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0xC5BA] */
L_fn_0D26C_0000A5:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC5BA), 0x4); /* cmp word ds:[0xC5BA], 0x4 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0D26C_000092;   /* jl 0x0092 */
L_fn_0D26C_0000AC:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D15D(cpu);                           /* call 0xFEF1 */
    goto L_fn_0D26C_0000BD;                  /* jmp 0x00BD */
L_fn_0D26C_0000B1:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06FC3(cpu);                           /* call 0x9D57 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D1D8(cpu);                           /* call 0xFF6C */
    mem_write16(cpu, cpu->ds, 0xC5BA, (uint16_t)(0x4)); /* mov word ds:[0xC5BA], 0x4 */
L_fn_0D26C_0000BD:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07DF1(cpu);                           /* call 0xAB85 */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_ne(cpu)) goto L_fn_0D26C_0000C7;  /* jne 0x00C7 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06997(cpu);                           /* call 0x972B */
L_fn_0D26C_0000C7:;
    mem_write16(cpu, cpu->ds, 0x1776, (uint16_t)(0x0)); /* mov word ds:[0x1776], 0x0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C834(cpu);                           /* call 0xF5C8 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5BA)); /* mov ax, word ds:[0xC5BA] */
    goto L_fn_0D26C_0000D5;                  /* jmp 0x00D5 */
L_fn_0D26C_0000D5:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D344(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D344");
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->ax = (uint16_t)(0xFA80);            /* mov ax, 0xFA80 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E9B4(cpu);                           /* call 0x1670 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0xC5CC, (uint16_t)(cpu->dx)); /* mov word ds:[0xC5CC], dx */
    mem_write16(cpu, cpu->ds, 0xC5CA, (uint16_t)(cpu->ax)); /* mov word ds:[0xC5CA], ax */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5CC)); /* mov si, word ds:[0xC5CC] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->dx = (uint16_t)(cpu->si);           /* mov dx, si */
    cpu->ax = (uint16_t)(0xE);               /* mov ax, 0xE */
    mem_write16(cpu, cpu->ds, 0xC5CC, (uint16_t)(cpu->dx)); /* mov word ds:[0xC5CC], dx */
    mem_write16(cpu, cpu->ds, 0xC5CA, (uint16_t)(cpu->ax)); /* mov word ds:[0xC5CA], ax */
    cpu->dx = (uint16_t)(cpu->si);           /* mov dx, si */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc dx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0xC5C8, (uint16_t)(cpu->dx)); /* mov word ds:[0xC5C8], dx */
    mem_write16(cpu, cpu->ds, 0xC5C6, (uint16_t)(cpu->ax)); /* mov word ds:[0xC5C6], ax */
    cpu->dx = (uint16_t)(cpu->si);           /* mov dx, si */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 0x7D4)); /* add dx, 0x7D4 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0xC5C0, (uint16_t)(cpu->dx)); /* mov word ds:[0xC5C0], dx */
    mem_write16(cpu, cpu->ds, 0xC5BE, (uint16_t)(cpu->ax)); /* mov word ds:[0xC5BE], ax */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D386(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D386");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC4 + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[0xBFC4] */
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    { uint16_t _r = cpu->cx ^ cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* xor cx, cx */
    cpu->cl = (uint8_t)(cpu->al);            /* mov cl, al */
L_fn_0D386_00000F:;
    push16(cpu, cpu->cx);                    /* push cx */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->di = (uint16_t)(cpu->si);           /* mov di, si */
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    cpu->bl = (uint8_t)(cpu->al);            /* mov bl, al */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->cx = (uint16_t)(cpu->ax);           /* mov cx, ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->bx)); /* add si, bx */
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec al */
    if (cc_s(cpu)) goto L_fn_0D386_000049;   /* js 0x0049 */
    { int _cf = cf(cpu); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, cpu->di), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc byte ds:[di] */
L_fn_0D386_000023:;
    cpu->bl = (uint8_t)(cpu->al);            /* mov bl, al */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x72B2)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x72B2) + 2)); cpu->si = _o; cpu->es = _s; } /* les si, word ds:[bx+0x72B2] */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    { uint16_t _t = cpu->ch; cpu->ch = (uint8_t)(cpu->dl); cpu->dl = (uint8_t)(_t); } /* xchg ch, dl */
    push16(cpu, cpu->dx);                    /* push dx */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shl cx, 0x1 */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x3043 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->si = (uint16_t)(cpu->di);           /* mov si, di */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0xC)); /* add si, 0xC */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0D386_00000F; /* loop 0x000F */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
L_fn_0D386_000049:;
    mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(0x1)); /* mov byte ds:[di], 0x1 */
    cpu->si = (uint16_t)(cpu->di);           /* mov si, di */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x3)); /* add si, 0x3 */
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    RECOMP_TICK(cpu);
    goto L_fn_0D386_000023;                  /* jmp 0x0023 */
}

void fn_0D3DA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D3DA");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x4)); /* lea ax, word ss:[bp+-0x4] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x40);              /* mov ax, 0x40 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0x9470 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0D3DA_00004B;                  /* jmp 0x004B */
L_fn_0D3DA_00001B:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov cx, word ss:[bp+-0x2] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov bx, word ss:[bp+-0x4] */
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
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3A30), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x3A30], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3A32), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x3A32], ax */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0D3DA_00004B:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* cmp si, word ss:[bp+0x6] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0D3DA_00001B;   /* jl 0x001B */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x8] */
    mem_write16(cpu, cpu->ds, 0x22F2, (uint16_t)(cpu->es)); /* mov word ds:[0x22F2], es */
    mem_write16(cpu, cpu->ds, 0x22F0, (uint16_t)(cpu->bx)); /* mov word ds:[0x22F0], bx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov al, byte ss:[bp+0x6] */
    mem_write8(cpu, cpu->ds, 0x22F9, (uint8_t)(cpu->al)); /* mov byte ds:[0x22F9], al */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x22F0);            /* mov ax, 0x22F0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0880A(cpu);                           /* call 0xB430 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F3F7(cpu);                           /* call 0x201D */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    goto L_fn_0D3DA_00007C;                  /* jmp 0x007C */
L_fn_0D3DA_00007C:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D4B3(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D4B3");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    flags_cmp16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x11)), 0x0); /* cmp word es:[bx+0x11], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0D4B3_000020;  /* jne 0x0020 */
    goto L_fn_0D4B3_00009E;                  /* jmp 0x009E */
L_fn_0D4B3_000020:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    cpu->cl = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov cl, byte ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    flags_logic16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x13)) & cpu->ax); /* test word es:[bx+0x13], ax */
    if (cc_e(cpu)) goto L_fn_0D4B3_00009E;   /* je 0x009E */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    cpu->cl = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov cl, byte ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    { uint16_t _r = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x13)) ^ cpu->ax; flags_logic16(cpu, _r); mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x13), (uint16_t)(_r)); } /* xor word es:[bx+0x13], ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x4)); /* lea ax, word ss:[bp+-0x4] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x101D);            /* mov ax, 0x101D */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0x9397 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    mem_write16(cpu, cpu->ds, 0x235F, (uint16_t)(cpu->es)); /* mov word ds:[0x235F], es */
    mem_write16(cpu, cpu->ds, 0x235D, (uint16_t)(cpu->bx)); /* mov word ds:[0x235D], bx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x2356);            /* mov ax, 0x2356 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_086C9(cpu);                           /* call 0xB216 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x2210 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0D4B3_00009E:;
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D555(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D555");
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->ax = (uint16_t)(0x620);             /* mov ax, 0x620 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E9B4(cpu);                           /* call 0x145F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0xC5DC, (uint16_t)(cpu->dx)); /* mov word ds:[0xC5DC], dx */
    mem_write16(cpu, cpu->ds, 0xC5DA, (uint16_t)(cpu->ax)); /* mov word ds:[0xC5DA], ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC5DE);            /* mov ax, 0xC5DE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x41);              /* mov ax, 0x41 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0x92F5 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5E0)); /* mov ax, word ds:[0xC5E0] */
    mem_write16(cpu, cpu->ds, 0x1760, (uint16_t)(cpu->ax)); /* mov word ds:[0x1760], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5DE)); /* mov ax, word ds:[0xC5DE] */
    mem_write16(cpu, cpu->ds, 0x175E, (uint16_t)(cpu->ax)); /* mov word ds:[0x175E], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5DC)); /* mov ax, word ds:[0xC5DC] */
    mem_write16(cpu, cpu->ds, 0x1764, (uint16_t)(cpu->ax)); /* mov word ds:[0x1764], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5DA)); /* mov ax, word ds:[0xC5DA] */
    mem_write16(cpu, cpu->ds, 0x1762, (uint16_t)(cpu->ax)); /* mov word ds:[0x1762], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C77A(cpu);                           /* call 0xF225 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D593(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D593");
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0xF5B5 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x237C, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x237C), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x237C] */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C26(cpu);                           /* call 0x9693 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C877(cpu);                           /* call 0xF2E4 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D5A6(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D5A6");
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x237C, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x237C), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ds:[0x237C] */
    if (cc_ge(cpu)) goto L_fn_0D5A6_00000C;  /* jge 0x000C */
    mem_write16(cpu, cpu->ds, 0x237C, (uint16_t)(0x0)); /* mov word ds:[0x237C], 0x0 */
L_fn_0D5A6_00000C:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D5B3(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D5B3");
    mem_write16(cpu, cpu->ds, 0x237C, (uint16_t)(0x0)); /* mov word ds:[0x237C], 0x0 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D5BA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D5BA");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x237E)); /* mov ax, word ds:[0x237E] */
    flags_cmp16(cpu, cpu->ax, cpu->si);      /* cmp ax, si */
    if (cc_e(cpu)) goto L_fn_0D5BA_00003C;   /* je 0x003C */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x0); /* cmp word ds:[0x1778], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0D5BA_000026;  /* jne 0x0026 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5DC)); /* push word ds:[0xC5DC] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5DA)); /* push word ds:[0xC5DA] */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x92F0 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    goto L_fn_0D5BA_000038;                  /* jmp 0x0038 */
L_fn_0D5BA_000026:;
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5DC)); /* push word ds:[0xC5DC] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5DA)); /* push word ds:[0xC5DA] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x92F0 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_0D5BA_000038:;
    mem_write16(cpu, cpu->ds, 0x237E, (uint16_t)(cpu->si)); /* mov word ds:[0x237E], si */
L_fn_0D5BA_00003C:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D5F9(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D5F9");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5BA(cpu);                           /* call 0xFFC1 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C7CB(cpu);                           /* call 0xF1D2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D60C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D60C");
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x237E), 0x0); /* cmp word ds:[0x237E], 0x0 */
    if (cc_l(cpu)) goto L_fn_0D60C_00000E;   /* jl 0x000E */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C7CB(cpu);                           /* call 0xF1BF */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0D60C_00000E:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D61C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D61C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x190)); /* mov word ds:[0x96], 0x190 */
    cpu->bx = (uint16_t)(0x2380);            /* mov bx, 0x2380 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x21), (uint8_t)(0x10)); /* mov byte ds:[bx+0x21], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0xA3), (uint8_t)(0x10)); /* mov byte ds:[bx+0xA3], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x105), (uint8_t)(0x10)); /* mov byte ds:[bx+0x105], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x197), (uint8_t)(0x10)); /* mov byte ds:[bx+0x197], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x219), (uint8_t)(0x10)); /* mov byte ds:[bx+0x219], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x27B), (uint8_t)(0x10)); /* mov byte ds:[bx+0x27B], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x30D), (uint8_t)(0x10)); /* mov byte ds:[bx+0x30D], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38F), (uint8_t)(0x10)); /* mov byte ds:[bx+0x38F], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3F1), (uint8_t)(0x10)); /* mov byte ds:[bx+0x3F1], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x483), (uint8_t)(0x10)); /* mov byte ds:[bx+0x483], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x505), (uint8_t)(0x10)); /* mov byte ds:[bx+0x505], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x567), (uint8_t)(0x10)); /* mov byte ds:[bx+0x567], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x5F9), (uint8_t)(0x10)); /* mov byte ds:[bx+0x5F9], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x67B), (uint8_t)(0x10)); /* mov byte ds:[bx+0x67B], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x6DD), (uint8_t)(0x10)); /* mov byte ds:[bx+0x6DD], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x76F), (uint8_t)(0x10)); /* mov byte ds:[bx+0x76F], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x7F1), (uint8_t)(0x10)); /* mov byte ds:[bx+0x7F1], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x853), (uint8_t)(0x10)); /* mov byte ds:[bx+0x853], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x8E5), (uint8_t)(0x10)); /* mov byte ds:[bx+0x8E5], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x967), (uint8_t)(0x10)); /* mov byte ds:[bx+0x967], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x9C9), (uint8_t)(0x10)); /* mov byte ds:[bx+0x9C9], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0xA5B), (uint8_t)(0x10)); /* mov byte ds:[bx+0xA5B], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0xADD), (uint8_t)(0x10)); /* mov byte ds:[bx+0xADD], 0x10 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0xB3F), (uint8_t)(0x10)); /* mov byte ds:[bx+0xB3F], 0x10 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC0 + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[0xBFC0] */
    cpu->ch = (uint8_t)(flags_sub8(cpu, cpu->ch, cpu->ch)); /* sub ch, ch */
    cpu->cl = (uint8_t)(mem_read8(cpu, cpu->es, cpu->di)); /* mov cl, byte es:[di] */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_0D61C_000091:;
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->es);                    /* push es */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->es, cpu->di)); /* mov bx, word es:[di] */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->es, cpu->di)); /* mov cx, word es:[di] */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ch = (uint8_t)(flags_sub8(cpu, cpu->ch, cpu->ch)); /* sub ch, ch */
    cpu->si = (uint16_t)(cpu->cx);           /* mov si, cx */
    flags_logic16(cpu, cpu->ax & 0x3);       /* test ax, 0x3 */
    if (cc_e(cpu)) goto L_fn_0D61C_0000B0;   /* je 0x00B0 */
    if (cc_np(cpu)) goto L_fn_0D61C_0000B0;  /* jnp 0x00B0 */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(flags_sub8(cpu, mem_read8(cpu, cpu->es, cpu->di), 0x3))); /* sub byte es:[di], 0x3 */
    goto L_fn_0D61C_0000B3;                  /* jmp 0x00B3 */
L_fn_0D61C_0000B0:;
    { int _cf = cf(cpu); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->es, cpu->di), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc byte es:[di] */
L_fn_0D61C_0000B3:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->dx = (uint16_t)(0x176);             /* mov dx, 0x176 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x2380)); /* add ax, 0x2380 */
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, cpu->dx)); /* sub dx, dx */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ah = (uint8_t)(cpu->dl);            /* mov ah, dl */
    cpu->al = (uint8_t)(cpu->bh);            /* mov al, bh */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ah = (uint8_t)(cpu->dl);            /* mov ah, dl */
    cpu->al = (uint8_t)(cpu->bl);            /* mov al, bl */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x2DB0 */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    mem_write16(cpu, cpu->ss, cpu->bp, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, cpu->bp), 0xC))); /* add word ss:[bp], 0xC */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 0x82))); /* add word ss:[bp+0x4], 0x82 */
    flags_cmp16(cpu, cpu->si, 0x0);          /* cmp si, 0x0 */
    if (cc_le(cpu)) goto L_fn_0D61C_0000ED;  /* jle 0x00ED */
L_fn_0D61C_0000E3:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x2DAD */
    mem_write16(cpu, cpu->ss, cpu->bp, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, cpu->bp), 0x8))); /* add word ss:[bp], 0x8 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_0D61C_0000E3;  /* jne 0x00E3 */
L_fn_0D61C_0000ED:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 0x62))); /* add word ss:[bp+0x4], 0x62 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x2DB0 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0D61C_000091; /* loop 0x0091 */
    cpu->bx = (uint16_t)(0x2380);            /* mov bx, 0x2380 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x21), (uint8_t)(0xB)); /* mov byte ds:[bx+0x21], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0xA3), (uint8_t)(0xB)); /* mov byte ds:[bx+0xA3], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x105), (uint8_t)(0xB)); /* mov byte ds:[bx+0x105], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x197), (uint8_t)(0xB)); /* mov byte ds:[bx+0x197], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x219), (uint8_t)(0xB)); /* mov byte ds:[bx+0x219], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x27B), (uint8_t)(0xB)); /* mov byte ds:[bx+0x27B], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x30D), (uint8_t)(0xB)); /* mov byte ds:[bx+0x30D], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38F), (uint8_t)(0xB)); /* mov byte ds:[bx+0x38F], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3F1), (uint8_t)(0xB)); /* mov byte ds:[bx+0x3F1], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x483), (uint8_t)(0xB)); /* mov byte ds:[bx+0x483], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x505), (uint8_t)(0xB)); /* mov byte ds:[bx+0x505], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x567), (uint8_t)(0xB)); /* mov byte ds:[bx+0x567], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x5F9), (uint8_t)(0xB)); /* mov byte ds:[bx+0x5F9], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x67B), (uint8_t)(0xB)); /* mov byte ds:[bx+0x67B], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x6DD), (uint8_t)(0xB)); /* mov byte ds:[bx+0x6DD], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x76F), (uint8_t)(0xB)); /* mov byte ds:[bx+0x76F], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x7F1), (uint8_t)(0xB)); /* mov byte ds:[bx+0x7F1], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x853), (uint8_t)(0xB)); /* mov byte ds:[bx+0x853], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x8E5), (uint8_t)(0xB)); /* mov byte ds:[bx+0x8E5], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x967), (uint8_t)(0xB)); /* mov byte ds:[bx+0x967], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x9C9), (uint8_t)(0xB)); /* mov byte ds:[bx+0x9C9], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0xA5B), (uint8_t)(0xB)); /* mov byte ds:[bx+0xA5B], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0xADD), (uint8_t)(0xB)); /* mov byte ds:[bx+0xADD], 0xB */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0xB3F), (uint8_t)(0xB)); /* mov byte ds:[bx+0xB3F], 0xB */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x9F)); /* mov word ds:[0x96], 0x9F */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D79C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D79C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC0 + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[0xBFC0] */
    cpu->ch = (uint8_t)(flags_sub8(cpu, cpu->ch, cpu->ch)); /* sub ch, ch */
    cpu->cl = (uint8_t)(mem_read8(cpu, cpu->es, cpu->di)); /* mov cl, byte es:[di] */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_0D79C_000011:;
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->es);                    /* push es */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->es, cpu->di)); /* mov bx, word es:[di] */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->es, cpu->di)); /* mov cx, word es:[di] */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ch = (uint8_t)(flags_sub8(cpu, cpu->ch, cpu->ch)); /* sub ch, ch */
    cpu->si = (uint16_t)(cpu->cx);           /* mov si, cx */
    flags_logic16(cpu, cpu->ax & 0x3);       /* test ax, 0x3 */
    if (cc_e(cpu)) goto L_fn_0D79C_000030;   /* je 0x0030 */
    if (cc_np(cpu)) goto L_fn_0D79C_000030;  /* jnp 0x0030 */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(flags_sub8(cpu, mem_read8(cpu, cpu->es, cpu->di), 0x3))); /* sub byte es:[di], 0x3 */
    goto L_fn_0D79C_000033;                  /* jmp 0x0033 */
L_fn_0D79C_000030:;
    { int _cf = cf(cpu); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->es, cpu->di), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc byte es:[di] */
L_fn_0D79C_000033:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->dx = (uint16_t)(0x176);             /* mov dx, 0x176 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x2380)); /* add ax, 0x2380 */
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, cpu->dx)); /* sub dx, dx */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ah = (uint8_t)(cpu->dl);            /* mov ah, dl */
    cpu->al = (uint8_t)(cpu->bh);            /* mov al, bh */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(cpu->bl);            /* mov al, bl */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x2C30 */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    mem_write16(cpu, cpu->ss, cpu->bp, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, cpu->bp), 0xC))); /* add word ss:[bp], 0xC */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 0x82))); /* add word ss:[bp+0x4], 0x82 */
    flags_cmp16(cpu, cpu->si, 0x0);          /* cmp si, 0x0 */
    if (cc_le(cpu)) goto L_fn_0D79C_000068;  /* jle 0x0068 */
L_fn_0D79C_00005E:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x2C2D */
    mem_write16(cpu, cpu->ss, cpu->bp, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, cpu->bp), 0x8))); /* add word ss:[bp], 0x8 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_0D79C_00005E;  /* jne 0x005E */
L_fn_0D79C_000068:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 0x62))); /* add word ss:[bp+0x4], 0x62 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x2C30 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0D79C_000011; /* loop 0x0011 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D818(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D818");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(0x2F30);            /* mov di, 0x2F30 */
    mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(0x0)); /* mov byte ds:[di], 0x0 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D825(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D825");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(cpu->ds);           /* mov ax, ds */
    cpu->es = (uint16_t)(cpu->ax);           /* mov es, ax */
    cpu->di = (uint16_t)(0x2F30);            /* mov di, 0x2F30 */
    cpu->bl = (uint8_t)(mem_read8(cpu, cpu->ds, cpu->di)); /* mov bl, byte ds:[di] */
    { int _cf = cf(cpu); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, cpu->di), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc byte ds:[di] */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->al = (uint8_t)(cpu->bl);            /* mov al, bl */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, cpu->bl)); /* add al, bl */
    cpu->ah = (uint8_t)(flags_sub8(cpu, cpu->ah, cpu->ah)); /* sub ah, ah */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov al, byte ss:[bp+0x4] */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov bx, word ss:[bp+0xC] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 0x4)); /* sub ax, 0x4 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D85F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D85F");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(cpu->ds);           /* mov ax, ds */
    cpu->es = (uint16_t)(cpu->ax);           /* mov es, ax */
    cpu->si = (uint16_t)(0x2F30);            /* mov si, 0x2F30 */
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    cpu->cl = (uint8_t)(cpu->al);            /* mov cl, al */
    cpu->ch = (uint8_t)(flags_sub8(cpu, cpu->ch, cpu->ch)); /* sub ch, ch */
    if (cpu->cx == 0) goto L_fn_0D85F_000037; /* jcxz 0x0037 */
L_fn_0D85F_000013:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, cpu->si)); /* mov al, byte ds:[si] */
    flags_cmp8(cpu, cpu->al, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* cmp al, byte ss:[bp+0x4] */
    if (cc_e(cpu)) goto L_fn_0D85F_000021;   /* je 0x0021 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x5)); /* add si, 0x5 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0D85F_000013; /* loop 0x0013 */
    if (cpu->cx == 0) goto L_fn_0D85F_000037; /* jcxz 0x0037 */
L_fn_0D85F_000021:;
    cpu->di = (uint16_t)(cpu->si);           /* mov di, si */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x5)); /* add si, 0x5 */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec cx */
    cpu->ax = (uint16_t)(cpu->cx);           /* mov ax, cx */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, cpu->ax)); /* add cx, ax */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    cpu->di = (uint16_t)(0x2F30);            /* mov di, 0x2F30 */
    { int _cf = cf(cpu); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(flags_sub8(cpu, mem_read8(cpu, cpu->es, cpu->di), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec byte es:[di] */
L_fn_0D85F_000037:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D89A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D89A");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->bl = (uint8_t)(cpu->al);            /* mov bl, al */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    cpu->bh = (uint8_t)(cpu->al);            /* mov bh, al */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov ax, word ss:[bp+0x8] */
    cpu->dl = (uint8_t)(cpu->al);            /* mov dl, al */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    cpu->dh = (uint8_t)(cpu->al);            /* mov dh, al */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->bx)); /* add dx, bx */
    { int _cf = cf(cpu); cpu->dl = (uint8_t)(flags_sub8(cpu, cpu->dl, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dl */
    { int _cf = cf(cpu); cpu->dh = (uint8_t)(flags_sub8(cpu, cpu->dh, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dh */
    cpu->si = (uint16_t)(0x2F30);            /* mov si, 0x2F30 */
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    cpu->ch = (uint8_t)(flags_sub8(cpu, cpu->ch, cpu->ch)); /* sub ch, ch */
    cpu->cl = (uint8_t)(cpu->al);            /* mov cl, al */
    { uint16_t _r = cpu->cx | cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* or cx, cx */
    if (cc_e(cpu)) goto L_fn_0D89A_000050;   /* je 0x0050 */
L_fn_0D89A_00002C:;
    cpu->ah = (uint8_t)(flags_sub8(cpu, cpu->ah, cpu->ah)); /* sub ah, ah */
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    flags_cmp8(cpu, cpu->dl, cpu->al);       /* cmp dl, al */
    if (cc_b(cpu)) goto L_fn_0D89A_00004B;   /* jb 0x004B */
    flags_cmp8(cpu, cpu->dh, cpu->ah);       /* cmp dh, ah */
    if (cc_b(cpu)) goto L_fn_0D89A_00004B;   /* jb 0x004B */
    cpu->bp = (uint16_t)(cpu->ax);           /* mov bp, ax */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->bp)); /* add ax, bp */
    flags_cmp8(cpu, cpu->al, cpu->bl);       /* cmp al, bl */
    if (cc_be(cpu)) goto L_fn_0D89A_00004E;  /* jbe 0x004E */
    flags_cmp8(cpu, cpu->ah, cpu->bh);       /* cmp ah, bh */
    if (cc_be(cpu)) goto L_fn_0D89A_00004E;  /* jbe 0x004E */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    goto L_fn_0D89A_000052;                  /* jmp 0x0052 */
L_fn_0D89A_00004B:;
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x2)); /* add si, 0x2 */
L_fn_0D89A_00004E:;
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0D89A_00002C; /* loop 0x002C */
L_fn_0D89A_000050:;
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->ax)); /* sub ax, ax */
L_fn_0D89A_000052:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D8F0(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D8F0");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5DA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5DA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5DA] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x8)); /* add bx, 0x8 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC6AB);            /* mov ax, 0xC6AB */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F32A(cpu);                           /* call 0x1A3A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xCA62);            /* mov ax, 0xCA62 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5DC)); /* mov dx, word ds:[0xC5DC] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5DA)); /* mov ax, word ds:[0xC5DA] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x11)); /* add ax, 0x11 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0x1A58 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0D8F0_0000A1;                  /* jmp 0x00A1 */
L_fn_0D8F0_000045:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0xFF); /* cmp byte es:[bx], 0xFF */
    if (cc_e(cpu)) goto L_fn_0D8F0_00009D;   /* je 0x009D */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5DA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5DA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5DA] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->si)); /* add bx, si */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1A))); /* mov al, byte es:[bx+0x1A] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->dx = (uint16_t)(0x9);               /* mov dx, 0x9 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->dx = (uint16_t)(0x3F);              /* mov dx, 0x3F */
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, cpu->ax)); /* sub dx, ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->bx = (uint16_t)(0x38);              /* mov bx, 0x38 */
    push16(cpu, cpu->dx);                    /* push dx */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->bx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul bx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x3044)); /* add bx, 0x3044 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(cpu->ax)); /* mov word es:[bx], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->dx = (uint16_t)(0x38);              /* mov dx, 0x38 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(0x301A);            /* mov bx, 0x301A */
    cpu->cx = (uint16_t)(cpu->ds);           /* mov cx, ds */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DA66(cpu);                           /* call 0x0176 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si - 0x3955), (uint8_t)(0x1)); /* mov byte ds:[si+-0x3955], 0x1 */
L_fn_0D8F0_00009D:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x4] */
L_fn_0D8F0_0000A1:;
    flags_cmp16(cpu, cpu->si, 0x9);          /* cmp si, 0x9 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0D8F0_000045;   /* jl 0x0045 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D99B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D99B");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DDC7(cpu);                           /* call 0x042C */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DEFA(cpu);                           /* call 0x055F */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D9D9(cpu);                           /* call 0x003E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DA49(cpu);                           /* call 0x00AE */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0D99B_000027;                  /* jmp 0x0027 */
L_fn_0D99B_000021:;
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E52A(cpu);                           /* call 0x0B8F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0D99B_000027:;
    flags_cmp16(cpu, cpu->si, 0x9);          /* cmp si, 0x9 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0D99B_000021;   /* jl 0x0021 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DA20(cpu);                           /* call 0x0085 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D9E1(cpu);                           /* call 0x0046 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D9D9(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D9D9");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E420(cpu);                           /* call 0x0A47 */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D9E1(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D9E1");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 0x0); /* cmp word ss:[bp+0x4], 0x0 */
    if (cc_e(cpu)) goto L_fn_0D9E1_00000F;   /* je 0x000F */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    goto L_fn_0D9E1_000011;                  /* jmp 0x0011 */
L_fn_0D9E1_00000F:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_0D9E1_000011:;
    mem_write16(cpu, cpu->ds, 0xCA22, (uint16_t)(cpu->ax)); /* mov word ds:[0xCA22], ax */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0D9E1_00002A;                  /* jmp 0x002A */
L_fn_0D9E1_000018:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->si + 0x2FE4))); /* mov al, byte ds:[si+0x2FE4] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xE0)); /* add ax, 0xE0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xEEB7 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0D9E1_00002A:;
    flags_cmp16(cpu, cpu->si, 0x12);         /* cmp si, 0x12 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0D9E1_000018;   /* jl 0x0018 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xCA22)); /* push word ds:[0xCA22] */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xEEB7 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0DA20(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0DA20");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    flags_cmp16(cpu, cpu->si, 0xC);          /* cmp si, 0xC */
    if (cc_be(cpu)) goto L_fn_0DA20_00000F;  /* jbe 0x000F */
    cpu->si = (uint16_t)(0xC);               /* mov si, 0xC */
L_fn_0DA20_00000F:;
    flags_cmp16(cpu, cpu->si, 0x1);          /* cmp si, 0x1 */
    if (cc_ae(cpu)) goto L_fn_0DA20_000017;  /* jae 0x0017 */
    cpu->si = (uint16_t)(0x1);               /* mov si, 0x1 */
L_fn_0DA20_000017:;
    mem_write16(cpu, cpu->ds, 0xC6C1, (uint16_t)(cpu->si)); /* mov word ds:[0xC6C1], si */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC6C1)); /* mov ax, word ds:[0xC6C1] */
    cpu->dx = (uint16_t)(0x19);              /* mov dx, 0x19 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    mem_write16(cpu, cpu->ds, 0xCA6B, (uint16_t)(cpu->ax)); /* mov word ds:[0xCA6B], ax */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0DA49(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0DA49");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov al, byte ss:[bp+0x4] */
    mem_write8(cpu, cpu->ds, 0xC6AA, (uint8_t)(cpu->al)); /* mov byte ds:[0xC6AA], al */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov al, byte ss:[bp+0x6] */
    mem_write8(cpu, cpu->ds, 0xC6B5, (uint8_t)(cpu->al)); /* mov byte ds:[0xC6B5], al */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov al, byte ss:[bp+0x8] */
    mem_write8(cpu, cpu->ds, 0xC6B4, (uint8_t)(cpu->al)); /* mov byte ds:[0xC6B4], al */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E420(cpu);                           /* call 0x09D7 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E262(cpu);                           /* call 0x0819 */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0DA66(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0DA66");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x8)); /* sub sp, 0x8 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x6) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x6] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x34)); /* add bx, 0x34 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov si, word es:[bx] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x2))); /* add word ss:[bp+-0x4], 0x2 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov di, word es:[bx] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x6) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x6] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x1A)); /* add bx, 0x1A */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x6], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x8], bx */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x2FD2)); /* add bx, 0x2FD2 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E0C0(cpu);                           /* call 0x065A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x2FD2)); /* add bx, 0x2FD2 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E0C0(cpu);                           /* call 0x065A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0DAD7(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0DAD7");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)), 0x0); /* cmp word ss:[bp+0x6], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DAD7_00000F;   /* je 0x000F */
    cpu->ax = (uint16_t)(0x7F);              /* mov ax, 0x7F */
    goto L_fn_0DAD7_000011;                  /* jmp 0x0011 */
L_fn_0DAD7_00000F:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_0DAD7_000011:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+0x6], ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x2FD2)); /* add bx, 0x2FD2 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)), 0x7F); /* cmp word ss:[bp+0x6], 0x7F */
    if (cc_be(cpu)) goto L_fn_0DAD7_000031;  /* jbe 0x0031 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6), (uint16_t)(0x7F)); /* mov word ss:[bp+0x6], 0x7F */
L_fn_0DAD7_000031:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov al, byte ss:[bp+0x6] */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si - 0x35B0), (uint8_t)(cpu->al)); /* mov byte ds:[si+-0x35B0], al */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E1F2(cpu);                           /* call 0x071B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0DB17(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0DB17");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x2FD2)); /* add bx, 0x2FD2 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E1F2(cpu);                           /* call 0x06DB */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0DB35(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0DB35");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x2FD2)); /* add bx, 0x2FD2 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(0x3F);              /* mov ax, 0x3F */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->si + 0x2FE4))); /* mov al, byte ds:[si+0x2FE4] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x40)); /* add ax, 0x40 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xED63 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0DB60(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0DB60");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov si, word ss:[bp+0x6] */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov di, word ss:[bp+0x4] */
    flags_cmp16(cpu, cpu->di, 0x2);          /* cmp di, 0x2 */
    if (cc_be(cpu)) goto L_fn_0DB60_000013;  /* jbe 0x0013 */
    goto L_fn_0DB60_000163;                  /* jmp 0x0163 */
L_fn_0DB60_000013:;
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    if (cc_ne(cpu)) goto L_fn_0DB60_000081;  /* jne 0x0081 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6AB), 0x0); /* cmp byte ds:[0xC6AB], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DB60_000039;   /* je 0x0039 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E52A(cpu);                           /* call 0x09CA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xCA62)); /* mov al, byte ds:[0xCA62] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->si)); /* add ax, si */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E48A(cpu);                           /* call 0x092A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_0DB60_000039:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6AC), 0x0); /* cmp byte ds:[0xC6AC], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DB60_00005D;   /* je 0x005D */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E52A(cpu);                           /* call 0x09CA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xCA63)); /* mov al, byte ds:[0xCA63] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->si)); /* add ax, si */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E48A(cpu);                           /* call 0x092A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_0DB60_00005D:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6AD), 0x0); /* cmp byte ds:[0xC6AD], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DB60_000081;   /* je 0x0081 */
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E52A(cpu);                           /* call 0x09CA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xCA64)); /* mov al, byte ds:[0xCA64] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->si)); /* add ax, si */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E48A(cpu);                           /* call 0x092A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_0DB60_000081:;
    flags_cmp16(cpu, cpu->di, 0x1);          /* cmp di, 0x1 */
    if (cc_ne(cpu)) goto L_fn_0DB60_0000F2;  /* jne 0x00F2 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6AE), 0x0); /* cmp byte ds:[0xC6AE], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DB60_0000AA;   /* je 0x00AA */
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E52A(cpu);                           /* call 0x09CA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xCA65)); /* mov al, byte ds:[0xCA65] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->si)); /* add ax, si */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E48A(cpu);                           /* call 0x092A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_0DB60_0000AA:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6AF), 0x0); /* cmp byte ds:[0xC6AF], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DB60_0000CE;   /* je 0x00CE */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E52A(cpu);                           /* call 0x09CA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xCA66)); /* mov al, byte ds:[0xCA66] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->si)); /* add ax, si */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E48A(cpu);                           /* call 0x092A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_0DB60_0000CE:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6B0), 0x0); /* cmp byte ds:[0xC6B0], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DB60_0000F2;   /* je 0x00F2 */
    cpu->ax = (uint16_t)(0x5);               /* mov ax, 0x5 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E52A(cpu);                           /* call 0x09CA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xCA67)); /* mov al, byte ds:[0xCA67] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->si)); /* add ax, si */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x5);               /* mov ax, 0x5 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E48A(cpu);                           /* call 0x092A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_0DB60_0000F2:;
    flags_cmp16(cpu, cpu->di, 0x2);          /* cmp di, 0x2 */
    if (cc_ne(cpu)) goto L_fn_0DB60_000163;  /* jne 0x0163 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6B1), 0x0); /* cmp byte ds:[0xC6B1], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DB60_00011B;   /* je 0x011B */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E52A(cpu);                           /* call 0x09CA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xCA68)); /* mov al, byte ds:[0xCA68] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->si)); /* add ax, si */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E48A(cpu);                           /* call 0x092A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_0DB60_00011B:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6B2), 0x0); /* cmp byte ds:[0xC6B2], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DB60_00013F;   /* je 0x013F */
    cpu->ax = (uint16_t)(0x7);               /* mov ax, 0x7 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E52A(cpu);                           /* call 0x09CA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xCA69)); /* mov al, byte ds:[0xCA69] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->si)); /* add ax, si */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x7);               /* mov ax, 0x7 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E48A(cpu);                           /* call 0x092A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_0DB60_00013F:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6B3), 0x0); /* cmp byte ds:[0xC6B3], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DB60_000163;   /* je 0x0163 */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E52A(cpu);                           /* call 0x09CA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xCA6A)); /* mov al, byte ds:[0xCA6A] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->si)); /* add ax, si */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E48A(cpu);                           /* call 0x092A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_0DB60_000163:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0DCC7(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0DCC7");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    flags_cmp16(cpu, cpu->si, 0x2);          /* cmp si, 0x2 */
    if (cc_le(cpu)) goto L_fn_0DCC7_00000F;  /* jle 0x000F */
    goto L_fn_0DCC7_0000A8;                  /* jmp 0x00A8 */
L_fn_0DCC7_00000F:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_ne(cpu)) goto L_fn_0DCC7_000042;  /* jne 0x0042 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6AB), 0x0); /* cmp byte ds:[0xC6AB], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DCC7_000021;   /* je 0x0021 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DD72(cpu);                           /* call 0x00AB */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0DCC7_000021:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6AC), 0x0); /* cmp byte ds:[0xC6AC], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DCC7_000030;   /* je 0x0030 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DD72(cpu);                           /* call 0x00AB */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0DCC7_000030:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6AD), 0x0); /* cmp byte ds:[0xC6AD], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DCC7_00003F;   /* je 0x003F */
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DD72(cpu);                           /* call 0x00AB */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0DCC7_00003F:;
    goto L_fn_0DCC7_0000A8;                  /* jmp 0x00A8 */
L_fn_0DCC7_000042:;
    flags_cmp16(cpu, cpu->si, 0x1);          /* cmp si, 0x1 */
    if (cc_ne(cpu)) goto L_fn_0DCC7_000076;  /* jne 0x0076 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6AE), 0x0); /* cmp byte ds:[0xC6AE], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DCC7_000056;   /* je 0x0056 */
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DD72(cpu);                           /* call 0x00AB */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0DCC7_000056:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6AF), 0x0); /* cmp byte ds:[0xC6AF], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DCC7_000065;   /* je 0x0065 */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DD72(cpu);                           /* call 0x00AB */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0DCC7_000065:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6B0), 0x0); /* cmp byte ds:[0xC6B0], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DCC7_000074;   /* je 0x0074 */
    cpu->ax = (uint16_t)(0x5);               /* mov ax, 0x5 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DD72(cpu);                           /* call 0x00AB */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0DCC7_000074:;
    goto L_fn_0DCC7_0000A8;                  /* jmp 0x00A8 */
L_fn_0DCC7_000076:;
    flags_cmp16(cpu, cpu->si, 0x2);          /* cmp si, 0x2 */
    if (cc_ne(cpu)) goto L_fn_0DCC7_0000A8;  /* jne 0x00A8 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6B1), 0x0); /* cmp byte ds:[0xC6B1], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DCC7_00008A;   /* je 0x008A */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DD72(cpu);                           /* call 0x00AB */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0DCC7_00008A:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6B2), 0x0); /* cmp byte ds:[0xC6B2], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DCC7_000099;   /* je 0x0099 */
    cpu->ax = (uint16_t)(0x7);               /* mov ax, 0x7 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DD72(cpu);                           /* call 0x00AB */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0DCC7_000099:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6B3), 0x0); /* cmp byte ds:[0xC6B3], 0x0 */
    if (cc_e(cpu)) goto L_fn_0DCC7_0000A8;   /* je 0x00A8 */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DD72(cpu);                           /* call 0x00AB */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0DCC7_0000A8:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0DD72(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0DD72");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x7);               /* mov ax, 0x7 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x2FD2)); /* add bx, 0x2FD2 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E095(cpu);                           /* call 0x0323 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x7);               /* mov ax, 0x7 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x2FD2)); /* add bx, 0x2FD2 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E095(cpu);                           /* call 0x0323 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->si - 0x394A))); /* mov al, byte ds:[si+-0x394A] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E48A(cpu);                           /* call 0x0718 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0DDC7(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0DDC7");
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0DDC7_00000B;                  /* jmp 0x000B */
L_fn_0DDC7_000005:;
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si - 0x35B0), (uint8_t)(0x7F)); /* mov byte ds:[si+-0x35B0], 0x7F */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0DDC7_00000B:;
    flags_cmp16(cpu, cpu->si, 0x12);         /* cmp si, 0x12 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0DDC7_000005;   /* jl 0x0005 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0DDD9(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0DDD9");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0xC)); /* sub sp, 0xC */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    cpu->dx = (uint16_t)(0x64);              /* mov dx, 0x64 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(0x6);               /* mov dx, 0x6 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)))); /* add ax, word ss:[bp+-0x4] */
    cpu->dx = (uint16_t)(flags_adc(cpu, cpu->dx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 16)); /* adc dx, word ss:[bp+-0x2] */
    { uint16_t _r = cpu->cx ^ cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* xor cx, cx */
    cpu->bx = (uint16_t)(0xCB78);            /* mov bx, 0xCB78 */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F2A7(cpu);                           /* call 0000:F2A7 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0xA], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    { uint16_t _r = cpu->cx ^ cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* xor cx, cx */
    cpu->bx = (uint16_t)(0x19);              /* mov bx, 0x19 */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F2A7(cpu);                           /* call 0000:F2A7 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* push word ss:[bp+-0xA] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC))); /* push word ss:[bp+-0xC] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F817(cpu);                           /* call 0000:F817 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0xA], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* mov dx, word ss:[bp+-0xA] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC))); /* mov ax, word ss:[bp+-0xC] */
    cpu->cl = (uint8_t)(0xE);                /* mov cl, 0xE */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F8BA(cpu);                           /* call 0000:F8BA */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x6], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov dx, word ss:[bp+-0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    { uint16_t _r = cpu->cx ^ cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* xor cx, cx */
    cpu->bx = (uint16_t)(0x9);               /* mov bx, 0x9 */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F2A7(cpu);                           /* call 0000:F2A7 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x6], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    cpu->dx = (uint16_t)(0x1);               /* mov dx, 0x1 */
    cpu->ax = (uint16_t)(0xB503);            /* mov ax, 0xB503 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F817(cpu);                           /* call 0000:F817 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x6], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov dx, word ss:[bp+-0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    goto L_fn_0DDD9_0000A1;                  /* jmp 0x00A1 */
L_fn_0DDD9_0000A1:;
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0DE7E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0DE7E");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DDD9(cpu);                           /* call 0xFF5B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(cpu->ax)); /* mov word es:[bx], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 0x2))); /* add word ss:[bp+0x4], 0x2 */
    cpu->si = (uint16_t)(0x1);               /* mov si, 0x1 */
    goto L_fn_0DE7E_000072;                  /* jmp 0x0072 */
L_fn_0DE7E_000030:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    { uint16_t _r = cpu->cx ^ cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* xor cx, cx */
    cpu->bx = (uint16_t)(0x6A);              /* mov bx, 0x6A */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F2A7(cpu);                           /* call 0000:F2A7 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->ax = (uint16_t)(0x64);              /* mov ax, 0x64 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F817(cpu);                           /* call 0000:F817 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(cpu->ax)); /* mov word es:[bx], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 0x2))); /* add word ss:[bp+0x4], 0x2 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0DE7E_000072:;
    flags_cmp16(cpu, cpu->si, 0xC);          /* cmp si, 0xC */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0DE7E_000030;   /* jl 0x0030 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0DEFA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0DEFA");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x8)); /* sub sp, 0x8 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x4)); /* mov word ss:[bp+-0x2], 0x4 */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    goto L_fn_0DEFA_000036;                  /* jmp 0x0036 */
L_fn_0DEFA_000016:;
    cpu->ax = (uint16_t)(0x64);              /* mov ax, 0x64 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0x18);              /* mov dx, 0x18 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC6C3)); /* add ax, 0xC6C3 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DE7E(cpu);                           /* call 0xFF84 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), cpu->ax))); /* add word ss:[bp+-0x4], ax */
L_fn_0DEFA_000036:;
    flags_cmp16(cpu, cpu->di, 0x19);         /* cmp di, 0x19 */
    RECOMP_TICK(cpu);
    if (cc_b(cpu)) goto L_fn_0DEFA_000016;   /* jb 0x0016 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(0x0)); /* mov word ss:[bp+-0x8], 0x0 */
    goto L_fn_0DEFA_000061;                  /* jmp 0x0061 */
L_fn_0DEFA_000042:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov bx, word ss:[bp+-0x8] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x35DA), (uint16_t)(cpu->ds)); /* mov word ds:[bx+-0x35DA], ds */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x35DC), (uint16_t)(0xC6C3)); /* mov word ds:[bx+-0x35DC], 0xC6C3 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov bx, word ss:[bp+-0x8] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3593), (uint16_t)(0x0)); /* mov word ds:[bx+-0x3593], 0x0 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x8] */
L_fn_0DEFA_000061:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0xB); /* cmp word ss:[bp+-0x8], 0xB */
    RECOMP_TICK(cpu);
    if (cc_b(cpu)) goto L_fn_0DEFA_000042;   /* jb 0x0042 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(0x0)); /* mov word ss:[bp+-0x8], 0x0 */
    goto L_fn_0DEFA_000092;                  /* jmp 0x0092 */
L_fn_0DEFA_000070:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(0x0)); /* mov word ss:[bp+-0x6], 0x0 */
    goto L_fn_0DEFA_000089;                  /* jmp 0x0089 */
L_fn_0DEFA_000077:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov al, byte ss:[bp+-0x8] */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si - 0x3A16), (uint8_t)(cpu->al)); /* mov byte ds:[si+-0x3A16], al */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov al, byte ss:[bp+-0x6] */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si - 0x39B6), (uint8_t)(cpu->al)); /* mov byte ds:[si+-0x39B6], al */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x6] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0DEFA_000089:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6)), 0xC); /* cmp word ss:[bp+-0x6], 0xC */
    RECOMP_TICK(cpu);
    if (cc_b(cpu)) goto L_fn_0DEFA_000077;   /* jb 0x0077 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x8] */
L_fn_0DEFA_000092:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x8); /* cmp word ss:[bp+-0x8], 0x8 */
    RECOMP_TICK(cpu);
    if (cc_b(cpu)) goto L_fn_0DEFA_000070;   /* jb 0x0070 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0DF98(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0DF98");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x6)); /* sub sp, 0x6 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xE000)); /* add ax, 0xE000 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xCA6B)); /* mov ax, word ds:[0xCA6B] */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F2A7(cpu);                           /* call 0000:F2A7 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x3754)); /* mov dx, word ds:[0x3754] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x3752)); /* mov ax, word ds:[0x3752] */
    flags_cmp16(cpu, cpu->dx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* cmp dx, word ss:[bp+-0x2] */
    if (cc_ne(cpu)) goto L_fn_0DF98_000058;  /* jne 0x0058 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* cmp ax, word ss:[bp+-0x4] */
    if (cc_ne(cpu)) goto L_fn_0DF98_000058;  /* jne 0x0058 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5E8)); /* mov dx, word ds:[0xC5E8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5E6)); /* mov ax, word ds:[0xC5E6] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x35DA), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x35DA], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x35DC), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x35DC], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5E4)); /* mov ax, word ds:[0xC5E4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3593), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x3593], ax */
    goto L_fn_0DF98_0000F7;                  /* jmp 0x00F7 */
L_fn_0DF98_000058:;
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->ax = (uint16_t)(0x2000);            /* mov ax, 0x2000 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F817(cpu);                           /* call 0000:F817 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    if (cc_ge(cpu)) goto L_fn_0DF98_0000AA;  /* jge 0x00AA */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->di)); /* sub ax, di */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    cpu->bx = (uint16_t)(0x19);              /* mov bx, 0x19 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x007F; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->ax = (uint16_t)(flags_sub16(cpu, 0, cpu->ax)); /* neg ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3593), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x3593], ax */
    mem_write16(cpu, cpu->ds, 0xC5E4, (uint16_t)(cpu->ax)); /* mov word ds:[0xC5E4], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFE8)); /* add ax, 0xFFE8 */
    cpu->bx = (uint16_t)(0x19);              /* mov bx, 0x19 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0099; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->si = (uint16_t)(cpu->dx);           /* mov si, dx */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_e(cpu)) goto L_fn_0DF98_0000A8;   /* je 0x00A8 */
    cpu->ax = (uint16_t)(0x19);              /* mov ax, 0x19 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->si)); /* sub ax, si */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
L_fn_0DF98_0000A8:;
    goto L_fn_0DF98_0000C8;                  /* jmp 0x00C8 */
L_fn_0DF98_0000AA:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->bx = (uint16_t)(0x19);              /* mov bx, 0x19 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x00B0; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3593), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x3593], ax */
    mem_write16(cpu, cpu->ds, 0xC5E4, (uint16_t)(cpu->ax)); /* mov word ds:[0xC5E4], ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->bx = (uint16_t)(0x19);              /* mov bx, 0x19 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x00C4; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->si = (uint16_t)(cpu->dx);           /* mov si, dx */
L_fn_0DF98_0000C8:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x18);              /* mov dx, 0x18 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC6C3)); /* add ax, 0xC6C3 */
    cpu->dx = (uint16_t)(cpu->ds);           /* mov dx, ds */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x35DA), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x35DA], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x35DC), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x35DC], ax */
    mem_write16(cpu, cpu->ds, 0xC5E8, (uint16_t)(cpu->dx)); /* mov word ds:[0xC5E8], dx */
    mem_write16(cpu, cpu->ds, 0xC5E6, (uint16_t)(cpu->ax)); /* mov word ds:[0xC5E6], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->ds, 0x3754, (uint16_t)(cpu->dx)); /* mov word ds:[0x3754], dx */
    mem_write16(cpu, cpu->ds, 0x3752, (uint16_t)(cpu->ax)); /* mov word ds:[0x3752], ax */
L_fn_0DF98_0000F7:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E095(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E095");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov al, byte ss:[bp+0x8] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)))); /* add bx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E151(cpu);                           /* call 0x00BC */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E0C0(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E0C0");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    goto L_fn_0E0C0_000035;                  /* jmp 0x0035 */
L_fn_0E0C0_000021:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x6) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x6] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)), 0x2))); /* add word ss:[bp+0x6], 0x2 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x4] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0E0C0_000035:;
    flags_cmp16(cpu, cpu->si, 0xD);          /* cmp si, 0xD */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0E0C0_000021;   /* jl 0x0021 */
    { uint16_t _r = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA)) & 0x3; flags_logic16(cpu, _r); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA), (uint16_t)(_r)); } /* and word ss:[bp+0xA], 0x3 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E1C4(cpu);                           /* call 0x0104 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E114(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E114");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x1C)); /* sub sp, 0x1C */
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0E114_000022;                  /* jmp 0x0022 */
L_fn_0E114_00000B:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x6) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x6] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->dx = (uint16_t)((uint16_t)(cpu->bp - 0x1C)); /* lea dx, word ss:[bp+-0x1C] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->dx)); /* add bx, dx */
    mem_write16(cpu, cpu->ss, cpu->bx, (uint16_t)(cpu->ax)); /* mov word ss:[bx], ax */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+0x6] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0E114_000022:;
    flags_cmp16(cpu, cpu->si, 0xD);          /* cmp si, 0xD */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0E114_00000B;   /* jl 0x000B */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x1C)); /* lea ax, word ss:[bp+-0x1C] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E0C0(cpu);                           /* call 0xFFAC */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E151(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E151");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    flags_cmp16(cpu, cpu->ax, 0x11);         /* cmp ax, 0x11 */
    if (cc_a(cpu)) goto L_fn_0E151_000070;   /* ja 0x0070 */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx - 0x1E97))); return; /* jmp word cs:[bx+-0x1E97] */
    { uint16_t _t = cpu->ax; cpu->ax = (uint16_t)(cpu->di); cpu->di = (uint16_t)(_t); } /* xchg ax, di */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E11, 0xF); return; } /* loopz tail 0x01E11F */ /* loopz 0xFFCE */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E10, 0xC); return; } /* loopz tail 0x01E10C */ /* loopz 0xFFBB */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E11, 0x5); return; } /* loopz tail 0x01E115 */ /* loopz 0xFFC4 */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E11, 0xE); return; } /* loopz tail 0x01E11E */ /* loopz 0xFFCD */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E12, 0x7); return; } /* loopz tail 0x01E127 */ /* loopz 0xFFD6 */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E11, 0xB); return; } /* loopz tail 0x01E11B */ /* loopz 0xFFCA */
L_fn_0E151_000025:;
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E12, 0x4); return; } /* loopz tail 0x01E124 */ /* loopz 0xFFD3 */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E11, 0x1); return; } /* loopz tail 0x01E111 */ /* loopz 0xFFC0 */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E12, 0xF); return; } /* loopz tail 0x01E12F */ /* loopz 0xFFDE */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E13, 0x1); return; } /* loopz tail 0x01E131 */ /* loopz 0xFFE0 */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E13, 0x3); return; } /* loopz tail 0x01E133 */ /* loopz 0xFFE2 */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E12, 0x0); return; } /* loopz tail 0x01E120 */ /* loopz 0xFFCF */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E13, 0xE); return; } /* loopz tail 0x01E13E */ /* loopz 0xFFED */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E11, 0x3); return; } /* loopz tail 0x01E113 */ /* loopz 0xFFC2 */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E11, 0x5); return; } /* loopz tail 0x01E115 */ /* loopz 0xFFC4 */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E11, 0xC); return; } /* loopz tail 0x01E11C */ /* loopz 0xFFCB */
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) { recomp_dispatch(cpu, 0x1E11, 0x9); return; } /* loopz tail 0x01E119 */ /* loopz 0xFFC8 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0 && zf(cpu)) goto L_fn_0E151_000025; /* loopz 0x0025 */
    /* nop */                                /* nop */
    cpu->ch = (uint8_t)(flags_add8(cpu, cpu->ch, cpu->bl)); /* add ch, bl */
    bcd_das(cpu);                            /* das */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E262(cpu);                           /* call 0x0111 */
    goto L_fn_0E151_000070;                  /* jmp 0x0070 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E1F2(cpu);                           /* call 0x00A1 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0E151_000070;                  /* jmp 0x0070 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E27B(cpu);                           /* call 0x012A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0E151_000070;                  /* jmp 0x0070 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E2D6(cpu);                           /* call 0x0185 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0E151_000070;                  /* jmp 0x0070 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E324(cpu);                           /* call 0x01D3 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0E151_000070;                  /* jmp 0x0070 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E372(cpu);                           /* call 0x0221 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0E151_000070;                  /* jmp 0x0070 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E44B(cpu);                           /* call 0x02FA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0E151_000070;                  /* jmp 0x0070 */
L_fn_0E151_000070:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E1C4(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E1C4");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E420(cpu);                           /* call 0x025C */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E262(cpu);                           /* call 0x009E */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E1F2(cpu);                           /* call 0x002E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E27B(cpu);                           /* call 0x00B7 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E2D6(cpu);                           /* call 0x0112 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E324(cpu);                           /* call 0x0160 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E372(cpu);                           /* call 0x01AE */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E44B(cpu);                           /* call 0x0287 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E1F2(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E1F2");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov di, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x8))); /* mov al, byte es:[bx+0x8] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _r = cpu->ax & 0x3F; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x3F */
    cpu->si = (uint16_t)(0x3F);              /* mov si, 0x3F */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->ax)); /* sub si, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di - 0x35B0))); /* mov al, byte ds:[di+-0x35B0] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->si; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul si */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x7F)); /* add ax, 0x7F */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->bx = (uint16_t)(0xFE);              /* mov bx, 0xFE */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    { uint32_t _n = ((uint32_t)cpu->dx << 16) | cpu->ax; uint16_t _d = cpu->bx; if (_d && _n / _d <= 0xFFFFu) { cpu->ax = (uint16_t)(_n / _d); cpu->dx = (uint16_t)(_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x003B; recomp_div0("div16"); } } /* div bx */
    cpu->dx = (uint16_t)(0x3F);              /* mov dx, 0x3F */
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, cpu->ax)); /* sub dx, ax */
    cpu->si = (uint16_t)(cpu->dx);           /* mov si, dx */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->cl = (uint8_t)(0x6);                /* mov cl, 0x6 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    { uint16_t _r = cpu->si | cpu->ax; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x2FE4))); /* mov al, byte ds:[di+0x2FE4] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x40)); /* add ax, 0x40 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE6A6 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E262(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E262");
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6B4), 0x0); /* cmp byte ds:[0xC6B4], 0x0 */
    if (cc_e(cpu)) goto L_fn_0E262_00000C;   /* je 0x000C */
    cpu->ax = (uint16_t)(0x40);              /* mov ax, 0x40 */
    goto L_fn_0E262_00000E;                  /* jmp 0x000E */
L_fn_0E262_00000C:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_0E262_00000E:;
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE636 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E27B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E27B");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->si + 0x2FF6)), 0x0); /* cmp byte ds:[si+0x2FF6], 0x0 */
    if (cc_e(cpu)) goto L_fn_0E27B_000011;   /* je 0x0011 */
    goto L_fn_0E27B_000057;                  /* jmp 0x0057 */
L_fn_0E27B_000011:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC)), 0x0); /* cmp byte es:[bx+0xC], 0x0 */
    if (cc_e(cpu)) goto L_fn_0E27B_000043;   /* je 0x0043 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0E27B_000046;                  /* jmp 0x0046 */
L_fn_0E27B_000043:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
L_fn_0E27B_000046:;
    { uint16_t _r = cpu->di | cpu->ax; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, ax */
    push16(cpu, cpu->di);                    /* push di */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->si + 0x3008))); /* mov al, byte ds:[si+0x3008] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC0)); /* add ax, 0xC0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE61D */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0E27B_000057:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E2D6(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E2D6");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov di, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3))); /* mov al, byte es:[bx+0x3] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->si; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->si = (uint16_t)(_r); } } /* shl si, cl */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x6))); /* mov al, byte es:[bx+0x6] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _r = cpu->ax & 0xF; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF */
    { uint16_t _r = cpu->si | cpu->ax; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x2FE4))); /* mov al, byte ds:[di+0x2FE4] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x60)); /* add ax, 0x60 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE5C2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E324(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E324");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov di, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4))); /* mov al, byte es:[bx+0x4] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->si; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->si = (uint16_t)(_r); } } /* shl si, cl */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x7))); /* mov al, byte es:[bx+0x7] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _r = cpu->ax & 0xF; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF */
    { uint16_t _r = cpu->si | cpu->ax; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x2FE4))); /* mov al, byte ds:[di+0x2FE4] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x80)); /* add ax, 0x80 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE574 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E372(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E372");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov di, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x9)), 0x0); /* cmp byte es:[bx+0x9], 0x0 */
    if (cc_e(cpu)) goto L_fn_0E372_000023;   /* je 0x0023 */
    cpu->si = (uint16_t)(0x80);              /* mov si, 0x80 */
    goto L_fn_0E372_000025;                  /* jmp 0x0025 */
L_fn_0E372_000023:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
L_fn_0E372_000025:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xA)), 0x0); /* cmp byte es:[bx+0xA], 0x0 */
    if (cc_e(cpu)) goto L_fn_0E372_000040;   /* je 0x0040 */
    cpu->ax = (uint16_t)(0x40);              /* mov ax, 0x40 */
    goto L_fn_0E372_000042;                  /* jmp 0x0042 */
L_fn_0E372_000040:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_0E372_000042:;
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x5)), 0x0); /* cmp byte es:[bx+0x5], 0x0 */
    if (cc_e(cpu)) goto L_fn_0E372_00005F;   /* je 0x005F */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    goto L_fn_0E372_000061;                  /* jmp 0x0061 */
L_fn_0E372_00005F:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_0E372_000061:;
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xB)), 0x0); /* cmp byte es:[bx+0xB], 0x0 */
    if (cc_e(cpu)) goto L_fn_0E372_00007E;   /* je 0x007E */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    goto L_fn_0E372_000080;                  /* jmp 0x0080 */
L_fn_0E372_00007E:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_0E372_000080:;
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _r = cpu->ax & 0xF; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x2FE4))); /* mov al, byte ds:[di+0x2FE4] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x20)); /* add ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE526 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E420(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E420");
    push16(cpu, cpu->si);                    /* push si */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6AA), 0x0); /* cmp byte ds:[0xC6AA], 0x0 */
    if (cc_e(cpu)) goto L_fn_0E420_00000D;   /* je 0x000D */
    cpu->si = (uint16_t)(0x80);              /* mov si, 0x80 */
    goto L_fn_0E420_00000F;                  /* jmp 0x000F */
L_fn_0E420_00000D:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
L_fn_0E420_00000F:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xC6B5), 0x0); /* cmp byte ds:[0xC6B5], 0x0 */
    if (cc_e(cpu)) goto L_fn_0E420_00001B;   /* je 0x001B */
    cpu->ax = (uint16_t)(0x40);              /* mov ax, 0x40 */
    goto L_fn_0E420_00001D;                  /* jmp 0x001D */
L_fn_0E420_00001B:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_0E420_00001D:;
    { uint16_t _r = cpu->si | cpu->ax; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0xBD);              /* mov ax, 0xBD */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE478 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}
