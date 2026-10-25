/*
 * vga.c - EGA/VGA model: planar memory with latches and write modes 0-3,
 * sequencer/graphics/CRTC/attribute/DAC registers, INT 10h, and a renderer
 * that turns the current mode into a 640x400 RGBA frame.
 */
#include "runtime.h"
#include "../platform.h"
#include "../font8x8.h"
#include <string.h>
#include <stdlib.h>

static uint8_t g_plane[4][65536];
static uint8_t g_latch[4];
static uint8_t g_seq[8], g_gc[9], g_crtc[32], g_ac[21], g_misc;
static uint8_t g_seq_idx, g_gc_idx, g_crtc_idx, g_ac_idx, g_ac_ff;
static uint8_t g_dac[256][3];
static uint8_t g_dac_mask = 0xFF, g_dac_widx, g_dac_ridx, g_dac_phase, g_dac_rphase, g_dac_rmode;
static int g_mode = 3;
static int g_width = 640, g_height = 400;     /* logical resolution of the current graphics mode */
static int g_text;                            /* 1 = text mode */
static int g_cur_x[8], g_cur_y[8], g_page;
static int g_dirty_gen;

static const uint8_t k_def_ac[16] = {0,1,2,3,4,5,0x14,7,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F};

int vga_mode(void) { return g_mode; }

static void dac_set(int i, int r6, int g6, int b6)
{
    g_dac[i][0] = (uint8_t)(r6 & 63); g_dac[i][1] = (uint8_t)(g6 & 63); g_dac[i][2] = (uint8_t)(b6 & 63);
}

static void dac_default(int is256)
{
    for (int c = 0; c < 64; c++) {
        int r = ((c >> 2) & 1) * 42 + ((c >> 5) & 1) * 21;
        int g = ((c >> 1) & 1) * 42 + ((c >> 4) & 1) * 21;
        int b = (c & 1) * 42 + ((c >> 3) & 1) * 21;
        dac_set(c, r, g, b);
    }
    if (is256) {
        static const uint8_t cga[16][3] = {{0,0,0},{0,0,42},{0,42,0},{0,42,42},{42,0,0},{42,0,42},{42,21,0},{42,42,42},
                                           {21,21,21},{21,21,63},{21,63,21},{21,63,63},{63,21,21},{63,21,63},{63,63,21},{63,63,63}};
        for (int i = 0; i < 16; i++) dac_set(i, cga[i][0], cga[i][1], cga[i][2]);
        for (int i = 16; i < 32; i++) { int v = (i - 16) * 63 / 15; dac_set(i, v, v, v); }
        for (int i = 32; i < 256; i++) dac_set(i, 0, 0, 0);
    } else {
        for (int i = 64; i < 256; i++) dac_set(i, 0, 0, 0);
    }
}

/* ------------------------------------------------------------ memory */

static int chain4(void)  { return (g_seq[4] & 8) != 0; }
static int oddeven(void) { return !(g_seq[4] & 4) && (g_gc[5] & 0x10) && !chain4(); }

static inline uint8_t alu(int fn, uint8_t d, uint8_t l)
{
    switch (fn) { case 1: return d & l; case 2: return d | l; case 3: return d ^ l; default: return d; }
}

int vga_mem_read8(CPU *cpu, uint32_t addr, uint8_t *out)
{
    (void)cpu;
    if (g_text) return 0;
    uint32_t a = addr - 0xA0000u;
    int mm = (g_gc[6] >> 2) & 3;
    if (mm >= 2) return 0;
    if (mm == 1 && a >= 0x10000) return 0;
    uint32_t off; int p;
    if (chain4()) { p = a & 3; off = a >> 2; for (int i = 0; i < 4; i++) g_latch[i] = g_plane[i][off & 0xFFFF]; *out = g_plane[p][off & 0xFFFF]; return 1; }
    if (oddeven()) { p = (a & 1) | (g_gc[4] & 2); off = a >> 1; }
    else { p = g_gc[4] & 3; off = a; }
    off &= 0xFFFF;
    for (int i = 0; i < 4; i++) g_latch[i] = g_plane[i][off];
    if (g_gc[5] & 8) {                                   /* read mode 1: colour compare */
        uint8_t r = 0xFF;
        for (int i = 0; i < 4; i++) {
            if (!((g_gc[7] >> i) & 1)) continue;
            uint8_t cc = ((g_gc[2] >> i) & 1) ? 0xFF : 0x00;
            r &= (uint8_t)~(g_plane[i][off] ^ cc);
        }
        *out = r;
    } else *out = g_plane[p][off];
    return 1;
}

