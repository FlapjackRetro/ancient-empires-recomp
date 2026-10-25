#include "recomp_all.h"

void fn_022B1(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_022B1");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x736), 0x8); /* cmp word ds:[0x736], 0x8 */
    if (cc_ge(cpu)) goto L_fn_022B1_000019;  /* jge 0x0019 */
    cpu->si = (uint16_t)(0x8);               /* mov si, 0x8 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x28)); /* mov word ss:[bp+-0x4], 0x28 */
    goto L_fn_022B1_00003D;                  /* jmp 0x003D */
L_fn_022B1_000019:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x27)); /* add ax, 0x27 */
    flags_cmp16(cpu, cpu->ax, 0x137);        /* cmp ax, 0x137 */
    if (cc_le(cpu)) goto L_fn_022B1_000034;  /* jle 0x0034 */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov si, word ds:[0x736] */
    cpu->ax = (uint16_t)(0x138);             /* mov ax, 0x138 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x736))); /* sub ax, word ds:[0x736] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    goto L_fn_022B1_00003D;                  /* jmp 0x003D */
L_fn_022B1_000034:;
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov si, word ds:[0x736] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x28)); /* mov word ss:[bp+-0x4], 0x28 */
L_fn_022B1_00003D:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x738), 0x10); /* cmp word ds:[0x738], 0x10 */
    if (cc_ge(cpu)) goto L_fn_022B1_00004E;  /* jge 0x004E */
    cpu->di = (uint16_t)(0x10);              /* mov di, 0x10 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x28)); /* mov word ss:[bp+-0x2], 0x28 */
    goto L_fn_022B1_000072;                  /* jmp 0x0072 */
L_fn_022B1_00004E:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x27)); /* add ax, 0x27 */
    flags_cmp16(cpu, cpu->ax, 0x9F);         /* cmp ax, 0x9F */
    if (cc_le(cpu)) goto L_fn_022B1_000069;  /* jle 0x0069 */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov di, word ds:[0x738] */
    cpu->ax = (uint16_t)(0xA0);              /* mov ax, 0xA0 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x738))); /* sub ax, word ds:[0x738] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    goto L_fn_022B1_000072;                  /* jmp 0x0072 */
L_fn_022B1_000069:;
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov di, word ds:[0x738] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x28)); /* mov word ss:[bp+-0x2], 0x28 */
L_fn_022B1_000072:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xE103 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0233E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0233E");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0xA80A */
    mem_write16(cpu, cpu->ds, 0x72C, (uint16_t)(0x0)); /* mov word ds:[0x72C], 0x0 */
    cpu->ax = (uint16_t)(0xD);               /* mov ax, 0xD */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0xA7B3 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x190)); /* mov word ds:[0x96], 0x190 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_022B1(cpu);                           /* call 0xFF73 */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x1)); /* mov word ds:[0xBC], 0x1 */
    cpu->di = (uint16_t)(0x1);               /* mov di, 0x1 */
    goto L_fn_0233E_0000C7;                  /* jmp 0x00C7 */
L_fn_0233E_00002E:;
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0x4919 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5CA] */
    mem_write16(cpu, cpu->ds, 0x40C6, (uint16_t)(cpu->es)); /* mov word ds:[0x40C6], es */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->bx)); /* mov word ds:[0x40C4], bx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0x319);             /* mov dx, 0x319 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x79BF)); /* add ax, 0x79BF */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x740C))); /* mov ax, word ds:[bx+-0x740C] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x7416))); /* push word ds:[bx+-0x7416] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0xE08B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x740C))); /* push word ds:[bx+-0x740C] */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x7416))); /* push word ds:[bx+-0x7416] */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2E);              /* mov ax, 0x2E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x740C))); /* mov ax, word ds:[bx+-0x740C] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x7416))); /* push word ds:[bx+-0x7416] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xE076 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
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
    ovl_call(cpu, 0x03CC);                           /* call 0xE08E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01ECD(cpu);                           /* call 0xFB8F */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C6F(cpu);                           /* call 0x4931 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_0233E_0000C7:;
    flags_cmp16(cpu, cpu->di, 0x5);          /* cmp di, 0x5 */
    if (cc_ge(cpu)) goto L_fn_0233E_0000CF;  /* jge 0x00CF */
    RECOMP_TICK(cpu);
    goto L_fn_0233E_00002E;                  /* jmp 0x002E */
L_fn_0233E_0000CF:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_022B1(cpu);                           /* call 0xFF73 */
    cpu->di = (uint16_t)(0xC);               /* mov di, 0xC */
    goto L_fn_0233E_000159;                  /* jmp 0x0159 */
L_fn_0233E_0000D8:;
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0x4919 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5CA] */
    mem_write16(cpu, cpu->ds, 0x40C6, (uint16_t)(cpu->es)); /* mov word ds:[0x40C6], es */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->bx)); /* mov word ds:[0x40C4], bx */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x740C))); /* push word ds:[bx+-0x740C] */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x7416))); /* push word ds:[bx+-0x7416] */
    cpu->ax = (uint16_t)(0x28);              /* mov ax, 0x28 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2E);              /* mov ax, 0x2E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x740C))); /* mov ax, word ds:[bx+-0x740C] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x7416))); /* push word ds:[bx+-0x7416] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xE076 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_022B1(cpu);                           /* call 0xFF73 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x73A)); /* push word ds:[0x73A] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0x2A2);             /* mov dx, 0x2A2 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D4)); /* mov cx, word ds:[0x99D4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D2)); /* mov bx, word ds:[0x99D2] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x740C))); /* push word ds:[bx+-0x740C] */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x7416))); /* mov ax, word ds:[bx+-0x7416] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xE08E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01ECD(cpu);                           /* call 0xFB8F */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C6F(cpu);                           /* call 0x4931 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_0233E_000159:;
    flags_cmp16(cpu, cpu->di, 0x10);         /* cmp di, 0x10 */
    if (cc_ge(cpu)) goto L_fn_0233E_000161;  /* jge 0x0161 */
    RECOMP_TICK(cpu);
    goto L_fn_0233E_0000D8;                  /* jmp 0x00D8 */
L_fn_0233E_000161:;
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x0)); /* mov word ds:[0xBC], 0x0 */
    cpu->ax = (uint16_t)(0xD);               /* mov ax, 0xD */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0xA7B3 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(0x3);               /* mov di, 0x3 */
    goto L_fn_0233E_0001C0;                  /* jmp 0x01C0 */
L_fn_0233E_000174:;
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0x4919 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0x319);             /* mov dx, 0x319 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x79BF)); /* add ax, 0x79BF */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x740C))); /* push word ds:[bx+-0x740C] */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x7416))); /* push word ds:[bx+-0x7416] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0xE08B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2E);              /* mov ax, 0x2E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x740C))); /* push word ds:[bx+-0x740C] */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x7416))); /* push word ds:[bx+-0x7416] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0xE061 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C6F(cpu);                           /* call 0x4931 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
L_fn_0233E_0001C0:;
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    RECOMP_TICK(cpu);
    if (cc_ge(cpu)) goto L_fn_0233E_000174;  /* jge 0x0174 */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x9F)); /* mov word ds:[0x96], 0x9F */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0250C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0250C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x6)); /* sub sp, 0x6 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(0x3);               /* mov dx, 0x3 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x2AC)); /* add bx, 0x2AC */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x5], al */
    { uint8_t _r = cpu->al | cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, al */
    if (cc_e(cpu)) goto L_fn_0250C_00006D;   /* je 0x006D */
    { uint8_t _r = mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5)) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5), (uint8_t)(_r)); } /* and byte ss:[bp+-0x5], 0xF */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5))); /* mov al, byte ss:[bp+-0x5] */
    { uint8_t _r = cpu->al | cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, al */
    if (cc_e(cpu)) goto L_fn_0250C_00005D;   /* je 0x005D */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    { uint8_t _r = cpu->al & 0xF0; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0xF0 */
    cpu->dl = (uint8_t)(0x6);                /* mov dl, 0x6 */
    cpu->dl = (uint8_t)(flags_sub8(cpu, cpu->dl, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5)))); /* sub dl, byte ss:[bp+-0x5] */
    { uint8_t _r = cpu->al | cpu->dl; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, dl */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    flags_logic8(cpu, mem_read8(cpu, cpu->es, cpu->bx) & 0xF); /* test byte es:[bx], 0xF */
    if (cc_e(cpu)) goto L_fn_0250C_00005B;   /* je 0x005B */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->bx) ^ 0x20; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(_r)); } /* xor byte es:[bx], 0x20 */
L_fn_0250C_00005B:;
    goto L_fn_0250C_00006D;                  /* jmp 0x006D */
L_fn_0250C_00005D:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    { uint8_t _r = cpu->al & 0xF0; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0xF0 */
    { uint8_t _r = cpu->al | 0x6; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, 0x6 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
L_fn_0250C_00006D:;
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0257D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0257D");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x736)); /* cmp ax, word ds:[0x736] */
    if (cc_l(cpu)) goto L_fn_0257D_000030;   /* jl 0x0030 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1F)); /* add ax, 0x1F */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* cmp ax, word ss:[bp+0x4] */
    if (cc_l(cpu)) goto L_fn_0257D_000030;   /* jl 0x0030 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x738)); /* cmp ax, word ds:[0x738] */
    if (cc_l(cpu)) goto L_fn_0257D_000030;   /* jl 0x0030 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x27)); /* add ax, 0x27 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* cmp ax, word ss:[bp+0x6] */
    if (cc_l(cpu)) goto L_fn_0257D_000030;   /* jl 0x0030 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_0257D_000034;                  /* jmp 0x0034 */
L_fn_0257D_000030:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0257D_000034;                  /* jmp 0x0034 */
L_fn_0257D_000034:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_025B3(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_025B3");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0xA)); /* sub sp, 0xA */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x2AC)); /* add bx, 0x2AC */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(0x0)); /* mov word ss:[bp+-0xA], 0x0 */
    goto L_fn_025B3_0002EA;                  /* jmp 0x02EA */
L_fn_025B3_00001E:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x5], al */
    flags_logic8(cpu, cpu->al & 0xF);        /* test al, 0xF */
    if (cc_ne(cpu)) goto L_fn_025B3_00002E;  /* jne 0x002E */
    goto L_fn_025B3_0002E3;                  /* jmp 0x02E3 */
L_fn_025B3_00002E:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    { int _cf = cf(cpu); mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(flags_sub8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec byte es:[bx] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    flags_logic8(cpu, cpu->al & 0xF);        /* test al, 0xF */
    if (cc_ne(cpu)) goto L_fn_025B3_000042;  /* jne 0x0042 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->bx) ^ 0x20; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(_r)); } /* xor byte es:[bx], 0x20 */
L_fn_025B3_000042:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    { uint16_t _v = cpu->si; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->si = (uint16_t)(_r); } } /* shl si, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    cpu->dx = (uint16_t)(0x26);              /* mov dx, 0x26 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->ax)); /* add dx, ax */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x8], dx */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0xB4)); /* add di, 0xB4 */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 0x4)); /* sub si, 0x4 */
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5)) & 0x80); /* test byte ss:[bp+-0x5], 0x80 */
    if (cc_ne(cpu)) goto L_fn_025B3_00008E;  /* jne 0x008E */
    goto L_fn_025B3_0001BC;                  /* jmp 0x01BC */
L_fn_025B3_00008E:;
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5)) & 0x20); /* test byte ss:[bp+-0x5], 0x20 */
    if (cc_ne(cpu)) goto L_fn_025B3_000097;  /* jne 0x0097 */
    goto L_fn_025B3_00012A;                  /* jmp 0x012A */
L_fn_025B3_000097:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFF40)); /* add ax, 0xFF40 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0257D(cpu);                           /* call 0xFFCA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_025B3_0000B7;   /* je 0x00B7 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5))); /* mov al, byte ss:[bp+-0x5] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    goto L_fn_025B3_000127;                  /* jmp 0x0127 */
L_fn_025B3_0000B7:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x38);              /* mov ax, 0x38 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x90)); /* add ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xDE01 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 0x8)); /* sub di, 0x8 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2), (uint8_t)(flags_sub8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)), 0x8))); /* sub byte es:[bx+0x2], 0x8 */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x167)); /* mov word ds:[0x96], 0x167 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x6CA6);            /* mov ax, 0x6CA6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xDE19 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x9F)); /* mov word ds:[0x96], 0x9F */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFF48)); /* add ax, 0xFF48 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x40);              /* mov ax, 0x40 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xDE01 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)))); /* add bx, word ss:[bp+-0x8] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xFFDA)); /* add bx, 0xFFDA */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(0x7)); /* mov byte es:[bx], 0x7 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)))); /* add bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xBE), (uint8_t)(0x0)); /* mov byte es:[bx+0xBE], 0x0 */
L_fn_025B3_000127:;
    goto L_fn_025B3_0001B9;                  /* jmp 0x01B9 */
L_fn_025B3_00012A:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFF88)); /* add ax, 0xFF88 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0257D(cpu);                           /* call 0xFFCA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_025B3_00014A;   /* je 0x014A */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5))); /* mov al, byte ss:[bp+-0x5] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    goto L_fn_025B3_0001B9;                  /* jmp 0x01B9 */
L_fn_025B3_00014A:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x38);              /* mov ax, 0x38 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x90)); /* add ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xDE01 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)), 0x8))); /* add byte es:[bx+0x2], 0x8 */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x167)); /* mov word ds:[0x96], 0x167 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x6CA6);            /* mov ax, 0x6CA6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xDE19 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x9F)); /* mov word ds:[0x96], 0x9F */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFF48)); /* add ax, 0xFF48 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x40);              /* mov ax, 0x40 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xDE01 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)))); /* add bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xE4), (uint8_t)(0x7)); /* mov byte es:[bx+0xE4], 0x7 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)))); /* add bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(0x0)); /* mov byte es:[bx], 0x0 */
L_fn_025B3_0001B9:;
    goto L_fn_025B3_0002E3;                  /* jmp 0x02E3 */
L_fn_025B3_0001BC:;
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5)) & 0x20); /* test byte ss:[bp+-0x5], 0x20 */
    if (cc_ne(cpu)) goto L_fn_025B3_0001C5;  /* jne 0x01C5 */
    goto L_fn_025B3_000255;                  /* jmp 0x0255 */
L_fn_025B3_0001C5:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFF4C)); /* add ax, 0xFF4C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFF8)); /* add ax, 0xFFF8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0257D(cpu);                           /* call 0xFFCA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_025B3_0001E5;   /* je 0x01E5 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5))); /* mov al, byte ss:[bp+-0x5] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    goto L_fn_025B3_000252;                  /* jmp 0x0252 */
L_fn_025B3_0001E5:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x38);              /* mov ax, 0x38 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x90)); /* add ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xDE01 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 0x8)); /* sub si, 0x8 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1), (uint8_t)(flags_sub8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1)), 0x4))); /* sub byte es:[bx+0x1], 0x4 */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x167)); /* mov word ds:[0x96], 0x167 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x6AC4);            /* mov ax, 0x6AC4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xDE19 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x9F)); /* mov word ds:[0x96], 0x9F */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFF48)); /* add ax, 0xFF48 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x40);              /* mov ax, 0x40 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xDE01 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)))); /* add bx, word ss:[bp+-0x8] */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec bx */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(0x7)); /* mov byte es:[bx], 0x7 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)))); /* add bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x5), (uint8_t)(0x0)); /* mov byte es:[bx+0x5], 0x0 */
L_fn_025B3_000252:;
    goto L_fn_025B3_0002E3;                  /* jmp 0x02E3 */
L_fn_025B3_000255:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFF4C)); /* add ax, 0xFF4C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x40)); /* add ax, 0x40 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0257D(cpu);                           /* call 0xFFCA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_025B3_000275;   /* je 0x0275 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5))); /* mov al, byte ss:[bp+-0x5] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    goto L_fn_025B3_0002E3;                  /* jmp 0x02E3 */
L_fn_025B3_000275:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x38);              /* mov ax, 0x38 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x90)); /* add ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xDE01 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1)), 0x4))); /* add byte es:[bx+0x1], 0x4 */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x167)); /* mov word ds:[0x96], 0x167 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x6AC4);            /* mov ax, 0x6AC4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xDE19 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x9F)); /* mov word ds:[0x96], 0x9F */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFF48)); /* add ax, 0xFF48 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x40);              /* mov ax, 0x40 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xDE01 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)))); /* add bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x6), (uint8_t)(0x7)); /* mov byte es:[bx+0x6], 0x7 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)))); /* add bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(0x0)); /* mov byte es:[bx], 0x0 */
L_fn_025B3_0002E3:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0xA] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x3))); /* add word ss:[bp+-0x4], 0x3 */
L_fn_025B3_0002EA:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)), 0xA); /* cmp word ss:[bp+-0xA], 0xA */
    if (cc_ge(cpu)) goto L_fn_025B3_0002F3;  /* jge 0x02F3 */
    RECOMP_TICK(cpu);
    goto L_fn_025B3_00001E;                  /* jmp 0x001E */
L_fn_025B3_0002F3:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_028AC(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_028AC");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0xE)); /* sub sp, 0xE */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x2AC)); /* add bx, 0x2AC */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(0x0)); /* mov word ss:[bp+-0xE], 0x0 */
    goto L_fn_028AC_0000CB;                  /* jmp 0x00CB */
L_fn_028AC_00001E:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x5], al */
    { uint8_t _r = cpu->al | cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, al */
    if (cc_ne(cpu)) goto L_fn_028AC_00002E;  /* jne 0x002E */
    goto L_fn_028AC_0000C4;                  /* jmp 0x00C4 */
L_fn_028AC_00002E:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    { uint16_t _v = cpu->si; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->si = (uint16_t)(_r); } } /* shl si, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    cpu->dx = (uint16_t)(0x26);              /* mov dx, 0x26 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->ax)); /* add dx, ax */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0xC], dx */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0xB4)); /* add di, 0xB4 */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 0x4)); /* sub si, 0x4 */
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5)) & 0x80); /* test byte ss:[bp+-0x5], 0x80 */
    if (cc_e(cpu)) goto L_fn_028AC_00008E;   /* je 0x008E */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x6CA6);            /* mov ax, 0x6CA6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xDB20 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(0x26)); /* mov word ss:[bp+-0xA], 0x26 */
    goto L_fn_028AC_0000A3;                  /* jmp 0x00A3 */
L_fn_028AC_00008E:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x6AC4);            /* mov ax, 0x6AC4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xDB20 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(0x1)); /* mov word ss:[bp+-0xA], 0x1 */
L_fn_028AC_0000A3:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(0x0)); /* mov word ss:[bp+-0x8], 0x0 */
    goto L_fn_028AC_0000BE;                  /* jmp 0x00BE */
L_fn_028AC_0000AA:;
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC)))); /* add bx, word ss:[bp+-0xC] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(0x7)); /* mov byte es:[bx], 0x7 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* mov ax, word ss:[bp+-0xA] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC)), cpu->ax))); /* add word ss:[bp+-0xC], ax */
L_fn_028AC_0000BE:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x6); /* cmp word ss:[bp+-0x8], 0x6 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_028AC_0000AA;   /* jl 0x00AA */
L_fn_028AC_0000C4:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0xE] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x3))); /* add word ss:[bp+-0x4], 0x3 */
L_fn_028AC_0000CB:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)), 0xA); /* cmp word ss:[bp+-0xE], 0xA */
    if (cc_ge(cpu)) goto L_fn_028AC_0000D4;  /* jge 0x00D4 */
    RECOMP_TICK(cpu);
    goto L_fn_028AC_00001E;                  /* jmp 0x001E */
L_fn_028AC_0000D4:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_02986(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_02986");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x6)); /* sub sp, 0x6 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBC)); /* mov ax, word ds:[0xBC] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xB1CC);            /* mov ax, 0xB1CC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xDA46 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x0)); /* mov word ds:[0xBC], 0x0 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4))); /* mov al, byte es:[bx+0x4] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x5)); /* add si, 0x5 */
    goto L_fn_02986_000096;                  /* jmp 0x0096 */
L_fn_02986_000052:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->si)), 0x0); /* cmp byte es:[bx+si], 0x0 */
    if (cc_ne(cpu)) goto L_fn_02986_00005D;  /* jne 0x005D */
    goto L_fn_02986_00009B;                  /* jmp 0x009B */
L_fn_02986_00005D:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFB)); /* add ax, 0xFFFB */
    cpu->dx = (uint16_t)(0xA);               /* mov dx, 0xA */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->di)); /* add ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x6)); /* add ax, 0x6 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->si))); /* mov al, byte es:[bx+si] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    cpu->dx = (uint16_t)(0x62);              /* mov dx, 0x62 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x893C)); /* add ax, 0x893C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB9)); /* add ax, 0xB9 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xDA46 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_02986_000096:;
    flags_cmp16(cpu, cpu->si, 0xA);          /* cmp si, 0xA */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_02986_000052;   /* jl 0x0052 */
L_fn_02986_00009B:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(cpu->ax)); /* mov word ds:[0xBC], ax */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_02A2D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_02A2D");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC0 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFC0] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC0 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFC0] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_02A2D_000031;                  /* jmp 0x0031 */
L_fn_02A2D_000025:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), cpu->ax))); /* add word ss:[bp+-0x4], ax */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_02A2D_000031:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* cmp si, word ss:[bp+0x4] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_02A2D_000025;   /* jl 0x0025 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    goto L_fn_02A2D_00003E;                  /* jmp 0x003E */
L_fn_02A2D_00003E:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_02A70(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_02A70");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC0 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFC0] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC0 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFC0] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02A2D(cpu);                           /* call 0xFFBD */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->dx = (uint16_t)(0x3);               /* mov dx, 0x3 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), cpu->ax))); /* add word ss:[bp+-0x4], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->dx = (uint16_t)(0xC);               /* mov dx, 0xC */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), cpu->ax))); /* add word ss:[bp+-0x4], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->dx = (uint16_t)(0x3);               /* mov dx, 0x3 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov cx, word ss:[bp+-0x2] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov bx, word ss:[bp+-0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    cpu->ax = (uint16_t)(cpu->bx);           /* mov ax, bx */
    goto L_fn_02A70_00006E;                  /* jmp 0x006E */
L_fn_02A70_00006E:;
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_02AE2(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_02AE2");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x12)); /* sub sp, 0x12 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x9ADE), 0x2A); /* cmp word ds:[0x9ADE], 0x2A */
    if (cc_ne(cpu)) goto L_fn_02AE2_000012;  /* jne 0x0012 */
    goto L_fn_02AE2_0006DC;                  /* jmp 0x06DC */
L_fn_02AE2_000012:;
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x2CA)); /* add bx, 0x2CA */
    mem_write16(cpu, cpu->ds, 0xBFC2, (uint16_t)(cpu->es)); /* mov word ds:[0xBFC2], es */
    mem_write16(cpu, cpu->ds, 0xBFC0, (uint16_t)(cpu->bx)); /* mov word ds:[0xBFC0], bx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x8C12);            /* mov ax, 0x8C12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0xD8E7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x8C12);            /* mov ax, 0x8C12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x54);              /* mov ax, 0x54 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0xD8E7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x8C12);            /* mov ax, 0x8C12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA0);              /* mov ax, 0xA0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0xD8E7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x8C12);            /* mov ax, 0x8C12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xEC);              /* mov ax, 0xEC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0xD8E7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x8C12);            /* mov ax, 0x8C12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x110);             /* mov ax, 0x110 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0xD8E7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x8C12);            /* mov ax, 0x8C12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x110);             /* mov ax, 0x110 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x54);              /* mov ax, 0x54 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0xD8E7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x8C12);            /* mov ax, 0x8C12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x110);             /* mov ax, 0x110 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA0);              /* mov ax, 0xA0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0xD8E7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x8C12);            /* mov ax, 0x8C12 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x110);             /* mov ax, 0x110 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xEC);              /* mov ax, 0xEC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0xD8E7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x190)); /* mov word ds:[0x96], 0x190 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x9ADE)); /* push word ds:[0x9ADE] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EC0(cpu);                           /* call 0xF3DE */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_02AE2_0000F0;   /* je 0x00F0 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x73C)); /* mov ax, word ds:[0x73C] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x101E)); /* add ax, 0x101E */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x3A8A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD8EA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_02AE2_0000F0:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02A70(cpu);                           /* call 0xFF8E */
    cpu->dx = (uint16_t)(cpu->ds);           /* mov dx, ds */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0xA], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->es = (uint16_t)(cpu->dx);           /* mov es, dx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0xC) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0xC] */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0xE], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x10], bx */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_02AE2_000171;                  /* jmp 0x0171 */
L_fn_02AE2_000115:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)), 0x80); /* cmp byte es:[bx+0x2], 0x80 */
    if (cc_b(cpu)) goto L_fn_02AE2_00016C;   /* jb 0x016C */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _r = cpu->ax & 0x40; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x40 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _r = cpu->bx & 0x3F; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* and bx, 0x3F */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x72B4))); /* push word ds:[bx+0x72B4] */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x72B2))); /* push word ds:[bx+0x72B2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD8EA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_02AE2_00016C:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 0x3))); /* add word ss:[bp+-0x10], 0x3 */
L_fn_02AE2_000171:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* cmp si, word ss:[bp+-0x6] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_02AE2_000115;   /* jl 0x0115 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    mem_write16(cpu, cpu->ds, 0xBFC6, (uint16_t)(cpu->es)); /* mov word ds:[0xBFC6], es */
    mem_write16(cpu, cpu->ds, 0xBFC4, (uint16_t)(cpu->bx)); /* mov word ds:[0xBFC4], bx */
    mem_write16(cpu, cpu->ds, 0x94, (uint16_t)(0xC8)); /* mov word ds:[0x94], 0xC8 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->si)); /* mov word ss:[bp+-0x8], si */
    goto L_fn_02AE2_000240;                  /* jmp 0x0240 */
L_fn_02AE2_00018F:;
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_02AE2_000237;                  /* jmp 0x0237 */
L_fn_02AE2_000194:;
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)))); /* add bx, word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x11), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x11], al */
    flags_logic8(cpu, cpu->al & 0x7);        /* test al, 0x7 */
    if (cc_e(cpu)) goto L_fn_02AE2_0001E7;   /* je 0x01E7 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x11))); /* mov al, byte ss:[bp+-0x11] */
    { uint8_t _r = cpu->al & 0x7; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0x7 */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0xFF)); /* add al, 0xFF */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x11), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x11], al */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x11)), 0x6); /* cmp byte ss:[bp+-0x11], 0x6 */
    if (cc_ae(cpu)) goto L_fn_02AE2_0001E5;  /* jae 0x01E5 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x11))); /* mov al, byte ss:[bp+-0x11] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->dx = (uint16_t)(0xBB);              /* mov dx, 0xBB */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x74A2)); /* add ax, 0x74A2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC4)); /* add ax, 0xC4 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD8EA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_02AE2_0001E5:;
    goto L_fn_02AE2_000233;                  /* jmp 0x0233 */
L_fn_02AE2_0001E7:;
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x11)) & 0x80); /* test byte ss:[bp+-0x11], 0x80 */
    if (cc_e(cpu)) goto L_fn_02AE2_000233;   /* je 0x0233 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x11))); /* mov al, byte ss:[bp+-0x11] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _r = cpu->ax & 0x70; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x70 */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { int16_t _v = (int16_t)cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->ax = (uint16_t)((uint16_t)_r); } } /* sar ax, cl */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x11), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x11], al */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x11)), 0x0); /* cmp byte ss:[bp+-0x11], 0x0 */
    if (cc_e(cpu)) goto L_fn_02AE2_000233;   /* je 0x0233 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x11))); /* mov al, byte ss:[bp+-0x11] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    cpu->dx = (uint16_t)(0xE2);              /* mov dx, 0xE2 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x6F2A)); /* add ax, 0x6F2A */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC8)); /* add ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD8EA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_02AE2_000233:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x8] */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_02AE2_000237:;
    flags_cmp16(cpu, cpu->di, 0x26);         /* cmp di, 0x26 */
    if (cc_ge(cpu)) goto L_fn_02AE2_00023F;  /* jge 0x023F */
    RECOMP_TICK(cpu);
    goto L_fn_02AE2_000194;                  /* jmp 0x0194 */
L_fn_02AE2_00023F:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_02AE2_000240:;
    flags_cmp16(cpu, cpu->si, 0x12);         /* cmp si, 0x12 */
    if (cc_ge(cpu)) goto L_fn_02AE2_000248;  /* jge 0x0248 */
    RECOMP_TICK(cpu);
    goto L_fn_02AE2_00018F;                  /* jmp 0x018F */
