#include "recomp_all.h"

void fn_0F407(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F407");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    { uint16_t _r = cpu->cx ^ cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* xor cx, cx */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C6)); /* mov dx, word ds:[0x37C6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C4)); /* mov ax, word ds:[0x37C4] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC6A(cpu);                           /* call 0000:EC6A */
    if (cc_e(cpu)) goto L_fn_0F407_00006E;   /* je 0x006E */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x37C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x37C4 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x37C4] */
    { uint16_t _o = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC)); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)((uint16_t)(cpu->bx + 0xC) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx+0xC] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x37C4); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x37C4 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x37C4] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xE), (uint16_t)(cpu->dx)); /* mov word es:[bx+0xE], dx */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC), (uint16_t)(cpu->ax)); /* mov word es:[bx+0xC], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xA), (uint16_t)(cpu->dx)); /* mov word es:[bx+0xA], dx */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x8), (uint16_t)(cpu->ax)); /* mov word es:[bx+0x8], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xE), (uint16_t)(cpu->dx)); /* mov word es:[bx+0xE], dx */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC), (uint16_t)(cpu->ax)); /* mov word es:[bx+0xC], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C6)); /* mov dx, word ds:[0x37C6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C4)); /* mov ax, word ds:[0x37C4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xA), (uint16_t)(cpu->dx)); /* mov word es:[bx+0xA], dx */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x8), (uint16_t)(cpu->ax)); /* mov word es:[bx+0x8], ax */
    goto L_fn_0F407_00009B;                  /* jmp 0x009B */
L_fn_0F407_00006E:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->ds, 0x37C6, (uint16_t)(cpu->es)); /* mov word ds:[0x37C6], es */
    mem_write16(cpu, cpu->ds, 0x37C4, (uint16_t)(cpu->bx)); /* mov word ds:[0x37C4], bx */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xA), (uint16_t)(cpu->dx)); /* mov word es:[bx+0xA], dx */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x8), (uint16_t)(cpu->ax)); /* mov word es:[bx+0x8], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xE), (uint16_t)(cpu->dx)); /* mov word es:[bx+0xE], dx */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0xC), (uint16_t)(cpu->ax)); /* mov word es:[bx+0xC], ax */
L_fn_0F407_00009B:;
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F4A6(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F4A6");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x8] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov dx, word es:[bx+0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->es, cpu->bx), cpu->ax))); /* add word es:[bx], ax */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2), (uint16_t)(flags_adc(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)), cpu->dx, 16))); /* adc word es:[bx+0x2], dx */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov cx, word ss:[bp+0xA] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C2)); /* mov dx, word ds:[0x37C2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C0)); /* mov ax, word ds:[0x37C0] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC6A(cpu);                           /* call 0000:EC6A */
    if (cc_ne(cpu)) goto L_fn_0F4A6_00003B;  /* jne 0x003B */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->ds, 0x37C2, (uint16_t)(cpu->es)); /* mov word ds:[0x37C2], es */
    mem_write16(cpu, cpu->ds, 0x37C0, (uint16_t)(cpu->bx)); /* mov word ds:[0x37C0], bx */
    goto L_fn_0F4A6_000067;                  /* jmp 0x0067 */
L_fn_0F4A6_00003B:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x8] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov cx, word es:[bx+0x2] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov bx, word es:[bx] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov dx, word ss:[bp+0xA] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov ax, word ss:[bp+0x8] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC0F(cpu);                           /* call 0000:EC0F */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x2], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x4], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x6), (uint16_t)(cpu->dx)); /* mov word es:[bx+0x6], dx */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4), (uint16_t)(cpu->ax)); /* mov word es:[bx+0x4], ax */
L_fn_0F4A6_000067:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* push word ss:[bp+0xA] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* push word ss:[bp+0x8] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E7CC(cpu);                           /* call 0xF326 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F51C(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F51C");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x4)); /* sub sp, 0x4 */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C2)); /* mov cx, word ds:[0x37C2] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37C0)); /* mov bx, word ds:[0x37C0] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37BE)); /* mov dx, word ds:[0x37BE] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37BC)); /* mov ax, word ds:[0x37BC] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC6A(cpu);                           /* call 0000:EC6A */
    if (cc_ne(cpu)) goto L_fn_0F51C_000046;  /* jne 0x0046 */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x37BE)); /* push word ds:[0x37BE] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x37BC)); /* push word ds:[0x37BC] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EB4D(cpu);                           /* call 0xF631 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    mem_write16(cpu, cpu->ds, 0x37C2, (uint16_t)(0x0)); /* mov word ds:[0x37C2], 0x0 */
    mem_write16(cpu, cpu->ds, 0x37C0, (uint16_t)(0x0)); /* mov word ds:[0x37C0], 0x0 */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->es = (uint16_t)(cpu->bx);           /* mov es, bx */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    mem_write16(cpu, cpu->ds, 0x37BE, (uint16_t)(cpu->es)); /* mov word ds:[0x37BE], es */
    mem_write16(cpu, cpu->ds, 0x37BC, (uint16_t)(cpu->bx)); /* mov word ds:[0x37BC], bx */
    goto L_fn_0F51C_0000D9;                  /* jmp 0x00D9 */
