#include "recomp_all.h"

void fn_0E44B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E44B");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0xCA22), 0x0); /* cmp word ds:[0xCA22], 0x0 */
    if (cc_e(cpu)) goto L_fn_0E44B_000028;   /* je 0x0028 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(0xE);               /* mov dx, 0xE */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC91B)); /* add bx, 0xC91B */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xD))); /* mov al, byte es:[bx+0xD] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    { uint16_t _r = cpu->si & 0x3; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* and si, 0x3 */
    goto L_fn_0E44B_00002A;                  /* jmp 0x002A */
L_fn_0E44B_000028:;
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
L_fn_0E44B_00002A:;
    push16(cpu, cpu->si);                    /* push si */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x2FE4))); /* mov al, byte ds:[bx+0x2FE4] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xE0)); /* add ax, 0xE0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE44D */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E48A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E48A");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov al, byte ss:[bp+0x8] */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si - 0x35E9), (uint8_t)(cpu->al)); /* mov byte ds:[si+-0x35E9], al */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov al, byte ss:[bp+0x6] */
    mem_write8(cpu, cpu->ds, (uint16_t)(cpu->si - 0x394A), (uint8_t)(cpu->al)); /* mov byte ds:[si+-0x394A], al */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3593))); /* mov ax, word ds:[bx+-0x3593] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)), cpu->ax))); /* add word ss:[bp+0x6], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)), 0x5F); /* cmp word ss:[bp+0x6], 0x5F */
    if (cc_le(cpu)) goto L_fn_0E48A_00002F;  /* jle 0x002F */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6), (uint16_t)(0x5F)); /* mov word ss:[bp+0x6], 0x5F */
L_fn_0E48A_00002F:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)), 0x0); /* cmp word ss:[bp+0x6], 0x0 */
    if (cc_ge(cpu)) goto L_fn_0E48A_00003A;  /* jge 0x003A */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6), (uint16_t)(0x0)); /* mov word ss:[bp+0x6], 0x0 */
L_fn_0E48A_00003A:;
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _o = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x35DC)); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)((uint16_t)(cpu->bx - 0x35DC) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[bx+-0x35DC] */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x39B6))); /* mov al, byte ds:[bx+-0x39B6] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xA0)); /* add ax, 0xA0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE40E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)), 0x0); /* cmp word ss:[bp+0x8], 0x0 */
    if (cc_e(cpu)) goto L_fn_0E48A_000073;   /* je 0x0073 */
    cpu->di = (uint16_t)(0x20);              /* mov di, 0x20 */
    goto L_fn_0E48A_000075;                  /* jmp 0x0075 */
L_fn_0E48A_000073:;
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
L_fn_0E48A_000075:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3A16))); /* mov al, byte ds:[bx+-0x3A16] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _r = cpu->ax & 0x3; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x3 */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->ax)); /* add dx, ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->dx)); /* add di, dx */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB0)); /* add ax, 0xB0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE40E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E52A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E52A");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xB0)); /* add ax, 0xB0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE36E */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xA0)); /* add ax, 0xA0 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE36E */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E54D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E54D");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(0x60);              /* mov ax, 0x60 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE34B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x80);              /* mov ax, 0x80 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE34B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x1830)); /* push word ds:[0x1830] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F7FF(cpu);                           /* call 0x12B2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->ax = (uint16_t)(0xFF);              /* mov ax, 0xFF */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE34B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x21);              /* mov ax, 0x21 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE34B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0E54D_000053;                  /* jmp 0x0053 */
L_fn_0E54D_00004A:;
    push16(cpu, mem_read16(cpu, cpu->ds, 0x1830)); /* push word ds:[0x1830] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F7FF(cpu);                           /* call 0x12B2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0E54D_000053:;
    flags_cmp16(cpu, cpu->si, 0xC8);         /* cmp si, 0xC8 */
    RECOMP_TICK(cpu);
    if (cc_b(cpu)) goto L_fn_0E54D_00004A;   /* jb 0x004A */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x1830)); /* push word ds:[0x1830] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F7FF(cpu);                           /* call 0x12B2 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    cpu->ax = (uint16_t)(0x60);              /* mov ax, 0x60 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE34B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x80);              /* mov ax, 0x80 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x4);               /* mov ax, 0x4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C898(cpu);                           /* call 0xE34B */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    flags_logic16(cpu, cpu->di & 0xE0);      /* test di, 0xE0 */
    if (cc_ne(cpu)) goto L_fn_0E54D_000094;  /* jne 0x0094 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    { uint16_t _r = cpu->ax & 0xE0; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xE0 */
    flags_cmp16(cpu, cpu->ax, 0xC0);         /* cmp ax, 0xC0 */
    if (cc_ne(cpu)) goto L_fn_0E54D_000094;  /* jne 0x0094 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_0E54D_000096;                  /* jmp 0x0096 */
L_fn_0E54D_000094:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_0E54D_000096:;
    goto L_fn_0E54D_000098;                  /* jmp 0x0098 */
L_fn_0E54D_000098:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E5EB(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E5EB");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_l(cpu)) goto L_fn_0E5EB_00001F;   /* jl 0x001F */
    flags_cmp16(cpu, cpu->si, 0x58);         /* cmp si, 0x58 */
    if (cc_be(cpu)) goto L_fn_0E5EB_000013;  /* jbe 0x0013 */
L_fn_0E5EB_000010:;
    cpu->si = (uint16_t)(0x57);              /* mov si, 0x57 */
L_fn_0E5EB_000013:;
    mem_write16(cpu, cpu->ds, 0x3756, (uint16_t)(cpu->si)); /* mov word ds:[0x3756], si */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->si + 0x3758))); /* mov al, byte ds:[si+0x3758] */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _t = cpu->ax; cpu->ax = (uint16_t)(cpu->si); cpu->si = (uint16_t)(_t); } /* xchg ax, si */
    goto L_fn_0E5EB_00002C;                  /* jmp 0x002C */
L_fn_0E5EB_00001F:;
    cpu->si = (uint16_t)(flags_sub16(cpu, 0, cpu->si)); /* neg si */
    flags_cmp16(cpu, cpu->si, 0x23);         /* cmp si, 0x23 */
    RECOMP_TICK(cpu);
    if (cc_a(cpu)) goto L_fn_0E5EB_000010;   /* ja 0x0010 */
    mem_write16(cpu, cpu->ds, 0x3756, (uint16_t)(0xFFFF)); /* mov word ds:[0x3756], 0xFFFF */
L_fn_0E5EB_00002C:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    mem_write16(cpu, cpu->ds, 0x7F, (uint16_t)(cpu->ax)); /* mov word ds:[0x7F], ax */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_0E5EB_000036;                  /* jmp 0x0036 */
L_fn_0E5EB_000036:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 0x4; return;                  /* ret 0x2 */
}