int vga_mem_write8(CPU *cpu, uint32_t addr, uint8_t val)
{
    (void)cpu;
    if (g_text) return 0;
    uint32_t a = addr - 0xA0000u;
    int mm = (g_gc[6] >> 2) & 3;
    if (mm >= 2) return 0;
    if (mm == 1 && a >= 0x10000) return 0;
    g_dirty_gen++;
    if (chain4()) { g_plane[a & 3][(a >> 2) & 0xFFFF] = val; return 1; }
    uint32_t off = a; int mask = g_seq[2] & 15;
    if (oddeven()) { off = a >> 1; mask &= (a & 1) ? 0xA : 0x5; }
    off &= 0xFFFF;
    int wm = g_gc[5] & 3, fn = (g_gc[3] >> 3) & 3, rot = g_gc[3] & 7;
    uint8_t bm = g_gc[8];
    uint8_t rv = rot ? (uint8_t)((val >> rot) | (val << (8 - rot))) : val;
    if (wm == 3) bm &= rv;
    for (int p = 0; p < 4; p++) {
        if (!((mask >> p) & 1)) continue;
        uint8_t d, l = g_latch[p], r;
        switch (wm) {
        case 0: d = ((g_gc[1] >> p) & 1) ? (((g_gc[0] >> p) & 1) ? 0xFF : 0) : rv; r = (uint8_t)((alu(fn, d, l) & bm) | (l & ~bm)); break;
        case 1: r = l; break;
        case 2: d = ((val >> p) & 1) ? 0xFF : 0; r = (uint8_t)((alu(fn, d, l) & bm) | (l & ~bm)); break;
        default: d = ((g_gc[0] >> p) & 1) ? 0xFF : 0; r = (uint8_t)((alu(fn, d, l) & bm) | (l & ~bm)); break;
        }
        g_plane[p][off] = r;
    }
    return 1;
}

/* ------------------------------------------------------------- ports */

int vga_port_in(uint16_t port, uint8_t *out)
{
    switch (port) {
    case 0x3C0: *out = g_ac_idx; return 1;
    case 0x3C1: *out = (g_ac_idx < 21) ? g_ac[g_ac_idx] : 0; return 1;
    case 0x3C4: *out = g_seq_idx; return 1;
    case 0x3C5: *out = g_seq[g_seq_idx & 7]; return 1;
    case 0x3C6: *out = g_dac_mask; return 1;
    case 0x3C7: *out = g_dac_rmode ? 0 : 3; return 1;
    case 0x3C8: *out = g_dac_widx; return 1;
    case 0x3C9: *out = g_dac[g_dac_ridx][g_dac_rphase];
                if (++g_dac_rphase == 3) { g_dac_rphase = 0; g_dac_ridx++; }
                return 1;
    case 0x3CC: *out = g_misc; return 1;
    case 0x3CE: *out = g_gc_idx; return 1;
    case 0x3CF: *out = (g_gc_idx < 9) ? g_gc[g_gc_idx] : 0; return 1;
    case 0x3D4: case 0x3B4: *out = g_crtc_idx; return 1;
    case 0x3D5: case 0x3B5: *out = (g_crtc_idx < 32) ? g_crtc[g_crtc_idx] : 0; return 1;
    case 0x3DA: case 0x3BA: {
        uint64_t us = plat_ticks_us();
        uint32_t ph = (uint32_t)(us % 14286u);                     /* ~70 Hz frame */
        uint8_t v = 0;
        if (ph >= 13000) v |= 8;                                   /* vertical retrace */
        if (ph >= 13000 || (us % 32u) >= 24u) v |= 1;              /* display disabled (retrace / hblank) */
        g_ac_ff = 0;
        *out = v; return 1; }
    default: return 0;
    }
}

