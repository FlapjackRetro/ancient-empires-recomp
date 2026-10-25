#include "recomp_all.h"

void fn_06036(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06036");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bp = (uint16_t)(0x2F);              /* mov bp, 0x2F */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC8); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC8 + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[0xBFC8] */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40D0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40D0 + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[0x40D0] */
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    { uint8_t _r = cpu->ch ^ cpu->ch; flags_logic8(cpu, _r); cpu->ch = (uint8_t)(_r); } /* xor ch, ch */
    cpu->cl = (uint8_t)(cpu->al);            /* mov cl, al */
L_fn_06036_000017:;
    push16(cpu, cpu->di);                    /* push di */
    { int _cf = cf(cpu); cpu->bp = (uint16_t)(flags_add16(cpu, cpu->bp, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bp */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    { uint8_t _r = cpu->al & 0x1F; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0x1F */
    cpu->dx = (uint16_t)(0x1E6);             /* mov dx, 0x1E6 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x2)); /* add ax, 0x2 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->dl = (uint8_t)(cpu->bh);            /* mov dl, bh */
    cpu->bh = (uint8_t)(cpu->dh);            /* mov bh, dh */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->es);                    /* push es */
    cpu->ax = (uint16_t)(0x1FA3);            /* mov ax, 0x1FA3 */
    cpu->ds = (uint16_t)(cpu->ax);           /* mov ds, ax */
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, cpu->bp);                    /* push bp */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D825(cpu);                           /* call 0x77EF */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x4)); /* add sp, 0x4 */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    push16(cpu, cpu->es);                    /* push es */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->di);                    /* push di */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 0xB8)); /* add dx, 0xB8 */
    push16(cpu, cpu->dx);                    /* push dx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xA396 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_06036_000017; /* loop 0x0017 */
    mem_write16(cpu, cpu->ds, 0xA20, (uint16_t)(0xA)); /* mov word ds:[0xA20], 0xA */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_060A9(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_060A9");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x8FE), 0x0); /* cmp word ds:[0x8FE], 0x0 */
    if (cc_e(cpu)) goto L_fn_060A9_000011;   /* je 0x0011 */
    goto L_fn_060A9_0000D3;                  /* jmp 0x00D3 */
L_fn_060A9_000011:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0xA20, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0xA20), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ds:[0xA20] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xA20), 0x0); /* cmp word ds:[0xA20], 0x0 */
    if (cc_e(cpu)) goto L_fn_060A9_00001F;   /* je 0x001F */
    goto L_fn_060A9_0000D3;                  /* jmp 0x00D3 */
L_fn_060A9_00001F:;
    mem_write16(cpu, cpu->ds, 0xA20, (uint16_t)(0xA)); /* mov word ds:[0xA20], 0xA */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC8); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC8 + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[0xBFC8] */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40D0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40D0 + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[0x40D0] */
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    { uint16_t _r = cpu->cx ^ cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* xor cx, cx */
    cpu->cl = (uint8_t)(cpu->al);            /* mov cl, al */
L_fn_060A9_000032:;
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->dl = (uint8_t)(cpu->ah);            /* mov dl, ah */
    cpu->bh = (uint8_t)(cpu->dh);            /* mov bh, dh */
    cpu->bl = (uint8_t)(cpu->al);            /* mov bl, al */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bp = (uint16_t)(cpu->dx);           /* mov bp, dx */
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    flags_logic8(cpu, cpu->al & 0x80);       /* test al, 0x80 */
    if (cc_ne(cpu)) goto L_fn_060A9_00004A;  /* jne 0x004A */
    goto L_fn_060A9_0000CC;                  /* jmp 0x00CC */
L_fn_060A9_00004A:;
    flags_logic8(cpu, cpu->al & 0x40);       /* test al, 0x40 */
    if (cc_e(cpu)) goto L_fn_060A9_000058;   /* je 0x0058 */
    { uint8_t _r = cpu->al & 0x1F; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0x1F */
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec al */
    if (cc_ge(cpu)) goto L_fn_060A9_000056;  /* jge 0x0056 */
    cpu->al = (uint8_t)(0x17);               /* mov al, 0x17 */
L_fn_060A9_000056:;
    goto L_fn_060A9_000062;                  /* jmp 0x0062 */
L_fn_060A9_000058:;
    { uint8_t _r = cpu->al & 0x1F; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0x1F */
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc al */
    flags_cmp8(cpu, cpu->al, 0x17);          /* cmp al, 0x17 */
    if (cc_le(cpu)) goto L_fn_060A9_000062;  /* jle 0x0062 */
    cpu->al = (uint8_t)(0x0);                /* mov al, 0x0 */
L_fn_060A9_000062:;
    { uint8_t _r = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->si - 0x1)) & 0xE0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si - 0x1), (uint8_t)(_r)); } /* and byte ds:[si+-0x1], 0xE0 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->si - 0x1)) | cpu->al; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si - 0x1), (uint8_t)(_r)); } /* or byte ds:[si+-0x1], al */
    cpu->dx = (uint16_t)(0x1E6);             /* mov dx, 0x1E6 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x2)); /* add ax, 0x2 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->dx = (uint16_t)(cpu->bp);           /* mov dx, bp */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->dx);                    /* push dx */
    cpu->ax = (uint16_t)(0x1FA3);            /* mov ax, 0x1FA3 */
    cpu->ds = (uint16_t)(cpu->ax);           /* mov ds, ax */
    push16(cpu, cpu->dx);                    /* push dx */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->dx);           /* mov ax, dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x148)); /* add ax, 0x148 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xA30B */
    mem_write16(cpu, cpu->ss, cpu->bp, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, cpu->bp), 0xB8))); /* add word ss:[bp], 0xB8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xA30B */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    push16(cpu, cpu->es);                    /* push es */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xA323 */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(cpu->dx);           /* mov ax, dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xA30B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
L_fn_060A9_0000CC:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec cx */
    if (cpu->cx == 0) goto L_fn_060A9_0000D3; /* jcxz 0x00D3 */
    RECOMP_TICK(cpu);
    goto L_fn_060A9_000032;                  /* jmp 0x0032 */
L_fn_060A9_0000D3:;
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06181(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06181");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC8); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC8 + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[0xBFC8] */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40D0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40D0 + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[0x40D0] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->bx)); /* add si, bx */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->dl = (uint8_t)(cpu->ah);            /* mov dl, ah */
    cpu->bh = (uint8_t)(cpu->dh);            /* mov bh, dh */
    cpu->bl = (uint8_t)(cpu->al);            /* mov bl, al */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bp = (uint16_t)(cpu->dx);           /* mov bp, dx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, cpu->si)); /* mov al, byte ds:[si] */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    flags_logic8(cpu, cpu->al & 0x40);       /* test al, 0x40 */
    if (cc_e(cpu)) goto L_fn_06181_00003A;   /* je 0x003A */
    { uint8_t _r = cpu->al & 0x1F; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0x1F */
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec al */
    if (cc_ge(cpu)) goto L_fn_06181_000038;  /* jge 0x0038 */
    cpu->al = (uint8_t)(0x17);               /* mov al, 0x17 */
L_fn_06181_000038:;
    goto L_fn_06181_000044;                  /* jmp 0x0044 */
L_fn_06181_00003A:;
    { uint8_t _r = cpu->al & 0x1F; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0x1F */
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc al */
    flags_cmp8(cpu, cpu->al, 0x17);          /* cmp al, 0x17 */
    if (cc_le(cpu)) goto L_fn_06181_000044;  /* jle 0x0044 */
    cpu->al = (uint8_t)(0x0);                /* mov al, 0x0 */
L_fn_06181_000044:;
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->si) & 0xE0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->si, (uint8_t)(_r)); } /* and byte ds:[si], 0xE0 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->si) | cpu->al; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->si, (uint8_t)(_r)); } /* or byte ds:[si], al */
    cpu->dx = (uint16_t)(0x1E6);             /* mov dx, 0x1E6 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x2)); /* add ax, 0x2 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->dx = (uint16_t)(cpu->bp);           /* mov dx, bp */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->dx);                    /* push dx */
    cpu->ax = (uint16_t)(0x1FA3);            /* mov ax, 0x1FA3 */
    cpu->ds = (uint16_t)(cpu->ax);           /* mov ds, ax */
    push16(cpu, cpu->dx);                    /* push dx */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->dx);           /* mov ax, dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x148)); /* add ax, 0x148 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xA233 */
    mem_write16(cpu, cpu->ss, cpu->bp, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, cpu->bp), 0xB8))); /* add word ss:[bp], 0xB8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xA233 */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xA24B */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(cpu->dx);           /* mov ax, dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xA233 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0622C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0622C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    mem_write16(cpu, cpu->ds, 0xB3E, (uint16_t)(0x1)); /* mov word ds:[0xB3E], 0x1 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov al, byte ss:[bp+0x6] */
    { uint8_t _r = cpu->al & 0xFF; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0xFF */
    mem_write8(cpu, cpu->ds, 0xC0C8, (uint8_t)(cpu->al)); /* mov byte ds:[0xC0C8], al */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB40), 0x0); /* cmp word ds:[0xB40], 0x0 */
    if (cc_e(cpu)) goto L_fn_0622C_000022;   /* je 0x0022 */
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F7CD(cpu);                           /* call 0x95A1 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0622C_00002A;                  /* jmp 0x002A */
L_fn_0622C_000022:;
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F7B2(cpu);                           /* call 0x9586 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0622C_00002A:;
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    goto L_fn_0622C_00002F;                  /* jmp 0x002F */
L_fn_0622C_00002F:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0625D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0625D");
    cpu->ax = (uint16_t)(0x622C);            /* mov ax, 0x622C */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F799(cpu);                           /* call 0x953C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06266(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06266");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0xA)); /* sub sp, 0xA */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB40)); /* mov ax, word ds:[0xB40] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    mem_write16(cpu, cpu->ds, 0xB40, (uint16_t)(0x1)); /* mov word ds:[0xB40], 0x1 */