void fn_0E626(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E626");
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E627(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E627");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    goto L_fn_0E627_00000F;                  /* jmp 0x000F */
L_fn_0E627_000005:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37BA)); /* mov bx, word ds:[0x37BA] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu,0xFFFF); dispatch_near(cpu, SEG_0000, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x357C))); /* call word ds:[bx+-0x357C] */
L_fn_0E627_00000F:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37BA)); /* mov ax, word ds:[0x37BA] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x37BA, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x37BA), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ds:[0x37BA] */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_0E627_000005;  /* jne 0x0005 */
    push16(cpu,0xFFFF); dispatch_near(cpu, SEG_0000, mem_read16(cpu, cpu->ds, 0x37B2)); /* call word ds:[0x37B2] */
    push16(cpu,0xFFFF); dispatch_near(cpu, SEG_0000, mem_read16(cpu, cpu->ds, 0x37B4)); /* call word ds:[0x37B4] */
    push16(cpu,0xFFFF); dispatch_near(cpu, SEG_0000, mem_read16(cpu, cpu->ds, 0x37B6)); /* call word ds:[0x37B6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_00104(cpu);                           /* call 0x1ADD */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E65C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E65C");
    mem_write16(cpu, SEG_0000, 0xE656, (uint16_t)(pop16(cpu))); /* pop word cs:[0xE656] */
    mem_write16(cpu, SEG_0000, 0xE658, (uint16_t)(cpu->ds)); /* mov word cs:[0xE658], ds */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->es = (uint16_t)(mem_read16(cpu, cpu->ds, 0x7B)); /* mov es, word ds:[0x7B] */
    cpu->si = (uint16_t)(0x80);              /* mov si, 0x80 */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    cpu->al = mem_read8(cpu, cpu->es, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    cpu->bp = (uint16_t)(cpu->es);           /* mov bp, es */
    { uint16_t _t = cpu->si; cpu->si = (uint16_t)(cpu->dx); cpu->dx = (uint16_t)(_t); } /* xchg si, dx */
    { uint16_t _t = cpu->ax; cpu->ax = (uint16_t)(cpu->bx); cpu->bx = (uint16_t)(_t); } /* xchg ax, bx */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, 0x75)); /* mov si, word ds:[0x75] */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x2)); /* add si, 0x2 */
    cpu->cx = (uint16_t)(0x1);               /* mov cx, 0x1 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, 0x7D), 0x3); /* cmp byte ds:[0x7D], 0x3 */
    if (cc_b(cpu)) goto L_fn_0E65C_00003E;   /* jb 0x003E */
    cpu->es = (uint16_t)(mem_read16(cpu, cpu->ds, 0x77)); /* mov es, word ds:[0x77] */
    cpu->di = (uint16_t)(cpu->si);           /* mov di, si */
    cpu->cl = (uint8_t)(0x7F);               /* mov cl, 0x7F */
    { uint8_t _r = cpu->al ^ cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* xor al, al */
    while (cpu->cx != 0) { cpu->cx--;        /* repnz scasb */
        flags_cmp8(cpu, cpu->al, mem_read8(cpu, cpu->es, cpu->di)); cpu->di += df(cpu) ? -1 : 1; /* scasb */
        if (zf(cpu)) break;
    }
    if (cpu->cx == 0) { recomp_dispatch(cpu, 0xE70, 0xD); return; } /* jcxz tail 0x00E70D */ /* jcxz 0x00B1 */
    { uint8_t _r = cpu->cl ^ 0x7F; flags_logic8(cpu, _r); cpu->cl = (uint8_t)(_r); } /* xor cl, 0x7F */
L_fn_0E65C_00003E:;
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->bx)); /* add ax, bx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->cx)); /* add ax, cx */
    { uint16_t _r = cpu->ax & 0xFFFE; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xFFFE */
    cpu->di = (uint16_t)(cpu->sp);           /* mov di, sp */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, cpu->ax)); /* sub di, ax */
    if (cc_b(cpu)) { recomp_dispatch(cpu, 0xE70, 0xD); return; } /* tail-jcc 0x00E70D */ /* jb 0x00B1 */
    cpu->sp = (uint16_t)(cpu->di);           /* mov sp, di */
    cpu->ax = (uint16_t)(cpu->es);           /* mov ax, es */
    cpu->ds = (uint16_t)(cpu->ax);           /* mov ds, ax */
    cpu->ax = (uint16_t)(cpu->ss);           /* mov ax, ss */
    cpu->es = (uint16_t)(cpu->ax);           /* mov es, ax */
    push16(cpu, cpu->cx);                    /* push cx */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec cx */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    { uint8_t _r = cpu->al ^ cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* xor al, al */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    cpu->ds = (uint16_t)(cpu->bp);           /* mov ds, bp */
    { uint16_t _t = cpu->dx; cpu->dx = (uint16_t)(cpu->si); cpu->si = (uint16_t)(_t); } /* xchg dx, si */
    { uint16_t _t = cpu->cx; cpu->cx = (uint16_t)(cpu->bx); cpu->bx = (uint16_t)(_t); } /* xchg cx, bx */
    cpu->ax = (uint16_t)(cpu->bx);           /* mov ax, bx */
    cpu->dx = (uint16_t)(cpu->ax);           /* mov dx, ax */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
L_fn_0E65C_00006D:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E6E5(cpu);                           /* call 0x0089 */
    if (cc_a(cpu)) goto L_fn_0E65C_000079;   /* ja 0x0079 */
L_fn_0E65C_000072:;
    if (cc_b(cpu)) { fn_0E710(cpu); return; } /* tail-jcc 0x00E710 */ /* jb 0x00B4 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E6E5(cpu);                           /* call 0x0089 */
    RECOMP_TICK(cpu);
    if (cc_a(cpu)) goto L_fn_0E65C_000072;   /* ja 0x0072 */
L_fn_0E65C_000079:;
    flags_cmp8(cpu, cpu->al, 0x20);          /* cmp al, 0x20 */
    if (cc_e(cpu)) goto L_fn_0E65C_000085;   /* je 0x0085 */
    flags_cmp8(cpu, cpu->al, 0xD);           /* cmp al, 0xD */
    if (cc_e(cpu)) goto L_fn_0E65C_000085;   /* je 0x0085 */
    flags_cmp8(cpu, cpu->al, 0x9);           /* cmp al, 0x9 */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_0E65C_00006D;  /* jne 0x006D */
L_fn_0E65C_000085:;
    { uint8_t _r = cpu->al ^ cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* xor al, al */
    RECOMP_TICK(cpu);
    goto L_fn_0E65C_00006D;                  /* jmp 0x006D */
}

void fn_0E6E5(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E6E5");
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_0E6E5_00000B;   /* je 0x000B */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc dx */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    { uint8_t _r = cpu->al | cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, al */
    if (cc_ne(cpu)) goto L_fn_0E6E5_00000B;  /* jne 0x000B */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
L_fn_0E6E5_00000B:;
    { uint16_t _t = cpu->al; cpu->al = (uint8_t)(cpu->ah); cpu->ah = (uint8_t)(_t); } /* xchg al, ah */
    { uint8_t _r = cpu->al ^ cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* xor al, al */
    cpu->flags |= FLAG_CF;                   /* stc */
    if (cpu->cx == 0) goto L_fn_0E6E5_000027; /* jcxz 0x0027 */
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec cx */
    cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, 0x22)); /* sub al, 0x22 */
    if (cc_e(cpu)) goto L_fn_0E6E5_000027;   /* je 0x0027 */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0x22)); /* add al, 0x22 */
    flags_cmp8(cpu, cpu->al, 0x5C);          /* cmp al, 0x5C */
    if (cc_ne(cpu)) goto L_fn_0E6E5_000025;  /* jne 0x0025 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ds, cpu->si), 0x22); /* cmp byte ds:[si], 0x22 */
    if (cc_ne(cpu)) goto L_fn_0E6E5_000025;  /* jne 0x0025 */
    cpu->al = mem_read8(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec cx */
L_fn_0E6E5_000025:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
L_fn_0E6E5_000027:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E710(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E710");
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, cpu->dx)); /* add cx, dx */
    cpu->ds = (uint16_t)(mem_read16(cpu, SEG_0000, 0xE658)); /* mov ds, word cs:[0xE658] */
    mem_write16(cpu, cpu->ds, 0x6B, (uint16_t)(cpu->bx)); /* mov word ds:[0x6B], bx */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->bx)); /* add bx, bx */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->bx)); /* add bx, bx */
    cpu->si = (uint16_t)(cpu->sp);           /* mov si, sp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->bp = (uint16_t)(flags_sub16(cpu, cpu->bp, cpu->bx)); /* sub bp, bx */
    if (cc_b(cpu)) { recomp_dispatch(cpu, 0x1E70, 0xD); return; } /* tail-jcc 0x01E70D */ /* jb 0xFFFD */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    mem_write16(cpu, cpu->ds, 0x6D, (uint16_t)(cpu->bp)); /* mov word ds:[0x6D], bp */
    mem_write16(cpu, cpu->ds, 0x6F, (uint16_t)(cpu->ss)); /* mov word ds:[0x6F], ss */
L_fn_0E710_000023:;
    if (cpu->cx == 0) goto L_fn_0E710_000036; /* jcxz 0x0036 */
    mem_write16(cpu, cpu->ss, cpu->bp, (uint16_t)(cpu->si)); /* mov word ss:[bp], si */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x2), (uint16_t)(cpu->ss)); /* mov word ss:[bp+0x2], ss */
    cpu->bp = (uint16_t)(flags_add16(cpu, cpu->bp, 0x4)); /* add bp, 0x4 */
L_fn_0E710_00002E:;
    cpu->al = mem_read8(cpu, cpu->ss, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    { uint8_t _r = cpu->al | cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, al */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0 && !zf(cpu)) goto L_fn_0E710_00002E; /* loopnz 0x002E */
    RECOMP_TICK(cpu);
    if (cc_e(cpu)) goto L_fn_0E710_000023;   /* je 0x0023 */
L_fn_0E710_000036:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ss, cpu->bp, (uint16_t)(cpu->ax)); /* mov word ss:[bp], ax */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+0x2], ax */
    return; /* jmp cs:[0xE656] == return to the caller, SP stays lowered */ /* jmp word cs:[0xE656] */
}

void fn_0E753(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E753");
    cpu->es = (uint16_t)(mem_read16(cpu, cpu->ds, 0x77)); /* mov es, word ds:[0x77] */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x79)); /* push word ds:[0x79] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E7B9(cpu);                           /* call 0x0066 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x2)); /* add sp, 0x2 */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->ds, 0x71, (uint16_t)(cpu->ax)); /* mov word ds:[0x71], ax */
    mem_write16(cpu, cpu->ds, 0x73, (uint16_t)(cpu->dx)); /* mov word ds:[0x73], dx */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ds = (uint16_t)(cpu->dx);           /* mov ds, dx */
    { uint16_t _r = cpu->ax | cpu->dx; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, dx */
    if (cc_ne(cpu)) goto L_fn_0E753_000025;  /* jne 0x0025 */
    fn_001A4(cpu); return; /* tail-jmp 0x0001A4 */ /* jmp 0x1A51 */
L_fn_0E753_000025:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    cpu->cx = (uint16_t)(0xFFFF);            /* mov cx, 0xFFFF */
L_fn_0E753_00002A:;
    mem_write16(cpu, cpu->ds, cpu->bx, (uint16_t)(cpu->di)); /* mov word ds:[bx], di */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x2), (uint16_t)(cpu->es)); /* mov word ds:[bx+0x2], es */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x4)); /* add bx, 0x4 */
    while (cpu->cx != 0) { cpu->cx--;        /* repnz scasb */
        flags_cmp8(cpu, cpu->al, mem_read8(cpu, cpu->es, cpu->di)); cpu->di += df(cpu) ? -1 : 1; /* scasb */
        if (zf(cpu)) break;
    }
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->di), cpu->al); /* cmp byte es:[di], al */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_0E753_00002A;  /* jne 0x002A */
    mem_write16(cpu, cpu->ds, cpu->bx, (uint16_t)(cpu->ax)); /* mov word ds:[bx], ax */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x2), (uint16_t)(cpu->ax)); /* mov word ds:[bx+0x2], ax */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E793(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E793");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x37BA), 0x20); /* cmp word ds:[0x37BA], 0x20 */
    if (cc_ne(cpu)) goto L_fn_0E793_00000F;  /* jne 0x000F */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_0E793_000024;                  /* jmp 0x0024 */
L_fn_0E793_00000F:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37BA)); /* mov bx, word ds:[0x37BA] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x357C), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x357C], ax */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x37BA, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x37BA), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x37BA] */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0E793_000024;                  /* jmp 0x0024 */
L_fn_0E793_000024:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E7B9(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E7B9");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E9B4(cpu);                           /* call 0x01FB */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    goto L_fn_0E7B9_000011;                  /* jmp 0x0011 */
L_fn_0E7B9_000011:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E7CC(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E7CC");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xE))); /* mov dx, word es:[bx+0xE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC))); /* mov ax, word es:[bx+0xC] */
    mem_write16(cpu, cpu->ds, 0x37C6, (uint16_t)(cpu->dx)); /* mov word ds:[0x37C6], dx */
    mem_write16(cpu, cpu->ds, 0x37C4, (uint16_t)(cpu->ax)); /* mov word ds:[0x37C4], ax */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov cx, word ss:[bp+0x6] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC6A(cpu);                           /* call 0000:EC6A */
    if (cc_ne(cpu)) goto L_fn_0E7CC_000033;  /* jne 0x0033 */
    mem_write16(cpu, cpu->ds, 0x37C6, (uint16_t)(0x0)); /* mov word ds:[0x37C6], 0x0 */
    mem_write16(cpu, cpu->ds, 0x37C4, (uint16_t)(0x0)); /* mov word ds:[0x37C4], 0x0 */
    goto L_fn_0E7CC_000064;                  /* jmp 0x0064 */
L_fn_0E7CC_000033:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x8)); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)((uint16_t)(cpu->bx + 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx+0x8] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x37C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x37C4 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x37C4] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xA), (uint16_t)(cpu->dx)); /* mov word es:[bx+0xA], dx */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x8), (uint16_t)(cpu->ax)); /* mov word es:[bx+0x8], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C6)); /* mov dx, word ds:[0x37C6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C4)); /* mov ax, word ds:[0x37C4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xE), (uint16_t)(cpu->dx)); /* mov word es:[bx+0xE], dx */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC), (uint16_t)(cpu->ax)); /* mov word es:[bx+0xC], ax */
L_fn_0E7CC_000064:;
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E834(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E834");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov ax, word ss:[bp+0x8] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->es, cpu->bx), cpu->ax))); /* sub word es:[bx], ax */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2), (uint16_t)(flags_sbb(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)), cpu->dx, 16))); /* sbb word es:[bx+0x2], dx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov cx, word es:[bx+0x2] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov bx, word es:[bx] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC0F(cpu);                           /* call 0000:EC0F */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov ax, word ss:[bp+0x8] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1)); /* add ax, 0x1 */
    cpu->dx = (uint16_t)(flags_adc(cpu, cpu->dx, 0x0, 16)); /* adc dx, 0x0 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2), (uint16_t)(cpu->dx)); /* mov word es:[bx+0x2], dx */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(cpu->ax)); /* mov word es:[bx], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x6), (uint16_t)(cpu->dx)); /* mov word es:[bx+0x6], dx */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4), (uint16_t)(cpu->ax)); /* mov word es:[bx+0x4], ax */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov cx, word ss:[bp+0x6] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C2)); /* mov dx, word ds:[0x37C2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C0)); /* mov ax, word ds:[0x37C0] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC6A(cpu);                           /* call 0000:EC6A */
    if (cc_ne(cpu)) goto L_fn_0E834_000079;  /* jne 0x0079 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->ds, 0x37C2, (uint16_t)(cpu->es)); /* mov word ds:[0x37C2], es */
    mem_write16(cpu, cpu->ds, 0x37C0, (uint16_t)(cpu->bx)); /* mov word ds:[0x37C0], bx */
    goto L_fn_0E834_0000A1;                  /* jmp 0x00A1 */
