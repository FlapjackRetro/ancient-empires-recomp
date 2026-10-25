#include "recomp_all.h"

void fn_0C1F7(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C1F7");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1784), 0x2); /* cmp word ds:[0x1784], 0x2 */
    if (cc_e(cpu)) goto L_fn_0C1F7_00000D;   /* je 0x000D */
L_fn_0C1F7_00000A:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C232(cpu);                           /* call 0x003B */
L_fn_0C1F7_00000D:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C27D(cpu);                           /* call 0x0086 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1784), 0x0); /* cmp word ds:[0x1784], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0C1F7_000039;  /* jne 0x0039 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1776)); /* mov ax, word ds:[0x1776] */
    flags_cmp16(cpu, cpu->ax, 0x0);          /* cmp ax, 0x0 */
    if (cc_e(cpu)) goto L_fn_0C1F7_000039;   /* je 0x0039 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1794)); /* mov ax, word ds:[0x1794] */
    mem_write16(cpu, cpu->ds, 0x178C, (uint16_t)(cpu->ax)); /* mov word ds:[0x178C], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1796)); /* mov ax, word ds:[0x1796] */
    mem_write16(cpu, cpu->ds, 0x178E, (uint16_t)(cpu->ax)); /* mov word ds:[0x178E], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1798)); /* mov ax, word ds:[0x1798] */
    mem_write16(cpu, cpu->ds, 0x1790, (uint16_t)(cpu->ax)); /* mov word ds:[0x1790], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x179A)); /* mov ax, word ds:[0x179A] */
    mem_write16(cpu, cpu->ds, 0x1792, (uint16_t)(cpu->ax)); /* mov word ds:[0x1792], ax */
    RECOMP_TICK(cpu);
    goto L_fn_0C1F7_00000A;                  /* jmp 0x000A */
L_fn_0C1F7_000039:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C232(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C232");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    cpu->bx = (uint16_t)(0x2);               /* mov bx, 0x2 */
    cpu->dx = (uint16_t)(0x6);               /* mov dx, 0x6 */
    mem_write16(cpu, cpu->ds, 0x1784, (uint16_t)(cpu->bx)); /* mov word ds:[0x1784], bx */
    mem_write16(cpu, cpu->ds, 0x178A, (uint16_t)(cpu->ax)); /* mov word ds:[0x178A], ax */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x177A)); /* mov cx, word ds:[0x177A] */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
L_fn_0C232_000018:;
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17AC), (uint16_t)(cpu->ax)); /* mov word ds:[si+0x17AC], ax */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x178C))); /* mov di, word ds:[si+0x178C] */
    flags_cmp8(cpu, mem_read8(cpu, cpu->es, cpu->di), 0xFF); /* cmp byte es:[di], 0xFF */
    if (cc_e(cpu)) goto L_fn_0C232_000044;   /* je 0x0044 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17AC), (uint16_t)(cpu->bx)); /* mov word ds:[si+0x17AC], bx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x179C), (uint16_t)(cpu->ax)); /* mov word ds:[si+0x179C], ax */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17A4), (uint16_t)(0x1)); /* mov word ds:[si+0x17A4], 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17B4), (uint16_t)(cpu->ax)); /* mov word ds:[si+0x17B4], ax */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17EC), (uint16_t)(cpu->ax)); /* mov word ds:[si+0x17EC], ax */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17F4), (uint16_t)(cpu->ax)); /* mov word ds:[si+0x17F4], ax */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17BC), (uint16_t)(cpu->dx)); /* mov word ds:[si+0x17BC], dx */
L_fn_0C232_000044:;
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x2)); /* add si, 0x2 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0C232_000018; /* loop 0x0018 */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C27D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C27D");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
L_fn_0C27D_000005:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17AC)), 0x0); /* cmp word ds:[si+0x17AC], 0x0 */
    if (cc_e(cpu)) goto L_fn_0C27D_00003D;   /* je 0x003D */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x179C)), 0x0); /* cmp word ds:[si+0x179C], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0C27D_00001D;  /* jne 0x001D */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C2EA(cpu);                           /* call 0x006D */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17AC)), 0x0); /* cmp word ds:[si+0x17AC], 0x0 */
    if (cc_e(cpu)) goto L_fn_0C27D_00003D;   /* je 0x003D */
L_fn_0C27D_00001D:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x179C), (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x179C)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ds:[si+0x179C] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x1); /* cmp word ds:[0x1778], 0x1 */
    if (cc_e(cpu)) goto L_fn_0C27D_00003D;   /* je 0x003D */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17B4)), 0x1); /* cmp word ds:[si+0x17B4], 0x1 */
    if (cc_e(cpu)) goto L_fn_0C27D_00003D;   /* je 0x003D */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17BC))); /* mov ax, word ds:[si+0x17BC] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x179C)), cpu->ax); /* cmp word ds:[si+0x179C], ax */
    if (cc_ne(cpu)) goto L_fn_0C27D_00003D;  /* jne 0x003D */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C6B9(cpu);                           /* call 0x043C */
L_fn_0C27D_00003D:;
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x2)); /* add si, 0x2 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x177A)); /* cmp ax, word ds:[0x177A] */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0C27D_000005;   /* jl 0x0005 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x17AC)); /* mov ax, word ds:[0x17AC] */
    { uint16_t _r = cpu->ax | mem_read16(cpu, cpu->ds, 0x17AE); flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, word ds:[0x17AE] */
    { uint16_t _r = cpu->ax | mem_read16(cpu, cpu->ds, 0x17B0); flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, word ds:[0x17B0] */
    { uint16_t _r = cpu->ax | mem_read16(cpu, cpu->ds, 0x17B2); flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, word ds:[0x17B2] */
    if (cc_ne(cpu)) goto L_fn_0C27D_000061;  /* jne 0x0061 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C755(cpu);                           /* call 0x04D8 */
    goto L_fn_0C27D_00006B;                  /* jmp 0x006B */
    /* nop */                                /* nop */
L_fn_0C27D_000061:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x1); /* cmp word ds:[0x1778], 0x1 */
    if (cc_ne(cpu)) goto L_fn_0C27D_00006B;  /* jne 0x006B */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C440(cpu);                           /* call 0x01C3 */
L_fn_0C27D_00006B:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C2EA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C2EA");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
L_fn_0C2EA_000003:;
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x178C))); /* mov di, word ds:[si+0x178C] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->di)); /* mov al, byte es:[di] */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _r = cpu->al & 0xF; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0xF */
    flags_cmp8(cpu, cpu->al, 0x0);           /* cmp al, 0x0 */
    if (cc_e(cpu)) goto L_fn_0C2EA_000035;   /* je 0x0035 */
    flags_cmp8(cpu, cpu->al, 0xD);           /* cmp al, 0xD */
    if (cc_e(cpu)) goto L_fn_0C2EA_000044;   /* je 0x0044 */
    flags_cmp8(cpu, cpu->al, 0xE);           /* cmp al, 0xE */
    if (cc_e(cpu)) goto L_fn_0C2EA_00004F;   /* je 0x004F */
    flags_cmp8(cpu, cpu->al, 0xF);           /* cmp al, 0xF */
    if (cc_e(cpu)) goto L_fn_0C2EA_000055;   /* je 0x0055 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C359(cpu);                           /* call 0x006F */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C3DB(cpu);                           /* call 0x00F1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17EC), (uint16_t)(0x0)); /* mov word ds:[si+0x17EC], 0x0 */
    goto L_fn_0C2EA_000061;                  /* jmp 0x0061 */
    /* nop */                                /* nop */
L_fn_0C2EA_000035:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C6B9(cpu);                           /* call 0x03CF */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C3DB(cpu);                           /* call 0x00F1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17EC), (uint16_t)(0x1)); /* mov word ds:[si+0x17EC], 0x1 */
    goto L_fn_0C2EA_000061;                  /* jmp 0x0061 */
    /* nop */                                /* nop */
L_fn_0C2EA_000044:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C501(cpu);                           /* call 0x0217 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x179C)), 0x0); /* cmp word ds:[si+0x179C], 0x0 */
    goto L_fn_0C2EA_000061;                  /* jmp 0x0061 */
    /* nop */                                /* nop */
L_fn_0C2EA_00004F:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C5D1(cpu);                           /* call 0x02E7 */
    goto L_fn_0C2EA_000061;                  /* jmp 0x0061 */
    /* nop */                                /* nop */
L_fn_0C2EA_000055:;
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17AC), (uint16_t)(0x0)); /* mov word ds:[si+0x17AC], 0x0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C6B9(cpu);                           /* call 0x03CF */
    goto L_fn_0C2EA_00006D;                  /* jmp 0x006D */
    /* nop */                                /* nop */
L_fn_0C2EA_000061:;
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x178C), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x178C)), 0x2))); /* add word ds:[si+0x178C], 0x2 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x179C)), 0x0); /* cmp word ds:[si+0x179C], 0x0 */
    RECOMP_TICK(cpu);
    if (cc_e(cpu)) goto L_fn_0C2EA_000003;   /* je 0x0003 */