L_fn_06266_000017:;
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    mem_write16(cpu, cpu->ds, 0xB3E, (uint16_t)(cpu->di)); /* mov word ds:[0xB3E], di */
    cpu->ax = (uint16_t)(0x8004);            /* mov ax, 0x8004 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xA22)); /* add ax, 0xA22 */
    cpu->dx = (uint16_t)(cpu->ds);           /* mov dx, ds */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, cl */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xA22)); /* add bx, 0xA22 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0x42); /* cmp byte es:[bx], 0x42 */
    if (cc_le(cpu)) goto L_fn_06266_000045;  /* jle 0x0045 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_06266_000047;                  /* jmp 0x0047 */
L_fn_06266_000045:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_06266_000047:;
    cpu->dx = (uint16_t)(0x3);               /* mov dx, 0x3 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ECDA(cpu);                           /* call 0x8A74 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    mem_write16(cpu, cpu->ds, 0xC0C9, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0C9], ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x6)); /* lea ax, word ss:[bp+-0x6] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EEFE(cpu);                           /* call 0x8C98 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9), 0x0); /* cmp word ds:[0xC0C9], 0x0 */
    if (cc_l(cpu)) goto L_fn_06266_0000A0;   /* jl 0x00A0 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB3E), 0x0); /* cmp word ds:[0xB3E], 0x0 */
    if (cc_ne(cpu)) goto L_fn_06266_0000A0;  /* jne 0x00A0 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x4); /* cmp word ss:[bp+-0x2], 0x4 */
    if (cc_l(cpu)) goto L_fn_06266_0000A0;   /* jl 0x00A0 */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0xA54))); /* mov dx, word ds:[bx+0xA54] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0xA52))); /* mov ax, word ds:[bx+0xA52] */
    flags_cmp16(cpu, cpu->dx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* cmp dx, word ss:[bp+-0x4] */
    if (cc_ne(cpu)) goto L_fn_06266_0000A0;  /* jne 0x00A0 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* cmp ax, word ss:[bp+-0x6] */
    if (cc_ne(cpu)) goto L_fn_06266_0000A0;  /* jne 0x00A0 */
    goto L_fn_06266_0001C1;                  /* jmp 0x01C1 */
L_fn_06266_0000A0:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9), 0x0); /* cmp word ds:[0xC0C9], 0x0 */
    if (cc_l(cpu)) goto L_fn_06266_0000AF;   /* jl 0x00AF */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EEAD(cpu);                           /* call 0x8C47 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_06266_0000AF:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCC), 0x1); /* cmp byte ds:[0xBFCC], 0x1 */
    if (cc_g(cpu)) goto L_fn_06266_0000B9;   /* jg 0x00B9 */
    goto L_fn_06266_00019D;                  /* jmp 0x019D */
L_fn_06266_0000B9:;
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, cl */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xA22)); /* add bx, 0xA22 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x9], al */
    flags_cmp8(cpu, cpu->al, 0x42);          /* cmp al, 0x42 */
    if (cc_le(cpu)) goto L_fn_06266_0000D2;  /* jle 0x00D2 */
    goto L_fn_06266_00019D;                  /* jmp 0x019D */
L_fn_06266_0000D2:;
    cpu->al = (uint8_t)(0x42);               /* mov al, 0x42 */
    cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9)))); /* sub al, byte ss:[bp+-0x9] */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0x41)); /* add al, 0x41 */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x9], al */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9))); /* mov al, byte ss:[bp+-0x9] */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, cl */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xA22)); /* add bx, 0xA22 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    mem_write16(cpu, cpu->ds, 0xB3E, (uint16_t)(0x0)); /* mov word ds:[0xB3E], 0x0 */
    cpu->ax = (uint16_t)(0x8004);            /* mov ax, 0x8004 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xA22)); /* add ax, 0xA22 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ECDA(cpu);                           /* call 0x8A74 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    mem_write16(cpu, cpu->ds, 0xC0C9, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0C9], ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x6)); /* lea ax, word ss:[bp+-0x6] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EEFE(cpu);                           /* call 0x8C98 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9), 0x0); /* cmp word ds:[0xC0C9], 0x0 */
    if (cc_l(cpu)) goto L_fn_06266_000150;   /* jl 0x0150 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB3E), 0x0); /* cmp word ds:[0xB3E], 0x0 */
    if (cc_ne(cpu)) goto L_fn_06266_000150;  /* jne 0x0150 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x4); /* cmp word ss:[bp+-0x2], 0x4 */
    if (cc_l(cpu)) goto L_fn_06266_000150;   /* jl 0x0150 */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0xA54))); /* mov dx, word ds:[bx+0xA54] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0xA52))); /* mov ax, word ds:[bx+0xA52] */
    flags_cmp16(cpu, cpu->dx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* cmp dx, word ss:[bp+-0x4] */
    if (cc_ne(cpu)) goto L_fn_06266_000150;  /* jne 0x0150 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* cmp ax, word ss:[bp+-0x6] */
    if (cc_e(cpu)) goto L_fn_06266_00019B;   /* je 0x019B */
L_fn_06266_000150:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9), 0x0); /* cmp word ds:[0xC0C9], 0x0 */
    if (cc_l(cpu)) goto L_fn_06266_00015F;   /* jl 0x015F */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EEAD(cpu);                           /* call 0x8C47 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_06266_00015F:;
    cpu->al = (uint8_t)(0x42);               /* mov al, 0x42 */
    cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9)))); /* sub al, byte ss:[bp+-0x9] */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0x41)); /* add al, 0x41 */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, cl */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xA22)); /* add bx, 0xA22 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x23);              /* mov dx, 0x23 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xA5E)); /* add bx, 0xA5E */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->ds, 0xB33, (uint16_t)(cpu->es)); /* mov word ds:[0xB33], es */
    mem_write16(cpu, cpu->ds, 0xB31, (uint16_t)(cpu->bx)); /* mov word ds:[0xB31], bx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xB2A);             /* mov ax, 0xB2A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_086C9(cpu);                           /* call 0x2463 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(0x1);               /* mov di, 0x1 */
L_fn_06266_00019B:;
    goto L_fn_06266_0001C1;                  /* jmp 0x01C1 */
L_fn_06266_00019D:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x23);              /* mov dx, 0x23 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xA5E)); /* add bx, 0xA5E */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->ds, 0xB33, (uint16_t)(cpu->es)); /* mov word ds:[0xB33], es */
    mem_write16(cpu, cpu->ds, 0xB31, (uint16_t)(cpu->bx)); /* mov word ds:[0xB31], bx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xB2A);             /* mov ax, 0xB2A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_086C9(cpu);                           /* call 0x2463 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(0x1);               /* mov di, 0x1 */
L_fn_06266_0001C1:;
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    if (cc_e(cpu)) goto L_fn_06266_0001C8;   /* je 0x01C8 */
    RECOMP_TICK(cpu);
    goto L_fn_06266_000017;                  /* jmp 0x0017 */
L_fn_06266_0001C8:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    mem_write16(cpu, cpu->ds, 0xB40, (uint16_t)(cpu->ax)); /* mov word ds:[0xB40], ax */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0643A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0643A");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0xC)); /* sub sp, 0xC */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    cpu->di = (uint16_t)(cpu->si);           /* mov di, si */
    cpu->cl = (uint8_t)(0xC);                /* mov cl, 0xC */
    { uint16_t _v = cpu->di; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shr di, cl */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB40)); /* mov ax, word ds:[0xB40] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    { uint16_t _r = cpu->si & 0xFFF; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* and si, 0xFFF */
    mem_write16(cpu, cpu->ds, 0xB40, (uint16_t)(0x1)); /* mov word ds:[0xB40], 0x1 */
L_fn_0643A_000021:;
    mem_write16(cpu, cpu->ds, 0xB3E, (uint16_t)(0x0)); /* mov word ds:[0xB3E], 0x0 */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06266(cpu);                           /* call 0xFE2C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F183(cpu);                           /* call 0x8D49 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0xA)); /* lea ax, word ss:[bp+-0xA] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EEFE(cpu);                           /* call 0x8AC4 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x6)); /* lea ax, word ss:[bp+-0x6] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EEFE(cpu);                           /* call 0x8AC4 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)))); /* sub ax, word ss:[bp+-0xA] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov dx, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* mov ax, word ss:[bp+-0xA] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x2)); /* add ax, 0x2 */
    cpu->dx = (uint16_t)(flags_adc(cpu, cpu->dx, 0x0, 16)); /* adc dx, 0x0 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F183(cpu);                           /* call 0x8D49 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC))); /* mov ax, word ss:[bp+-0xC] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EFDB(cpu);                           /* call 0x8BA1 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EEAD(cpu);                           /* call 0x8A73 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB3E), 0x0); /* cmp word ds:[0xB3E], 0x0 */
    if (cc_e(cpu)) goto L_fn_0643A_0000D9;   /* je 0x00D9 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC0C8)); /* mov al, byte ds:[0xC0C8] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0652A(cpu);                           /* call 0x00F0 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0xB33, (uint16_t)(cpu->ds)); /* mov word ds:[0xB33], ds */
    mem_write16(cpu, cpu->ds, 0xB31, (uint16_t)(0xAC7)); /* mov word ds:[0xB31], 0xAC7 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xB2A);             /* mov ax, 0xB2A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_086C9(cpu);                           /* call 0x228F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC0C8)); /* mov al, byte ds:[0xC0C8] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0652A(cpu);                           /* call 0x00F0 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0643A_0000D9:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB3E), 0x0); /* cmp word ds:[0xB3E], 0x0 */
    if (cc_e(cpu)) goto L_fn_0643A_0000E3;   /* je 0x00E3 */
    RECOMP_TICK(cpu);
    goto L_fn_0643A_000021;                  /* jmp 0x0021 */