int vga_port_out(uint16_t port, uint8_t v)
{
    switch (port) {
    case 0x3C0:
        if (!g_ac_ff) { g_ac_idx = v & 0x1F; }
        else if ((g_ac_idx & 0x1F) < 21) { g_ac[g_ac_idx & 0x1F] = v; g_dirty_gen++; }
        g_ac_ff ^= 1; return 1;
    case 0x3C2: g_misc = v; return 1;
    case 0x3C4: g_seq_idx = v; return 1;
    case 0x3C5: g_seq[g_seq_idx & 7] = v; g_dirty_gen++; return 1;
    case 0x3C6: g_dac_mask = v; return 1;
    case 0x3C7: g_dac_ridx = v; g_dac_rphase = 0; g_dac_rmode = 0; return 1;
    case 0x3C8: g_dac_widx = v; g_dac_phase = 0; return 1;
    case 0x3C9: {
        static uint8_t tmp[3];
        tmp[g_dac_phase++] = v & 63;
        if (g_dac_phase == 3) { memcpy(g_dac[g_dac_widx], tmp, 3); g_dac_widx++; g_dac_phase = 0; g_dirty_gen++; }
        return 1; }
    case 0x3CE: g_gc_idx = v; return 1;
    case 0x3CF: if (g_gc_idx < 9) g_gc[g_gc_idx] = v; g_dirty_gen++; return 1;
    case 0x3D4: case 0x3B4: g_crtc_idx = v & 0x1F; return 1;
    case 0x3D5: case 0x3B5: g_crtc[g_crtc_idx] = v; g_dirty_gen++; return 1;
    case 0x3DA: case 0x3C1: case 0x3CC: case 0x3CA: case 0x3BA: return 1;
    default: return 0;
    }
}

/* -------------------------------------------------------------- modes */

void vga_set_mode(CPU *cpu, int mode, int clear)
{
    mode &= 0x7F;
    g_mode = mode;
    g_text = (mode <= 3 || mode == 7);
    memset(g_seq, 0, sizeof g_seq); memset(g_gc, 0, sizeof g_gc);
    memset(g_crtc, 0, sizeof g_crtc); memset(g_ac, 0, sizeof g_ac);
    g_seq[2] = 0x0F; g_gc[8] = 0xFF; g_ac_ff = 0;
    for (int i = 0; i < 16; i++) g_ac[i] = k_def_ac[i];
    g_ac[0x12] = 0x0F;
    g_crtc[0x13] = 40;
    g_dac_mask = 0xFF;
    memset(g_latch, 0, 4);

    switch (mode) {
    case 0: case 1: case 2: case 3: case 7:
        g_width = 640; g_height = 400; g_seq[4] = 3; g_gc[6] = 0x0E; g_gc[5] = 0x10; g_crtc[0x13] = 40; g_ac[0x10] = 0x08;
        dac_default(0); break;
    case 0x0D: g_width = 320; g_height = 200; g_seq[4] = 6; g_gc[6] = 0x05; g_crtc[9] = 0x00; g_crtc[0x13] = 20; g_ac[0x10] = 0x01; dac_default(0); break;
    case 0x0E: g_width = 640; g_height = 200; g_seq[4] = 6; g_gc[6] = 0x05; g_crtc[9] = 0x00; g_crtc[0x13] = 40; g_ac[0x10] = 0x01; dac_default(0); break;
    case 0x10: g_width = 640; g_height = 350; g_seq[4] = 6; g_gc[6] = 0x05; g_crtc[0x13] = 40; g_ac[0x10] = 0x01; dac_default(0); break;
    case 0x12: g_width = 640; g_height = 480; g_seq[4] = 6; g_gc[6] = 0x05; g_crtc[0x13] = 40; g_ac[0x10] = 0x01; dac_default(0); break;
    case 0x13: g_width = 320; g_height = 200; g_seq[4] = 0x0E; g_gc[5] = 0x40; g_gc[6] = 0x05; g_crtc[0x13] = 40; g_ac[0x10] = 0x41; dac_default(1); break;
    default:   g_width = 320; g_height = 200; g_seq[4] = 6; g_gc[6] = 0x05; g_crtc[0x13] = 20; g_ac[0x10] = 0x01; dac_default(0); break;
    }
    for (int i = 0; i < 8; i++) g_cur_x[i] = g_cur_y[i] = 0;
    g_page = 0;
    cpu->mem[0x449] = (uint8_t)mode;
    cpu->mem[0x44A] = 80; cpu->mem[0x44B] = 0;
    cpu->mem[0x462] = 0;
    if (clear) {
        memset(g_plane, 0, sizeof g_plane);
        if (g_text) for (int i = 0; i < 4000; i += 2) { cpu->mem[0xB8000 + i] = ' '; cpu->mem[0xB8000 + i + 1] = 0x07; }
    }
    g_dirty_gen++;
}

void vga_init(CPU *cpu) { dac_default(0); vga_set_mode(cpu, 3, 1); }