L_fn_0C2EA_00006D:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C359(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C359");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x1); /* cmp word ds:[0x1778], 0x1 */
    if (cc_e(cpu)) goto L_fn_0C359_000048;   /* je 0x0048 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x2); /* cmp word ds:[0x1778], 0x2 */
    if (cc_e(cpu)) goto L_fn_0C359_00002B;   /* je 0x002B */
    cpu->cl = (uint8_t)(cpu->ah);            /* mov cl, ah */
    cpu->bx = (uint16_t)(0x17FC);            /* mov bx, 0x17FC */
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec al */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, cpu->bx)); /* mov ax, word ds:[bx] */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, cl */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C706(cpu);                           /* call 0x03AD */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C678(cpu);                           /* call 0x031F */
    goto L_fn_0C359_000080;                  /* jmp 0x0080 */
    /* nop */                                /* nop */
L_fn_0C359_00002B:;
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec al */
    { uint16_t _r = cpu->cx ^ cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* xor cx, cx */
    cpu->cl = (uint8_t)(cpu->ah);            /* mov cl, ah */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shl cx, 0x1 */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shl cx, 0x1 */
    cpu->bx = (uint16_t)(cpu->cx);           /* mov bx, cx */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shl cx, 0x1 */
    cpu->cx = (uint16_t)(flags_add16(cpu, cpu->cx, cpu->bx)); /* add cx, bx */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, cpu->cl)); /* add al, cl */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C706(cpu);                           /* call 0x03AD */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C678(cpu);                           /* call 0x031F */
    goto L_fn_0C359_000080;                  /* jmp 0x0080 */
    /* nop */                                /* nop */
L_fn_0C359_000048:;
    flags_cmp16(cpu, cpu->si, 0x6);          /* cmp si, 0x6 */
    if (cc_e(cpu)) goto L_fn_0C359_000072;   /* je 0x0072 */
    flags_cmp8(cpu, cpu->ah, 0x0);           /* cmp ah, 0x0 */
    if (cc_e(cpu)) goto L_fn_0C359_000054;   /* je 0x0054 */
    { int _cf = cf(cpu); cpu->ah = (uint8_t)(flags_sub8(cpu, cpu->ah, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ah */
L_fn_0C359_000054:;
    cpu->cl = (uint8_t)(cpu->ah);            /* mov cl, ah */
    cpu->bx = (uint16_t)(0x1814);            /* mov bx, 0x1814 */
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec al */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, cpu->bx)); /* mov ax, word ds:[bx] */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, cl */
    flags_cmp16(cpu, cpu->ax, 0x3FF);        /* cmp ax, 0x3FF */
    if (cc_le(cpu)) goto L_fn_0C359_00006C;  /* jle 0x006C */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
L_fn_0C359_00006C:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C706(cpu);                           /* call 0x03AD */
    goto L_fn_0C359_000080;                  /* jmp 0x0080 */
    /* nop */                                /* nop */
L_fn_0C359_000072:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x177C)), 0x0); /* cmp word ds:[si+0x177C], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0C359_000080;  /* jne 0x0080 */
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec al */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0xE0)); /* add al, 0xE0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C8D4(cpu);                           /* call 0x057B */
L_fn_0C359_000080:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C3DB(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C3DB");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->di + 0x1))); /* mov al, byte es:[di+0x1] */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1788)); /* mov bx, word ds:[0x1788] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ds, 0x178A))); /* add bx, word ds:[0x178A] */
    flags_logic8(cpu, cpu->ah & 0x80);       /* test ah, 0x80 */
    if (cc_e(cpu)) goto L_fn_0C3DB_00001A;   /* je 0x001A */
    { uint8_t _r = cpu->al & 0x7F; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0x7F */
    goto L_fn_0C3DB_000059;                  /* jmp 0x0059 */
L_fn_0C3DB_00001A:;
    { uint8_t _r = cpu->al & 0x7; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0x7 */
    cpu->cl = (uint8_t)(cpu->al);            /* mov cl, al */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, cl */
    flags_logic8(cpu, cpu->ah & 0x8);        /* test ah, 0x8 */
    if (cc_e(cpu)) goto L_fn_0C3DB_00002B;   /* je 0x002B */
    cpu->dx = (uint16_t)(cpu->bx);           /* mov dx, bx */
    { uint16_t _v = cpu->dx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shr dx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->dx)); /* add bx, dx */
L_fn_0C3DB_00002B:;
    flags_logic8(cpu, cpu->ah & 0x10);       /* test ah, 0x10 */
    if (cc_e(cpu)) goto L_fn_0C3DB_00004E;   /* je 0x004E */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17F4)), 0x3); /* cmp word ds:[si+0x17F4], 0x3 */
    if (cc_e(cpu)) goto L_fn_0C3DB_000059;   /* je 0x0059 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17F4)), 0x1); /* cmp word ds:[si+0x17F4], 0x1 */
    if (cc_e(cpu)) goto L_fn_0C3DB_000045;   /* je 0x0045 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17F4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17F4)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[si+0x17F4] */
    goto L_fn_0C3DB_000059;                  /* jmp 0x0059 */
    /* nop */                                /* nop */
L_fn_0C3DB_000045:;
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17F4), (uint16_t)(0x3)); /* mov word ds:[si+0x17F4], 0x3 */
    goto L_fn_0C3DB_000059;                  /* jmp 0x0059 */
    /* nop */                                /* nop */
L_fn_0C3DB_00004E:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17F4)), 0x0); /* cmp word ds:[si+0x17F4], 0x0 */
    if (cc_e(cpu)) goto L_fn_0C3DB_000059;   /* je 0x0059 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17F4), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17F4)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[si+0x17F4] */
L_fn_0C3DB_000059:;
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x179C), (uint16_t)(cpu->bx)); /* mov word ds:[si+0x179C], bx */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17E4), (uint16_t)(0x1)); /* mov word ds:[si+0x17E4], 0x1 */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C440(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C440");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    cpu->bl = (uint8_t)(0x90);               /* mov bl, 0x90 */
L_fn_0C440_000007:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x177C)), 0x0); /* cmp word ds:[si+0x177C], 0x0 */
    if (cc_e(cpu)) goto L_fn_0C440_000011;   /* je 0x0011 */
    goto L_fn_0C440_0000B1;                  /* jmp 0x00B1 */
L_fn_0C440_000011:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17AC)), 0x0); /* cmp word ds:[si+0x17AC], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0C440_00001B;  /* jne 0x001B */
    goto L_fn_0C440_0000B1;                  /* jmp 0x00B1 */
L_fn_0C440_00001B:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17E4)), 0x1); /* cmp word ds:[si+0x17E4], 0x1 */
    if (cc_ne(cpu)) goto L_fn_0C440_000050;  /* jne 0x0050 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17E4), (uint16_t)(0x0)); /* mov word ds:[si+0x17E4], 0x0 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17F4)), 0x2); /* cmp word ds:[si+0x17F4], 0x2 */
    if (cc_l(cpu)) goto L_fn_0C440_00003F;   /* jl 0x003F */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17F4)), 0x3); /* cmp word ds:[si+0x17F4], 0x3 */
    if (cc_e(cpu)) goto L_fn_0C440_00007B;   /* je 0x007B */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17F4), (uint16_t)(0x0)); /* mov word ds:[si+0x17F4], 0x0 */
    goto L_fn_0C440_00007B;                  /* jmp 0x007B */
    /* nop */                                /* nop */
L_fn_0C440_00003F:;
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17D4), (uint16_t)(0x0)); /* mov word ds:[si+0x17D4], 0x0 */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17C4))); /* mov cx, word ds:[si+0x17C4] */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17CC), (uint16_t)(cpu->cx)); /* mov word ds:[si+0x17CC], cx */
    goto L_fn_0C440_00007B;                  /* jmp 0x007B */
    /* nop */                                /* nop */
L_fn_0C440_000050:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17EC)), 0x1); /* cmp word ds:[si+0x17EC], 0x1 */
    if (cc_ne(cpu)) goto L_fn_0C440_00005C;  /* jne 0x005C */
    cpu->al = (uint8_t)(0xF);                /* mov al, 0xF */
    goto L_fn_0C440_0000AC;                  /* jmp 0x00AC */
    /* nop */                                /* nop */
L_fn_0C440_00005C:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17F4)), 0x1); /* cmp word ds:[si+0x17F4], 0x1 */
    if (cc_e(cpu)) goto L_fn_0C440_00007B;   /* je 0x007B */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17F4)), 0x3); /* cmp word ds:[si+0x17F4], 0x3 */
    if (cc_e(cpu)) goto L_fn_0C440_00007B;   /* je 0x007B */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17B4)), 0x1); /* cmp word ds:[si+0x17B4], 0x1 */
    if (cc_e(cpu)) goto L_fn_0C440_00007B;   /* je 0x007B */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17BC))); /* mov cx, word ds:[si+0x17BC] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x179C)), cpu->cx); /* cmp word ds:[si+0x179C], cx */
    if (cc_le(cpu)) goto L_fn_0C440_000090;  /* jle 0x0090 */
L_fn_0C440_00007B:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17D4)), 0x0); /* cmp word ds:[si+0x17D4], 0x0 */
    if (cc_e(cpu)) goto L_fn_0C440_000095;   /* je 0x0095 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17D4)), 0x1); /* cmp word ds:[si+0x17D4], 0x1 */
    if (cc_g(cpu)) goto L_fn_0C440_000090;   /* jg 0x0090 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17DC))); /* mov ax, word ds:[si+0x17DC] */
    goto L_fn_0C440_0000AC;                  /* jmp 0x00AC */
    /* nop */                                /* nop */
L_fn_0C440_000090:;
    cpu->al = (uint8_t)(0xF);                /* mov al, 0xF */
    goto L_fn_0C440_0000AC;                  /* jmp 0x00AC */
    /* nop */                                /* nop */