L_fn_0643A_0000E3:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    mem_write16(cpu, cpu->ds, 0xB40, (uint16_t)(cpu->ax)); /* mov word ds:[0xB40], ax */
    cpu->flags |= FLAG_IF;                   /* sti */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0652A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0652A");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x200)); /* sub sp, 0x200 */
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0652A_000034;                  /* jmp 0x0034 */
L_fn_0652A_00000C:;
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->dl = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC0C8)); /* mov dl, byte ds:[0xC0C8] */
    int_handler(cpu, 0x13);                  /* int 0x13 */
    cpu->dx = (uint16_t)(cpu->ss);           /* mov dx, ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x200)); /* lea ax, word ss:[bp+-0x200] */
    cpu->es = (uint16_t)(cpu->dx);           /* mov es, dx */
    cpu->dx = (uint16_t)(cpu->ss);           /* mov dx, ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x200)); /* lea ax, word ss:[bp+-0x200] */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->ah = (uint8_t)(0x2);                /* mov ah, 0x2 */
    cpu->al = (uint8_t)(0x1);                /* mov al, 0x1 */
    cpu->ch = (uint8_t)(0x1);                /* mov ch, 0x1 */
    cpu->cl = (uint8_t)(0x1);                /* mov cl, 0x1 */
    cpu->dh = (uint8_t)(0x0);                /* mov dh, 0x0 */
    cpu->dl = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov dl, byte ss:[bp+0x4] */
    int_handler(cpu, 0x13);                  /* int 0x13 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0652A_000034:;
    flags_cmp16(cpu, cpu->si, 0x3);          /* cmp si, 0x3 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0652A_00000C;   /* jl 0x000C */
    cpu->ah = (uint8_t)(0xD);                /* mov ah, 0xD */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0656C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0656C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0xC)); /* sub sp, 0xC */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov di, word ss:[bp+0x4] */
    cpu->cl = (uint8_t)(0xC);                /* mov cl, 0xC */
    { uint16_t _v = cpu->di; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shr di, cl */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB40)); /* mov ax, word ds:[0xB40] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    { uint16_t _r = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)) & 0xFFF; flags_logic16(cpu, _r); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(_r)); } /* and word ss:[bp+0x4], 0xFFF */
    mem_write16(cpu, cpu->ds, 0xB40, (uint16_t)(0x1)); /* mov word ds:[0xB40], 0x1 */
L_fn_0656C_000020:;
    mem_write16(cpu, cpu->ds, 0xB3E, (uint16_t)(0x0)); /* mov word ds:[0xB3E], 0x0 */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06266(cpu);                           /* call 0xFCFA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F183(cpu);                           /* call 0x8C17 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0xC)); /* lea ax, word ss:[bp+-0xC] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EEFE(cpu);                           /* call 0x8992 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x8)); /* lea ax, word ss:[bp+-0x8] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EEFE(cpu);                           /* call 0x8992 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov si, word ss:[bp+-0x8] */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC)))); /* sub si, word ss:[bp+-0xC] */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* push word ss:[bp+-0xA] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC))); /* push word ss:[bp+-0xC] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F183(cpu);                           /* call 0x8C17 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5CC)); /* push word ds:[0xC5CC] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5CA)); /* push word ds:[0xC5CA] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EEFE(cpu);                           /* call 0x8992 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0C9)); /* push word ds:[0xC0C9] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EEAD(cpu);                           /* call 0x8941 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB3E), 0x0); /* cmp word ds:[0xB3E], 0x0 */
    if (cc_e(cpu)) goto L_fn_0656C_0000C5;   /* je 0x00C5 */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0x23);              /* mov dx, 0x23 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xA5E)); /* add bx, 0xA5E */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->ds, 0xB33, (uint16_t)(cpu->es)); /* mov word ds:[0xB33], es */
    mem_write16(cpu, cpu->ds, 0xB31, (uint16_t)(cpu->bx)); /* mov word ds:[0xB31], bx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xB2A);             /* mov ax, 0xB2A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_086C9(cpu);                           /* call 0x215D */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0656C_0000C5:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB3E), 0x0); /* cmp word ds:[0xB3E], 0x0 */
    if (cc_e(cpu)) goto L_fn_0656C_0000CF;   /* je 0x00CF */
    RECOMP_TICK(cpu);
    goto L_fn_0656C_000020;                  /* jmp 0x0020 */
L_fn_0656C_0000CF:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    mem_write16(cpu, cpu->ds, 0xB40, (uint16_t)(cpu->ax)); /* mov word ds:[0xB40], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5CA] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    mem_write8(cpu, cpu->ds, 0xC0CB, (uint8_t)(cpu->al)); /* mov byte ds:[0xC0CB], al */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5CA] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x3), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x3], al */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x3)) & 0x2); /* test byte ss:[bp+-0x3], 0x2 */
    if (cc_e(cpu)) goto L_fn_0656C_00012C;   /* je 0x012C */
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x3)) & 0x1); /* test byte ss:[bp+-0x3], 0x1 */
    if (cc_e(cpu)) goto L_fn_0656C_00012C;   /* je 0x012C */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C0)); /* push word ds:[0xC5C0] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5BE)); /* push word ds:[0xC5BE] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06DCC(cpu);                           /* call 0x0860 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C0)); /* push word ds:[0xC5C0] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5BE)); /* push word ds:[0xC5BE] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D86(cpu);                           /* call 0x081A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    goto L_fn_0656C_00019A;                  /* jmp 0x019A */
L_fn_0656C_00012C:;
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x3)) & 0x2); /* test byte ss:[bp+-0x3], 0x2 */
    if (cc_e(cpu)) goto L_fn_0656C_000164;   /* je 0x0164 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C0)); /* push word ds:[0xC5C0] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5BE)); /* push word ds:[0xC5BE] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06DCC(cpu);                           /* call 0x0860 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C0)); /* push word ds:[0xC5C0] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5BE)); /* push word ds:[0xC5BE] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F39C(cpu);                           /* call 0x8E30 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    goto L_fn_0656C_00019A;                  /* jmp 0x019A */
L_fn_0656C_000164:;
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x3)) & 0x1); /* test byte ss:[bp+-0x3], 0x1 */
    if (cc_e(cpu)) goto L_fn_0656C_00019A;   /* je 0x019A */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C0)); /* push word ds:[0xC5C0] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5BE)); /* push word ds:[0xC5BE] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D86(cpu);                           /* call 0x081A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C0)); /* push word ds:[0xC5C0] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5BE)); /* push word ds:[0xC5BE] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F39C(cpu);                           /* call 0x8E30 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_0656C_00019A:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x5); /* cmp byte ds:[0xBFCD], 0x5 */
    if (cc_e(cpu)) goto L_fn_0656C_0001FA;   /* je 0x01FA */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC0CB)); /* mov al, byte ds:[0xC0CB] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_0656C_0001DA;   /* je 0x01DA */
    flags_cmp16(cpu, cpu->ax, 0x1);          /* cmp ax, 0x1 */
    if (cc_e(cpu)) goto L_fn_0656C_0001EB;   /* je 0x01EB */
    flags_cmp16(cpu, cpu->ax, 0x47);         /* cmp ax, 0x47 */
    if (cc_e(cpu)) goto L_fn_0656C_0001B5;   /* je 0x01B5 */
    goto L_fn_0656C_0001FA;                  /* jmp 0x01FA */
L_fn_0656C_0001B5:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x2); /* cmp byte ds:[0xBFCD], 0x2 */
    if (cc_ne(cpu)) goto L_fn_0656C_0001CB;  /* jne 0x01CB */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06F4B(cpu);                           /* call 0x09DF */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0656C_0001D8;                  /* jmp 0x01D8 */
L_fn_0656C_0001CB:;
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06EFF(cpu);                           /* call 0x0993 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0656C_0001D8:;
    goto L_fn_0656C_0001FA;                  /* jmp 0x01FA */
L_fn_0656C_0001DA:;
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06771(cpu);                           /* call 0x0205 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    goto L_fn_0656C_0001FA;                  /* jmp 0x01FA */
L_fn_0656C_0001EB:;
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_067DC(cpu);                           /* call 0x0270 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0656C_0001FA;                  /* jmp 0x01FA */
L_fn_0656C_0001FA:;
    cpu->flags |= FLAG_IF;                   /* sti */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    goto L_fn_0656C_0001FF;                  /* jmp 0x01FF */
L_fn_0656C_0001FF:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06771(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06771");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_06771_000061;                  /* jmp 0x0061 */
L_fn_06771_00000B:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->si)); /* add bx, si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0x47); /* cmp byte es:[bx], 0x47 */
    if (cc_e(cpu)) goto L_fn_06771_000021;   /* je 0x0021 */
    goto L_fn_06771_000066;                  /* jmp 0x0066 */
L_fn_06771_000021:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x2); /* cmp byte ds:[0xBFCD], 0x2 */
    if (cc_ne(cpu)) goto L_fn_06771_000039;  /* jne 0x0039 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06F4B(cpu);                           /* call 0x07DA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_06771_000048;                  /* jmp 0x0048 */