L_fn_0E834_000079:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov cx, word ss:[bp+0xA] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC0F(cpu);                           /* call 0000:EC0F */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6), (uint16_t)(cpu->dx)); /* mov word ss:[bp+0x6], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+0x4], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x6), (uint16_t)(cpu->dx)); /* mov word es:[bx+0x6], dx */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4), (uint16_t)(cpu->ax)); /* mov word es:[bx+0x4], ax */
L_fn_0E834_0000A1:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    goto L_fn_0E834_0000AC;                  /* jmp 0x00AC */
L_fn_0E834_0000AC:;
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E8E4(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E8E4");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EB94(cpu);                           /* call 0x02B0 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0xFFFF); /* cmp word ss:[bp+-0x2], 0xFFFF */
    if (cc_ne(cpu)) goto L_fn_0E8E4_000029;  /* jne 0x0029 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0xFFFF); /* cmp word ss:[bp+-0x4], 0xFFFF */
    if (cc_ne(cpu)) goto L_fn_0E8E4_000029;  /* jne 0x0029 */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0E8E4_000068;                  /* jmp 0x0068 */
L_fn_0E8E4_000029:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C2)); /* mov dx, word ds:[0x37C2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C0)); /* mov ax, word ds:[0x37C0] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x6), (uint16_t)(cpu->dx)); /* mov word es:[bx+0x6], dx */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4), (uint16_t)(cpu->ax)); /* mov word es:[bx+0x4], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1)); /* add ax, 0x1 */
    cpu->dx = (uint16_t)(flags_adc(cpu, cpu->dx, 0x0, 16)); /* adc dx, 0x0 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2), (uint16_t)(cpu->dx)); /* mov word es:[bx+0x2], dx */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(cpu->ax)); /* mov word es:[bx], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->ds, 0x37C2, (uint16_t)(cpu->es)); /* mov word ds:[0x37C2], es */
    mem_write16(cpu, cpu->ds, 0x37C0, (uint16_t)(cpu->bx)); /* mov word ds:[0x37C0], bx */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C2)); /* mov dx, word ds:[0x37C2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C0)); /* mov ax, word ds:[0x37C0] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    goto L_fn_0E8E4_000068;                  /* jmp 0x0068 */
L_fn_0E8E4_000068:;
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E950(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E950");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EB94(cpu);                           /* call 0x0244 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2)), 0xFFFF); /* cmp word ss:[bp+-0x2], 0xFFFF */
    if (cc_ne(cpu)) goto L_fn_0E950_000029;  /* jne 0x0029 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0xFFFF); /* cmp word ss:[bp+-0x4], 0xFFFF */
    if (cc_ne(cpu)) goto L_fn_0E950_000029;  /* jne 0x0029 */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0E950_000060;                  /* jmp 0x0060 */
L_fn_0E950_000029:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->ds, 0x37BE, (uint16_t)(cpu->es)); /* mov word ds:[0x37BE], es */
    mem_write16(cpu, cpu->ds, 0x37BC, (uint16_t)(cpu->bx)); /* mov word ds:[0x37BC], bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->ds, 0x37C2, (uint16_t)(cpu->es)); /* mov word ds:[0x37C2], es */
    mem_write16(cpu, cpu->ds, 0x37C0, (uint16_t)(cpu->bx)); /* mov word ds:[0x37C0], bx */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1)); /* add ax, 0x1 */
    cpu->dx = (uint16_t)(flags_adc(cpu, cpu->dx, 0x0, 16)); /* adc dx, 0x0 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2), (uint16_t)(cpu->dx)); /* mov word es:[bx+0x2], dx */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(cpu->ax)); /* mov word es:[bx], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    goto L_fn_0E950_000060;                  /* jmp 0x0060 */
L_fn_0E950_000060:;
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0E9B4(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0E9B4");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _r = cpu->ax | mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, word ss:[bp+0x6] */
    if (cc_ne(cpu)) goto L_fn_0E9B4_000015;  /* jne 0x0015 */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0E9B4_000107;                  /* jmp 0x0107 */
L_fn_0E9B4_000015:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x17)); /* add ax, 0x17 */
    cpu->dx = (uint16_t)(flags_adc(cpu, cpu->dx, 0x0, 16)); /* adc dx, 0x0 */
    { uint16_t _r = cpu->ax & 0xFFF0; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xFFF0 */
    { uint16_t _r = cpu->dx & 0xFFFF; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* and dx, 0xFFFF */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6), (uint16_t)(cpu->dx)); /* mov word ss:[bp+0x6], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+0x4], ax */
    { uint16_t _r = cpu->cx ^ cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* xor cx, cx */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37BE)); /* mov dx, word ds:[0x37BE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37BC)); /* mov ax, word ds:[0x37BC] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC6A(cpu);                           /* call 0000:EC6A */
    if (cc_ne(cpu)) goto L_fn_0E9B4_00004E;  /* jne 0x004E */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E950(cpu);                           /* call 0xFF9C */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0E9B4_000107;                  /* jmp 0x0107 */
L_fn_0E9B4_00004E:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C6)); /* mov dx, word ds:[0x37C6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C4)); /* mov ax, word ds:[0x37C4] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    { uint16_t _r = cpu->cx ^ cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* xor cx, cx */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC6A(cpu);                           /* call 0000:EC6A */
    if (cc_ne(cpu)) goto L_fn_0E9B4_000069;  /* jne 0x0069 */
    goto L_fn_0E9B4_0000FA;                  /* jmp 0x00FA */
L_fn_0E9B4_000069:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov dx, word es:[bx+0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov cx, word ss:[bp+0x6] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x30)); /* add bx, 0x30 */
    cpu->cx = (uint16_t)(flags_adc(cpu, cpu->cx, 0x0, 16)); /* adc cx, 0x0 */
    flags_cmp16(cpu, cpu->dx, cpu->cx);      /* cmp dx, cx */
    if (cc_b(cpu)) goto L_fn_0E9B4_00009D;   /* jb 0x009D */
    if (cc_ne(cpu)) goto L_fn_0E9B4_000089;  /* jne 0x0089 */
    flags_cmp16(cpu, cpu->ax, cpu->bx);      /* cmp ax, bx */
    if (cc_b(cpu)) goto L_fn_0E9B4_00009D;   /* jb 0x009D */
L_fn_0E9B4_000089:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E834(cpu);                           /* call 0xFE80 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    goto L_fn_0E9B4_000107;                  /* jmp 0x0107 */
L_fn_0E9B4_00009D:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov dx, word es:[bx+0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    flags_cmp16(cpu, cpu->dx, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* cmp dx, word ss:[bp+0x6] */
    if (cc_b(cpu)) goto L_fn_0E9B4_0000D5;   /* jb 0x00D5 */
    if (cc_ne(cpu)) goto L_fn_0E9B4_0000B3;  /* jne 0x00B3 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* cmp ax, word ss:[bp+0x4] */
    if (cc_b(cpu)) goto L_fn_0E9B4_0000D5;   /* jb 0x00D5 */
L_fn_0E9B4_0000B3:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E7CC(cpu);                           /* call 0xFE18 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->es, cpu->bx), 0x1))); /* add word es:[bx], 0x1 */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2), (uint16_t)(flags_adc(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)), 0x0, 16))); /* adc word es:[bx+0x2], 0x0 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x8)); /* add ax, 0x8 */
    goto L_fn_0E9B4_000107;                  /* jmp 0x0107 */
L_fn_0E9B4_0000D5:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC)); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)((uint16_t)(cpu->bx + 0xC) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx+0xC] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C6)); /* mov cx, word ds:[0x37C6] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C4)); /* mov bx, word ds:[0x37C4] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC6A(cpu);                           /* call 0000:EC6A */
    if (cc_e(cpu)) goto L_fn_0E9B4_0000FA;   /* je 0x00FA */
    RECOMP_TICK(cpu);
    goto L_fn_0E9B4_000069;                  /* jmp 0x0069 */