L_fn_02AE2_000248:;
    mem_write16(cpu, cpu->ds, 0x94, (uint16_t)(0x10)); /* mov word ds:[0x94], 0x10 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0xC) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0xC] */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0xE], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x10], bx */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_02AE2_0002B8;                  /* jmp 0x02B8 */
L_fn_02AE2_00025C:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)), 0x80); /* cmp byte es:[bx+0x2], 0x80 */
    if (cc_ae(cpu)) goto L_fn_02AE2_0002B3;  /* jae 0x02B3 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _r = cpu->ax & 0x40; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x40 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _r = cpu->bx & 0x3F; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* and bx, 0x3F */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x72B4))); /* push word ds:[bx+0x72B4] */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x72B2))); /* push word ds:[bx+0x72B2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD8EA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_02AE2_0002B3:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 0x3))); /* add word ss:[bp+-0x10], 0x3 */
L_fn_02AE2_0002B8:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* cmp si, word ss:[bp+-0x6] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_02AE2_00025C;   /* jl 0x025C */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB07A), 0x0); /* cmp word ds:[0xB07A], 0x0 */
    if (cc_e(cpu)) goto L_fn_02AE2_0002F1;   /* je 0x02F1 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0x4377)); /* mov al, byte ds:[0x4377] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xBFBA)); /* cmp ax, word ds:[0xBFBA] */
    if (cc_ne(cpu)) goto L_fn_02AE2_0002EB;  /* jne 0x02EB */
    mem_write16(cpu, cpu->ds, 0x722, (uint16_t)(0x1)); /* mov word ds:[0x722], 0x1 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0x4378)); /* mov al, byte ds:[0x4378] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ds, 0x8BEA, (uint16_t)(cpu->ax)); /* mov word ds:[0x8BEA], ax */
    { uint16_t _v = mem_read16(cpu, cpu->ds, 0x8BEA); uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); mem_write16(cpu, cpu->ds, 0x8BEA, (uint16_t)(_r)); } } /* shl word ds:[0x8BEA], 0x1 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0x4379)); /* mov al, byte ds:[0x4379] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ds, 0x8BF4, (uint16_t)(cpu->ax)); /* mov word ds:[0x8BF4], ax */
    goto L_fn_02AE2_0002F1;                  /* jmp 0x02F1 */
L_fn_02AE2_0002EB:;
    mem_write16(cpu, cpu->ds, 0x722, (uint16_t)(0x0)); /* mov word ds:[0x722], 0x0 */
L_fn_02AE2_0002F1:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_02AE2_000315;                  /* jmp 0x0315 */
L_fn_02AE2_0002F5:;
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x79BF);            /* mov ax, 0x79BF */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x740C))); /* mov ax, word ds:[bx+-0x740C] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x7416))); /* push word ds:[bx+-0x7416] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0xD8E7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_02AE2_000315:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ds, 0x722)); /* cmp si, word ds:[0x722] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_02AE2_0002F5;   /* jl 0x02F5 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC0 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFC0] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0x0); /* cmp byte es:[bx], 0x0 */
    if (cc_e(cpu)) goto L_fn_02AE2_000328;   /* je 0x0328 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D61C(cpu);                           /* call 0xAB3A */
L_fn_02AE2_000328:;
    cpu->ax = (uint16_t)(0x158);             /* mov ax, 0x158 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xD8D2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x190)); /* mov word ds:[0x96], 0x190 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_028AC(cpu);                           /* call 0xFDCA */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D818(cpu);                           /* call 0xAD36 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_02AE2_0003A2;                  /* jmp 0x03A2 */
L_fn_02AE2_000354:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov ax, word ds:[0xBFBA] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    cpu->dl = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->si + 0x437A))); /* mov dl, byte ds:[si+0x437A] */
    cpu->dh = (uint8_t)(0x0);                /* mov dh, 0x0 */
    flags_cmp16(cpu, cpu->ax, cpu->dx);      /* cmp ax, dx */
    if (cc_ne(cpu)) goto L_fn_02AE2_0003A1;  /* jne 0x03A1 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x7400);            /* mov ax, 0x7400 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->si + 0x4386))); /* mov al, byte ds:[si+0x4386] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->si + 0x4380))); /* mov al, byte ds:[si+0x4380] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD8EA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc al */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D825(cpu);                           /* call 0xAD43 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_02AE2_0003A1:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_02AE2_0003A2:;
    flags_cmp16(cpu, cpu->si, 0x6);          /* cmp si, 0x6 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_02AE2_000354;   /* jl 0x0354 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3E7))); /* mov al, byte es:[bx+0x3E7] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov dx, word ds:[0xBFBA] */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc dx */
    flags_cmp16(cpu, cpu->ax, cpu->dx);      /* cmp ax, dx */
    if (cc_ne(cpu)) goto L_fn_02AE2_000402;  /* jne 0x0402 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x735E);            /* mov ax, 0x735E */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3E6))); /* mov al, byte es:[bx+0x3E6] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3E5))); /* mov al, byte es:[bx+0x3E5] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD8EA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(0x7);                /* mov al, 0x7 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D825(cpu);                           /* call 0xAD43 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_02AE2_000402:;
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC0 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFC0] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC0 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFC0] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0xE], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x10], bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x10] */
    goto L_fn_02AE2_00057A;                  /* jmp 0x057A */
L_fn_02AE2_00042E:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3))); /* mov al, byte es:[bx+0x3] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    flags_cmp16(cpu, cpu->ax, 0x2);          /* cmp ax, 0x2 */
    if (cc_le(cpu)) goto L_fn_02AE2_000470;  /* jle 0x0470 */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0x8)); /* add al, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D825(cpu);                           /* call 0xAD43 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    goto L_fn_02AE2_00056E;                  /* jmp 0x056E */
L_fn_02AE2_000470:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x0); /* cmp word ss:[bp+-0x4], 0x0 */
    if (cc_ne(cpu)) goto L_fn_02AE2_0004D9;  /* jne 0x04D9 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4)), 0x0); /* cmp byte es:[bx+0x4], 0x0 */
    if (cc_e(cpu)) goto L_fn_02AE2_00049C;   /* je 0x049C */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9B6E);            /* mov ax, 0x9B6E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD8EA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    goto L_fn_02AE2_0004B6;                  /* jmp 0x04B6 */
L_fn_02AE2_00049C:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9AE0);            /* mov ax, 0x9AE0 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD8EA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_02AE2_0004B6:;
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x3)); /* add ax, 0x3 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x6)); /* add ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0x8)); /* add al, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D825(cpu);                           /* call 0xAD43 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    goto L_fn_02AE2_00056E;                  /* jmp 0x056E */
L_fn_02AE2_0004D9:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x1); /* cmp word ss:[bp+-0x4], 0x1 */
    if (cc_ne(cpu)) goto L_fn_02AE2_00053D;  /* jne 0x053D */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4)), 0x0); /* cmp byte es:[bx+0x4], 0x0 */
    if (cc_e(cpu)) goto L_fn_02AE2_000505;   /* je 0x0505 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9A5C);            /* mov ax, 0x9A5C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD8EA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    goto L_fn_02AE2_00051F;                  /* jmp 0x051F */
L_fn_02AE2_000505:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x99DA);            /* mov ax, 0x99DA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD8EA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_02AE2_00051F:;
    cpu->ax = (uint16_t)(0x7);               /* mov ax, 0x7 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x7);               /* mov ax, 0x7 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x3)); /* add ax, 0x3 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0x8)); /* add al, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D825(cpu);                           /* call 0xAD43 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    goto L_fn_02AE2_00056E;                  /* jmp 0x056E */
L_fn_02AE2_00053D:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9C50);            /* mov ax, 0x9C50 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD8EA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0x8)); /* add al, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D825(cpu);                           /* call 0xAD43 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_02AE2_00056E:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), cpu->ax))); /* add word ss:[bp+-0x10], ax */
L_fn_02AE2_00057A:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* cmp si, word ss:[bp+-0x6] */
    if (cc_ge(cpu)) goto L_fn_02AE2_000582;  /* jge 0x0582 */
    RECOMP_TICK(cpu);
    goto L_fn_02AE2_00042E;                  /* jmp 0x042E */
L_fn_02AE2_000582:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* mov dx, word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* mov ax, word ss:[bp+-0x10] */
    mem_write16(cpu, cpu->ds, 0x96E8, (uint16_t)(cpu->dx)); /* mov word ds:[0x96E8], dx */
    mem_write16(cpu, cpu->ds, 0x96E6, (uint16_t)(cpu->ax)); /* mov word ds:[0x96E6], ax */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->es = (uint16_t)(cpu->dx);           /* mov es, dx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x10] */
    goto L_fn_02AE2_000628;                  /* jmp 0x0628 */
L_fn_02AE2_0005A3:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x6E88);            /* mov ax, 0x6E88 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD8EA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->dx = (uint16_t)(0x62);              /* mov dx, 0x62 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x893C)); /* add ax, 0x893C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD8EA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0x20)); /* add al, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D825(cpu);                           /* call 0xAD43 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 0x3))); /* add word ss:[bp+-0x10], 0x3 */
L_fn_02AE2_000628:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* cmp si, word ss:[bp+-0x6] */
    if (cc_ge(cpu)) goto L_fn_02AE2_000630;  /* jge 0x0630 */
    RECOMP_TICK(cpu);
    goto L_fn_02AE2_0005A3;                  /* jmp 0x05A3 */
L_fn_02AE2_000630:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* mov dx, word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* mov ax, word ss:[bp+-0x10] */
    mem_write16(cpu, cpu->ds, 0x96EC, (uint16_t)(cpu->dx)); /* mov word ds:[0x96EC], dx */
    mem_write16(cpu, cpu->ds, 0x96EA, (uint16_t)(cpu->ax)); /* mov word ds:[0x96EA], ax */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->es = (uint16_t)(cpu->dx);           /* mov es, dx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x10] */
    goto L_fn_02AE2_0006B7;                  /* jmp 0x06B7 */
L_fn_02AE2_000650:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* push word ss:[bp+-0xE] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* push word ss:[bp+-0x10] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02986(cpu);                           /* call 0xFEA4 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->bx = (uint16_t)(0x4);               /* mov bx, 0x4 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0667; recomp_div0("idiv16"); } } /* idiv bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x10) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x10] */
    cpu->dl = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov dl, byte es:[bx+0x1] */
    cpu->dh = (uint8_t)(0x0);                /* mov dh, 0x0 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->dx);           /* mov ax, dx */
    cpu->bx = (uint16_t)(0x8);               /* mov bx, 0x8 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0679; recomp_div0("idiv16"); } } /* idiv bx */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    cpu->dx = (uint16_t)(0x26);              /* mov dx, 0x26 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->ax)); /* add dx, ax */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(0x0)); /* mov word ss:[bp+-0x8], 0x0 */
    goto L_fn_02AE2_0006AC;                  /* jmp 0x06AC */
L_fn_02AE2_00068F:;
    cpu->al = (uint8_t)(0x7);                /* mov al, 0x7 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)))); /* add bx, word ss:[bp+-0x2] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x26), (uint8_t)(cpu->al)); /* mov byte es:[bx+0x26], al */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)))); /* add bx, word ss:[bp+-0x2] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x8] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x2] */
L_fn_02AE2_0006AC:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x6); /* cmp word ss:[bp+-0x8], 0x6 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_02AE2_00068F;   /* jl 0x068F */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 0xC))); /* add word ss:[bp+-0x10], 0xC */
L_fn_02AE2_0006B7:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* cmp si, word ss:[bp+-0x6] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_02AE2_000650;   /* jl 0x0650 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* mov dx, word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* mov ax, word ss:[bp+-0x10] */
    mem_write16(cpu, cpu->ds, 0x40D2, (uint16_t)(cpu->dx)); /* mov word ds:[0x40D2], dx */
    mem_write16(cpu, cpu->ds, 0x40D0, (uint16_t)(cpu->ax)); /* mov word ds:[0x40D0], ax */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->es = (uint16_t)(cpu->dx);           /* mov es, dx */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0x0); /* cmp byte es:[bx], 0x0 */
    if (cc_e(cpu)) goto L_fn_02AE2_0006D6;   /* je 0x06D6 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06036(cpu);                           /* call 0x3554 */
L_fn_02AE2_0006D6:;
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x9F)); /* mov word ds:[0x96], 0x9F */
L_fn_02AE2_0006DC:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_031C4(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_031C4");
    push16(cpu, cpu->si);                    /* push si */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x72E), 0x8); /* cmp word ds:[0x72E], 0x8 */
    if (cc_g(cpu)) goto L_fn_031C4_00003F;   /* jg 0x003F */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5CA] */
    mem_write16(cpu, cpu->ds, 0x40C6, (uint16_t)(cpu->es)); /* mov word ds:[0x40C6], es */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->bx)); /* mov word ds:[0x40C4], bx */
    cpu->si = (uint16_t)(0x10);              /* mov si, 0x10 */
    goto L_fn_031C4_000032;                  /* jmp 0x0032 */
L_fn_031C4_000019:;
    cpu->ax = (uint16_t)(0x30);              /* mov ax, 0x30 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0x3A93 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(cpu->si)); /* mov word ds:[0x72E], si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_022B1(cpu);                           /* call 0xF0ED */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02269(cpu);                           /* call 0xF0A5 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01ECD(cpu);                           /* call 0xED09 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C6F(cpu);                           /* call 0x3AAB */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_031C4_000032:;
    flags_cmp16(cpu, cpu->si, 0x14);         /* cmp si, 0x14 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_031C4_000019;   /* jl 0x0019 */
    cpu->ax = (uint16_t)(0x30);              /* mov ax, 0x30 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C26(cpu);                           /* call 0x3A62 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_031C4_00003F:;
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x0)); /* mov word ds:[0xBC], 0x0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0x9984 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08BAB(cpu);                           /* call 0x59E7 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02AE2(cpu);                           /* call 0xF91E */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x130);             /* mov ax, 0x130 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xD1F0 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04EEB(cpu);                           /* call 0x1D27 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02269(cpu);                           /* call 0xF0A5 */
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x130);             /* mov ax, 0x130 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0xD1DB */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06FDA(cpu);                           /* call 0x3E16 */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x1)); /* mov word ds:[0xBC], 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5CA] */
    mem_write16(cpu, cpu->ds, 0x40C6, (uint16_t)(cpu->es)); /* mov word ds:[0x40C6], es */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->bx)); /* mov word ds:[0x40C4], bx */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x72E), 0x13); /* cmp word ds:[0x72E], 0x13 */
    if (cc_ne(cpu)) goto L_fn_031C4_0000D9;  /* jne 0x00D9 */
    cpu->si = (uint16_t)(0x13);              /* mov si, 0x13 */
    goto L_fn_031C4_0000C6;                  /* jmp 0x00C6 */
L_fn_031C4_0000AD:;
    cpu->ax = (uint16_t)(0x30);              /* mov ax, 0x30 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0x3A93 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(cpu->si)); /* mov word ds:[0x72E], si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_022B1(cpu);                           /* call 0xF0ED */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02269(cpu);                           /* call 0xF0A5 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01ECD(cpu);                           /* call 0xED09 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C6F(cpu);                           /* call 0x3AAB */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
L_fn_031C4_0000C6:;
    flags_cmp16(cpu, cpu->si, 0x10);         /* cmp si, 0x10 */
    RECOMP_TICK(cpu);
    if (cc_ge(cpu)) goto L_fn_031C4_0000AD;  /* jge 0x00AD */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0x0)); /* mov word ds:[0x72E], 0x0 */
    cpu->ax = (uint16_t)(0x30);              /* mov ax, 0x30 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C26(cpu);                           /* call 0x3A62 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_031C4_0000D9:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0329F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0329F");
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov ax, word ds:[0xBFBA] */
    cpu->dx = (uint16_t)(0x3E8);             /* mov dx, 0x3E8 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x43B4)); /* add bx, 0x43B4 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->ds, 0xBFBE, (uint16_t)(cpu->es)); /* mov word ds:[0xBFBE], es */
    mem_write16(cpu, cpu->ds, 0xBFBC, (uint16_t)(cpu->bx)); /* mov word ds:[0xBFBC], bx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02AE2(cpu);                           /* call 0xF843 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5CA] */
    mem_write16(cpu, cpu->ds, 0x40C6, (uint16_t)(cpu->es)); /* mov word ds:[0x40C6], es */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->bx)); /* mov word ds:[0x40C4], bx */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x130);             /* mov ax, 0x130 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xD115 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(cpu->ax)); /* mov word ds:[0xBC], ax */
    mem_write16(cpu, cpu->ds, 0x40CE, (uint16_t)(cpu->ax)); /* mov word ds:[0x40CE], ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04EEB(cpu);                           /* call 0x1C4C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x1)); /* mov word ds:[0xBC], 0x1 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_032FA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_032FA");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0xA)); /* sub sp, 0xA */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC0 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFC0] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3))); /* mov al, byte es:[bx+0x3] */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0x4)); /* add al, 0x4 */
    { uint8_t _r = cpu->al & 0x7; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0x7 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3), (uint8_t)(cpu->al)); /* mov byte es:[bx+0x3], al */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xA], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* mov ax, word ss:[bp+-0xA] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    cpu->bx = (uint16_t)(0x4);               /* mov bx, 0x4 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x005C; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    cpu->bx = (uint16_t)(0x8);               /* mov bx, 0x8 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x006A; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    cpu->dx = (uint16_t)(0x26);              /* mov dx, 0x26 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_032FA_000085;                  /* jmp 0x0085 */
L_fn_032FA_00007B:;
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    { uint8_t _r = mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->di)) ^ 0x10; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->di), (uint8_t)(_r)); } /* xor byte es:[bx+di], 0x10 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_032FA_000085:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* cmp si, word ss:[bp+-0x6] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_032FA_00007B;   /* jl 0x007B */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0338A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0338A");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x16)); /* sub sp, 0x16 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xE], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1)), 0x2); /* cmp byte es:[bx+0x1], 0x2 */
    if (cc_b(cpu)) goto L_fn_0338A_000020;   /* jb 0x0020 */
    goto L_fn_0338A_000178;                  /* jmp 0x0178 */
L_fn_0338A_000020:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    { uint16_t _v = cpu->si; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->si = (uint16_t)(_r); } } /* shl si, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3))); /* mov al, byte es:[bx+0x3] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1)), 0x0); /* cmp byte es:[bx+0x1], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0338A_000045;  /* jne 0x0045 */
    goto L_fn_0338A_0000DB;                  /* jmp 0x00DB */
L_fn_0338A_000045:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    { uint16_t _v = cpu->si; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->si = (uint16_t)(_r); } } /* shl si, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3))); /* mov al, byte es:[bx+0x3] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x148)); /* add ax, 0x148 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xD02A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x167)); /* mov word ds:[0x96], 0x167 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    { uint8_t _r = mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4)) ^ 0x1; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4), (uint8_t)(_r)); } /* xor byte es:[bx+0x4], 0x1 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4))); /* mov al, byte es:[bx+0x4] */
    { uint8_t _r = cpu->al | cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, al */
    if (cc_e(cpu)) goto L_fn_0338A_0000A6;   /* je 0x00A6 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9A5C);            /* mov ax, 0x9A5C */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD042 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    goto L_fn_0338A_0000BB;                  /* jmp 0x00BB */
L_fn_0338A_0000A6:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x99DA);            /* mov ax, 0x99DA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD042 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_0338A_0000BB:;
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x9F)); /* mov word ds:[0x96], 0x9F */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xD02A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    goto L_fn_0338A_00016E;                  /* jmp 0x016E */
L_fn_0338A_0000DB:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    { uint16_t _v = cpu->si; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->si = (uint16_t)(_r); } } /* shl si, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3))); /* mov al, byte es:[bx+0x3] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x148)); /* add ax, 0x148 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xD02A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x167)); /* mov word ds:[0x96], 0x167 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    { uint8_t _r = mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4)) ^ 0x1; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4), (uint8_t)(_r)); } /* xor byte es:[bx+0x4], 0x1 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4))); /* mov al, byte es:[bx+0x4] */
    { uint8_t _r = cpu->al | cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, al */
    if (cc_e(cpu)) goto L_fn_0338A_00013C;   /* je 0x013C */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9B6E);            /* mov ax, 0x9B6E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD042 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    goto L_fn_0338A_000151;                  /* jmp 0x0151 */
L_fn_0338A_00013C:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x9AE0);            /* mov ax, 0x9AE0 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xD042 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_0338A_000151:;
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x9F)); /* mov word ds:[0x96], 0x9F */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xD02A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
L_fn_0338A_00016E:;
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x9767 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0338A_00018A;                  /* jmp 0x018A */
L_fn_0338A_000178:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1)), 0x2); /* cmp byte es:[bx+0x1], 0x2 */
    if (cc_ne(cpu)) goto L_fn_0338A_00018A;  /* jne 0x018A */
    cpu->ax = (uint16_t)(0x16);              /* mov ax, 0x16 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x9767 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0338A_00018A:;
    cpu->ax = (uint16_t)(0x5);               /* mov ax, 0x5 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x10], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), cpu->ax))); /* add word ss:[bp+0x4], ax */
    goto L_fn_0338A_000355;                  /* jmp 0x0355 */
L_fn_0338A_000196:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x9], al */
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9)) & 0x80); /* test byte ss:[bp+-0x9], 0x80 */
    if (cc_ne(cpu)) goto L_fn_0338A_0001DC;  /* jne 0x01DC */
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9)) & 0x10); /* test byte ss:[bp+-0x9], 0x10 */
    if (cc_e(cpu)) goto L_fn_0338A_0001BA;   /* je 0x01BA */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9))); /* mov al, byte ss:[bp+-0x9] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _r = cpu->ax & 0xF; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_032FA(cpu);                           /* call 0xFF70 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0338A_0001D9;                  /* jmp 0x01D9 */
L_fn_0338A_0001BA:;
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9)) & 0x40); /* test byte ss:[bp+-0x9], 0x40 */
    if (cc_e(cpu)) goto L_fn_0338A_0001CF;   /* je 0x01CF */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9))); /* mov al, byte ss:[bp+-0x9] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _r = cpu->ax & 0xF; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06181(cpu);                           /* call 0x2DF7 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0338A_0001D9;                  /* jmp 0x01D9 */
L_fn_0338A_0001CF:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9))); /* mov al, byte ss:[bp+-0x9] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0250C(cpu);                           /* call 0xF182 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0338A_0001D9:;
    goto L_fn_0338A_00034F;                  /* jmp 0x034F */
L_fn_0338A_0001DC:;
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9)) & 0x30); /* test byte ss:[bp+-0x9], 0x30 */
    if (cc_e(cpu)) goto L_fn_0338A_0001E5;   /* je 0x01E5 */
    goto L_fn_0338A_00026B;                  /* jmp 0x026B */
L_fn_0338A_0001E5:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x10] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->dx = (uint16_t)(0x3E8);             /* mov dx, 0x3E8 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x43B4)); /* add bx, 0x43B4 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9))); /* mov al, byte ss:[bp+-0x9] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _r = cpu->ax & 0x7F; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x7F */
    cpu->dx = (uint16_t)(0x3);               /* mov dx, 0x3 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x2AC)); /* add bx, 0x2AC */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x6], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x8], bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x9], al */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->bx) & 0xF0; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(_r)); } /* and byte es:[bx], 0xF0 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->bx) ^ 0x20; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(_r)); } /* xor byte es:[bx], 0x20 */
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9)) & 0x80); /* test byte ss:[bp+-0x9], 0x80 */
    if (cc_e(cpu)) goto L_fn_0338A_000250;   /* je 0x0250 */
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9)) & 0x20); /* test byte ss:[bp+-0x9], 0x20 */
    if (cc_e(cpu)) goto L_fn_0338A_000246;   /* je 0x0246 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2), (uint8_t)(flags_sub8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)), 0x30))); /* sub byte es:[bx+0x2], 0x30 */
    goto L_fn_0338A_00024E;                  /* jmp 0x024E */
L_fn_0338A_000246:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)), 0x30))); /* add byte es:[bx+0x2], 0x30 */
L_fn_0338A_00024E:;
    goto L_fn_0338A_000268;                  /* jmp 0x0268 */
L_fn_0338A_000250:;
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9)) & 0x20); /* test byte ss:[bp+-0x9], 0x20 */
    if (cc_e(cpu)) goto L_fn_0338A_000260;   /* je 0x0260 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1), (uint8_t)(flags_sub8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1)), 0x18))); /* sub byte es:[bx+0x1], 0x18 */
    goto L_fn_0338A_000268;                  /* jmp 0x0268 */
L_fn_0338A_000260:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1)), 0x18))); /* add byte es:[bx+0x1], 0x18 */
L_fn_0338A_000268:;
    goto L_fn_0338A_00034F;                  /* jmp 0x034F */
L_fn_0338A_00026B:;
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9)) & 0x10); /* test byte ss:[bp+-0x9], 0x10 */
    if (cc_ne(cpu)) goto L_fn_0338A_000274;  /* jne 0x0274 */
    goto L_fn_0338A_00032A;                  /* jmp 0x032A */
L_fn_0338A_000274:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x10] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->dx = (uint16_t)(0x3E8);             /* mov dx, 0x3E8 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x43B4)); /* add bx, 0x43B4 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9))); /* mov al, byte ss:[bp+-0x9] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _r = cpu->ax & 0xF; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x2CB)); /* add bx, 0x2CB */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x6], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x8], bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3))); /* mov al, byte es:[bx+0x3] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, 0, cpu->ax)); /* neg ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3), (uint8_t)(cpu->al)); /* mov byte es:[bx+0x3], al */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0x2)); /* add al, 0x2 */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x9], al */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x16], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x14], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16))); /* mov ax, word ss:[bp+-0x16] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    cpu->bx = (uint16_t)(0x4);               /* mov bx, 0x4 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x02E9; recomp_div0("idiv16"); } } /* idiv bx */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* mov ax, word ss:[bp+-0x14] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    cpu->bx = (uint16_t)(0x8);               /* mov bx, 0x8 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x02F6; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    cpu->dx = (uint16_t)(0x26);              /* mov dx, 0x26 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->ax)); /* add dx, ax */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x12], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(0x0)); /* mov word ss:[bp+-0xC], 0x0 */
    goto L_fn_0338A_00031E;                  /* jmp 0x031E */
L_fn_0338A_00030E:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12)))); /* add bx, word ss:[bp+-0x12] */
    { uint8_t _r = mem_read8(cpu, cpu->es, cpu->bx) ^ 0x10; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(_r)); } /* xor byte es:[bx], 0x10 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0xC] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x12] */
L_fn_0338A_00031E:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9))); /* mov al, byte ss:[bp+-0x9] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC))); /* cmp ax, word ss:[bp+-0xC] */
    RECOMP_TICK(cpu);
    if (cc_g(cpu)) goto L_fn_0338A_00030E;   /* jg 0x030E */
    goto L_fn_0338A_00034F;                  /* jmp 0x034F */
L_fn_0338A_00032A:;
    flags_logic8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9)) & 0x20); /* test byte ss:[bp+-0x9], 0x20 */
    if (cc_e(cpu)) goto L_fn_0338A_00034F;   /* je 0x034F */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x10] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x9], al */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x9))); /* mov al, byte ss:[bp+-0x9] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->cl = (uint8_t)(0x5);                /* mov cl, 0x5 */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, cl */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4C51), (uint8_t)(0x0)); /* mov byte ds:[bx+-0x4C51], 0x0 */
L_fn_0338A_00034F:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x10] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+0x4] */
L_fn_0338A_000355:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* mov ax, word ss:[bp+-0x10] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* cmp ax, word ss:[bp+-0xE] */
    if (cc_ge(cpu)) goto L_fn_0338A_000360;  /* jge 0x0360 */
    RECOMP_TICK(cpu);
    goto L_fn_0338A_000196;                  /* jmp 0x0196 */
L_fn_0338A_000360:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_036F0(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_036F0");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0xC)); /* sub sp, 0xC */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x190)); /* mov word ds:[0x96], 0x190 */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x9401 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x96EA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x96EA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x96EA] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x96EA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x96EA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x96EA] */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x6], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x8], bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(0x0)); /* mov word ss:[bp+-0xA], 0x0 */
    goto L_fn_036F0_00027F;                  /* jmp 0x027F */
L_fn_036F0_000038:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4))); /* mov al, byte es:[bx+0x4] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x3), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x3], al */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x2], al */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x1], al */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x3))); /* mov al, byte ss:[bp+-0x3] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x5))); /* mov al, byte es:[bx+0x5] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* cmp ax, word ss:[bp+0x4] */
    if (cc_e(cpu)) goto L_fn_036F0_0000B3;   /* je 0x00B3 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x3)), 0x0); /* cmp byte ss:[bp+-0x3], 0x0 */
    if (cc_e(cpu)) goto L_fn_036F0_0000B0;   /* je 0x00B0 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4), (uint8_t)(0x0)); /* mov byte es:[bx+0x4], 0x0 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02986(cpu);                           /* call 0xF296 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov al, byte ss:[bp+-0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x38);              /* mov ax, 0x38 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov al, byte ss:[bp+-0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xCCC4 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
L_fn_036F0_0000B0:;
    goto L_fn_036F0_000278;                  /* jmp 0x0278 */