L_fn_0C440_000095:;
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17CC))); /* mov di, word ds:[si+0x17CC] */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17CC), (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17CC)), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[si+0x17CC] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ds, cpu->di)); /* mov al, byte ds:[di] */
    flags_cmp8(cpu, cpu->al, 0xFF);          /* cmp al, 0xFF */
    if (cc_ne(cpu)) goto L_fn_0C440_0000AC;  /* jne 0x00AC */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17D4), (uint16_t)(0x1)); /* mov word ds:[si+0x17D4], 0x1 */
    goto L_fn_0C440_0000B1;                  /* jmp 0x00B1 */
    /* nop */                                /* nop */
L_fn_0C440_0000AC:;
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, cpu->bl)); /* add al, bl */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C8D4(cpu);                           /* call 0x0494 */
L_fn_0C440_0000B1:;
    cpu->bl = (uint8_t)(flags_add8(cpu, cpu->bl, 0x20)); /* add bl, 0x20 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x2)); /* add si, 0x2 */
    flags_cmp16(cpu, cpu->si, 0x6);          /* cmp si, 0x6 */
    if (cc_g(cpu)) goto L_fn_0C440_0000BF;   /* jg 0x00BF */
    RECOMP_TICK(cpu);
    goto L_fn_0C440_000007;                  /* jmp 0x0007 */
L_fn_0C440_0000BF:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C501(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C501");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->di + 0x1))); /* mov al, byte es:[di+0x1] */
    flags_cmp8(cpu, cpu->ah, 0x0);           /* cmp ah, 0x0 */
    if (cc_ne(cpu)) goto L_fn_0C501_000012;  /* jne 0x0012 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C549(cpu);                           /* call 0x0048 */
    goto L_fn_0C501_000046;                  /* jmp 0x0046 */
    /* nop */                                /* nop */
L_fn_0C501_000012:;
    flags_cmp8(cpu, cpu->ah, 0x2);           /* cmp ah, 0x2 */
    if (cc_g(cpu)) goto L_fn_0C501_00001D;   /* jg 0x001D */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C567(cpu);                           /* call 0x0066 */
    goto L_fn_0C501_000046;                  /* jmp 0x0046 */
    /* nop */                                /* nop */
L_fn_0C501_00001D:;
    flags_cmp8(cpu, cpu->ah, 0x3);           /* cmp ah, 0x3 */
    if (cc_ne(cpu)) goto L_fn_0C501_000028;  /* jne 0x0028 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C5A8(cpu);                           /* call 0x00A7 */
    goto L_fn_0C501_000046;                  /* jmp 0x0046 */
    /* nop */                                /* nop */
L_fn_0C501_000028:;
    flags_cmp8(cpu, cpu->ah, 0x4);           /* cmp ah, 0x4 */
    if (cc_ne(cpu)) goto L_fn_0C501_000033;  /* jne 0x0033 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C59A(cpu);                           /* call 0x0099 */
    goto L_fn_0C501_000046;                  /* jmp 0x0046 */
    /* nop */                                /* nop */
L_fn_0C501_000033:;
    flags_cmp8(cpu, cpu->ah, 0x5);           /* cmp ah, 0x5 */
    if (cc_ne(cpu)) goto L_fn_0C501_00003E;  /* jne 0x003E */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C5B3(cpu);                           /* call 0x00B2 */
    goto L_fn_0C501_000046;                  /* jmp 0x0046 */
    /* nop */                                /* nop */
L_fn_0C501_00003E:;
    flags_cmp8(cpu, cpu->ah, 0x6);           /* cmp ah, 0x6 */
    if (cc_ne(cpu)) goto L_fn_0C501_000046;  /* jne 0x0046 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C5C6(cpu);                           /* call 0x00C5 */
L_fn_0C501_000046:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C549(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C549");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    flags_cmp8(cpu, cpu->al, 0x0);           /* cmp al, 0x0 */
    if (cc_e(cpu)) goto L_fn_0C549_000016;   /* je 0x0016 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17B4), (uint16_t)(0x0)); /* mov word ds:[si+0x17B4], 0x0 */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17BC), (uint16_t)(cpu->ax)); /* mov word ds:[si+0x17BC], ax */
    goto L_fn_0C549_00001C;                  /* jmp 0x001C */
    /* nop */                                /* nop */
L_fn_0C549_000016:;
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17B4), (uint16_t)(0x1)); /* mov word ds:[si+0x17B4], 0x1 */
L_fn_0C549_00001C:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C567(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C567");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->bl = (uint8_t)(cpu->ah);            /* mov bl, ah */
    cpu->cl = (uint8_t)(cpu->al);            /* mov cl, al */
    { uint8_t _r = cpu->ch ^ cpu->ch; flags_logic8(cpu, _r); cpu->ch = (uint8_t)(_r); } /* xor ch, ch */
    flags_cmp16(cpu, cpu->cx, 0x0);          /* cmp cx, 0x0 */
    if (cc_e(cpu)) goto L_fn_0C567_00002B;   /* je 0x002B */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1788)); /* mov ax, word ds:[0x1788] */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->cx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul cx */
    cpu->cx = (uint16_t)(0x64);              /* mov cx, 0x64 */
    { uint32_t _n = ((uint32_t)cpu->dx << 16) | cpu->ax; uint16_t _d = cpu->cx; if (_d && _n / _d <= 0xFFFFu) { cpu->ax = (uint16_t)(_n / _d); cpu->dx = (uint16_t)(_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0016; recomp_div0("div16"); } } /* div cx */
    flags_cmp16(cpu, cpu->dx, 0x31);         /* cmp dx, 0x31 */
    if (cc_le(cpu)) goto L_fn_0C567_00001E;  /* jle 0x001E */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
L_fn_0C567_00001E:;
    flags_cmp8(cpu, cpu->bl, 0x1);           /* cmp bl, 0x1 */
    if (cc_e(cpu)) goto L_fn_0C567_000025;   /* je 0x0025 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, 0, cpu->ax)); /* neg ax */
L_fn_0C567_000025:;
    mem_write16(cpu, cpu->ds, 0x178A, (uint16_t)(cpu->ax)); /* mov word ds:[0x178A], ax */
    goto L_fn_0C567_000031;                  /* jmp 0x0031 */
    /* nop */                                /* nop */
L_fn_0C567_00002B:;
    mem_write16(cpu, cpu->ds, 0x178A, (uint16_t)(0x0)); /* mov word ds:[0x178A], 0x0 */
L_fn_0C567_000031:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C59A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C59A");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    mem_write16(cpu, cpu->ds, 0x1788, (uint16_t)(cpu->ax)); /* mov word ds:[0x1788], ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C5A8(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C5A8");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17A4), (uint16_t)(cpu->ax)); /* mov word ds:[si+0x17A4], ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C5B3(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C5B3");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->bl = (uint8_t)(cpu->al);            /* mov bl, al */
    { uint8_t _r = cpu->bh ^ cpu->bh; flags_logic8(cpu, _r); cpu->bh = (uint8_t)(_r); } /* xor bh, bh */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x1832))); /* mov bx, word ds:[bx+0x1832] */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17C4), (uint16_t)(cpu->bx)); /* mov word ds:[si+0x17C4], bx */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C5C6(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C5C6");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17DC), (uint16_t)(cpu->ax)); /* mov word ds:[si+0x17DC], ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C5D1(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C5D1");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->dl = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->di + 0x1))); /* mov dl, byte es:[di+0x1] */
    { uint8_t _r = cpu->dh ^ cpu->dh; flags_logic8(cpu, _r); cpu->dh = (uint8_t)(_r); } /* xor dh, dh */
    flags_cmp16(cpu, cpu->dx, 0x0);          /* cmp dx, 0x0 */
    if (cc_ne(cpu)) goto L_fn_0C5D1_00001A;  /* jne 0x001A */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C6B9(cpu);                           /* call 0x00E8 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17EC), (uint16_t)(0x1)); /* mov word ds:[si+0x17EC], 0x1 */
    goto L_fn_0C5D1_00009D;                  /* jmp 0x009D */
L_fn_0C5D1_00001A:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x1); /* cmp word ds:[0x1778], 0x1 */
    if (cc_e(cpu)) goto L_fn_0C5D1_000052;   /* je 0x0052 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x2); /* cmp word ds:[0x1778], 0x2 */
    if (cc_e(cpu)) goto L_fn_0C5D1_000049;   /* je 0x0049 */
    cpu->cl = (uint8_t)(0x7);                /* mov cl, 0x7 */
    { uint16_t _v = cpu->dx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shl dx, cl */
    cpu->dx = (uint16_t)(flags_sub16(cpu, 0, cpu->dx)); /* neg dx */
    cpu->cl = (uint8_t)(cpu->ah);            /* mov cl, ah */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1778)); /* mov bx, word ds:[0x1778] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x182C))); /* mov bx, word ds:[bx+0x182C] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, cpu->bx)); /* mov ax, word ds:[bx] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->dx)); /* add ax, dx */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, cl */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C706(cpu);                           /* call 0x0135 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C678(cpu);                           /* call 0x00A7 */
    goto L_fn_0C5D1_00009D;                  /* jmp 0x009D */
    /* nop */                                /* nop */
L_fn_0C5D1_000049:;
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17E4), (uint16_t)(0x1)); /* mov word ds:[si+0x17E4], 0x1 */
    goto L_fn_0C5D1_00009D;                  /* jmp 0x009D */
    /* nop */                                /* nop */
