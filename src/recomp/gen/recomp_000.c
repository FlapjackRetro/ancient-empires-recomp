#include "recomp_all.h"

void fn_00000(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_00000");
    cpu->dx = (uint16_t)(0x1FA3);            /* mov dx, 0x1FA3 */
    mem_write16(cpu, SEG_0000, 0x1BA, (uint16_t)(cpu->dx)); /* mov word cs:[0x1BA], dx */
    cpu->ah = (uint8_t)(0x30);               /* mov ah, 0x30 */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->bp = (uint16_t)(mem_read16(cpu, cpu->ds, 0x2)); /* mov bp, word ds:[0x2] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x2C)); /* mov bx, word ds:[0x2C] */
    cpu->ds = (uint16_t)(cpu->dx);           /* mov ds, dx */
    mem_write16(cpu, cpu->ds, 0x7D, (uint16_t)(cpu->ax)); /* mov word ds:[0x7D], ax */
    mem_write16(cpu, cpu->ds, 0x7B, (uint16_t)(cpu->es)); /* mov word ds:[0x7B], es */
    mem_write16(cpu, cpu->ds, 0x77, (uint16_t)(cpu->bx)); /* mov word ds:[0x77], bx */
    mem_write16(cpu, cpu->ds, 0x91, (uint16_t)(cpu->bp)); /* mov word ds:[0x91], bp */
    mem_write16(cpu, cpu->ds, 0x81, (uint16_t)(0xFFFF)); /* mov word ds:[0x81], 0xFFFF */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00124(cpu);                           /* call 0x0124 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x75); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x75 + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[0x75] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->cx = (uint16_t)(0x7FFF);            /* mov cx, 0x7FFF */
L_fn_00000_000039:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->es, cpu->di), 0x3738); /* cmp word es:[di], 0x3738 */
    if (cc_ne(cpu)) goto L_fn_00000_000059;  /* jne 0x0059 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->di + 0x2))); /* mov dx, word es:[di+0x2] */
    flags_cmp8(cpu, cpu->dl, 0x3D);          /* cmp dl, 0x3D */
    if (cc_ne(cpu)) goto L_fn_00000_000059;  /* jne 0x0059 */
    { uint8_t _r = cpu->dh & 0xDF; flags_logic8(cpu, _r); cpu->dh = (uint8_t)(_r); } /* and dh, 0xDF */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x81, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x81), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x81] */
    flags_cmp8(cpu, cpu->dh, 0x59);          /* cmp dh, 0x59 */
    if (cc_ne(cpu)) goto L_fn_00000_000059;  /* jne 0x0059 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x81, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x81), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x81] */
L_fn_00000_000059:;
    while (cpu->cx != 0) { cpu->cx--;        /* repnz scasb */
        flags_cmp8(cpu, cpu->al, mem_read8(cpu, cpu->es, cpu->di)); cpu->di += df(cpu) ? -1 : 1; /* scasb */
        if (zf(cpu)) break;
    }
    if (cpu->cx == 0) goto L_fn_00000_000099; /* jcxz 0x0099 */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->di), cpu->al); /* cmp byte es:[di], al */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_00000_000039;  /* jne 0x0039 */
    { uint8_t _r = cpu->ch | 0x80; flags_logic8(cpu, _r); cpu->ch = (uint8_t)(_r); } /* or ch, 0x80 */
    cpu->cx = (uint16_t)(flags_sub16(cpu, 0, cpu->cx)); /* neg cx */
    mem_write16(cpu, cpu->ds, 0x75, (uint16_t)(cpu->cx)); /* mov word ds:[0x75], cx */
    cpu->cx = (uint16_t)(0x2);               /* mov cx, 0x2 */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, cl */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x10)); /* add bx, 0x10 */
    { uint16_t _r = cpu->bx & 0xFFF0; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* and bx, 0xFFF0 */
    mem_write16(cpu, cpu->ds, 0x79, (uint16_t)(cpu->bx)); /* mov word ds:[0x79], bx */
    cpu->dx = (uint16_t)(cpu->ss);           /* mov dx, ss */
    cpu->bp = (uint16_t)(flags_sub16(cpu, cpu->bp, cpu->dx)); /* sub bp, dx */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37B8)); /* mov di, word ds:[0x37B8] */
    flags_cmp16(cpu, cpu->di, 0x200);        /* cmp di, 0x200 */
    if (cc_ae(cpu)) goto L_fn_00000_000090;  /* jae 0x0090 */
    cpu->di = (uint16_t)(0x200);             /* mov di, 0x200 */
    mem_write16(cpu, cpu->ds, 0x37B8, (uint16_t)(cpu->di)); /* mov word ds:[0x37B8], di */
L_fn_00000_000090:;
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->di; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shr di, cl */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    flags_cmp16(cpu, cpu->bp, cpu->di);      /* cmp bp, di */
    if (cc_ae(cpu)) goto L_fn_00000_00009C;  /* jae 0x009C */
L_fn_00000_000099:;
    goto L_fn_00000_0001A4;                  /* jmp 0x01A4 */
L_fn_00000_00009C:;
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->dx)); /* add bx, dx */
    mem_write16(cpu, cpu->ds, 0x89, (uint16_t)(cpu->bx)); /* mov word ds:[0x89], bx */
    mem_write16(cpu, cpu->ds, 0x8D, (uint16_t)(cpu->bx)); /* mov word ds:[0x8D], bx */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x7B)); /* mov ax, word ds:[0x7B] */
    cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, cpu->ax)); /* sub bx, ax */
    cpu->es = (uint16_t)(cpu->ax);           /* mov es, ax */
    cpu->ah = (uint8_t)(0x4A);               /* mov ah, 0x4A */
    push16(cpu, cpu->di);                    /* push di */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    { uint16_t _v = cpu->di; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, cl */
    cpu->flags &= ~FLAG_IF;                  /* cli */
    cpu->ss = (uint16_t)(cpu->dx);           /* mov ss, dx */
    cpu->sp = (uint16_t)(cpu->di);           /* mov sp, di */
    cpu->flags |= FLAG_IF;                   /* sti */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    cpu->es = (uint16_t)(mem_read16(cpu, SEG_0000, 0x1BA)); /* mov es, word cs:[0x1BA] */
    cpu->di = (uint16_t)(0x3902);            /* mov di, 0x3902 */
    cpu->cx = (uint16_t)(0xCAC8);            /* mov cx, 0xCAC8 */
    cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, cpu->di)); /* sub cx, di */
    while (cpu->cx != 0) { cpu->cx--;        /* rep stosb */
        mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    }
    push16(cpu, SEG_0000);                   /* push cs */
    push16(cpu,0xFFFF); dispatch_near(cpu, SEG_0000, mem_read16(cpu, cpu->ds, 0x38FC)); /* call word ds:[0x38FC] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E65C(cpu);                           /* call 0xE65C */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E753(cpu);                           /* call 0xE753 */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    int_handler(cpu, 0x1A);                  /* int 0x1A */
    mem_write16(cpu, cpu->ds, 0x83, (uint16_t)(cpu->dx)); /* mov word ds:[0x83], dx */
    mem_write16(cpu, cpu->ds, 0x85, (uint16_t)(cpu->cx)); /* mov word ds:[0x85], cx */
    push16(cpu,0xFFFF); dispatch_near(cpu, SEG_0000, mem_read16(cpu, cpu->ds, 0x3900)); /* call word ds:[0x3900] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x73)); /* push word ds:[0x73] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x71)); /* push word ds:[0x71] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x6F)); /* push word ds:[0x6F] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x6D)); /* push word ds:[0x6D] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x6B)); /* push word ds:[0x6B] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04A93(cpu);                           /* call 0x4A93 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E627(cpu);                           /* call 0xE627 */
    cpu->ds = (uint16_t)(mem_read16(cpu, SEG_0000, 0x1BA)); /* mov ds, word cs:[0x1BA] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00167(cpu);                           /* call 0x0167 */
    push16(cpu, SEG_0000);                   /* push cs */
    push16(cpu,0xFFFF); dispatch_near(cpu, SEG_0000, mem_read16(cpu, cpu->ds, 0x38FE)); /* call word ds:[0x38FE] */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ah = (uint8_t)(0x4C);               /* mov ah, 0x4C */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x2))); /* mov al, byte ss:[bp+0x2] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->cx = (uint16_t)(0xE);               /* mov cx, 0xE */
    /* nop */                                /* nop */
    cpu->dx = (uint16_t)(0x2F);              /* mov dx, 0x2F */
    goto L_fn_00000_0001AB;                  /* jmp 0x01AB */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x3500);            /* mov ax, 0x3500 */
    dos_int21(cpu);                          /* int 0x21 */
    mem_write16(cpu, cpu->ds, 0x5B, (uint16_t)(cpu->bx)); /* mov word ds:[0x5B], bx */
    mem_write16(cpu, cpu->ds, 0x5D, (uint16_t)(cpu->es)); /* mov word ds:[0x5D], es */
    cpu->ax = (uint16_t)(0x3504);            /* mov ax, 0x3504 */
    dos_int21(cpu);                          /* int 0x21 */
    mem_write16(cpu, cpu->ds, 0x5F, (uint16_t)(cpu->bx)); /* mov word ds:[0x5F], bx */
    mem_write16(cpu, cpu->ds, 0x61, (uint16_t)(cpu->es)); /* mov word ds:[0x61], es */
    cpu->ax = (uint16_t)(0x3505);            /* mov ax, 0x3505 */
    dos_int21(cpu);                          /* int 0x21 */
    mem_write16(cpu, cpu->ds, 0x63, (uint16_t)(cpu->bx)); /* mov word ds:[0x63], bx */
    mem_write16(cpu, cpu->ds, 0x65, (uint16_t)(cpu->es)); /* mov word ds:[0x65], es */
    cpu->ax = (uint16_t)(0x3506);            /* mov ax, 0x3506 */
    dos_int21(cpu);                          /* int 0x21 */
    mem_write16(cpu, cpu->ds, 0x67, (uint16_t)(cpu->bx)); /* mov word ds:[0x67], bx */
    mem_write16(cpu, cpu->ds, 0x69, (uint16_t)(cpu->es)); /* mov word ds:[0x69], es */
    cpu->ax = (uint16_t)(0x2500);            /* mov ax, 0x2500 */
    cpu->dx = (uint16_t)(SEG_0000);          /* mov dx, cs */
    cpu->ds = (uint16_t)(cpu->dx);           /* mov ds, dx */
    cpu->dx = (uint16_t)(0x11A);             /* mov dx, 0x11A */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->sp += 2; return;                    /* ret */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x2500);            /* mov ax, 0x2500 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x5B); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x5B + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ds:[0x5B] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x2504);            /* mov ax, 0x2504 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x5F); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x5F + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ds:[0x5F] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x2505);            /* mov ax, 0x2505 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x63); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x63 + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ds:[0x63] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x2506);            /* mov ax, 0x2506 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x67); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x67 + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ds:[0x67] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->sp += 2; return;                    /* ret */
    mem_write16(cpu, cpu->ds, 0x81, (uint16_t)(0x0)); /* mov word ds:[0x81], 0x0 */
    { uint16_t _ip=pop16(cpu); uint16_t _cs=pop16(cpu); if (_ip != 0xFFFF && _ip != 0) recomp_dispatch(cpu,_cs,_ip); return; } /* retf */
    cpu->sp += 2; return;                    /* ret */
    cpu->ah = (uint8_t)(0x40);               /* mov ah, 0x40 */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->sp += 2; return;                    /* ret */