L_fn_06771_000039:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06EFF(cpu);                           /* call 0x078E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_06771_000048:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x22))); /* mov al, byte es:[bx+0x22] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->dl = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x23))); /* mov dl, byte es:[bx+0x23] */
    cpu->dh = (uint8_t)(0x0);                /* mov dh, 0x0 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x24)); /* add ax, 0x24 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
L_fn_06771_000061:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* cmp si, word ss:[bp+0x8] */
    RECOMP_TICK(cpu);
    if (cc_b(cpu)) goto L_fn_06771_00000B;   /* jb 0x000B */
L_fn_06771_000066:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_067DC(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_067DC");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x8)); /* sub sp, 0x8 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x6], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x8], bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov di, word es:[bx] */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shr di, 0x1 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_067DC_000064;                  /* jmp 0x0064 */
L_fn_067DC_00001E:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x2))); /* add word ss:[bp+-0x8], 0x2 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0x47); /* cmp byte es:[bx], 0x47 */
    if (cc_ne(cpu)) goto L_fn_067DC_000063;  /* jne 0x0063 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x2); /* cmp byte ds:[0xBFCD], 0x2 */
    if (cc_ne(cpu)) goto L_fn_067DC_000054;  /* jne 0x0054 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06F4B(cpu);                           /* call 0x076F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_067DC_000063;                  /* jmp 0x0063 */
L_fn_067DC_000054:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06EFF(cpu);                           /* call 0x0723 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_067DC_000063:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_067DC_000064:;
    flags_cmp16(cpu, cpu->si, cpu->di);      /* cmp si, di */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_067DC_00001E;   /* jl 0x001E */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0684A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0684A");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xFD22 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E9B4(cpu);                           /* call 0x816A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x6) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x6] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2), (uint16_t)(cpu->dx)); /* mov word es:[bx+0x2], dx */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(cpu->ax)); /* mov word es:[bx], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x6) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    { uint16_t _r = cpu->ax | mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)); flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, word es:[bx+0x2] */
    if (cc_ne(cpu)) goto L_fn_0684A_000044;  /* jne 0x0044 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_049E3(cpu);                           /* call 0xE199 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0034F(cpu);                           /* call 0x9B05 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xB42);             /* mov ax, 0xB42 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04F63(cpu);                           /* call 0xE719 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E627(cpu);                           /* call 0x7DDD */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0684A_000044:;
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x6) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* push word es:[bx+0x2] */
    push16(cpu, mem_read16(cpu, cpu->es, cpu->bx)); /* push word es:[bx] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0x8AFE */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_068AA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_068AA");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0xFCC2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0x8A9E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_068CF(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_068CF");
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1772), 0x0); /* cmp word ds:[0x1772], 0x0 */
    if (cc_e(cpu)) goto L_fn_068CF_00004C;   /* je 0x004C */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0x6279 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C834(cpu);                           /* call 0x5F65 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0x176E, (uint16_t)(cpu->ax)); /* mov word ds:[0x176E], ax */
    mem_write16(cpu, cpu->ds, 0x1772, (uint16_t)(cpu->ax)); /* mov word ds:[0x1772], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x13ED), 0x0); /* cmp word ds:[0x13ED], 0x0 */
    if (cc_l(cpu)) goto L_fn_068CF_00004A;   /* jl 0x004A */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xD), (uint16_t)(cpu->ax)); /* mov word es:[bx+0xD], ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xF), (uint16_t)(cpu->ax)); /* mov word es:[bx+0xF], ax */
L_fn_068CF_00004A:;
    goto L_fn_068CF_00008E;                  /* jmp 0x008E */
L_fn_068CF_00004C:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    mem_write16(cpu, cpu->ds, 0x176E, (uint16_t)(cpu->ax)); /* mov word ds:[0x176E], ax */
    mem_write16(cpu, cpu->ds, 0x1772, (uint16_t)(cpu->ax)); /* mov word ds:[0x1772], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x13ED), 0x0); /* cmp word ds:[0x13ED], 0x0 */
    if (cc_l(cpu)) goto L_fn_068CF_00008B;   /* jl 0x008B */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xD), (uint16_t)(cpu->ax)); /* mov word es:[bx+0xD], ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xF), (uint16_t)(cpu->ax)); /* mov word es:[bx+0xF], ax */
L_fn_068CF_00008B:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D60C(cpu);                           /* call 0x6D3D */
L_fn_068CF_00008E:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_0695E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0695E");
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F73E(cpu);                           /* call 0x8DE0 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0xC0CE, (uint16_t)(cpu->dx)); /* mov word ds:[0xC0CE], dx */
    mem_write16(cpu, cpu->ds, 0xC0CC, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0CC], ax */
    push16(cpu, SEG_0000);                   /* push cs */
    cpu->ax = (uint16_t)(0x699E);            /* mov ax, 0x699E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F750(cpu);                           /* call 0x8DF2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0697D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0697D");
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0CE)); /* push word ds:[0xC0CE] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0CC)); /* push word ds:[0xC0CC] */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F750(cpu);                           /* call 0x8DD3 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06990(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06990");
    mem_write16(cpu, cpu->ds, 0xB72, (uint16_t)(0x1)); /* mov word ds:[0xB72], 0x1 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06997(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06997");
    mem_write16(cpu, cpu->ds, 0xB72, (uint16_t)(0x0)); /* mov word ds:[0xB72], 0x0 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06B1A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06B1A");
    push16(cpu, cpu->si);                    /* push si */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    bios_int16(cpu);                         /* int 0x16 */
    { uint8_t _r = cpu->al | cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, al */
    if (cc_ne(cpu)) goto L_fn_06B1A_00002C;  /* jne 0x002C */
    cpu->al = (uint8_t)(cpu->ah);            /* mov al, ah */
    cpu->ah = (uint8_t)(0x1);                /* mov ah, 0x1 */
    flags_cmp8(cpu, cpu->al, 0x3B);          /* cmp al, 0x3B */
    if (cc_b(cpu)) goto L_fn_06B1A_00002E;   /* jb 0x002E */
    flags_cmp8(cpu, cpu->al, 0x44);          /* cmp al, 0x44 */
    if (cc_g(cpu)) goto L_fn_06B1A_00002E;   /* jg 0x002E */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0792C(cpu);                           /* call 0x0E12 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    if (cc_e(cpu)) goto L_fn_06B1A_00002E;   /* je 0x002E */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 0x13B)); /* sub ax, 0x13B */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07964(cpu);                           /* call 0x0E4A */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    goto L_fn_06B1A_00002E;                  /* jmp 0x002E */
L_fn_06B1A_00002C:;
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
L_fn_06B1A_00002E:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06B4A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06B4A");
    cpu->ah = (uint8_t)(0x1);                /* mov ah, 0x1 */
    bios_int16(cpu);                         /* int 0x16 */
    if (cc_e(cpu)) goto L_fn_06B4A_000015;   /* je 0x0015 */
    { uint8_t _r = cpu->al | cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, al */
    if (cc_ne(cpu)) goto L_fn_06B4A_000019;  /* jne 0x0019 */
    cpu->al = (uint8_t)(cpu->ah);            /* mov al, ah */
    cpu->ah = (uint8_t)(0x1);                /* mov ah, 0x1 */
    goto L_fn_06B4A_00001B;                  /* jmp 0x001B */
    cpu->ax = (uint16_t)(0x100);             /* mov ax, 0x100 */
    goto L_fn_06B4A_000019;                  /* jmp 0x0019 */
L_fn_06B4A_000015:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_06B4A_00001B;                  /* jmp 0x001B */
L_fn_06B4A_000019:;
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
L_fn_06B4A_00001B:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_06B66(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06B66");
    goto L_fn_06B66_000006;                  /* jmp 0x0006 */
L_fn_06B66_000002:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    bios_int16(cpu);                         /* int 0x16 */
L_fn_06B66_000006:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B4A(cpu);                           /* call 0xFFE4 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_06B66_000002;  /* jne 0x0002 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06B74(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06B74");
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB72)); /* mov ax, word ds:[0xB72] */
    goto L_fn_06B74_000005;                  /* jmp 0x0005 */
L_fn_06B74_000005:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_06B7A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06B7A");
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->es);                    /* push es */
    cpu->ax = (uint16_t)(0x3508);            /* mov ax, 0x3508 */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ax = (uint16_t)(cpu->es);           /* mov ax, es */
    mem_write16(cpu, cpu->ds, 0xB7C, (uint16_t)(cpu->ax)); /* mov word ds:[0xB7C], ax */
    mem_write16(cpu, cpu->ds, 0xB7A, (uint16_t)(cpu->bx)); /* mov word ds:[0xB7A], bx */
    cpu->dx = (uint16_t)(0x6BCF);            /* mov dx, 0x6BCF */
    push16(cpu, SEG_0000);                   /* push cs */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->ax = (uint16_t)(0x2508);            /* mov ax, 0x2508 */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->al = (uint8_t)(0x36);               /* mov al, 0x36 */
    port_out8(cpu, 0x43, cpu->al);           /* out 0x43, al */
    cpu->ax = (uint16_t)(0x13B1);            /* mov ax, 0x13B1 */
    port_out8(cpu, 0x40, cpu->al);           /* out 0x40, al */
    cpu->al = (uint8_t)(cpu->ah);            /* mov al, ah */
    port_out8(cpu, 0x40, cpu->al);           /* out 0x40, al */
    cpu->al = (uint8_t)(0xB6);               /* mov al, 0xB6 */
    port_out8(cpu, 0x43, cpu->al);           /* out 0x43, al */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06BAC(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06BAC");
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->es);                    /* push es */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB7A)); /* mov dx, word ds:[0xB7A] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB7C)); /* mov ax, word ds:[0xB7C] */
    cpu->ds = (uint16_t)(cpu->ax);           /* mov ds, ax */
    cpu->ax = (uint16_t)(0x2508);            /* mov ax, 0x2508 */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->al = (uint8_t)(0x36);               /* mov al, 0x36 */
    port_out8(cpu, 0x43, cpu->al);           /* out 0x43, al */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    port_out8(cpu, 0x40, cpu->al);           /* out 0x40, al */
    cpu->al = (uint8_t)(cpu->ah);            /* mov al, ah */
    port_out8(cpu, 0x40, cpu->al);           /* out 0x40, al */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06BCF(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06BCF");
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(0x1FA3);            /* mov bp, 0x1FA3 */
    cpu->ds = (uint16_t)(cpu->bp);           /* mov ds, bp */
    push16(cpu, (uint16_t)(cpu->flags | 0x0002)); /* pushf */
    cpu->flags |= FLAG_IF;                   /* sti */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0xC0D4, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC0D4), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0xC0D4] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC0D4), 0xD); /* cmp word ds:[0xC0D4], 0xD */
    if (cc_l(cpu)) goto L_fn_06BCF_000026;   /* jl 0x0026 */
    mem_write16(cpu, cpu->ds, 0xC0D4, (uint16_t)(0x0)); /* mov word ds:[0xC0D4], 0x0 */
    push16(cpu, (uint16_t)(cpu->flags | 0x0002)); /* pushf */
    { uint16_t _o=0xB7A; uint16_t _s=cpu->ds; push16(cpu,SEG_0000); push16(cpu,0xFFFF); dispatch_far(cpu, mem_read16(cpu,_s,(uint16_t)(_o+2)), mem_read16(cpu,_s,_o)); } /* call far word ds:[0xB7A] */