L_fn_0C5D1_000052:;
    cpu->bx = (uint16_t)(cpu->dx);           /* mov bx, dx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->dx)); /* add bx, dx */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { int _cf = cf(cpu); cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc bx */
    cpu->cl = (uint8_t)(cpu->ah);            /* mov cl, ah */
    flags_cmp8(cpu, cpu->cl, 0x0);           /* cmp cl, 0x0 */
    if (cc_ne(cpu)) goto L_fn_0C5D1_000066;  /* jne 0x0066 */
    { int _cf = cf(cpu); cpu->cl = (uint8_t)(flags_add8(cpu, cpu->cl, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc cl */
L_fn_0C5D1_000066:;
    cpu->dx = (uint16_t)(0xD70);             /* mov dx, 0xD70 */
    { uint16_t _v = cpu->dx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shr dx, cl */
    flags_cmp8(cpu, cpu->cl, 0x4);           /* cmp cl, 0x4 */
    if (cc_e(cpu)) goto L_fn_0C5D1_000082;   /* je 0x0082 */
    if (cc_g(cpu)) goto L_fn_0C5D1_00007D;   /* jg 0x007D */
    cpu->al = (uint8_t)(0x4);                /* mov al, 0x4 */
    cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, cpu->cl)); /* sub al, cl */
    cpu->cl = (uint8_t)(cpu->al);            /* mov cl, al */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, cl */
    goto L_fn_0C5D1_000082;                  /* jmp 0x0082 */
    /* nop */                                /* nop */
L_fn_0C5D1_00007D:;
    cpu->cl = (uint8_t)(flags_sub8(cpu, cpu->cl, 0x4)); /* sub cl, 0x4 */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, cl */
L_fn_0C5D1_000082:;
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, cpu->bx)); /* sub dx, bx */
    flags_cmp16(cpu, cpu->dx, 0x400);        /* cmp dx, 0x400 */
    if (cc_le(cpu)) goto L_fn_0C5D1_00008C;  /* jle 0x008C */
    { uint16_t _v = cpu->dx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shr dx, 0x1 */
L_fn_0C5D1_00008C:;
    cpu->ax = (uint16_t)(cpu->dx);           /* mov ax, dx */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C706(cpu);                           /* call 0x0135 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17E4), (uint16_t)(0x1)); /* mov word ds:[si+0x17E4], 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17EC), (uint16_t)(0x0)); /* mov word ds:[si+0x17EC], 0x0 */
L_fn_0C5D1_00009D:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17A4))); /* mov ax, word ds:[si+0x17A4] */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x179C), (uint16_t)(cpu->ax)); /* mov word ds:[si+0x179C], ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C678(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C678");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x177C)), 0x0); /* cmp word ds:[si+0x177C], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0C678_00003F;  /* jne 0x003F */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x1); /* cmp word ds:[0x1778], 0x1 */
    if (cc_e(cpu)) goto L_fn_0C678_000039;   /* je 0x0039 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x2); /* cmp word ds:[0x1778], 0x2 */
    if (cc_e(cpu)) goto L_fn_0C678_000021;   /* je 0x0021 */
    cpu->al = (uint8_t)(port_in8(cpu, 0x61)); /* in al, 0x61 */
    { uint8_t _r = cpu->al | 0x3; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, 0x3 */
    port_out8(cpu, 0x61, cpu->al);           /* out 0x61, al */
    goto L_fn_0C678_00003F;                  /* jmp 0x003F */
    /* nop */                                /* nop */
L_fn_0C678_000021:;
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->es);                    /* push es */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x1766))); /* mov ax, word ds:[si+0x1766] */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DB60(cpu);                           /* call 0x14E8 */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    goto L_fn_0C678_00003F;                  /* jmp 0x003F */
    /* nop */                                /* nop */
L_fn_0C678_000039:;
    cpu->al = (uint8_t)(port_in8(cpu, 0x61)); /* in al, 0x61 */
    { uint8_t _r = cpu->al | 0x60; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, 0x60 */
    port_out8(cpu, 0x61, cpu->al);           /* out 0x61, al */
L_fn_0C678_00003F:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C6B9(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C6B9");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x177C)), 0x0); /* cmp word ds:[si+0x177C], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0C6B9_00004B;  /* jne 0x004B */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x1); /* cmp word ds:[0x1778], 0x1 */
    if (cc_e(cpu)) goto L_fn_0C6B9_000035;   /* je 0x0035 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x2); /* cmp word ds:[0x1778], 0x2 */
    if (cc_e(cpu)) goto L_fn_0C6B9_000021;   /* je 0x0021 */
    cpu->al = (uint8_t)(port_in8(cpu, 0x61)); /* in al, 0x61 */
    { uint8_t _r = cpu->al & 0xFC; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0xFC */
    port_out8(cpu, 0x61, cpu->al);           /* out 0x61, al */
    goto L_fn_0C6B9_00004B;                  /* jmp 0x004B */
    /* nop */                                /* nop */
L_fn_0C6B9_000021:;
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->cx);                    /* push cx */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0DCC7(cpu);                           /* call 0x160E */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    goto L_fn_0C6B9_00004B;                  /* jmp 0x004B */
    /* nop */                                /* nop */
L_fn_0C6B9_000035:;
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0x90)); /* add al, 0x90 */
    { uint8_t _r = cpu->al | 0xF; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, 0xF */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C8D4(cpu);                           /* call 0x021B */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C706(cpu);                           /* call 0x004D */
L_fn_0C6B9_00004B:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C706(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C706");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x177C)), 0x0); /* cmp word ds:[si+0x177C], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0C706_00004D;  /* jne 0x004D */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x1); /* cmp word ds:[0x1778], 0x1 */
    if (cc_e(cpu)) goto L_fn_0C706_000028;   /* je 0x0028 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x2); /* cmp word ds:[0x1778], 0x2 */
    if (cc_e(cpu)) goto L_fn_0C706_000021;   /* je 0x0021 */
    port_out8(cpu, 0x42, cpu->al);           /* out 0x42, al */
    cpu->al = (uint8_t)(cpu->ah);            /* mov al, ah */
    port_out8(cpu, 0x42, cpu->al);           /* out 0x42, al */
    goto L_fn_0C706_00004D;                  /* jmp 0x004D */
    /* nop */                                /* nop */
L_fn_0C706_000021:;
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x1766), (uint16_t)(cpu->ax)); /* mov word ds:[si+0x1766], ax */
    goto L_fn_0C706_00004D;                  /* jmp 0x004D */
    /* nop */                                /* nop */
L_fn_0C706_000028:;
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    cpu->al = (uint8_t)(flags_add8(cpu, cpu->al, 0x80)); /* add al, 0x80 */
    cpu->ah = (uint8_t)(cpu->bl);            /* mov ah, bl */
    { uint8_t _r = cpu->ah & 0xF; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* and ah, 0xF */
    { uint8_t _r = cpu->al | cpu->ah; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, ah */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C8D4(cpu);                           /* call 0x01CE */
    cpu->al = (uint8_t)(cpu->bl);            /* mov al, bl */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C8D4(cpu);                           /* call 0x01CE */
L_fn_0C706_00004D:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C755(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C755");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    mem_write16(cpu, cpu->ds, 0x1784, (uint16_t)(0x0)); /* mov word ds:[0x1784], 0x0 */
    mem_write16(cpu, cpu->ds, 0x1786, (uint16_t)(0xFFFF)); /* mov word ds:[0x1786], 0xFFFF */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x177A)); /* mov cx, word ds:[0x177A] */
L_fn_0C755_000015:;
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17AC), (uint16_t)(0x0)); /* mov word ds:[si+0x17AC], 0x0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C6B9(cpu);                           /* call 0xFF64 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x2)); /* add si, 0x2 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0C755_000015; /* loop 0x0015 */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C77A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C77A");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1778)); /* mov ax, word ds:[0x1778] */
    flags_cmp16(cpu, cpu->ax, 0x1);          /* cmp ax, 0x1 */
    if (cc_e(cpu)) goto L_fn_0C77A_00003F;   /* je 0x003F */
    flags_cmp16(cpu, cpu->ax, 0x2);          /* cmp ax, 0x2 */
    if (cc_e(cpu)) goto L_fn_0C77A_00001F;   /* je 0x001F */
    flags_cmp16(cpu, cpu->ax, 0x3);          /* cmp ax, 0x3 */
    if (cc_e(cpu)) goto L_fn_0C77A_00002B;   /* je 0x002B */
    mem_write16(cpu, cpu->ds, 0x177A, (uint16_t)(0x1)); /* mov word ds:[0x177A], 0x1 */
    goto L_fn_0C77A_00004E;                  /* jmp 0x004E */
    /* nop */                                /* nop */
L_fn_0C77A_00001F:;
    mem_write16(cpu, cpu->ds, 0x177A, (uint16_t)(0x4)); /* mov word ds:[0x177A], 0x4 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D99B(cpu);                           /* call 0x1221 */
    goto L_fn_0C77A_00004E;                  /* jmp 0x004E */
    /* nop */                                /* nop */
L_fn_0C77A_00002B:;
    mem_write16(cpu, cpu->ds, 0x1830, (uint16_t)(0x205)); /* mov word ds:[0x1830], 0x205 */
    mem_write16(cpu, cpu->ds, 0x177A, (uint16_t)(0x4)); /* mov word ds:[0x177A], 0x4 */
    mem_write16(cpu, cpu->ds, 0x1778, (uint16_t)(0x1)); /* mov word ds:[0x1778], 0x1 */
    goto L_fn_0C77A_00004E;                  /* jmp 0x004E */