L_fn_00000_0001A4:;
    cpu->cx = (uint16_t)(0x1E);              /* mov cx, 0x1E */
    /* nop */                                /* nop */
    cpu->dx = (uint16_t)(0x3D);              /* mov dx, 0x3D */
L_fn_00000_0001AB:;
    cpu->ds = (uint16_t)(mem_read16(cpu, SEG_0000, 0x1BA)); /* mov ds, word cs:[0x1BA] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0019C(cpu);                           /* call 0x019C */
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00104(cpu);                           /* call 0x0104 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si)), cpu->al))); /* add byte ds:[bx+si], al */
    fn_001BC(cpu); return;                   /* fallthrough 0x0001BC */
}

void fn_00104(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_00104");
    cpu->ds = (uint16_t)(mem_read16(cpu, SEG_0000, 0x1BA)); /* mov ds, word cs:[0x1BA] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00167(cpu);                           /* call 0x0063 */
    push16(cpu, SEG_0000);                   /* push cs */
    push16(cpu,0xFFFF); dispatch_near(cpu, SEG_0000, mem_read16(cpu, cpu->ds, 0x38FE)); /* call word ds:[0x38FE] */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ah = (uint8_t)(0x4C);               /* mov ah, 0x4C */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x2))); /* mov al, byte ss:[bp+0x2] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->cx = (uint16_t)(0xE);               /* mov cx, 0xE */
    /* nop */                                /* nop */
    cpu->dx = (uint16_t)(0x2F);              /* mov dx, 0x2F */
    recomp_dispatch(cpu, 0x1A, 0xB); return; /* tail-jmp 0x0001AB */ /* jmp 0x00A7 */
}

void fn_00124(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_00124");
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x3500);            /* mov ax, 0x3500 */
    dos_int21(cpu);                          /* int 0x21 */
    mem_write16(cpu, cpu->ds, 0x5B, (uint16_t)(cpu->bx)); /* mov word ds:[0x5B], bx */
    mem_write16(cpu, cpu->ds, 0x5D, (uint16_t)(cpu->es)); /* mov word ds:[0x5D], es */
    cpu->ax = (uint16_t)(0x3504);            /* mov ax, 0x3504 */
    dos_int21(cpu);                          /* int 0x21 */
    mem_write16(cpu, cpu->ds, 0x5F, (uint16_t)(cpu->bx)); /* mov word ds:[0x5F], bx */
    mem_write16(cpu, cpu->ds, 0x61, (uint16_t)(cpu->es)); /* mov word ds:[0x61], es */
    cpu->ax = (uint16_t)(0x3505);            /* mov ax, 0x3505 */
    dos_int21(cpu);                          /* int 0x21 */
    mem_write16(cpu, cpu->ds, 0x63, (uint16_t)(cpu->bx)); /* mov word ds:[0x63], bx */
    mem_write16(cpu, cpu->ds, 0x65, (uint16_t)(cpu->es)); /* mov word ds:[0x65], es */
    cpu->ax = (uint16_t)(0x3506);            /* mov ax, 0x3506 */
    dos_int21(cpu);                          /* int 0x21 */
    mem_write16(cpu, cpu->ds, 0x67, (uint16_t)(cpu->bx)); /* mov word ds:[0x67], bx */
    mem_write16(cpu, cpu->ds, 0x69, (uint16_t)(cpu->es)); /* mov word ds:[0x69], es */
    cpu->ax = (uint16_t)(0x2500);            /* mov ax, 0x2500 */
    cpu->dx = (uint16_t)(SEG_0000);          /* mov dx, cs */
    cpu->ds = (uint16_t)(cpu->dx);           /* mov ds, dx */
    cpu->dx = (uint16_t)(0x11A);             /* mov dx, 0x11A */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->sp += 2; return;                    /* ret */
}

void fn_00167(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_00167");
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x2500);            /* mov ax, 0x2500 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x5B); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x5B + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ds:[0x5B] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x2504);            /* mov ax, 0x2504 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x5F); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x5F + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ds:[0x5F] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x2505);            /* mov ax, 0x2505 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x63); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x63 + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ds:[0x63] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x2506);            /* mov ax, 0x2506 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x67); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x67 + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ds:[0x67] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->sp += 2; return;                    /* ret */
    mem_write16(cpu, cpu->ds, 0x81, (uint16_t)(0x0)); /* mov word ds:[0x81], 0x0 */
    { uint16_t _ip=pop16(cpu); uint16_t _cs=pop16(cpu); if (_ip != 0xFFFF && _ip != 0) recomp_dispatch(cpu,_cs,_ip); return; } /* retf */
    cpu->sp += 2; return;                    /* ret */
}

void fn_00194(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_00194");
    mem_write16(cpu, cpu->ds, 0x81, (uint16_t)(0x0)); /* mov word ds:[0x81], 0x0 */
    { uint16_t _ip=pop16(cpu); uint16_t _cs=pop16(cpu); if (_ip != 0xFFFF && _ip != 0) recomp_dispatch(cpu,_cs,_ip); return; } /* retf */
}

void fn_0019B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0019B");
    cpu->sp += 2; return;                    /* ret */
}

void fn_0019C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0019C");
    cpu->ah = (uint8_t)(0x40);               /* mov ah, 0x40 */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->sp += 2; return;                    /* ret */
    cpu->cx = (uint16_t)(0x1E);              /* mov cx, 0x1E */
    /* nop */                                /* nop */
    cpu->dx = (uint16_t)(0x3D);              /* mov dx, 0x3D */
    cpu->ds = (uint16_t)(mem_read16(cpu, SEG_0000, 0x1BA)); /* mov ds, word cs:[0x1BA] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0019C(cpu);                           /* call 0x0000 */
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00104(cpu);                           /* call 0xFF68 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si)), cpu->al))); /* add byte ds:[bx+si], al */
    fn_001BC(cpu); return;                   /* fallthrough 0x0001BC */
}

void fn_001A4(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_001A4");
    cpu->cx = (uint16_t)(0x1E);              /* mov cx, 0x1E */
    /* nop */                                /* nop */
    cpu->dx = (uint16_t)(0x3D);              /* mov dx, 0x3D */
    cpu->ds = (uint16_t)(mem_read16(cpu, SEG_0000, 0x1BA)); /* mov ds, word cs:[0x1BA] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0019C(cpu);                           /* call 0xFFF8 */
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00104(cpu);                           /* call 0xFF60 */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si)), cpu->al))); /* add byte ds:[bx+si], al */
    fn_001BC(cpu); return;                   /* fallthrough 0x0001BC */
}

void fn_001BC(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_001BC");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->dx = _o; cpu->es = _s; } /* les dx, word ss:[bp+0x4] */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->cx = (uint16_t)(0x100);             /* mov cx, 0x100 */
    cpu->ax = (uint16_t)(0x1012);            /* mov ax, 0x1012 */
    bios_int10(cpu);                         /* int 0x10 */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_001CE(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_001CE");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->ds, 0x3902, (uint16_t)(cpu->si)); /* mov word ds:[0x3902], si */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x5); /* cmp byte ds:[0xBFCD], 0x5 */
    if (cc_ne(cpu)) goto L_fn_001CE_00001F;  /* jne 0x001F */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3904))); /* mov ax, word ds:[bx+0x3904] */
    mem_write16(cpu, cpu->ds, 0x40C8, (uint16_t)(cpu->ax)); /* mov word ds:[0x40C8], ax */
    goto L_fn_001CE_00003E;                  /* jmp 0x003E */
L_fn_001CE_00001F:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x2); /* cmp byte ds:[0xBFCD], 0x2 */
    if (cc_ne(cpu)) goto L_fn_001CE_000033;  /* jne 0x0033 */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0xBE))); /* mov ax, word ds:[bx+0xBE] */
    mem_write16(cpu, cpu->ds, 0x40C8, (uint16_t)(cpu->ax)); /* mov word ds:[0x40C8], ax */
    goto L_fn_001CE_00003E;                  /* jmp 0x003E */
L_fn_001CE_000033:;
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0xFE))); /* mov ax, word ds:[bx+0xFE] */
    mem_write16(cpu, cpu->ds, 0x40C8, (uint16_t)(cpu->ax)); /* mov word ds:[0x40C8], ax */
L_fn_001CE_00003E:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0020F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0020F");
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x3902)); /* mov ax, word ds:[0x3902] */
    goto L_fn_0020F_000005;                  /* jmp 0x0005 */
L_fn_0020F_000005:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_00215(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_00215");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3904), (uint16_t)(cpu->ax)); /* mov word ds:[bx+0x3904], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov ax, word ss:[bp+0x8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0xBE), (uint16_t)(cpu->ax)); /* mov word ds:[bx+0xBE], ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_00232(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_00232");
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x3904);            /* mov ax, 0x3904 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9C);              /* mov ax, 0x9C */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0xF116 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xBE);              /* mov ax, 0xBE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xDE);              /* mov ax, 0xDE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0xF116 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0025B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0025B");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov di, word ss:[bp+0x6] */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, cl */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->di)); /* add ax, di */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _r = cpu->ax & 0xF; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->dx = (uint16_t)(cpu->di);           /* mov dx, di */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    goto L_fn_0025B_000022;                  /* jmp 0x0022 */
L_fn_0025B_000022:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_00281(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_00281");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x6)); /* sub sp, 0x6 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x5); /* cmp byte ds:[0xBFCD], 0x5 */
    if (cc_ne(cpu)) goto L_fn_00281_000014;  /* jne 0x0014 */
    cpu->si = (uint16_t)(0x140);             /* mov si, 0x140 */
    goto L_fn_00281_000023;                  /* jmp 0x0023 */
L_fn_00281_000014:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x2); /* cmp byte ds:[0xBFCD], 0x2 */
    if (cc_ne(cpu)) goto L_fn_00281_000020;  /* jne 0x0020 */
    cpu->si = (uint16_t)(0x50);              /* mov si, 0x50 */
    goto L_fn_00281_000023;                  /* jmp 0x0023 */
L_fn_00281_000020:;
    cpu->si = (uint16_t)(0xA0);              /* mov si, 0xA0 */