L_fn_036F0_0000B3:;
    { int _cf = cf(cpu); mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x3), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x3)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc byte ss:[bp+-0x3] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x3))); /* mov al, byte ss:[bp+-0x3] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4), (uint8_t)(cpu->al)); /* mov byte es:[bx+0x4], al */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x3)), 0x5); /* cmp byte ss:[bp+-0x3], 0x5 */
    if (cc_e(cpu)) goto L_fn_036F0_0000DA;   /* je 0x00DA */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x3))); /* mov al, byte ss:[bp+-0x3] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x5)), 0x0); /* cmp byte es:[bx+0x5], 0x0 */
    if (cc_e(cpu)) goto L_fn_036F0_0000DA;   /* je 0x00DA */
    goto L_fn_036F0_000240;                  /* jmp 0x0240 */
L_fn_036F0_0000DA:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4), (uint8_t)(0x0)); /* mov byte es:[bx+0x4], 0x0 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->bx = (uint16_t)(0x4);               /* mov bx, 0x4 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x00EE; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->bx = (uint16_t)(0x8);               /* mov bx, 0x8 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x00FF; recomp_div0("idiv16"); } } /* idiv bx */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    cpu->dx = (uint16_t)(0x26);              /* mov dx, 0x26 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_036F0_000123;                  /* jmp 0x0123 */
L_fn_036F0_00010E:;
    cpu->al = (uint8_t)(0x0);                /* mov al, 0x0 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->si)); /* add bx, si */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x26), (uint8_t)(cpu->al)); /* mov byte es:[bx+0x26], al */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->si), (uint8_t)(cpu->al)); /* mov byte es:[bx+si], al */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_036F0_000123:;
    flags_cmp16(cpu, cpu->di, 0x6);          /* cmp di, 0x6 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_036F0_00010E;   /* jl 0x010E */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3))); /* mov al, byte es:[bx+0x3] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1), (uint8_t)(cpu->al)); /* mov byte es:[bx+0x1], al */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov al, byte ss:[bp+-0x2] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2), (uint8_t)(cpu->al)); /* mov byte es:[bx+0x2], al */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3), (uint8_t)(cpu->al)); /* mov byte es:[bx+0x3], al */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov al, byte ss:[bp+-0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x38);              /* mov ax, 0x38 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x148)); /* add ax, 0x148 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov al, byte ss:[bp+-0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xCCC4 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov al, byte ss:[bp+-0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x38);              /* mov ax, 0x38 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x148)); /* add ax, 0x148 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov al, byte ss:[bp+-0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xCCC4 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02986(cpu);                           /* call 0xF296 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x2], al */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x1], al */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov al, byte ss:[bp+-0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x38);              /* mov ax, 0x38 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov al, byte ss:[bp+-0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xCCC4 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov al, byte ss:[bp+-0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->bx = (uint16_t)(0x4);               /* mov bx, 0x4 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0208; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->bx = (uint16_t)(0x8);               /* mov bx, 0x8 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0215; recomp_div0("idiv16"); } } /* idiv bx */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    cpu->dx = (uint16_t)(0x26);              /* mov dx, 0x26 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_036F0_000239;                  /* jmp 0x0239 */
L_fn_036F0_000224:;
    cpu->al = (uint8_t)(0x7);                /* mov al, 0x7 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->si)); /* add bx, si */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x26), (uint8_t)(cpu->al)); /* mov byte es:[bx+0x26], al */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + cpu->si), (uint8_t)(cpu->al)); /* mov byte es:[bx+si], al */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_036F0_000239:;
    flags_cmp16(cpu, cpu->di, 0x6);          /* cmp di, 0x6 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_036F0_000224;   /* jl 0x0224 */
    goto L_fn_036F0_000278;                  /* jmp 0x0278 */
L_fn_036F0_000240:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02986(cpu);                           /* call 0xF296 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov al, byte ss:[bp+-0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x38);              /* mov ax, 0x38 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov al, byte ss:[bp+-0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xCCC4 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
L_fn_036F0_000278:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0xA] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0xC))); /* add word ss:[bp+-0x8], 0xC */
L_fn_036F0_00027F:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* mov ax, word ss:[bp+-0xA] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC))); /* cmp ax, word ss:[bp+-0xC] */
    if (cc_ge(cpu)) goto L_fn_036F0_00028A;  /* jge 0x028A */
    RECOMP_TICK(cpu);
    goto L_fn_036F0_000038;                  /* jmp 0x0038 */
L_fn_036F0_00028A:;
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x9F)); /* mov word ds:[0x96], 0x9F */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_03986(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_03986");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov ax, word ds:[0xBFBA] */
    mem_write16(cpu, cpu->ds, 0x73E, (uint16_t)(cpu->ax)); /* mov word ds:[0x73E], ax */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x190)); /* mov word ds:[0x96], 0x190 */
    cpu->ax = (uint16_t)(0xB8);              /* mov ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04EEB(cpu);                           /* call 0x1565 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x9F)); /* mov word ds:[0x96], 0x9F */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x736), 0x8); /* cmp word ds:[0x736], 0x8 */
    if (cc_ge(cpu)) goto L_fn_03986_000033;  /* jge 0x0033 */
    cpu->si = (uint16_t)(0x8);               /* mov si, 0x8 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x28)); /* mov word ss:[bp+-0x4], 0x28 */
    goto L_fn_03986_000057;                  /* jmp 0x0057 */
L_fn_03986_000033:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x27)); /* add ax, 0x27 */
    flags_cmp16(cpu, cpu->ax, 0x137);        /* cmp ax, 0x137 */
    if (cc_le(cpu)) goto L_fn_03986_00004E;  /* jle 0x004E */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov si, word ds:[0x736] */
    cpu->ax = (uint16_t)(0x138);             /* mov ax, 0x138 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x736))); /* sub ax, word ds:[0x736] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    goto L_fn_03986_000057;                  /* jmp 0x0057 */
L_fn_03986_00004E:;
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov si, word ds:[0x736] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x28)); /* mov word ss:[bp+-0x4], 0x28 */
L_fn_03986_000057:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x738), 0x10); /* cmp word ds:[0x738], 0x10 */
    if (cc_ge(cpu)) goto L_fn_03986_000068;  /* jge 0x0068 */
    cpu->di = (uint16_t)(0x10);              /* mov di, 0x10 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x28)); /* mov word ss:[bp+-0x2], 0x28 */
    goto L_fn_03986_00008C;                  /* jmp 0x008C */
L_fn_03986_000068:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x27)); /* add ax, 0x27 */
    flags_cmp16(cpu, cpu->ax, 0x9F);         /* cmp ax, 0x9F */
    if (cc_le(cpu)) goto L_fn_03986_000083;  /* jle 0x0083 */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov di, word ds:[0x738] */
    cpu->ax = (uint16_t)(0xA0);              /* mov ax, 0xA0 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x738))); /* sub ax, word ds:[0x738] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    goto L_fn_03986_00008C;                  /* jmp 0x008C */
L_fn_03986_000083:;
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov di, word ds:[0x738] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(0x28)); /* mov word ss:[bp+-0x2], 0x28 */
L_fn_03986_00008C:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09F40(cpu);                           /* call 0x65BA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x9), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x9)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word es:[bx+0x9] */
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
    fn_07343(cpu);                           /* call 0x39BD */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A768(cpu);                           /* call 0x6DE2 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_03986_0000E9;   /* je 0x00E9 */
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x8BFE);            /* mov ax, 0x8BFE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F98B(cpu);                           /* call 0xC005 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_03986_0000E9:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_03A75(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_03A75");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x16)); /* sub sp, 0x16 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0x732, (uint16_t)(cpu->ax)); /* mov word ds:[0x732], ax */
    mem_write16(cpu, cpu->ds, 0x730, (uint16_t)(cpu->ax)); /* mov word ds:[0x730], ax */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    mem_write16(cpu, cpu->ds, 0x96E4, (uint16_t)(cpu->si)); /* mov word ds:[0x96E4], si */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    mem_write16(cpu, cpu->ds, 0x8FE, (uint16_t)(cpu->ax)); /* mov word ds:[0x8FE], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    mem_write16(cpu, cpu->ds, 0xB70, (uint16_t)(cpu->ax)); /* mov word ds:[0xB70], ax */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(cpu->ax)); /* mov word ds:[0xBC], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06997(cpu);                           /* call 0x2F22 */
L_fn_03A75_000030:;
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0x31E2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x16], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x10], ax */
    mem_write16(cpu, cpu->ds, 0x40CE, (uint16_t)(cpu->ax)); /* mov word ds:[0x40CE], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B4A(cpu);                           /* call 0x30D5 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_03A75_000070;   /* je 0x0070 */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x0)); /* mov word ds:[0xBC], 0x0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B1A(cpu);                           /* call 0x30A5 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x16], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16)), 0xD); /* cmp word ss:[bp+-0x16], 0xD */
    if (cc_ne(cpu)) goto L_fn_03A75_000061;  /* jne 0x0061 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0727D(cpu);                           /* call 0x3808 */
    goto L_fn_03A75_00006A;                  /* jmp 0x006A */
L_fn_03A75_000061:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16)), 0x1B); /* cmp word ss:[bp+-0x16], 0x1B */
    if (cc_ne(cpu)) goto L_fn_03A75_00006A;  /* jne 0x006A */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CE2A(cpu);                           /* call 0x93B5 */
L_fn_03A75_00006A:;
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x1)); /* mov word ds:[0xBC], 0x1 */
L_fn_03A75_000070:;
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5CA] */
    mem_write16(cpu, cpu->ds, 0x40C6, (uint16_t)(cpu->es)); /* mov word ds:[0x40C6], es */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->bx)); /* mov word ds:[0x40C4], bx */
    cpu->ax = (uint16_t)(0x27);              /* mov ax, 0x27 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xE);               /* mov ax, 0xE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    { int16_t _v = (int16_t)cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->ax = (uint16_t)((uint16_t)_r); } } /* sar ax, 0x1 */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D89A(cpu);                           /* call 0x9E25 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x14], ax */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_03A75_0000A0;  /* jne 0x00A0 */
    goto L_fn_03A75_00021A;                  /* jmp 0x021A */
L_fn_03A75_0000A0:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* mov ax, word ss:[bp+-0x14] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC))); /* cmp ax, word ss:[bp+-0xC] */
    if (cc_ne(cpu)) goto L_fn_03A75_0000AB;  /* jne 0x00AB */
    goto L_fn_03A75_00021A;                  /* jmp 0x021A */
L_fn_03A75_0000AB:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14)), 0x7); /* cmp word ss:[bp+-0x14], 0x7 */
    if (cc_l(cpu)) goto L_fn_03A75_0000B4;   /* jl 0x00B4 */
    goto L_fn_03A75_000144;                  /* jmp 0x0144 */
L_fn_03A75_0000B4:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* push word ss:[bp+-0x14] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D85F(cpu);                           /* call 0x9DEA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ss:[bp+-0x14] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* mov bx, word ss:[bp+-0x14] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x4380))); /* mov al, byte ds:[bx+0x4380] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* mov bx, word ss:[bp+-0x14] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x4386))); /* mov al, byte ds:[bx+0x4386] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xE], ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* mov bx, word ss:[bp+-0x14] */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x437A), (uint8_t)(0x0)); /* mov byte ds:[bx+0x437A], 0x0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08AA2(cpu);                           /* call 0x502D */
    mem_write16(cpu, cpu->ds, 0xB07A, (uint16_t)(cpu->ax)); /* mov word ds:[0xB07A], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5CA] */
    mem_write16(cpu, cpu->ds, 0x40C6, (uint16_t)(cpu->es)); /* mov word ds:[0x40C6], es */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->bx)); /* mov word ds:[0x40C4], bx */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* mov ax, word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* mov ax, word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x148)); /* add ax, 0x148 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xC93F */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* push word ss:[bp+-0xE] */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* mov ax, word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xC93F */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x907C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB07A), 0x0); /* cmp word ds:[0xB07A], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_000141;   /* je 0x0141 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02269(cpu);                           /* call 0xE7F4 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01ECD(cpu);                           /* call 0xE458 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_031C4(cpu);                           /* call 0xF74F */
L_fn_03A75_000141:;
    goto L_fn_03A75_00021A;                  /* jmp 0x021A */
L_fn_03A75_000144:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14)), 0x7); /* cmp word ss:[bp+-0x14], 0x7 */
    if (cc_e(cpu)) goto L_fn_03A75_00014D;   /* je 0x014D */
    goto L_fn_03A75_0001DB;                  /* jmp 0x01DB */
L_fn_03A75_00014D:;
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
    fn_0734E(cpu);                           /* call 0x38D9 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* push word ss:[bp+-0x14] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D85F(cpu);                           /* call 0x9DEA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3E5))); /* mov al, byte es:[bx+0x3E5] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3E6))); /* mov al, byte es:[bx+0x3E6] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xE], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x3E7), (uint8_t)(0x0)); /* mov byte es:[bx+0x3E7], 0x0 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* mov ax, word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* mov ax, word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x148)); /* add ax, 0x148 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xC93F */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* push word ss:[bp+-0xE] */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* mov ax, word ss:[bp+-0xE] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xC93F */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x907C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_03A75_00021A;                  /* jmp 0x021A */
L_fn_03A75_0001DB:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14)), 0x20); /* cmp word ss:[bp+-0x14], 0x20 */
    if (cc_ge(cpu)) goto L_fn_03A75_000209;  /* jge 0x0209 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* mov ax, word ss:[bp+-0x14] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFF8)); /* add ax, 0xFFF8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02A2D(cpu);                           /* call 0xEFB8 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1)), 0x2); /* cmp byte es:[bx+0x1], 0x2 */
    if (cc_e(cpu)) goto L_fn_03A75_000207;   /* je 0x0207 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0338A(cpu);                           /* call 0xF915 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_03A75_000207:;
    goto L_fn_03A75_00021A;                  /* jmp 0x021A */
L_fn_03A75_000209:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14)), 0x30); /* cmp word ss:[bp+-0x14], 0x30 */
    if (cc_ge(cpu)) goto L_fn_03A75_00021A;  /* jge 0x021A */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* mov ax, word ss:[bp+-0x14] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFE0)); /* add ax, 0xFFE0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_036F0(cpu);                           /* call 0xFC7B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_03A75_00021A:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* mov ax, word ss:[bp+-0x14] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40D0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40D0 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x40D0] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0x0); /* cmp byte es:[bx], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_00022D;   /* je 0x022D */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_060A9(cpu);                           /* call 0x2634 */
L_fn_03A75_00022D:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x8FE), 0x0); /* cmp word ds:[0x8FE], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_000237;   /* je 0x0237 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06021(cpu);                           /* call 0x25AC */
L_fn_03A75_000237:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB68), 0x0); /* cmp word ds:[0xB68], 0x0 */
    if (cc_ne(cpu)) goto L_fn_03A75_000241;  /* jne 0x0241 */
    goto L_fn_03A75_00030D;                  /* jmp 0x030D */
L_fn_03A75_000241:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x722), 0x0); /* cmp word ds:[0x722], 0x0 */
    if (cc_ne(cpu)) goto L_fn_03A75_00024B;  /* jne 0x024B */
    goto L_fn_03A75_00030D;                  /* jmp 0x030D */
L_fn_03A75_00024B:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14), (uint16_t)(0x0)); /* mov word ss:[bp+-0x14], 0x0 */
    goto L_fn_03A75_000301;                  /* jmp 0x0301 */
L_fn_03A75_000253:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* mov bx, word ss:[bp+-0x14] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x740C))); /* mov ax, word ds:[bx+-0x740C] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x738)); /* cmp ax, word ds:[0x738] */
    if (cc_le(cpu)) goto L_fn_03A75_000268;  /* jle 0x0268 */
    goto L_fn_03A75_0002FE;                  /* jmp 0x02FE */
L_fn_03A75_000268:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* mov bx, word ss:[bp+-0x14] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x740C))); /* mov ax, word ds:[bx+-0x740C] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x738)); /* cmp ax, word ds:[0x738] */
    if (cc_ge(cpu)) goto L_fn_03A75_00027C;  /* jge 0x027C */
    goto L_fn_03A75_0002FE;                  /* jmp 0x02FE */
L_fn_03A75_00027C:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* mov bx, word ss:[bp+-0x14] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x7416))); /* mov ax, word ds:[bx+-0x7416] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x736)); /* cmp ax, word ds:[0x736] */
    if (cc_le(cpu)) goto L_fn_03A75_00028E;  /* jle 0x028E */
    goto L_fn_03A75_0002FE;                  /* jmp 0x02FE */
    /* nop */                                /* nop */
L_fn_03A75_00028E:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* mov bx, word ss:[bp+-0x14] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x7416))); /* mov ax, word ds:[bx+-0x7416] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x10)); /* add ax, 0x10 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x736)); /* cmp ax, word ds:[0x736] */
    if (cc_l(cpu)) goto L_fn_03A75_0002FE;   /* jl 0x02FE */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x71E), 0x0); /* cmp word ds:[0x71E], 0x0 */
    if (cc_ne(cpu)) goto L_fn_03A75_0002BC;  /* jne 0x02BC */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x0)); /* mov word ds:[0xBC], 0x0 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* push word ss:[bp+-0x14] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0233E(cpu);                           /* call 0xE8C9 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_03A75_000A9C;                  /* jmp 0x0A9C */
    goto L_fn_03A75_0002FE;                  /* jmp 0x02FE */
L_fn_03A75_0002BC:;
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x0)); /* mov word ds:[0xBC], 0x0 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* push word ss:[bp+-0x14] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09DCC(cpu);                           /* call 0x6357 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x12], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12)), 0x0); /* cmp word ss:[bp+-0x12], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_0002EA;   /* je 0x02EA */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12)), 0x0); /* cmp word ss:[bp+-0x12], 0x0 */
    if (cc_le(cpu)) goto L_fn_03A75_0002E5;  /* jle 0x02E5 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* push word ss:[bp+-0x14] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0233E(cpu);                           /* call 0xE8C9 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_03A75_000A9C;                  /* jmp 0x0A9C */
L_fn_03A75_0002E5:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_03A75_000A9C;                  /* jmp 0x0A9C */
L_fn_03A75_0002EA:;
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5CA); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5CA + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5CA] */
    mem_write16(cpu, cpu->ds, 0x40C6, (uint16_t)(cpu->es)); /* mov word ds:[0x40C6], es */
    mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(cpu->bx)); /* mov word ds:[0x40C4], bx */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x1)); /* mov word ds:[0xBC], 0x1 */
    goto L_fn_03A75_00030D;                  /* jmp 0x030D */
L_fn_03A75_0002FE:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x14] */
L_fn_03A75_000301:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* mov ax, word ss:[bp+-0x14] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x722)); /* cmp ax, word ds:[0x722] */
    if (cc_ge(cpu)) goto L_fn_03A75_00030D;  /* jge 0x030D */
    RECOMP_TICK(cpu);
    goto L_fn_03A75_000253;                  /* jmp 0x0253 */
L_fn_03A75_00030D:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_022B1(cpu);                           /* call 0xE83C */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04E9F(cpu);                           /* call 0x142A */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x8FE), 0x0); /* cmp word ds:[0x8FE], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_00031D;   /* je 0x031D */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05E98(cpu);                           /* call 0x2423 */
L_fn_03A75_00031D:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_025B3(cpu);                           /* call 0xEB3E */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC0 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFC0] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0x0); /* cmp byte es:[bx], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_00032D;   /* je 0x032D */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D79C(cpu);                           /* call 0x9D27 */
L_fn_03A75_00032D:;
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC4 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFC4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0x0); /* cmp byte es:[bx], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_00033A;   /* je 0x033A */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D386(cpu);                           /* call 0x9911 */
L_fn_03A75_00033A:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB6E), 0x0); /* cmp word ds:[0xB6E], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_000394;   /* je 0x0394 */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_e(cpu)) goto L_fn_03A75_00034C;   /* je 0x034C */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB68), 0x0); /* cmp word ds:[0xB68], 0x0 */
    if (cc_ne(cpu)) goto L_fn_03A75_000392;  /* jne 0x0392 */
L_fn_03A75_00034C:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    mem_write16(cpu, cpu->ds, 0x73A, (uint16_t)(cpu->si)); /* mov word ds:[0x73A], si */
    cpu->ax = (uint16_t)(0x27);              /* mov ax, 0x27 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x21)); /* add ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F91(cpu);                           /* call 0xE51C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_03A75_000392;  /* jne 0x0392 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x734)); /* mov ax, word ds:[0x734] */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x736), cpu->ax))); /* add word ds:[0x736], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(0x1)); /* mov word ss:[bp+-0x10], 0x1 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x72E), 0x8); /* cmp word ds:[0x72E], 0x8 */
    if (cc_g(cpu)) goto L_fn_03A75_000392;   /* jg 0x0392 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x72E), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x72E] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x72E)); /* mov ax, word ds:[0x72E] */
    flags_cmp16(cpu, cpu->ax, 0x8);          /* cmp ax, 0x8 */
    if (cc_le(cpu)) goto L_fn_03A75_000392;  /* jle 0x0392 */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0x1)); /* mov word ds:[0x72E], 0x1 */
L_fn_03A75_000392:;
    goto L_fn_03A75_0003EB;                  /* jmp 0x03EB */
L_fn_03A75_000394:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB6C), 0x0); /* cmp word ds:[0xB6C], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_0003EB;   /* je 0x03EB */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_e(cpu)) goto L_fn_03A75_0003A6;   /* je 0x03A6 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB68), 0x0); /* cmp word ds:[0xB68], 0x0 */
    if (cc_ne(cpu)) goto L_fn_03A75_0003EB;  /* jne 0x03EB */
L_fn_03A75_0003A6:;
    mem_write16(cpu, cpu->ds, 0x73A, (uint16_t)(0x1)); /* mov word ds:[0x73A], 0x1 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    cpu->ax = (uint16_t)(0x27);              /* mov ax, 0x27 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x736)); /* push word ds:[0x736] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F91(cpu);                           /* call 0xE51C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_03A75_0003EB;  /* jne 0x03EB */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x734)); /* mov ax, word ds:[0x734] */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x736), cpu->ax))); /* sub word ds:[0x736], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(0xFFFF)); /* mov word ss:[bp+-0x10], 0xFFFF */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x72E), 0x8); /* cmp word ds:[0x72E], 0x8 */
    if (cc_g(cpu)) goto L_fn_03A75_0003EB;   /* jg 0x03EB */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x72E), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x72E] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x72E)); /* mov ax, word ds:[0x72E] */
    flags_cmp16(cpu, cpu->ax, 0x8);          /* cmp ax, 0x8 */
    if (cc_le(cpu)) goto L_fn_03A75_0003EB;  /* jle 0x03EB */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0x1)); /* mov word ds:[0x72E], 0x1 */
L_fn_03A75_0003EB:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB68), 0x0); /* cmp word ds:[0xB68], 0x0 */
    if (cc_ne(cpu)) goto L_fn_03A75_0003F5;  /* jne 0x03F5 */
    goto L_fn_03A75_0004CC;                  /* jmp 0x04CC */
L_fn_03A75_0003F5:;
    cpu->ax = (uint16_t)(0x27);              /* mov ax, 0x27 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x73A)); /* mov ax, word ds:[0x73A] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov dx, word ds:[0x736] */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 0x10)); /* add dx, 0x10 */
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, cpu->ax)); /* sub dx, ax */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F91(cpu);                           /* call 0xE51C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x80);      /* test ax, 0x80 */
    if (cc_ne(cpu)) goto L_fn_03A75_00041D;  /* jne 0x041D */
    goto L_fn_03A75_0004CC;                  /* jmp 0x04CC */
L_fn_03A75_00041D:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_ne(cpu)) goto L_fn_03A75_00045A;  /* jne 0x045A */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->bx = (uint16_t)(0x8);               /* mov bx, 0x8 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0428; recomp_div0("idiv16"); } } /* idiv bx */
    { uint16_t _r = cpu->dx | cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* or dx, dx */
    if (cc_ne(cpu)) goto L_fn_03A75_000455;  /* jne 0x0455 */
    cpu->ax = (uint16_t)(0x1D);              /* mov ax, 0x1D */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x14)); /* add ax, 0x14 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F91(cpu);                           /* call 0xE51C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x80);      /* test ax, 0x80 */
    if (cc_e(cpu)) goto L_fn_03A75_000450;   /* je 0x0450 */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x736), 0x4))); /* add word ds:[0x736], 0x4 */
    goto L_fn_03A75_000455;                  /* jmp 0x0455 */
L_fn_03A75_000450:;
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x736), 0x4))); /* sub word ds:[0x736], 0x4 */
L_fn_03A75_000455:;
    cpu->si = (uint16_t)(0x1);               /* mov si, 0x1 */
    goto L_fn_03A75_0004B6;                  /* jmp 0x04B6 */
L_fn_03A75_00045A:;
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFC)); /* add ax, 0xFFFC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xF)); /* add ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F17(cpu);                           /* call 0xE4A2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x80);      /* test ax, 0x80 */
    if (cc_e(cpu)) goto L_fn_03A75_000489;   /* je 0x0489 */
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x738), 0x4))); /* sub word ds:[0x738], 0x4 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    flags_cmp16(cpu, cpu->ax, 0x2);          /* cmp ax, 0x2 */
    if (cc_le(cpu)) goto L_fn_03A75_000487;  /* jle 0x0487 */
    cpu->si = (uint16_t)(0x1);               /* mov si, 0x1 */
L_fn_03A75_000487:;
    goto L_fn_03A75_0004B6;                  /* jmp 0x04B6 */
L_fn_03A75_000489:;
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xF)); /* add ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F17(cpu);                           /* call 0xE4A2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x80);      /* test ax, 0x80 */
    if (cc_e(cpu)) goto L_fn_03A75_0004B6;   /* je 0x04B6 */
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x738), 0x2))); /* sub word ds:[0x738], 0x2 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    flags_cmp16(cpu, cpu->ax, 0x2);          /* cmp ax, 0x2 */
    if (cc_le(cpu)) goto L_fn_03A75_0004B6;  /* jle 0x04B6 */
    cpu->si = (uint16_t)(0x1);               /* mov si, 0x1 */
L_fn_03A75_0004B6:;
    mem_write16(cpu, cpu->ds, 0x734, (uint16_t)(0x8)); /* mov word ds:[0x734], 0x8 */
    mem_write16(cpu, cpu->ds, 0x730, (uint16_t)(0x0)); /* mov word ds:[0x730], 0x0 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x13)); /* add ax, 0x13 */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(cpu->ax)); /* mov word ds:[0x72E], ax */
    goto L_fn_03A75_000510;                  /* jmp 0x0510 */
L_fn_03A75_0004CC:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB6A), 0x0); /* cmp word ds:[0xB6A], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_000510;   /* je 0x0510 */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_e(cpu)) goto L_fn_03A75_000510;   /* je 0x0510 */
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x26)); /* add ax, 0x26 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xF)); /* add ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F17(cpu);                           /* call 0xE4A2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x80);      /* test ax, 0x80 */
    if (cc_e(cpu)) goto L_fn_03A75_00050E;   /* je 0x050E */
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x738), 0x4))); /* add word ds:[0x738], 0x4 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    flags_cmp16(cpu, cpu->ax, 0x2);          /* cmp ax, 0x2 */
    if (cc_le(cpu)) goto L_fn_03A75_000504;  /* jle 0x0504 */
    cpu->si = (uint16_t)(0x1);               /* mov si, 0x1 */
L_fn_03A75_000504:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x13)); /* add ax, 0x13 */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(cpu->ax)); /* mov word ds:[0x72E], ax */
    goto L_fn_03A75_000510;                  /* jmp 0x0510 */
L_fn_03A75_00050E:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
L_fn_03A75_000510:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_e(cpu)) goto L_fn_03A75_000517;   /* je 0x0517 */
    goto L_fn_03A75_000752;                  /* jmp 0x0752 */
L_fn_03A75_000517:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x730), 0x0); /* cmp word ds:[0x730], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_000574;   /* je 0x0574 */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F17(cpu);                           /* call 0xE4A2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_03A75_00056B;  /* jne 0x056B */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x730)); /* mov bx, word ds:[0x730] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x740))); /* mov al, byte ds:[bx+0x740] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x738), cpu->ax))); /* sub word ds:[0x738], ax */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x730, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x730), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ds:[0x730] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x72E), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x72E] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x72E)); /* mov ax, word ds:[0x72E] */
    flags_cmp16(cpu, cpu->ax, 0xB);          /* cmp ax, 0xB */
    if (cc_le(cpu)) goto L_fn_03A75_00055D;  /* jle 0x055D */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0xB)); /* mov word ds:[0x72E], 0xB */