L_fn_0C77A_00003F:;
    mem_write16(cpu, cpu->ds, 0x1830, (uint16_t)(0xC0)); /* mov word ds:[0x1830], 0xC0 */
    mem_write16(cpu, cpu->ds, 0x177A, (uint16_t)(0x4)); /* mov word ds:[0x177A], 0x4 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C678(cpu);                           /* call 0xFEFE */
L_fn_0C77A_00004E:;
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C7CB(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C7CB");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->es);                    /* push es */
    cpu->es = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1764)); /* mov es, word ds:[0x1764] */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov di, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->ds, 0x1786, (uint16_t)(cpu->di)); /* mov word ds:[0x1786], di */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1772), 0x0); /* cmp word ds:[0x1772], 0x0 */
    if (cc_e(cpu)) goto L_fn_0C7CB_000062;   /* je 0x0062 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x2); /* cmp word ds:[0x1778], 0x2 */
    if (cc_ne(cpu)) goto L_fn_0C7CB_00002E;  /* jne 0x002E */
    push16(cpu, cpu->es);                    /* push es */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D8F0(cpu);                           /* call 0x1125 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    mem_write16(cpu, cpu->ds, 0x177A, (uint16_t)(0x4)); /* mov word ds:[0x177A], 0x4 */
L_fn_0C7CB_00002E:;
    cpu->cl = (uint8_t)(0x1);                /* mov cl, 0x1 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x0); /* cmp word ds:[0x1778], 0x0 */
    if (cc_e(cpu)) goto L_fn_0C7CB_000039;   /* je 0x0039 */
    cpu->cl = (uint8_t)(0x3);                /* mov cl, 0x3 */
L_fn_0C7CB_000039:;
    { uint16_t _v = cpu->di; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, cl */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x177A)); /* mov cx, word ds:[0x177A] */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ds, 0x1762))); /* add di, word ds:[0x1762] */
L_fn_0C7CB_000045:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->di)); /* mov ax, word es:[di] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x1762))); /* add ax, word ds:[0x1762] */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x178C), (uint16_t)(cpu->ax)); /* mov word ds:[si+0x178C], ax */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x1794), (uint16_t)(cpu->ax)); /* mov word ds:[si+0x1794], ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x2)); /* add di, 0x2 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x2)); /* add si, 0x2 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0C7CB_000045; /* loop 0x0045 */
    mem_write16(cpu, cpu->ds, 0x1784, (uint16_t)(0x1)); /* mov word ds:[0x1784], 0x1 */
L_fn_0C7CB_000062:;
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C834(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C834");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->si);                    /* push si */
    mem_write16(cpu, cpu->ds, 0x1784, (uint16_t)(0x0)); /* mov word ds:[0x1784], 0x0 */
    mem_write16(cpu, cpu->ds, 0x1786, (uint16_t)(0xFFFF)); /* mov word ds:[0x1786], 0xFFFF */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x177A)); /* mov cx, word ds:[0x177A] */
    push16(cpu, cpu->cx);                    /* push cx */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x2); /* cmp word ds:[0x1778], 0x2 */
    if (cc_ne(cpu)) goto L_fn_0C834_000026;  /* jne 0x0026 */
    mem_write16(cpu, cpu->ds, 0x177A, (uint16_t)(0x4)); /* mov word ds:[0x177A], 0x4 */
L_fn_0C834_000026:;
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x17AC), (uint16_t)(0x0)); /* mov word ds:[si+0x17AC], 0x0 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->si + 0x177C), (uint16_t)(0x0)); /* mov word ds:[si+0x177C], 0x0 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C6B9(cpu);                           /* call 0xFE85 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x2)); /* add si, 0x2 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0C834_000026; /* loop 0x0026 */
    mem_write16(cpu, cpu->ds, 0x177A, (uint16_t)(pop16(cpu))); /* pop word ds:[0x177A] */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C877(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C877");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->si);                    /* push si */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x177A)); /* mov cx, word ds:[0x177A] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1778), 0x2); /* cmp word ds:[0x1778], 0x2 */
    if (cc_ne(cpu)) goto L_fn_0C877_000015;  /* jne 0x0015 */
    cpu->cx = (uint16_t)(0x4);               /* mov cx, 0x4 */
L_fn_0C877_000015:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C6B9(cpu);                           /* call 0xFE42 */
    cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 0x2)); /* add si, 0x2 */
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0C877_000015; /* loop 0x0015 */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C898(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C898");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1830)); /* mov dx, word ds:[0x1830] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    port_out8(cpu, cpu->dx, cpu->al);        /* out dx, al */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc dx */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov ax, word ss:[bp+0x6] */
    port_out8(cpu, cpu->dx, cpu->al);        /* out dx, al */
    { int _cf = cf(cpu); cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C8D4(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C8D4");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->dx);                    /* push dx */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1830)); /* mov dx, word ds:[0x1830] */
    port_out8(cpu, cpu->dx, cpu->al);        /* out dx, al */
    goto L_fn_0C8D4_00000B;                  /* jmp 0x000B */
L_fn_0C8D4_00000B:;
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C8E2(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C8E2");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->es = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1760)); /* mov es, word ds:[0x1760] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1E90), 0x0); /* cmp word ds:[0x1E90], 0x0 */
    if (cc_ne(cpu)) goto L_fn_0C8E2_000018;  /* jne 0x0018 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C914(cpu);                           /* call 0x0032 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1770), 0x0); /* cmp word ds:[0x1770], 0x0 */
    if (cc_e(cpu)) goto L_fn_0C8E2_000030;   /* je 0x0030 */
L_fn_0C8E2_000018:;
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x1E90, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->ds, 0x1E90), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec word ds:[0x1E90] */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1E94), 0x1); /* cmp word ds:[0x1E94], 0x1 */
    if (cc_e(cpu)) goto L_fn_0C8E2_000030;   /* je 0x0030 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1E8E)); /* mov ax, word ds:[0x1E8E] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_sub16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec ax */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1E90), cpu->ax); /* cmp word ds:[0x1E90], ax */
    if (cc_ne(cpu)) goto L_fn_0C8E2_000030;  /* jne 0x0030 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CADB(cpu);                           /* call 0x01F9 */
L_fn_0C8E2_000030:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C914(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C914");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
L_fn_0C914_000003:;
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1E88)); /* mov di, word ds:[0x1E88] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, cpu->di)); /* mov al, byte es:[di] */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _v = cpu->ah; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, 0x1 */
    { uint8_t _r = cpu->al & 0xF; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0xF */
    flags_cmp8(cpu, cpu->al, 0x0);           /* cmp al, 0x0 */
    if (cc_e(cpu)) goto L_fn_0C914_00002F;   /* je 0x002F */
    flags_cmp8(cpu, cpu->al, 0xD);           /* cmp al, 0xD */
    if (cc_e(cpu)) goto L_fn_0C914_000038;   /* je 0x0038 */
    flags_cmp8(cpu, cpu->al, 0xE);           /* cmp al, 0xE */
    if (cc_e(cpu)) goto L_fn_0C914_000043;   /* je 0x0043 */
    flags_cmp8(cpu, cpu->al, 0xF);           /* cmp al, 0xF */
    if (cc_e(cpu)) goto L_fn_0C914_000049;   /* je 0x0049 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C988(cpu);                           /* call 0x0074 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C9A4(cpu);                           /* call 0x0090 */
    goto L_fn_0C914_000066;                  /* jmp 0x0066 */
    /* nop */                                /* nop */
L_fn_0C914_00002F:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CADB(cpu);                           /* call 0x01C7 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C9A4(cpu);                           /* call 0x0090 */
    goto L_fn_0C914_000066;                  /* jmp 0x0066 */
    /* nop */                                /* nop */
L_fn_0C914_000038:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CA03(cpu);                           /* call 0x00EF */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1E90), 0x0); /* cmp word ds:[0x1E90], 0x0 */
    goto L_fn_0C914_000066;                  /* jmp 0x0066 */
    /* nop */                                /* nop */
L_fn_0C914_000043:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CA9B(cpu);                           /* call 0x0187 */
    goto L_fn_0C914_000066;                  /* jmp 0x0066 */
    /* nop */                                /* nop */
L_fn_0C914_000049:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CADB(cpu);                           /* call 0x01C7 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1774), 0x0); /* cmp word ds:[0x1774], 0x0 */
    if (cc_e(cpu)) goto L_fn_0C914_000061;   /* je 0x0061 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1E8A)); /* mov ax, word ds:[0x1E8A] */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAF1(cpu);                           /* call 0x01DD */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x1E90, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x1E90), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x1E90] */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