/* ------------------------------------------------------ text helpers */

static uint8_t *tcell(CPU *cpu, int x, int y) { return &cpu->mem[0xB8000 + g_page * 4096 + (y * 80 + x) * 2]; }

static void tscroll(CPU *cpu, int lines, int top, int left, int bot, int right, uint8_t attr, int down)
{
    if (!g_text) return;
    int h = bot - top + 1, w = right - left + 1;
    if (lines == 0 || lines >= h) { for (int y = top; y <= bot; y++) for (int x = left; x <= right; x++) { uint8_t *c = tcell(cpu, x, y); c[0] = ' '; c[1] = attr; } return; }
    if (!down) {
        for (int y = top; y <= bot - lines; y++) memmove(tcell(cpu, left, y), tcell(cpu, left, y + lines), (size_t)w * 2);
        for (int y = bot - lines + 1; y <= bot; y++) for (int x = left; x <= right; x++) { uint8_t *c = tcell(cpu, x, y); c[0] = ' '; c[1] = attr; }
    } else {
        for (int y = bot; y >= top + lines; y--) memmove(tcell(cpu, left, y), tcell(cpu, left, y - lines), (size_t)w * 2);
        for (int y = top; y < top + lines; y++) for (int x = left; x <= right; x++) { uint8_t *c = tcell(cpu, x, y); c[0] = ' '; c[1] = attr; }
    }
}

/* plot a pixel in the current graphics mode (INT 10h/0C and teletype in gfx) */
static void gplot(int x, int y, uint8_t col)
{
    if (x < 0 || y < 0 || x >= g_width || y >= g_height) return;
    int stride = g_crtc[0x13] * 2;
    if (g_mode == 0x13) { g_plane[x & 3][(y * stride + (x >> 2)) & 0xFFFF] = col; return; }
    uint32_t off = (uint32_t)(y * stride + (x >> 3)) & 0xFFFF; uint8_t bit = (uint8_t)(0x80 >> (x & 7));
    for (int p = 0; p < 4; p++) { if ((col >> p) & 1) g_plane[p][off] |= bit; else g_plane[p][off] &= (uint8_t)~bit; }
}

static uint8_t gread(int x, int y)
{
    int stride = g_crtc[0x13] * 2;
    if (x < 0 || y < 0 || x >= g_width || y >= g_height) return 0;
    if (g_mode == 0x13) return g_plane[x & 3][(y * stride + (x >> 2)) & 0xFFFF];
    uint32_t off = (uint32_t)(y * stride + (x >> 3)) & 0xFFFF; uint8_t bit = (uint8_t)(0x80 >> (x & 7)), c = 0;
    for (int p = 0; p < 4; p++) if (g_plane[p][off] & bit) c |= (uint8_t)(1 << p);
    return c;
}

static void gchar(CPU *cpu, uint8_t ch, uint8_t col, int cx, int cy)
{
    (void)cpu;
    for (int r = 0; r < 8; r++) for (int b = 0; b < 8; b++)
        if (font8x8_cp437[ch][r] & (0x80 >> b)) gplot(cx * 8 + b, cy * 8 + r, col);
    g_dirty_gen++;
}

void vga_text_putc(CPU *cpu, uint8_t ch)
{
    int cols = g_text ? 80 : g_width / 8, rows = g_text ? 25 : g_height / 8;
    int *x = &g_cur_x[g_page], *y = &g_cur_y[g_page];
    if (ch == 7) return;
    if (ch == 8) { if (*x > 0) (*x)--; }
    else if (ch == 13) *x = 0;
    else if (ch == 10) (*y)++;
    else {
        if (g_text) { uint8_t *c = tcell(cpu, *x, *y); c[0] = ch; }
        else gchar(cpu, ch, 15, *x, *y);
        if (++(*x) >= cols) { *x = 0; (*y)++; }
    }
    if (*y >= rows) {
        *y = rows - 1;
        if (g_text) tscroll(cpu, 1, 0, 0, 24, 79, 0x07, 0);
    }
}

/* ------------------------------------------------------------ INT 10h */