L_fn_03A75_00055D:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 0x0); /* cmp word ss:[bp+-0x10], 0x0 */
    if (cc_ne(cpu)) goto L_fn_03A75_000569;  /* jne 0x0569 */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0xA)); /* mov word ds:[0x72E], 0xA */
L_fn_03A75_000569:;
    goto L_fn_03A75_000571;                  /* jmp 0x0571 */
L_fn_03A75_00056B:;
    mem_write16(cpu, cpu->ds, 0x730, (uint16_t)(0x0)); /* mov word ds:[0x730], 0x0 */
L_fn_03A75_000571:;
    goto L_fn_03A75_000752;                  /* jmp 0x0752 */
L_fn_03A75_000574:;
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x2F)); /* add ax, 0x2F */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F17(cpu);                           /* call 0xE4A2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_03A75_0005B9;  /* jne 0x05B9 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x732), 0x0); /* cmp word ds:[0x732], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_00059F;   /* je 0x059F */
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x738), 0x8))); /* add word ds:[0x738], 0x8 */
    goto L_fn_03A75_0005AA;                  /* jmp 0x05AA */
L_fn_03A75_00059F:;
    mem_write16(cpu, cpu->ds, 0x732, (uint16_t)(0x1)); /* mov word ds:[0x732], 0x1 */
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x738), 0x2))); /* add word ds:[0x738], 0x2 */
L_fn_03A75_0005AA:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* mov ax, word ss:[bp+-0x10] */
    { uint16_t _r = cpu->ax & 0x1; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xA)); /* add ax, 0xA */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(cpu->ax)); /* mov word ds:[0x72E], ax */
    goto L_fn_03A75_000752;                  /* jmp 0x0752 */
L_fn_03A75_0005B9:;
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x28)); /* add ax, 0x28 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F17(cpu);                           /* call 0xE4A2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xA], ax */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_03A75_000615;  /* jne 0x0615 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x30)); /* add ax, 0x30 */
    cpu->bx = (uint16_t)(0x8);               /* mov bx, 0x8 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x05E3; recomp_div0("idiv16"); } } /* idiv bx */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov dx, word ds:[0x738] */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 0x28)); /* add dx, 0x28 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->dx)); /* sub ax, dx */
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x738), cpu->ax))); /* add word ds:[0x738], ax */
    mem_write16(cpu, cpu->ds, 0x732, (uint16_t)(0x0)); /* mov word ds:[0x732], 0x0 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* mov ax, word ss:[bp+-0x10] */
    { uint16_t _r = cpu->ax & 0x1; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xA)); /* add ax, 0xA */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(cpu->ax)); /* mov word ds:[0x72E], ax */
    cpu->ax = (uint16_t)(0xB);               /* mov ax, 0xB */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x907C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_03A75_000752;                  /* jmp 0x0752 */
L_fn_03A75_000615:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16)), 0x20); /* cmp word ss:[bp+-0x16], 0x20 */
    if (cc_ne(cpu)) goto L_fn_03A75_00066E;  /* jne 0x066E */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07277(cpu);                           /* call 0x3802 */
    flags_cmp16(cpu, cpu->ax, 0x1);          /* cmp ax, 0x1 */
    if (cc_ne(cpu)) goto L_fn_03A75_000669;  /* jne 0x0669 */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F17(cpu);                           /* call 0xE4A2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_03A75_000665;  /* jne 0x0665 */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x907C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x730, (uint16_t)(0x8)); /* mov word ds:[0x730], 0x8 */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0x9)); /* mov word ds:[0x72E], 0x9 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 0x0); /* cmp word ss:[bp+-0x10], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_00065D;   /* je 0x065D */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    goto L_fn_03A75_000660;                  /* jmp 0x0660 */
L_fn_03A75_00065D:;
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
L_fn_03A75_000660:;
    mem_write16(cpu, cpu->ds, 0x734, (uint16_t)(cpu->ax)); /* mov word ds:[0x734], ax */
    goto L_fn_03A75_000667;                  /* jmp 0x0667 */
L_fn_03A75_000665:;
    goto L_fn_03A75_0006C5;                  /* jmp 0x06C5 */
L_fn_03A75_000667:;
    goto L_fn_03A75_00066B;                  /* jmp 0x066B */
L_fn_03A75_000669:;
    goto L_fn_03A75_0006C5;                  /* jmp 0x06C5 */
L_fn_03A75_00066B:;
    goto L_fn_03A75_000752;                  /* jmp 0x0752 */
L_fn_03A75_00066E:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB68), 0x0); /* cmp word ds:[0xB68], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_0006C5;   /* je 0x06C5 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xB70), 0x0); /* cmp word ds:[0xB70], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_0006C5;   /* je 0x06C5 */
    cpu->ax = (uint16_t)(0x9);               /* mov ax, 0x9 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F17(cpu);                           /* call 0xE4A2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_03A75_0006C5;  /* jne 0x06C5 */
    mem_write16(cpu, cpu->ds, 0xB70, (uint16_t)(0x0)); /* mov word ds:[0xB70], 0x0 */
    mem_write16(cpu, cpu->ds, 0x730, (uint16_t)(0x5)); /* mov word ds:[0x730], 0x5 */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0x9)); /* mov word ds:[0x72E], 0x9 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 0x0); /* cmp word ss:[bp+-0x10], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_0006B4;   /* je 0x06B4 */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    goto L_fn_03A75_0006B7;                  /* jmp 0x06B7 */
L_fn_03A75_0006B4:;
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
L_fn_03A75_0006B7:;
    mem_write16(cpu, cpu->ds, 0x734, (uint16_t)(cpu->ax)); /* mov word ds:[0x734], ax */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x907C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_03A75_000752;                  /* jmp 0x0752 */
L_fn_03A75_0006C5:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)), 0x0); /* cmp word ss:[bp+-0x10], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_0006DA;   /* je 0x06DA */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x72E), 0x8); /* cmp word ds:[0x72E], 0x8 */
    if (cc_le(cpu)) goto L_fn_03A75_0006D8;  /* jle 0x06D8 */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0x1)); /* mov word ds:[0x72E], 0x1 */
L_fn_03A75_0006D8:;
    goto L_fn_03A75_0006E0;                  /* jmp 0x06E0 */
L_fn_03A75_0006DA:;
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(0x0)); /* mov word ds:[0x72E], 0x0 */
L_fn_03A75_0006E0:;
    flags_logic16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)) & 0x8); /* test word ss:[bp+-0xA], 0x8 */
    if (cc_e(cpu)) goto L_fn_03A75_00074C;   /* je 0x074C */
    flags_logic16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)) & 0x10); /* test word ss:[bp+-0xA], 0x10 */
    if (cc_e(cpu)) goto L_fn_03A75_00071C;   /* je 0x071C */
    cpu->ax = (uint16_t)(0x27);              /* mov ax, 0x27 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x736)); /* push word ds:[0x736] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F91(cpu);                           /* call 0xE51C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_03A75_00071A;  /* jne 0x071A */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x734)); /* mov ax, word ds:[0x734] */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x736), cpu->ax))); /* sub word ds:[0x736], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x736), 0xFFFC); /* cmp word ds:[0x736], 0xFFFC */
    if (cc_g(cpu)) goto L_fn_03A75_00071A;   /* jg 0x071A */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(0xFFEF)); /* mov word ds:[0x736], 0xFFEF */
L_fn_03A75_00071A:;
    goto L_fn_03A75_00074C;                  /* jmp 0x074C */
L_fn_03A75_00071C:;
    cpu->ax = (uint16_t)(0x27);              /* mov ax, 0x27 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x21)); /* add ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01F91(cpu);                           /* call 0xE51C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    flags_logic16(cpu, cpu->ax & 0x7);       /* test ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_03A75_00074C;  /* jne 0x074C */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x734)); /* mov ax, word ds:[0x734] */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x736), cpu->ax))); /* add word ds:[0x736], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x736), 0x130); /* cmp word ds:[0x736], 0x130 */
    if (cc_l(cpu)) goto L_fn_03A75_00074C;   /* jl 0x074C */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(0x131)); /* mov word ds:[0x736], 0x131 */
L_fn_03A75_00074C:;
    mem_write16(cpu, cpu->ds, 0x734, (uint16_t)(0x4)); /* mov word ds:[0x734], 0x4 */
L_fn_03A75_000752:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16)), 0x20); /* cmp word ss:[bp+-0x16], 0x20 */
    if (cc_ne(cpu)) goto L_fn_03A75_0007BB;  /* jne 0x07BB */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07277(cpu);                           /* call 0x3802 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x14], ax */
    flags_cmp16(cpu, cpu->ax, 0x2);          /* cmp ax, 0x2 */
    if (cc_ne(cpu)) goto L_fn_03A75_000795;  /* jne 0x0795 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x72C), 0x0); /* cmp word ds:[0x72C], 0x0 */
    if (cc_ne(cpu)) goto L_fn_03A75_000795;  /* jne 0x0795 */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07313(cpu);                           /* call 0x389E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, cpu->ax, 0xFFFF);       /* cmp ax, 0xFFFF */
    if (cc_e(cpu)) goto L_fn_03A75_00078B;   /* je 0x078B */
    mem_write16(cpu, cpu->ds, 0x72C, (uint16_t)(0x3A)); /* mov word ds:[0x72C], 0x3A */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(0x0)); /* mov word ss:[bp+-0x6], 0x0 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x907C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_03A75_000793;                  /* jmp 0x0793 */
L_fn_03A75_00078B:;
    cpu->ax = (uint16_t)(0x11);              /* mov ax, 0x11 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x907C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_03A75_000793:;
    goto L_fn_03A75_0007BB;                  /* jmp 0x07BB */
L_fn_03A75_000795:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14)), 0x0); /* cmp word ss:[bp+-0x14], 0x0 */
    if (cc_ne(cpu)) goto L_fn_03A75_0007BB;  /* jne 0x07BB */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_ne(cpu)) goto L_fn_03A75_0007BB;  /* jne 0x07BB */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x8FE), 0x0); /* cmp word ds:[0x8FE], 0x0 */
    if (cc_ne(cpu)) goto L_fn_03A75_0007B3;  /* jne 0x07B3 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05A3B(cpu);                           /* call 0x1FC6 */
    cpu->ax = (uint16_t)(0x14);              /* mov ax, 0x14 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x907C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_03A75_0007BB;                  /* jmp 0x07BB */
L_fn_03A75_0007B3:;
    cpu->ax = (uint16_t)(0x17);              /* mov ax, 0x17 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x907C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_03A75_0007BB:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x72C), 0x1); /* cmp word ds:[0x72C], 0x1 */
    if (cc_ne(cpu)) goto L_fn_03A75_0007C8;  /* jne 0x07C8 */
    mem_write16(cpu, cpu->ds, 0x72C, (uint16_t)(0x0)); /* mov word ds:[0x72C], 0x0 */
L_fn_03A75_0007C8:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04B0C(cpu);                           /* call 0x1097 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x738), 0x0); /* cmp word ds:[0x738], 0x0 */
    if (cc_ge(cpu)) goto L_fn_03A75_000818;  /* jge 0x0818 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov bx, word ds:[0xBFBA] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x43A0)), 0x0); /* cmp byte ds:[bx+0x43A0], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_000810;   /* je 0x0810 */
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(0x90)); /* mov word ds:[0x738], 0x90 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov bx, word ds:[0xBFBA] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x43A0))); /* mov al, byte ds:[bx+0x43A0] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xBFBA)); /* cmp ax, word ds:[0xBFBA] */
    if (cc_e(cpu)) goto L_fn_03A75_00080E;   /* je 0x080E */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov bx, word ds:[0xBFBA] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x43A0))); /* mov al, byte ds:[bx+0x43A0] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    mem_write16(cpu, cpu->ds, 0xBFBA, (uint16_t)(cpu->ax)); /* mov word ds:[0xBFBA], ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    mem_write16(cpu, cpu->ds, 0x8FE, (uint16_t)(cpu->ax)); /* mov word ds:[0x8FE], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0329F(cpu);                           /* call 0xF82A */
L_fn_03A75_00080E:;
    goto L_fn_03A75_000816;                  /* jmp 0x0816 */
L_fn_03A75_000810:;
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(0x0)); /* mov word ds:[0x738], 0x0 */
L_fn_03A75_000816:;
    goto L_fn_03A75_000864;                  /* jmp 0x0864 */
L_fn_03A75_000818:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x738), 0x90); /* cmp word ds:[0x738], 0x90 */
    if (cc_le(cpu)) goto L_fn_03A75_000864;  /* jle 0x0864 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov bx, word ds:[0xBFBA] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x43AA)), 0x0); /* cmp byte ds:[bx+0x43AA], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_00085E;   /* je 0x085E */
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(0x0)); /* mov word ds:[0x738], 0x0 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov bx, word ds:[0xBFBA] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x43AA))); /* mov al, byte ds:[bx+0x43AA] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xBFBA)); /* cmp ax, word ds:[0xBFBA] */
    if (cc_e(cpu)) goto L_fn_03A75_00085C;   /* je 0x085C */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov bx, word ds:[0xBFBA] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x43AA))); /* mov al, byte ds:[bx+0x43AA] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    mem_write16(cpu, cpu->ds, 0xBFBA, (uint16_t)(cpu->ax)); /* mov word ds:[0xBFBA], ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    mem_write16(cpu, cpu->ds, 0x8FE, (uint16_t)(cpu->ax)); /* mov word ds:[0x8FE], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0329F(cpu);                           /* call 0xF82A */
L_fn_03A75_00085C:;
    goto L_fn_03A75_000864;                  /* jmp 0x0864 */
L_fn_03A75_00085E:;
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(0x90)); /* mov word ds:[0x738], 0x90 */
L_fn_03A75_000864:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x736), 0xFFF0); /* cmp word ds:[0x736], 0xFFF0 */
    if (cc_ge(cpu)) goto L_fn_03A75_0008B1;  /* jge 0x08B1 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov bx, word ds:[0xBFBA] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x438C)), 0x0); /* cmp byte ds:[bx+0x438C], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_0008A9;   /* je 0x08A9 */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(0x120)); /* mov word ds:[0x736], 0x120 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov bx, word ds:[0xBFBA] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x438C))); /* mov al, byte ds:[bx+0x438C] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xBFBA)); /* cmp ax, word ds:[0xBFBA] */
    if (cc_e(cpu)) goto L_fn_03A75_0008A7;   /* je 0x08A7 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov bx, word ds:[0xBFBA] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x438C))); /* mov al, byte ds:[bx+0x438C] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    mem_write16(cpu, cpu->ds, 0xBFBA, (uint16_t)(cpu->ax)); /* mov word ds:[0xBFBA], ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    mem_write16(cpu, cpu->ds, 0x8FE, (uint16_t)(cpu->ax)); /* mov word ds:[0x8FE], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0329F(cpu);                           /* call 0xF82A */
L_fn_03A75_0008A7:;
    goto L_fn_03A75_0008AF;                  /* jmp 0x08AF */
L_fn_03A75_0008A9:;
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(0xFFF0)); /* mov word ds:[0x736], 0xFFF0 */
L_fn_03A75_0008AF:;
    goto L_fn_03A75_0008FD;                  /* jmp 0x08FD */
L_fn_03A75_0008B1:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x736), 0x130); /* cmp word ds:[0x736], 0x130 */
    if (cc_le(cpu)) goto L_fn_03A75_0008FD;  /* jle 0x08FD */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov bx, word ds:[0xBFBA] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x4396)), 0x0); /* cmp byte ds:[bx+0x4396], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_0008F7;   /* je 0x08F7 */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(0x0)); /* mov word ds:[0x736], 0x0 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov bx, word ds:[0xBFBA] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x4396))); /* mov al, byte ds:[bx+0x4396] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xBFBA)); /* cmp ax, word ds:[0xBFBA] */
    if (cc_e(cpu)) goto L_fn_03A75_0008F5;   /* je 0x08F5 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFBA)); /* mov bx, word ds:[0xBFBA] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x4396))); /* mov al, byte ds:[bx+0x4396] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    mem_write16(cpu, cpu->ds, 0xBFBA, (uint16_t)(cpu->ax)); /* mov word ds:[0xBFBA], ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    mem_write16(cpu, cpu->ds, 0x8FE, (uint16_t)(cpu->ax)); /* mov word ds:[0x8FE], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0329F(cpu);                           /* call 0xF82A */
L_fn_03A75_0008F5:;
    goto L_fn_03A75_0008FD;                  /* jmp 0x08FD */
L_fn_03A75_0008F7:;
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(0x130)); /* mov word ds:[0x736], 0x130 */
L_fn_03A75_0008FD:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x8FE), 0x0); /* cmp word ds:[0x8FE], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_000907;   /* je 0x0907 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05AC3(cpu);                           /* call 0x204E */
L_fn_03A75_000907:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6)), 0x0); /* cmp word ss:[bp+-0x6], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_000966;   /* je 0x0966 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ss:[bp+-0x6] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6)), 0x1A); /* cmp word ss:[bp+-0x6], 0x1A */
    if (cc_le(cpu)) goto L_fn_03A75_000936;  /* jle 0x0936 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x73A)); /* push word ds:[0x73A] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D4)); /* mov dx, word ds:[0x99D4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D2)); /* mov ax, word ds:[0x99D2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x39EC)); /* add ax, 0x39EC */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x738)); /* push word ds:[0x738] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x736)); /* push word ds:[0x736] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xC957 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    goto L_fn_03A75_000963;                  /* jmp 0x0963 */
L_fn_03A75_000936:;
    flags_logic16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6)) & 0x1); /* test word ss:[bp+-0x6], 0x1 */
    if (cc_e(cpu)) goto L_fn_03A75_000963;   /* je 0x0963 */
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
    ovl_call(cpu, 0x03CC);                           /* call 0xC957 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_03A75_000963:;
    goto L_fn_03A75_000A69;                  /* jmp 0x0A69 */
L_fn_03A75_000966:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x72C), 0x0); /* cmp word ds:[0x72C], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_0009B0;   /* je 0x09B0 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x96EE);            /* mov ax, 0x96EE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x738)); /* push word ds:[0x738] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x736)); /* push word ds:[0x736] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xC957 */
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
    ovl_call(cpu, 0x03CC);                           /* call 0xC957 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    goto L_fn_03A75_000A69;                  /* jmp 0x0A69 */
L_fn_03A75_0009B0:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x40CE), 0x0); /* cmp word ds:[0x40CE], 0x0 */
    if (cc_ne(cpu)) goto L_fn_03A75_0009BA;  /* jne 0x09BA */
    goto L_fn_03A75_000A3D;                  /* jmp 0x0A3D */
L_fn_03A75_0009BA:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x40CE)); /* cmp ax, word ds:[0x40CE] */
    if (cc_ne(cpu)) goto L_fn_03A75_0009C6;  /* jne 0x09C6 */
    goto L_fn_03A75_000A3D;                  /* jmp 0x0A3D */
    /* nop */                                /* nop */
L_fn_03A75_0009C6:;
    push16(cpu, mem_read16(cpu, cpu->ds, 0x73A)); /* push word ds:[0x73A] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D4)); /* mov dx, word ds:[0x99D4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D2)); /* mov ax, word ds:[0x99D2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x39EC)); /* add ax, 0x39EC */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x738)); /* push word ds:[0x738] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x736)); /* push word ds:[0x736] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xC957 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(0x1E)); /* mov word ss:[bp+-0x6], 0x1E */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x907C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01ECD(cpu);                           /* call 0xE458 */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x0)); /* mov word ds:[0xBC], 0x0 */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0734E(cpu);                           /* call 0x38D9 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_03A75_000A0E;  /* jne 0x0A0E */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_03986(cpu);                           /* call 0xFF11 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_03A75_000A9C;                  /* jmp 0x0A9C */
L_fn_03A75_000A0E:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0734E(cpu);                           /* call 0x38D9 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
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
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x1)); /* mov word ds:[0xBC], 0x1 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40CE)); /* mov ax, word ds:[0x40CE] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    goto L_fn_03A75_000A6C;                  /* jmp 0x0A6C */
    goto L_fn_03A75_000A63;                  /* jmp 0x0A63 */
L_fn_03A75_000A3D:;
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
    ovl_call(cpu, 0x03CC);                           /* call 0xC957 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_03A75_000A63:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x40CE)); /* mov ax, word ds:[0x40CE] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
L_fn_03A75_000A69:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01ECD(cpu);                           /* call 0xE458 */
L_fn_03A75_000A6C:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C6F(cpu);                           /* call 0x31FA */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x71E), 0x0); /* cmp word ds:[0x71E], 0x0 */
    if (cc_e(cpu)) goto L_fn_03A75_000A8E;   /* je 0x0A8E */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x96E4), 0x0); /* cmp word ds:[0x96E4], 0x0 */
    if (cc_ne(cpu)) goto L_fn_03A75_000A8E;  /* jne 0x0A8E */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x736), 0xBE); /* cmp word ds:[0x736], 0xBE */
    if (cc_le(cpu)) goto L_fn_03A75_000A8E;  /* jle 0x0A8E */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09AC7(cpu);                           /* call 0x6052 */
    mem_write16(cpu, cpu->ds, 0x96E4, (uint16_t)(0x1)); /* mov word ds:[0x96E4], 0x1 */
L_fn_03A75_000A8E:;
    RECOMP_TICK(cpu);
    goto L_fn_03A75_000030;                  /* jmp 0x0030 */
    mem_write16(cpu, cpu->ds, 0xBC, (uint16_t)(0x0)); /* mov word ds:[0xBC], 0x0 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_03A75_000A9C;                  /* jmp 0x0A9C */
L_fn_03A75_000A9C:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_04517(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_04517");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov di, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x73C)); /* mov ax, word ds:[0x73C] */
    flags_cmp16(cpu, cpu->ax, cpu->di);      /* cmp ax, di */
    if (cc_ne(cpu)) goto L_fn_04517_000015;  /* jne 0x0015 */
    goto L_fn_04517_000111;                  /* jmp 0x0111 */
L_fn_04517_000015:;
    mem_write16(cpu, cpu->ds, 0x73C, (uint16_t)(cpu->di)); /* mov word ds:[0x73C], di */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1015)); /* add ax, 0x1015 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x2055 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC5C6); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC5C6 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC5C6] */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_04517_000059;                  /* jmp 0x0059 */
L_fn_04517_000033:;
    cpu->ax = (uint16_t)(0x319);             /* mov ax, 0x319 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x319);             /* mov dx, 0x319 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(0x79BF);            /* mov bx, 0x79BF */
    cpu->cx = (uint16_t)(cpu->ds);           /* mov cx, ds */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0xAE31 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x31B))); /* add word ss:[bp+-0x4], 0x31B */
L_fn_04517_000059:;
    flags_cmp16(cpu, cpu->si, 0x5);          /* cmp si, 0x5 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_04517_000033;   /* jl 0x0033 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_04517_000088;                  /* jmp 0x0088 */
L_fn_04517_000062:;
    cpu->ax = (uint16_t)(0xBB);              /* mov ax, 0xBB */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0xBB);              /* mov dx, 0xBB */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(0x74A2);            /* mov bx, 0x74A2 */
    cpu->cx = (uint16_t)(cpu->ds);           /* mov cx, ds */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0xAE31 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0xBD))); /* add word ss:[bp+-0x4], 0xBD */
L_fn_04517_000088:;
    flags_cmp16(cpu, cpu->si, 0x6);          /* cmp si, 0x6 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_04517_000062;   /* jl 0x0062 */
    cpu->ax = (uint16_t)(0xAD2);             /* mov ax, 0xAD2 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x8C12);            /* mov ax, 0x8C12 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0xAE31 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x99D8)); /* push word ds:[0x99D8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x99D6)); /* push word ds:[0x99D6] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1019)); /* add ax, 0x1019 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_068AA(cpu);                           /* call 0x2393 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_04517_0000E6;                  /* jmp 0x00E6 */
L_fn_04517_0000BA:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x99D6); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x99D6 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x99D6] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D8)); /* mov cx, word ds:[0x99D8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D6)); /* mov bx, word ds:[0x99D6] */
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
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x72B4), (uint16_t)(cpu->dx)); /* mov word ds:[bx+0x72B4], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x72B2), (uint16_t)(cpu->ax)); /* mov word ds:[bx+0x72B2], ax */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_04517_0000E6:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x73C)); /* mov bx, word ds:[0x73C] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x724))); /* mov ax, word ds:[bx+0x724] */
    flags_cmp16(cpu, cpu->ax, cpu->si);      /* cmp ax, si */
    RECOMP_TICK(cpu);
    if (cc_g(cpu)) goto L_fn_04517_0000BA;   /* jg 0x00BA */
    goto L_fn_04517_00010C;                  /* jmp 0x010C */
L_fn_04517_0000F6:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x72B4)); /* mov dx, word ds:[0x72B4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x72B2)); /* mov ax, word ds:[0x72B2] */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x72B4), (uint16_t)(cpu->dx)); /* mov word ds:[bx+0x72B4], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x72B2), (uint16_t)(cpu->ax)); /* mov word ds:[bx+0x72B2], ax */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_04517_00010C:;
    flags_cmp16(cpu, cpu->si, 0x28);         /* cmp si, 0x28 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_04517_0000F6;   /* jl 0x00F6 */
L_fn_04517_000111:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0462E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0462E");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01D47(cpu);                           /* call 0xD719 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x9ADE)); /* push word ds:[0x9ADE] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EC0(cpu);                           /* call 0xD892 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_0462E_000016;   /* je 0x0016 */
    cpu->si = (uint16_t)(0x14);              /* mov si, 0x14 */
    goto L_fn_0462E_000021;                  /* jmp 0x0021 */
L_fn_0462E_000016:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x9ADE)); /* mov ax, word ds:[0x9ADE] */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    { int32_t _n = (int32_t)(((uint32_t)cpu->dx << 16) | cpu->ax); int16_t _d = (int16_t)cpu->bx; long long _q = _d ? (long long)_n / _d : 0; if (_d && _q >= -32768 && _q <= 32767) { cpu->ax = (uint16_t)(int16_t)_q; cpu->dx = (uint16_t)(int16_t)((long long)_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x001D; recomp_div0("idiv16"); } } /* idiv bx */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
L_fn_0462E_000021:;
    flags_cmp16(cpu, cpu->si, 0x15);         /* cmp si, 0x15 */
    if (cc_ne(cpu)) goto L_fn_0462E_000030;  /* jne 0x0030 */
    cpu->ax = (uint16_t)(0x42);              /* mov ax, 0x42 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x1F3E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0462E_00003A;                  /* jmp 0x003A */
L_fn_0462E_000030:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1000)); /* add ax, 0x1000 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x1F3E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0462E_00003A:;
    flags_cmp16(cpu, cpu->si, 0x14);         /* cmp si, 0x14 */
    if (cc_ne(cpu)) goto L_fn_0462E_00006A;  /* jne 0x006A */
    cpu->ax = (uint16_t)(0x2750);            /* mov ax, 0x2750 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x4374);            /* mov ax, 0x4374 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0xAD1A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xBB8);             /* mov ax, 0xBB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xB3AE);            /* mov ax, 0xB3AE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F304(cpu);                           /* call 0xACD6 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    goto L_fn_0462E_0000B6;                  /* jmp 0x00B6 */
L_fn_0462E_00006A:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ACE7(cpu);                           /* call 0x66B9 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_0462E_000076;   /* je 0x0076 */
    flags_cmp16(cpu, cpu->si, 0x14);         /* cmp si, 0x14 */
    if (cc_le(cpu)) goto L_fn_0462E_00007A;  /* jle 0x007A */
L_fn_0462E_000076:;
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_0462E_00007D;                  /* jmp 0x007D */
L_fn_0462E_00007A:;
    cpu->di = (uint16_t)(0x330C);            /* mov di, 0x330C */