L_fn_06BCF_000026:;
    mem_write16(cpu, cpu->ds, 0xB76, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xB76), 0x1))); /* add word ds:[0xB76], 0x1 */
    mem_write16(cpu, cpu->ds, 0xB78, (uint16_t)(flags_adc(cpu, mem_read16(cpu, cpu->ds, 0xB78), 0x0, 16))); /* adc word ds:[0xB78], 0x0 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x237C), 0x0); /* cmp word ds:[0x237C], 0x0 */
    if (cc_ne(cpu)) goto L_fn_06BCF_000048;  /* jne 0x0048 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x176E), 0x0); /* cmp word ds:[0x176E], 0x0 */
    if (cc_ne(cpu)) goto L_fn_06BCF_000045;  /* jne 0x0045 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1772), 0x0); /* cmp word ds:[0x1772], 0x0 */
    if (cc_e(cpu)) goto L_fn_06BCF_000048;   /* je 0x0048 */
L_fn_06BCF_000045:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C1A0(cpu);                           /* call 0x55D1 */
L_fn_06BCF_000048:;
    cpu->al = (uint8_t)(0x20);               /* mov al, 0x20 */
    port_out8(cpu, 0x20, cpu->al);           /* out 0x20, al */
    cpu->flags = pop16(cpu);                 /* popf */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->sp += 4; cpu->flags = pop16(cpu); return; /* iret */
}

void fn_06C26(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06C26");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xB76))); /* add ax, word ds:[0xB76] */
    cpu->dx = (uint16_t)(flags_adc(cpu, cpu->dx, mem_read16(cpu, cpu->ds, 0xB78), 16)); /* adc dx, word ds:[0xB78] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    goto L_fn_06C26_00001A;                  /* jmp 0x001A */
L_fn_06C26_00001A:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB78)); /* mov dx, word ds:[0xB78] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB76)); /* mov ax, word ds:[0xB76] */
    flags_cmp16(cpu, cpu->dx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* cmp dx, word ss:[bp+-0x2] */
    RECOMP_TICK(cpu);
    if (cc_b(cpu)) goto L_fn_06C26_00001A;   /* jb 0x001A */
    if (cc_ne(cpu)) goto L_fn_06C26_00002D;  /* jne 0x002D */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* cmp ax, word ss:[bp+-0x4] */
    RECOMP_TICK(cpu);
    if (cc_b(cpu)) goto L_fn_06C26_00001A;   /* jb 0x001A */
L_fn_06C26_00002D:;
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06C57(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06C57");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xB76))); /* add ax, word ds:[0xB76] */
    cpu->dx = (uint16_t)(flags_adc(cpu, cpu->dx, mem_read16(cpu, cpu->ds, 0xB78), 16)); /* adc dx, word ds:[0xB78] */
    mem_write16(cpu, cpu->ds, 0xC0D2, (uint16_t)(cpu->dx)); /* mov word ds:[0xC0D2], dx */
    mem_write16(cpu, cpu->ds, 0xC0D0, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0D0], ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06C6F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06C6F");
    goto L_fn_06C6F_000002;                  /* jmp 0x0002 */
L_fn_06C6F_000002:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB78)); /* mov dx, word ds:[0xB78] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB76)); /* mov ax, word ds:[0xB76] */
    flags_cmp16(cpu, cpu->dx, mem_read16(cpu, cpu->ds, 0xC0D2)); /* cmp dx, word ds:[0xC0D2] */
    RECOMP_TICK(cpu);
    if (cc_b(cpu)) goto L_fn_06C6F_000002;   /* jb 0x0002 */
    if (cc_ne(cpu)) goto L_fn_06C6F_000017;  /* jne 0x0017 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC0D0)); /* cmp ax, word ds:[0xC0D0] */
    RECOMP_TICK(cpu);
    if (cc_b(cpu)) goto L_fn_06C6F_000002;   /* jb 0x0002 */
L_fn_06C6F_000017:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_06C87(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06C87");
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB78)); /* mov dx, word ds:[0xB78] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB76)); /* mov ax, word ds:[0xB76] */
    flags_cmp16(cpu, cpu->dx, mem_read16(cpu, cpu->ds, 0xC0D2)); /* cmp dx, word ds:[0xC0D2] */
    if (cc_a(cpu)) goto L_fn_06C87_000019;   /* ja 0x0019 */
    if (cc_b(cpu)) goto L_fn_06C87_000015;   /* jb 0x0015 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC0D0)); /* cmp ax, word ds:[0xC0D0] */
    if (cc_ae(cpu)) goto L_fn_06C87_000019;  /* jae 0x0019 */
L_fn_06C87_000015:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_06C87_00001E;                  /* jmp 0x001E */
L_fn_06C87_000019:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_06C87_00001E;                  /* jmp 0x001E */
L_fn_06C87_00001E:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_06CA6(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06CA6");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->ds, 0xC0EA, (uint16_t)(cpu->bx)); /* mov word ds:[0xC0EA], bx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3F2A)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx - 0x3F2A) + 2)); cpu->si = _o; cpu->es = _s; } /* les si, word ds:[bx+-0x3F2A] */
    cpu->ax = (uint16_t)(cpu->es);           /* mov ax, es */
    mem_write16(cpu, cpu->ds, 0xC0E0, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0E0], ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    cpu->cx = (uint16_t)(cpu->ax);           /* mov cx, ax */
    cpu->cl = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->si + 0x1))); /* mov cl, byte es:[si+0x1] */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc cx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->si + 0x2))); /* mov al, byte es:[si+0x2] */
    mem_write16(cpu, cpu->ds, 0xC0E8, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0E8], ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x3)); /* add si, 0x3 */
    mem_write16(cpu, cpu->ds, 0xC0E4, (uint16_t)(cpu->si)); /* mov word ds:[0xC0E4], si */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->cx)); /* add si, cx */
    mem_write16(cpu, cpu->ds, 0xC0E6, (uint16_t)(cpu->si)); /* mov word ds:[0xC0E6], si */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->cx)); /* add si, cx */
    mem_write16(cpu, cpu->ds, 0xC0E2, (uint16_t)(cpu->si)); /* mov word ds:[0xC0E2], si */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->cx)); /* add si, cx */
    mem_write16(cpu, cpu->ds, 0xC0DE, (uint16_t)(cpu->si)); /* mov word ds:[0xC0DE], si */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06CEA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06CEA");
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0EA)); /* mov ax, word ds:[0xC0EA] */
    goto L_fn_06CEA_000005;                  /* jmp 0x0005 */
L_fn_06CEA_000005:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_06CF0(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06CF0");
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0E8)); /* mov ax, word ds:[0xC0E8] */
    goto L_fn_06CF0_000005;                  /* jmp 0x0005 */
L_fn_06CF0_000005:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_06CF6(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06CF6");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->cx = (uint16_t)(cpu->dx);           /* mov cx, dx */
    cpu->bx = (uint16_t)(cpu->dx);           /* mov bx, dx */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0E0)); /* mov ax, word ds:[0xC0E0] */
    cpu->es = (uint16_t)(cpu->ax);           /* mov es, ax */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0E4)); /* mov di, word ds:[0xC0E4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ss:[bp+0x4] */
L_fn_06CF6_000019:;
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    { uint8_t _r = cpu->al | cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, al */
    if (cc_e(cpu)) goto L_fn_06CF6_000039;   /* je 0x0039 */
    flags_cmp8(cpu, cpu->al, 0xA);           /* cmp al, 0xA */
    if (cc_e(cpu)) goto L_fn_06CF6_00002F;   /* je 0x002F */
    flags_cmp8(cpu, cpu->al, 0xD);           /* cmp al, 0xD */
    if (cc_e(cpu)) goto L_fn_06CF6_00002F;   /* je 0x002F */
    cpu->bl = (uint8_t)(cpu->al);            /* mov bl, al */
    cpu->bl = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->di))); /* mov bl, byte es:[bx+di] */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->bx)); /* add dx, bx */
    RECOMP_TICK(cpu);
    goto L_fn_06CF6_000019;                  /* jmp 0x0019 */