L_fn_0C914_000061:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0x0234 */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
L_fn_0C914_000066:;
    mem_write16(cpu, cpu->ds, 0x1E88, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x1E88), 0x2))); /* add word ds:[0x1E88], 0x2 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1E90), 0x0); /* cmp word ds:[0x1E90], 0x0 */
    RECOMP_TICK(cpu);
    if (cc_e(cpu)) goto L_fn_0C914_000003;   /* je 0x0003 */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C988(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C988");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->cl = (uint8_t)(cpu->ah);            /* mov cl, ah */
    cpu->bx = (uint16_t)(0x17FC);            /* mov bx, 0x17FC */
    { int _cf = cf(cpu); cpu->al = (uint8_t)(flags_sub8(cpu, cpu->al, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* dec al */
    { uint8_t _v = cpu->al; uint8_t _c = (0x1) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v << _c); int _cf = (_c <= 8) ? ((_v >> (8 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (8 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->al = (uint8_t)(_r); } } /* shl al, 0x1 */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->ax)); /* add bx, ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, cpu->bx)); /* mov ax, word ds:[bx] */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, cl */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAE6(cpu);                           /* call 0x015E */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAD0(cpu);                           /* call 0x0148 */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0C9A4(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0C9A4");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->di + 0x1))); /* mov al, byte es:[di+0x1] */
    cpu->ah = (uint8_t)(cpu->al);            /* mov ah, al */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1E84)); /* mov bx, word ds:[0x1E84] */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, mem_read16(cpu, cpu->ds, 0x1E86))); /* add bx, word ds:[0x1E86] */
    flags_logic8(cpu, cpu->ah & 0x80);       /* test ah, 0x80 */
    if (cc_e(cpu)) goto L_fn_0C9A4_00001A;   /* je 0x001A */
    { uint8_t _r = cpu->al & 0x7F; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0x7F */
    goto L_fn_0C9A4_000059;                  /* jmp 0x0059 */
L_fn_0C9A4_00001A:;
    { uint8_t _r = cpu->al & 0x7; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0x7 */
    cpu->cl = (uint8_t)(cpu->al);            /* mov cl, al */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, cl */
    flags_logic8(cpu, cpu->ah & 0x8);        /* test ah, 0x8 */
    if (cc_e(cpu)) goto L_fn_0C9A4_00002B;   /* je 0x002B */
    cpu->dx = (uint16_t)(cpu->bx);           /* mov dx, bx */
    { uint16_t _v = cpu->dx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shr dx, 0x1 */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->dx)); /* add bx, dx */
L_fn_0C9A4_00002B:;
    flags_logic8(cpu, cpu->ah & 0x10);       /* test ah, 0x10 */
    if (cc_e(cpu)) goto L_fn_0C9A4_00004E;   /* je 0x004E */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1E8C), 0x3); /* cmp word ds:[0x1E8C], 0x3 */
    if (cc_e(cpu)) goto L_fn_0C9A4_000059;   /* je 0x0059 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1E8C), 0x1); /* cmp word ds:[0x1E8C], 0x1 */
    if (cc_e(cpu)) goto L_fn_0C9A4_000045;   /* je 0x0045 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x1E8C, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x1E8C), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x1E8C] */
    goto L_fn_0C9A4_000059;                  /* jmp 0x0059 */
    /* nop */                                /* nop */
L_fn_0C9A4_000045:;
    mem_write16(cpu, cpu->ds, 0x1E8C, (uint16_t)(0x3)); /* mov word ds:[0x1E8C], 0x3 */
    goto L_fn_0C9A4_000059;                  /* jmp 0x0059 */
    /* nop */                                /* nop */
L_fn_0C9A4_00004E:;
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x1E8C), 0x0); /* cmp word ds:[0x1E8C], 0x0 */
    if (cc_e(cpu)) goto L_fn_0C9A4_000059;   /* je 0x0059 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0x1E8C, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0x1E8C), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0x1E8C] */
L_fn_0C9A4_000059:;
    mem_write16(cpu, cpu->ds, 0x1E90, (uint16_t)(cpu->bx)); /* mov word ds:[0x1E90], bx */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CA03(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CA03");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->di + 0x1))); /* mov al, byte es:[di+0x1] */
    flags_cmp8(cpu, cpu->ah, 0x0);           /* cmp ah, 0x0 */
    if (cc_ne(cpu)) goto L_fn_0CA03_000012;  /* jne 0x0012 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CA35(cpu);                           /* call 0x0032 */
    goto L_fn_0CA03_000030;                  /* jmp 0x0030 */
    /* nop */                                /* nop */
L_fn_0CA03_000012:;
    flags_cmp8(cpu, cpu->ah, 0x2);           /* cmp ah, 0x2 */
    if (cc_g(cpu)) goto L_fn_0CA03_00001D;   /* jg 0x001D */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CA51(cpu);                           /* call 0x004E */
    goto L_fn_0CA03_000030;                  /* jmp 0x0030 */
    /* nop */                                /* nop */
L_fn_0CA03_00001D:;
    flags_cmp8(cpu, cpu->ah, 0x3);           /* cmp ah, 0x3 */
    if (cc_ne(cpu)) goto L_fn_0CA03_000028;  /* jne 0x0028 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CA91(cpu);                           /* call 0x008E */
    goto L_fn_0CA03_000030;                  /* jmp 0x0030 */
    /* nop */                                /* nop */
L_fn_0CA03_000028:;
    flags_cmp8(cpu, cpu->ah, 0x4);           /* cmp ah, 0x4 */
    if (cc_ne(cpu)) goto L_fn_0CA03_000030;  /* jne 0x0030 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CA83(cpu);                           /* call 0x0080 */
L_fn_0CA03_000030:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CA35(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CA35");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    flags_cmp8(cpu, cpu->al, 0x0);           /* cmp al, 0x0 */
    if (cc_e(cpu)) goto L_fn_0CA35_000014;   /* je 0x0014 */
    mem_write16(cpu, cpu->ds, 0x1E94, (uint16_t)(0x0)); /* mov word ds:[0x1E94], 0x0 */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    mem_write16(cpu, cpu->ds, 0x1E8E, (uint16_t)(cpu->ax)); /* mov word ds:[0x1E8E], ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
L_fn_0CA35_000014:;
    mem_write16(cpu, cpu->ds, 0x1E94, (uint16_t)(0x1)); /* mov word ds:[0x1E94], 0x1 */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CA51(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CA51");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->bl = (uint8_t)(cpu->ah);            /* mov bl, ah */
    cpu->cl = (uint8_t)(cpu->al);            /* mov cl, al */
    { uint8_t _r = cpu->ch ^ cpu->ch; flags_logic8(cpu, _r); cpu->ch = (uint8_t)(_r); } /* xor ch, ch */
    flags_cmp16(cpu, cpu->cx, 0x0);          /* cmp cx, 0x0 */
    if (cc_e(cpu)) goto L_fn_0CA51_00002A;   /* je 0x002A */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1E84)); /* mov ax, word ds:[0x1E84] */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->cx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul cx */
    cpu->cx = (uint16_t)(0x64);              /* mov cx, 0x64 */
    { uint32_t _n = ((uint32_t)cpu->dx << 16) | cpu->ax; uint16_t _d = cpu->cx; if (_d && _n / _d <= 0xFFFFu) { cpu->ax = (uint16_t)(_n / _d); cpu->dx = (uint16_t)(_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0016; recomp_div0("div16"); } } /* div cx */
    flags_cmp16(cpu, cpu->dx, 0x31);         /* cmp dx, 0x31 */
    if (cc_le(cpu)) goto L_fn_0CA51_00001E;  /* jle 0x001E */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
L_fn_0CA51_00001E:;
    flags_cmp8(cpu, cpu->bl, 0x1);           /* cmp bl, 0x1 */
    if (cc_e(cpu)) goto L_fn_0CA51_000025;   /* je 0x0025 */
    cpu->ax = (uint16_t)(flags_sub16(cpu, 0, cpu->ax)); /* neg ax */
L_fn_0CA51_000025:;
    mem_write16(cpu, cpu->ds, 0x1E86, (uint16_t)(cpu->ax)); /* mov word ds:[0x1E86], ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
L_fn_0CA51_00002A:;
    mem_write16(cpu, cpu->ds, 0x1E86, (uint16_t)(0x0)); /* mov word ds:[0x1E86], 0x0 */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CA83(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CA83");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    mem_write16(cpu, cpu->ds, 0x1E84, (uint16_t)(cpu->ax)); /* mov word ds:[0x1E84], ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CA91(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CA91");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    mem_write16(cpu, cpu->ds, 0x1E92, (uint16_t)(cpu->ax)); /* mov word ds:[0x1E92], ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CA9B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CA9B");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->dl = (uint8_t)(mem_read8(cpu, cpu->es, (uint16_t)(cpu->di + 0x1))); /* mov dl, byte es:[di+0x1] */
    { uint8_t _r = cpu->dh ^ cpu->dh; flags_logic8(cpu, _r); cpu->dh = (uint8_t)(_r); } /* xor dh, dh */
    flags_cmp16(cpu, cpu->dx, 0x0);          /* cmp dx, 0x0 */
    if (cc_ne(cpu)) goto L_fn_0CA9B_000014;  /* jne 0x0014 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CADB(cpu);                           /* call 0x0040 */
    goto L_fn_0CA9B_00002D;                  /* jmp 0x002D */
    /* nop */                                /* nop */
L_fn_0CA9B_000014:;
    cpu->cl = (uint8_t)(0x7);                /* mov cl, 0x7 */
    { uint16_t _v = cpu->dx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shl dx, cl */
    cpu->dx = (uint16_t)(flags_sub16(cpu, 0, cpu->dx)); /* neg dx */
    cpu->cl = (uint8_t)(cpu->ah);            /* mov cl, ah */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->bx = (uint16_t)(0x17FC);            /* mov bx, 0x17FC */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, cpu->bx)); /* mov ax, word ds:[bx] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, cpu->dx)); /* add ax, dx */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shr ax, cl */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAE6(cpu);                           /* call 0x004B */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CAD0(cpu);                           /* call 0x0035 */
L_fn_0CA9B_00002D:;
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1E92)); /* mov ax, word ds:[0x1E92] */
    mem_write16(cpu, cpu->ds, 0x1E90, (uint16_t)(cpu->ax)); /* mov word ds:[0x1E90], ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CAD0(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CAD0");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->al = (uint8_t)(port_in8(cpu, 0x61)); /* in al, 0x61 */
    { uint8_t _r = cpu->al | 0x3; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* or al, 0x3 */
    port_out8(cpu, 0x61, cpu->al);           /* out 0x61, al */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CADB(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CADB");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->al = (uint8_t)(port_in8(cpu, 0x61)); /* in al, 0x61 */
    { uint8_t _r = cpu->al & 0xFC; flags_logic8(cpu, _r); cpu->al = (uint8_t)(_r); } /* and al, 0xFC */
    port_out8(cpu, 0x61, cpu->al);           /* out 0x61, al */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CAE6(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CAE6");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    port_out8(cpu, 0x42, cpu->al);           /* out 0x42, al */
    cpu->al = (uint8_t)(cpu->ah);            /* mov al, ah */
    port_out8(cpu, 0x42, cpu->al);           /* out 0x42, al */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CAF1(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CAF1");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->cx);                    /* push cx */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->es);                    /* push es */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, 0x176E), 0x0); /* cmp word ds:[0x176E], 0x0 */
    if (cc_e(cpu)) goto L_fn_0CAF1_000050;   /* je 0x0050 */
    cpu->es = (uint16_t)(mem_read16(cpu, cpu->ds, 0x1760)); /* mov es, word ds:[0x1760] */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov di, word ss:[bp+0x4] */
    flags_cmp16(cpu, cpu->di, mem_read16(cpu, cpu->ds, 0x1E8A)); /* cmp di, word ds:[0x1E8A] */
    if (cc_a(cpu)) goto L_fn_0CAF1_000050;   /* ja 0x0050 */
    mem_write16(cpu, cpu->ds, 0x1E8A, (uint16_t)(cpu->di)); /* mov word ds:[0x1E8A], di */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, mem_read16(cpu, cpu->ds, 0x175E))); /* add di, word ds:[0x175E] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->di)); /* mov ax, word es:[di] */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x175E))); /* add ax, word ds:[0x175E] */
    mem_write16(cpu, cpu->ds, 0x1E88, (uint16_t)(cpu->ax)); /* mov word ds:[0x1E88], ax */
    mem_write16(cpu, cpu->ds, 0x1770, (uint16_t)(0x2)); /* mov word ds:[0x1770], 0x2 */
    mem_write16(cpu, cpu->ds, 0x1E8E, (uint16_t)(0x6)); /* mov word ds:[0x1E8E], 0x6 */
    mem_write16(cpu, cpu->ds, 0x1E92, (uint16_t)(0x1)); /* mov word ds:[0x1E92], 0x1 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0x1E86, (uint16_t)(cpu->ax)); /* mov word ds:[0x1E86], ax */
    mem_write16(cpu, cpu->ds, 0x1E90, (uint16_t)(cpu->ax)); /* mov word ds:[0x1E90], ax */
    mem_write16(cpu, cpu->ds, 0x1E94, (uint16_t)(cpu->ax)); /* mov word ds:[0x1E94], ax */
    mem_write16(cpu, cpu->ds, 0x1E8C, (uint16_t)(cpu->ax)); /* mov word ds:[0x1E8C], ax */