L_fn_00281_000023:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { uint16_t _r = cpu->cx ^ cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* xor cx, cx */
    cpu->bx = (uint16_t)(0x1E8);             /* mov bx, 0x1E8 */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F2A7(cpu);                           /* call 0000:F2A7 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x10)); /* add ax, 0x10 */
    cpu->dx = (uint16_t)(flags_adc(cpu, cpu->dx, 0x0, 16)); /* adc dx, 0x0 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E9B4(cpu);                           /* call 0xE733 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x40CC, (uint16_t)(cpu->dx)); /* mov word ds:[0x40CC], dx */
    mem_write16(cpu, cpu->ds, 0x40CA, (uint16_t)(cpu->ax)); /* mov word ds:[0x40CA], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40CC)); /* mov ax, word ds:[0x40CC] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0x40CC, (uint16_t)(cpu->dx)); /* mov word ds:[0x40CC], dx */
    mem_write16(cpu, cpu->ds, 0x40CA, (uint16_t)(cpu->ax)); /* mov word ds:[0x40CA], ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x40CC)); /* push word ds:[0x40CC] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x40CA)); /* push word ds:[0x40CA] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0025B(cpu);                           /* call 0xFFDA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x4], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_00281_000098;                  /* jmp 0x0098 */
L_fn_00281_00006E:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov dx, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3926), (uint16_t)(cpu->dx)); /* mov word ds:[bx+0x3926], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924), (uint16_t)(cpu->ax)); /* mov word ds:[bx+0x3924], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov dx, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->si)); /* add ax, si */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0025B(cpu);                           /* call 0xFFDA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x4], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_00281_000098:;
    flags_cmp16(cpu, cpu->di, 0x1E8);        /* cmp di, 0x1E8 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_00281_00006E;   /* jl 0x006E */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039C);                           /* call 0x011B */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00232(cpu);                           /* call 0xFFB1 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x5); /* cmp byte ds:[0xBFCD], 0x5 */
    if (cc_ne(cpu)) goto L_fn_00281_0000B7;  /* jne 0x00B7 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x11E);             /* mov ax, 0x11E */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001BC(cpu);                           /* call 0xFF3B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_00281_0000C8;                  /* jmp 0x00C8 */
L_fn_00281_0000B7:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x4); /* cmp byte ds:[0xBFCD], 0x4 */
    if (cc_ne(cpu)) goto L_fn_00281_0000C8;  /* jne 0x00C8 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x41E);             /* mov ax, 0x41E */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001BC(cpu);                           /* call 0xFF3B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_00281_0000C8:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0034F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0034F");
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    bios_int10(cpu);                         /* int 0x10 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_00355(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_00355");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov di, word ss:[bp+0x6] */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x004D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x0050 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA)))); /* add ax, word ss:[bp+0xA] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x004D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)))); /* add ax, word ss:[bp+0x8] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0x0050 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_00B61(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_00B61");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->si = _o; cpu->es = _s; } /* les si, word ds:[bx+0x3924] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(cpu->ax);           /* mov dx, ax */
    { uint16_t _v = cpu->dx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shr dx, 0x1 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->dx)); /* add si, dx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { uint16_t _t = cpu->bl; cpu->bl = (uint8_t)(cpu->bh); cpu->bh = (uint8_t)(_t); } /* xchg bl, bh */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    cpu->ah = (uint8_t)(flags_add8(cpu, cpu->ah, cpu->bl)); /* add ah, bl */
    { uint8_t _r = cpu->bl ^ cpu->bl; flags_logic8(cpu, _r); cpu->bl = (uint8_t)(_r); } /* xor bl, bl */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->bx)); /* add ax, bx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->bx)); /* add ax, bx */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov dx, word ss:[bp+0x8] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->dx = (uint16_t)(flags_adc(cpu, cpu->dx, 0x0, 16)); /* adc dx, 0x0 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    push16(cpu, cpu->es);                    /* push es */
    cpu->ax = (uint16_t)(0xB800);            /* mov ax, 0xB800 */
    cpu->es = (uint16_t)(cpu->ax);           /* mov es, ax */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    { uint16_t _v = cpu->dx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shr dx, 0x1 */
    cpu->dx = (uint16_t)(flags_adc(cpu, cpu->dx, 0x0, 16)); /* adc dx, 0x0 */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov cx, word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(0xA0);              /* mov ax, 0xA0 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->dx)); /* sub ax, dx */
    cpu->bx = (uint16_t)(0x2000);            /* mov bx, 0x2000 */
    cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, cpu->dx)); /* sub bx, dx */
    cpu->bp = (uint16_t)(0x80A0);            /* mov bp, 0x80A0 */
L_fn_00B61_000057:;
    push16(cpu, cpu->cx);                    /* push cx */
    cpu->cx = (uint16_t)(cpu->dx);           /* mov cx, dx */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsw */
        mem_write16(cpu, cpu->es, cpu->di, mem_read16(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -2 : 2; cpu->di += df(cpu) ? -2 : 2; /* movsw */
    }
    { uint16_t _v = (uint16_t)cpu->cx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 17; uint64_t _val = (uint64_t)_v | (cf(cpu) ? 0x10000ull : 0ull); uint64_t _r = (((_val << _c) | (_val >> (17 - _c)))) & 0x1FFFFull; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (((_r >> 16) & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ (_r >> 16)) & 1) ? FLAG_OF : 0); cpu->cx = (uint16_t)((uint16_t)_r); } } /* rcl cx, 0x1 */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    if (cc_s(cpu)) goto L_fn_00B61_00006D;   /* js 0x006D */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_00B61_000057; /* loop 0x0057 */
    goto L_fn_00B61_000071;                  /* jmp 0x0071 */
L_fn_00B61_00006D:;
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bp)); /* add di, bp */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_00B61_000057; /* loop 0x0057 */
L_fn_00B61_000071:;
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_00BD7(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_00BD7");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->si = _o; cpu->es = _s; } /* les si, word ds:[bx+0x3924] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(cpu->bx);           /* mov di, bx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec bx */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, cpu->ax)); /* sub bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x48E))); /* mov ax, word cs:[bx+0x48E] */
    mem_write16(cpu, SEG_0000, 0x12D9, (uint16_t)(cpu->ax)); /* mov word cs:[0x12D9], ax */
    cpu->dx = (uint16_t)(0xA0);              /* mov dx, 0xA0 */
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, cpu->bx)); /* sub dx, bx */
    push16(cpu, cpu->es);                    /* push es */
    cpu->cx = (uint16_t)(0xA000);            /* mov cx, 0xA000 */
    cpu->es = (uint16_t)(cpu->cx);           /* mov es, cx */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov cx, word ss:[bp+0xA] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bp = (uint16_t)(0x140);             /* mov bp, 0x140 */
    cpu->bp = (uint16_t)(flags_sub16(cpu, cpu->bp, cpu->bx)); /* sub bp, bx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x12DB)); /* add ax, 0x12DB */
    recomp_dispatch(cpu, SEG_0000, cpu->ax); return; /* jmp ax */
L_fn_00BD7_000064:;
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ch = (uint8_t)(cpu->ah);            /* mov ch, ah */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->bx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 16; uint16_t _r = (_c ? (uint16_t)((_v << _c) | (_v >> (16 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->bx = (uint16_t)(_r); } } /* rol bx, 0x1 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bh);            /* mov ah, bh */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->dx)); /* add si, dx */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bp)); /* add di, bp */
    { uint8_t _r = cpu->ch ^ cpu->ch; flags_logic8(cpu, _r); cpu->ch = (uint8_t)(_r); } /* xor ch, ch */
    cpu->cx--; if (cpu->cx != 0) goto L_fn_00BD7_000701; /* loop 0x0701 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
L_fn_00BD7_000701:;
    RECOMP_TICK(cpu);
    goto L_fn_00BD7_000064;                  /* jmp 0x0064 */
}

void fn_012DB(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_012DB");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40C8)); /* mov ax, word ds:[0x40C8] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov cx, word ss:[bp+0x8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    if (cc_ae(cpu)) goto L_fn_012DB_00002B;  /* jae 0x002B */
    cpu->dl = (uint8_t)(cpu->al);            /* mov dl, al */
    { uint8_t _r = cpu->dl & 0xF; flags_logic8(cpu, _r); cpu->dl = (uint8_t)(_r); } /* and dl, 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->di)) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->di), (uint8_t)(_r)); } /* and byte es:[bx+di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->di)) | cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->di), (uint8_t)(_r)); } /* or byte es:[bx+di], dl */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec cx */
L_fn_012DB_00002B:;
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, cpu->bx)); /* sub bx, bx */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    if (cc_ae(cpu)) goto L_fn_012DB_000036;  /* jae 0x0036 */
    cpu->bx = (uint16_t)(0x1);               /* mov bx, 0x1 */
L_fn_012DB_000036:;
    while (cpu->cx != 0) { cpu->cx--;        /* rep stosb */
        mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    }
    flags_cmp16(cpu, cpu->bx, 0x0);          /* cmp bx, 0x0 */
    if (cc_e(cpu)) goto L_fn_012DB_000046;   /* je 0x0046 */
    { uint8_t _r = cpu->al & 0xF0; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* and byte es:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) | cpu->al; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* or byte es:[di], al */
L_fn_012DB_000046:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_01324(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01324");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40C8)); /* mov ax, word ds:[0x40C8] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov cx, word ss:[bp+0x8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    if (cc_b(cpu)) goto L_fn_01324_000023;   /* jb 0x0023 */
    { uint8_t _r = cpu->al & 0xF0; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0xF0 */
    cpu->dl = (uint8_t)(0xF);                /* mov dl, 0xF */
    goto L_fn_01324_000027;                  /* jmp 0x0027 */
L_fn_01324_000023:;
    { uint8_t _r = cpu->al & 0xF; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0xF */
    cpu->dl = (uint8_t)(0xF0);               /* mov dl, 0xF0 */
L_fn_01324_000027:;
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    cpu->bx = (uint16_t)(0xA0);              /* mov bx, 0xA0 */
L_fn_01324_00002C:;
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) & cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* and byte es:[di], dl */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) | cpu->al; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* or byte es:[di], al */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_01324_00002C; /* loop 0x002C */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0135D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0135D");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40C8)); /* mov ax, word ds:[0x40C8] */
    cpu->si = (uint16_t)(0xA0);              /* mov si, 0xA0 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    if (cc_ae(cpu)) goto L_fn_0135D_00003A;  /* jae 0x003A */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov cx, word ss:[bp+0xA] */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    cpu->dh = (uint8_t)(0xF0);               /* mov dh, 0xF0 */
    cpu->dl = (uint8_t)(cpu->al);            /* mov dl, al */
    { uint8_t _r = cpu->dl & 0xF; flags_logic8(cpu, _r); cpu->dl = (uint8_t)(_r); } /* and dl, 0xF */
L_fn_0135D_00002B:;
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) & cpu->dh; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* and byte es:[di], dh */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) | cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* or byte es:[di], dl */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->si)); /* add di, si */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0135D_00002B; /* loop 0x002B */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ss:[bp+0x8] */
L_fn_0135D_00003A:;
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    cpu->ah = (uint8_t)(flags_sub8(cpu, cpu->ah, cpu->ah)); /* sub ah, ah */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    if (cc_ae(cpu)) goto L_fn_0135D_000047;  /* jae 0x0047 */
    cpu->ah = (uint8_t)(0x1);                /* mov ah, 0x1 */