L_fn_06CF6_00002F:;
    flags_cmp16(cpu, cpu->dx, cpu->cx);      /* cmp dx, cx */
    if (cc_be(cpu)) goto L_fn_06CF6_000035;  /* jbe 0x0035 */
    cpu->cx = (uint16_t)(cpu->dx);           /* mov cx, dx */
L_fn_06CF6_000035:;
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    RECOMP_TICK(cpu);
    goto L_fn_06CF6_000019;                  /* jmp 0x0019 */
L_fn_06CF6_000039:;
    flags_cmp16(cpu, cpu->dx, cpu->cx);      /* cmp dx, cx */
    if (cc_be(cpu)) goto L_fn_06CF6_00003F;  /* jbe 0x003F */
    cpu->cx = (uint16_t)(cpu->dx);           /* mov cx, dx */
L_fn_06CF6_00003F:;
    cpu->ax = (uint16_t)(cpu->cx);           /* mov ax, cx */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06D3C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06D3C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    goto L_fn_06D3C_000034;                  /* jmp 0x0034 */
L_fn_06D3C_00000C:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1)), 0xA); /* cmp byte ss:[bp+-0x1], 0xA */
    if (cc_e(cpu)) goto L_fn_06D3C_000018;   /* je 0x0018 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1)), 0xD); /* cmp byte ss:[bp+-0x1], 0xD */
    if (cc_ne(cpu)) goto L_fn_06D3C_000023;  /* jne 0x0023 */
L_fn_06D3C_000018:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0E8)); /* mov ax, word ds:[0xC0E8] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)), cpu->ax))); /* add word ss:[bp+0x6], ax */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    goto L_fn_06D3C_000034;                  /* jmp 0x0034 */
L_fn_06D3C_000023:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C6);                           /* call 0x968A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
L_fn_06D3C_000034:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x8] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x1], al */
    { uint8_t _r = cpu->al | cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, al */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_06D3C_00000C;  /* jne 0x000C */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06D86(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06D86");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ss:[bp+0x8] */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    cpu->dx = (uint16_t)(cpu->di);           /* mov dx, di */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov ax, word ss:[bp+0xC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
L_fn_06D86_000017:;
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    flags_cmp16(cpu, cpu->ax, 0x0);          /* cmp ax, 0x0 */
    if (cc_g(cpu)) goto L_fn_06D86_00002C;   /* jg 0x002C */
    cpu->ax = (uint16_t)(flags_sub16(cpu, 0, cpu->ax)); /* neg ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    cpu->cx = (uint16_t)(cpu->ax);           /* mov cx, ax */
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    while (cpu->cx != 0) { cpu->cx--;        /* rep stosb */
        mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    }
    flags_cmp16(cpu, cpu->si, cpu->bx);      /* cmp si, bx */
    if (cc_ge(cpu)) goto L_fn_06D86_000034;  /* jge 0x0034 */
    RECOMP_TICK(cpu);
    goto L_fn_06D86_000017;                  /* jmp 0x0017 */
L_fn_06D86_00002C:;
    cpu->cx = (uint16_t)(cpu->ax);           /* mov cx, ax */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    flags_cmp16(cpu, cpu->si, cpu->bx);      /* cmp si, bx */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_06D86_000017;   /* jl 0x0017 */
L_fn_06D86_000034:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->dx)); /* sub ax, dx */
    cpu->flags &= ~FLAG_CF;                  /* clc */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06DCC(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06DCC");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ss:[bp+0x8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov ax, word ss:[bp+0xC] */
    cpu->bp = (uint16_t)(cpu->si);           /* mov bp, si */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 0x2)); /* sub ax, 0x2 */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    mem_write16(cpu, SEG_0000, 0x6DC7, (uint16_t)(cpu->ax)); /* mov word cs:[0x6DC7], ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x2)); /* add si, 0x2 */
    mem_write16(cpu, SEG_0000, 0x6DC9, (uint16_t)(0x0)); /* mov word cs:[0x6DC9], 0x0 */
    mem_write16(cpu, SEG_0000, 0x6DC5, (uint16_t)(0x9)); /* mov word cs:[0x6DC5], 0x9 */
L_fn_06DCC_00002E:;
    mem_write16(cpu, cpu->ds, cpu->bx, (uint16_t)(cpu->di)); /* mov word ds:[bx], di */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x2)); /* add bx, 0x2 */
L_fn_06DCC_000033:;
    push16(cpu, cpu->bx);                    /* push bx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, SEG_0000, 0x6DC9)); /* mov dx, word cs:[0x6DC9] */
    cpu->bl = (uint8_t)(mem_read8(cpu, SEG_0000, 0x6DCB)); /* mov bl, byte cs:[0x6DCB] */
    cpu->cx = (uint16_t)(mem_read16(cpu, SEG_0000, 0x6DC5)); /* mov cx, word cs:[0x6DC5] */
L_fn_06DCC_000045:;
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    flags_cmp16(cpu, cpu->dx, 0x0);          /* cmp dx, 0x0 */
    if (cc_l(cpu)) goto L_fn_06DCC_000053;   /* jl 0x0053 */
L_fn_06DCC_00004B:;
    { uint8_t _v = (uint8_t)cpu->bl; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 9; uint64_t _val = (uint64_t)_v | (cf(cpu) ? 0x100ull : 0ull); uint64_t _r = (((_val << _c) | (_val >> (9 - _c)))) & 0x1FFull; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (((_r >> 8) & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ (_r >> 8)) & 1) ? FLAG_OF : 0); cpu->bl = (uint8_t)((uint8_t)_r); } } /* rcl bl, 0x1 */
    { uint16_t _v = (uint16_t)cpu->ax; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 17; uint64_t _val = (uint64_t)_v | (cf(cpu) ? 0x10000ull : 0ull); uint64_t _r = (((_val << _c) | (_val >> (17 - _c)))) & 0x1FFFFull; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (((_r >> 16) & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ (_r >> 16)) & 1) ? FLAG_OF : 0); cpu->ax = (uint16_t)((uint16_t)_r); } } /* rcl ax, 0x1 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_06DCC_000045; /* loop 0x0045 */
    goto L_fn_06DCC_000060;                  /* jmp 0x0060 */
L_fn_06DCC_000053:;
    cpu->bl = (uint8_t)(mem_read8(cpu, cpu->ds, cpu->si)); /* mov bl, byte ds:[si] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->dx = (uint16_t)(0x7);               /* mov dx, 0x7 */
    { int _cf = cf(cpu); mem_write16(cpu, SEG_0000, 0x6DC7, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, SEG_0000, 0x6DC7), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word cs:[0x6DC7] */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_06DCC_00004B;  /* jne 0x004B */
L_fn_06DCC_000060:;
    mem_write16(cpu, SEG_0000, 0x6DC9, (uint16_t)(cpu->dx)); /* mov word cs:[0x6DC9], dx */
    mem_write8(cpu, SEG_0000, 0x6DCB, (uint8_t)(cpu->bl)); /* mov byte cs:[0x6DCB], bl */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    flags_cmp16(cpu, cpu->ax, 0x100);        /* cmp ax, 0x100 */
    if (cc_ne(cpu)) goto L_fn_06DCC_000077;  /* jne 0x0077 */
    { int _cf = cf(cpu); mem_write16(cpu, SEG_0000, 0x6DC5, (uint16_t)(flags_add16(cpu, mem_read16(cpu, SEG_0000, 0x6DC5), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word cs:[0x6DC5] */
    RECOMP_TICK(cpu);
    goto L_fn_06DCC_000033;                  /* jmp 0x0033 */
L_fn_06DCC_000077:;
    flags_cmp16(cpu, mem_read16(cpu, SEG_0000, 0x6DC7), 0x0); /* cmp word cs:[0x6DC7], 0x0 */
    if (cc_ne(cpu)) goto L_fn_06DCC_000082;  /* jne 0x0082 */
    goto L_fn_06DCC_00012B;                  /* jmp 0x012B */
L_fn_06DCC_000082:;
    flags_cmp16(cpu, cpu->ax, 0xFF);         /* cmp ax, 0xFF */
    if (cc_le(cpu)) goto L_fn_06DCC_0000AE;  /* jle 0x00AE */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 0x101)); /* sub ax, 0x101 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->bp)); /* add ax, bp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, cpu->si)); /* mov ax, word ds:[si] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x2))); /* mov cx, word ds:[si+0x2] */
    cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, cpu->ax)); /* sub cx, ax */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->dx = (uint16_t)(cpu->ds);           /* mov dx, ds */
    push16(cpu, cpu->es);                    /* push es */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    flags_logic16(cpu, cpu->cx & 0x1);       /* test cx, 0x1 */
    if (cc_e(cpu)) goto L_fn_06DCC_0000A5;   /* je 0x00A5 */
    mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
L_fn_06DCC_0000A5:;
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsw */
        mem_write16(cpu, cpu->es, cpu->di, mem_read16(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -2 : 2; cpu->di += df(cpu) ? -2 : 2; /* movsw */
    }
    cpu->ds = (uint16_t)(cpu->dx);           /* mov ds, dx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    goto L_fn_06DCC_0000AF;                  /* jmp 0x00AF */
L_fn_06DCC_0000AE:;
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
L_fn_06DCC_0000AF:;
    push16(cpu, cpu->bx);                    /* push bx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, SEG_0000, 0x6DC9)); /* mov dx, word cs:[0x6DC9] */
    cpu->bl = (uint8_t)(mem_read8(cpu, SEG_0000, 0x6DCB)); /* mov bl, byte cs:[0x6DCB] */
    cpu->cx = (uint16_t)(mem_read16(cpu, SEG_0000, 0x6DC5)); /* mov cx, word cs:[0x6DC5] */
L_fn_06DCC_0000C1:;
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    flags_cmp16(cpu, cpu->dx, 0x0);          /* cmp dx, 0x0 */
    if (cc_l(cpu)) goto L_fn_06DCC_0000CF;   /* jl 0x00CF */
L_fn_06DCC_0000C7:;
    { uint8_t _v = (uint8_t)cpu->bl; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 9; uint64_t _val = (uint64_t)_v | (cf(cpu) ? 0x100ull : 0ull); uint64_t _r = (((_val << _c) | (_val >> (9 - _c)))) & 0x1FFull; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (((_r >> 8) & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ (_r >> 8)) & 1) ? FLAG_OF : 0); cpu->bl = (uint8_t)((uint8_t)_r); } } /* rcl bl, 0x1 */
    { uint16_t _v = (uint16_t)cpu->ax; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 17; uint64_t _val = (uint64_t)_v | (cf(cpu) ? 0x10000ull : 0ull); uint64_t _r = (((_val << _c) | (_val >> (17 - _c)))) & 0x1FFFFull; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (((_r >> 16) & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ (_r >> 16)) & 1) ? FLAG_OF : 0); cpu->ax = (uint16_t)((uint16_t)_r); } } /* rcl ax, 0x1 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_06DCC_0000C1; /* loop 0x00C1 */
    goto L_fn_06DCC_0000DC;                  /* jmp 0x00DC */