L_fn_0F51C_000046:;
    { uint16_t _o = mem_read16(cpu, cpu->ds, 0x37C0); uint16_t _s = mem_read16(cpu, cpu->ds, (uint16_t)(0x37C0 + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ds:[0x37C0] */
    { uint16_t _o = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4)); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)((uint16_t)(cpu->bx + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx+0x4] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov dx, word es:[bx+0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    { uint16_t _r = cpu->ax & 0x1; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x1 */
    { uint16_t _r = cpu->dx & 0x0; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* and dx, 0x0 */
    { uint16_t _r = cpu->dx | cpu->ax; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* or dx, ax */
    if (cc_ne(cpu)) goto L_fn_0F51C_0000C1;  /* jne 0x00C1 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E7CC(cpu);                           /* call 0xF2B0 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37BE)); /* mov cx, word ds:[0x37BE] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37BC)); /* mov bx, word ds:[0x37BC] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC6A(cpu);                           /* call 0000:EC6A */
    if (cc_ne(cpu)) goto L_fn_0F51C_0000A5;  /* jne 0x00A5 */
    mem_write16(cpu, cpu->ds, 0x37C2, (uint16_t)(0x0)); /* mov word ds:[0x37C2], 0x0 */
    mem_write16(cpu, cpu->ds, 0x37C0, (uint16_t)(0x0)); /* mov word ds:[0x37C0], 0x0 */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    cpu->es = (uint16_t)(cpu->bx);           /* mov es, bx */
    { uint16_t _r = cpu->bx ^ cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* xor bx, bx */
    mem_write16(cpu, cpu->ds, 0x37BE, (uint16_t)(cpu->es)); /* mov word ds:[0x37BE], es */
    mem_write16(cpu, cpu->ds, 0x37BC, (uint16_t)(cpu->bx)); /* mov word ds:[0x37BC], bx */
    goto L_fn_0F51C_0000B4;                  /* jmp 0x00B4 */
L_fn_0F51C_0000A5:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4)); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)((uint16_t)(cpu->bx + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx+0x4] */
    mem_write16(cpu, cpu->ds, 0x37C2, (uint16_t)(cpu->es)); /* mov word ds:[0x37C2], es */
    mem_write16(cpu, cpu->ds, 0x37C0, (uint16_t)(cpu->bx)); /* mov word ds:[0x37C0], bx */
L_fn_0F51C_0000B4:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* push word ss:[bp+-0x2] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* push word ss:[bp+-0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EB4D(cpu);                           /* call 0xF631 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    goto L_fn_0F51C_0000D9;                  /* jmp 0x00D9 */
L_fn_0F51C_0000C1:;
    push16(cpu, mem_read16(cpu, cpu->ds, 0x37C2)); /* push word ds:[0x37C2] */
    push16(cpu, mem_read16(cpu, cpu->ds, 0x37C0)); /* push word ds:[0x37C0] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0EB4D(cpu);                           /* call 0xF631 */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->ds, 0x37C2, (uint16_t)(cpu->es)); /* mov word ds:[0x37C2], es */
    mem_write16(cpu, cpu->ds, 0x37C0, (uint16_t)(cpu->bx)); /* mov word ds:[0x37C0], bx */
L_fn_0F51C_0000D9:;
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F5F9(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F5F9");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->sp = (uint16_t)(flags_sub16(cpu, cpu->sp, 0x8)); /* sub sp, 0x8 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(flags_sub16(cpu, mem_read16(cpu, cpu->es, cpu->bx), 0x1))); /* sub word es:[bx], 0x1 */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2), (uint16_t)(flags_sbb(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)), 0x0, 16))); /* sbb word es:[bx+0x2], 0x0 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov cx, word es:[bx+0x2] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov bx, word es:[bx] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC0F(cpu);                           /* call 0000:EC0F */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6), (uint16_t)(cpu->dx)); /* mov word ss:[bp+-0x6], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8), (uint16_t)(cpu->ax)); /* mov word ss:[bp+-0x8], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4)); uint16_t _s = mem_read16(cpu, cpu->es, (uint16_t)((uint16_t)(cpu->bx + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word es:[bx+0x4] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2), (uint16_t)(cpu->es)); /* mov word ss:[bp+-0x2], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+-0x4], bx */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov dx, word es:[bx+0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    { uint16_t _r = cpu->ax & 0x1; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x1 */
    { uint16_t _r = cpu->dx & 0x0; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* and dx, 0x0 */
    { uint16_t _r = cpu->dx | cpu->ax; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* or dx, ax */
    if (cc_ne(cpu)) goto L_fn_0F5F9_000094;  /* jne 0x0094 */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37BE)); /* mov cx, word ds:[0x37BE] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x37BC)); /* mov bx, word ds:[0x37BC] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC6A(cpu);                           /* call 0000:EC6A */
    if (cc_e(cpu)) goto L_fn_0F5F9_000094;   /* je 0x0094 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+0x4] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov dx, word es:[bx+0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->es, cpu->bx, (uint16_t)(flags_add16(cpu, mem_read16(cpu, cpu->es, cpu->bx), cpu->ax))); /* add word es:[bx], ax */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2), (uint16_t)(flags_adc(cpu, mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2)), cpu->dx, 16))); /* adc word es:[bx+0x2], dx */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x2))); /* mov dx, word ss:[bp+-0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4))); /* mov ax, word ss:[bp+-0x4] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x6), (uint16_t)(cpu->dx)); /* mov word es:[bx+0x6], dx */
    mem_write16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x4), (uint16_t)(cpu->ax)); /* mov word es:[bx+0x4], ax */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x4) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x4] */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6), (uint16_t)(cpu->es)); /* mov word ss:[bp+0x6], es */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(cpu->bx)); /* mov word ss:[bp+0x4], bx */
    goto L_fn_0F5F9_00009F;                  /* jmp 0x009F */