L_fn_0E9B4_0000FA:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E8E4(cpu);                           /* call 0xFF30 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0E9B4_000107;                  /* jmp 0x0107 */
L_fn_0E9B4_000107:;
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0EABF(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0EABF");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov si, word ss:[bp+0x6] */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, mem_read16(cpu, cpu->ds, 0x7B))); /* sub si, word ds:[0x7B] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x3F)); /* add ax, 0x3F */
    cpu->cl = (uint8_t)(0x6);                /* mov cl, 0x6 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, cl */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    flags_cmp16(cpu, cpu->si, mem_read16(cpu, cpu->ds, 0x37C8)); /* cmp si, word ds:[0x37C8] */
    if (cc_ne(cpu)) goto L_fn_0EABF_00002E;  /* jne 0x002E */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->ds, 0x8D, (uint16_t)(cpu->es)); /* mov word ds:[0x8D], es */
    mem_write16(cpu, cpu->ds, 0x8B, (uint16_t)(cpu->bx)); /* mov word ds:[0x8B], bx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_0EABF_000088;                  /* jmp 0x0088 */
L_fn_0EABF_00002E:;
    cpu->cl = (uint8_t)(0x6);                /* mov cl, 0x6 */
    { uint16_t _v = cpu->si; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->si = (uint16_t)(_r); } } /* shl si, cl */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0x91)); /* mov di, word ds:[0x91] */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x7B))); /* add ax, word ds:[0x7B] */
    flags_cmp16(cpu, cpu->ax, cpu->di);      /* cmp ax, di */
    if (cc_be(cpu)) goto L_fn_0EABF_000046;  /* jbe 0x0046 */
    cpu->si = (uint16_t)(cpu->di);           /* mov si, di */
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, mem_read16(cpu, cpu->ds, 0x7B))); /* sub si, word ds:[0x7B] */
L_fn_0EABF_000046:;
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x7B)); /* push word ds:[0x7B] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EC8B(cpu);                           /* call 0x01CC */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    flags_cmp16(cpu, cpu->di, 0xFFFF);       /* cmp di, 0xFFFF */
    if (cc_ne(cpu)) goto L_fn_0EABF_000072;  /* jne 0x0072 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->cl = (uint8_t)(0x6);                /* mov cl, 0x6 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, cl */
    mem_write16(cpu, cpu->ds, 0x37C8, (uint16_t)(cpu->ax)); /* mov word ds:[0x37C8], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->ds, 0x8D, (uint16_t)(cpu->es)); /* mov word ds:[0x8D], es */
    mem_write16(cpu, cpu->ds, 0x8B, (uint16_t)(cpu->bx)); /* mov word ds:[0x8B], bx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_0EABF_000088;                  /* jmp 0x0088 */
    goto L_fn_0EABF_000088;                  /* jmp 0x0088 */
L_fn_0EABF_000072:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x7B)); /* mov ax, word ds:[0x7B] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->di)); /* add ax, di */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->dx = (uint16_t)(cpu->ax);           /* mov dx, ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0x91, (uint16_t)(cpu->dx)); /* mov word ds:[0x91], dx */
    mem_write16(cpu, cpu->ds, 0x8F, (uint16_t)(cpu->ax)); /* mov word ds:[0x8F], ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0EABF_000088;                  /* jmp 0x0088 */
L_fn_0EABF_000088:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 0x6; return;                  /* ret 0x4 */
}

void fn_0EB4D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0EB4D");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x89)); /* mov cx, word ds:[0x89] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x87)); /* mov bx, word ds:[0x87] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC6A(cpu);                           /* call 0000:EC6A */
    if (cc_b(cpu)) goto L_fn_0EB4D_00003A;   /* jb 0x003A */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x91)); /* mov cx, word ds:[0x91] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x8F)); /* mov bx, word ds:[0x8F] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC6A(cpu);                           /* call 0000:EC6A */
    if (cc_a(cpu)) goto L_fn_0EB4D_00003A;   /* ja 0x003A */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EABF(cpu);                           /* call 0xFF72 */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_0EB4D_000041;  /* jne 0x0041 */
L_fn_0EB4D_00003A:;
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_0EB4D_000045;                  /* jmp 0x0045 */
    goto L_fn_0EB4D_000045;                  /* jmp 0x0045 */
L_fn_0EB4D_000041:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0EB4D_000045;                  /* jmp 0x0045 */
L_fn_0EB4D_000045:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0EB94(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0EB94");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x8)); /* sub sp, 0x8 */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x8D)); /* mov dx, word ds:[0x8D] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x8B)); /* mov ax, word ds:[0x8B] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov cx, word ss:[bp+0x6] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC0F(cpu);                           /* call 0000:EC0F */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x6], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x89)); /* mov cx, word ds:[0x89] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x87)); /* mov bx, word ds:[0x87] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov dx, word ss:[bp+-0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC6A(cpu);                           /* call 0000:EC6A */
    if (cc_b(cpu)) goto L_fn_0EB94_000048;   /* jb 0x0048 */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x91)); /* mov cx, word ds:[0x91] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x8F)); /* mov bx, word ds:[0x8F] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* mov dx, word ss:[bp+-0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* mov ax, word ss:[bp+-0x8] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC6A(cpu);                           /* call 0000:EC6A */
    if (cc_be(cpu)) goto L_fn_0EB94_000050;  /* jbe 0x0050 */
L_fn_0EB94_000048:;
    cpu->dx = (uint16_t)(0xFFFF);            /* mov dx, 0xFFFF */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_0EB94_000077;                  /* jmp 0x0077 */
L_fn_0EB94_000050:;
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x8B); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x8B + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x8B] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EABF(cpu);                           /* call 0xFF2B */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ne(cpu)) goto L_fn_0EB94_00006F;  /* jne 0x006F */
    cpu->dx = (uint16_t)(0xFFFF);            /* mov dx, 0xFFFF */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_0EB94_000077;                  /* jmp 0x0077 */
L_fn_0EB94_00006F:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    goto L_fn_0EB94_000077;                  /* jmp 0x0077 */
L_fn_0EB94_000077:;
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0EC0F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0EC0F");
    { uint16_t _r = cpu->cx | cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* or cx, cx */
    if (cc_ge(cpu)) goto L_fn_0EC0F_000011;  /* jge 0x0011 */
    cpu->bx = (uint16_t)(~cpu->bx);          /* not bx */
    cpu->cx = (uint16_t)(~cpu->cx);          /* not cx */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x1)); /* add bx, 0x1 */
    cpu->cx = (uint16_t)(flags_adc(cpu, cpu->cx, 0x0, 16)); /* adc cx, 0x0 */
    goto L_fn_0EC0F_00003D;                  /* jmp 0x003D */
    /* nop */                                /* nop */
L_fn_0EC0F_000011:;
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->bx)); /* add ax, bx */
    if (cc_ae(cpu)) goto L_fn_0EC0F_000019;  /* jae 0x0019 */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 0x1000)); /* add dx, 0x1000 */
L_fn_0EC0F_000019:;
    cpu->ch = (uint8_t)(cpu->cl);            /* mov ch, cl */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint8_t _v = cpu->ch; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ch = (uint8_t)(_r); } } /* shl ch, cl */
    cpu->dh = (uint8_t)(flags_add8(cpu, cpu->dh, cpu->ch)); /* add dh, ch */
    cpu->ch = (uint8_t)(cpu->al);            /* mov ch, al */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, cl */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->ax)); /* add dx, ax */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    { uint16_t _r = cpu->ax & 0xF; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF */
    { uint16_t _ip=pop16(cpu); uint16_t _cs=pop16(cpu); if (_ip != 0xFFFF && _ip != 0) recomp_dispatch(cpu,_cs,_ip); return; } /* retf */
    { uint16_t _r = cpu->cx | cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* or cx, cx */
    if (cc_ge(cpu)) goto L_fn_0EC0F_00003D;  /* jge 0x003D */
    cpu->bx = (uint16_t)(~cpu->bx);          /* not bx */
    cpu->cx = (uint16_t)(~cpu->cx);          /* not cx */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0x1)); /* add bx, 0x1 */
    cpu->cx = (uint16_t)(flags_adc(cpu, cpu->cx, 0x0, 16)); /* adc cx, 0x0 */
    RECOMP_TICK(cpu);
    goto L_fn_0EC0F_000011;                  /* jmp 0x0011 */
L_fn_0EC0F_00003D:;
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
    if (cc_ae(cpu)) goto L_fn_0EC0F_000045;  /* jae 0x0045 */
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 0x1000)); /* sub dx, 0x1000 */
L_fn_0EC0F_000045:;
    cpu->bh = (uint8_t)(cpu->cl);            /* mov bh, cl */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint8_t _v = cpu->bh; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->bh = (uint8_t)(_r); } } /* shl bh, cl */
    { uint8_t _r = cpu->bl ^ cpu->bl; flags_logic8(cpu, _r); cpu->bl = (uint8_t)(_r); } /* xor bl, bl */
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, cpu->bx)); /* sub dx, bx */
    cpu->ch = (uint8_t)(cpu->al);            /* mov ch, al */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, cl */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->ax)); /* add dx, ax */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    { uint16_t _r = cpu->ax & 0xF; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF */
    { uint16_t _ip=pop16(cpu); uint16_t _cs=pop16(cpu); if (_ip != 0xFFFF && _ip != 0) recomp_dispatch(cpu,_cs,_ip); return; } /* retf */
}