L_fn_0462E_00007D:;
    cpu->ax = (uint16_t)(0x2750);            /* mov ax, 0x2750 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x4374);            /* mov ax, 0x4374 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C8)); /* mov dx, word ds:[0xC5C8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C6)); /* mov ax, word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->di)); /* add ax, di */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0xAD1A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->ax = (uint16_t)(0xBB8);             /* mov ax, 0xBB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xB3AE);            /* mov ax, 0xB3AE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C8)); /* mov dx, word ds:[0xC5C8] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5C6)); /* mov ax, word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->di)); /* add ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x2754)); /* add ax, 0x2754 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0xAD1A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_0462E_0000B6:;
    flags_cmp16(cpu, cpu->si, 0x14);         /* cmp si, 0x14 */
    if (cc_ge(cpu)) goto L_fn_0462E_0000C8;  /* jge 0x00C8 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0x4374)); /* mov al, byte ds:[0x4374] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _r = cpu->ax & 0x7F; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x7F */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04517(cpu);                           /* call 0xFEE9 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0462E_0000C8:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0xBFBA, (uint16_t)(cpu->ax)); /* mov word ds:[0xBFBA], ax */
    cpu->dx = (uint16_t)(0x3E8);             /* mov dx, 0x3E8 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x43B4)); /* add bx, 0x43B4 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->ds, 0xBFBE, (uint16_t)(cpu->es)); /* mov word ds:[0xBFBE], es */
    mem_write16(cpu, cpu->ds, 0xBFBC, (uint16_t)(cpu->bx)); /* mov word ds:[0xBFBC], bx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_04713(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_04713");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0462E(cpu);                           /* call 0xFF1B */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07DF1(cpu);                           /* call 0x36DE */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0x4375)); /* mov al, byte ds:[0x4375] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(cpu->ax)); /* mov word ds:[0x736], ax */
    { uint16_t _v = mem_read16(cpu, cpu->ds, 0x736); uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(_r)); } } /* shl word ds:[0x736], 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov ax, word ds:[0x736] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x3)); /* add ax, 0x3 */
    { int16_t _v = (int16_t)cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->ax = (uint16_t)((uint16_t)_r); } } /* sar ax, 0x1 */
    { int16_t _v = (int16_t)cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->ax = (uint16_t)((uint16_t)_r); } } /* sar ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    mem_write16(cpu, cpu->ds, 0x736, (uint16_t)(cpu->ax)); /* mov word ds:[0x736], ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0x4376)); /* mov al, byte ds:[0x4376] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ds, 0x738, (uint16_t)(cpu->ax)); /* mov word ds:[0x738], ax */
    flags_logic8(cpu, mem_read8(cpu, cpu->ds, 0x4374) & 0x80); /* test byte ds:[0x4374], 0x80 */
    if (cc_e(cpu)) goto L_fn_04713_00003B;   /* je 0x003B */
    mem_write16(cpu, cpu->ds, 0x73A, (uint16_t)(0x1)); /* mov word ds:[0x73A], 0x1 */
    goto L_fn_04713_000041;                  /* jmp 0x0041 */
L_fn_04713_00003B:;
    mem_write16(cpu, cpu->ds, 0x73A, (uint16_t)(0x0)); /* mov word ds:[0x73A], 0x0 */
L_fn_04713_000041:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0x72E, (uint16_t)(cpu->ax)); /* mov word ds:[0x72E], ax */
    mem_write16(cpu, cpu->ds, 0xB07A, (uint16_t)(cpu->ax)); /* mov word ds:[0xB07A], ax */
    mem_write16(cpu, cpu->ds, 0x72C, (uint16_t)(cpu->ax)); /* mov word ds:[0x72C], ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x9ADE)); /* push word ds:[0x9ADE] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EC0(cpu);                           /* call 0xD7AD */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_04713_000091;   /* je 0x0091 */
    mem_write16(cpu, cpu->ds, 0x722, (uint16_t)(0x3)); /* mov word ds:[0x722], 0x3 */
    cpu->ax = (uint16_t)(0xF4);              /* mov ax, 0xF4 */
    mem_write16(cpu, cpu->ds, 0x8BEE, (uint16_t)(cpu->ax)); /* mov word ds:[0x8BEE], ax */
    mem_write16(cpu, cpu->ds, 0x8BEC, (uint16_t)(cpu->ax)); /* mov word ds:[0x8BEC], ax */
    mem_write16(cpu, cpu->ds, 0x8BEA, (uint16_t)(cpu->ax)); /* mov word ds:[0x8BEA], ax */
    mem_write16(cpu, cpu->ds, 0x8BF4, (uint16_t)(0x12)); /* mov word ds:[0x8BF4], 0x12 */
    mem_write16(cpu, cpu->ds, 0x8BF6, (uint16_t)(0x42)); /* mov word ds:[0x8BF6], 0x42 */
    mem_write16(cpu, cpu->ds, 0x8BF8, (uint16_t)(0x72)); /* mov word ds:[0x8BF8], 0x72 */
    mem_write16(cpu, cpu->ds, 0x71E, (uint16_t)(0x1)); /* mov word ds:[0x71E], 0x1 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02AE2(cpu);                           /* call 0xE3CF */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x9ADE)); /* mov ax, word ds:[0x9ADE] */
    { int16_t _v = (int16_t)cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->ax = (uint16_t)((uint16_t)_r); } } /* sar ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09B68(cpu);                           /* call 0x5455 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_04713_0000A2;                  /* jmp 0x00A2 */
L_fn_04713_000091:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0x71E, (uint16_t)(cpu->ax)); /* mov word ds:[0x71E], ax */
    mem_write16(cpu, cpu->ds, 0x722, (uint16_t)(cpu->ax)); /* mov word ds:[0x722], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08A37(cpu);                           /* call 0x4324 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0726A(cpu);                           /* call 0x2B57 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02AE2(cpu);                           /* call 0xE3CF */
L_fn_04713_0000A2:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x73E), 0x0); /* cmp word ds:[0x73E], 0x0 */
    if (cc_ne(cpu)) goto L_fn_04713_0000C7;  /* jne 0x00C7 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0xBABB */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x130);             /* mov ax, 0x130 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A8);                           /* call 0xBC95 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_04713_0000C7:;
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x90);              /* mov ax, 0x90 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x130);             /* mov ax, 0x130 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09F40(cpu);                           /* call 0x582D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04EEB(cpu);                           /* call 0x07D8 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02269(cpu);                           /* call 0xDB56 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06FDA(cpu);                           /* call 0x28C7 */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0xBC8C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EB4(cpu);                           /* call 0xD7A1 */
    flags_cmp16(cpu, cpu->ax, 0x4);          /* cmp ax, 0x4 */
    if (cc_e(cpu)) goto L_fn_04713_000147;   /* je 0x0147 */
    flags_logic16(cpu, mem_read16(cpu, cpu->ds, 0x9ADE) & 0x7); /* test word ds:[0x9ADE], 0x7 */
    if (cc_ne(cpu)) goto L_fn_04713_000147;  /* jne 0x0147 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D4B3(cpu);                           /* call 0x8DA0 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D4B3(cpu);                           /* call 0x8DA0 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EB4(cpu);                           /* call 0xD7A1 */
    flags_cmp16(cpu, cpu->ax, 0x1);          /* cmp ax, 0x1 */
    if (cc_ne(cpu)) goto L_fn_04713_000137;  /* jne 0x0137 */
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D4B3(cpu);                           /* call 0x8DA0 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_04713_000147;                  /* jmp 0x0147 */
L_fn_04713_000137:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EB4(cpu);                           /* call 0xD7A1 */
    flags_cmp16(cpu, cpu->ax, 0x2);          /* cmp ax, 0x2 */
    if (cc_ne(cpu)) goto L_fn_04713_000147;  /* jne 0x0147 */
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D4B3(cpu);                           /* call 0x8DA0 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_04713_000147:;
    mem_write16(cpu, cpu->ds, 0x1776, (uint16_t)(0x1)); /* mov word ds:[0x1776], 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x9ADE)); /* push word ds:[0x9ADE] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EC0(cpu);                           /* call 0xD7AD */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_04713_00018A;  /* jne 0x018A */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EB4(cpu);                           /* call 0xD7A1 */
    flags_cmp16(cpu, cpu->ax, 0x4);          /* cmp ax, 0x4 */
    if (cc_e(cpu)) goto L_fn_04713_00017B;   /* je 0x017B */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EB4(cpu);                           /* call 0xD7A1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x9ADE)); /* mov dx, word ds:[0x9ADE] */
    { uint16_t _r = cpu->dx & 0x2; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* and dx, 0x2 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->dx)); /* add ax, dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1073)); /* add ax, 0x1073 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5F9(cpu);                           /* call 0x8EE6 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_04713_00018A;                  /* jmp 0x018A */
L_fn_04713_00017B:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EA5(cpu);                           /* call 0xD792 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1073)); /* add ax, 0x1073 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5F9(cpu);                           /* call 0x8EE6 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_04713_00018A:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_03A75(cpu);                           /* call 0xF362 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_e(cpu)) goto L_fn_04713_0001A5;   /* je 0x01A5 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x9ADE), 0x27); /* cmp word ds:[0x9ADE], 0x27 */
    if (cc_ne(cpu)) goto L_fn_04713_0001A5;  /* jne 0x01A5 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C15E(cpu);                           /* call 0x7A4B */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    mem_write16(cpu, cpu->ds, 0x9ADE, (uint16_t)(0x27)); /* mov word ds:[0x9ADE], 0x27 */
L_fn_04713_0001A5:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    goto L_fn_04713_0001A9;                  /* jmp 0x01A9 */
L_fn_04713_0001A9:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_048BE(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_048BE");
    push16(cpu, cpu->si);                    /* push si */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x5); /* cmp byte ds:[0xBFCD], 0x5 */
    if (cc_ne(cpu)) goto L_fn_048BE_000028;  /* jne 0x0028 */
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x1CAE */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, SEG_0000);                   /* push cs */
    cpu->ax = (uint16_t)(0x39C);             /* mov ax, 0x39C */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F39C(cpu);                           /* call 0xAADE */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    goto L_fn_048BE_00004D;                  /* jmp 0x004D */
L_fn_048BE_000028:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x2); /* cmp byte ds:[0xBFCD], 0x2 */
    if (cc_ne(cpu)) goto L_fn_048BE_00004D;  /* jne 0x004D */
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x1CAE */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, SEG_0000);                   /* push cs */
    cpu->ax = (uint16_t)(0x39C);             /* mov ax, 0x39C */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F39C(cpu);                           /* call 0xAADE */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_048BE_00004D:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0490D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0490D");
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0FA0F(cpu);                           /* call 0xB102 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F8FE(cpu);                           /* call 0xAFF1 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B7A(cpu);                           /* call 0x226D */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0625D(cpu);                           /* call 0x1950 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D344(cpu);                           /* call 0x8A37 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_048BE(cpu);                           /* call 0xFFB1 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00281(cpu);                           /* call 0xB974 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D555(cpu);                           /* call 0x8C48 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0695E(cpu);                           /* call 0x2051 */
    cpu->flags |= FLAG_IF;                   /* sti */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_021DB(cpu);                           /* call 0xD8CE */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_021A9(cpu);                           /* call 0xD89C */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CA6(cpu);                           /* call 0x2399 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->sp += 2; return;                    /* ret */
}

void fn_04943(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_04943");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc al */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC), (uint8_t)(cpu->al)); /* mov byte es:[bx+0xC], al */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->si)); /* add bx, si */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x16))); /* mov al, byte es:[bx+0x16] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->dx = (uint16_t)(cpu->si);           /* mov dx, si */
    { uint16_t _v = cpu->dx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shl dx, 0x1 */
    { uint16_t _v = cpu->dx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shl dx, 0x1 */
    { uint16_t _v = cpu->dx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shl dx, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->dx)); /* add ax, dx */
    mem_write16(cpu, cpu->ds, 0x9ADE, (uint16_t)(cpu->ax)); /* mov word ds:[0x9ADE], ax */
    mem_write16(cpu, cpu->ds, 0x73E, (uint16_t)(0xFFFF)); /* mov word ds:[0x73E], 0xFFFF */
    goto L_fn_04943_00009B;                  /* jmp 0x009B */
L_fn_04943_00004F:;
    push16(cpu, mem_read16(cpu, cpu->ds, 0x9ADE)); /* push word ds:[0x9ADE] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_01EC0(cpu);                           /* call 0xD57D */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_04943_00008E;   /* je 0x008E */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04713(cpu);                           /* call 0xFDD0 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_04943_000069;  /* jne 0x0069 */
    mem_write16(cpu, cpu->ds, 0x9ADE, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x9ADE), 0x2))); /* sub word ds:[0x9ADE], 0x2 */
    goto L_fn_04943_00008C;                  /* jmp 0x008C */
L_fn_04943_000069:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->si)); /* add bx, si */
    { int _cf = cf(cpu); mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x16), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x16)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc byte es:[bx+0x16] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x9ADE)); /* mov ax, word ds:[0x9ADE] */
    { uint16_t _r = cpu->ax & 0x7; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x7 */
    flags_cmp16(cpu, cpu->ax, 0x7);          /* cmp ax, 0x7 */
    if (cc_ne(cpu)) goto L_fn_04943_00008C;  /* jne 0x008C */
    goto L_fn_04943_00009D;                  /* jmp 0x009D */
L_fn_04943_00008C:;
    goto L_fn_04943_000097;                  /* jmp 0x0097 */
L_fn_04943_00008E:;
    goto L_fn_04943_000090;                  /* jmp 0x0090 */
L_fn_04943_000090:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04713(cpu);                           /* call 0xFDD0 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    RECOMP_TICK(cpu);
    if (cc_e(cpu)) goto L_fn_04943_000090;   /* je 0x0090 */
L_fn_04943_000097:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x9ADE, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x9ADE), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x9ADE] */
L_fn_04943_00009B:;
    RECOMP_TICK(cpu);
    goto L_fn_04943_00004F;                  /* jmp 0x004F */
L_fn_04943_00009D:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_049E3(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_049E3");
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0x8165 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C834(cpu);                           /* call 0x7E51 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0697D(cpu);                           /* call 0x1F9A */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06BAC(cpu);                           /* call 0x21C9 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_049F0(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_049F0");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_056C6(cpu);                           /* call 0x0CD6 */
    flags_cmp16(cpu, cpu->ax, 0xFFFF);       /* cmp ax, 0xFFFF */
    if (cc_ne(cpu)) goto L_fn_049F0_000013;  /* jne 0x0013 */
    goto L_fn_049F0_00009D;                  /* jmp 0x009D */
L_fn_049F0_000013:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0224C(cpu);                           /* call 0xD85C */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x8BFE);            /* mov ax, 0x8BFE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F953(cpu);                           /* call 0xAF63 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->si = (uint16_t)(0xFFFF);            /* mov si, 0xFFFF */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_071FB(cpu);                           /* call 0x280B */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5B3(cpu);                           /* call 0x8BC3 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09259(cpu);                           /* call 0x4869 */
    flags_cmp16(cpu, cpu->di, 0x3);          /* cmp di, 0x3 */
    if (cc_ne(cpu)) goto L_fn_049F0_000035;  /* jne 0x0035 */
    goto L_fn_049F0_00009D;                  /* jmp 0x009D */
L_fn_049F0_000035:;
    flags_cmp16(cpu, cpu->di, 0x2);          /* cmp di, 0x2 */
    if (cc_ge(cpu)) goto L_fn_049F0_000087;  /* jge 0x0087 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0AB66(cpu);                           /* call 0x6176 */
    flags_cmp16(cpu, cpu->ax, 0xFFFF);       /* cmp ax, 0xFFFF */
    if (cc_ne(cpu)) goto L_fn_049F0_000044;  /* jne 0x0044 */
    goto L_fn_049F0_00009D;                  /* jmp 0x009D */
L_fn_049F0_000044:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x15))); /* mov al, byte es:[bx+0x15] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07343(cpu);                           /* call 0x2953 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC))); /* mov al, byte es:[bx+0xC] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_049F0_000087;   /* je 0x0087 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ss:[bp+-0x2] */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov si, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04943(cpu);                           /* call 0xFF53 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_049F0_000087:;
    goto L_fn_049F0_000095;                  /* jmp 0x0095 */
L_fn_049F0_000089:;
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D26C(cpu);                           /* call 0x887C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04943(cpu);                           /* call 0xFF53 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_049F0_000095:;
    flags_cmp16(cpu, cpu->si, 0x4);          /* cmp si, 0x4 */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_049F0_000089;  /* jne 0x0089 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0AD25(cpu);                           /* call 0x6335 */
L_fn_049F0_00009D:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_04A93(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_04A93");
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0520A(cpu);                           /* call 0x0777 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_04A93_000013;   /* je 0x0013 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0490D(cpu);                           /* call 0xFE7A */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_049F0(cpu);                           /* call 0xFF5D */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_049E3(cpu);                           /* call 0xFF50 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0034F(cpu);                           /* call 0xB8BC */
L_fn_04A93_000013:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_04AA8(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_04AA8");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    flags_cmp16(cpu, cpu->ax, 0x137);        /* cmp ax, 0x137 */
    if (cc_g(cpu)) goto L_fn_04AA8_000062;   /* jg 0x0062 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    flags_cmp16(cpu, cpu->bx, 0x9F);         /* cmp bx, 0x9F */
    if (cc_g(cpu)) goto L_fn_04AA8_000062;   /* jg 0x0062 */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov cx, word ss:[bp+0x8] */
    cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, cpu->ax)); /* add cx, ax */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec cx */
    flags_cmp16(cpu, cpu->cx, 0x8);          /* cmp cx, 0x8 */
    if (cc_l(cpu)) goto L_fn_04AA8_000062;   /* jl 0x0062 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->bx)); /* add dx, bx */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    flags_cmp16(cpu, cpu->dx, 0x10);         /* cmp dx, 0x10 */
    if (cc_l(cpu)) goto L_fn_04AA8_000062;   /* jl 0x0062 */
    flags_cmp16(cpu, cpu->ax, 0x8);          /* cmp ax, 0x8 */
    if (cc_ge(cpu)) goto L_fn_04AA8_000032;  /* jge 0x0032 */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
L_fn_04AA8_000032:;
    flags_cmp16(cpu, cpu->cx, 0x137);        /* cmp cx, 0x137 */
    if (cc_le(cpu)) goto L_fn_04AA8_00003B;  /* jle 0x003B */
    cpu->cx = (uint16_t)(0x137);             /* mov cx, 0x137 */
L_fn_04AA8_00003B:;
    flags_cmp16(cpu, cpu->bx, 0x10);         /* cmp bx, 0x10 */
    if (cc_ge(cpu)) goto L_fn_04AA8_000043;  /* jge 0x0043 */
    cpu->bx = (uint16_t)(0x10);              /* mov bx, 0x10 */
L_fn_04AA8_000043:;
    flags_cmp16(cpu, cpu->dx, 0x9F);         /* cmp dx, 0x9F */
    if (cc_le(cpu)) goto L_fn_04AA8_00004C;  /* jle 0x004C */
    cpu->dx = (uint16_t)(0x9F);              /* mov dx, 0x9F */
L_fn_04AA8_00004C:;
    cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, cpu->ax)); /* sub cx, ax */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc cx */
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, cpu->bx)); /* sub dx, bx */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc dx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->cx);                    /* push cx */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xB8)); /* add bx, 0xB8 */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xB90C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
L_fn_04AA8_000062:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_04B0C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_04B0C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0xB6C2 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->di = (uint16_t)(0xB3AE);            /* mov di, 0xB3AE */
    { uint16_t _r = cpu->cx ^ cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* xor cx, cx */
    cpu->cl = (uint8_t)(mem_read8(cpu, cpu->ds, cpu->di)); /* mov cl, byte ds:[di] */
    { uint16_t _r = cpu->cx | cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* or cx, cx */
    if (cc_e(cpu)) goto L_fn_04B0C_00005F;   /* je 0x005F */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_04B0C_00001B:;
    push16(cpu, cpu->cx);                    /* push cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x1))); /* mov al, byte ds:[di+0x1] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xBFBA)); /* cmp ax, word ds:[0xBFBA] */
    if (cc_ne(cpu)) goto L_fn_04B0C_000059;  /* jne 0x0059 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, cpu->di)); /* mov al, byte ds:[di] */
    flags_cmp8(cpu, cpu->al, 0x1);           /* cmp al, 0x1 */
    if (cc_e(cpu)) goto L_fn_04B0C_000067;   /* je 0x0067 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0xA)), 0x0); /* cmp byte ds:[di+0xA], 0x0 */
    if (cc_ne(cpu)) goto L_fn_04B0C_000064;  /* jne 0x0064 */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0xD))); /* mov si, word ds:[di+0xD] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0xB3AE)); /* add si, 0xB3AE */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    cpu->bl = (uint8_t)(cpu->al);            /* mov bl, al */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x74A)); /* add bx, 0x74A */
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, cpu->ds, cpu->bx)); return; /* jmp word ds:[bx] */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 0xB3AE)); /* sub si, 0xB3AE */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->di + 0xD), (uint16_t)(cpu->si)); /* mov word ds:[di+0xD], si */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x1))); /* mov al, byte ds:[di+0x1] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xBFBA)); /* cmp ax, word ds:[0xBFBA] */
    if (cc_e(cpu)) goto L_fn_04B0C_00008C;   /* je 0x008C */
L_fn_04B0C_000059:;
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x20)); /* add di, 0x20 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_04B0C_00001B; /* loop 0x001B */
L_fn_04B0C_00005F:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
L_fn_04B0C_000064:;
    { int _cf = cf(cpu); mem_write8(cpu, cpu->ds, (uint16_t)(cpu->di + 0xA), (uint8_t)(flags_sub8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0xA)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec byte ds:[di+0xA] */
L_fn_04B0C_000067:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x8)), 0x1); /* cmp byte ds:[di+0x8], 0x1 */
    RECOMP_TICK(cpu);
    if (cc_e(cpu)) goto L_fn_04B0C_000059;   /* je 0x0059 */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->bl = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x7))); /* mov bl, byte ds:[di+0x7] */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bl = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x6))); /* mov bl, byte ds:[di+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F84)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx - 0x4F84) + 2)); cpu->ax = _o; cpu->es = _s; } /* les ax, word ds:[bx+-0x4F84] */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x4))); /* push word ds:[di+0x4] */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x2))); /* push word ds:[di+0x2] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xB8C0 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
L_fn_04B0C_00008C:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x8)), 0x1); /* cmp byte ds:[di+0x8], 0x1 */
    RECOMP_TICK(cpu);
    if (cc_e(cpu)) goto L_fn_04B0C_000059;   /* je 0x0059 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x1A)), 0x0); /* cmp byte ds:[di+0x1A], 0x0 */
    if (cc_e(cpu)) goto L_fn_04B0C_0000B2;   /* je 0x00B2 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x2))); /* mov ax, word ds:[di+0x2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x10)); /* add ax, 0x10 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x4))); /* mov bx, word ds:[di+0x4] */
    cpu->dl = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x1A))); /* mov dl, byte ds:[di+0x1A] */
    { uint8_t _r = cpu->dh ^ cpu->dh; flags_logic8(cpu, _r); cpu->dh = (uint8_t)(_r); } /* xor dh, dh */
    cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, cpu->dx)); /* sub bx, dx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0xB899 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_04B0C_0000B2:;
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->bl = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x6))); /* mov bl, byte ds:[di+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bl = (uint8_t)(flags_add8(cpu, cpu->bl, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x7)))); /* add bl, byte ds:[di+0x7] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x40D4))); /* mov ax, word ds:[bx+0x40D4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x2)); /* add bx, 0x2 */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x40D4))); /* mov cx, word ds:[bx+0x40D4] */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    { uint16_t _t = cpu->ch; cpu->ch = (uint8_t)(cpu->dl); cpu->dl = (uint8_t)(_t); } /* xchg ch, dl */
    cpu->bp = (uint16_t)(cpu->dx);           /* mov bp, dx */
    cpu->dl = (uint8_t)(cpu->ah);            /* mov dl, ah */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x2))); /* mov bx, word ds:[di+0x2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->bx)); /* add ax, bx */
    cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, cpu->bx)); /* add cx, bx */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x4))); /* mov bx, word ds:[di+0x4] */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->bx)); /* add dx, bx */
    cpu->bp = (uint16_t)(flags_add16(cpu, cpu->bp, cpu->bx)); /* add bp, bx */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x72E)); /* mov bx, word ds:[0x72E] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ds, 0x73A))); /* add bx, word ds:[0x73A] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->si = (uint16_t)(cpu->bx);           /* mov si, bx */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x79E)); /* add si, 0x79E */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    { uint16_t _t = cpu->ah; cpu->ah = (uint8_t)(cpu->bl); cpu->bl = (uint8_t)(_t); } /* xchg ah, bl */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x736))); /* add ax, word ds:[0x736] */
    flags_cmp16(cpu, cpu->ax, cpu->cx);      /* cmp ax, cx */
    if (cc_g(cpu)) goto L_fn_04B0C_00016A;   /* jg 0x016A */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ds, 0x738))); /* add bx, word ds:[0x738] */
    flags_cmp16(cpu, cpu->bx, cpu->bp);      /* cmp bx, bp */
    if (cc_g(cpu)) goto L_fn_04B0C_00016A;   /* jg 0x016A */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    { uint16_t _t = cpu->ah; cpu->ah = (uint8_t)(cpu->bl); cpu->bl = (uint8_t)(_t); } /* xchg ah, bl */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x736))); /* add ax, word ds:[0x736] */
    flags_cmp16(cpu, cpu->di, cpu->ax);      /* cmp di, ax */
    if (cc_g(cpu)) goto L_fn_04B0C_00016A;   /* jg 0x016A */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ds, 0x738))); /* add bx, word ds:[0x738] */
    flags_cmp16(cpu, cpu->dx, cpu->bx);      /* cmp dx, bx */
    if (cc_g(cpu)) goto L_fn_04B0C_00016A;   /* jg 0x016A */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x40CE), 0x0); /* cmp word ds:[0x40CE], 0x0 */
    if (cc_ne(cpu)) goto L_fn_04B0C_000136;  /* jne 0x0136 */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    push16(cpu, cpu->bx);                    /* push bx */
    mem_write16(cpu, cpu->ds, 0x40CE, (uint16_t)(cpu->bx)); /* mov word ds:[0x40CE], bx */
L_fn_04B0C_000136:;
    cpu->bl = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x19))); /* mov bl, byte ds:[di+0x19] */
    { uint8_t _r = cpu->bl | cpu->bl; flags_logic8(cpu, _r); cpu->bl = (uint8_t)(_r); } /* or bl, bl */
    if (cc_e(cpu)) goto L_fn_04B0C_00016E;   /* je 0x016E */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x1B)), 0x1); /* cmp byte ds:[di+0x1B], 0x1 */
    if (cc_e(cpu)) goto L_fn_04B0C_00016E;   /* je 0x016E */
    flags_cmp8(cpu, cpu->bl, 0x1);           /* cmp bl, 0x1 */
    if (cc_ne(cpu)) goto L_fn_04B0C_00014F;  /* jne 0x014F */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0x72C), 0x0); /* cmp byte ds:[0x72C], 0x0 */
    if (cc_e(cpu)) goto L_fn_04B0C_00016E;   /* je 0x016E */
L_fn_04B0C_00014F:;
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->di + 0xF), (uint16_t)(cpu->bx)); /* mov word ds:[di+0xF], bx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x11), (uint16_t)(cpu->bx)); /* mov word ds:[di+0x11], bx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x13), (uint16_t)(cpu->bx)); /* mov word ds:[di+0x13], bx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x15), (uint16_t)(cpu->bx)); /* mov word ds:[di+0x15], bx */
    { int _cf = cf(cpu); cpu->bl = (uint8_t)(flags_add8(cpu, cpu->bl, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bl */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x1B), (uint8_t)(cpu->bl)); /* mov byte ds:[di+0x1B], bl */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x17))); /* mov si, word ds:[di+0x17] */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->di + 0xD), (uint16_t)(cpu->si)); /* mov word ds:[di+0xD], si */
    goto L_fn_04B0C_00016E;                  /* jmp 0x016E */
L_fn_04B0C_00016A:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
L_fn_04B0C_00016E:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0x8FE), 0x0); /* cmp byte ds:[0x8FE], 0x0 */
    if (cc_e(cpu)) goto L_fn_04B0C_0001A3;   /* je 0x01A3 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0xA)), 0x0); /* cmp byte ds:[di+0xA], 0x0 */
    if (cc_ne(cpu)) goto L_fn_04B0C_0001A3;  /* jne 0x01A3 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC04E)); /* mov bx, word ds:[0xC04E] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3FB0))); /* mov bx, word ds:[bx+-0x3FB0] */
    flags_cmp16(cpu, cpu->bx, cpu->ax);      /* cmp bx, ax */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    if (cc_l(cpu)) goto L_fn_04B0C_0001A3;   /* jl 0x01A3 */
    flags_cmp16(cpu, cpu->bx, cpu->cx);      /* cmp bx, cx */
    if (cc_g(cpu)) goto L_fn_04B0C_0001A3;   /* jg 0x01A3 */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3F80))); /* mov ax, word ds:[bx+-0x3F80] */
    flags_cmp16(cpu, cpu->ax, cpu->dx);      /* cmp ax, dx */
    if (cc_l(cpu)) goto L_fn_04B0C_0001A3;   /* jl 0x01A3 */
    flags_cmp16(cpu, cpu->ax, cpu->bp);      /* cmp ax, bp */
    if (cc_g(cpu)) goto L_fn_04B0C_0001A3;   /* jg 0x01A3 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x9))); /* mov al, byte ds:[di+0x9] */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->di + 0xA), (uint8_t)(cpu->al)); /* mov byte ds:[di+0xA], al */