L_fn_0135D_000047:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->bx)); /* sub si, bx */
L_fn_0135D_00004C:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    while (cpu->cx != 0) { cpu->cx--;        /* rep stosb */
        mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    }
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->si)); /* add di, si */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_0135D_00004C;  /* jne 0x004C */
    flags_cmp8(cpu, cpu->ah, 0x0);           /* cmp ah, 0x0 */
    if (cc_e(cpu)) goto L_fn_0135D_000073;   /* je 0x0073 */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov cx, word ss:[bp+0xA] */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, cpu->si)); /* sub di, si */
    cpu->dh = (uint8_t)(0xF);                /* mov dh, 0xF */
    cpu->dl = (uint8_t)(cpu->al);            /* mov dl, al */
    { uint8_t _r = cpu->dl & 0xF0; flags_logic8(cpu, _r); cpu->dl = (uint8_t)(_r); } /* and dl, 0xF0 */
    cpu->si = (uint16_t)(0xA0);              /* mov si, 0xA0 */
L_fn_0135D_000069:;
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) & cpu->dh; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* and byte es:[di], dh */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) | cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* or byte es:[di], dl */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, cpu->si)); /* sub di, si */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0135D_000069; /* loop 0x0069 */
L_fn_0135D_000073:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_013D4(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_013D4");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->si = (uint16_t)(0xA0);              /* mov si, 0xA0 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    if (cc_ae(cpu)) goto L_fn_013D4_000031;  /* jae 0x0031 */
    cpu->cx = (uint16_t)(cpu->dx);           /* mov cx, dx */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    cpu->al = (uint8_t)(0xF);                /* mov al, 0xF */
L_fn_013D4_000025:;
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) ^ cpu->al; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* xor byte es:[di], al */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->si)); /* add di, si */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_013D4_000025; /* loop 0x0025 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ss:[bp+0x8] */
L_fn_013D4_000031:;
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ah = (uint8_t)(flags_sub8(cpu, cpu->ah, cpu->ah)); /* sub ah, ah */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov cx, word ss:[bp+0x8] */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    if (cc_ae(cpu)) goto L_fn_013D4_00003F;  /* jae 0x003F */
    cpu->ah = (uint8_t)(0x1);                /* mov ah, 0x1 */
L_fn_013D4_00003F:;
    cpu->bx = (uint16_t)(cpu->cx);           /* mov bx, cx */
    if (cpu->cx == 0) goto L_fn_013D4_000054; /* jcxz 0x0054 */
    cpu->al = (uint8_t)(0xFF);               /* mov al, 0xFF */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->cx)); /* sub si, cx */
L_fn_013D4_000047:;
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) ^ cpu->al; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* xor byte es:[di], al */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_013D4_000047; /* loop 0x0047 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->si)); /* add di, si */
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_013D4_000047;  /* jne 0x0047 */
L_fn_013D4_000054:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    flags_cmp8(cpu, cpu->ah, 0x0);           /* cmp ah, 0x0 */
    if (cc_e(cpu)) goto L_fn_013D4_00006B;   /* je 0x006B */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov cx, word ss:[bp+0xA] */
    cpu->al = (uint8_t)(0xF0);               /* mov al, 0xF0 */
    cpu->si = (uint16_t)(0xA0);              /* mov si, 0xA0 */
L_fn_013D4_000064:;
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) ^ cpu->al; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* xor byte es:[di], al */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->si)); /* add di, si */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_013D4_000064; /* loop 0x0064 */
L_fn_013D4_00006B:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_01443(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01443");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec bx */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, cpu->ax)); /* sub bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov si, word ss:[bp+0x6] */
    { uint16_t _v = cpu->si; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->si = (uint16_t)(_r); } } /* shl si, 0x1 */
    { uint16_t _v = cpu->si; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->si = (uint16_t)(_r); } } /* shl si, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->si + 0x3924) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[si+0x3924] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0xC) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ss:[bp+0xC] */
    mem_write16(cpu, cpu->es, cpu->di, (uint16_t)(cpu->bx)); /* mov word es:[di], bx */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->di + 0x2), (uint16_t)(cpu->dx)); /* mov word es:[di+0x2], dx */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x4)); /* add di, 0x4 */
    cpu->ax = (uint16_t)(0xA0);              /* mov ax, 0xA0 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
L_fn_01443_000039:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_01443_000039;  /* jne 0x0039 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0148A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0148A");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov di, word ss:[bp+0x6] */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->di + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[di+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ss:[bp+0x8] */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->dx = (uint16_t)(cpu->ax);           /* mov dx, ax */
    cpu->ax = (uint16_t)(0xA0);              /* mov ax, 0xA0 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
L_fn_0148A_000027:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_0148A_000027;  /* jne 0x0027 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_014BF(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_014BF");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov bx, word ss:[bp+0xE] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov ax, word ss:[bp+0xC] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[bx+0x3924] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(0xA0);              /* mov ax, 0xA0 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
L_fn_014BF_000038:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsw */
        mem_write16(cpu, cpu->es, cpu->di, mem_read16(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -2 : 2; cpu->di += df(cpu) ? -2 : 2; /* movsw */
    }
    { uint16_t _v = (uint16_t)cpu->cx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 17; uint64_t _val = (uint64_t)_v | (cf(cpu) ? 0x10000ull : 0ull); uint64_t _r = (((_val << _c) | (_val >> (17 - _c)))) & 0x1FFFFull; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (((_r >> 16) & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ (_r >> 16)) & 1) ? FLAG_OF : 0); cpu->cx = (uint16_t)((uint16_t)_r); } } /* rcl cx, 0x1 */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_014BF_000038;  /* jne 0x0038 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xBC), 0x1); /* cmp word ds:[0xBC], 0x1 */
    if (cc_ne(cpu)) goto L_fn_014BF_000075;  /* jne 0x0075 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov bx, word ss:[bp+0xE] */
    flags_cmp16(cpu, cpu->bx, 0xC8);         /* cmp bx, 0xC8 */
    if (cc_ae(cpu)) goto L_fn_014BF_000075;  /* jae 0x0075 */
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
L_fn_014BF_000075:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_01538(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01538");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov bx, word ss:[bp+0xE] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov ax, word ss:[bp+0xC] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[bx+0x3924] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(cpu->dx);           /* mov ax, dx */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    { uint16_t _t = cpu->al; cpu->al = (uint8_t)(cpu->ah); cpu->ah = (uint8_t)(_t); } /* xchg al, ah */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->ax = (uint16_t)(0xA0);              /* mov ax, 0xA0 */
L_fn_01538_000045:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->bx)); /* sub si, bx */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, cpu->ax)); /* sub di, ax */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, cpu->bx)); /* sub di, bx */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_01538_000045;  /* jne 0x0045 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_01591(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01591");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov bx, word ss:[bp+0xE] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov ax, word ss:[bp+0xC] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[bx+0x3924] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
L_fn_01591_000036:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
L_fn_01591_000038:;
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    { uint8_t _v = (uint8_t)cpu->al; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 8; uint8_t _r = (_c ? (uint8_t)((_v << _c) | (_v >> (8 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->al = (uint8_t)(_r); } } /* rol al, 0x1 */
    { uint8_t _v = (uint8_t)cpu->al; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 8; uint8_t _r = (_c ? (uint8_t)((_v << _c) | (_v >> (8 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->al = (uint8_t)(_r); } } /* rol al, 0x1 */
    { uint8_t _v = (uint8_t)cpu->al; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 8; uint8_t _r = (_c ? (uint8_t)((_v << _c) | (_v >> (8 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->al = (uint8_t)(_r); } } /* rol al, 0x1 */
    { uint8_t _v = (uint8_t)cpu->al; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 8; uint8_t _r = (_c ? (uint8_t)((_v << _c) | (_v >> (8 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->al = (uint8_t)(_r); } } /* rol al, 0x1 */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->al)); /* mov byte es:[di], al */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_01591_000038; /* loop 0x0038 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0xA0)); /* add si, 0xA0 */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->bx)); /* sub si, bx */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0xA0)); /* add di, 0xA0 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_01591_000036;  /* jne 0x0036 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_015EC(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_015EC");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov bx, word ss:[bp+0xE] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov ax, word ss:[bp+0xC] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[bx+0x3924] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(cpu->dx);           /* mov ax, dx */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    { uint16_t _t = cpu->al; cpu->al = (uint8_t)(cpu->ah); cpu->ah = (uint8_t)(_t); } /* xchg al, ah */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
L_fn_015EC_000045:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
L_fn_015EC_000047:;
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    { uint8_t _v = (uint8_t)cpu->al; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 8; uint8_t _r = (_c ? (uint8_t)((_v << _c) | (_v >> (8 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->al = (uint8_t)(_r); } } /* rol al, 0x1 */
    { uint8_t _v = (uint8_t)cpu->al; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 8; uint8_t _r = (_c ? (uint8_t)((_v << _c) | (_v >> (8 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->al = (uint8_t)(_r); } } /* rol al, 0x1 */
    { uint8_t _v = (uint8_t)cpu->al; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 8; uint8_t _r = (_c ? (uint8_t)((_v << _c) | (_v >> (8 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->al = (uint8_t)(_r); } } /* rol al, 0x1 */
    { uint8_t _v = (uint8_t)cpu->al; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 8; uint8_t _r = (_c ? (uint8_t)((_v << _c) | (_v >> (8 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | ((_r & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ _r) & 1) ? FLAG_OF : 0); cpu->al = (uint8_t)(_r); } } /* rol al, 0x1 */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->al)); /* mov byte es:[di], al */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_015EC_000047; /* loop 0x0047 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0xA0)); /* add si, 0xA0 */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->bx)); /* sub si, bx */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 0xA0)); /* sub di, 0xA0 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_015EC_000045;  /* jne 0x0045 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_01656(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01656");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov bx, word ss:[bp+0xE] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov ax, word ss:[bp+0xC] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[bx+0x3924] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    { uint16_t _v = cpu->dx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shr dx, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->dx)); /* add di, dx */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
L_fn_01656_000038:;
    push16(cpu, cpu->di);                    /* push di */
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
L_fn_01656_00003B:;
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    { uint16_t _r = cpu->ax & 0xF00F; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF00F */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* and byte es:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) | cpu->ah; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* or byte es:[di], ah */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0xA0)); /* add di, 0xA0 */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* and byte es:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) | cpu->al; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* or byte es:[di], al */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0xA0)); /* add di, 0xA0 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_01656_00003B; /* loop 0x003B */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0xA0)); /* add si, 0xA0 */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->bx)); /* sub si, bx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    push16(cpu, cpu->di);                    /* push di */
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
L_fn_01656_00006B:;
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    { uint16_t _r = cpu->ax & 0xF00F; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF00F */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* and byte es:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) | cpu->ah; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* or byte es:[di], ah */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0xA0)); /* add di, 0xA0 */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* and byte es:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) | cpu->al; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* or byte es:[di], al */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0xA0)); /* add di, 0xA0 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_01656_00006B; /* loop 0x006B */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0xA0)); /* add si, 0xA0 */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->bx)); /* sub si, bx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_01656_000038;  /* jne 0x0038 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_016F7(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_016F7");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov bx, word ss:[bp+0xE] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov ax, word ss:[bp+0xC] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[bx+0x3924] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->ax = (uint16_t)(cpu->bx);           /* mov ax, bx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    { uint16_t _v = cpu->dx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shr dx, 0x1 */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    { uint16_t _t = cpu->al; cpu->al = (uint8_t)(cpu->ah); cpu->ah = (uint8_t)(_t); } /* xchg al, ah */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
L_fn_016F7_000044:;
    push16(cpu, cpu->di);                    /* push di */
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
L_fn_016F7_000047:;
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    { uint16_t _r = cpu->ax & 0xF00F; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF00F */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* and byte es:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) | cpu->ah; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* or byte es:[di], ah */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 0xA0)); /* sub di, 0xA0 */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* and byte es:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) | cpu->al; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* or byte es:[di], al */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 0xA0)); /* sub di, 0xA0 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_016F7_000047; /* loop 0x0047 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0xA0)); /* add si, 0xA0 */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->bx)); /* sub si, bx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    push16(cpu, cpu->di);                    /* push di */
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
L_fn_016F7_000077:;
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    { uint16_t _r = cpu->ax & 0xF00F; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF00F */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* and byte es:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) | cpu->ah; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* or byte es:[di], ah */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 0xA0)); /* sub di, 0xA0 */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* and byte es:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->di) | cpu->al; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(_r)); } /* or byte es:[di], al */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 0xA0)); /* sub di, 0xA0 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_016F7_000077; /* loop 0x0077 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0xA0)); /* add si, 0xA0 */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->bx)); /* sub si, bx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_016F7_000044;  /* jne 0x0044 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_017A4(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_017A4");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0E0)); /* mov ax, word ds:[0xC0E0] */
    cpu->es = (uint16_t)(cpu->ax);           /* mov es, ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0E4)); /* mov di, word ds:[0xC0E4] */
    cpu->cl = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->di))); /* mov cl, byte es:[bx+di] */
    cpu->ch = (uint8_t)(flags_sub8(cpu, cpu->ch, cpu->ch)); /* sub ch, ch */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0E6)); /* mov di, word ds:[0xC0E6] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->di))); /* mov al, byte es:[bx+di] */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0E2)); /* mov di, word ds:[0xC0E2] */
    cpu->ah = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->di))); /* mov ah, byte es:[bx+di] */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0DE)); /* mov si, word ds:[0xC0DE] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0E8)); /* mov dx, word ds:[0xC0E8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40C8)); /* mov ax, word ds:[0x40C8] */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->ds = _s; } /* lds di, word ds:[bx+0x3924] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x0)); /* mov word ss:[bp+-0x2], 0x0 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_000054;  /* jae 0x0054 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x1)); /* mov word ss:[bp+-0x2], 0x1 */