L_fn_0CAF1_000050:;
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CB48(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CB48");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    mem_write16(cpu, cpu->ds, 0x1770, (uint16_t)(0x0)); /* mov word ds:[0x1770], 0x0 */
    mem_write16(cpu, cpu->ds, 0x1E8A, (uint16_t)(0xFFFF)); /* mov word ds:[0x1E8A], 0xFFFF */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CADB(cpu);                           /* call 0xFF93 */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CC6C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CC6C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x21C4);            /* mov ax, 0x21C4 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08480(cpu);                           /* call 0xB814 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x3562 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x27);              /* mov ax, 0x27 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x32);              /* mov ax, 0x32 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2B);              /* mov ax, 0x2B */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x3736 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x26);              /* mov ax, 0x26 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x32);              /* mov ax, 0x32 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x9D);              /* mov ax, 0x9D */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x3736 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x23);              /* mov ax, 0x23 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x32);              /* mov ax, 0x32 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xDF);              /* mov ax, 0xDF */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x3736 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CF0(cpu);                           /* call 0xA084 */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_0CC6C_000082;                  /* jmp 0x0082 */
L_fn_0CC6C_000060:;
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x34)); /* add ax, 0x34 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC360)); /* add ax, 0xC360 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A28D(cpu);                           /* call 0xD621 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
L_fn_0CC6C_000082:;
    flags_cmp16(cpu, cpu->si, 0xA);          /* cmp si, 0xA */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0CC6C_000060;   /* jl 0x0060 */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x130);             /* mov ax, 0x130 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x3733 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_0CC6C_00009C:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B1A(cpu);                           /* call 0x9EAE */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    flags_cmp16(cpu, cpu->si, 0x1B);         /* cmp si, 0x1B */
    if (cc_e(cpu)) goto L_fn_0CC6C_0000AB;   /* je 0x00AB */
    flags_cmp16(cpu, cpu->si, 0xD);          /* cmp si, 0xD */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_0CC6C_00009C;  /* jne 0x009C */
L_fn_0CC6C_0000AB:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08453(cpu);                           /* call 0xB7E7 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0CC6C_0000B2;                  /* jmp 0x00B2 */
L_fn_0CC6C_0000B2:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CD24(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CD24");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x21D8);            /* mov ax, 0x21D8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08480(cpu);                           /* call 0xB75C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x34AA */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->ax = (uint16_t)(0x27);              /* mov ax, 0x27 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x32);              /* mov ax, 0x32 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2B);              /* mov ax, 0x2B */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x367E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x26);              /* mov ax, 0x26 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x32);              /* mov ax, 0x32 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x99);              /* mov ax, 0x99 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x367E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(0x37);              /* mov ax, 0x37 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x32);              /* mov ax, 0x32 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0xDC);              /* mov ax, 0xDC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03A2);                           /* call 0x367E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06CF0(cpu);                           /* call 0x9FCC */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    goto L_fn_0CD24_000083;                  /* jmp 0x0083 */
L_fn_0CD24_000060:;
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x34)); /* add ax, 0x34 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xC470)); /* add ax, 0xC470 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A28D(cpu);                           /* call 0xD569 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov ax, word ss:[bp+-0x2] */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->ax)); /* add di, ax */
L_fn_0CD24_000083:;
    flags_cmp16(cpu, cpu->si, 0xA);          /* cmp si, 0xA */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0CD24_000060;   /* jl 0x0060 */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x130);             /* mov ax, 0x130 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x8);               /* mov ax, 0x8 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x367B */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_0CD24_00009D:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_06B1A(cpu);                           /* call 0x9DF6 */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    flags_cmp16(cpu, cpu->si, 0x1B);         /* cmp si, 0x1B */
    if (cc_e(cpu)) goto L_fn_0CD24_0000AC;   /* je 0x00AC */
    flags_cmp16(cpu, cpu->si, 0xD);          /* cmp si, 0xD */
    RECOMP_TICK(cpu);
    if (cc_ne(cpu)) goto L_fn_0CD24_00009D;  /* jne 0x009D */
L_fn_0CD24_0000AC:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_08453(cpu);                           /* call 0xB72F */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0CD24_0000B3;                  /* jmp 0x00B3 */
L_fn_0CD24_0000B3:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CE2A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CE2A");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D593(cpu);                           /* call 0x0769 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x21EC);            /* mov ax, 0x21EC */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_086C9(cpu);                           /* call 0xB89F */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    flags_cmp16(cpu, cpu->si, 0x1);          /* cmp si, 0x1 */
    if (cc_ne(cpu)) goto L_fn_0CE2A_000035;  /* jne 0x0035 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0A13F(cpu);                           /* call 0xD315 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    mem_write16(cpu, cpu->ds, 0x1772, (uint16_t)(cpu->ax)); /* mov word ds:[0x1772], ax */
    mem_write16(cpu, cpu->ds, 0x176E, (uint16_t)(cpu->ax)); /* mov word ds:[0x176E], ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CB48(cpu);                           /* call 0xFD1E */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0C834(cpu);                           /* call 0xFA0A */
    cpu->ax = (uint16_t)(0x3);               /* mov ax, 0x3 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ax = (uint16_t)(0x8BFE);            /* mov ax, 0x8BFE */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F98B(cpu);                           /* call 0x2B61 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
L_fn_0CE2A_000035:;
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D5A6(cpu);                           /* call 0x077C */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0CE2A_00003C;                  /* jmp 0x003C */
L_fn_0CE2A_00003C:;
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CE68(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CE68");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 0xFFFF); /* cmp word ss:[bp+0x4], 0xFFFF */
    if (cc_e(cpu)) goto L_fn_0CE68_000034;   /* je 0x0034 */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0xC5B0, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC5B0), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0xC5B0] */
    cpu->ax = (uint16_t)(0x1);               /* mov ax, 0x1 */
    cpu->cl = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov cl, byte ss:[bp+0x4] */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov bx, word ss:[bp+0x4] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    mem_write16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3A4E), (uint16_t)(cpu->ax)); /* mov word ds:[bx+-0x3A4E], ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x13ED)); /* mov ax, word ds:[0x13ED] */
    cpu->dx = (uint16_t)(0x1B);              /* mov dx, 0x1B */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, 0xC470)); /* add bx, 0xC470 */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    { uint8_t _r = mem_read8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xB)) | cpu->al; flags_logic8(cpu, _r); mem_write8(cpu, cpu->es, (uint16_t)(cpu->bx + 0xB), (uint8_t)(_r)); } /* or byte es:[bx+0xB], al */