void fn_0EC6A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0EC6A");
    push16(cpu, cpu->cx);                    /* push cx */
    cpu->ch = (uint8_t)(cpu->al);            /* mov ch, al */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, cl */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->ax)); /* add dx, ax */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, cl */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, cpu->bx)); /* add cx, bx */
    cpu->bl = (uint8_t)(cpu->ah);            /* mov bl, ah */
    { uint16_t _r = cpu->ax & 0xF; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF */
    { uint16_t _r = cpu->bx & 0xF; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* and bx, 0xF */
    flags_cmp16(cpu, cpu->dx, cpu->cx);      /* cmp dx, cx */
    if (cc_ne(cpu)) goto L_fn_0EC6A_000020;  /* jne 0x0020 */
    flags_cmp16(cpu, cpu->ax, cpu->bx);      /* cmp ax, bx */
L_fn_0EC6A_000020:;
    { uint16_t _ip=pop16(cpu); uint16_t _cs=pop16(cpu); if (_ip != 0xFFFF && _ip != 0) recomp_dispatch(cpu,_cs,_ip); return; } /* retf */
}

void fn_0EC8B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0EC8B");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ah = (uint8_t)(0x4A);               /* mov ah, 0x4A */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov bx, word ss:[bp+0x6] */
    cpu->es = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov es, word ss:[bp+0x4] */
    dos_int21(cpu);                          /* int 0x21 */
    if (cc_b(cpu)) goto L_fn_0EC8B_000014;   /* jb 0x0014 */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_0EC8B_00001C;                  /* jmp 0x001C */
L_fn_0EC8B_000014:;
    push16(cpu, cpu->bx);                    /* push bx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E5EB(cpu);                           /* call 0xF960 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    goto L_fn_0EC8B_00001C;                  /* jmp 0x001C */
L_fn_0EC8B_00001C:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0ECA9(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0ECA9");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov cx, word ss:[bp+0x4] */
    cpu->ah = (uint8_t)(0x3C);               /* mov ah, 0x3C */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x6) + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ss:[bp+0x6] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    if (cc_b(cpu)) goto L_fn_0ECA9_000013;   /* jb 0x0013 */
    goto L_fn_0ECA9_000019;                  /* jmp 0x0019 */
L_fn_0ECA9_000013:;
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E5EB(cpu);                           /* call 0xF942 */
    goto L_fn_0ECA9_000019;                  /* jmp 0x0019 */
L_fn_0ECA9_000019:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 0x8; return;                  /* ret 0x6 */
}

void fn_0ECC6(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0ECC6");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, cpu->cx)); /* sub cx, cx */
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, cpu->dx)); /* sub dx, dx */
    cpu->ah = (uint8_t)(0x40);               /* mov ah, 0x40 */
    dos_int21(cpu);                          /* int 0x21 */
    goto L_fn_0ECC6_000010;                  /* jmp 0x0010 */
L_fn_0ECC6_000010:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 0x4; return;                  /* ret 0x2 */
}

void fn_0ECDA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0ECDA");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov di, word ss:[bp+0x8] */
    flags_logic16(cpu, cpu->di & 0xC000);    /* test di, 0xC000 */
    if (cc_ne(cpu)) goto L_fn_0ECDA_000019;  /* jne 0x0019 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x38F4)); /* mov ax, word ds:[0x38F4] */
    { uint16_t _r = cpu->ax & 0xC000; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xC000 */
    { uint16_t _r = cpu->di | cpu->ax; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, ax */
L_fn_0ECDA_000019:;
    flags_logic16(cpu, cpu->di & 0x100);     /* test di, 0x100 */
    if (cc_ne(cpu)) goto L_fn_0ECDA_000022;  /* jne 0x0022 */
    goto L_fn_0ECDA_0000B9;                  /* jmp 0x00B9 */
L_fn_0ECDA_000022:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x38F6)); /* mov ax, word ds:[0x38F6] */
    { uint16_t _r = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA)) & cpu->ax; flags_logic16(cpu, _r); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA), (uint16_t)(_r)); } /* and word ss:[bp+0xA], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    flags_logic16(cpu, cpu->ax & 0x180);     /* test ax, 0x180 */
    if (cc_ne(cpu)) goto L_fn_0ECDA_000037;  /* jne 0x0037 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E5EB(cpu);                           /* call 0xF911 */
L_fn_0ECDA_000037:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F3BB(cpu);                           /* call 0x06E1 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    flags_cmp16(cpu, cpu->ax, 0xFFFF);       /* cmp ax, 0xFFFF */
    if (cc_ne(cpu)) goto L_fn_0ECDA_000061;  /* jne 0x0061 */
    flags_logic16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA)) & 0x80); /* test word ss:[bp+0xA], 0x80 */
    if (cc_e(cpu)) goto L_fn_0ECDA_000059;   /* je 0x0059 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0ECDA_00005C;                  /* jmp 0x005C */
L_fn_0ECDA_000059:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
L_fn_0ECDA_00005C:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    goto L_fn_0ECDA_000075;                  /* jmp 0x0075 */
L_fn_0ECDA_000061:;
    flags_logic16(cpu, cpu->di & 0x400);     /* test di, 0x400 */
    if (cc_e(cpu)) goto L_fn_0ECDA_000073;   /* je 0x0073 */
    cpu->ax = (uint16_t)(0x50);              /* mov ax, 0x50 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E5EB(cpu);                           /* call 0xF911 */
    goto L_fn_0ECDA_000157;                  /* jmp 0x0157 */
    goto L_fn_0ECDA_000075;                  /* jmp 0x0075 */
L_fn_0ECDA_000073:;
    goto L_fn_0ECDA_0000B9;                  /* jmp 0x00B9 */
L_fn_0ECDA_000075:;
    flags_logic16(cpu, cpu->di & 0xF0);      /* test di, 0xF0 */
    if (cc_e(cpu)) goto L_fn_0ECDA_00009D;   /* je 0x009D */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ECA9(cpu);                           /* call 0xFFCF */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ge(cpu)) goto L_fn_0ECDA_000094;  /* jge 0x0094 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    goto L_fn_0ECDA_000157;                  /* jmp 0x0157 */
L_fn_0ECDA_000094:;
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EEDA(cpu);                           /* call 0x0200 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0ECDA_0000BE;                  /* jmp 0x00BE */
    goto L_fn_0ECDA_0000B6;                  /* jmp 0x00B6 */
L_fn_0ECDA_00009D:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ECA9(cpu);                           /* call 0xFFCF */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_ge(cpu)) goto L_fn_0ECDA_0000B6;  /* jge 0x00B6 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    goto L_fn_0ECDA_000157;                  /* jmp 0x0157 */
L_fn_0ECDA_0000B6:;
    goto L_fn_0ECDA_000132;                  /* jmp 0x0132 */
    /* nop */                                /* nop */
L_fn_0ECDA_0000B9:;
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(0x0)); /* mov word ss:[bp+-0x4], 0x0 */
L_fn_0ECDA_0000BE:;
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EE37(cpu);                           /* call 0x015D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_l(cpu)) goto L_fn_0ECDA_000132;   /* jl 0x0132 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EE82(cpu);                           /* call 0x01A8 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    flags_logic16(cpu, cpu->ax & 0x80);      /* test ax, 0x80 */
    if (cc_e(cpu)) goto L_fn_0ECDA_000108;   /* je 0x0108 */
    { uint16_t _r = cpu->di | 0x2000; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, 0x2000 */
    flags_logic16(cpu, cpu->di & 0x8000);    /* test di, 0x8000 */
    if (cc_e(cpu)) goto L_fn_0ECDA_000106;   /* je 0x0106 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    { uint16_t _r = cpu->ax & 0xFF; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xFF */
    { uint16_t _r = cpu->ax | 0x20; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, 0x20 */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EE82(cpu);                           /* call 0x01A8 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_0ECDA_000106:;
    goto L_fn_0ECDA_000112;                  /* jmp 0x0112 */
L_fn_0ECDA_000108:;
    flags_logic16(cpu, cpu->di & 0x200);     /* test di, 0x200 */
    if (cc_e(cpu)) goto L_fn_0ECDA_000112;   /* je 0x0112 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0ECC6(cpu);                           /* call 0xFFEC */
L_fn_0ECDA_000112:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)), 0x0); /* cmp word ss:[bp+-0x4], 0x0 */
    if (cc_e(cpu)) goto L_fn_0ECDA_000132;   /* je 0x0132 */
    flags_logic16(cpu, cpu->di & 0xF0);      /* test di, 0xF0 */
    if (cc_e(cpu)) goto L_fn_0ECDA_000132;   /* je 0x0132 */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F3BB(cpu);                           /* call 0x06E1 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_0ECDA_000132:;
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_l(cpu)) goto L_fn_0ECDA_000153;   /* jl 0x0153 */
    flags_logic16(cpu, cpu->di & 0x300);     /* test di, 0x300 */
    if (cc_e(cpu)) goto L_fn_0ECDA_000141;   /* je 0x0141 */
    cpu->ax = (uint16_t)(0x1000);            /* mov ax, 0x1000 */
    goto L_fn_0ECDA_000143;                  /* jmp 0x0143 */
L_fn_0ECDA_000141:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_0ECDA_000143:;
    cpu->dx = (uint16_t)(cpu->di);           /* mov dx, di */
    { uint16_t _r = cpu->dx & 0xF8FF; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* and dx, 0xF8FF */
    { uint16_t _r = cpu->ax | cpu->dx; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, dx */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC), (uint16_t)(cpu->ax)); /* mov word ds:[bx+0x38CC], ax */