void vga_int10(CPU *cpu)
{
    switch (cpu->ah) {
    case 0x00: vga_set_mode(cpu, cpu->al, !(cpu->al & 0x80)); break;
    case 0x01: break;
    case 0x02: if (cpu->bh < 8) { g_cur_y[cpu->bh] = cpu->dh; g_cur_x[cpu->bh] = cpu->dl; } break;
    case 0x03: cpu->dh = (uint8_t)g_cur_y[cpu->bh & 7]; cpu->dl = (uint8_t)g_cur_x[cpu->bh & 7]; cpu->cx = 0x0607; break;
    case 0x05: g_page = cpu->al & 7; cpu->mem[0x462] = (uint8_t)g_page; break;
    case 0x06: tscroll(cpu, cpu->al, cpu->ch, cpu->cl, cpu->dh, cpu->dl, cpu->bh, 0); break;
    case 0x07: tscroll(cpu, cpu->al, cpu->ch, cpu->cl, cpu->dh, cpu->dl, cpu->bh, 1); break;
    case 0x08:
        if (g_text) { uint8_t *c = tcell(cpu, g_cur_x[g_page], g_cur_y[g_page]); cpu->al = c[0]; cpu->ah = c[1]; }
        else { cpu->al = ' '; cpu->ah = 0; }
        break;
    case 0x09: case 0x0A:
        for (int i = 0; i < cpu->cx; i++) {
            int x = g_cur_x[g_page] + i;
            if (g_text) { if (x < 80) { uint8_t *c = tcell(cpu, x, g_cur_y[g_page]); c[0] = cpu->al; if (cpu->ah == 0x09) c[1] = cpu->bl; } }
            else gchar(cpu, cpu->al, cpu->bl & 0xFF ? cpu->bl : 15, x, g_cur_y[g_page]);
        }
        break;
    case 0x0B: if (cpu->bh == 0) { g_ac[0x11] = cpu->bl; } break;
    case 0x0C: gplot(cpu->cx, cpu->dx, cpu->al); g_dirty_gen++; break;
    case 0x0D: cpu->al = gread(cpu->cx, cpu->dx); break;
    case 0x0E: vga_text_putc(cpu, cpu->al); break;
    case 0x0F: cpu->al = (uint8_t)g_mode; cpu->ah = (uint8_t)(g_text ? 80 : g_width / 8); cpu->bh = (uint8_t)g_page; break;
    case 0x10:
        switch (cpu->al) {
        case 0x00: if (cpu->bl < 16) g_ac[cpu->bl] = cpu->bh; break;
        case 0x01: g_ac[0x11] = cpu->bh; break;
        case 0x02: for (int i = 0; i < 16; i++) g_ac[i] = mem_read8(cpu, cpu->es, (uint16_t)(cpu->dx + i)); g_ac[0x11] = mem_read8(cpu, cpu->es, (uint16_t)(cpu->dx + 16)); break;
        case 0x03: if (cpu->bl & 1) g_ac[0x10] |= 8; else g_ac[0x10] &= (uint8_t)~8; break;
        case 0x07: cpu->bh = g_ac[cpu->bl & 15]; break;
        case 0x08: cpu->bh = g_ac[0x11]; break;
        case 0x10: dac_set(cpu->bx & 255, cpu->dh, cpu->ch, cpu->cl); break;
        case 0x12: for (int i = 0; i < cpu->cx; i++) { int o = cpu->dx + i * 3;
                       dac_set((cpu->bx + i) & 255, mem_read8(cpu, cpu->es, (uint16_t)o), mem_read8(cpu, cpu->es, (uint16_t)(o + 1)), mem_read8(cpu, cpu->es, (uint16_t)(o + 2))); } break;
        case 0x15: cpu->dh = g_dac[cpu->bx & 255][0]; cpu->ch = g_dac[cpu->bx & 255][1]; cpu->cl = g_dac[cpu->bx & 255][2]; break;
        case 0x17: for (int i = 0; i < cpu->cx; i++) for (int k = 0; k < 3; k++) mem_write8(cpu, cpu->es, (uint16_t)(cpu->dx + i * 3 + k), g_dac[(cpu->bx + i) & 255][k]); break;
        default: break;
        }
        g_dirty_gen++;
        break;
    case 0x11: break;
    case 0x12:
        if (cpu->bl == 0x10) { cpu->bh = 0; cpu->bl = 3; cpu->cx = 0x0009; }
        break;
    case 0x1A:
        if (cpu->al == 0) { cpu->al = 0x1A; cpu->bl = 8; cpu->bh = 0; }
        break;
    default: break;
    }
}

/* ------------------------------------------------------------ renderer */