L_fn_0F5F9_000094:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F407(cpu);                           /* call 0xFE0E */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
L_fn_0F5F9_00009F:;
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp - 0x8) + 2)); cpu->bx = _o; cpu->es = _s; } /* les bx, word ss:[bp+-0x8] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->es, (uint16_t)(cpu->bx + 0x2))); /* mov dx, word es:[bx+0x2] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->es, cpu->bx)); /* mov ax, word es:[bx] */
    { uint16_t _r = cpu->ax & 0x1; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x1 */
    { uint16_t _r = cpu->dx & 0x0; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* and dx, 0x0 */
    { uint16_t _r = cpu->dx | cpu->ax; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* or dx, ax */
    if (cc_ne(cpu)) goto L_fn_0F5F9_0000C6;  /* jne 0x00C6 */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x6))); /* push word ss:[bp+-0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp - 0x8))); /* push word ss:[bp+-0x8] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F4A6(cpu);                           /* call 0xFEAD */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x8)); /* add sp, 0x8 */
L_fn_0F5F9_0000C6:;
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F6C3(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F6C3");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _r = cpu->ax | mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* or ax, word ss:[bp+0x6] */
    if (cc_ne(cpu)) goto L_fn_0F6C3_00000D;  /* jne 0x000D */
    goto L_fn_0F6C3_000046;                  /* jmp 0x0046 */
L_fn_0F6C3_00000D:;
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->cx = (uint16_t)(0xFFFF);            /* mov cx, 0xFFFF */
    cpu->bx = (uint16_t)(0xFFF8);            /* mov bx, 0xFFF8 */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0EC0F(cpu);                           /* call 0000:EC0F */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6), (uint16_t)(cpu->dx)); /* mov word ss:[bp+0x6], dx */
    mem_write16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4), (uint16_t)(cpu->ax)); /* mov word ss:[bp+0x4], ax */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    flags_cmp16(cpu, cpu->dx, mem_read16(cpu, cpu->ds, 0x37C2)); /* cmp dx, word ds:[0x37C2] */
    if (cc_ne(cpu)) goto L_fn_0F6C3_00003B;  /* jne 0x003B */
    flags_cmp16(cpu, cpu->ax, mem_read16(cpu, cpu->ds, 0x37C0)); /* cmp ax, word ds:[0x37C0] */
    if (cc_ne(cpu)) goto L_fn_0F6C3_00003B;  /* jne 0x003B */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F51C(cpu);                           /* call 0xFE59 */
    goto L_fn_0F6C3_000046;                  /* jmp 0x0046 */
L_fn_0F6C3_00003B:;
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* push word ss:[bp+0x6] */
    push16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* push word ss:[bp+0x4] */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F5F9(cpu);                           /* call 0xFF36 */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
L_fn_0F6C3_000046:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F70B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F70B");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->ds);                    /* push ds */
    cpu->ah = (uint8_t)(0x3B);               /* mov ah, 0x3B */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ss:[bp+0x4] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    if (cc_b(cpu)) goto L_fn_0F70B_000012;   /* jb 0x0012 */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0F70B_000018;                  /* jmp 0x0018 */
L_fn_0F70B_000012:;
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0E5EB(cpu);                           /* call 0xEEE0 */
    goto L_fn_0F70B_000018;                  /* jmp 0x0018 */