L_fn_0ECDA_000153:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    goto L_fn_0ECDA_000157;                  /* jmp 0x0157 */
L_fn_0ECDA_000157:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0EE37(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0EE37");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->al = (uint8_t)(0x1);                /* mov al, 0x1 */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov cx, word ss:[bp+0x8] */
    flags_logic16(cpu, cpu->cx & 0x2);       /* test cx, 0x2 */
    if (cc_ne(cpu)) goto L_fn_0EE37_000019;  /* jne 0x0019 */
    cpu->al = (uint8_t)(0x2);                /* mov al, 0x2 */
    flags_logic16(cpu, cpu->cx & 0x4);       /* test cx, 0x4 */
    if (cc_ne(cpu)) goto L_fn_0EE37_000019;  /* jne 0x0019 */
    cpu->al = (uint8_t)(0x0);                /* mov al, 0x0 */
L_fn_0EE37_000019:;
    push16(cpu, cpu->ds);                    /* push ds */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ss:[bp+0x4] */
    cpu->cl = (uint8_t)(0xF0);               /* mov cl, 0xF0 */
    { uint8_t _r = cpu->cl & mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); flags_logic8(cpu, _r); cpu->cl = (uint8_t)(_r); } /* and cl, byte ss:[bp+0x8] */
    { uint8_t _r = cpu->al | cpu->cl; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, cl */
    cpu->ah = (uint8_t)(0x3D);               /* mov ah, 0x3D */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    if (cc_b(cpu)) goto L_fn_0EE37_000042;   /* jb 0x0042 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov ax, word ss:[bp+0x8] */
    { uint16_t _r = cpu->ax & 0xF8FF; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0xF8FF */
    { uint16_t _r = cpu->ax | 0x8000; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, 0x8000 */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC), (uint16_t)(cpu->ax)); /* mov word ds:[bx+0x38CC], ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    goto L_fn_0EE37_000048;                  /* jmp 0x0048 */
L_fn_0EE37_000042:;
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E5EB(cpu);                           /* call 0xF7B4 */
    goto L_fn_0EE37_000048;                  /* jmp 0x0048 */
L_fn_0EE37_000048:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0EE82(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0EE82");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ah = (uint8_t)(0x44);               /* mov ah, 0x44 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov al, byte ss:[bp+0x6] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov cx, word ss:[bp+0xC] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ss:[bp+0x8] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    if (cc_b(cpu)) goto L_fn_0EE82_000023;   /* jb 0x0023 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)), 0x0); /* cmp word ss:[bp+0x6], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0EE82_000021;  /* jne 0x0021 */
    cpu->ax = (uint16_t)(cpu->dx);           /* mov ax, dx */
    goto L_fn_0EE82_000029;                  /* jmp 0x0029 */
L_fn_0EE82_000021:;
    goto L_fn_0EE82_000029;                  /* jmp 0x0029 */
L_fn_0EE82_000023:;
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E5EB(cpu);                           /* call 0xF769 */
    goto L_fn_0EE82_000029;                  /* jmp 0x0029 */
L_fn_0EE82_000029:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0EEAD(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0EEAD");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    { uint16_t _r = cpu->si | cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* or si, si */
    if (cc_l(cpu)) goto L_fn_0EEAD_000010;   /* jl 0x0010 */
    flags_cmp16(cpu, cpu->si, 0x14);         /* cmp si, 0x14 */
    if (cc_l(cpu)) goto L_fn_0EEAD_000019;   /* jl 0x0019 */
L_fn_0EEAD_000010:;
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E5EB(cpu);                           /* call 0xF73E */
    goto L_fn_0EEAD_00002A;                  /* jmp 0x002A */
L_fn_0EEAD_000019:;
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC), (uint16_t)(0xFFFF)); /* mov word ds:[bx+0x38CC], 0xFFFF */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EEDA(cpu);                           /* call 0x002D */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0EEAD_00002A;                  /* jmp 0x002A */
L_fn_0EEAD_00002A:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0EEDA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0EEDA");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov si, word ss:[bp+0x4] */
    cpu->ah = (uint8_t)(0x3E);               /* mov ah, 0x3E */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    dos_int21(cpu);                          /* int 0x21 */
    if (cc_b(cpu)) goto L_fn_0EEDA_00001B;   /* jb 0x001B */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC), (uint16_t)(0xFFFF)); /* mov word ds:[bx+0x38CC], 0xFFFF */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0EEDA_000021;                  /* jmp 0x0021 */
L_fn_0EEDA_00001B:;
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E5EB(cpu);                           /* call 0xF711 */
    goto L_fn_0EEDA_000021;                  /* jmp 0x0021 */
L_fn_0EEDA_000021:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0EEFE(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0EEFE");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    flags_cmp16(cpu, cpu->ax, 0x2);          /* cmp ax, 0x2 */
    if (cc_b(cpu)) goto L_fn_0EEFE_00001E;   /* jb 0x001E */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    flags_logic16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC)) & 0x200); /* test word ds:[bx+0x38CC], 0x200 */
    if (cc_e(cpu)) goto L_fn_0EEFE_000023;   /* je 0x0023 */
L_fn_0EEFE_00001E:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0EEFE_0000B9;                  /* jmp 0x00B9 */
L_fn_0EEFE_000023:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EFBD(cpu);                           /* call 0x00BF */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    flags_cmp16(cpu, cpu->ax, 0x2);          /* cmp ax, 0x2 */
    if (cc_b(cpu)) goto L_fn_0EEFE_00004E;   /* jb 0x004E */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    flags_logic16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC)) & 0x8000); /* test word ds:[bx+0x38CC], 0x8000 */
    if (cc_e(cpu)) goto L_fn_0EEFE_000054;   /* je 0x0054 */
L_fn_0EEFE_00004E:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    goto L_fn_0EEFE_0000B9;                  /* jmp 0x00B9 */
    /* nop */                                /* nop */
L_fn_0EEFE_000054:;
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov cx, word ss:[bp+-0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x6) + 2)); cpu->si = _o; cpu->es = _s; } /* les si, word ss:[bp+0x6] */
    cpu->di = (uint16_t)(cpu->si);           /* mov di, si */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    cpu->flags &= ~FLAG_DF;                  /* cld */
L_fn_0EEFE_00005F:;
    cpu->al = mem_read8(cpu, cpu->es, cpu->si); cpu->si += df(cpu) ? -1 : 1; /* lodsb */
    flags_cmp8(cpu, cpu->al, 0x1A);          /* cmp al, 0x1A */
    if (cc_e(cpu)) goto L_fn_0EEFE_000093;   /* je 0x0093 */
    flags_cmp8(cpu, cpu->al, 0xD);           /* cmp al, 0xD */
    if (cc_e(cpu)) goto L_fn_0EEFE_00006E;   /* je 0x006E */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0EEFE_00005F; /* loop 0x005F */
    goto L_fn_0EEFE_00008B;                  /* jmp 0x008B */
L_fn_0EEFE_00006E:;
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0EEFE_00005F; /* loop 0x005F */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x1)); /* lea ax, word ss:[bp+-0x1] */
    push16(cpu, cpu->ss);                    /* push ss */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EFBD(cpu);                           /* call 0x00BF */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x1))); /* mov al, byte ss:[bp+-0x1] */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
L_fn_0EEFE_00008B:;
    flags_cmp16(cpu, cpu->di, cpu->bx);      /* cmp di, bx */
    if (cc_ne(cpu)) goto L_fn_0EEFE_000091;  /* jne 0x0091 */
    RECOMP_TICK(cpu);
    goto L_fn_0EEFE_000023;                  /* jmp 0x0023 */
L_fn_0EEFE_000091:;
    goto L_fn_0EEFE_0000B3;                  /* jmp 0x00B3 */
L_fn_0EEFE_000093:;
    push16(cpu, cpu->bx);                    /* push bx */
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->cx = (uint16_t)(flags_sub16(cpu, 0, cpu->cx)); /* neg cx */
    cpu->ax = (uint16_t)(flags_sbb(cpu, cpu->ax, cpu->ax, 16)); /* sbb ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F183(cpu);                           /* call 0x0285 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _r = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC)) | 0x200; flags_logic16(cpu, _r); mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC), (uint16_t)(_r)); } /* or word ds:[bx+0x38CC], 0x200 */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
L_fn_0EEFE_0000B3:;
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
    goto L_fn_0EEFE_0000B9;                  /* jmp 0x00B9 */
L_fn_0EEFE_0000B9:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0EFBD(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0EFBD");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ah = (uint8_t)(0x3F);               /* mov ah, 0x3F */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov cx, word ss:[bp+0xA] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x6) + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ss:[bp+0x6] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    if (cc_b(cpu)) goto L_fn_0EFBD_000016;   /* jb 0x0016 */
    goto L_fn_0EFBD_00001C;                  /* jmp 0x001C */
L_fn_0EFBD_000016:;
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E5EB(cpu);                           /* call 0xF62E */
    goto L_fn_0EFBD_00001C;                  /* jmp 0x001C */
L_fn_0EFBD_00001C:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0EFDB(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0EFDB");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x8E)); /* sub sp, 0x8E */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    flags_cmp16(cpu, cpu->ax, 0x2);          /* cmp ax, 0x2 */
    if (cc_ae(cpu)) goto L_fn_0EFDB_000017;  /* jae 0x0017 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0EFDB_00015A;                  /* jmp 0x015A */
L_fn_0EFDB_000017:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    flags_logic16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC)) & 0x8000); /* test word ds:[bx+0x38CC], 0x8000 */
    if (cc_e(cpu)) goto L_fn_0EFDB_000039;   /* je 0x0039 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F13B(cpu);                           /* call 0x0160 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    goto L_fn_0EFDB_00015A;                  /* jmp 0x015A */
L_fn_0EFDB_000039:;
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _r = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC)) & 0xFDFF; flags_logic16(cpu, _r); mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC), (uint16_t)(_r)); } /* and word ds:[bx+0x38CC], 0xFDFF */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x6) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x6] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x84), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x84], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x86), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x86], bx */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8A), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8A], ax */
    cpu->bx = (uint16_t)(cpu->ss);           /* mov bx, ss */
    cpu->es = (uint16_t)(cpu->bx);           /* mov es, bx */
    cpu->bx = (uint16_t)((uint16_t)(cpu->bp - 0x82)); /* lea bx, word ss:[bp+-0x82] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8C), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x8C], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8E), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x8E], bx */
    goto L_fn_0EFDB_000108;                  /* jmp 0x0108 */
L_fn_0EFDB_000069:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8A), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8A)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ss:[bp+-0x8A] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x86)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x86) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x86] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x86), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x86)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x86] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->bx)); /* mov al, byte es:[bx] */
    mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x87), (uint8_t)(cpu->al)); /* mov byte ss:[bp+-0x87], al */
    flags_cmp8(cpu, cpu->al, 0xA);           /* cmp al, 0xA */
    if (cc_ne(cpu)) goto L_fn_0EFDB_00008C;  /* jne 0x008C */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8E)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8E) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8E] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(0xD)); /* mov byte es:[bx], 0xD */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8E), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8E)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x8E] */