static uint32_t dac_rgb(int idx)
{
    idx &= g_dac_mask;
    uint32_t r = g_dac[idx][0], g = g_dac[idx][1], b = g_dac[idx][2];
    r = (r << 2) | (r >> 4); g = (g << 2) | (g >> 4); b = (b << 2) | (b >> 4);
    return 0xFF000000u | (r << 16) | (g << 8) | b;
}

static uint32_t g_prev[640 * 400];
static uint32_t g_cur[640 * 400];

static void render_text(CPU *cpu)
{
    uint32_t pal[16];
    for (int i = 0; i < 16; i++) pal[i] = dac_rgb(g_ac[i] & 0x3F);
    int blink_on = (plat_ticks_ms() / 500) & 1;
    for (int cy = 0; cy < 25; cy++) for (int cx = 0; cx < 80; cx++) {
        const uint8_t *c = tcell(cpu, cx, cy);
        int fg = c[1] & 15, bg = (c[1] >> 4) & 7;
        if ((g_ac[0x10] & 8)) { if ((c[1] & 0x80) && !blink_on) fg = bg; }
        else bg = (c[1] >> 4) & 15;
        for (int r = 0; r < 16; r++) {
            uint8_t bits = font8x8_cp437[c[0]][r >> 1];
            uint32_t *dst = &g_cur[(cy * 16 + r) * 640 + cx * 8];
            for (int b = 0; b < 8; b++) dst[b] = pal[(bits & (0x80 >> b)) ? fg : bg];
        }
    }
}

static void render_gfx(void)
{
    int stride = g_crtc[0x13] * 2;
    if (stride == 0) stride = 80;
    uint32_t start = ((uint32_t)g_crtc[0x0C] << 8) | g_crtc[0x0D];
    int dbl = (g_crtc[9] & 0x80) != 0;
    int lc = g_crtc[0x18] | ((g_crtc[7] & 0x10) << 4) | ((g_crtc[9] & 0x40) << 3);
    int is256 = (g_ac[0x10] & 0x40) || chain4() || (g_gc[5] & 0x40);
    int vscale = 400 / g_height; if (vscale < 1) vscale = 1;
    int hscale = 640 / g_width;  if (hscale < 1) hscale = 1;
    int rows = g_height; if (rows * vscale > 400) rows = 400 / vscale;
    uint32_t pal[16]; uint8_t plane_en = g_ac[0x12] & 15;
    uint8_t cs = g_ac[0x14], mc = g_ac[0x10];
    for (int i = 0; i < 16; i++) {
        int v = g_ac[i] & 0x3F;
        if (mc & 0x80) v = (v & 0x0F) | ((cs & 3) << 4);
        v |= (cs & 0x0C) << 4;
        pal[i] = dac_rgb(v);
    }
    uint32_t border = dac_rgb(g_ac[0x11]);
    for (int i = 0; i < 640 * 400; i++) g_cur[i] = border;
    int scan_div = dbl ? 2 : 1;
    for (int y = 0; y < rows; y++) {
        /* line compare: scanlines at/after it restart at address 0 */
        int sl = y * (dbl ? 1 : 1);
        uint32_t base = (lc < 0x3FF && (sl * scan_div) > lc) ? (uint32_t)(((sl * scan_div) - lc - 1) / scan_div) * stride : start + (uint32_t)y * stride;
        for (int x = 0; x < g_width; x++) {
            uint32_t px;
            if (is256) {
                uint8_t v = g_plane[x & 3][(base + (x >> 2)) & 0xFFFF];
                px = dac_rgb(v);
            } else {
                uint32_t off = (base + (x >> 3)) & 0xFFFF; uint8_t bit = (uint8_t)(0x80 >> (x & 7)); int idx = 0;
                for (int p = 0; p < 4; p++) if (g_plane[p][off] & bit) idx |= 1 << p;
                px = pal[idx & plane_en];
            }
            for (int vy = 0; vy < vscale; vy++) {
                uint32_t *dst = &g_cur[(y * vscale + vy) * 640 + x * hscale];
                for (int hx = 0; hx < hscale; hx++) dst[hx] = px;
            }
        }
    }
}

int vga_render(CPU *cpu, uint32_t *rgba, int force)
{
    if (g_text) render_text(cpu); else render_gfx();
    int changed = force || memcmp(g_cur, g_prev, sizeof g_cur) != 0;
    if (changed) { memcpy(g_prev, g_cur, sizeof g_cur); memcpy(rgba, g_cur, sizeof g_cur); }
    return changed;
}