L_fn_017A4_000054:;
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    cpu->bx = (uint16_t)(cpu->cx);           /* mov bx, cx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc cx */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0xA0)); /* mov word ss:[bp+-0x4], 0xA0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), cpu->cx))); /* sub word ss:[bp+-0x4], cx */
    cpu->cl = (uint8_t)(cpu->dl);            /* mov cl, dl */
    cpu->dh = (uint8_t)(cpu->al);            /* mov dh, al */
    cpu->dl = (uint8_t)(cpu->dh);            /* mov dl, dh */
    { uint16_t _r = cpu->dx & 0xF00F; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* and dx, 0xF00F */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x0); /* cmp word ss:[bp+-0x2], 0x0 */
    if (cc_ne(cpu)) goto L_fn_017A4_0000EA;  /* jne 0x00EA */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
L_fn_017A4_000076:;
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ah = (uint8_t)(flags_sub8(cpu, cpu->ah, cpu->ah)); /* sub ah, ah */
L_fn_017A4_000079:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->si)); /* mov al, byte es:[si] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    flags_cmp16(cpu, cpu->bx, 0x10);         /* cmp bx, 0x10 */
    if (cc_ge(cpu)) goto L_fn_017A4_00008C;  /* jge 0x008C */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    { uint8_t _r = cpu->ah & 0x2; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* and ah, 0x2 */
    { uint16_t _t = mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x190C)); /* jmp word cs:[bx+0x190C] */
      switch (_t) {
        case 0x1881: goto L_fn_017A4_0000DD;
        case 0x1869: goto L_fn_017A4_0000C5;
        case 0x1856: goto L_fn_017A4_0000B2;
        case 0x1843: goto L_fn_017A4_00009F;
        case 0x1830: goto L_fn_017A4_00008C;
        case 0x18F5: goto L_fn_017A4_000151;
        case 0x18DD: goto L_fn_017A4_000139;
        case 0x18CA: goto L_fn_017A4_000126;
        case 0x18B7: goto L_fn_017A4_000113;
        case 0x18A4: goto L_fn_017A4_000100;
        default: recomp_dispatch(cpu, SEG_0000, _t); return;
      } }
L_fn_017A4_00008C:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_000096;  /* jae 0x0096 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dh; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dh */
L_fn_017A4_000096:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_00009F;  /* jae 0x009F */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dl */
L_fn_017A4_00009F:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_0000A9;  /* jae 0x00A9 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dh; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dh */
L_fn_017A4_0000A9:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_0000B2;  /* jae 0x00B2 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dl */
L_fn_017A4_0000B2:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_0000BC;  /* jae 0x00BC */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dh; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dh */
L_fn_017A4_0000BC:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_0000C5;  /* jae 0x00C5 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dl */
L_fn_017A4_0000C5:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_0000CF;  /* jae 0x00CF */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dh; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dh */
L_fn_017A4_0000CF:;
    flags_cmp8(cpu, cpu->ah, 0x0);           /* cmp ah, 0x0 */
    if (cc_ne(cpu)) goto L_fn_017A4_0000E2;  /* jne 0x00E2 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_0000DD;  /* jae 0x00DD */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dl */
L_fn_017A4_0000DD:;
    cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, 0x10)); /* sub bx, 0x10 */
    RECOMP_TICK(cpu);
    if (cc_g(cpu)) goto L_fn_017A4_000079;   /* jg 0x0079 */
L_fn_017A4_0000E2:;
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)))); /* add di, word ss:[bp+-0x4] */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_017A4_000076; /* loop 0x0076 */
    goto L_fn_017A4_00015C;                  /* jmp 0x015C */
L_fn_017A4_0000EA:;
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ah = (uint8_t)(flags_sub8(cpu, cpu->ah, cpu->ah)); /* sub ah, ah */
L_fn_017A4_0000ED:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->si)); /* mov al, byte es:[si] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    flags_cmp16(cpu, cpu->bx, 0x10);         /* cmp bx, 0x10 */
    if (cc_ge(cpu)) goto L_fn_017A4_000100;  /* jge 0x0100 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    { uint8_t _r = cpu->ah & 0x2; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* and ah, 0x2 */
    { uint16_t _t = mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x191E)); /* jmp word cs:[bx+0x191E] */
      switch (_t) {
        case 0x18F5: goto L_fn_017A4_000151;
        case 0x18DD: goto L_fn_017A4_000139;
        case 0x18CA: goto L_fn_017A4_000126;
        case 0x18B7: goto L_fn_017A4_000113;
        case 0x18A4: goto L_fn_017A4_000100;
        default: recomp_dispatch(cpu, SEG_0000, _t); return;
      } }
L_fn_017A4_000100:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_000109;  /* jae 0x0109 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dl */
L_fn_017A4_000109:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_000113;  /* jae 0x0113 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dh; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dh */
L_fn_017A4_000113:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_00011C;  /* jae 0x011C */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dl */
L_fn_017A4_00011C:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_000126;  /* jae 0x0126 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dh; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dh */
L_fn_017A4_000126:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_00012F;  /* jae 0x012F */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dl */
L_fn_017A4_00012F:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_000139;  /* jae 0x0139 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dh; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dh */
L_fn_017A4_000139:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_000142;  /* jae 0x0142 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dl */
L_fn_017A4_000142:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    flags_cmp8(cpu, cpu->ah, 0x0);           /* cmp ah, 0x0 */
    if (cc_ne(cpu)) goto L_fn_017A4_000156;  /* jne 0x0156 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_017A4_000151;  /* jae 0x0151 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dh; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dh */
L_fn_017A4_000151:;
    cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, 0x10)); /* sub bx, 0x10 */
    RECOMP_TICK(cpu);
    if (cc_g(cpu)) goto L_fn_017A4_0000ED;   /* jg 0x00ED */
L_fn_017A4_000156:;
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)))); /* add di, word ss:[bp+-0x4] */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_017A4_0000EA; /* loop 0x00EA */
L_fn_017A4_00015C:;
    cpu->ax = (uint16_t)(cpu->bx);           /* mov ax, bx */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x4)); /* add sp, 0x4 */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_01930(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01930");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ss:[bp+0x8] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x20)); /* add si, 0x20 */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->bh = (uint8_t)(flags_sub8(cpu, cpu->bh, cpu->bh)); /* sub bh, bh */
    cpu->bl = (uint8_t)(cpu->al);            /* mov bl, al */
    cpu->dh = (uint8_t)(cpu->bh);            /* mov dh, bh */
    cpu->dl = (uint8_t)(cpu->ah);            /* mov dl, ah */
    push16(cpu, cpu->dx);                    /* push dx */
    cpu->ax = (uint16_t)(0xA0);              /* mov ax, 0xA0 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
L_fn_01930_00002E:;
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsw */
        mem_write16(cpu, cpu->es, cpu->di, mem_read16(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -2 : 2; cpu->di += df(cpu) ? -2 : 2; /* movsw */
    }
    { uint16_t _v = (uint16_t)cpu->cx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 17; uint64_t _val = (uint64_t)_v | (cf(cpu) ? 0x10000ull : 0ull); uint64_t _r = (((_val << _c) | (_val >> (17 - _c)))) & 0x1FFFFull; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (((_r >> 16) & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ (_r >> 16)) & 1) ? FLAG_OF : 0); cpu->cx = (uint16_t)((uint16_t)_r); } } /* rcl cx, 0x1 */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_01930_00002E;  /* jne 0x002E */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xBC), 0x1); /* cmp word ds:[0xBC], 0x1 */
    if (cc_ne(cpu)) goto L_fn_01930_000064;  /* jne 0x0064 */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov cx, word ss:[bp+0x6] */
    flags_cmp16(cpu, cpu->cx, 0xC8);         /* cmp cx, 0xC8 */
    if (cc_ae(cpu)) goto L_fn_01930_000064;  /* jae 0x0064 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40C4 + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[0x40C4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->ah = (uint8_t)(cpu->cl);            /* mov ah, cl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->bl);            /* mov al, bl */
    cpu->ah = (uint8_t)(cpu->dl);            /* mov ah, dl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->di)); /* mov word ds:[0x40C4], di */