L_fn_04B0C_0001A3:;
    RECOMP_TICK(cpu);
    goto L_fn_04B0C_000059;                  /* jmp 0x0059 */
}

void fn_04E9F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_04E9F");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(0xB3AE);            /* mov di, 0xB3AE */
    { uint16_t _r = cpu->cx ^ cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* xor cx, cx */
    cpu->cl = (uint8_t)(mem_read8(cpu, cpu->ds, cpu->di)); /* mov cl, byte ds:[di] */
    { uint16_t _r = cpu->cx | cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* or cx, cx */
    if (cc_e(cpu)) goto L_fn_04E9F_000048;   /* je 0x0048 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_04E9F_000011:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x1))); /* mov al, byte ds:[di+0x1] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xBFBA)); /* cmp ax, word ds:[0xBFBA] */
    if (cc_ne(cpu)) goto L_fn_04E9F_000043;  /* jne 0x0043 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x8)), 0x1); /* cmp byte ds:[di+0x8], 0x1 */
    if (cc_e(cpu)) goto L_fn_04E9F_000043;   /* je 0x0043 */
    push16(cpu, cpu->cx);                    /* push cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x6))); /* mov al, byte ds:[di+0x6] */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x409A))); /* mov al, byte ds:[bx+-0x409A] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x6404))); /* mov al, byte ds:[bx+-0x6404] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x4))); /* mov ax, word ds:[di+0x4] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x2))); /* mov ax, word ds:[di+0x2] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04AA8(cpu);                           /* call 0xFC09 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_04E9F_000043:;
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x20)); /* add di, 0x20 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_04E9F_000011; /* loop 0x0011 */
L_fn_04E9F_000048:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_04EEB(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_04EEB");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0xB2E3 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(0xB3AE);            /* mov di, 0xB3AE */
    { uint16_t _r = cpu->cx ^ cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* xor cx, cx */
    cpu->cl = (uint8_t)(mem_read8(cpu, cpu->ds, cpu->di)); /* mov cl, byte ds:[di] */
    { uint16_t _r = cpu->cx | cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* or cx, cx */
    if (cc_e(cpu)) goto L_fn_04EEB_000074;   /* je 0x0074 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_04EEB_000019:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x1))); /* mov al, byte ds:[di+0x1] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xBFBA)); /* cmp ax, word ds:[0xBFBA] */
    if (cc_ne(cpu)) goto L_fn_04EEB_00006F;  /* jne 0x006F */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x8)), 0x1); /* cmp byte ds:[di+0x8], 0x1 */
    if (cc_e(cpu)) goto L_fn_04EEB_00006F;   /* je 0x006F */
    push16(cpu, cpu->cx);                    /* push cx */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->bl = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x7))); /* mov bl, byte ds:[di+0x7] */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bl = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x6))); /* mov bl, byte ds:[di+0x6] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4F84)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx - 0x4F84) + 2)); cpu->ax = _o; cpu->es = _s; } /* les ax, word ds:[bx+-0x4F84] */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x4)))); /* add ax, word ds:[di+0x4] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x2))); /* push word ds:[di+0x2] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xB4E1 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x1A)), 0x0); /* cmp byte ds:[di+0x1A], 0x0 */
    if (cc_e(cpu)) goto L_fn_04EEB_00006E;   /* je 0x006E */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x2))); /* mov ax, word ds:[di+0x2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x10)); /* add ax, 0x10 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->di + 0x4))); /* mov bx, word ds:[di+0x4] */
    cpu->dl = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->di + 0x1A))); /* mov dl, byte ds:[di+0x1A] */
    { uint8_t _r = cpu->dh ^ cpu->dh; flags_logic8(cpu, _r); cpu->dh = (uint8_t)(_r); } /* xor dh, dh */
    cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, cpu->dx)); /* sub bx, dx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A5);                           /* call 0xB4BA */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_04EEB_00006E:;
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_04EEB_00006F:;
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x20)); /* add di, 0x20 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_04EEB_000019; /* loop 0x0019 */
L_fn_04EEB_000074:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_04F63(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_04F63");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F2C0(cpu);                           /* call 0xA35D */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov di, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->cx = (uint16_t)(cpu->si);           /* mov cx, si */
    cpu->dx = (uint16_t)(cpu->di);           /* mov dx, di */
    cpu->ah = (uint8_t)(0x40);               /* mov ah, 0x40 */
    cpu->ds = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ds, word ss:[bp+-0x2] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_04F96(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_04F96");
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(0x1);               /* mov si, 0x1 */
    goto L_fn_04F96_000120;                  /* jmp 0x0120 */
L_fn_04F96_000007:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x6D); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x6D + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x6D] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { uint16_t _o = mem_read16(cpu, cpu->es, cpu->bx); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0x2D); /* cmp byte es:[bx], 0x2D */
    if (cc_e(cpu)) goto L_fn_04F96_000034;   /* je 0x0034 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x6D); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x6D + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x6D] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { uint16_t _o = mem_read16(cpu, cpu->es, cpu->bx); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->bx), 0x2F); /* cmp byte es:[bx], 0x2F */
    if (cc_e(cpu)) goto L_fn_04F96_000034;   /* je 0x0034 */
    goto L_fn_04F96_00011F;                  /* jmp 0x011F */
L_fn_04F96_000034:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x6D); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x6D + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x6D] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { uint16_t _o = mem_read16(cpu, cpu->es, cpu->bx); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1))); /* mov al, byte es:[bx+0x1] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->cx = (uint16_t)(0xE);               /* mov cx, 0xE */
    cpu->bx = (uint16_t)(0x4FF4);            /* mov bx, 0x4FF4 */
L_fn_04F96_00004E:;
    flags_cmp16(cpu, mem_read16(cpu, SEG_0000, cpu->bx), cpu->ax); /* cmp word cs:[bx], ax */
    if (cc_e(cpu)) goto L_fn_04F96_00005A;   /* je 0x005A */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_04F96_00004E; /* loop 0x004E */
    goto L_fn_04F96_00011F;                  /* jmp 0x011F */
L_fn_04F96_00005A:;
    { uint16_t _t = mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x1C)); /* jmp word cs:[bx+0x1C] */
      switch (_t) {
        case 0x5034: goto L_fn_04F96_00009E;
        case 0x502C: goto L_fn_04F96_000096;
        case 0x5052: goto L_fn_04F96_0000BC;
        case 0x5044: goto L_fn_04F96_0000AE;
        case 0x505A: goto L_fn_04F96_0000C4;
        case 0x503C: goto L_fn_04F96_0000A6;
        case 0x504B: goto L_fn_04F96_0000B5;
        default: recomp_dispatch(cpu, SEG_0000, _t); return;
      } }
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, cpu->di), cpu->al))); /* add byte ds:[di], al */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec cx */
    mem_write8(cpu, cpu->ds, cpu->di, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, cpu->di), cpu->cl))); /* add byte ds:[di], cl */
    push16(cpu, cpu->bx);                    /* push bx */
    mem_write8(cpu, cpu->ds, cpu->si, (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, cpu->si), cpu->dl))); /* add byte ds:[si], dl */
    push16(cpu, cpu->si);                    /* push si */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di)), cpu->ah))); /* add byte ss:[bp+di], ah */
    mem_write8(cpu, cpu->gs, (uint16_t)(cpu->bx + cpu->di), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->gs, (uint16_t)(cpu->bx + cpu->di)), cpu->ch))); /* add byte gs:[bx+di], ch */
    mem_write16(cpu, cpu->es, cpu->di, port_in16(cpu, cpu->dx)); cpu->di += df(cpu) ? -2 : 2; /* insw */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + cpu->di)), cpu->dh))); /* add byte ss:[bp+di], dh */
    if (cc_e(cpu)) goto L_fn_04F96_000078;   /* je 0x0078 */
L_fn_04F96_000078:;
    if (cc_be(cpu)) goto L_fn_04F96_00007A;  /* jbe 0x007A */
L_fn_04F96_00007A:;
    { uint8_t _r = cpu->al ^ 0x50; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* xor al, 0x50 */
    cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, 0x50)); /* sub al, 0x50 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    { int _cf = cf(cpu); cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc sp */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    push16(cpu, cpu->ax);                    /* push ax */
    flags_cmp8(cpu, cpu->al, 0x50);          /* cmp al, 0x50 */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec bx */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint8_t _r = cpu->al ^ 0x50; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* xor al, 0x50 */
    cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, 0x50)); /* sub al, 0x50 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    { int _cf = cf(cpu); cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc sp */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    push16(cpu, cpu->ax);                    /* push ax */
    flags_cmp8(cpu, cpu->al, 0x50);          /* cmp al, 0x50 */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_sub16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec bx */
    push16(cpu, cpu->ax);                    /* push ax */
L_fn_04F96_000096:;
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x1)); /* mov byte ds:[0xBFCD], 0x1 */
    goto L_fn_04F96_00011F;                  /* jmp 0x011F */
L_fn_04F96_00009E:;
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x2)); /* mov byte ds:[0xBFCD], 0x2 */
    goto L_fn_04F96_00011F;                  /* jmp 0x011F */
    /* nop */                                /* nop */
L_fn_04F96_0000A6:;
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x3)); /* mov byte ds:[0xBFCD], 0x3 */
    goto L_fn_04F96_00011F;                  /* jmp 0x011F */
    /* nop */                                /* nop */
L_fn_04F96_0000AE:;
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x4)); /* mov byte ds:[0xBFCD], 0x4 */
    goto L_fn_04F96_00011F;                  /* jmp 0x011F */
L_fn_04F96_0000B5:;
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x5)); /* mov byte ds:[0xBFCD], 0x5 */
    goto L_fn_04F96_00011F;                  /* jmp 0x011F */
L_fn_04F96_0000BC:;
    mem_write16(cpu, cpu->ds, 0x1778, (uint16_t)(0x0)); /* mov word ds:[0x1778], 0x0 */
    goto L_fn_04F96_00011F;                  /* jmp 0x011F */
L_fn_04F96_0000C4:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x6D); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x6D + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x6D] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { uint16_t _o = mem_read16(cpu, cpu->es, cpu->bx); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov al, byte es:[bx+0x2] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->cx = (uint16_t)(0x6);               /* mov cx, 0x6 */
    cpu->bx = (uint16_t)(0x5083);            /* mov bx, 0x5083 */
L_fn_04F96_0000DE:;
    flags_cmp16(cpu, mem_read16(cpu, SEG_0000, cpu->bx), cpu->ax); /* cmp word cs:[bx], ax */
    if (cc_e(cpu)) goto L_fn_04F96_0000E9;   /* je 0x00E9 */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_04F96_0000DE; /* loop 0x00DE */
    goto L_fn_04F96_00011D;                  /* jmp 0x011D */
L_fn_04F96_0000E9:;
    { uint16_t _t = mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0xC)); /* jmp word cs:[bx+0xC] */
      switch (_t) {
        case 0x50A3: goto L_fn_04F96_00010D;
        case 0x509B: goto L_fn_04F96_000105;
        case 0x50AB: goto L_fn_04F96_000115;
        default: recomp_dispatch(cpu, SEG_0000, _t); return;
      } }
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc cx */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di)), cpu->cl))); /* add byte ds:[bx+di], cl */
    push16(cpu, cpu->sp);                    /* push sp */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di), (uint8_t)(flags_add8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->di)), cpu->ah))); /* add byte ds:[bx+di], ah */
    { long long _r = (long long)(int16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + cpu->si))) * (int16_t)(0x74); cpu->ax = (uint16_t)((uint16_t)_r); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | ((_r != (int16_t)_r) ? (FLAG_CF|FLAG_OF) : 0); } /* imul ax, 0x74 */
    mem_write16(cpu, cpu->ds, 0x9B50, (uint16_t)(cpu->ax)); /* mov word ds:[0x9B50], ax */
    push16(cpu, cpu->ax);                    /* push ax */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    push16(cpu, cpu->ax);                    /* push ax */
    mem_write16(cpu, cpu->ds, 0x9B50, (uint16_t)(cpu->ax)); /* mov word ds:[0x9B50], ax */
    push16(cpu, cpu->ax);                    /* push ax */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    push16(cpu, cpu->ax);                    /* push ax */
L_fn_04F96_000105:;
    mem_write16(cpu, cpu->ds, 0x1778, (uint16_t)(0x0)); /* mov word ds:[0x1778], 0x0 */
    goto L_fn_04F96_00011D;                  /* jmp 0x011D */
L_fn_04F96_00010D:;
    mem_write16(cpu, cpu->ds, 0x1778, (uint16_t)(0x2)); /* mov word ds:[0x1778], 0x2 */
    goto L_fn_04F96_00011D;                  /* jmp 0x011D */
L_fn_04F96_000115:;
    mem_write16(cpu, cpu->ds, 0x1778, (uint16_t)(0x1)); /* mov word ds:[0x1778], 0x1 */
    goto L_fn_04F96_00011D;                  /* jmp 0x011D */
L_fn_04F96_00011D:;
    goto L_fn_04F96_00011F;                  /* jmp 0x011F */
L_fn_04F96_00011F:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_04F96_000120:;
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ds, 0x6B)); /* cmp si, word ds:[0x6B] */
    if (cc_ge(cpu)) goto L_fn_04F96_000129;  /* jge 0x0129 */
    RECOMP_TICK(cpu);
    goto L_fn_04F96_000007;                  /* jmp 0x0007 */
L_fn_04F96_000129:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_050C1(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_050C1");
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    int_handler(cpu, 0x11);                  /* int 0x11 */
    { uint16_t _r = cpu->ax & 0xC0; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xC0 */
    cpu->cl = (uint8_t)(0x6);                /* mov cl, 0x6 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, cl */
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc al */
    mem_write8(cpu, cpu->ds, 0xBFCC, (uint8_t)(cpu->al)); /* mov byte ds:[0xBFCC], al */
    cpu->sp += 2; return;                    /* ret */
}

void fn_050D2(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_050D2");
    push16(cpu, cpu->si);                    /* push si */
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x0)); /* mov byte ds:[0xBFCD], 0x0 */
    /* nop */                                /* nop */
    cpu->ah = (uint8_t)(0xF);                /* mov ah, 0xF */
    bios_int10(cpu);                         /* int 0x10 */
    flags_cmp8(cpu, cpu->al, 0x7);           /* cmp al, 0x7 */
    if (cc_ne(cpu)) goto L_fn_050D2_000012;  /* jne 0x0012 */
    goto L_fn_050D2_0000C0;                  /* jmp 0x00C0 */
L_fn_050D2_000012:;
    cpu->ax = (uint16_t)(0xF000);            /* mov ax, 0xF000 */
    cpu->es = (uint16_t)(cpu->ax);           /* mov es, ax */
    cpu->si = (uint16_t)(0xFFFE);            /* mov si, 0xFFFE */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->si), 0xFF); /* cmp byte es:[si], 0xFF */
    if (cc_ne(cpu)) goto L_fn_050D2_000037;  /* jne 0x0037 */
    cpu->si = (uint16_t)(0xC000);            /* mov si, 0xC000 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->si), 0x21); /* cmp byte es:[si], 0x21 */
    if (cc_ne(cpu)) goto L_fn_050D2_000037;  /* jne 0x0037 */
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x3)); /* mov byte ds:[0xBFCD], 0x3 */
    /* nop */                                /* nop */
    mem_write8(cpu, cpu->ds, 0x856, (uint8_t)(0x1)); /* mov byte ds:[0x856], 0x1 */
    goto L_fn_050D2_0000C0;                  /* jmp 0x00C0 */
L_fn_050D2_000037:;
    cpu->ax = (uint16_t)(0x1A00);            /* mov ax, 0x1A00 */
    bios_int10(cpu);                         /* int 0x10 */
    flags_cmp8(cpu, cpu->al, 0x1A);          /* cmp al, 0x1A */
    if (cc_ne(cpu)) goto L_fn_050D2_000082;  /* jne 0x0082 */
    flags_cmp8(cpu, cpu->bl, 0xA);           /* cmp bl, 0xA */
    if (cc_l(cpu)) goto L_fn_050D2_00004E;   /* jl 0x004E */
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x4)); /* mov byte ds:[0xBFCD], 0x4 */
    /* nop */                                /* nop */
    goto L_fn_050D2_0000C0;                  /* jmp 0x00C0 */
    /* nop */                                /* nop */
L_fn_050D2_00004E:;
    flags_cmp8(cpu, cpu->bl, 0x4);           /* cmp bl, 0x4 */
    if (cc_e(cpu)) goto L_fn_050D2_000058;   /* je 0x0058 */
    flags_cmp8(cpu, cpu->bl, 0x5);           /* cmp bl, 0x5 */
    if (cc_ne(cpu)) goto L_fn_050D2_000061;  /* jne 0x0061 */
L_fn_050D2_000058:;
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x1)); /* mov byte ds:[0xBFCD], 0x1 */
    /* nop */                                /* nop */
    goto L_fn_050D2_0000C0;                  /* jmp 0x00C0 */
    /* nop */                                /* nop */
L_fn_050D2_000061:;
    flags_cmp8(cpu, cpu->bl, 0x7);           /* cmp bl, 0x7 */
    if (cc_e(cpu)) goto L_fn_050D2_00006B;   /* je 0x006B */
    flags_cmp8(cpu, cpu->bl, 0x8);           /* cmp bl, 0x8 */
    if (cc_ne(cpu)) goto L_fn_050D2_000074;  /* jne 0x0074 */
L_fn_050D2_00006B:;
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x5)); /* mov byte ds:[0xBFCD], 0x5 */
    /* nop */                                /* nop */
    goto L_fn_050D2_0000C0;                  /* jmp 0x00C0 */
    /* nop */                                /* nop */
L_fn_050D2_000074:;
    flags_cmp8(cpu, cpu->bl, 0x2);           /* cmp bl, 0x2 */
    if (cc_ne(cpu)) goto L_fn_050D2_000082;  /* jne 0x0082 */
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x2)); /* mov byte ds:[0xBFCD], 0x2 */
    /* nop */                                /* nop */
    goto L_fn_050D2_0000C0;                  /* jmp 0x00C0 */
    /* nop */                                /* nop */
L_fn_050D2_000082:;
    cpu->bh = (uint8_t)(0xFF);               /* mov bh, 0xFF */
    cpu->cl = (uint8_t)(0xFF);               /* mov cl, 0xFF */
    cpu->ah = (uint8_t)(0x12);               /* mov ah, 0x12 */
    cpu->bl = (uint8_t)(0x10);               /* mov bl, 0x10 */
    bios_int10(cpu);                         /* int 0x10 */
    flags_cmp8(cpu, cpu->bh, 0x1);           /* cmp bh, 0x1 */
    if (cc_a(cpu)) goto L_fn_050D2_00009F;   /* ja 0x009F */
    flags_cmp8(cpu, cpu->cl, 0xF);           /* cmp cl, 0xF */
    if (cc_a(cpu)) goto L_fn_050D2_00009F;   /* ja 0x009F */
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x1)); /* mov byte ds:[0xBFCD], 0x1 */
    /* nop */                                /* nop */
    goto L_fn_050D2_0000C0;                  /* jmp 0x00C0 */
    /* nop */                                /* nop */
L_fn_050D2_00009F:;
    cpu->dx = (uint16_t)(0x3D4);             /* mov dx, 0x3D4 */
    cpu->al = (uint8_t)(0xF);                /* mov al, 0xF */
    port_out8(cpu, cpu->dx, cpu->al);        /* out dx, al */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    cpu->al = (uint8_t)(0x66);               /* mov al, 0x66 */
    port_out8(cpu, cpu->dx, cpu->al);        /* out dx, al */
    cpu->cx = (uint16_t)(0x100);             /* mov cx, 0x100 */
L_fn_050D2_0000AF:;
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_050D2_0000AF; /* loop 0x00AF */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    { uint16_t _t = cpu->al; cpu->al = (uint8_t)(cpu->ah); cpu->ah = (uint8_t)(_t); } /* xchg al, ah */
    port_out8(cpu, cpu->dx, cpu->al);        /* out dx, al */
    flags_cmp8(cpu, cpu->ah, 0x66);          /* cmp ah, 0x66 */
    if (cc_ne(cpu)) goto L_fn_050D2_0000C0;  /* jne 0x00C0 */
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x2)); /* mov byte ds:[0xBFCD], 0x2 */
    /* nop */                                /* nop */
L_fn_050D2_0000C0:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xBFCD), 0x1); /* cmp word ds:[0xBFCD], 0x1 */
    if (cc_ne(cpu)) goto L_fn_050D2_0000DA;  /* jne 0x00DA */
    cpu->ah = (uint8_t)(0x12);               /* mov ah, 0x12 */
    cpu->bl = (uint8_t)(0x10);               /* mov bl, 0x10 */
    bios_int10(cpu);                         /* int 0x10 */
    { uint8_t _r = cpu->bl | cpu->bl; flags_logic8(cpu, _r); cpu->bl = (uint8_t)(_r); } /* or bl, bl */
    if (cc_ne(cpu)) goto L_fn_050D2_0000EB;  /* jne 0x00EB */
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x2)); /* mov byte ds:[0xBFCD], 0x2 */
    /* nop */                                /* nop */
    goto L_fn_050D2_0000EB;                  /* jmp 0x00EB */
    /* nop */                                /* nop */
L_fn_050D2_0000DA:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xBFCD), 0x4); /* cmp word ds:[0xBFCD], 0x4 */
    if (cc_ne(cpu)) goto L_fn_050D2_0000E4;  /* jne 0x00E4 */
    goto L_fn_050D2_0000EB;                  /* jmp 0x00EB */
    /* nop */                                /* nop */
L_fn_050D2_0000E4:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xBFCD), 0x5); /* cmp word ds:[0xBFCD], 0x5 */
    if (cc_ne(cpu)) goto L_fn_050D2_0000EB;  /* jne 0x00EB */
L_fn_050D2_0000EB:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_051BF(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_051BF");
    mem_write16(cpu, cpu->ds, 0x1778, (uint16_t)(0x0)); /* mov word ds:[0x1778], 0x0 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xBFCD), 0x3); /* cmp word ds:[0xBFCD], 0x3 */
    if (cc_ne(cpu)) goto L_fn_051BF_000015;  /* jne 0x0015 */
    mem_write16(cpu, cpu->ds, 0x1778, (uint16_t)(0x1)); /* mov word ds:[0x1778], 0x1 */
    goto L_fn_051BF_00004A;                  /* jmp 0x004A */
L_fn_051BF_000015:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E54D(cpu);                           /* call 0x938E */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_051BF_000024;   /* je 0x0024 */
    mem_write16(cpu, cpu->ds, 0x1778, (uint16_t)(0x2)); /* mov word ds:[0x1778], 0x2 */
    goto L_fn_051BF_00004A;                  /* jmp 0x004A */
L_fn_051BF_000024:;
    cpu->ah = (uint8_t)(0xC0);               /* mov ah, 0xC0 */
    int_handler(cpu, 0x15);                  /* int 0x15 */
    { uint8_t _r = cpu->ah | cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* or ah, ah */
    if (cc_ne(cpu)) goto L_fn_051BF_00004A;  /* jne 0x004A */
    flags_cmp16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)), 0xBFC); /* cmp word es:[bx+0x2], 0xBFC */
    if (cc_ne(cpu)) goto L_fn_051BF_00004A;  /* jne 0x004A */
    cpu->cx = (uint16_t)(0xA);               /* mov cx, 0xA */
    cpu->dx = (uint16_t)(0x203);             /* mov dx, 0x203 */
L_fn_051BF_00003A:;
    cpu->al = (uint8_t)(0xA5);               /* mov al, 0xA5 */
    port_out8(cpu, cpu->dx, cpu->al);        /* out dx, al */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    flags_cmp8(cpu, cpu->al, 0xA5);          /* cmp al, 0xA5 */
    if (cc_ne(cpu)) goto L_fn_051BF_00004A;  /* jne 0x004A */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_051BF_00003A; /* loop 0x003A */
    mem_write16(cpu, cpu->ds, 0x1778, (uint16_t)(0x3)); /* mov word ds:[0x1778], 0x3 */
L_fn_051BF_00004A:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_0520A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0520A");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x6)); /* sub sp, 0x6 */
    push16(cpu, cpu->si);                    /* push si */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0x7D), 0x3); /* cmp byte ds:[0x7D], 0x3 */
    if (cc_b(cpu)) goto L_fn_0520A_00002B;   /* jb 0x002B */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x6D); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x6D + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x6D] */
    { uint16_t _o = mem_read16(cpu, cpu->es, cpu->bx); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1)), 0x3A); /* cmp byte es:[bx+0x1], 0x3A */
    if (cc_ne(cpu)) goto L_fn_0520A_00002B;  /* jne 0x002B */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x6D); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x6D + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x6D] */
    { uint16_t _o = mem_read16(cpu, cpu->es, cpu->bx); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x5], al */
    goto L_fn_0520A_000033;                  /* jmp 0x0033 */
L_fn_0520A_00002B:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F725(cpu);                           /* call 0xA51B */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0x41)); /* add al, 0x41 */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x5], al */
L_fn_0520A_000033:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0520A_00004C;                  /* jmp 0x004C */
L_fn_0520A_000037:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x5))); /* mov al, byte ss:[bp+-0x5] */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, cl */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xA22)); /* add bx, 0xA22 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0520A_00004C:;
    flags_cmp16(cpu, cpu->si, 0x3);          /* cmp si, 0x3 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0520A_000037;   /* jl 0x0037 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_050C1(cpu);                           /* call 0xFEB7 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_050D2(cpu);                           /* call 0xFEC8 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x0); /* cmp byte ds:[0xBFCD], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0520A_00006D;  /* jne 0x006D */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x859);             /* mov ax, 0x859 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04F63(cpu);                           /* call 0xFD59 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    recomp_dispatch(cpu, 0x531, 0xC); return; /* tail-jmp 0x00531C */ /* jmp 0x0112 */
L_fn_0520A_00006D:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_051BF(cpu);                           /* call 0xFFB5 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04F96(cpu);                           /* call 0xFD8C */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F3DA(cpu);                           /* call 0xA1D0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    flags_cmp16(cpu, cpu->dx, 0x3);          /* cmp dx, 0x3 */
    if (cc_g(cpu)) goto L_fn_0520A_000097;   /* jg 0x0097 */
    if (cc_l(cpu)) goto L_fn_0520A_000088;   /* jl 0x0088 */
    flags_cmp16(cpu, cpu->ax, 0xADA0);       /* cmp ax, 0xADA0 */
    if (cc_ae(cpu)) goto L_fn_0520A_000097;  /* jae 0x0097 */
L_fn_0520A_000088:;
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x8A8);             /* mov ax, 0x8A8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_04F63(cpu);                           /* call 0xFD59 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    recomp_dispatch(cpu, 0x531, 0xC); return; /* tail-jmp 0x00531C */ /* jmp 0x0112 */
    /* nop */                                /* nop */
L_fn_0520A_000097:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xBFCD)); /* mov al, byte ds:[0xBFCD] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    flags_cmp16(cpu, cpu->ax, 0x4);          /* cmp ax, 0x4 */
    if (cc_be(cpu)) goto L_fn_0520A_0000A4;  /* jbe 0x00A4 */
    recomp_dispatch(cpu, 0x531, 0x7); return; /* tail-jmp 0x005317 */ /* jmp 0x010D */
    /* nop */                                /* nop */
L_fn_0520A_0000A4:;
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    recomp_dispatch(cpu, SEG_0000, mem_read16(cpu, SEG_0000, (uint16_t)(cpu->bx + 0x52B7))); return; /* jmp word cs:[bx+0x52B7] */
    bcd_aad(cpu, 82);                        /* aad 0x52 */
    cpu->ss = (uint16_t)(pop16(cpu));        /* pop ss */
    push16(cpu, cpu->bx);                    /* push bx */
    bcd_aad(cpu, 82);                        /* aad 0x52 */
    recomp_dispatch(cpu, 0x531, 0x1); return; /* tail-jmp 0x005311 */ /* jmp 0x0107 */
}