L_fn_0EFDB_00008C:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x87))); /* mov al, byte ss:[bp+-0x87] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8E)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8E) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8E] */
    mem_write8(cpu, cpu->es, cpu->bx, (uint8_t)(cpu->al)); /* mov byte es:[bx], al */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8E), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8E)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ss:[bp+-0x8E] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8E))); /* mov ax, word ss:[bp+-0x8E] */
    cpu->cx = (uint16_t)(cpu->ss);           /* mov cx, ss */
    cpu->bx = (uint16_t)((uint16_t)(cpu->bp - 0x82)); /* lea bx, word ss:[bp+-0x82] */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
    cpu->dx = (uint16_t)(flags_sbb(cpu, cpu->dx, 0x0, 16)); /* sbb dx, 0x0 */
    { uint16_t _r = cpu->dx | cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* or dx, dx */
    if (cc_l(cpu)) goto L_fn_0EFDB_000108;   /* jl 0x0108 */
    if (cc_ne(cpu)) goto L_fn_0EFDB_0000B7;  /* jne 0x00B7 */
    flags_cmp16(cpu, cpu->ax, 0x80);         /* cmp ax, 0x80 */
    if (cc_b(cpu)) goto L_fn_0EFDB_000108;   /* jb 0x0108 */
L_fn_0EFDB_0000B7:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8E))); /* mov ax, word ss:[bp+-0x8E] */
    cpu->cx = (uint16_t)(cpu->ss);           /* mov cx, ss */
    cpu->bx = (uint16_t)((uint16_t)(cpu->bp - 0x82)); /* lea bx, word ss:[bp+-0x82] */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
    cpu->dx = (uint16_t)(flags_sbb(cpu, cpu->dx, 0x0, 16)); /* sbb dx, 0x0 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x82)); /* lea ax, word ss:[bp+-0x82] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F13B(cpu);                           /* call 0x0160 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    flags_cmp16(cpu, cpu->ax, cpu->si);      /* cmp ax, si */
    if (cc_e(cpu)) goto L_fn_0EFDB_0000F8;   /* je 0x00F8 */
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    if (cc_ae(cpu)) goto L_fn_0EFDB_0000EB;  /* jae 0x00EB */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_0EFDB_0000F6;                  /* jmp 0x00F6 */
L_fn_0EFDB_0000EB:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8A)))); /* sub ax, word ss:[bp+-0x8A] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->di)); /* add ax, di */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->si)); /* sub ax, si */
L_fn_0EFDB_0000F6:;
    goto L_fn_0EFDB_00015A;                  /* jmp 0x015A */
L_fn_0EFDB_0000F8:;
    cpu->bx = (uint16_t)(cpu->ss);           /* mov bx, ss */
    cpu->es = (uint16_t)(cpu->bx);           /* mov es, bx */
    cpu->bx = (uint16_t)((uint16_t)(cpu->bp - 0x82)); /* lea bx, word ss:[bp+-0x82] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8C), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x8C], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8E), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x8E], bx */
L_fn_0EFDB_000108:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8A)), 0x0); /* cmp word ss:[bp+-0x8A], 0x0 */
    if (cc_e(cpu)) goto L_fn_0EFDB_000112;   /* je 0x0112 */
    RECOMP_TICK(cpu);
    goto L_fn_0EFDB_000069;                  /* jmp 0x0069 */
L_fn_0EFDB_000112:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8E))); /* mov ax, word ss:[bp+-0x8E] */
    cpu->cx = (uint16_t)(cpu->ss);           /* mov cx, ss */
    cpu->bx = (uint16_t)((uint16_t)(cpu->bp - 0x82)); /* lea bx, word ss:[bp+-0x82] */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->bx)); /* sub ax, bx */
    cpu->dx = (uint16_t)(flags_sbb(cpu, cpu->dx, 0x0, 16)); /* sbb dx, 0x0 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_be(cpu)) goto L_fn_0EFDB_000155;  /* jbe 0x0155 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->ss);                    /* push ss */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp - 0x82)); /* lea ax, word ss:[bp+-0x82] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F13B(cpu);                           /* call 0x0160 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    flags_cmp16(cpu, cpu->ax, cpu->si);      /* cmp ax, si */
    if (cc_e(cpu)) goto L_fn_0EFDB_000155;   /* je 0x0155 */
    { uint16_t _r = cpu->di | cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, di */
    if (cc_ae(cpu)) goto L_fn_0EFDB_00014C;  /* jae 0x014C */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_0EFDB_000153;                  /* jmp 0x0153 */
L_fn_0EFDB_00014C:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->di)); /* add ax, di */
    cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, cpu->si)); /* sub ax, si */
L_fn_0EFDB_000153:;
    goto L_fn_0EFDB_00015A;                  /* jmp 0x015A */
L_fn_0EFDB_000155:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    goto L_fn_0EFDB_00015A;                  /* jmp 0x015A */
L_fn_0EFDB_00015A:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F13B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F13B");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    flags_logic16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC)) & 0x800); /* test word ds:[bx+0x38CC], 0x800 */
    if (cc_e(cpu)) goto L_fn_0F13B_000020;   /* je 0x0020 */
    cpu->ax = (uint16_t)(0x2);               /* mov ax, 0x2 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F183(cpu);                           /* call 0x0048 */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
L_fn_0F13B_000020:;
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ah = (uint8_t)(0x40);               /* mov ah, 0x40 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov cx, word ss:[bp+0xA] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x6) + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ss:[bp+0x6] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    if (cc_b(cpu)) goto L_fn_0F13B_000040;   /* jb 0x0040 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _r = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC)) | 0x1000; flags_logic16(cpu, _r); mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC), (uint16_t)(_r)); } /* or word ds:[bx+0x38CC], 0x1000 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    goto L_fn_0F13B_000046;                  /* jmp 0x0046 */
L_fn_0F13B_000040:;
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E5EB(cpu);                           /* call 0xF4B0 */
    goto L_fn_0F13B_000046;                  /* jmp 0x0046 */
L_fn_0F13B_000046:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F183(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F183");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    { uint16_t _r = mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC)) & 0xFDFF; flags_logic16(cpu, _r); mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x38CC), (uint16_t)(_r)); } /* and word ds:[bx+0x38CC], 0xFDFF */
    cpu->ah = (uint8_t)(0x42);               /* mov ah, 0x42 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov al, byte ss:[bp+0xA] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov cx, word ss:[bp+0x8] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    dos_int21(cpu);                          /* int 0x21 */
    if (cc_b(cpu)) goto L_fn_0F183_000022;   /* jb 0x0022 */
    goto L_fn_0F183_000029;                  /* jmp 0x0029 */
L_fn_0F183_000022:;
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E5EB(cpu);                           /* call 0xF468 */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    goto L_fn_0F183_000029;                  /* jmp 0x0029 */
L_fn_0F183_000029:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F1AE(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F1AE");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x22)); /* sub sp, 0x22 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->es);                    /* push es */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0xA) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ss:[bp+0xA] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    flags_cmp16(cpu, cpu->bx, 0x24);         /* cmp bx, 0x24 */
    if (cc_a(cpu)) goto L_fn_0F1AE_000070;   /* ja 0x0070 */
    flags_cmp8(cpu, cpu->bl, 0x2);           /* cmp bl, 0x2 */
    if (cc_b(cpu)) goto L_fn_0F1AE_000070;   /* jb 0x0070 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov ax, word ss:[bp+0xE] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x10))); /* mov cx, word ss:[bp+0x10] */
    { uint16_t _r = cpu->cx | cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* or cx, cx */
    if (cc_ge(cpu)) goto L_fn_0F1AE_000035;  /* jge 0x0035 */
    flags_cmp8(cpu, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)), 0x0); /* cmp byte ss:[bp+0x6], 0x0 */
    if (cc_e(cpu)) goto L_fn_0F1AE_000035;   /* je 0x0035 */
    mem_write8(cpu, cpu->es, cpu->di, (uint8_t)(0x2D)); /* mov byte es:[di], 0x2D */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
    cpu->cx = (uint16_t)(flags_sub16(cpu, 0, cpu->cx)); /* neg cx */
    cpu->ax = (uint16_t)(flags_sub16(cpu, 0, cpu->ax)); /* neg ax */
    cpu->cx = (uint16_t)(flags_sbb(cpu, cpu->cx, 0x0, 16)); /* sbb cx, 0x0 */
L_fn_0F1AE_000035:;
    cpu->si = (uint16_t)((uint16_t)(cpu->bp - 0x22)); /* lea si, word ss:[bp+-0x22] */
    if (cpu->cx == 0) goto L_fn_0F1AE_00004A; /* jcxz 0x004A */
L_fn_0F1AE_00003A:;
    { uint16_t _t = cpu->ax; cpu->ax = (uint16_t)(cpu->cx); cpu->cx = (uint16_t)(_t); } /* xchg ax, cx */
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, cpu->dx)); /* sub dx, dx */
    { uint32_t _n = ((uint32_t)cpu->dx << 16) | cpu->ax; uint16_t _d = cpu->bx; if (_d && _n / _d <= 0xFFFFu) { cpu->ax = (uint16_t)(_n / _d); cpu->dx = (uint16_t)(_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x003D; recomp_div0("div16"); } } /* div bx */
    { uint16_t _t = cpu->ax; cpu->ax = (uint16_t)(cpu->cx); cpu->cx = (uint16_t)(_t); } /* xchg ax, cx */
    { uint32_t _n = ((uint32_t)cpu->dx << 16) | cpu->ax; uint16_t _d = cpu->bx; if (_d && _n / _d <= 0xFFFFu) { cpu->ax = (uint16_t)(_n / _d); cpu->dx = (uint16_t)(_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0040; recomp_div0("div16"); } } /* div bx */
    mem_write8(cpu, cpu->ss, cpu->si, (uint8_t)(cpu->dl)); /* mov byte ss:[si], dl */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    if (cpu->cx == 0) goto L_fn_0F1AE_000052; /* jcxz 0x0052 */
    RECOMP_TICK(cpu);
    goto L_fn_0F1AE_00003A;                  /* jmp 0x003A */
L_fn_0F1AE_00004A:;
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, cpu->dx)); /* sub dx, dx */
    { uint32_t _n = ((uint32_t)cpu->dx << 16) | cpu->ax; uint16_t _d = cpu->bx; if (_d && _n / _d <= 0xFFFFu) { cpu->ax = (uint16_t)(_n / _d); cpu->dx = (uint16_t)(_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x004C; recomp_div0("div16"); } } /* div bx */
    mem_write8(cpu, cpu->ss, cpu->si, (uint8_t)(cpu->dl)); /* mov byte ss:[si], dl */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0F1AE_000052:;
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_0F1AE_00004A;  /* jne 0x004A */
    cpu->cx = (uint16_t)((uint16_t)(cpu->bp - 0x22)); /* lea cx, word ss:[bp+-0x22] */
    cpu->cx = (uint16_t)(flags_sub16(cpu, 0, cpu->cx)); /* neg cx */
    cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, cpu->si)); /* add cx, si */
    cpu->flags &= ~FLAG_DF;                  /* cld */