L_fn_01930_000064:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_01A98(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01A98");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->bp);                    /* push bp */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->si = _o; cpu->es = _s; } /* les si, word ss:[bp+0x8] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x20)); /* add si, 0x20 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->si)); /* mov ax, word es:[si] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x2)); /* add si, 0x2 */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->cx = (uint16_t)(cpu->dx);           /* mov cx, dx */
    cpu->cl = (uint8_t)(cpu->al);            /* mov cl, al */
    cpu->dl = (uint8_t)(cpu->ah);            /* mov dl, ah */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov di, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x96)); /* mov ax, word ds:[0x96] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->di)); /* sub ax, di */
    if (cc_s(cpu)) goto L_fn_01A98_00006B;   /* js 0x006B */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    flags_cmp16(cpu, cpu->dx, cpu->ax);      /* cmp dx, ax */
    if (cc_be(cpu)) goto L_fn_01A98_00002C;  /* jbe 0x002C */
    cpu->dx = (uint16_t)(cpu->ax);           /* mov dx, ax */
L_fn_01A98_00002C:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x94)); /* mov ax, word ds:[0x94] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->di)); /* sub ax, di */
    if (cc_le(cpu)) goto L_fn_01A98_00003D;  /* jle 0x003D */
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, cpu->ax)); /* sub dx, ax */
    if (cc_be(cpu)) goto L_fn_01A98_00006B;  /* jbe 0x006B */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { uint16_t _r = (uint16_t)cpu->al * cpu->cl; cpu->ax = _r; cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (_r > 0xFF ? FLAG_CF|FLAG_OF : 0); } /* mul cl */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
L_fn_01A98_00003D:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC)), 0x0); /* cmp word ss:[bp+0xC], 0x0 */
    if (cc_e(cpu)) goto L_fn_01A98_000049;   /* je 0x0049 */
    goto L_fn_01A98_0000CB;                  /* jmp 0x00CB */
L_fn_01A98_000049:;
    { int16_t _v = (int16_t)cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->bx = (uint16_t)((uint16_t)_r); } } /* sar bx, 0x1 */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    { uint16_t _r = cpu->bp ^ cpu->bp; flags_logic16(cpu, _r); cpu->bp = (uint16_t)(_r); } /* xor bp, bp */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x9A)); /* mov ax, word ds:[0x9A] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
    if (cc_s(cpu)) goto L_fn_01A98_00006B;   /* js 0x006B */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    flags_cmp16(cpu, cpu->cx, cpu->ax);      /* cmp cx, ax */
    if (cc_be(cpu)) goto L_fn_01A98_000060;  /* jbe 0x0060 */
    cpu->bp = (uint16_t)(cpu->cx);           /* mov bp, cx */
    cpu->bp = (uint16_t)(flags_sub16(cpu, cpu->bp, cpu->ax)); /* sub bp, ax */
    cpu->cx = (uint16_t)(cpu->ax);           /* mov cx, ax */
L_fn_01A98_000060:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x98)); /* mov ax, word ds:[0x98] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
    if (cc_le(cpu)) goto L_fn_01A98_000078;  /* jle 0x0078 */
    cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, cpu->ax)); /* sub cx, ax */
    if (cc_a(cpu)) goto L_fn_01A98_000072;   /* ja 0x0072 */
L_fn_01A98_00006B:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
L_fn_01A98_000072:;
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->bp = (uint16_t)(flags_add16(cpu, cpu->bp, cpu->ax)); /* add bp, ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
L_fn_01A98_000078:;
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->di);                    /* push di */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xBC), 0x1); /* cmp word ds:[0xBC], 0x1 */
    if (cc_ne(cpu)) goto L_fn_01A98_00009B;  /* jne 0x009B */
    flags_cmp16(cpu, cpu->di, 0xC8);         /* cmp di, 0xC8 */
    if (cc_ae(cpu)) goto L_fn_01A98_00009B;  /* jae 0x009B */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    cpu->al = (uint8_t)(cpu->bl);            /* mov al, bl */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40C4 + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[0x40C4] */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->al = (uint8_t)(cpu->cl);            /* mov al, cl */
    cpu->ah = (uint8_t)(cpu->dl);            /* mov ah, dl */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->di)); /* mov word ds:[0x40C4], di */
L_fn_01A98_00009B:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->di + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[di+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->bx = (uint16_t)(0x1998);            /* mov bx, 0x1998 */
L_fn_01A98_0000AA:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->cx);                    /* push cx */
L_fn_01A98_0000AC:;
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    cpu->al = mem_read8(cpu, SEG_0000, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    { uint8_t _r = cpu->al & mem_read8(cpu, cpu->es, cpu->di); flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, byte es:[di] */
    { uint8_t _r = cpu->al | cpu->ah; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, ah */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_01A98_0000AC; /* loop 0x00AC */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0xA0)); /* add di, 0xA0 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->bp)); /* add si, bp */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_01A98_0000AA;  /* jne 0x00AA */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
L_fn_01A98_0000CB:;
    cpu->flags |= FLAG_DF;                   /* std */
    { uint16_t _r = cpu->bp ^ cpu->bp; flags_logic16(cpu, _r); cpu->bp = (uint16_t)(_r); } /* xor bp, bp */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->cx)); /* add bx, cx */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->cx)); /* add bx, cx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec bx */
    cpu->ax = (uint16_t)(cpu->bx);           /* mov ax, bx */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x98))); /* sub ax, word ds:[0x98] */
    if (cc_s(cpu)) goto L_fn_01A98_0000F4;   /* js 0x00F4 */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    flags_cmp16(cpu, cpu->cx, cpu->ax);      /* cmp cx, ax */
    if (cc_be(cpu)) goto L_fn_01A98_0000E8;  /* jbe 0x00E8 */
    cpu->bp = (uint16_t)(cpu->cx);           /* mov bp, cx */
    cpu->bp = (uint16_t)(flags_sub16(cpu, cpu->bp, cpu->ax)); /* sub bp, ax */
    cpu->cx = (uint16_t)(cpu->ax);           /* mov cx, ax */
L_fn_01A98_0000E8:;
    cpu->ax = (uint16_t)(cpu->bx);           /* mov ax, bx */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x9A))); /* sub ax, word ds:[0x9A] */
    if (cc_be(cpu)) goto L_fn_01A98_000101;  /* jbe 0x0101 */
    cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, cpu->ax)); /* sub cx, ax */
    if (cc_a(cpu)) goto L_fn_01A98_0000FB;   /* ja 0x00FB */
L_fn_01A98_0000F4:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
L_fn_01A98_0000FB:;
    cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, cpu->ax)); /* sub bx, ax */
    cpu->bp = (uint16_t)(flags_add16(cpu, cpu->bp, cpu->ax)); /* add bp, ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
L_fn_01A98_000101:;
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->di);                    /* push di */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xBC), 0x1); /* cmp word ds:[0xBC], 0x1 */
    if (cc_ne(cpu)) goto L_fn_01A98_00012A;  /* jne 0x012A */
    flags_cmp16(cpu, cpu->di, 0xC8);         /* cmp di, 0xC8 */
    if (cc_ae(cpu)) goto L_fn_01A98_00012A;  /* jae 0x012A */
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
L_fn_01A98_00012A:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->di + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[di+0x3924] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->bx = (uint16_t)(0x1998);            /* mov bx, 0x1998 */
L_fn_01A98_000139:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->cx);                    /* push cx */
L_fn_01A98_00013B:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, cpu->si)); /* mov al, byte ds:[si] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { uint8_t _v = (uint8_t)cpu->al; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 8; uint8_t _r = (_c ? (uint8_t)((_v >> _c) | (_v << (8 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (((_r >> (8 - 1)) & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ (_r >> (8 - 2))) & 1) ? FLAG_OF : 0); cpu->al = (uint8_t)(_r); } } /* ror al, 0x1 */
    { uint8_t _v = (uint8_t)cpu->al; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 8; uint8_t _r = (_c ? (uint8_t)((_v >> _c) | (_v << (8 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (((_r >> (8 - 1)) & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ (_r >> (8 - 2))) & 1) ? FLAG_OF : 0); cpu->al = (uint8_t)(_r); } } /* ror al, 0x1 */
    { uint8_t _v = (uint8_t)cpu->al; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 8; uint8_t _r = (_c ? (uint8_t)((_v >> _c) | (_v << (8 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (((_r >> (8 - 1)) & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ (_r >> (8 - 2))) & 1) ? FLAG_OF : 0); cpu->al = (uint8_t)(_r); } } /* ror al, 0x1 */
    { uint8_t _v = (uint8_t)cpu->al; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 8; uint8_t _r = (_c ? (uint8_t)((_v >> _c) | (_v << (8 - _c))) : _v); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (((_r >> (8 - 1)) & 1) ? FLAG_CF : 0) | ((((_r >> (8 - 1)) ^ (_r >> (8 - 2))) & 1) ? FLAG_OF : 0); cpu->al = (uint8_t)(_r); } } /* ror al, 0x1 */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    cpu->al = mem_read8(cpu, SEG_0000, (uint16_t)(cpu->bx + cpu->al)); /* xlat */
    { uint8_t _r = cpu->al & mem_read8(cpu, cpu->es, cpu->di); flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, byte es:[di] */
    { uint8_t _r = cpu->al | cpu->ah; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, ah */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_01A98_00013B; /* loop 0x013B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0xA0)); /* add di, 0xA0 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->bp)); /* add si, bp */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_01A98_000139;  /* jne 0x0139 */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_01BFC(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01BFC");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40C8)); /* mov dx, word ds:[0x40C8] */
    cpu->dh = (uint8_t)(cpu->dl);            /* mov dh, dl */
    { uint16_t _r = cpu->dx & 0xF00F; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* and dx, 0xF00F */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->si = _o; cpu->es = _s; } /* les si, word ss:[bp+0x8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->ds = _s; } /* lds di, word ds:[bx+0x3924] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->cx = (uint16_t)(cpu->bx);           /* mov cx, bx */
    cpu->bl = (uint8_t)(mem_read8(cpu, cpu->es, cpu->si)); /* mov bl, byte es:[si] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0xA0)); /* mov word ss:[bp+-0x2], 0xA0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), cpu->bx))); /* sub word ss:[bp+-0x2], bx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->cl = (uint8_t)(mem_read8(cpu, cpu->es, cpu->si)); /* mov cl, byte es:[si] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
L_fn_01BFC_000042:;
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ah = (uint8_t)(flags_sub8(cpu, cpu->ah, cpu->ah)); /* sub ah, ah */
L_fn_01BFC_000045:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->si)); /* mov al, byte es:[si] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    flags_cmp16(cpu, cpu->bx, 0x10);         /* cmp bx, 0x10 */
    if (cc_ge(cpu)) goto L_fn_01BFC_000058;  /* jge 0x0058 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    { uint8_t _r = cpu->ah & 0x2; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* and ah, 0x2 */
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x190C))); return; /* jmp word cs:[bx+0x190C] */
L_fn_01BFC_000058:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_01BFC_000062;  /* jae 0x0062 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dh; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dh */
L_fn_01BFC_000062:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_01BFC_00006B;  /* jae 0x006B */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dl */
L_fn_01BFC_00006B:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_01BFC_000075;  /* jae 0x0075 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dh; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dh */
L_fn_01BFC_000075:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_01BFC_00007E;  /* jae 0x007E */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dl */
L_fn_01BFC_00007E:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_01BFC_000088;  /* jae 0x0088 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dh; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dh */
L_fn_01BFC_000088:;
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_01BFC_000091;  /* jae 0x0091 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dl */
L_fn_01BFC_000091:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_01BFC_00009B;  /* jae 0x009B */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dh; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dh */
L_fn_01BFC_00009B:;
    flags_cmp8(cpu, cpu->ah, 0x0);           /* cmp ah, 0x0 */
    if (cc_ne(cpu)) goto L_fn_01BFC_0000AE;  /* jne 0x00AE */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    if (cc_ae(cpu)) goto L_fn_01BFC_0000A9;  /* jae 0x00A9 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* and byte ds:[di], 0xF0 */
    { uint8_t _r = mem_read8(cpu, cpu->ds, cpu->di) | cpu->dl; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(_r)); } /* or byte ds:[di], dl */