L_fn_0F70B_000018:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F725(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F725");
    cpu->ah = (uint8_t)(0x19);               /* mov ah, 0x19 */
    dos_int21(cpu);                          /* int 0x21 */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    goto L_fn_0F725_000008;                  /* jmp 0x0008 */
L_fn_0F725_000008:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F72E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F72E");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ah = (uint8_t)(0xE);                /* mov ah, 0xE */
    cpu->dl = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov dl, byte ss:[bp+0x4] */
    dos_int21(cpu);                          /* int 0x21 */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    goto L_fn_0F72E_00000E;                  /* jmp 0x000E */
L_fn_0F72E_00000E:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F73E(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F73E");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ah = (uint8_t)(0x35);               /* mov ah, 0x35 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov al, byte ss:[bp+0x4] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ax = (uint16_t)(cpu->bx);           /* mov ax, bx */
    cpu->dx = (uint16_t)(cpu->es);           /* mov dx, es */
    goto L_fn_0F73E_000010;                  /* jmp 0x0010 */
L_fn_0F73E_000010:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F750(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F750");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ah = (uint8_t)(0x25);               /* mov ah, 0x25 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov al, byte ss:[bp+0x4] */
    push16(cpu, cpu->ds);                    /* push ds */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x6) + 2)); cpu->dx = _o; cpu->ds = _s; } /* lds dx, word ss:[bp+0x6] */
    dos_int21(cpu);                          /* int 0x21 */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F799(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F799");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->ds, 0xCAC4, (uint16_t)(cpu->ax)); /* mov word ds:[0xCAC4], ax */
    push16(cpu, SEG_0000);                   /* push cs */
    cpu->ax = (uint16_t)(0xF761);            /* mov ax, 0xF761 */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x24);              /* mov ax, 0x24 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F750(cpu);                           /* call 0xFFB7 */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F7B2(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F7B2");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->sp = (uint16_t)(mem_read16(cpu, cpu->ds, 0xCAC6)); /* mov sp, word ds:[0xCAC6] */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    { int _cf = cf(cpu); cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc sp */
    { int _cf = cf(cpu); cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc sp */
    cpu->sp += 4; cpu->flags = pop16(cpu); return; /* iret */
}

void fn_0F7CD(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F7CD");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = (uint16_t)(0x54);              /* mov ax, 0x54 */
    push16(cpu, cpu->ax);                    /* push ax */
    push16(cpu, 0xFFFF);                     /* near call return addr */
    fn_0F9EF(cpu);                           /* call 0x0222 */
    cpu->sp = (uint16_t)(flags_add16(cpu, cpu->sp, 0x6)); /* add sp, 0x6 */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    cpu->bp = (uint16_t)(mem_read16(cpu, cpu->ds, 0xCAC6)); /* mov bp, word ds:[0xCAC6] */
    cpu->bp = (uint16_t)(flags_add16(cpu, cpu->bp, 0x1A)); /* add bp, 0x1A */
    cpu->sp = (uint16_t)(cpu->bp);           /* mov sp, bp */
    { uint8_t _r = mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x14)) | 0x1; flags_logic8(cpu, _r); mem_write8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x14), (uint8_t)(_r)); } /* or byte ss:[bp+0x14], 0x1 */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    cpu->cx = (uint16_t)(pop16(cpu));        /* pop cx */
    cpu->dx = (uint16_t)(pop16(cpu));        /* pop dx */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->es = (uint16_t)(pop16(cpu));        /* pop es */
    cpu->sp += 4; cpu->flags = pop16(cpu); return; /* iret */
}