L_fn_0F1AE_00005E:;
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, cpu->si)); /* mov al, byte ss:[si] */
    cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, 0xA)); /* sub al, 0xA */
    if (cc_ae(cpu)) goto L_fn_0F1AE_00006A;  /* jae 0x006A */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0x3A)); /* add al, 0x3A */
    goto L_fn_0F1AE_00006D;                  /* jmp 0x006D */
L_fn_0F1AE_00006A:;
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)))); /* add al, byte ss:[bp+0x4] */
L_fn_0F1AE_00006D:;
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0F1AE_00005E; /* loop 0x005E */
L_fn_0F1AE_000070:;
    cpu->al = (uint8_t)(0x0);                /* mov al, 0x0 */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov dx, word ss:[bp+0xC] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    goto L_fn_0F1AE_00007C;                  /* jmp 0x007C */
L_fn_0F1AE_00007C:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 0x10; return;                 /* ret 0xE */
}

void fn_0F232(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F232");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA)), 0xA); /* cmp word ss:[bp+0xA], 0xA */
    if (cc_ne(cpu)) goto L_fn_0F232_00000F;  /* jne 0x000F */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->dx = (cpu->ax & 0x8000) ? 0xFFFF : 0x0000; /* cwd */
    goto L_fn_0F232_000014;                  /* jmp 0x0014 */
L_fn_0F232_00000F:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
L_fn_0F232_000014:;
    push16(cpu, cpu->dx);                    /* push dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    cpu->al = (uint8_t)(0x1);                /* mov al, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(0x61);               /* mov al, 0x61 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F1AE(cpu);                           /* call 0xFF7C */
    goto L_fn_0F232_00002A;                  /* jmp 0x002A */
L_fn_0F232_00002A:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F25E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F25E");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* push word ss:[bp+0xC] */
    cpu->al = (uint8_t)(0x0);                /* mov al, 0x0 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(0x61);               /* mov al, 0x61 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F1AE(cpu);                           /* call 0xFF50 */
    goto L_fn_0F25E_00001D;                  /* jmp 0x001D */
L_fn_0F25E_00001D:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F27D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F27D");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* push word ss:[bp+0xC] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC)), 0xA); /* cmp word ss:[bp+0xC], 0xA */
    if (cc_ne(cpu)) goto L_fn_0F27D_00001D;  /* jne 0x001D */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_0F27D_00001F;                  /* jmp 0x001F */
L_fn_0F27D_00001D:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_0F27D_00001F:;
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->al = (uint8_t)(0x61);               /* mov al, 0x61 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F1AE(cpu);                           /* call 0xFF31 */
    goto L_fn_0F27D_000028;                  /* jmp 0x0028 */
L_fn_0F27D_000028:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F2A7(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F2A7");
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _t = cpu->ax; cpu->ax = (uint16_t)(cpu->si); cpu->si = (uint16_t)(_t); } /* xchg ax, si */
    { uint16_t _t = cpu->ax; cpu->ax = (uint16_t)(cpu->dx); cpu->dx = (uint16_t)(_t); } /* xchg ax, dx */
    flags_logic16(cpu, cpu->ax & cpu->ax);   /* test ax, ax */
    if (cc_e(cpu)) goto L_fn_0F2A7_000009;   /* je 0x0009 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->bx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul bx */
L_fn_0F2A7_000009:;
    { uint16_t _t = cpu->ax; cpu->ax = (uint16_t)(cpu->cx); cpu->cx = (uint16_t)(_t); } /* xchg ax, cx */
    flags_logic16(cpu, cpu->ax & cpu->ax);   /* test ax, ax */
    if (cc_e(cpu)) goto L_fn_0F2A7_000012;   /* je 0x0012 */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->si; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul si */
    cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, cpu->ax)); /* add cx, ax */
L_fn_0F2A7_000012:;
    { uint16_t _t = cpu->ax; cpu->ax = (uint16_t)(cpu->si); cpu->si = (uint16_t)(_t); } /* xchg ax, si */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->bx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul bx */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->cx)); /* add dx, cx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    { uint16_t _ip=pop16(cpu); uint16_t _cs=pop16(cpu); if (_ip != 0xFFFF && _ip != 0) recomp_dispatch(cpu,_cs,_ip); return; } /* retf */
}

void fn_0F2C0(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F2C0");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ss:[bp+0x4] */
    { uint8_t _r = cpu->al ^ cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* xor al, al */
    cpu->cx = (uint16_t)(0xFFFF);            /* mov cx, 0xFFFF */
    while (cpu->cx != 0) { cpu->cx--;        /* repnz scasb */
        flags_cmp8(cpu, cpu->al, mem_read8(cpu, cpu->es, cpu->di)); cpu->di += df(cpu) ? -1 : 1; /* scasb */
        if (zf(cpu)) break;
    }
    cpu->ax = (uint16_t)(cpu->cx);           /* mov ax, cx */
    cpu->ax = (uint16_t)(~cpu->ax);          /* not ax */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    goto L_fn_0F2C0_000017;                  /* jmp 0x0017 */
L_fn_0F2C0_000017:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F2DB(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F2DB");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ss:[bp+0x8] */
    cpu->si = (uint16_t)(cpu->di);           /* mov si, di */
    { uint8_t _r = cpu->al ^ cpu->al; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* xor al, al */
    cpu->cx = (uint16_t)(0xFFFF);            /* mov cx, 0xFFFF */
    while (cpu->cx != 0) { cpu->cx--;        /* repnz scasb */
        flags_cmp8(cpu, cpu->al, mem_read8(cpu, cpu->es, cpu->di)); cpu->di += df(cpu) ? -1 : 1; /* scasb */
        if (zf(cpu)) break;
    }
    cpu->cx = (uint16_t)(~cpu->cx);          /* not cx */
    push16(cpu, cpu->ds);                    /* push ds */
    push16(cpu, cpu->es);                    /* push es */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ss:[bp+0x4] */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    goto L_fn_0F2DB_000025;                  /* jmp 0x0025 */
L_fn_0F2DB_000025:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F304(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F304");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ss:[bp+0x4] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov cx, word ss:[bp+0x8] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov al, byte ss:[bp+0xA] */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    flags_logic16(cpu, cpu->di & 0x1);       /* test di, 0x1 */
    if (cc_e(cpu)) goto L_fn_0F304_00001B;   /* je 0x001B */
    if (cpu->cx == 0) goto L_fn_0F304_000022; /* jcxz 0x0022 */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec cx */
L_fn_0F304_00001B:;
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    while (cpu->cx != 0) { cpu->cx--;        /* rep stosw */
        mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    }
    if (cc_ae(cpu)) goto L_fn_0F304_000022;  /* jae 0x0022 */
    mem_write8(cpu, cpu->es, cpu->di, cpu->al); cpu->di += df(cpu) ? -1 : 1; /* stosb */
L_fn_0F304_000022:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F32A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F32A");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F304(cpu);                           /* call 0xFFDA */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    goto L_fn_0F32A_00001C;                  /* jmp 0x001C */
L_fn_0F32A_00001C:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F348(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F348");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov cx, word ss:[bp+0xA] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC6A(cpu);                           /* call 0000:EC6A */
    if (cc_ae(cpu)) goto L_fn_0F348_00001F;  /* jae 0x001F */
    cpu->flags |= FLAG_DF;                   /* std */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    goto L_fn_0F348_000022;                  /* jmp 0x0022 */
L_fn_0F348_00001F:;
    cpu->flags &= ~FLAG_DF;                  /* cld */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
L_fn_0F348_000022:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ss:[bp+0x8] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov cx, word ss:[bp+0xC] */
    { uint16_t _r = cpu->ax | cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, ax */
    if (cc_e(cpu)) goto L_fn_0F348_000035;   /* je 0x0035 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->cx)); /* add si, cx */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec si */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->cx)); /* add di, cx */
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec di */
L_fn_0F348_000035:;
    flags_logic16(cpu, cpu->di & 0x1);       /* test di, 0x1 */
    if (cc_e(cpu)) goto L_fn_0F348_00003F;   /* je 0x003F */
    if (cpu->cx == 0) goto L_fn_0F348_00004E; /* jcxz 0x004E */
    mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    { int _cf = cf(cpu); cpu->cx = (uint16_t)(flags_sub16(cpu, cpu->cx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec cx */
L_fn_0F348_00003F:;
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->ax)); /* sub si, ax */
    cpu->di = (uint16_t)(flags_sub16(cpu, cpu->di, cpu->ax)); /* sub di, ax */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsw */
        mem_write16(cpu, cpu->es, cpu->di, mem_read16(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -2 : 2; cpu->di += df(cpu) ? -2 : 2; /* movsw */
    }
    if (cc_ae(cpu)) goto L_fn_0F348_00004E;  /* jae 0x004E */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, cpu->ax)); /* add si, ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
    mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
L_fn_0F348_00004E:;
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F39C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F39C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* push word ss:[bp+0xC] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F348(cpu);                           /* call 0xFFAC */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F3BB(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F3BB");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ah = (uint8_t)(0x43);               /* mov ah, 0x43 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov al, byte ss:[bp+0x8] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov cx, word ss:[bp+0xA] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ss:[bp+0x4] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    if (cc_b(cpu)) goto L_fn_0F3BB_000017;   /* jb 0x0017 */
    { uint16_t _t = cpu->ax; cpu->ax = (uint16_t)(cpu->cx); cpu->cx = (uint16_t)(_t); } /* xchg ax, cx */
    goto L_fn_0F3BB_00001D;                  /* jmp 0x001D */
L_fn_0F3BB_000017:;
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E5EB(cpu);                           /* call 0xF230 */
    goto L_fn_0F3BB_00001D;                  /* jmp 0x001D */
L_fn_0F3BB_00001D:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F3DA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F3DA");
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x91)); /* mov dx, word ds:[0x91] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x8F)); /* mov ax, word ds:[0x8F] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x8D)); /* mov cx, word ds:[0x8D] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x8B)); /* mov bx, word ds:[0x8B] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F8D9(cpu);                           /* call 0000:F8D9 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFF8)); /* add ax, 0xFFF8 */
    cpu->dx = (uint16_t)(flags_adc(cpu, cpu->dx, 0xFFFF, 16)); /* adc dx, 0xFFFF */
    goto L_fn_0F3DA_00001C;                  /* jmp 0x001C */
L_fn_0F3DA_00001C:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F3F7(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F3F7");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F6C3(cpu);                           /* call 0x02CC */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}