L_fn_0CE68_000034:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CE9E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CE9E");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x2)); /* sub sp, 0x2 */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0CE9E_000090;                  /* jmp 0x0090 */
L_fn_0CE9E_00000D:;
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x22E0))); /* mov di, word ds:[bx+0x22E0] */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x22E8))); /* mov ax, word ds:[bx+0x22E8] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x2], ax */
    cpu->ax = (uint16_t)(0x190);             /* mov ax, 0x190 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x2A);              /* mov dx, 0x2A */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2A);              /* mov ax, 0x2A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x3516 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x352E */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    cpu->ax = (uint16_t)(0x1B0);             /* mov ax, 0x1B0 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x2A);              /* mov dx, 0x2A */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2A);              /* mov ax, 0x2A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x3516 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2A);              /* mov ax, 0x2A */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x190);             /* mov ax, 0x190 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(0x2A);              /* mov dx, 0x2A */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x3516 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0CE9E_000090:;
    flags_cmp16(cpu, cpu->si, 0x4);          /* cmp si, 0x4 */
    if (cc_ge(cpu)) goto L_fn_0CE9E_000098;  /* jge 0x0098 */
    RECOMP_TICK(cpu);
    goto L_fn_0CE9E_00000D;                  /* jmp 0x000D */
L_fn_0CE9E_000098:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0CF3C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0CF3C");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    mem_write16(cpu, cpu->ds, 0x96, (uint16_t)(0x190)); /* mov word ds:[0x96], 0x190 */
    cpu->ax = (uint16_t)(0x1A);              /* mov ax, 0x1A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x9630 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(0xD4);              /* mov ax, 0xD4 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03C9);                           /* call 0x348D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
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
    ovl_call(cpu, 0x03B4);                           /* call 0x3478 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x1B);              /* mov ax, 0x1B */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x9630 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x94, (uint16_t)(0x0)); /* mov word ds:[0x94], 0x0 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2E);              /* mov ax, 0x2E */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x3490 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(0xC);               /* mov ax, 0xC */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x106);             /* mov ax, 0x106 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x3490 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ds, 0x94, (uint16_t)(0x10)); /* mov word ds:[0x94], 0x10 */
    cpu->ax = (uint16_t)(0x1C);              /* mov ax, 0x1C */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x9630 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x98, (uint16_t)(0x3)); /* mov word ds:[0x98], 0x3 */
    mem_write16(cpu, cpu->ds, 0x9A, (uint16_t)(0x9C)); /* mov word ds:[0x9A], 0x9C */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    cpu->ax = (uint16_t)(0x11);              /* mov ax, 0x11 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x6);               /* mov ax, 0x6 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x3490 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    mem_write16(cpu, cpu->ds, 0x98, (uint16_t)(0x4)); /* mov word ds:[0x98], 0x4 */
    mem_write16(cpu, cpu->ds, 0x9A, (uint16_t)(0x9B)); /* mov word ds:[0x9A], 0x9B */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
    goto L_fn_0CF3C_00010A;                  /* jmp 0x010A */
L_fn_0CF3C_0000C3:;
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3A4E)), 0x0); /* cmp word ds:[bx+-0x3A4E], 0x0 */
    if (cc_e(cpu)) goto L_fn_0CF3C_0000D3;   /* je 0x00D3 */
    cpu->di = (uint16_t)(0x1);               /* mov di, 0x1 */
    goto L_fn_0CF3C_0000D5;                  /* jmp 0x00D5 */
L_fn_0CF3C_0000D3:;
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
L_fn_0CF3C_0000D5:;
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    { uint16_t _v = cpu->di; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, 0x1 */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, cpu->si)); /* add di, si */
    cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 0x3)); /* add di, 0x3 */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1A)); /* add ax, 0x1A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x9630 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C8)); /* push word ds:[0xC5C8] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0xC5C6)); /* push word ds:[0xC5C6] */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x22E8))); /* push word ds:[bx+0x22E8] */
    cpu->bx = (uint16_t)(cpu->si);           /* mov bx, si */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    push16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x22E0))); /* push word ds:[bx+0x22E0] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03CC);                           /* call 0x3490 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xA)); /* add sp, 0xA */
    { int _cf = cf(cpu); cpu->si = (uint16_t)(flags_add16(cpu, cpu->si, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc si */
L_fn_0CF3C_00010A:;
    flags_cmp16(cpu, cpu->si, 0x4);          /* cmp si, 0x4 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0CF3C_0000C3;   /* jl 0x00C3 */
    cpu->ax = (uint16_t)(0x25);              /* mov ax, 0x25 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0656C(cpu);                           /* call 0x9630 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_001CE(cpu);                           /* call 0x3292 */
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
    ovl_call(cpu, 0x03A8);                           /* call 0x346C */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0CE9E(cpu);                           /* call 0xFF62 */
    cpu->ax = (uint16_t)(0xC8);              /* mov ax, 0xC8 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x140);             /* mov ax, 0x140 */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x3463 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D089(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D089");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0AD0E(cpu);                           /* call 0xDC85 */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _r = cpu->ax & 0x1; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x1 */
    mem_write16(cpu, cpu->ds, 0xC5B2, (uint16_t)(cpu->ax)); /* mov word ds:[0xC5B2], ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _r = cpu->ax & 0x2; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x2 */
    mem_write16(cpu, cpu->ds, 0xC5B4, (uint16_t)(cpu->ax)); /* mov word ds:[0xC5B4], ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _r = cpu->ax & 0x4; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x4 */
    mem_write16(cpu, cpu->ds, 0xC5B6, (uint16_t)(cpu->ax)); /* mov word ds:[0xC5B6], ax */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    { uint16_t _r = cpu->ax & 0x8; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x8 */
    mem_write16(cpu, cpu->ds, 0xC5B8, (uint16_t)(cpu->ax)); /* mov word ds:[0xC5B8], ax */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    mem_write16(cpu, cpu->ds, 0xC5B0, (uint16_t)(cpu->di)); /* mov word ds:[0xC5B0], di */
    goto L_fn_0D089_000040;                  /* jmp 0x0040 */
L_fn_0D089_000030:;
    cpu->bx = (uint16_t)(cpu->di);           /* mov bx, di */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx - 0x3A4E)), 0x0); /* cmp word ds:[bx+-0x3A4E], 0x0 */
    if (cc_e(cpu)) goto L_fn_0D089_00003F;   /* je 0x003F */
    { int _cf = cf(cpu); mem_write16(cpu, cpu->ds, 0xC5B0, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->ds, 0xC5B0), 1))); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc word ds:[0xC5B0] */
L_fn_0D089_00003F:;
    { int _cf = cf(cpu); cpu->di = (uint16_t)(flags_add16(cpu, cpu->di, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc di */
L_fn_0D089_000040:;
    flags_cmp16(cpu, cpu->di, 0x4);          /* cmp di, 0x4 */
    RECOMP_TICK(cpu);
    if (cc_l(cpu)) goto L_fn_0D089_000030;   /* jl 0x0030 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D0D1(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D0D1");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5BA)); /* mov bx, word ds:[0xC5BA] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x22E0))); /* mov si, word ds:[bx+0x22E0] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5BA)); /* mov bx, word ds:[0xC5BA] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x22E8))); /* mov di, word ds:[bx+0x22E8] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2A);              /* mov ax, 0x2A */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x190);             /* mov ax, 0x190 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5BA)); /* mov ax, word ds:[0xC5BA] */
    cpu->dx = (uint16_t)(0x2A);              /* mov dx, 0x2A */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x32E3 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2A);              /* mov ax, 0x2A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x32CE */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D117(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D117");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5BA)); /* mov bx, word ds:[0xC5BA] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->si = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x22E0))); /* mov si, word ds:[bx+0x22E0] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5BA)); /* mov bx, word ds:[0xC5BA] */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shl bx, 0x1 */
    cpu->di = (uint16_t)(mem_read16(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x22E8))); /* mov di, word ds:[bx+0x22E8] */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2A);              /* mov ax, 0x2A */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x1B0);             /* mov ax, 0x1B0 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0xC5BA)); /* mov ax, word ds:[0xC5BA] */
    cpu->dx = (uint16_t)(0x2A);              /* mov dx, 0x2A */
    { uint32_t _r = (uint32_t)cpu->ax * cpu->dx; cpu->ax = (uint16_t)_r; cpu->dx = (uint16_t)(_r >> 16); cpu->flags = (cpu->flags & ~(FLAG_CF|FLAG_OF)) | (cpu->dx ? FLAG_CF|FLAG_OF : 0); } /* mul dx */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x03B4);                           /* call 0x329D */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0xC)); /* add sp, 0xC */
    cpu->ax = (uint16_t)(0x20);              /* mov ax, 0x20 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x2A);              /* mov ax, 0x2A */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    ovl_call(cpu, 0x039F);                           /* call 0x3288 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0D15D(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0D15D");
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0D117(cpu);                           /* call 0xFFBA */
    recomp_dispatch(cpu, 0xD1D, 0x3); return; /* tail-jmp 0x00D1D3 */ /* jmp 0x0076 */
}