void fn_052C1(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_052C1");
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x5); /* cmp word ss:[bp+-0x2], 0x5 */
    if (cc_g(cpu)) goto L_fn_052C1_000014;   /* jg 0x0014 */
    if (cc_l(cpu)) goto L_fn_052C1_00000F;   /* jl 0x000F */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x7720); /* cmp word ss:[bp+-0x4], 0x7720 */
    if (cc_ae(cpu)) goto L_fn_052C1_000014;  /* jae 0x0014 */
L_fn_052C1_00000F:;
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x1)); /* mov byte ds:[0xBFCD], 0x1 */
L_fn_052C1_000014:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x4); /* cmp word ss:[bp+-0x2], 0x4 */
    if (cc_g(cpu)) goto L_fn_052C1_000028;   /* jg 0x0028 */
    if (cc_l(cpu)) goto L_fn_052C1_000023;   /* jl 0x0023 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x4620); /* cmp word ss:[bp+-0x4], 0x4620 */
    if (cc_ae(cpu)) goto L_fn_052C1_000028;  /* jae 0x0028 */
L_fn_052C1_000023:;
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x2)); /* mov byte ds:[0xBFCD], 0x2 */
L_fn_052C1_000028:;
    goto L_fn_052C1_000056;                  /* jmp 0x0056 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x5); /* cmp word ss:[bp+-0x2], 0x5 */
    if (cc_l(cpu)) goto L_fn_052C1_000040;   /* jl 0x0040 */
    if (cc_ne(cpu)) goto L_fn_052C1_000039;  /* jne 0x0039 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x7720); /* cmp word ss:[bp+-0x4], 0x7720 */
    if (cc_b(cpu)) goto L_fn_052C1_000040;   /* jb 0x0040 */
L_fn_052C1_000039:;
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x5)); /* mov byte ds:[0xBFCD], 0x5 */
    goto L_fn_052C1_000054;                  /* jmp 0x0054 */
L_fn_052C1_000040:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x4); /* cmp word ss:[bp+-0x2], 0x4 */
    if (cc_g(cpu)) goto L_fn_052C1_000054;   /* jg 0x0054 */
    if (cc_l(cpu)) goto L_fn_052C1_00004F;   /* jl 0x004F */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x4620); /* cmp word ss:[bp+-0x4], 0x4620 */
    if (cc_ae(cpu)) goto L_fn_052C1_000054;  /* jae 0x0054 */
L_fn_052C1_00004F:;
    mem_write8(cpu, cpu->ds, 0xBFCD, (uint8_t)(0x2)); /* mov byte ds:[0xBFCD], 0x2 */
L_fn_052C1_000054:;
    goto L_fn_052C1_000056;                  /* jmp 0x0056 */
L_fn_052C1_000056:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_052C1_00005B;                  /* jmp 0x005B */
L_fn_052C1_00005B:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_05321(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_05321");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0xE)); /* sub sp, 0xE */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(0x0)); /* mov word ss:[bp+-0xE], 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(0x0)); /* mov word ss:[bp+-0xA], 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(0x0)); /* mov word ss:[bp+-0xC], 0x0 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x0)); /* mov word ss:[bp+-0x4], 0x0 */
    goto L_fn_05321_000055;                  /* jmp 0x0055 */
L_fn_05321_00001C:;
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x2)); /* lea ax, word ss:[bp+-0x2] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x4)); /* lea ax, word ss:[bp+-0x4] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x6)); /* lea ax, word ss:[bp+-0x6] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x8)); /* lea ax, word ss:[bp+-0x8] */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0xC)); /* lea ax, word ss:[bp+-0xC] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0xE)); /* lea ax, word ss:[bp+-0xE] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* push word ss:[bp+0xE] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* push word ss:[bp+0xC] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05382(cpu);                           /* call 0x0061 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x26)); /* add sp, 0x26 */
L_fn_05321_000055:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE))); /* mov ax, word ss:[bp+-0xE] */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* cmp ax, word ss:[bp+0x8] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_05321_00001C;   /* jl 0x001C */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_05382(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_05382");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x16)); /* sub sp, 0x16 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x12)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x12) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x12] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov dx, word es:[bx+0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    flags_cmp16(cpu, cpu->dx, mem_read16(cpu, cpu->ds, 0xB78)); /* cmp dx, word ds:[0xB78] */
    if (cc_b(cpu)) goto L_fn_05382_000023;   /* jb 0x0023 */
    if (cc_a(cpu)) goto L_fn_05382_000020;   /* ja 0x0020 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xB76)); /* cmp ax, word ds:[0xB76] */
    if (cc_be(cpu)) goto L_fn_05382_000023;  /* jbe 0x0023 */
L_fn_05382_000020:;
    goto L_fn_05382_0001D3;                  /* jmp 0x01D3 */
L_fn_05382_000023:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0xE) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0xE] */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov si, word es:[bx] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->es, cpu->bx), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word es:[bx] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x16], ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov di, word es:[bx+0x2] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x16)))); /* add di, word ss:[bp+0x16] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4))); /* mov ax, word es:[bx+0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x18)))); /* add ax, word ss:[bp+0x18] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x14], ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x6))); /* mov ax, word es:[bx+0x6] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x12], ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x8))); /* mov ax, word es:[bx+0x8] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x10], ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xA))); /* mov ax, word es:[bx+0xA] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xE], ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC))); /* mov ax, word es:[bx+0xC] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xC], ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xE))); /* mov ax, word es:[bx+0xE] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xA], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16))); /* mov ax, word ss:[bp+-0x16] */
    flags_cmp16(cpu, cpu->ax, 0xFFFE);       /* cmp ax, 0xFFFE */
    if (cc_e(cpu)) goto L_fn_05382_0000F8;   /* je 0x00F8 */
    flags_cmp16(cpu, cpu->ax, 0xFFFF);       /* cmp ax, 0xFFFF */
    if (cc_e(cpu)) goto L_fn_05382_0000CD;   /* je 0x00CD */
    goto L_fn_05382_000103;                  /* jmp 0x0103 */
L_fn_05382_0000CD:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* push word ss:[bp+-0x14] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* push word ss:[bp+-0x10] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12))); /* push word ss:[bp+-0x12] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* mov ax, word ss:[bp+-0x14] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC8)); /* add ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xB032 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* push word ss:[bp+-0x10] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12))); /* push word ss:[bp+-0x12] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* push word ss:[bp+-0x14] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0xB01D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    goto L_fn_05382_0001D3;                  /* jmp 0x01D3 */
L_fn_05382_0000F8:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0x77C6 */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x776F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_05382_0001D3;                  /* jmp 0x01D3 */
L_fn_05382_000103:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)), 0x0); /* cmp word ss:[bp+-0xA], 0x0 */
    if (cc_e(cpu)) goto L_fn_05382_000122;   /* je 0x0122 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* mov ax, word ss:[bp+-0xA] */
    { uint32_t _r = (uint32_t)cpu->ax * mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul word ss:[bp+0x8] */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xB76))); /* add ax, word ds:[0xB76] */
    cpu->dx = (uint16_t)(flags_adc(cpu, cpu->dx, mem_read16(cpu, cpu->ds, 0xB78), 16)); /* adc dx, word ds:[0xB78] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x12)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x12) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x12] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2), (uint16_t)(cpu->dx)); /* mov word es:[bx+0x2], dx */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(cpu->ax)); /* mov word es:[bx], ax */
L_fn_05382_000122:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x1A)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x1A) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x1A] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x1E)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x1E) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x1E] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x22)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x22) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x22] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x26)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x26) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x26] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x0); /* cmp word ss:[bp+-0x4], 0x0 */
    if (cc_e(cpu)) goto L_fn_05382_000168;   /* je 0x0168 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov ax, word ss:[bp+-0x6] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC8)); /* add ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0xB032 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
L_fn_05382_000168:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC))); /* push word ss:[bp+-0xC] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16))); /* mov ax, word ss:[bp+-0x16] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0xA) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0xA] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* push word es:[bx+0x2] */
    push16(cpu, mem_read16(cpu, cpu->es, cpu->bx)); /* push word es:[bx] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* push word ss:[bp+-0x14] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xB04A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x0); /* cmp word ss:[bp+-0x4], 0x0 */
    if (cc_e(cpu)) goto L_fn_05382_0001A0;   /* je 0x01A0 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0xB01D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_05382_0001A0:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* push word ss:[bp+-0x10] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12))); /* push word ss:[bp+-0x12] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* push word ss:[bp+-0x14] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0xB01D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x1A)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x1A) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x1A] */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(cpu->di)); /* mov word es:[bx], di */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14))); /* mov ax, word ss:[bp+-0x14] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x1E)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x1E) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x1E] */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(cpu->ax)); /* mov word es:[bx], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12))); /* mov ax, word ss:[bp+-0x12] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x22)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x22) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x22] */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(cpu->ax)); /* mov word es:[bx], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* mov ax, word ss:[bp+-0x10] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x26)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x26) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x26] */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(cpu->ax)); /* mov word es:[bx], ax */
    goto L_fn_05382_0001D3;                  /* jmp 0x01D3 */
L_fn_05382_0001D3:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0555B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0555B");
    cpu->ax = (uint16_t)(0x33);              /* mov ax, 0x33 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x1011 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0xAE6E */
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
    ovl_call(cpu, 0x03B4);                           /* call 0xAE59 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->sp += 2; return;                    /* ret */
}

void fn_05593(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_05593");
    goto L_fn_05593_000027;                  /* jmp 0x0027 */
L_fn_05593_000002:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B4A(cpu);                           /* call 0x15B7 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_05593_000027;   /* je 0x0027 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B1A(cpu);                           /* call 0x1587 */
    mem_write16(cpu, cpu->ds, 0x8FC, (uint16_t)(cpu->ax)); /* mov word ds:[0x8FC], ax */
    flags_cmp16(cpu, cpu->ax, 0xD);          /* cmp ax, 0xD */
    if (cc_ne(cpu)) goto L_fn_05593_00001B;  /* jne 0x001B */
    cpu->ax = (uint16_t)(0xD);               /* mov ax, 0xD */
    goto L_fn_05593_000033;                  /* jmp 0x0033 */
    goto L_fn_05593_000027;                  /* jmp 0x0027 */
L_fn_05593_00001B:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x8FC), 0x1B); /* cmp word ds:[0x8FC], 0x1B */
    if (cc_ne(cpu)) goto L_fn_05593_000027;  /* jne 0x0027 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x8FC)); /* mov ax, word ds:[0x8FC] */
    goto L_fn_05593_000033;                  /* jmp 0x0033 */
L_fn_05593_000027:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C87(cpu);                           /* call 0x16F4 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    RECOMP_TICK(cpu);
    if (cc_e(cpu)) goto L_fn_05593_000002;   /* je 0x0002 */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_05593_000033;                  /* jmp 0x0033 */
L_fn_05593_000033:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_055C7(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_055C7");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xBFDE);            /* mov ax, 0xBFDE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x34);              /* mov ax, 0x34 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0x1283 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_055C7_000041;                  /* jmp 0x0041 */
L_fn_055C7_000015:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFDE); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFDE + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFDE] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFE0)); /* mov cx, word ds:[0xBFE0] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFDE)); /* mov bx, word ds:[0xBFDE] */
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
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4010), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4010], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4012), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4012], ax */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_055C7_000041:;
    flags_cmp16(cpu, cpu->si, 0x9);          /* cmp si, 0x9 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_055C7_000015;   /* jl 0x0015 */
    cpu->si = (uint16_t)(0x9);               /* mov si, 0x9 */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_055C7_000072;                  /* jmp 0x0072 */
L_fn_055C7_00004D:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0x2A2);             /* mov dx, 0x2A2 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D4)); /* mov cx, word ds:[0x99D4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D2)); /* mov bx, word ds:[0x99D2] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4010), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4010], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4012), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4012], ax */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_055C7_000072:;
    flags_cmp16(cpu, cpu->di, 0x9);          /* cmp di, 0x9 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_055C7_00004D;   /* jl 0x004D */
    cpu->si = (uint16_t)(0x12);              /* mov si, 0x12 */
    cpu->di = (uint16_t)(0xC);               /* mov di, 0xC */
    goto L_fn_055C7_0000A4;                  /* jmp 0x00A4 */
L_fn_055C7_00007F:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->dx = (uint16_t)(0x2A2);             /* mov dx, 0x2A2 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D4)); /* mov cx, word ds:[0x99D4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x99D2)); /* mov bx, word ds:[0x99D2] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4010), (uint16_t)(cpu->dx)); /* mov word ds:[bx+-0x4010], dx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x4012), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x4012], ax */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_055C7_0000A4:;
    flags_cmp16(cpu, cpu->di, 0x10);         /* cmp di, 0x10 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_055C7_00007F;   /* jl 0x007F */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_05673(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_05673");
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xBFF0)); /* push word ds:[0xBFF0] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xBFEE)); /* push word ds:[0xBFEE] */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xAD59 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0568C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0568C");
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_07676(cpu);                           /* call 0x1FEA */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x98);              /* mov ax, 0x98 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xE8);              /* mov ax, 0xE8 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09F40(cpu);                           /* call 0x48B4 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05673(cpu);                           /* call 0xFFE7 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_075F3(cpu);                           /* call 0x1F67 */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0xAD13 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->sp += 2; return;                    /* ret */
}

void fn_056C6(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_056C6");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->si = (uint16_t)(0x1);               /* mov si, 0x1 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x857), 0x0); /* cmp word ds:[0x857], 0x0 */
    if (cc_e(cpu)) goto L_fn_056C6_000015;   /* je 0x0015 */
    goto L_fn_056C6_00033B;                  /* jmp 0x033B */
L_fn_056C6_000015:;
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x18F)); /* mov word ds:[0x96], 0x18F */
    mem_write16(cpu, cpu->ds, 0x98, (uint16_t)(0x0)); /* mov word ds:[0x98], 0x0 */
    mem_write16(cpu, cpu->ds, 0x9A, (uint16_t)(0xA0)); /* mov word ds:[0x9A], 0xA0 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0xAB08 */
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
    ovl_call(cpu, 0x03A8);                           /* call 0xACE2 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->ax = (uint16_t)(0x35);              /* mov ax, 0x35 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5BA(cpu);                           /* call 0x7EF4 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0555B(cpu);                           /* call 0xFE95 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xBFE2);            /* mov ax, 0xBFE2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x38);              /* mov ax, 0x38 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0x1184 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xBFE6);            /* mov ax, 0xBFE6 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x37);              /* mov ax, 0x37 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0684A(cpu);                           /* call 0x1184 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_055C7(cpu);                           /* call 0xFF01 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xBFF4)); /* push word ds:[0xBFF4] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xBFF2)); /* push word ds:[0xBFF2] */
    cpu->ax = (uint16_t)(0x89);              /* mov ax, 0x89 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xEC);              /* mov ax, 0xEC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0xAD06 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05673(cpu);                           /* call 0xFFAD */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0xACD9 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    mem_write16(cpu, cpu->ds, 0x1776, (uint16_t)(0x1)); /* mov word ds:[0x1776], 0x1 */
    cpu->ax = (uint16_t)(0x35);              /* mov ax, 0x35 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5F9(cpu);                           /* call 0x7F33 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xBFEE);            /* mov ax, 0xBFEE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x34);              /* mov ax, 0x34 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFE4)); /* mov dx, word ds:[0xBFE4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFE2)); /* mov ax, word ds:[0xBFE2] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05321(cpu);                           /* call 0xFC5B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_075F3(cpu);                           /* call 0x1F2D */
L_fn_056C6_0000CD:;
    goto L_fn_056C6_00010C;                  /* jmp 0x010C */
L_fn_056C6_0000CF:;
    cpu->ax = (uint16_t)(0x1BC6);            /* mov ax, 0x1BC6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0x1591 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05593(cpu);                           /* call 0xFECD */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    flags_cmp16(cpu, cpu->ax, 0xFFFF);       /* cmp ax, 0xFFFF */
    if (cc_e(cpu)) goto L_fn_056C6_000108;   /* je 0x0108 */
    flags_cmp16(cpu, cpu->ax, 0xD);          /* cmp ax, 0xD */
    if (cc_e(cpu)) goto L_fn_056C6_000108;   /* je 0x0108 */
    flags_cmp16(cpu, cpu->ax, 0x1B);         /* cmp ax, 0x1B */
    if (cc_e(cpu)) goto L_fn_056C6_0000F1;   /* je 0x00F1 */
    goto L_fn_056C6_00010A;                  /* jmp 0x010A */
L_fn_056C6_0000F1:;
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x139D);            /* mov ax, 0x139D */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_086C9(cpu);                           /* call 0x3003 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, cpu->ax, 0x1);          /* cmp ax, 0x1 */
    if (cc_ne(cpu)) goto L_fn_056C6_000106;  /* jne 0x0106 */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_056C6_00036F;                  /* jmp 0x036F */
L_fn_056C6_000106:;
    goto L_fn_056C6_00010C;                  /* jmp 0x010C */
L_fn_056C6_000108:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
L_fn_056C6_00010A:;
    goto L_fn_056C6_00010C;                  /* jmp 0x010C */
L_fn_056C6_00010C:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_056C6_0000CF;  /* jne 0x00CF */
    cpu->si = (uint16_t)(0x1);               /* mov si, 0x1 */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_056C6_0001D4;                  /* jmp 0x01D4 */
L_fn_056C6_000118:;
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8A);              /* mov ax, 0x8A */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xE8);              /* mov ax, 0xE8 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09F40(cpu);                           /* call 0x487A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x2); /* cmp byte ds:[0xBFCD], 0x2 */
    if (cc_ne(cpu)) goto L_fn_056C6_000145;  /* jne 0x0145 */
    cpu->ax = (uint16_t)(0x5);               /* mov ax, 0x5 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0xAB08 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_056C6_00014D;                  /* jmp 0x014D */
L_fn_056C6_000145:;
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0xAB08 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_056C6_00014D:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFE6); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFE6 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFE6] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFE8)); /* mov cx, word ds:[0xBFE8] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFE6)); /* mov bx, word ds:[0xBFE6] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06D3C(cpu);                           /* call 0x1676 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_075F3(cpu);                           /* call 0x1F2D */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0xACD9 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    goto L_fn_056C6_0001CC;                  /* jmp 0x01CC */
L_fn_056C6_00018F:;
    cpu->ax = (uint16_t)(0x1BC6);            /* mov ax, 0x1BC6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C57(cpu);                           /* call 0x1591 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05593(cpu);                           /* call 0xFECD */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    flags_cmp16(cpu, cpu->ax, 0xFFFF);       /* cmp ax, 0xFFFF */
    if (cc_e(cpu)) goto L_fn_056C6_0001C8;   /* je 0x01C8 */
    flags_cmp16(cpu, cpu->ax, 0xD);          /* cmp ax, 0xD */
    if (cc_e(cpu)) goto L_fn_056C6_0001C8;   /* je 0x01C8 */
    flags_cmp16(cpu, cpu->ax, 0x1B);         /* cmp ax, 0x1B */
    if (cc_e(cpu)) goto L_fn_056C6_0001B1;   /* je 0x01B1 */
    goto L_fn_056C6_0001CA;                  /* jmp 0x01CA */
L_fn_056C6_0001B1:;
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x139D);            /* mov ax, 0x139D */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_086C9(cpu);                           /* call 0x3003 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, cpu->ax, 0x1);          /* cmp ax, 0x1 */
    if (cc_ne(cpu)) goto L_fn_056C6_0001C6;  /* jne 0x01C6 */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_056C6_00036F;                  /* jmp 0x036F */
L_fn_056C6_0001C6:;
    goto L_fn_056C6_0001CC;                  /* jmp 0x01CC */
L_fn_056C6_0001C8:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
L_fn_056C6_0001CA:;
    goto L_fn_056C6_0001CC;                  /* jmp 0x01CC */
L_fn_056C6_0001CC:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_056C6_00018F;  /* jne 0x018F */
    cpu->si = (uint16_t)(0x1);               /* mov si, 0x1 */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_056C6_0001D4:;
    flags_cmp16(cpu, cpu->di, 0x2);          /* cmp di, 0x2 */
    if (cc_ge(cpu)) goto L_fn_056C6_0001DC;  /* jge 0x01DC */
    RECOMP_TICK(cpu);
    goto L_fn_056C6_000118;                  /* jmp 0x0118 */
L_fn_056C6_0001DC:;
    flags_cmp16(cpu, cpu->di, 0x2);          /* cmp di, 0x2 */
    if (cc_ne(cpu)) goto L_fn_056C6_0001ED;  /* jne 0x01ED */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0xFFFF); /* cmp word ss:[bp+-0x2], 0xFFFF */
    if (cc_ne(cpu)) goto L_fn_056C6_0001ED;  /* jne 0x01ED */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0568C(cpu);                           /* call 0xFFC6 */
    RECOMP_TICK(cpu);
    goto L_fn_056C6_0000CD;                  /* jmp 0x00CD */
L_fn_056C6_0001ED:;
    cpu->ax = (uint16_t)(0xB6);              /* mov ax, 0xB6 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x10);              /* mov ax, 0x10 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xBC);              /* mov ax, 0xBC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x17E);             /* mov ax, 0x17E */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_09F40(cpu);                           /* call 0x487A */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    mem_write16(cpu, cpu->ds, 0x94, (uint16_t)(0x0)); /* mov word ds:[0x94], 0x0 */
    mem_write16(cpu, cpu->ds, 0x9A, (uint16_t)(0x9F)); /* mov word ds:[0x9A], 0x9F */
    mem_write16(cpu, cpu->ds, 0x1774, (uint16_t)(0x1)); /* mov word ds:[0x1774], 0x1 */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x742B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xBFEE);            /* mov ax, 0xBFEE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2D);              /* mov ax, 0x2D */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xA);               /* mov ax, 0xA */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFE4)); /* mov dx, word ds:[0xBFE4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFE2)); /* mov ax, word ds:[0xBFE2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x344)); /* add ax, 0x344 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05321(cpu);                           /* call 0xFC5B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    mem_write16(cpu, cpu->ds, 0x1770, (uint16_t)(0x1)); /* mov word ds:[0x1770], 0x1 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0x7482 */
    mem_write16(cpu, cpu->ds, 0x1774, (uint16_t)(0x0)); /* mov word ds:[0x1774], 0x0 */
    cpu->ax = (uint16_t)(0xED);              /* mov ax, 0xED */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C26(cpu);                           /* call 0x1560 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xBFEE);            /* mov ax, 0xBFEE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x16);              /* mov ax, 0x16 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFE4)); /* mov dx, word ds:[0xBFE4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFE2)); /* mov ax, word ds:[0xBFE2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x498)); /* add ax, 0x498 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05321(cpu);                           /* call 0xFC5B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xBFEE);            /* mov ax, 0xBFEE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x28);              /* mov ax, 0x28 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xB);               /* mov ax, 0xB */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFE4)); /* mov dx, word ds:[0xBFE4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFE2)); /* mov ax, word ds:[0xBFE2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x3E6)); /* add ax, 0x3E6 */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05321(cpu);                           /* call 0xFC5B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0xED);              /* mov ax, 0xED */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06C26(cpu);                           /* call 0x1560 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x1774, (uint16_t)(0x1)); /* mov word ds:[0x1774], 0x1 */
    cpu->ax = (uint16_t)(0x18);              /* mov ax, 0x18 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x742B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xBFEE);            /* mov ax, 0xBFEE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x28);              /* mov ax, 0x28 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xB);               /* mov ax, 0xB */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFE4)); /* mov dx, word ds:[0xBFE4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFE2)); /* mov ax, word ds:[0xBFE2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x66C)); /* add ax, 0x66C */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05321(cpu);                           /* call 0xFC5B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    mem_write16(cpu, cpu->ds, 0x1774, (uint16_t)(0x0)); /* mov word ds:[0x1774], 0x0 */
    mem_write16(cpu, cpu->ds, 0x1770, (uint16_t)(0x1)); /* mov word ds:[0x1770], 0x1 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0x7482 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0xBFEE);            /* mov ax, 0xBFEE */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1E);              /* mov ax, 0x1E */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x7);               /* mov ax, 0x7 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFE4)); /* mov dx, word ds:[0xBFE4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xBFE2)); /* mov ax, word ds:[0xBFE2] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x5FA)); /* add ax, 0x5FA */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05321(cpu);                           /* call 0xFC5B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    mem_write16(cpu, cpu->ds, 0x94, (uint16_t)(0x10)); /* mov word ds:[0x94], 0x10 */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x9F)); /* mov word ds:[0x96], 0x9F */
    mem_write16(cpu, cpu->ds, 0x98, (uint16_t)(0x4)); /* mov word ds:[0x98], 0x4 */
    mem_write16(cpu, cpu->ds, 0x9A, (uint16_t)(0x9B)); /* mov word ds:[0x9A], 0x9B */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xBFE4)); /* push word ds:[0xBFE4] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xBFE2)); /* push word ds:[0xBFE2] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x9FFD */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xBFE8)); /* push word ds:[0xBFE8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xBFE6)); /* push word ds:[0xBFE6] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x9FFD */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xBFE0)); /* push word ds:[0xBFE0] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xBFDE)); /* push word ds:[0xBFDE] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x9FFD */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_056C6_00036A;                  /* jmp 0x036A */
L_fn_056C6_00033B:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0xAB08 */
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
    ovl_call(cpu, 0x03A8);                           /* call 0xACE2 */
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
    ovl_call(cpu, 0x039F);                           /* call 0xACD9 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_056C6_00036A:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_056C6_00036F;                  /* jmp 0x036F */
L_fn_056C6_00036F:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_05A3B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_05A3B");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    mem_write16(cpu, cpu->ds, 0xC04E, (uint16_t)(0x17)); /* mov word ds:[0xC04E], 0x17 */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0x736)); /* mov di, word ds:[0x736] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x10)); /* add di, 0x10 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x738)); /* mov ax, word ds:[0x738] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    flags_cmp16(cpu, cpu->di, 0x8);          /* cmp di, 0x8 */
    if (cc_l(cpu)) goto L_fn_05A3B_000036;   /* jl 0x0036 */
    flags_cmp16(cpu, cpu->di, 0x137);        /* cmp di, 0x137 */
    if (cc_g(cpu)) goto L_fn_05A3B_000036;   /* jg 0x0036 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x10); /* cmp word ss:[bp+-0x2], 0x10 */
    if (cc_l(cpu)) goto L_fn_05A3B_000036;   /* jl 0x0036 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0x9F); /* cmp word ss:[bp+-0x2], 0x9F */
    if (cc_le(cpu)) goto L_fn_05A3B_000038;  /* jle 0x0038 */
L_fn_05A3B_000036:;
    goto L_fn_05A3B_000082;                  /* jmp 0x0082 */
L_fn_05A3B_000038:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_05A3B_000050;                  /* jmp 0x0050 */
L_fn_05A3B_00003C:;
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3FB0), (uint16_t)(cpu->di)); /* mov word ds:[bx+-0x3FB0], di */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3F80), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x3F80], ax */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_05A3B_000050:;
    flags_cmp16(cpu, cpu->si, 0x18);         /* cmp si, 0x18 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_05A3B_00003C;   /* jl 0x003C */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x73A), 0x0); /* cmp word ds:[0x73A], 0x0 */
    if (cc_e(cpu)) goto L_fn_05A3B_000064;   /* je 0x0064 */
    mem_write16(cpu, cpu->ds, 0xC0B8, (uint16_t)(0x9)); /* mov word ds:[0xC0B8], 0x9 */
    goto L_fn_05A3B_00006A;                  /* jmp 0x006A */
L_fn_05A3B_000064:;
    mem_write16(cpu, cpu->ds, 0xC0B8, (uint16_t)(0x3)); /* mov word ds:[0xC0B8], 0x3 */
L_fn_05A3B_00006A:;
    mem_write16(cpu, cpu->ds, 0xC0B0, (uint16_t)(0x0)); /* mov word ds:[0xC0B0], 0x0 */
    mem_write16(cpu, cpu->ds, 0xC0C0, (uint16_t)(0x18)); /* mov word ds:[0xC0C0], 0x18 */
    mem_write16(cpu, cpu->ds, 0x8FE, (uint16_t)(0x1)); /* mov word ds:[0x8FE], 0x1 */
    mem_write16(cpu, cpu->ds, 0xC0B6, (uint16_t)(0x0)); /* mov word ds:[0xC0B6], 0x0 */