void fn_0F7FF(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F7FF");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov dx, word ss:[bp+0x4] */
    cpu->ax = (uint16_t)(port_in16(cpu, cpu->dx)); /* in ax, dx */
    goto L_fn_0F7FF_000009;                  /* jmp 0x0009 */
L_fn_0F7FF_000009:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F80A(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F80A");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov dx, word ss:[bp+0x4] */
    cpu->al = (uint8_t)(port_in8(cpu, cpu->dx)); /* in al, dx */
    { uint8_t _r = cpu->ah ^ cpu->ah; flags_logic8(cpu, _r); cpu->ah = (uint8_t)(_r); } /* xor ah, ah */
    goto L_fn_0F80A_00000B;                  /* jmp 0x000B */
L_fn_0F80A_00000B:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F817(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F817");
    { uint16_t _r = cpu->cx ^ cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* xor cx, cx */
    goto L_fn_0F817_000011;                  /* jmp 0x0011 */
    cpu->cx = (uint16_t)(0x1);               /* mov cx, 0x1 */
    goto L_fn_0F817_000011;                  /* jmp 0x0011 */
    cpu->cx = (uint16_t)(0x2);               /* mov cx, 0x2 */
    goto L_fn_0F817_000011;                  /* jmp 0x0011 */
    cpu->cx = (uint16_t)(0x3);               /* mov cx, 0x3 */
L_fn_0F817_000011:;
    push16(cpu, cpu->bp);                    /* push bp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->di = (uint16_t)(cpu->cx);           /* mov di, cx */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA))); /* mov ax, word ss:[bp+0xA] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xC))); /* mov dx, word ss:[bp+0xC] */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xE))); /* mov bx, word ss:[bp+0xE] */
    cpu->cx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x10))); /* mov cx, word ss:[bp+0x10] */
    { uint16_t _r = cpu->cx | cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* or cx, cx */
    if (cc_ne(cpu)) goto L_fn_0F817_000030;  /* jne 0x0030 */
    { uint16_t _r = cpu->dx | cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* or dx, dx */
    if (cc_e(cpu)) goto L_fn_0F817_000095;   /* je 0x0095 */
    { uint16_t _r = cpu->bx | cpu->bx; flags_logic16(cpu, _r); cpu->bx = (uint16_t)(_r); } /* or bx, bx */
    if (cc_e(cpu)) goto L_fn_0F817_000095;   /* je 0x0095 */
L_fn_0F817_000030:;
    flags_logic16(cpu, cpu->di & 0x1);       /* test di, 0x1 */
    if (cc_ne(cpu)) goto L_fn_0F817_000052;  /* jne 0x0052 */
    { uint16_t _r = cpu->dx | cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* or dx, dx */
    if (cc_ns(cpu)) goto L_fn_0F817_000044;  /* jns 0x0044 */
    cpu->dx = (uint16_t)(flags_sub16(cpu, 0, cpu->dx)); /* neg dx */
    cpu->ax = (uint16_t)(flags_sub16(cpu, 0, cpu->ax)); /* neg ax */
    cpu->dx = (uint16_t)(flags_sbb(cpu, cpu->dx, 0x0, 16)); /* sbb dx, 0x0 */
    { uint16_t _r = cpu->di | 0xC; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* or di, 0xC */
L_fn_0F817_000044:;
    { uint16_t _r = cpu->cx | cpu->cx; flags_logic16(cpu, _r); cpu->cx = (uint16_t)(_r); } /* or cx, cx */
    if (cc_ns(cpu)) goto L_fn_0F817_000052;  /* jns 0x0052 */
    cpu->cx = (uint16_t)(flags_sub16(cpu, 0, cpu->cx)); /* neg cx */
    cpu->bx = (uint16_t)(flags_sub16(cpu, 0, cpu->bx)); /* neg bx */
    cpu->cx = (uint16_t)(flags_sbb(cpu, cpu->cx, 0x0, 16)); /* sbb cx, 0x0 */
    { uint16_t _r = cpu->di ^ 0x4; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, 0x4 */
L_fn_0F817_000052:;
    cpu->bp = (uint16_t)(cpu->cx);           /* mov bp, cx */
    cpu->cx = (uint16_t)(0x20);              /* mov cx, 0x20 */
    push16(cpu, cpu->di);                    /* push di */
    { uint16_t _r = cpu->di ^ cpu->di; flags_logic16(cpu, _r); cpu->di = (uint16_t)(_r); } /* xor di, di */
    { uint16_t _r = cpu->si ^ cpu->si; flags_logic16(cpu, _r); cpu->si = (uint16_t)(_r); } /* xor si, si */
L_fn_0F817_00005C:;
    { uint16_t _v = cpu->ax; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, 0x1 */
    { uint16_t _v = (uint16_t)cpu->dx; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 17; uint64_t _val = (uint64_t)_v | (cf(cpu) ? 0x10000ull : 0ull); uint64_t _r = (((_val << _c) | (_val >> (17 - _c)))) & 0x1FFFFull; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (((_r >> 16) & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ (_r >> 16)) & 1) ? FLAG_OF : 0); cpu->dx = (uint16_t)((uint16_t)_r); } } /* rcl dx, 0x1 */
    { uint16_t _v = (uint16_t)cpu->si; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 17; uint64_t _val = (uint64_t)_v | (cf(cpu) ? 0x10000ull : 0ull); uint64_t _r = (((_val << _c) | (_val >> (17 - _c)))) & 0x1FFFFull; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (((_r >> 16) & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ (_r >> 16)) & 1) ? FLAG_OF : 0); cpu->si = (uint16_t)((uint16_t)_r); } } /* rcl si, 0x1 */
    { uint16_t _v = (uint16_t)cpu->di; uint8_t _n = (0x1) & 0x1F; if (_n) { uint8_t _c = _n % 17; uint64_t _val = (uint64_t)_v | (cf(cpu) ? 0x10000ull : 0ull); uint64_t _r = (((_val << _c) | (_val >> (17 - _c)))) & 0x1FFFFull; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (((_r >> 16) & 1) ? FLAG_CF : 0) | ((((_r >> (16 - 1)) ^ (_r >> 16)) & 1) ? FLAG_OF : 0); cpu->di = (uint16_t)((uint16_t)_r); } } /* rcl di, 0x1 */
    flags_cmp16(cpu, cpu->di, cpu->bp);      /* cmp di, bp */
    if (cc_b(cpu)) goto L_fn_0F817_000073;   /* jb 0x0073 */
    if (cc_a(cpu)) goto L_fn_0F817_00006E;   /* ja 0x006E */
    flags_cmp16(cpu, cpu->si, cpu->bx);      /* cmp si, bx */
    if (cc_b(cpu)) goto L_fn_0F817_000073;   /* jb 0x0073 */
L_fn_0F817_00006E:;
    cpu->si = (uint16_t)(flags_sub16(cpu, cpu->si, cpu->bx)); /* sub si, bx */
    cpu->di = (uint16_t)(flags_sbb(cpu, cpu->di, cpu->bp, 16)); /* sbb di, bp */
    { int _cf = cf(cpu); cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 1)); if (_cf) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; } /* inc ax */