L_fn_01BFC_0000A9:;
    cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, 0x10)); /* sub bx, 0x10 */
    RECOMP_TICK(cpu);
    if (cc_g(cpu)) goto L_fn_01BFC_000045;   /* jg 0x0045 */
L_fn_01BFC_0000AE:;
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)))); /* add di, word ss:[bp+-0x2] */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_01BFC_000042; /* loop 0x0042 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x2)); /* add sp, 0x2 */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_01CCA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01CCA");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    if (cc_b(cpu)) goto L_fn_01CCA_00002B;   /* jb 0x002B */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->di)); /* mov al, byte es:[di] */
    { uint8_t _r = cpu->al & 0xF; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0xF */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40C8)); /* mov bx, word ds:[0x40C8] */
    { uint8_t _v = cpu->bl; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->bl = (uint8_t)(_r); } } /* shl bl, 0x1 */
    { uint8_t _v = cpu->bl; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->bl = (uint8_t)(_r); } } /* shl bl, 0x1 */
    { uint8_t _v = cpu->bl; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->bl = (uint8_t)(_r); } } /* shl bl, 0x1 */
    { uint8_t _v = cpu->bl; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->bl = (uint8_t)(_r); } } /* shl bl, 0x1 */
    goto L_fn_01CCA_000039;                  /* jmp 0x0039 */
L_fn_01CCA_00002B:;
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->di)); /* mov al, byte es:[di] */
    { uint8_t _r = cpu->al & 0xF0; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0xF0 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40C8)); /* mov bx, word ds:[0x40C8] */
    { uint8_t _r = cpu->bl & 0xF; flags_logic8(cpu, _r); cpu->bl = (uint8_t)(_r); } /* and bl, 0xF */
L_fn_01CCA_000039:;
    { uint8_t _r = cpu->al | cpu->bl; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, bl */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(cpu->al)); /* mov byte es:[di], al */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_01D0B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01D0B");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->di);                    /* push di */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x3924)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx + 0x3924) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ds:[bx+0x3924] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    if (cc_b(cpu)) goto L_fn_01D0B_000028;   /* jb 0x0028 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->di)); /* mov al, byte es:[di] */
    { uint16_t _r = cpu->ax & 0xF0; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF0 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    goto L_fn_01D0B_000030;                  /* jmp 0x0030 */
L_fn_01D0B_000028:;
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->di)); /* mov al, byte es:[di] */
    { uint16_t _r = cpu->ax & 0xF; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF */
L_fn_01D0B_000030:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_01D47(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01D47");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x720), 0x1); /* cmp word ds:[0x720], 0x1 */
    if (cc_ne(cpu)) goto L_fn_01D47_00000E;  /* jne 0x000E */
    goto L_fn_01D47_00015B;                  /* jmp 0x015B */
    goto L_fn_01D47_000018;                  /* jmp 0x0018 */
L_fn_01D47_00000E:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x720), 0x2); /* cmp word ds:[0x720], 0x2 */
    if (cc_ne(cpu)) goto L_fn_01D47_000018;  /* jne 0x0018 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0B593(cpu);                           /* call 0x984C */
L_fn_01D47_000018:;
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x7352);            /* mov ax, 0x7352 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x14);              /* mov ax, 0x14 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0x4B03 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    cpu->di = (uint16_t)(cpu->si);           /* mov di, si */
    goto L_fn_01D47_00005A;                  /* jmp 0x005A */
L_fn_01D47_00002D:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x7352); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x7352 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x7352] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x7354)); /* mov cx, word ds:[0x7354] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x7352)); /* mov bx, word ds:[0x7352] */
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
L_fn_01D47_00005A:;
    flags_cmp16(cpu, cpu->si, 0x17);         /* cmp si, 0x17 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_01D47_00002D;   /* jl 0x002D */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x7356);            /* mov ax, 0x7356 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x15);              /* mov ax, 0x15 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0x4B03 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_01D47_00009F;                  /* jmp 0x009F */
L_fn_01D47_000072:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x7356); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x7356 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x7356] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x7358)); /* mov cx, word ds:[0x7358] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x7356)); /* mov bx, word ds:[0x7356] */
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
L_fn_01D47_00009F:;
    flags_cmp16(cpu, cpu->si, 0x14);         /* cmp si, 0x14 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_01D47_000072;   /* jl 0x0072 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x735A);            /* mov ax, 0x735A */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x16);              /* mov ax, 0x16 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0x4B03 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_01D47_0000E4;                  /* jmp 0x00E4 */
L_fn_01D47_0000B7:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x735A); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x735A + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x735A] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x735C)); /* mov cx, word ds:[0x735C] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x735A)); /* mov bx, word ds:[0x735A] */
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
L_fn_01D47_0000E4:;
    flags_cmp16(cpu, cpu->si, 0x29);         /* cmp si, 0x29 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_01D47_0000B7;   /* jl 0x00B7 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xBFC8);            /* mov ax, 0xBFC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x13);              /* mov ax, 0x13 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0x4B03 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x17);              /* mov ax, 0x17 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x4825 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x54);              /* mov ax, 0x54 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9BFC);            /* mov ax, 0x9BFC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F39C(cpu);                           /* call 0xD655 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x4825 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x54);              /* mov ax, 0x54 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xBF66);            /* mov ax, 0xBF66 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F39C(cpu);                           /* call 0xD655 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->ax = (uint16_t)(0x19);              /* mov ax, 0x19 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x4825 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x2A0);             /* mov ax, 0x2A0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x40D4);            /* mov ax, 0x40D4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F39C(cpu);                           /* call 0xD655 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ds, 0x720, (uint16_t)(0x1)); /* mov word ds:[0x720], 0x1 */
L_fn_01D47_00015B:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_01EA5(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01EA5");
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x9ADE)); /* mov ax, word ds:[0x9ADE] */
    { uint16_t _r = cpu->ax & 0x7; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x7 */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x000A; recomp_div0("idiv16"); } } /* idiv bx */
    goto L_fn_01EA5_00000E;                  /* jmp 0x000E */
L_fn_01EA5_00000E:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_01EB4(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01EB4");
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x9ADE)); /* mov ax, word ds:[0x9ADE] */
    cpu->bx = (uint16_t)(0x8);               /* mov bx, 0x8 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0007; recomp_div0("idiv16"); } } /* idiv bx */
    goto L_fn_01EB4_00000B;                  /* jmp 0x000B */
L_fn_01EB4_00000B:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_01EC0(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01EC0");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _r = cpu->ax & 0x1; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x1 */
    goto L_fn_01EC0_00000B;                  /* jmp 0x000B */
L_fn_01EC0_00000B:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_01ECD(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01ECD");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->di = (uint16_t)(cpu->ds);           /* mov di, ds */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40C4 + 2)); cpu->cx = _o; cpu->es = _s; } /* les cx, word ds:[0x40C4] */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[0xC5CA] */
    cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, cpu->si)); /* sub cx, si */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
L_fn_01ECD_000013:;
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->dx = (uint16_t)(cpu->ax);           /* mov dx, ax */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->bl = (uint8_t)(cpu->ah);            /* mov bl, ah */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bl = (uint8_t)(cpu->al);            /* mov bl, al */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, cpu->bx);                    /* push bx */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->bl = (uint8_t)(cpu->dh);            /* mov bl, dh */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bl = (uint8_t)(cpu->dl);            /* mov bl, dl */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ds = (uint16_t)(cpu->di);           /* mov ds, di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0xE4D2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_01ECD_000013; /* loop 0x0013 */
    cpu->ds = (uint16_t)(cpu->di);           /* mov ds, di */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5CA] */
    mem_write16(cpu, cpu->ds, 0x40C6, (uint16_t)(cpu->es)); /* mov word ds:[0x40C6], es */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->bx)); /* mov word ds:[0x40C4], bx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_01F17(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01F17");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[0xBFBC] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    flags_cmp16(cpu, cpu->ax, 0x137);        /* cmp ax, 0x137 */
    if (cc_g(cpu)) goto L_fn_01F17_00001C;   /* jg 0x001C */
    flags_cmp16(cpu, cpu->ax, 0x8);          /* cmp ax, 0x8 */
    if (cc_ge(cpu)) goto L_fn_01F17_00001F;  /* jge 0x001F */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    goto L_fn_01F17_00001F;                  /* jmp 0x001F */
L_fn_01F17_00001C:;
    cpu->ax = (uint16_t)(0x137);             /* mov ax, 0x137 */