L_fn_06DCC_0000CF:;
    cpu->bl = (uint8_t)(mem_read8(cpu, cpu->ds, cpu->si)); /* mov bl, byte ds:[si] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->dx = (uint16_t)(0x7);               /* mov dx, 0x7 */
    { int _cf = cf(cpu); mem_write16(cpu, SEG_0000, 0x6DC7, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, SEG_0000, 0x6DC7), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word cs:[0x6DC7] */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_06DCC_0000C7;  /* jne 0x00C7 */
L_fn_06DCC_0000DC:;
    mem_write16(cpu, SEG_0000, 0x6DC9, (uint16_t)(cpu->dx)); /* mov word cs:[0x6DC9], dx */
    mem_write8(cpu, SEG_0000, 0x6DCB, (uint8_t)(cpu->bl)); /* mov byte cs:[0x6DCB], bl */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    flags_cmp16(cpu, cpu->ax, 0x100);        /* cmp ax, 0x100 */
    if (cc_ne(cpu)) goto L_fn_06DCC_0000F3;  /* jne 0x00F3 */
    { int _cf = cf(cpu); mem_write16(cpu, SEG_0000, 0x6DC5, (uint16_t)(flags_add16(cpu, mem_read16(cpu, SEG_0000, 0x6DC5), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word cs:[0x6DC5] */
    RECOMP_TICK(cpu);
    goto L_fn_06DCC_0000AF;                  /* jmp 0x00AF */
L_fn_06DCC_0000F3:;
    flags_cmp16(cpu, mem_read16(cpu, SEG_0000, 0x6DC7), 0x0); /* cmp word cs:[0x6DC7], 0x0 */
    if (cc_e(cpu)) goto L_fn_06DCC_00012B;   /* je 0x012B */
    flags_cmp16(cpu, cpu->ax, 0xFF);         /* cmp ax, 0xFF */
    if (cc_le(cpu)) goto L_fn_06DCC_000127;  /* jle 0x0127 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 0x101)); /* sub ax, 0x101 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->bp)); /* add ax, bp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, cpu->si)); /* mov ax, word ds:[si] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x2))); /* mov cx, word ds:[si+0x2] */
    cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, cpu->ax)); /* sub cx, ax */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->dx = (uint16_t)(cpu->ds);           /* mov dx, ds */
    push16(cpu, cpu->es);                    /* push es */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    flags_logic16(cpu, cpu->cx & 0x1);       /* test cx, 0x1 */
    if (cc_e(cpu)) goto L_fn_06DCC_00011E;   /* je 0x011E */
    mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
L_fn_06DCC_00011E:;
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsw */
        mem_write16(cpu, cpu->es, cpu->di, mem_read16(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -2 : 2; cpu->di += df(cpu) ? -2 : 2; /* movsw */
    }
    cpu->ds = (uint16_t)(cpu->dx);           /* mov ds, dx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    goto L_fn_06DCC_000128;                  /* jmp 0x0128 */
L_fn_06DCC_000127:;
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
L_fn_06DCC_000128:;
    RECOMP_TICK(cpu);
    goto L_fn_06DCC_00002E;                  /* jmp 0x002E */
L_fn_06DCC_00012B:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06EFF(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06EFF");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(cpu->es);           /* mov ax, es */
    cpu->ds = (uint16_t)(cpu->ax);           /* mov ds, ax */
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    cpu->cx = (uint16_t)(0x8);               /* mov cx, 0x8 */
L_fn_06EFF_000013:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->di)); /* mov ax, word es:[di] */
    { uint16_t _r = cpu->ax & 0xF0F; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF0F */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_06EFF_000013; /* loop 0x0013 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x10)); /* add di, 0x10 */
    cpu->si = (uint16_t)(cpu->di);           /* mov si, di */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    { uint16_t _r = (uint16_t)cpu->al * cpu->ah; cpu->ax = _r; cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (_r > 0xFF ? FLAG_CF|FLAG_OF : 0); } /* mul ah */
    cpu->cx = (uint16_t)(cpu->ax);           /* mov cx, ax */
    cpu->di = (uint16_t)(cpu->si);           /* mov di, si */
L_fn_06EFF_000028:;
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    { uint16_t _r = cpu->ax & 0xF00F; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF00F */
    cpu->al = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    { uint16_t _t = cpu->al; cpu->al = (uint8_t)(cpu->ah); cpu->ah = (uint8_t)(_t); } /* xchg al, ah */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    cpu->al = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _r = cpu->al | cpu->ah; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, ah */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_06EFF_000028; /* loop 0x0028 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06F4B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06F4B");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->ds = _s; } /* lds bx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(cpu->ds);           /* mov ax, ds */
    cpu->es = (uint16_t)(cpu->ax);           /* mov es, ax */
    cpu->di = (uint16_t)(cpu->bx);           /* mov di, bx */
    { uint8_t _r = cpu->al ^ cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* xor al, al */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    cpu->cx = (uint16_t)(0xF);               /* mov cx, 0xF */
L_fn_06F4B_00001A:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->di)); /* mov al, byte es:[di] */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    { uint16_t _r = cpu->ax & 0xC030; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xC030 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1001)); /* add ax, 0x1001 */
    { uint8_t _r = cpu->al | cpu->ah; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, ah */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_06F4B_00001A; /* loop 0x001A */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x10)); /* add di, 0x10 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->di)); /* mov ax, word es:[di] */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->dh = (uint8_t)(cpu->al);            /* mov dh, al */
    { uint16_t _r = (uint16_t)cpu->al * cpu->ah; cpu->ax = _r; cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (_r > 0xFF ? FLAG_CF|FLAG_OF : 0); } /* mul ah */
    cpu->bp = (uint16_t)(cpu->ax);           /* mov bp, ax */
    { uint8_t _r = cpu->cl ^ cpu->cl; flags_logic8(cpu, _r); cpu->cl = (uint8_t)(_r); } /* xor cl, cl */
    cpu->dl = (uint8_t)(cpu->dh);            /* mov dl, dh */
L_fn_06F4B_000044:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->di)); /* mov al, byte es:[di] */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    { uint16_t _r = cpu->ax & 0xFF0; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xFF0 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shr al, 0x1 */
    cpu->al = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    { uint8_t _v = (uint8_t)cpu->al; uint8_t _n = (cpu->cl) & 0x1F; if (_n) { uint8_t _c = _n % 8; uint8_t _r = (_c ? (uint8_t)((_v << _c) | (_v >> (8 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->al = (uint8_t)(_r); } } /* rol al, cl */
    { uint16_t _t = cpu->ah; cpu->ah = (uint8_t)(cpu->al); cpu->al = (uint8_t)(_t); } /* xchg ah, al */
    cpu->al = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    { uint8_t _v = (uint8_t)cpu->al; uint8_t _n = (cpu->cl) & 0x1F; if (_n) { uint8_t _c = _n % 8; uint8_t _r = (_c ? (uint8_t)((_v << _c) | (_v >> (8 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->al = (uint8_t)(_r); } } /* rol al, cl */
    { uint16_t _r = cpu->ax & 0xF00F; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF00F */
    { uint8_t _r = cpu->al | cpu->ah; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, ah */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    { int _cf = cf(cpu); cpu->bp = (uint16_t)(flags_sub16(cpu, cpu->bp, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec bp */
    if (cc_e(cpu)) goto L_fn_06F4B_000070;   /* je 0x0070 */
    { int _cf = cf(cpu); cpu->dl = (uint8_t)(flags_sub8(cpu, cpu->dl, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dl */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_06F4B_000044;  /* jne 0x0044 */
    cpu->dl = (uint8_t)(cpu->dh);            /* mov dl, dh */
    { uint8_t _r = cpu->cl ^ 0x4; flags_logic8(cpu, _r); cpu->cl = (uint8_t)(_r); } /* xor cl, 0x4 */
    RECOMP_TICK(cpu);
    goto L_fn_06F4B_000044;                  /* jmp 0x0044 */
L_fn_06F4B_000070:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06FC3(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06FC3");
    mem_write16(cpu, cpu->ds, 0xB83, (uint16_t)(0x0)); /* mov word ds:[0xB83], 0x0 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06FCA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06FCA");
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xC0EE);            /* mov ax, 0xC0EE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x3F);              /* mov ax, 0x3F */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0xF880 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06FDA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06FDA");
    mem_write16(cpu, cpu->ds, 0xC0FA, (uint16_t)(0x0)); /* mov word ds:[0xC0FA], 0x0 */
    mem_write16(cpu, cpu->ds, 0xB83, (uint16_t)(0x1)); /* mov word ds:[0xB83], 0x1 */
    mem_write16(cpu, cpu->ds, 0xC0FC, (uint16_t)(0x1)); /* mov word ds:[0xC0FC], 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC0EE); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC0EE + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC0EE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0F0)); /* mov cx, word ds:[0xC0F0] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0EE)); /* mov bx, word ds:[0xC0EE] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0xA2);              /* mov ax, 0xA2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x93EF */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07202(cpu);                           /* call 0x0228 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07298(cpu);                           /* call 0x02BE */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0738A(cpu);                           /* call 0x03B0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07417(cpu);                           /* call 0x043D */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07443(cpu);                           /* call 0x0469 */
    cpu->ax = (uint16_t)(0x24);              /* mov ax, 0x24 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA2);              /* mov ax, 0xA2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x93C5 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0747B(cpu);                           /* call 0x04A1 */
    mem_write16(cpu, cpu->ds, 0xC0FA, (uint16_t)(0x1)); /* mov word ds:[0xC0FA], 0x1 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0703E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0703E");
    push16(cpu, cpu->si);                    /* push si */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0xB85, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xB85), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0xB85] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0020F(cpu);                           /* call 0x91D1 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB83)); /* mov ax, word ds:[0xB83] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    flags_cmp16(cpu, cpu->ax, 0x4);          /* cmp ax, 0x4 */
    if (cc_be(cpu)) goto L_fn_0703E_000016;  /* jbe 0x0016 */
    recomp_dispatch(cpu, 0x715, 0xB); return; /* tail-jmp 0x00715B */ /* jmp 0x011D */
L_fn_0703E_000016:;
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x705D))); return; /* jmp word cs:[bx+0x705D] */
    if (cc_o(cpu)) { recomp_dispatch(cpu, 0x16FF, 0xE); return; } /* tail-jcc 0x016FFE */ /* jo 0xFFC0 */
    if (cc_o(cpu)) { recomp_dispatch(cpu, 0x1703, 0x7); return; } /* tail-jcc 0x017037 */ /* jo 0xFFF9 */
    if (cc_o(cpu)) { recomp_dispatch(cpu, 0x70B, 0xF); return; } /* tail-jcc 0x0070BF */ /* jo 0x0081 */
    if (cc_no(cpu)) { recomp_dispatch(cpu, 0x706, 0xE); return; } /* tail-jcc 0x00706E */ /* jno 0x0030 */
    recomp_dispatch(cpu, 0x706, 0x6); return; /* fallthrough 0x007066 */
}

void fn_07067(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07067");
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0FC)); /* push word ds:[0xC0FC] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x9167 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x66);              /* mov ax, 0x66 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xB8);              /* mov ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xE);               /* mov ax, 0xE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0x9341 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x66);              /* mov ax, 0x66 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xB8);              /* mov ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xE);               /* mov ax, 0xE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x9338 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    recomp_dispatch(cpu, 0x715, 0xB); return; /* tail-jmp 0x00715B */ /* jmp 0x00F4 */
}

void fn_070D5(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_070D5");
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x90F9 */
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
    ovl_call(cpu, 0x03A8);                           /* call 0x92D3 */
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
    ovl_call(cpu, 0x039F);                           /* call 0x92CA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    goto L_fn_070D5_000086;                  /* jmp 0x0086 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x90F9 */
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
    fn_00355(cpu);                           /* call 0x9280 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0FC)); /* push word ds:[0xC0FC] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x90F9 */
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
    ovl_call(cpu, 0x03A8);                           /* call 0x92D3 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x24);              /* mov ax, 0x24 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x134);             /* mov ax, 0x134 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA2);              /* mov ax, 0xA2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x92CA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    goto L_fn_070D5_000086;                  /* jmp 0x0086 */
L_fn_070D5_000086:;
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x90F9 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07162(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07162");
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0xB85, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0xB85), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ds:[0xB85] */
    if (cc_ge(cpu)) goto L_fn_07162_00000E;  /* jge 0x000E */
L_fn_07162_000006:;
    mem_write16(cpu, cpu->ds, 0xB85, (uint16_t)(0x0)); /* mov word ds:[0xB85], 0x0 */
    goto L_fn_07162_000018;                  /* jmp 0x0018 */
L_fn_07162_00000E:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB85), 0x0); /* cmp word ds:[0xB85], 0x0 */
    if (cc_e(cpu)) goto L_fn_07162_000018;   /* je 0x0018 */
    recomp_dispatch(cpu, 0x71F, 0xA); return; /* tail-jmp 0x0071FA */ /* jmp 0x0098 */
L_fn_07162_000018:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB83)); /* mov ax, word ds:[0xB83] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    flags_cmp16(cpu, cpu->ax, 0x4);          /* cmp ax, 0x4 */
    if (cc_a(cpu)) { recomp_dispatch(cpu, 0x71F, 0xA); return; } /* tail-jcc 0x0071FA */ /* ja 0x0098 */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x718C))); return; /* jmp word cs:[bx+0x718C] */
    { uint16_t _t = cpu->ax; cpu->ax = (uint16_t)(cpu->si); cpu->si = (uint16_t)(_t); } /* xchg ax, si */
L_fn_07162_00002B:;
    if (cc_no(cpu)) { recomp_dispatch(cpu, 0x1716, 0x1); return; } /* tail-jcc 0x017161 */ /* jno 0xFFFF */
    RECOMP_TICK(cpu);
    if (cc_no(cpu)) goto L_fn_07162_000006;  /* jno 0x0006 */
    RECOMP_TICK(cpu);
    if (cc_no(cpu)) goto L_fn_07162_00002B;  /* jno 0x002B */
    if (cc_no(cpu)) { recomp_dispatch(cpu, 0x717, 0xB); return; } /* tail-jcc 0x00717B */ /* jno 0x0019 */
    if (cc_no(cpu)) { recomp_dispatch(cpu, 0x1715, 0xB); return; } /* tail-jcc 0x01715B */ /* jno 0xFFF9 */
    push16(cpu, cpu->ds);                    /* push ds */
    port_out8(cpu, cpu->dx, cpu->al);        /* out dx, al */
    { uint8_t _v = mem_read8(cpu, cpu->ds, 0x478B); uint8_t _c = (0x4) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); mem_write8(cpu, cpu->ds, 0x478B, (uint8_t)(_r)); } } /* shl byte ds:[0x478B], 0x4 */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0F0)); /* mov cx, word ds:[0xC0F0] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0EE)); /* mov bx, word ds:[0xC0EE] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0xB8);              /* mov ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xE);               /* mov ax, 0xE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x9267 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x66);              /* mov ax, 0x66 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xB8);              /* mov ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xE);               /* mov ax, 0xE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x923D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    recomp_dispatch(cpu, 0x71F, 0xA); return; /* tail-jmp 0x0071FA */ /* jmp 0x0098 */
}