L_fn_0F817_000073:;
    RECOMP_TICK(cpu);
    cpu->cx--; if (cpu->cx != 0) goto L_fn_0F817_00005C; /* loop 0x005C */
    cpu->bx = (uint16_t)(pop16(cpu));        /* pop bx */
    flags_logic16(cpu, cpu->bx & 0x2);       /* test bx, 0x2 */
    if (cc_e(cpu)) goto L_fn_0F817_000082;   /* je 0x0082 */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    cpu->dx = (uint16_t)(cpu->di);           /* mov dx, di */
    { uint16_t _v = cpu->bx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, 0x1 */
L_fn_0F817_000082:;
    flags_logic16(cpu, cpu->bx & 0x4);       /* test bx, 0x4 */
    if (cc_e(cpu)) goto L_fn_0F817_00008F;   /* je 0x008F */
    cpu->dx = (uint16_t)(flags_sub16(cpu, 0, cpu->dx)); /* neg dx */
    cpu->ax = (uint16_t)(flags_sub16(cpu, 0, cpu->ax)); /* neg ax */
    cpu->dx = (uint16_t)(flags_sbb(cpu, cpu->dx, 0x0, 16)); /* sbb dx, 0x0 */
L_fn_0F817_00008F:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    { uint16_t _ip=pop16(cpu); uint16_t _cs=pop16(cpu); cpu->sp += 0x8; if (_ip != 0xFFFF && _ip != 0) recomp_dispatch(cpu,_cs,_ip); return; } /* retf 0x8 */
L_fn_0F817_000095:;
    { uint32_t _n = ((uint32_t)cpu->dx << 16) | cpu->ax; uint16_t _d = cpu->bx; if (_d && _n / _d <= 0xFFFFu) { cpu->ax = (uint16_t)(_n / _d); cpu->dx = (uint16_t)(_n % _d); } else { cpu->cs = SEG_0000; cpu->ip = 0x0095; recomp_div0("div16"); } } /* div bx */
    flags_logic16(cpu, cpu->di & 0x2);       /* test di, 0x2 */
    if (cc_e(cpu)) goto L_fn_0F817_00009F;   /* je 0x009F */
    cpu->ax = (uint16_t)(cpu->dx);           /* mov ax, dx */
L_fn_0F817_00009F:;
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    RECOMP_TICK(cpu);
    goto L_fn_0F817_00008F;                  /* jmp 0x008F */
}

void fn_0F8BA(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F8BA");
    flags_cmp8(cpu, cpu->cl, 0x10);          /* cmp cl, 0x10 */
    if (cc_ae(cpu)) goto L_fn_0F8BA_000015;  /* jae 0x0015 */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    { uint16_t _v = cpu->ax; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->ax = (uint16_t)(_r); } } /* shl ax, cl */
    { uint16_t _v = cpu->dx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shl dx, cl */
    cpu->cl = (uint8_t)(flags_sub8(cpu, 0, cpu->cl)); /* neg cl */
    cpu->cl = (uint8_t)(flags_add8(cpu, cpu->cl, 0x10)); /* add cl, 0x10 */
    { uint16_t _v = cpu->bx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->bx = (uint16_t)(_r); } } /* shr bx, cl */
    { uint16_t _r = cpu->dx | cpu->bx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* or dx, bx */
    { uint16_t _ip=pop16(cpu); uint16_t _cs=pop16(cpu); if (_ip != 0xFFFF && _ip != 0) recomp_dispatch(cpu,_cs,_ip); return; } /* retf */
L_fn_0F8BA_000015:;
    cpu->cl = (uint8_t)(flags_sub8(cpu, cpu->cl, 0x10)); /* sub cl, 0x10 */
    cpu->dx = (uint16_t)(cpu->ax);           /* mov dx, ax */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    { uint16_t _v = cpu->dx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shl dx, cl */
    { uint16_t _ip=pop16(cpu); uint16_t _cs=pop16(cpu); if (_ip != 0xFFFF && _ip != 0) recomp_dispatch(cpu,_cs,_ip); return; } /* retf */
}

void fn_0F8D9(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F8D9");
    push16(cpu, cpu->di);                    /* push di */
    cpu->di = (uint16_t)(cpu->cx);           /* mov di, cx */
    cpu->ch = (uint8_t)(cpu->dh);            /* mov ch, dh */
    cpu->cl = (uint8_t)(0x4);                /* mov cl, 0x4 */
    { uint16_t _v = cpu->dx; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->dx = (uint16_t)(_r); } } /* shl dx, cl */
    { uint8_t _v = cpu->ch; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ch = (uint8_t)(_r); } } /* shr ch, cl */
    cpu->dx = (uint16_t)(flags_add16(cpu, cpu->dx, cpu->ax)); /* add dx, ax */
    cpu->ch = (uint8_t)(flags_adc(cpu, cpu->ch, 0x0, 8)); /* adc ch, 0x0 */
    cpu->ax = (uint16_t)(cpu->di);           /* mov ax, di */
    { uint16_t _v = cpu->di; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v << _c); int _cf = (_c <= 16) ? ((_v >> (16 - _c)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | ((((_r >> (16 - 1)) & 1) ^ _cf) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->di = (uint16_t)(_r); } } /* shl di, cl */
    { uint8_t _v = cpu->ah; uint8_t _c = (cpu->cl) & 0x1F; if (_c) { uint8_t _r = (_c >= 8) ? 0 : (uint8_t)(_v >> _c); int _cf = (_c <= 8) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (8 - 1)) & 1) ? FLAG_OF : 0); flags_shift8(cpu, _r); cpu->ah = (uint8_t)(_r); } } /* shr ah, cl */
    cpu->bx = (uint16_t)(flags_add16(cpu, cpu->bx, cpu->di)); /* add bx, di */
    cpu->ah = (uint8_t)(flags_adc(cpu, cpu->ah, 0x0, 8)); /* adc ah, 0x0 */
    cpu->dx = (uint16_t)(flags_sub16(cpu, cpu->dx, cpu->bx)); /* sub dx, bx */
    cpu->ch = (uint8_t)(flags_sbb(cpu, cpu->ch, cpu->ah, 8)); /* sbb ch, ah */
    cpu->al = (uint8_t)(cpu->ch);            /* mov al, ch */
    cpu->ax = (uint16_t)(int16_t)(int8_t)cpu->al; /* cbw */
    { uint16_t _t = cpu->ax; cpu->ax = (uint16_t)(cpu->dx); cpu->dx = (uint16_t)(_t); } /* xchg ax, dx */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    { uint16_t _ip=pop16(cpu); uint16_t _cs=pop16(cpu); if (_ip != 0xFFFF && _ip != 0) recomp_dispatch(cpu,_cs,_ip); return; } /* retf */
}