L_fn_01F17_00001F:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    flags_cmp16(cpu, cpu->bx, 0x9F);         /* cmp bx, 0x9F */
    if (cc_g(cpu)) goto L_fn_01F17_000032;   /* jg 0x0032 */
    flags_cmp16(cpu, cpu->bx, 0x10);         /* cmp bx, 0x10 */
    if (cc_ge(cpu)) goto L_fn_01F17_000035;  /* jge 0x0035 */
    cpu->bx = (uint16_t)(0x10);              /* mov bx, 0x10 */
    goto L_fn_01F17_000035;                  /* jmp 0x0035 */
L_fn_01F17_000032:;
    cpu->bx = (uint16_t)(0x9F);              /* mov bx, 0x9F */
L_fn_01F17_000035:;
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov cx, word ss:[bp+0x8] */
    cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, cpu->ax)); /* add cx, ax */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec cx */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    flags_cmp16(cpu, cpu->cx, 0x26);         /* cmp cx, 0x26 */
    if (cc_l(cpu)) goto L_fn_01F17_00004D;   /* jl 0x004D */
    cpu->cx = (uint16_t)(0x26);              /* mov cx, 0x26 */
L_fn_01F17_00004D:;
    cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, cpu->ax)); /* sub cx, ax */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc cx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, 0x2)); /* sub bx, 0x2 */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(cpu->bx);           /* mov di, bx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->di)); /* add bx, di */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->bx)); /* add si, bx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_01F17_000070:;
    { uint8_t _r = cpu->al | mem_read8(cpu, cpu->ds, cpu->si); flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, byte ds:[si] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_01F17_000070; /* loop 0x0070 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_01F91(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_01F91");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ds:[0xBFBC] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    flags_cmp16(cpu, cpu->ax, 0x137);        /* cmp ax, 0x137 */
    if (cc_g(cpu)) goto L_fn_01F91_00001C;   /* jg 0x001C */
    flags_cmp16(cpu, cpu->ax, 0x8);          /* cmp ax, 0x8 */
    if (cc_ge(cpu)) goto L_fn_01F91_00001F;  /* jge 0x001F */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    goto L_fn_01F91_00001F;                  /* jmp 0x001F */
L_fn_01F91_00001C:;
    cpu->ax = (uint16_t)(0x137);             /* mov ax, 0x137 */
L_fn_01F91_00001F:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    flags_cmp16(cpu, cpu->bx, 0x9F);         /* cmp bx, 0x9F */
    if (cc_g(cpu)) goto L_fn_01F91_000032;   /* jg 0x0032 */
    flags_cmp16(cpu, cpu->bx, 0x10);         /* cmp bx, 0x10 */
    if (cc_ge(cpu)) goto L_fn_01F91_000035;  /* jge 0x0035 */
    cpu->bx = (uint16_t)(0x10);              /* mov bx, 0x10 */
    goto L_fn_01F91_000035;                  /* jmp 0x0035 */
L_fn_01F91_000032:;
    cpu->bx = (uint16_t)(0x9F);              /* mov bx, 0x9F */
L_fn_01F91_000035:;
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov cx, word ss:[bp+0x8] */
    cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, cpu->bx)); /* add cx, bx */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec cx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    flags_cmp16(cpu, cpu->cx, 0x13);         /* cmp cx, 0x13 */
    if (cc_l(cpu)) goto L_fn_01F91_000055;   /* jl 0x0055 */
    cpu->cx = (uint16_t)(0x13);              /* mov cx, 0x13 */
L_fn_01F91_000055:;
    cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, cpu->bx)); /* sub cx, bx */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc cx */
    cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, 0x2)); /* sub bx, 0x2 */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(cpu->bx);           /* mov di, bx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->bx)); /* add di, bx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->di)); /* add bx, di */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->bx)); /* add si, bx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_01F91_000072:;
    { uint8_t _r = cpu->al | mem_read8(cpu, cpu->ds, cpu->si); flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, byte ds:[si] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x26)); /* add si, 0x26 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_01F91_000072; /* loop 0x0072 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0200F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0200F");
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0200F_00001E;                  /* jmp 0x001E */
L_fn_0200F_000005:;
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xE2);              /* mov dx, 0xE2 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x6F2A)); /* add ax, 0x6F2A */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x5)); /* add ax, 0x5 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x489B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0200F_00001E:;
    flags_cmp16(cpu, cpu->si, 0x4);          /* cmp si, 0x4 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0200F_000005;   /* jl 0x0005 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0200F_000040;                  /* jmp 0x0040 */
L_fn_0200F_000027:;
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x62);              /* mov dx, 0x62 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x893C)); /* add ax, 0x893C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xA)); /* add ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x489B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0200F_000040:;
    flags_cmp16(cpu, cpu->si, 0x7);          /* cmp si, 0x7 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0200F_000027;   /* jl 0x0027 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x6E88);            /* mov ax, 0x6E88 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x489B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xB1CC);            /* mov ax, 0xB1CC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x11);              /* mov ax, 0x11 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x489B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9990);            /* mov ax, 0x9990 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x12);              /* mov ax, 0x12 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x489B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x7904);            /* mov ax, 0x7904 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2E);              /* mov ax, 0x2E */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x489B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x6AC4);            /* mov ax, 0x6AC4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2F);              /* mov ax, 0x2F */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x489B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x6CA6);            /* mov ax, 0x6CA6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x30);              /* mov ax, 0x30 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x489B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9AE0);            /* mov ax, 0x9AE0 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x27);              /* mov ax, 0x27 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x489B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x99DA);            /* mov ax, 0x99DA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x28);              /* mov ax, 0x28 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x489B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9C50);            /* mov ax, 0x9C50 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x29);              /* mov ax, 0x29 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x489B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9B6E);            /* mov ax, 0x9B6E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2A);              /* mov ax, 0x2A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x489B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9A5C);            /* mov ax, 0x9A5C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2B);              /* mov ax, 0x2B */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x489B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x7400);            /* mov ax, 0x7400 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2C);              /* mov ax, 0x2C */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x489B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x735E);            /* mov ax, 0x735E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2D);              /* mov ax, 0x2D */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x489B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_02119(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_02119");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x8)); /* sub sp, 0x8 */
    push16(cpu, cpu->si);                    /* push si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ds)); /* mov word ss:[bp+-0x6], ds */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(0x2380)); /* mov word ss:[bp+-0x8], 0x2380 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5C6); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5C6 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5C6] */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    cpu->ax = (uint16_t)(0x26);              /* mov ax, 0x26 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x4453 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_02119_000086;                  /* jmp 0x0086 */
L_fn_02119_000027:;
    cpu->ax = (uint16_t)(0x82);              /* mov ax, 0x82 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F39C(cpu);                           /* call 0xD283 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x82))); /* add word ss:[bp+-0x8], 0x82 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x84))); /* add word ss:[bp+-0x4], 0x84 */
    cpu->ax = (uint16_t)(0x62);              /* mov ax, 0x62 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F39C(cpu);                           /* call 0xD283 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x62))); /* add word ss:[bp+-0x8], 0x62 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x64))); /* add word ss:[bp+-0x4], 0x64 */
    cpu->ax = (uint16_t)(0x92);              /* mov ax, 0x92 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F39C(cpu);                           /* call 0xD283 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x92))); /* add word ss:[bp+-0x8], 0x92 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x94))); /* add word ss:[bp+-0x4], 0x94 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_02119_000086:;
    flags_cmp16(cpu, cpu->si, 0x8);          /* cmp si, 0x8 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_02119_000027;   /* jl 0x0027 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_021A9(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_021A9");
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9CF2);            /* mov ax, 0x9CF2 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x4701 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xA6B6);            /* mov ax, 0xA6B6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x4701 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    mem_write16(cpu, cpu->ds, 0xC0D8, (uint16_t)(cpu->ds)); /* mov word ds:[0xC0D8], ds */
    mem_write16(cpu, cpu->ds, 0xC0D6, (uint16_t)(0x9CF2)); /* mov word ds:[0xC0D6], 0x9CF2 */
    mem_write16(cpu, cpu->ds, 0xC0DC, (uint16_t)(cpu->ds)); /* mov word ds:[0xC0DC], ds */
    mem_write16(cpu, cpu->ds, 0xC0DA, (uint16_t)(0xA6B6)); /* mov word ds:[0xC0DA], 0xA6B6 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_021DB(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_021DB");
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x4391 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x3C8E);            /* mov ax, 0x3C8E */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E7B9(cpu);                           /* call 0xC5DE */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x99D4, (uint16_t)(cpu->dx)); /* mov word ds:[0x99D4], dx */
    mem_write16(cpu, cpu->ds, 0x99D2, (uint16_t)(cpu->ax)); /* mov word ds:[0x99D2], ax */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_021DB_00004F;                  /* jmp 0x004F */
L_fn_021DB_00001C:;
    cpu->ax = (uint16_t)(0x2A2);             /* mov ax, 0x2A2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x2A2);             /* mov dx, 0x2A2 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D4)); /* mov cx, word ds:[0x99D4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D2)); /* mov bx, word ds:[0x99D2] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x2A4);             /* mov dx, 0x2A4 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C8)); /* mov cx, word ds:[0xC5C8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C6)); /* mov bx, word ds:[0xC5C6] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0xD16D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_021DB_00004F:;
    flags_cmp16(cpu, cpu->si, 0x17);         /* cmp si, 0x17 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_021DB_00001C;   /* jl 0x001C */
    cpu->ax = (uint16_t)(0x2A2);             /* mov ax, 0x2A2 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x96EE);            /* mov ax, 0x96EE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C8)); /* mov dx, word ds:[0xC5C8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C6)); /* mov ax, word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x3CBE)); /* add ax, 0x3CBE */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0xD16D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0224C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0224C");
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->ax = (uint16_t)(0x55F0);            /* mov ax, 0x55F0 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E9B4(cpu);                           /* call 0xC768 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x99D8, (uint16_t)(cpu->dx)); /* mov word ds:[0x99D8], dx */
    mem_write16(cpu, cpu->ds, 0x99D6, (uint16_t)(cpu->ax)); /* mov word ds:[0x99D6], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0200F(cpu);                           /* call 0xFDC3 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02119(cpu);                           /* call 0xFECD */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06FCA(cpu);                           /* call 0x4D7E */
    cpu->sp += 2; return;                    /* ret */
}

void fn_02269(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_02269");
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x72C), 0x0); /* cmp word ds:[0x72C], 0x0 */
    if (cc_e(cpu)) goto L_fn_02269_000021;   /* je 0x0021 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x96EE);            /* mov ax, 0x96EE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x738)); /* push word ds:[0x738] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x736)); /* push word ds:[0x736] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xE163 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x72C, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x72C), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ds:[0x72C] */
L_fn_02269_000021:;
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
    ovl_call(cpu, 0x03CC);                           /* call 0xE163 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->sp += 2; return;                    /* ret */
}