void fn_071D7(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_071D7");
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0F8)); /* push word ds:[0xC0F8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0F6)); /* push word ds:[0xC0F6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07695(cpu);                           /* call 0x04BE */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_071D7_000023;                  /* jmp 0x0023 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0EC)); /* push word ds:[0xC0EC] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0F4)); /* push word ds:[0xC0F4] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0F2)); /* push word ds:[0xC0F2] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07856(cpu);                           /* call 0x067F */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    goto L_fn_071D7_000023;                  /* jmp 0x0023 */
L_fn_071D7_000023:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_071FB(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_071FB");
    mem_write16(cpu, cpu->ds, 0xB85, (uint16_t)(0x0)); /* mov word ds:[0xB85], 0x0 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07202(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07202");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(0x10);              /* mov di, 0x10 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08BA5(cpu);                           /* call 0x19A3 */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0012; recomp_div0("idiv16"); } } /* idiv bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_07202_000040;                  /* jmp 0x0040 */
L_fn_07202_00001B:;
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC0EE); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC0EE + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC0EE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov ax, word es:[bx+0x2] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0F0)); /* mov cx, word ds:[0xC0F0] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0EE)); /* mov bx, word ds:[0xC0EE] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0xB0);              /* mov ax, 0xB0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x91C7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x12)); /* add di, 0x12 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_07202_000040:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* cmp si, word ss:[bp+-0x2] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_07202_00001B;   /* jl 0x001B */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC0FA), 0x0); /* cmp word ds:[0xC0FA], 0x0 */
    if (cc_e(cpu)) goto L_fn_07202_000062;   /* je 0x0062 */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6A);              /* mov ax, 0x6A */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xB0);              /* mov ax, 0xB0 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x919D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_07202_000062:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0726A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0726A");
    mem_write16(cpu, cpu->ds, 0xB7E, (uint16_t)(0x0)); /* mov word ds:[0xB7E], 0x0 */
    mem_write16(cpu, cpu->ds, 0xB80, (uint16_t)(0x4)); /* mov word ds:[0xB80], 0x4 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_07277(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_07277");
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xB7E)); /* mov ax, word ds:[0xB7E] */
    goto L_fn_07277_000005;                  /* jmp 0x0005 */
L_fn_07277_000005:;
    cpu->sp += 2; return;                    /* ret */
}