L_fn_05A3B_000082:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_05AC3(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_05AC3");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x1A)); /* sub sp, 0x1A */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(0x1)); /* mov word ss:[bp+-0xC], 0x1 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(0x0)); /* mov word ss:[bp+-0x6], 0x0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0020F(cpu);                           /* call 0xA74C */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1A), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x1A], ax */
    mem_write16(cpu, cpu->ds, 0xC0BE, (uint16_t)(0x0)); /* mov word ds:[0xC0BE], 0x0 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC04E)); /* mov bx, word ds:[0xC04E] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3FB0))); /* mov si, word ds:[bx+-0x3FB0] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC04E)); /* mov bx, word ds:[0xC04E] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3F80))); /* mov di, word ds:[bx+-0x3F80] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _r = cpu->ax & 0x7; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x7 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x16], ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _r = cpu->ax & 0x7; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x7 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x14], ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { int16_t _v = (int16_t)cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->ax = (uint16_t)((uint16_t)_r); } } /* sar ax, 0x1 */
    { int16_t _v = (int16_t)cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->ax = (uint16_t)((uint16_t)_r); } } /* sar ax, 0x1 */
    { int16_t _v = (int16_t)cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->ax = (uint16_t)((uint16_t)_r); } } /* sar ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFFE)); /* add ax, 0xFFFE */
    cpu->dx = (uint16_t)(0x26);              /* mov dx, 0x26 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->dx = (uint16_t)(cpu->si);           /* mov dx, si */
    { int16_t _v = (int16_t)cpu->dx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->dx = (uint16_t)((uint16_t)_r); } } /* sar dx, 0x1 */
    { int16_t _v = (int16_t)cpu->dx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->dx = (uint16_t)((uint16_t)_r); } } /* sar dx, 0x1 */
    { int16_t _v = (int16_t)cpu->dx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->dx = (uint16_t)((uint16_t)_r); } } /* sar dx, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->dx)); /* add ax, dx */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xE], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18), (uint16_t)(0x0)); /* mov word ss:[bp+-0x18], 0x0 */
    goto L_fn_05AC3_0002F4;                  /* jmp 0x02F4 */
L_fn_05AC3_000068:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_ne(cpu)) goto L_fn_05AC3_00006F;  /* jne 0x006F */
    goto L_fn_05AC3_0002BD;                  /* jmp 0x02BD */
L_fn_05AC3_00006F:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0B8)); /* mov ax, word ds:[0xC0B8] */
    cpu->dx = (uint16_t)(0x18);              /* mov dx, 0x18 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x900)); /* add bx, 0x900 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0B0)); /* mov ax, word ds:[0xC0B0] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x12], ax */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0xC0B0, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC0B0), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0xC0B0] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0B8)); /* mov ax, word ds:[0xC0B8] */
    cpu->dx = (uint16_t)(0x18);              /* mov dx, 0x18 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x900)); /* add bx, 0x900 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0B0)); /* mov ax, word ds:[0xC0B0] */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x10], ax */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0xC0B0, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC0B0), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0xC0B0] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC0B0), 0xC); /* cmp word ds:[0xC0B0], 0xC */
    if (cc_l(cpu)) goto L_fn_05AC3_0000BE;   /* jl 0x00BE */
    mem_write16(cpu, cpu->ds, 0xC0B0, (uint16_t)(0x0)); /* mov word ds:[0xC0B0], 0x0 */
L_fn_05AC3_0000BE:;
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12)))); /* add si, word ss:[bp+-0x12] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10)))); /* add di, word ss:[bp+-0x10] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x12))); /* mov ax, word ss:[bp+-0x12] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16)), cpu->ax))); /* add word ss:[bp+-0x16], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x10))); /* mov ax, word ss:[bp+-0x10] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14)), cpu->ax))); /* add word ss:[bp+-0x14], ax */
    flags_logic16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16)) & 0x8); /* test word ss:[bp+-0x16], 0x8 */
    if (cc_e(cpu)) goto L_fn_05AC3_0000EF;   /* je 0x00EF */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16)), 0x0); /* cmp word ss:[bp+-0x16], 0x0 */
    if (cc_ge(cpu)) goto L_fn_05AC3_0000E2;  /* jge 0x00E2 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ss:[bp+-0xE] */
    goto L_fn_05AC3_0000E5;                  /* jmp 0x00E5 */
L_fn_05AC3_0000E2:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0xE] */
L_fn_05AC3_0000E5:;
    { uint16_t _r = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16)) & 0x7; flags_logic16(cpu, _r); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x16), (uint16_t)(_r)); } /* and word ss:[bp+-0x16], 0x7 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(0x1)); /* mov word ss:[bp+-0xC], 0x1 */
L_fn_05AC3_0000EF:;
    flags_logic16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14)) & 0x8); /* test word ss:[bp+-0x14], 0x8 */
    if (cc_e(cpu)) goto L_fn_05AC3_000110;   /* je 0x0110 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14)), 0x0); /* cmp word ss:[bp+-0x14], 0x0 */
    if (cc_ge(cpu)) goto L_fn_05AC3_000102;  /* jge 0x0102 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)), 0x26))); /* sub word ss:[bp+-0xE], 0x26 */
    goto L_fn_05AC3_000106;                  /* jmp 0x0106 */
L_fn_05AC3_000102:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)), 0x26))); /* add word ss:[bp+-0xE], 0x26 */
L_fn_05AC3_000106:;
    { uint16_t _r = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14)) & 0x7; flags_logic16(cpu, _r); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x14), (uint16_t)(_r)); } /* and word ss:[bp+-0x14], 0x7 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(0x1)); /* mov word ss:[bp+-0xC], 0x1 */
L_fn_05AC3_000110:;
    flags_cmp16(cpu, cpu->si, 0x8);          /* cmp si, 0x8 */
    if (cc_l(cpu)) goto L_fn_05AC3_000126;   /* jl 0x0126 */
    flags_cmp16(cpu, cpu->si, 0x137);        /* cmp si, 0x137 */
    if (cc_g(cpu)) goto L_fn_05AC3_000126;   /* jg 0x0126 */
    flags_cmp16(cpu, cpu->di, 0x10);         /* cmp di, 0x10 */
    if (cc_l(cpu)) goto L_fn_05AC3_000126;   /* jl 0x0126 */
    flags_cmp16(cpu, cpu->di, 0x9F);         /* cmp di, 0x9F */
    if (cc_le(cpu)) goto L_fn_05AC3_00012A;  /* jle 0x012A */
L_fn_05AC3_000126:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_05AC3_000144;                  /* jmp 0x0144 */
L_fn_05AC3_00012A:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC)), 0x0); /* cmp word ss:[bp+-0xC], 0x0 */
    if (cc_e(cpu)) goto L_fn_05AC3_000144;   /* je 0x0144 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFBC); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFBC + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFBC] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xE)))); /* add bx, word ss:[bp+-0xE] */
    flags_logic8(cpu, mem_read8(cpu, cpu->es, cpu->bx) & 0x7); /* test byte es:[bx], 0x7 */
    if (cc_e(cpu)) goto L_fn_05AC3_00013F;   /* je 0x013F */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
L_fn_05AC3_00013F:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xC), (uint16_t)(0x0)); /* mov word ss:[bp+-0xC], 0x0 */
L_fn_05AC3_000144:;
    flags_logic16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18)) & 0x3); /* test word ss:[bp+-0x18], 0x3 */
    if (cc_e(cpu)) goto L_fn_05AC3_00014E;   /* je 0x014E */
    goto L_fn_05AC3_000218;                  /* jmp 0x0218 */
L_fn_05AC3_00014E:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_ne(cpu)) goto L_fn_05AC3_000155;  /* jne 0x0155 */
    goto L_fn_05AC3_000218;                  /* jmp 0x0218 */
L_fn_05AC3_000155:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { int16_t _v = (int16_t)cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->ax = (uint16_t)((uint16_t)_r); } } /* sar ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D89A(cpu);                           /* call 0x7DD7 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0xA], ax */
    flags_cmp16(cpu, cpu->ax, 0x8);          /* cmp ax, 0x8 */
    if (cc_l(cpu)) goto L_fn_05AC3_0001A6;   /* jl 0x01A6 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)), 0x1F); /* cmp word ss:[bp+-0xA], 0x1F */
    if (cc_g(cpu)) goto L_fn_05AC3_0001A6;   /* jg 0x01A6 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* mov ax, word ss:[bp+-0xA] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFF8)); /* add ax, 0xFFF8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_02A2D(cpu);                           /* call 0xCF6A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0xC0BC, (uint16_t)(cpu->dx)); /* mov word ds:[0xC0BC], dx */
    mem_write16(cpu, cpu->ds, 0xC0BA, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0BA], ax */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->es = (uint16_t)(cpu->dx);           /* mov es, dx */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0x1)), 0x2); /* cmp byte es:[bx+0x1], 0x2 */
    if (cc_ne(cpu)) goto L_fn_05AC3_0001A6;  /* jne 0x01A6 */
    mem_write16(cpu, cpu->ds, 0xC0BE, (uint16_t)(0x1)); /* mov word ds:[0xC0BE], 0x1 */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0xC0B6, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0B6], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
    goto L_fn_05AC3_000218;                  /* jmp 0x0218 */
L_fn_05AC3_0001A6:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)), 0x30); /* cmp word ss:[bp+-0xA], 0x30 */
    if (cc_l(cpu)) goto L_fn_05AC3_000210;   /* jl 0x0210 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA)), 0x4F); /* cmp word ss:[bp+-0xA], 0x4F */
    if (cc_g(cpu)) goto L_fn_05AC3_000210;   /* jg 0x0210 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(0x1)); /* mov word ss:[bp+-0x6], 0x1 */
    cpu->bx = (uint16_t)((uint16_t)(cpu->bp - 0x4)); /* lea bx, word ss:[bp+-0x4] */
    push16(cpu, cpu->ss);                    /* push ss */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0xA))); /* mov ax, word ss:[bp+-0xA] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFD0)); /* add ax, 0xFFD0 */
    cpu->dx = (uint16_t)(0x3);               /* mov dx, 0x3 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40D0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40D0 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x40D0] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->cx = (uint16_t)(0x3);               /* mov cx, 0x3 */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F937(cpu);                           /* call 0000:F937 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov al, byte ss:[bp+-0x4] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    mem_write16(cpu, cpu->ds, 0xC0B2, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0B2], ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x3))); /* mov al, byte ss:[bp+-0x3] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    mem_write16(cpu, cpu->ds, 0xC0B4, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0B4], ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov al, byte ss:[bp+-0x2] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    { uint16_t _r = cpu->ax & 0x1F; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x1F */
    mem_write16(cpu, cpu->ds, 0xC0C2, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0C2], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0C2)); /* mov ax, word ds:[0xC0C2] */
    cpu->dx = (uint16_t)(0x1E6);             /* mov dx, 0x1E6 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xBFC8); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xBFC8 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xBFC8] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x24)); /* add bx, 0x24 */
    mem_write16(cpu, cpu->ds, 0xC0C6, (uint16_t)(cpu->es)); /* mov word ds:[0xC0C6], es */
    mem_write16(cpu, cpu->ds, 0xC0C4, (uint16_t)(cpu->bx)); /* mov word ds:[0xC0C4], bx */
    goto L_fn_05AC3_000218;                  /* jmp 0x0218 */
L_fn_05AC3_000210:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0xC0B6, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0B6], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x6], ax */
L_fn_05AC3_000218:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6)), 0x0); /* cmp word ss:[bp+-0x6], 0x0 */
    if (cc_ne(cpu)) goto L_fn_05AC3_000221;  /* jne 0x0221 */
    goto L_fn_05AC3_0002BB;                  /* jmp 0x02BB */
L_fn_05AC3_000221:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC0B6), 0x0); /* cmp word ds:[0xC0B6], 0x0 */
    if (cc_e(cpu)) goto L_fn_05AC3_00022B;   /* je 0x022B */
    goto L_fn_05AC3_0002BB;                  /* jmp 0x02BB */
L_fn_05AC3_00022B:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_05F3C(cpu);                           /* call 0x0479 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    flags_cmp16(cpu, cpu->ax, 0x1);          /* cmp ax, 0x1 */
    if (cc_ne(cpu)) goto L_fn_05AC3_000254;  /* jne 0x0254 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0C2)); /* mov ax, word ds:[0xC0C2] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC0B8))); /* sub ax, word ds:[0xC0B8] */
    mem_write16(cpu, cpu->ds, 0xC0B8, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0B8], ax */
    mem_write16(cpu, cpu->ds, 0xC0B6, (uint16_t)(0x1)); /* mov word ds:[0xC0B6], 0x1 */
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x702E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_05AC3_000298;                  /* jmp 0x0298 */
L_fn_05AC3_000254:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x2); /* cmp word ss:[bp+-0x8], 0x2 */
    if (cc_ne(cpu)) goto L_fn_05AC3_000277;  /* jne 0x0277 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0C2)); /* mov ax, word ds:[0xC0C2] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC0B8))); /* sub ax, word ds:[0xC0B8] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFF8)); /* add ax, 0xFFF8 */
    mem_write16(cpu, cpu->ds, 0xC0B8, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0B8], ax */
    mem_write16(cpu, cpu->ds, 0xC0B6, (uint16_t)(0x1)); /* mov word ds:[0xC0B6], 0x1 */
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x702E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_05AC3_000298;                  /* jmp 0x0298 */
L_fn_05AC3_000277:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)), 0x3); /* cmp word ss:[bp+-0x8], 0x3 */
    if (cc_ne(cpu)) goto L_fn_05AC3_000298;  /* jne 0x0298 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC0C2)); /* mov ax, word ds:[0xC0C2] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC0B8))); /* sub ax, word ds:[0xC0B8] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    mem_write16(cpu, cpu->ds, 0xC0B8, (uint16_t)(cpu->ax)); /* mov word ds:[0xC0B8], ax */
    mem_write16(cpu, cpu->ds, 0xC0B6, (uint16_t)(0x1)); /* mov word ds:[0xC0B6], 0x1 */
    cpu->ax = (uint16_t)(0xF);               /* mov ax, 0xF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x702E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_05AC3_000298:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC0B6), 0x0); /* cmp word ds:[0xC0B6], 0x0 */
    if (cc_e(cpu)) goto L_fn_05AC3_0002BB;   /* je 0x02BB */
    goto L_fn_05AC3_0002A6;                  /* jmp 0x02A6 */
L_fn_05AC3_0002A1:;
    mem_write16(cpu, cpu->ds, 0xC0B8, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC0B8), 0xC))); /* add word ds:[0xC0B8], 0xC */
L_fn_05AC3_0002A6:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC0B8), 0x0); /* cmp word ds:[0xC0B8], 0x0 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_05AC3_0002A1;   /* jl 0x02A1 */
    goto L_fn_05AC3_0002B4;                  /* jmp 0x02B4 */
L_fn_05AC3_0002AF:;
    mem_write16(cpu, cpu->ds, 0xC0B8, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0xC0B8), 0xC))); /* sub word ds:[0xC0B8], 0xC */
L_fn_05AC3_0002B4:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC0B8), 0xC); /* cmp word ds:[0xC0B8], 0xC */
    RECOMP_TICK(cpu);
    if (cc_ge(cpu)) goto L_fn_05AC3_0002AF;  /* jge 0x02AF */
L_fn_05AC3_0002BB:;
    goto L_fn_05AC3_0002CB;                  /* jmp 0x02CB */
L_fn_05AC3_0002BD:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0xC0C0, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0xC0C0), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ds:[0xC0C0] */
    if (cc_g(cpu)) goto L_fn_05AC3_0002CB;   /* jg 0x02CB */
    mem_write16(cpu, cpu->ds, 0x8FE, (uint16_t)(0x0)); /* mov word ds:[0x8FE], 0x0 */
L_fn_05AC3_0002CB:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0xC04E, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC04E), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0xC04E] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC04E)); /* mov ax, word ds:[0xC04E] */
    flags_cmp16(cpu, cpu->ax, 0x18);         /* cmp ax, 0x18 */
    if (cc_l(cpu)) goto L_fn_05AC3_0002DD;   /* jl 0x02DD */
    mem_write16(cpu, cpu->ds, 0xC04E, (uint16_t)(0x0)); /* mov word ds:[0xC04E], 0x0 */
L_fn_05AC3_0002DD:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC04E)); /* mov bx, word ds:[0xC04E] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3FB0), (uint16_t)(cpu->si)); /* mov word ds:[bx+-0x3FB0], si */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC04E)); /* mov bx, word ds:[0xC04E] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3F80), (uint16_t)(cpu->di)); /* mov word ds:[bx+-0x3F80], di */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x18] */
L_fn_05AC3_0002F4:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18)), 0x8); /* cmp word ss:[bp+-0x18], 0x8 */
    if (cc_ge(cpu)) goto L_fn_05AC3_0002FD;  /* jge 0x02FD */
    RECOMP_TICK(cpu);
    goto L_fn_05AC3_000068;                  /* jmp 0x0068 */
L_fn_05AC3_0002FD:;
    mem_write16(cpu, cpu->ds, 0xC046, (uint16_t)(0x140)); /* mov word ds:[0xC046], 0x140 */
    mem_write16(cpu, cpu->ds, 0xC04A, (uint16_t)(0xC8)); /* mov word ds:[0xC04A], 0xC8 */
    mem_write16(cpu, cpu->ds, 0xC048, (uint16_t)(0x0)); /* mov word ds:[0xC048], 0x0 */
    mem_write16(cpu, cpu->ds, 0xC04C, (uint16_t)(0x0)); /* mov word ds:[0xC04C], 0x0 */
    cpu->ax = (uint16_t)(0xE);               /* mov ax, 0xE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0xA70B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18), (uint16_t)(0x0)); /* mov word ss:[bp+-0x18], 0x0 */
    goto L_fn_05AC3_000372;                  /* jmp 0x0372 */
L_fn_05AC3_000324:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18))); /* mov bx, word ss:[bp+-0x18] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3FB0))); /* mov si, word ds:[bx+-0x3FB0] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_05AC3_00036F;   /* je 0x036F */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18))); /* mov bx, word ss:[bp+-0x18] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3F80))); /* mov di, word ds:[bx+-0x3F80] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03D2);                           /* call 0xA90F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ds, 0xC046)); /* cmp si, word ds:[0xC046] */
    if (cc_ge(cpu)) goto L_fn_05AC3_00034F;  /* jge 0x034F */
    mem_write16(cpu, cpu->ds, 0xC046, (uint16_t)(cpu->si)); /* mov word ds:[0xC046], si */
L_fn_05AC3_00034F:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC048)); /* mov ax, word ds:[0xC048] */
    flags_cmp16(cpu, cpu->ax, cpu->si);      /* cmp ax, si */
    if (cc_ge(cpu)) goto L_fn_05AC3_00035A;  /* jge 0x035A */
    mem_write16(cpu, cpu->ds, 0xC048, (uint16_t)(cpu->si)); /* mov word ds:[0xC048], si */
L_fn_05AC3_00035A:;
    flags_cmp16(cpu, cpu->di, mem_read16(cpu, cpu->ds, 0xC04A)); /* cmp di, word ds:[0xC04A] */
    if (cc_ge(cpu)) goto L_fn_05AC3_000364;  /* jge 0x0364 */
    mem_write16(cpu, cpu->ds, 0xC04A, (uint16_t)(cpu->di)); /* mov word ds:[0xC04A], di */
L_fn_05AC3_000364:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC04C)); /* mov ax, word ds:[0xC04C] */
    flags_cmp16(cpu, cpu->ax, cpu->di);      /* cmp ax, di */
    if (cc_ge(cpu)) goto L_fn_05AC3_00036F;  /* jge 0x036F */
    mem_write16(cpu, cpu->ds, 0xC04C, (uint16_t)(cpu->di)); /* mov word ds:[0xC04C], di */
L_fn_05AC3_00036F:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x18] */
L_fn_05AC3_000372:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x18)), 0x18); /* cmp word ss:[bp+-0x18], 0x18 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_05AC3_000324;   /* jl 0x0324 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC048), 0x0); /* cmp word ds:[0xC048], 0x0 */
    if (cc_e(cpu)) goto L_fn_05AC3_0003C8;   /* je 0x03C8 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC046)); /* mov ax, word ds:[0xC046] */
    { int16_t _v = (int16_t)cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->ax = (uint16_t)((uint16_t)_r); } } /* sar ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40C4 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x40C4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x40C4), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x40C4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC04A)); /* mov al, byte ds:[0xC04A] */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40C4 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x40C4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x40C4), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x40C4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC048)); /* mov ax, word ds:[0xC048] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC046))); /* sub ax, word ds:[0xC046] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    { int16_t _v = (int16_t)cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->ax = (uint16_t)((uint16_t)_r); } } /* sar ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40C4 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x40C4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x40C4), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x40C4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC04C)); /* mov al, byte ds:[0xC04C] */
    cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, mem_read8(cpu, cpu->ds, 0xC04A))); /* sub al, byte ds:[0xC04A] */
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc al */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40C4 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x40C4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x40C4), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x40C4] */
L_fn_05AC3_0003C8:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1A))); /* push word ss:[bp+-0x1A] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0xA70B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_05E98(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_05E98");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0020F(cpu);                           /* call 0xA377 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_05E98_000042;                  /* jmp 0x0042 */
L_fn_05E98_000012:;
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3FB0))); /* mov di, word ds:[bx+-0x3FB0] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_05E98_000041;   /* je 0x0041 */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3F80))); /* mov ax, word ds:[bx+-0x3F80] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03D5);                           /* call 0xA53D */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x40C8, (uint16_t)(cpu->ax)); /* mov word ds:[0x40C8], ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03D2);                           /* call 0xA53A */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_05E98_000041:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_05E98_000042:;
    flags_cmp16(cpu, cpu->si, 0x18);         /* cmp si, 0x18 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_05E98_000012;   /* jl 0x0012 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC048), 0x0); /* cmp word ds:[0xC048], 0x0 */
    if (cc_e(cpu)) goto L_fn_05E98_000097;   /* je 0x0097 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC046)); /* mov ax, word ds:[0xC046] */
    { int16_t _v = (int16_t)cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->ax = (uint16_t)((uint16_t)_r); } } /* sar ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40C4 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x40C4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x40C4), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x40C4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC04A)); /* mov al, byte ds:[0xC04A] */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40C4 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x40C4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x40C4), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x40C4] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC048)); /* mov ax, word ds:[0xC048] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0xC046))); /* sub ax, word ds:[0xC046] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x4)); /* add ax, 0x4 */
    { int16_t _v = (int16_t)cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->ax = (uint16_t)((uint16_t)_r); } } /* sar ax, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40C4 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x40C4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x40C4), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x40C4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, 0xC04C)); /* mov al, byte ds:[0xC04C] */
    cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, mem_read8(cpu, cpu->ds, 0xC04A))); /* sub al, byte ds:[0xC04A] */
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc al */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x40C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x40C4 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x40C4] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x40C4, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x40C4), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x40C4] */
L_fn_05E98_000097:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0xA336 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_05F3C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_05F3C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov di, word ss:[bp+0x6] */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x5); /* cmp byte ds:[0xBFCD], 0x5 */
    if (cc_ne(cpu)) goto L_fn_05F3C_00004C;  /* jne 0x004C */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB8)); /* add ax, 0xB8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03D5);                           /* call 0xA499 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, cpu->ax, 0x83);         /* cmp ax, 0x83 */
    if (cc_e(cpu)) goto L_fn_05F3C_000032;   /* je 0x0032 */
    flags_cmp16(cpu, cpu->ax, 0x86);         /* cmp ax, 0x86 */
    if (cc_e(cpu)) goto L_fn_05F3C_000038;   /* je 0x0038 */
    flags_cmp16(cpu, cpu->ax, 0x8A);         /* cmp ax, 0x8A */
    if (cc_e(cpu)) goto L_fn_05F3C_00003E;   /* je 0x003E */
    goto L_fn_05F3C_000044;                  /* jmp 0x0044 */
L_fn_05F3C_000032:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_05F3C_0000DF;                  /* jmp 0x00DF */
L_fn_05F3C_000038:;
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    goto L_fn_05F3C_0000DF;                  /* jmp 0x00DF */
L_fn_05F3C_00003E:;
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    goto L_fn_05F3C_0000DF;                  /* jmp 0x00DF */
L_fn_05F3C_000044:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_05F3C_0000DF;                  /* jmp 0x00DF */
    goto L_fn_05F3C_0000DF;                  /* jmp 0x00DF */
L_fn_05F3C_00004C:;
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, mem_read16(cpu, cpu->ds, 0xC0B2))); /* sub si, word ds:[0xC0B2] */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, mem_read16(cpu, cpu->ds, 0xC0B4))); /* sub di, word ds:[0xC0B4] */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->di)); /* sub ax, di */
    cpu->dx = (uint16_t)(cpu->si);           /* mov dx, si */
    { int16_t _v = (int16_t)cpu->dx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _s = (_c >= 16) ? 15 : _c; int16_t _r = _v >> _s; int _cf = (_c >= 16) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift16(cpu, (uint16_t)_r); cpu->dx = (uint16_t)((uint16_t)_r); } } /* sar dx, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->dx)); /* add ax, dx */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0xC0C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0xC0C4 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0xC0C4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x1], al */
    flags_logic16(cpu, cpu->si & 0x1);       /* test si, 0x1 */
    if (cc_e(cpu)) goto L_fn_05F3C_00007A;   /* je 0x007A */
    { uint8_t _r = mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1)) & 0xF; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1), (uint8_t)(_r)); } /* and byte ss:[bp+-0x1], 0xF */
    goto L_fn_05F3C_000086;                  /* jmp 0x0086 */
L_fn_05F3C_00007A:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { int8_t _v = (int8_t)cpu->al; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint8_t _s = (_c >= 8) ? 7 : _c; int8_t _r = _v >> _s; int _cf = (_c >= 8) ? (_v < 0) : ((_v >> (_s - 1)) & 1); cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0); flags_shift8(cpu, (uint8_t)_r); cpu->al = (uint8_t)((uint8_t)_r); } } /* sar al, cl */
    { uint8_t _r = cpu->al & 0xF; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0xF */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x1], al */
L_fn_05F3C_000086:;
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0xBFCD), 0x2); /* cmp byte ds:[0xBFCD], 0x2 */
    if (cc_ne(cpu)) goto L_fn_05F3C_0000B7;  /* jne 0x00B7 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    flags_cmp16(cpu, cpu->ax, 0x2);          /* cmp ax, 0x2 */
    if (cc_e(cpu)) goto L_fn_05F3C_0000A2;   /* je 0x00A2 */
    flags_cmp16(cpu, cpu->ax, 0x3);          /* cmp ax, 0x3 */
    if (cc_e(cpu)) goto L_fn_05F3C_0000A7;   /* je 0x00A7 */
    flags_cmp16(cpu, cpu->ax, 0x4);          /* cmp ax, 0x4 */
    if (cc_e(cpu)) goto L_fn_05F3C_0000AC;   /* je 0x00AC */
    goto L_fn_05F3C_0000B1;                  /* jmp 0x00B1 */
L_fn_05F3C_0000A2:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_05F3C_0000DF;                  /* jmp 0x00DF */
L_fn_05F3C_0000A7:;
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    goto L_fn_05F3C_0000DF;                  /* jmp 0x00DF */
L_fn_05F3C_0000AC:;
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    goto L_fn_05F3C_0000DF;                  /* jmp 0x00DF */
L_fn_05F3C_0000B1:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_05F3C_0000DF;                  /* jmp 0x00DF */
    goto L_fn_05F3C_0000DF;                  /* jmp 0x00DF */
L_fn_05F3C_0000B7:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    flags_cmp16(cpu, cpu->ax, 0x8);          /* cmp ax, 0x8 */
    if (cc_e(cpu)) goto L_fn_05F3C_0000D6;   /* je 0x00D6 */
    flags_cmp16(cpu, cpu->ax, 0x9);          /* cmp ax, 0x9 */
    if (cc_e(cpu)) goto L_fn_05F3C_0000D1;   /* je 0x00D1 */
    flags_cmp16(cpu, cpu->ax, 0xB);          /* cmp ax, 0xB */
    if (cc_e(cpu)) goto L_fn_05F3C_0000CC;   /* je 0x00CC */
    goto L_fn_05F3C_0000DB;                  /* jmp 0x00DB */
L_fn_05F3C_0000CC:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_05F3C_0000DF;                  /* jmp 0x00DF */
L_fn_05F3C_0000D1:;
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    goto L_fn_05F3C_0000DF;                  /* jmp 0x00DF */
L_fn_05F3C_0000D6:;
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    goto L_fn_05F3C_0000DF;                  /* jmp 0x00DF */
L_fn_05F3C_0000DB:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_05F3C_0000DF;                  /* jmp 0x00DF */
L_fn_05F3C_0000DF:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_06021(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_06021");
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xC0BE), 0x0); /* cmp word ds:[0xC0BE], 0x0 */
    if (cc_e(cpu)) goto L_fn_06021_000014;   /* je 0x0014 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0BC)); /* push word ds:[0xC0BC] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC0BA)); /* push word ds:[0xC0BA] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0338A(cpu);                           /* call 0xD369 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_06021_000014:;
    cpu->sp += 2; return;                    /* ret */
}