void fn_0F8FE(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F8FE");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ax, word ss:[bp+0x4] */
    { uint16_t _r = cpu->dx ^ cpu->dx; flags_logic16(cpu, _r); cpu->dx = (uint16_t)(_r); } /* xor dx, dx */
    mem_write16(cpu, cpu->ds, 0x38FA, (uint16_t)(cpu->dx)); /* mov word ds:[0x38FA], dx */
    mem_write16(cpu, cpu->ds, 0x38F8, (uint16_t)(cpu->ax)); /* mov word ds:[0x38F8], ax */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F90F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F90F");
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ds, 0x38FA)); /* mov dx, word ds:[0x38FA] */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x38F8)); /* mov ax, word ds:[0x38F8] */
    cpu->cx = (uint16_t)(0x15A);             /* mov cx, 0x15A */
    cpu->bx = (uint16_t)(0x4E35);            /* mov bx, 0x4E35 */
    push16(cpu, SEG_0000); push16(cpu, 0xFFFF); /* far call return addr */
    fn_0F2A7(cpu);                           /* call 0000:F2A7 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0x1)); /* add ax, 0x1 */
    cpu->dx = (uint16_t)(flags_adc(cpu, cpu->dx, 0x0, 16)); /* adc dx, 0x0 */
    mem_write16(cpu, cpu->ds, 0x38FA, (uint16_t)(cpu->dx)); /* mov word ds:[0x38FA], dx */
    mem_write16(cpu, cpu->ds, 0x38F8, (uint16_t)(cpu->ax)); /* mov word ds:[0x38F8], ax */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ds, 0x38FA)); /* mov ax, word ds:[0x38FA] */
    { uint16_t _r = cpu->ax & 0x7FFF; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* and ax, 0x7FFF */
    goto L_fn_0F90F_000027;                  /* jmp 0x0027 */
L_fn_0F90F_000027:;
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F937(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F937");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    push16(cpu, cpu->ds);                    /* push ds */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x6) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ss:[bp+0x6] */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0xA)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0xA) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ss:[bp+0xA] */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    { uint16_t _v = cpu->cx; uint8_t _c = (0x1) & 0x1F; if (_c) { uint16_t _r = (_c >= 16) ? 0 : (uint16_t)(_v >> _c); int _cf = (_c <= 16) ? ((_v >> (_c - 1)) & 1) : 0; cpu->flags = (cpu->flags & ~(FLAG_CF | FLAG_OF)) | (_cf ? FLAG_CF : 0) | (((_v >> (16 - 1)) & 1) ? FLAG_OF : 0); flags_shift16(cpu, _r); cpu->cx = (uint16_t)(_r); } } /* shr cx, 0x1 */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsw */
        mem_write16(cpu, cpu->es, cpu->di, mem_read16(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -2 : 2; cpu->di += df(cpu) ? -2 : 2; /* movsw */
    }
    cpu->cx = (uint16_t)(flags_adc(cpu, cpu->cx, cpu->cx, 16)); /* adc cx, cx */
    while (cpu->cx != 0) { cpu->cx--;        /* rep movsb */
        mem_write8(cpu, cpu->es, cpu->di, mem_read8(cpu, cpu->ds, cpu->si)); cpu->si += df(cpu) ? -1 : 1; cpu->di += df(cpu) ? -1 : 1; /* movsb */
    }
    cpu->ds = (uint16_t)(pop16(cpu));        /* pop ds */
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    { uint16_t _ip=pop16(cpu); uint16_t _cs=pop16(cpu); cpu->sp += 0x8; if (_ip != 0xFFFF && _ip != 0) recomp_dispatch(cpu,_cs,_ip); return; } /* retf 0x8 */
}

void fn_0F953(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F953");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->dx = (uint16_t)(cpu->es);           /* mov dx, es */
    cpu->cx = (uint16_t)(cpu->di);           /* mov cx, di */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->di = _o; cpu->es = _s; } /* les di, word ss:[bp+0x4] */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->ax = (uint16_t)((uint16_t)(cpu->bp + 0x4)); /* lea ax, word ss:[bp+0x4] */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = (uint16_t)(cpu->ss);           /* mov ax, ss */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    push16(cpu, (uint16_t)(cpu->flags | 0x0002)); /* pushf */
    cpu->ax = (uint16_t)(pop16(cpu));        /* pop ax */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = (uint16_t)(SEG_0000);          /* mov ax, cs */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x2))); /* mov ax, word ss:[bp+0x2] */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = (uint16_t)(mem_read16(cpu, cpu->ss, cpu->bp)); /* mov ax, word ss:[bp] */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = (uint16_t)(cpu->cx);           /* mov ax, cx */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = (uint16_t)(cpu->dx);           /* mov ax, dx */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = (uint16_t)(cpu->si);           /* mov ax, si */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->ax = (uint16_t)(cpu->ds);           /* mov ax, ds */
    mem_write16(cpu, cpu->es, cpu->di, cpu->ax); cpu->di += df(cpu) ? -2 : 2; /* stosw */
    cpu->es = (uint16_t)(cpu->dx);           /* mov es, dx */
    { uint16_t _r = cpu->ax ^ cpu->ax; flags_logic16(cpu, _r); cpu->ax = (uint16_t)(_r); } /* xor ax, ax */
    goto L_fn_0F953_000034;                  /* jmp 0x0034 */
L_fn_0F953_000034:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F98B(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F98B");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->bx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov bx, word ss:[bp+0x8] */
    flags_cmp16(cpu, cpu->bx, 0x1);          /* cmp bx, 0x1 */
    cpu->bx = (uint16_t)(flags_adc(cpu, cpu->bx, 0x0, 16)); /* adc bx, 0x0 */
    { uint16_t _o = mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)); uint16_t _s = mem_read16(cpu, cpu->ss, (uint16_t)((uint16_t)(cpu->bp + 0x4) + 2)); cpu->si = _o; cpu->ds = _s; } /* lds si, word ss:[bp+0x4] */
    cpu->flags &= ~FLAG_DF;                  /* cld */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ss = (uint16_t)(mem_read16(cpu, cpu->ds, cpu->si)); /* mov ss, word ds:[si] */
    cpu->sp = (uint16_t)(cpu->ax);           /* mov sp, ax */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    push16(cpu, cpu->ax);                    /* push ax */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->bp = (uint16_t)(cpu->ax);           /* mov bp, ax */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->di = (uint16_t)(cpu->ax);           /* mov di, ax */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->es = (uint16_t)(cpu->ax);           /* mov es, ax */
    cpu->ax = mem_read16(cpu, cpu->ds, cpu->si); cpu->si += df(cpu) ? -2 : 2; /* lodsw */
    cpu->ds = (uint16_t)(mem_read16(cpu, cpu->ds, cpu->si)); /* mov ds, word ds:[si] */
    cpu->si = (uint16_t)(cpu->ax);           /* mov si, ax */
    cpu->ax = (uint16_t)(cpu->bx);           /* mov ax, bx */
    cpu->sp += 4; cpu->flags = pop16(cpu); return; /* iret */
}

void fn_0F9BE(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F9BE");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    flags_cmp16(cpu, mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4)), 0xFFFF); /* cmp word ss:[bp+0x4], 0xFFFF */
    if (cc_ne(cpu)) goto L_fn_0F9BE_00000E;  /* jne 0x000E */
    cpu->ax = (uint16_t)(0xFFFF);            /* mov ax, 0xFFFF */
    goto L_fn_0F9BE_00002F;                  /* jmp 0x002F */
L_fn_0F9BE_00000E:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov al, byte ss:[bp+0x4] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->bx = (uint16_t)(cpu->ax);           /* mov bx, ax */
    flags_logic8(cpu, mem_read8(cpu, cpu->ds, (uint16_t)(cpu->bx + 0x37CB)) & 0x8); /* test byte ds:[bx+0x37CB], 0x8 */
    if (cc_e(cpu)) goto L_fn_0F9BE_000028;   /* je 0x0028 */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov al, byte ss:[bp+0x4] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    cpu->ax = (uint16_t)(flags_add16(cpu, cpu->ax, 0xFFE0)); /* add ax, 0xFFE0 */
    goto L_fn_0F9BE_00002F;                  /* jmp 0x002F */
    goto L_fn_0F9BE_00002F;                  /* jmp 0x002F */
L_fn_0F9BE_000028:;
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov al, byte ss:[bp+0x4] */
    cpu->ah = (uint8_t)(0x0);                /* mov ah, 0x0 */
    goto L_fn_0F9BE_00002F;                  /* jmp 0x002F */
L_fn_0F9BE_00002F:;
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0F9EF(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0F9EF");
    push16(cpu, cpu->bp);                    /* push bp */
    cpu->bp = (uint16_t)(cpu->sp);           /* mov bp, sp */
    push16(cpu, cpu->si);                    /* push si */
    push16(cpu, cpu->di);                    /* push di */
    cpu->ah = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x4))); /* mov ah, byte ss:[bp+0x4] */
    cpu->al = (uint8_t)(mem_read8(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x8))); /* mov al, byte ss:[bp+0x8] */
    cpu->dx = (uint16_t)(mem_read16(cpu, cpu->ss, (uint16_t)(cpu->bp + 0x6))); /* mov dx, word ss:[bp+0x6] */
    dos_int21(cpu);                          /* int 0x21 */
    goto L_fn_0F9EF_000012;                  /* jmp 0x0012 */
L_fn_0F9EF_000012:;
    cpu->di = (uint16_t)(pop16(cpu));        /* pop di */
    cpu->si = (uint16_t)(pop16(cpu));        /* pop si */
    cpu->bp = (uint16_t)(pop16(cpu));        /* pop bp */
    cpu->sp += 2; return;                    /* ret */
}

void fn_0FA0F(CPU *cpu)
{
    cpu->cs = SEG_0000;
    RECOMP_ENTER("fn_0FA0F");
}
