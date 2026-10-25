/*
 * runtime.c - a small PC/DOS machine for the lifted Ancient Empires code.
 *
 * Provides: MZ image loader + PSP, DOS memory manager, INT 21h file/console
 * services, BIOS INT 11h/12h/13h/15h/16h/1Ah, IRQ0 delivery to the guest's
 * hooked timer handler, keyboard queue, PIT + PC speaker, indirect dispatch.
 * Video lives in vga.c; the window/audio/events live in platform_sdl.c.
 */
#include "runtime.h"
#include "../platform.h"
#include "../opl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>

#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#else
#include <dirent.h>
#include <strings.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

#ifdef _WIN32
#define strcasecmp _stricmp
#define strtok_r_compat(s, d, sv) strtok_s((s), (d), (sv))
#else
#define strtok_r_compat(s, d, sv) strtok_r((s), (d), (sv))
#endif

/* generated dispatch table (recomp_dispatch.c) */
typedef void (*recomp_fn)(CPU *);
typedef struct { unsigned addr; recomp_fn fn; } DispEntry;
extern const DispEntry g_disp[];
extern const int g_disp_count;
extern void fn_00000(CPU *cpu);
extern const unsigned g_ovl_lo, g_ovl_hi;
extern const unsigned char g_ovl_sig[48];
extern const DispEntry g_ovl_disp[];
extern const int g_ovl_count;

int g_recomp_tick_budget = 1;

static uint8_t *g_img_orig;      /* pristine relocated image, to spot runtime code changes */
static unsigned g_img_len;
static CPU g_cpu;
static RtConfig g_cfg;
static char g_game_dir[512] = ".";
static int  g_quit_requested;
static int  g_exited;

/* ------------------------------------------------------------------ misc */

static void rt_log(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}

uint32_t rt_now_ms(void) { return plat_ticks_ms(); }

void recomp_div0(const char *kind)
{
    static int n;
    if (n++ < 8) rt_log("[rt] divide error (%s)\n", kind ? kind : "?");
}

/* ------------------------------------------------------- entry trace */
#ifdef RECOMP_TRACE
#include <signal.h>
static const char *g_ring[128];
static unsigned g_ring_n;
static const char *g_seen[2048];
static int g_seen_log;
static const char *recomp_last_fn(void) { const char *a = g_ring[(g_ring_n - 1) & 127], *b = g_ring[(g_ring_n - 2) & 127]; static char buf[64]; snprintf(buf, sizeof buf, "%s<-%s", a ? a : "?", b ? b : "?"); return buf; }
void recomp_enter(const char *fn)
{
    g_ring[g_ring_n++ & 127] = fn;
    if (!g_seen_log) return;
    unsigned h = (unsigned)(((uintptr_t)fn >> 3) * 2654435761u) & 2047;
    while (g_seen[h]) { if (g_seen[h] == fn) return; h = (h + 1) & 2047; }
    g_seen[h] = fn;
    fprintf(stderr, "[first] %s\n", fn);
}
void recomp_trace_dump(const char *why)
{
    fprintf(stderr, "[trace] %s; last functions entered (oldest first):\n", why);
    for (unsigned i = 0; i < 128; i++) {
        const char *n = g_ring[(g_ring_n + i) & 127];
        if (n) fprintf(stderr, "  %s\n", n);
    }
}
static void on_segv(int sig) { (void)sig; recomp_trace_dump("fatal signal"); _exit(139); }
#endif

/* ------------------------------------------------------------ dispatch */

#define MAX_MISS 512
static unsigned g_miss[MAX_MISS];
static int g_nmiss;

static void note_miss(unsigned addr)
{
    for (int i = 0; i < g_nmiss; i++) if (g_miss[i] == addr) return;
    if (g_nmiss < MAX_MISS) {
        g_miss[g_nmiss++] = addr;
        rt_log("[rt] dispatch miss: image offset 0x%05X\n", addr);
#ifdef RECOMP_TRACE
        if (addr == 0xFFFF) recomp_trace_dump("dispatch to 0xFFFF");
#endif
        FILE *mf = fopen("misses.txt", "a");        /* append now: a later crash must not lose it */
        if (mf) { fprintf(mf, "%05X\n", addr); fclose(mf); }
    }
}

static const DispEntry *disp_find(unsigned addr)
{
    int lo = 0, hi = g_disp_count - 1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (g_disp[mid].addr == addr) return &g_disp[mid];
        if (g_disp[mid].addr < addr) lo = mid + 1; else hi = mid - 1;
    }
    return NULL;
}

/* The driver overlay: look up addr in the lifted driver, but only while the
 * bytes in memory are the driver that was lifted. */
static int ovl_run(CPU *cpu, unsigned addr)
{
    static int warned;
    if (!g_ovl_count || memcmp(cpu->mem + RT_IMG_LIN + g_ovl_lo, g_ovl_sig, sizeof g_ovl_sig) != 0) {
        if (!warned++) rt_log("[rt] the video driver loaded in memory is not the one that was lifted (call to 0x%04X)\n", addr);
        return 0;
    }
    int lo = 0, hi = g_ovl_count - 1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (g_ovl_disp[mid].addr == addr) { g_ovl_disp[mid].fn(cpu); return 1; }
        if (g_ovl_disp[mid].addr < addr) lo = mid + 1; else hi = mid - 1;
    }
    note_miss(addr);
    return 0;
}

void ovl_call(CPU *cpu, unsigned addr)
{
    /* the lifted caller already pushed its dummy return word; a driver
     * function ends with a plain C return. */
    if (!ovl_run(cpu, addr)) (void)pop16(cpu);
}

/* Run whatever lives at seg:off. Returns 1 if something ran. */
static int dispatch_any(CPU *cpu, unsigned seg, unsigned off)
{
    unsigned addr;
    seg &= 0xFFFF; off &= 0xFFFF;
    if (seg >= 0xC000) {            /* BIOS ROM: default vector. IRET-equivalent. */
        cpu->sp = (uint16_t)(cpu->sp + 6);
        return 1;
    }
    if (seg >= RT_LOAD_SEG) addr = ((seg << 4) + off) - RT_IMG_LIN;
    else                    addr = (seg << 4) + off;       /* image-space */
    if (addr >= g_ovl_lo && addr < g_ovl_hi) return ovl_run(cpu, addr);
    const DispEntry *e = disp_find(addr);
    if (!e) { note_miss(addr); return 0; }
    e->fn(cpu);
    return 1;
}

int recomp_dispatch(CPU *cpu, unsigned seg, unsigned off)
{
    return dispatch_any(cpu, seg, off);
}

void dispatch_near(CPU *cpu, unsigned seg, unsigned off)
{
    if (!dispatch_any(cpu, seg, off)) (void)pop16(cpu);     /* drop dummy return word */
}

void dispatch_far(CPU *cpu, unsigned seg, unsigned off)
{
    if (!dispatch_any(cpu, seg, off)) { (void)pop16(cpu); (void)pop16(cpu); }
}

/* ------------------------------------------------------------------ IVT */

static void ivt_get(CPU *cpu, int vec, uint16_t *seg, uint16_t *off)
{
    *off = (uint16_t)(cpu->mem[vec * 4] | (cpu->mem[vec * 4 + 1] << 8));
    *seg = (uint16_t)(cpu->mem[vec * 4 + 2] | (cpu->mem[vec * 4 + 3] << 8));
}

static void ivt_set(CPU *cpu, int vec, uint16_t seg, uint16_t off)
{
    cpu->mem[vec * 4] = (uint8_t)off;     cpu->mem[vec * 4 + 1] = (uint8_t)(off >> 8);
    cpu->mem[vec * 4 + 2] = (uint8_t)seg; cpu->mem[vec * 4 + 3] = (uint8_t)(seg >> 8);
}

/* Deliver a hardware interrupt to a guest-installed handler (if any). The
 * whole CPU is saved and restored around it, so a handler that is sloppy about
 * registers cannot corrupt the interrupted code. */
static int g_in_irq;
static unsigned g_irq_count, g_irq_skip_if;

static void deliver_irq(CPU *cpu, int vec)
{
    uint16_t seg, off;
    if (g_in_irq) return;
    if (!(cpu->flags & FLAG_IF)) { g_irq_skip_if++; return; }
    ivt_get(cpu, vec, &seg, &off);
    if (seg >= 0xC000 || seg == 0) return;                  /* BIOS default: nothing to run */
    CPU saved = *cpu;
    g_irq_count++;
    g_in_irq = 1;
    push16(cpu, cpu->flags);
    push16(cpu, 0xFFFF);                                    /* CS slot: sentinel */
    push16(cpu, 0xFFFF);                                    /* IP slot: sentinel */
    cpu->flags &= ~FLAG_IF;
    dispatch_any(cpu, seg, off);
    g_in_irq = 0;
    *cpu = saved;
}

/* ---------------------------------------------------------------- BDA */

#define BDA(off)       (cpu->mem[0x400 + (off)])
static void bda_w16(CPU *cpu, int off, uint16_t v) { cpu->mem[0x400 + off] = (uint8_t)v; cpu->mem[0x401 + off] = (uint8_t)(v >> 8); }
static uint16_t bda_r16(CPU *cpu, int off) { return (uint16_t)(cpu->mem[0x400 + off] | (cpu->mem[0x401 + off] << 8)); }
static uint32_t bda_r32(CPU *cpu, int off) { return bda_r16(cpu, off) | ((uint32_t)bda_r16(cpu, off + 2) << 16); }
static void bda_w32(CPU *cpu, int off, uint32_t v) { bda_w16(cpu, off, (uint16_t)v); bda_w16(cpu, off + 2, (uint16_t)(v >> 16)); }

/* ------------------------------------------------------- PIT / speaker */

static uint16_t g_pit_div[3] = { 0, 0, 0 };   /* 0 = 65536 */
static uint8_t  g_pit_mode_lohi[3] = { 3, 3, 3 };
static int      g_pit_phase[3];               /* which byte of the divisor comes next */
static uint8_t  g_pit_lo[3];
static uint8_t  g_p61;
static int      g_spk_hz;

static uint32_t pit_divisor(int ch) { return g_pit_div[ch] ? g_pit_div[ch] : 65536u; }

static void speaker_update(void)
{
    int hz = 0;
    if ((g_p61 & 3) == 3) {
        uint32_t d = pit_divisor(2);
        hz = (int)(1193182u / d);
        if (hz < 20 || hz > 20000) hz = 0;
    }
    if (hz != g_spk_hz) { g_spk_hz = hz; plat_speaker(hz); if (g_cfg.trace) rt_log("[snd] speaker %d Hz\n", hz); }
}

/* ---- audio capture (testing aid; --wav) ---- */
static FILE *g_wav; static uint64_t g_wav_t0, g_wav_n; static double g_wav_ph;
static void wav_capture(uint64_t us)
{
    if (!g_cfg.wav_path) return;
    if (!g_wav) {
        g_wav = fopen(g_cfg.wav_path, "wb"); if (!g_wav) { g_cfg.wav_path = NULL; return; }
        uint8_t h[44] = {0}; fwrite(h, 1, 44, g_wav); g_wav_t0 = us;
    }
    uint64_t want = (us - g_wav_t0) * 44100 / 1000000;
    while (g_wav_n < want) {
        int n = (int)(want - g_wav_n); if (n > 1024) n = 1024;
        int32_t acc[1024]; int16_t out[1024];
        for (int i = 0; i < n; i++) {
            int32_t v = 0;
            if (g_spk_hz) { g_wav_ph += (double)g_spk_hz / 44100.0; if (g_wav_ph >= 1.0) g_wav_ph -= 1.0; v = g_wav_ph < 0.5 ? 4000 : -4000; }
            acc[i] = v;
        }
        opl_mix(acc, n, 44100);
        for (int i = 0; i < n; i++) out[i] = acc[i] > 32767 ? 32767 : acc[i] < -32768 ? -32768 : (int16_t)acc[i];
        fwrite(out, 2, n, g_wav); g_wav_n += n;
    }
}
static void wav_finish(void)
{
    if (!g_wav) return;
    uint32_t data = (uint32_t)(g_wav_n * 2), riff = data + 36, rate = 44100, brate = 88200, fmt = 16;
    uint16_t pcm = 1, ch = 1, align = 2, bits = 16;
    fseek(g_wav, 0, SEEK_SET);
    fwrite("RIFF", 1, 4, g_wav); fwrite(&riff, 4, 1, g_wav); fwrite("WAVEfmt ", 1, 8, g_wav); fwrite(&fmt, 4, 1, g_wav);
    fwrite(&pcm, 2, 1, g_wav); fwrite(&ch, 2, 1, g_wav); fwrite(&rate, 4, 1, g_wav); fwrite(&brate, 4, 1, g_wav);
    fwrite(&align, 2, 1, g_wav); fwrite(&bits, 2, 1, g_wav); fwrite("data", 1, 4, g_wav); fwrite(&data, 4, 1, g_wav);
    fclose(g_wav); g_wav = NULL;
}

void rt_speaker(int hz) { g_spk_hz = hz; plat_speaker(hz); }

static void pit_write(int ch, uint8_t v)
{
    switch (g_pit_mode_lohi[ch]) {
    case 1: g_pit_div[ch] = v; break;                          /* lo only */
    case 2: g_pit_div[ch] = (uint16_t)(v << 8); break;         /* hi only */
    default:
        if (g_pit_phase[ch] == 0) { g_pit_lo[ch] = v; g_pit_phase[ch] = 1; return; }
        g_pit_div[ch] = (uint16_t)(g_pit_lo[ch] | (v << 8));
        g_pit_phase[ch] = 0;
    }
    if (ch == 2) speaker_update();
}

/* --------------------------------------------------------- keyboard */

#define KQ 64
static uint16_t g_kq[KQ];
static int g_kq_h, g_kq_t;
static uint8_t g_scan_latch;
static uint8_t g_shift_flags;          /* BDA 0x417 bits */

static int kq_count(void) { return (g_kq_t - g_kq_h + KQ) % KQ; }
static void kq_push(uint16_t k) { int n = (g_kq_t + 1) % KQ; if (n != g_kq_h) { g_kq[g_kq_t] = k; g_kq_t = n; } }
static int kq_pop(uint16_t *k) { if (g_kq_h == g_kq_t) return 0; *k = g_kq[g_kq_h]; g_kq_h = (g_kq_h + 1) % KQ; return 1; }

void rt_key_event(int scan, int ascii, int down)
{
    g_scan_latch = (uint8_t)(scan | (down ? 0 : 0x80));
    /* shift/ctrl/alt state, for INT 16h/02 */
    {
        uint8_t bit = 0;
        if (scan == 0x2A) bit = 0x02; else if (scan == 0x36) bit = 0x01;
        else if (scan == 0x1D) bit = 0x04; else if (scan == 0x38) bit = 0x08;
        if (bit) { if (down) g_shift_flags |= bit; else g_shift_flags &= (uint8_t)~bit; }
    }
    if (down && scan != 0x2A && scan != 0x36 && scan != 0x1D && scan != 0x38)
        kq_push((uint16_t)((scan << 8) | (ascii & 0xFF)));
}

void rt_request_quit(void) { g_quit_requested = 1; }

/* scripted key injection for headless testing: "1.5=ENTER,3=ESC,4=0x3920" */
typedef struct { double t; uint16_t key; int done; } KeyScript;
static KeyScript g_ks[64];
static int g_nks;

static uint16_t keyword_to_key(const char *s)
{
    if (!strcasecmp(s, "SHOT")) return 0xFFFF;                  /* screenshot, not a key */
    if (!strcasecmp(s, "ENTER")) return 0x1C0D;
    if (!strcasecmp(s, "ESC")) return 0x011B;
    if (!strcasecmp(s, "SPACE")) return 0x3920;
    if (!strcasecmp(s, "UP")) return 0x4800;
    if (!strcasecmp(s, "DOWN")) return 0x5000;
    if (!strcasecmp(s, "LEFT")) return 0x4B00;
    if (!strcasecmp(s, "RIGHT")) return 0x4D00;
    if (!strcasecmp(s, "F1")) return 0x3B00;
    if (!strcasecmp(s, "F2")) return 0x3C00;
    if (!strcasecmp(s, "F3")) return 0x3D00;
    if (strlen(s) == 1 && isalnum((unsigned char)s[0])) {
        static const uint8_t az[26] = {0x1E,0x30,0x2E,0x20,0x12,0x21,0x22,0x23,0x17,0x24,0x25,0x26,0x32,0x31,0x18,0x19,0x10,0x13,0x1F,0x14,0x16,0x2F,0x11,0x2D,0x15,0x2C};
        int c = tolower((unsigned char)s[0]);
        int scan = isalpha(c) ? az[c - 'a'] : (c == '0' ? 0x0B : 0x02 + (c - '1'));
        return (uint16_t)((scan << 8) | c);
    }
    return (uint16_t)strtol(s, NULL, 0);
}

static void parse_key_script(const char *s)
{
    char buf[1024];
    strncpy(buf, s, sizeof buf - 1); buf[sizeof buf - 1] = 0;
    for (char *tok = strtok(buf, ","); tok && g_nks < 64; tok = strtok(NULL, ",")) {
        char *eq = strchr(tok, '=');
        if (!eq) continue;
        *eq = 0;
        g_ks[g_nks].t = atof(tok);
        g_ks[g_nks].key = keyword_to_key(eq + 1);
        g_ks[g_nks].done = 0;
        g_nks++;
    }
}

/* ----------------------------------------------------------- polling */

static uint32_t g_start_ms;
static uint64_t g_next_irq0_us;
static uint64_t g_next_bios_tick_us;
static uint32_t g_frames;
static uint32_t g_last_present_ms;
static uint32_t g_last_event_ms;
static uint32_t g_rgba[640 * 400];
static uint64_t opl_clock(void);

static uint64_t now_us(void) { return plat_ticks_us(); }

static void dump_ppm(const char *path)
{
    FILE *f = fopen(path, "wb");
    if (!f) return;
    fprintf(f, "P6\n640 400\n255\n");
    for (int i = 0; i < 640 * 400; i++) {
        uint32_t p = g_rgba[i];
        fputc((p >> 16) & 255, f); fputc((p >> 8) & 255, f); fputc(p & 255, f);
    }
    fclose(f);
}

static void present_frame(CPU *cpu, int force)
{
    if (vga_render(cpu, g_rgba, force)) {
        plat_present(g_rgba, 640, 400);
        g_frames++;
        if (g_cfg.frame_dir && g_cfg.frame_every > 0 && (g_frames % (unsigned)g_cfg.frame_every) == 0) {
            char path[600];
            snprintf(path, sizeof path, "%s/frame_%05u.ppm", g_cfg.frame_dir, g_frames);
            dump_ppm(path);
        }
    }
}

void rt_poll(CPU *cpu)
{
    uint32_t ms = rt_now_ms();
    uint64_t us = now_us();

    if (g_quit_requested) rt_exit(0);
    if (g_cfg.max_seconds > 0 && (ms - g_start_ms) / 1000.0 >= g_cfg.max_seconds) {
        rt_log("[rt] max-seconds reached (video mode %02Xh); irq0 delivered %u, skipped(IF=0) %u, pit0 divisor %u\n", vga_mode(), g_irq_count, g_irq_skip_if, pit_divisor(0));
#ifdef RECOMP_TRACE
        if (g_cfg.trace) recomp_trace_dump("max-seconds");
#endif
        if (g_cfg.trace && g_img_orig) {      /* runtime-modified code (overlays / self-modifying) */
            FILE *cf_ = fopen("code_runtime.bin", "wb");
            if (cf_) { fwrite(cpu->mem + RT_IMG_LIN, 1, 0x10000, cf_); fclose(cf_); }
            cf_ = fopen("code_orig.bin", "wb");
            if (cf_) { fwrite(g_img_orig, 1, g_img_len < 0x10000 ? g_img_len : 0x10000, cf_); fclose(cf_); }
        }
        if (g_cfg.trace) {
            rt_log("[rt] text screen:\n");
            for (int y = 0; y < 25; y++) { char ln[81]; for (int x = 0; x < 80; x++) { uint8_t c = cpu->mem[0xB8000 + (y * 80 + x) * 2]; ln[x] = (c >= 32 && c < 127) ? (char)c : ' '; } ln[80] = 0; rt_log("|%s|\n", ln); }
        }
        present_frame(cpu, 1);
        if (g_cfg.frame_dir) { char path[600]; snprintf(path, sizeof path, "%s/final.ppm", g_cfg.frame_dir); dump_ppm(path); }
        rt_exit(0);
    }

    opl_poll(opl_clock());
    wav_capture(us);
    if (g_cfg.trace) { static int last=-1; int v = mem_read16(cpu, 0x1FA3, 0x1778); if (v != last) { rt_log("[snd] ds:1778 -> %d (cs:ip last fn %s)\n", v, recomp_last_fn()); last = v; } }
    if (ms - g_last_event_ms >= 4) { g_last_event_ms = ms; plat_pump(); }

    /* scripted keys */
    for (int i = 0; i < g_nks; i++)
        if (!g_ks[i].done && (ms - g_start_ms) / 1000.0 >= g_ks[i].t) {
            g_ks[i].done = 1;
            if (g_ks[i].key == 0xFFFF) {
                if (g_cfg.frame_dir) { char path[600]; present_frame(cpu, 1); snprintf(path, sizeof path, "%s/shot_%05.1f.ppm", g_cfg.frame_dir, g_ks[i].t); dump_ppm(path); }
                continue;
            }
            rt_key_event(g_ks[i].key >> 8, g_ks[i].key & 0xFF, 1);
            rt_key_event(g_ks[i].key >> 8, g_ks[i].key & 0xFF, 0);
        }

    /* BIOS tick counter, 18.2065 Hz */
    if (g_next_bios_tick_us == 0) g_next_bios_tick_us = us + 54925;
    while (us >= g_next_bios_tick_us) {
        bda_w32(cpu, 0x6C, bda_r32(cpu, 0x6C) + 1);
        g_next_bios_tick_us += 54925;
        if (us > g_next_bios_tick_us + 1000000) g_next_bios_tick_us = us + 54925;  /* don't spiral after a stall */
    }

    /* IRQ0 at the PIT channel 0 rate; at most a few catch-up deliveries */
    {
        uint64_t period = (uint64_t)pit_divisor(0) * 1000000ull / 1193182ull;
        if (period < 200) period = 200;
        if (g_next_irq0_us == 0) g_next_irq0_us = us + period;
        int n = 0;
        while (us >= g_next_irq0_us && n < 3) {
            deliver_irq(cpu, 8);
            g_next_irq0_us += period;
            n++;
        }
        if (us >= g_next_irq0_us) g_next_irq0_us = us + period;
    }

    if (ms - g_last_present_ms >= 16) { g_last_present_ms = ms; present_frame(cpu, 0); }
}

void recomp_tick(CPU *cpu)
{
    g_recomp_tick_budget = 4000;
    rt_poll(cpu);
}

/* ------------------------------------------------------ DOS memory */

#define ARENA_LO 0x0200u
#define ARENA_HI 0xA000u
typedef struct { uint16_t start, size; int used; } Block;
static Block g_blk[256];
static int g_nblk;

static void blk_insert(int at, Block b)
{
    if (g_nblk >= 255) return;
    memmove(&g_blk[at + 1], &g_blk[at], (size_t)(g_nblk - at) * sizeof(Block));
    g_blk[at] = b; g_nblk++;
}

static void blk_coalesce(void)
{
    for (int i = 0; i + 1 < g_nblk; ) {
        if (!g_blk[i].used && !g_blk[i + 1].used) {
            g_blk[i].size = (uint16_t)(g_blk[i].size + g_blk[i + 1].size);
            memmove(&g_blk[i + 1], &g_blk[i + 2], (size_t)(g_nblk - i - 2) * sizeof(Block));
            g_nblk--;
        } else i++;
    }
}

static void mem_init_arena(void)
{
    g_nblk = 0;
    g_blk[g_nblk++] = (Block){ ARENA_LO, (uint16_t)(0x0EF0 - ARENA_LO), 0 };
    g_blk[g_nblk++] = (Block){ 0x0EF0, 0x10, 1 };                                   /* environment */
    g_blk[g_nblk++] = (Block){ RT_PSP_SEG, (uint16_t)(ARENA_HI - RT_PSP_SEG), 1 };   /* the program */
}

static int mem_alloc(uint16_t paras, uint16_t *seg, uint16_t *largest)
{
    uint16_t big = 0;
    for (int i = 0; i < g_nblk; i++) {
        if (g_blk[i].used) continue;
        if (g_blk[i].size > big) big = g_blk[i].size;
        if (g_blk[i].size >= paras) {
            uint16_t st = g_blk[i].start;
            if (g_blk[i].size > paras)
                blk_insert(i + 1, (Block){ (uint16_t)(st + paras), (uint16_t)(g_blk[i].size - paras), 0 });
            g_blk[i].size = paras; g_blk[i].used = 1;
            *seg = st;
            return 1;
        }
    }
    *largest = big;
    return 0;
}

static int mem_free(uint16_t seg)
{
    for (int i = 0; i < g_nblk; i++)
        if (g_blk[i].start == seg && g_blk[i].used) { g_blk[i].used = 0; blk_coalesce(); return 1; }
    return 0;
}

static int mem_resize(uint16_t seg, uint16_t paras, uint16_t *largest)
{
    for (int i = 0; i < g_nblk; i++) {
        if (g_blk[i].start != seg || !g_blk[i].used) continue;
        uint16_t cur = g_blk[i].size;
        if (paras <= cur) {
            if (paras < cur) {
                blk_insert(i + 1, (Block){ (uint16_t)(seg + paras), (uint16_t)(cur - paras), 0 });
                g_blk[i].size = paras;
                blk_coalesce();
            }
            return 1;
        }
        if (i + 1 < g_nblk && !g_blk[i + 1].used && (uint32_t)cur + g_blk[i + 1].size >= paras) {
            uint16_t need = (uint16_t)(paras - cur);
            g_blk[i].size = paras;
            g_blk[i + 1].start = (uint16_t)(g_blk[i + 1].start + need);
            g_blk[i + 1].size = (uint16_t)(g_blk[i + 1].size - need);
            if (!g_blk[i + 1].size) { memmove(&g_blk[i + 1], &g_blk[i + 2], (size_t)(g_nblk - i - 2) * sizeof(Block)); g_nblk--; }
            return 1;
        }
        *largest = cur;
        if (i + 1 < g_nblk && !g_blk[i + 1].used) *largest = (uint16_t)(cur + g_blk[i + 1].size);
        return 0;
    }
    *largest = 0;
    return -1;
}

/* ------------------------------------------------------ DOS files */

#define MAXFH 40
static struct { FILE *f; char name[300]; int used; } g_fh[MAXFH];
static uint16_t g_dta_seg = RT_PSP_SEG, g_dta_off = 0x80;
static int g_cur_drive = 0;                 /* A: */

static void set_cf(CPU *cpu, int on) { if (on) cpu->flags |= FLAG_CF; else cpu->flags &= ~FLAG_CF; }
static void dos_err(CPU *cpu, uint16_t code) { cpu->ax = code; set_cf(cpu, 1); }

static void read_asciiz(CPU *cpu, uint16_t seg, uint16_t off, char *out, int n)
{
    int i = 0;
    while (i < n - 1) { char c = (char)mem_read8(cpu, seg, (uint16_t)(off + i)); if (!c) break; out[i++] = c; }
    out[i] = 0;
}

/* Case-insensitive resolution of a DOS path against the game directory. */
static int resolve_ci(const char *dosname, char *out, size_t outsz, int *exists)
{
    char rel[300];
    const char *p = dosname;
    size_t n = 0;
    if (isalpha((unsigned char)p[0]) && p[1] == ':') p += 2;
    while (*p == '\\' || *p == '/') p++;
    for (; *p && n < sizeof rel - 1; p++) rel[n++] = (*p == '\\') ? '/' : *p;
    rel[n] = 0;

    char cur[512];
    snprintf(cur, sizeof cur, "%s", g_game_dir);
    *exists = 1;
    char *save = NULL;
    char tmp[300]; snprintf(tmp, sizeof tmp, "%s", rel);
    for (char *tok = strtok_r_compat(tmp, "/", &save); tok; tok = strtok_r_compat(NULL, "/", &save)) {
        if (!strcmp(tok, ".")) continue;
        char found[300] = "";
#ifdef _WIN32
        snprintf(found, sizeof found, "%s", tok);
        (void)found;
        char cand[800]; snprintf(cand, sizeof cand, "%s/%s", cur, tok);
        DWORD at = GetFileAttributesA(cand);
        if (at == INVALID_FILE_ATTRIBUTES) *exists = 0;
        snprintf(cur, sizeof cur, "%s", cand);
#else
        DIR *d = opendir(cur);
        if (d) {
            struct dirent *de;
            while ((de = readdir(d))) if (!strcasecmp(de->d_name, tok)) { snprintf(found, sizeof found, "%s", de->d_name); break; }
            closedir(d);
        }
        if (!found[0]) { snprintf(found, sizeof found, "%s", tok); *exists = 0; }
        size_t l = strlen(cur);
        snprintf(cur + l, sizeof cur - l, "/%s", found);
#endif
    }
    snprintf(out, outsz, "%s", cur);
    return 1;
}

static int fh_alloc(FILE *f, const char *name)
{
    for (int i = 5; i < MAXFH; i++)
        if (!g_fh[i].used) { g_fh[i].used = 1; g_fh[i].f = f; snprintf(g_fh[i].name, sizeof g_fh[i].name, "%s", name); return i; }
    return -1;
}

/* find first/next */
typedef struct { char dir[512]; char pat[64]; int attr; void *h; int active; } FindState;
static FindState g_find;

static int wild_match(const char *pat, const char *s)
{
    while (*pat) {
        if (*pat == '*') { pat++; if (!*pat) return 1; while (*s) { if (wild_match(pat, s)) return 1; s++; } return 0; }
        if (!*s) return 0;
        if (*pat != '?' && tolower((unsigned char)*pat) != tolower((unsigned char)*s)) return 0;
        pat++; s++;
    }
    return *s == 0;
}

static int find_next(CPU *cpu)
{
#ifdef _WIN32
    WIN32_FIND_DATAA fd;
    for (;;) {
        if (!g_find.active) return 0;
        if (g_find.h == NULL) {
            char pat[600]; snprintf(pat, sizeof pat, "%s/*", g_find.dir);
            g_find.h = FindFirstFileA(pat, &fd);
            if (g_find.h == INVALID_HANDLE_VALUE) { g_find.active = 0; g_find.h = NULL; return 0; }
        } else if (!FindNextFileA((HANDLE)g_find.h, &fd)) { FindClose((HANDLE)g_find.h); g_find.h = NULL; g_find.active = 0; return 0; }
        if ((fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) continue;
        if (!wild_match(g_find.pat, fd.cFileName)) continue;
        uint32_t size = fd.nFileSizeLow;
        const char *name = fd.cFileName;
        goto got;
    got:
        mem_write8(cpu, g_dta_seg, (uint16_t)(g_dta_off + 0x15), 0x20);
        mem_write16(cpu, g_dta_seg, (uint16_t)(g_dta_off + 0x16), 0); mem_write16(cpu, g_dta_seg, (uint16_t)(g_dta_off + 0x18), 0x21);
        mem_write16(cpu, g_dta_seg, (uint16_t)(g_dta_off + 0x1A), (uint16_t)size); mem_write16(cpu, g_dta_seg, (uint16_t)(g_dta_off + 0x1C), (uint16_t)(size >> 16));
        for (int i = 0; i < 13; i++) mem_write8(cpu, g_dta_seg, (uint16_t)(g_dta_off + 0x1E + i), (uint8_t)(i < 12 && name[i] ? toupper((unsigned char)name[i]) : 0));
        return 1;
    }
#else
    DIR *d = (DIR *)g_find.h;
    struct dirent *de;
    if (!g_find.active || !d) return 0;
    while ((de = readdir(d))) {
        if (de->d_name[0] == '.') continue;
        if (!wild_match(g_find.pat, de->d_name)) continue;
        char full[900]; snprintf(full, sizeof full, "%s/%s", g_find.dir, de->d_name);
        struct stat st;
        if (stat(full, &st) || S_ISDIR(st.st_mode)) continue;
        uint32_t size = (uint32_t)st.st_size;
        mem_write8(cpu, g_dta_seg, (uint16_t)(g_dta_off + 0x15), 0x20);
        mem_write16(cpu, g_dta_seg, (uint16_t)(g_dta_off + 0x16), 0);
        mem_write16(cpu, g_dta_seg, (uint16_t)(g_dta_off + 0x18), 0x21);
        mem_write16(cpu, g_dta_seg, (uint16_t)(g_dta_off + 0x1A), (uint16_t)size);
        mem_write16(cpu, g_dta_seg, (uint16_t)(g_dta_off + 0x1C), (uint16_t)(size >> 16));
        for (int i = 0; i < 13; i++)
            mem_write8(cpu, g_dta_seg, (uint16_t)(g_dta_off + 0x1E + i), (uint8_t)(i < 12 && de->d_name[i] ? toupper((unsigned char)de->d_name[i]) : 0));
        return 1;
    }
    closedir(d); g_find.h = NULL; g_find.active = 0;
    return 0;
#endif
}

/* ------------------------------------------------------- INT 21h */

static void int21(CPU *cpu)
{
    uint8_t ah = cpu->ah;
    switch (ah) {
    case 0x00: rt_exit(0); break;
    case 0x01: {                                   /* read char with echo */
        uint16_t k; while (!kq_pop(&k)) { rt_poll(cpu); plat_sleep_ms(1); }
        cpu->al = (uint8_t)k; break; }
    case 0x02: fputc(cpu->dl, stdout); break;
    case 0x06: if (cpu->dl == 0xFF) { uint16_t k; if (kq_pop(&k)) { cpu->al = (uint8_t)k; cpu->flags &= ~FLAG_ZF; } else { cpu->al = 0; cpu->flags |= FLAG_ZF; } }
               else fputc(cpu->dl, stdout);
               break;
    case 0x07: case 0x08: { uint16_t k; while (!kq_pop(&k)) { rt_poll(cpu); plat_sleep_ms(1); } cpu->al = (uint8_t)k; break; }
    case 0x09: { uint16_t o = cpu->dx; for (int i = 0; i < 4096; i++) { uint8_t c = mem_read8(cpu, cpu->ds, (uint16_t)(o + i)); if (c == '$') break; fputc(c, stdout); } fflush(stdout); break; }
    case 0x0B: cpu->al = kq_count() ? 0xFF : 0x00; break;
    case 0x0C: while (kq_count()) { uint16_t k; kq_pop(&k); } if (cpu->al) { uint8_t a = cpu->al; cpu->ah = a; int21(cpu); } break;
    case 0x0D: break;                                  /* disk reset */
    case 0x0E: g_cur_drive = cpu->dl; cpu->al = 5; break;
    case 0x19: cpu->al = (uint8_t)g_cur_drive; break;
    case 0x1A: g_dta_seg = cpu->ds; g_dta_off = cpu->dx; break;
    case 0x25: ivt_set(cpu, cpu->al, cpu->ds, cpu->dx); break;
    case 0x2A: { time_t t = time(NULL); struct tm *tm = localtime(&t);
                 cpu->cx = (uint16_t)(tm->tm_year + 1900); cpu->dh = (uint8_t)(tm->tm_mon + 1); cpu->dl = (uint8_t)tm->tm_mday; cpu->al = (uint8_t)tm->tm_wday; break; }
    case 0x2C: { time_t t = time(NULL); struct tm *tm = localtime(&t);
                 cpu->ch = (uint8_t)tm->tm_hour; cpu->cl = (uint8_t)tm->tm_min; cpu->dh = (uint8_t)tm->tm_sec; cpu->dl = 0; break; }
    case 0x2F: cpu->es = g_dta_seg; cpu->bx = g_dta_off; break;
    case 0x30: cpu->ax = 0x0005; cpu->bx = 0; cpu->cx = 0; break;        /* DOS 5.0 */
    case 0x33: if (cpu->al == 0) cpu->dl = 0; break;
    case 0x35: { uint16_t s, o; ivt_get(cpu, cpu->al, &s, &o); cpu->es = s; cpu->bx = o; break; }
    case 0x36: cpu->ax = 4; cpu->bx = 0x4000; cpu->cx = 512; cpu->dx = 0x4000; break;
    case 0x3B: set_cf(cpu, 0); break;
    case 0x3C: case 0x3D: {                       /* create / open */
        char dn[300], hp[900]; int ex;
        read_asciiz(cpu, cpu->ds, cpu->dx, dn, sizeof dn);
        resolve_ci(dn, hp, sizeof hp, &ex);
        FILE *f;
        if (ah == 0x3C) f = fopen(hp, "w+b");
        else {
            int acc = cpu->al & 3;
            f = fopen(hp, acc == 0 ? "rb" : "r+b");
            if (!f && acc != 0 && ex) f = fopen(hp, "rb");
        }
        if (!f) { if (g_cfg.trace) rt_log("[dos] open FAIL '%s' -> %s\n", dn, hp); dos_err(cpu, ex ? 5 : 2); break; }
        int h = fh_alloc(f, hp);
        if (h < 0) { fclose(f); dos_err(cpu, 4); break; }
        if (g_cfg.trace) rt_log("[dos] open '%s' -> handle %d (%s)\n", dn, h, hp);
        cpu->ax = (uint16_t)h; set_cf(cpu, 0); break; }
    case 0x3E: {
        uint16_t h = cpu->bx;
        if (h < MAXFH && g_fh[h].used && h >= 5) { fclose(g_fh[h].f); g_fh[h].used = 0; set_cf(cpu, 0); }
        else if (h < 5) set_cf(cpu, 0);
        else dos_err(cpu, 6);
        break; }
    case 0x3F: {
        uint16_t h = cpu->bx, n = cpu->cx;
        if (h == 0) { cpu->ax = 0; set_cf(cpu, 0); break; }
        if (h >= MAXFH || !g_fh[h].used) { dos_err(cpu, 6); break; }
        uint8_t buf[4096]; uint16_t done = 0;
        while (done < n) {
            size_t want = (size_t)(n - done); if (want > sizeof buf) want = sizeof buf;
            size_t got = fread(buf, 1, want, g_fh[h].f);
            for (size_t i = 0; i < got; i++) mem_write8(cpu, cpu->ds, (uint16_t)(cpu->dx + done + i), buf[i]);
            done = (uint16_t)(done + got);
            if (got < want) break;
        }
        cpu->ax = done; set_cf(cpu, 0); break; }
    case 0x40: {
        uint16_t h = cpu->bx, n = cpu->cx;
        if (h == 1 || h == 2) { for (uint16_t i = 0; i < n; i++) fputc(mem_read8(cpu, cpu->ds, (uint16_t)(cpu->dx + i)), h == 1 ? stdout : stderr); cpu->ax = n; set_cf(cpu, 0); break; }
        if (h >= MAXFH || !g_fh[h].used) { dos_err(cpu, 6); break; }
        uint16_t done = 0;
        for (; done < n; done++) { int c = mem_read8(cpu, cpu->ds, (uint16_t)(cpu->dx + done)); if (fputc(c, g_fh[h].f) == EOF) break; }
        cpu->ax = done; set_cf(cpu, 0); break; }
    case 0x41: {
        char dn[300], hp[900]; int ex; read_asciiz(cpu, cpu->ds, cpu->dx, dn, sizeof dn); resolve_ci(dn, hp, sizeof hp, &ex);
        if (remove(hp)) dos_err(cpu, 2); else set_cf(cpu, 0); break; }
    case 0x42: {
        uint16_t h = cpu->bx;
        if (h >= MAXFH || !g_fh[h].used) { dos_err(cpu, 6); break; }
        long off = (long)(((uint32_t)cpu->cx << 16) | cpu->dx);
        int wh = cpu->al == 0 ? SEEK_SET : cpu->al == 1 ? SEEK_CUR : SEEK_END;
        fseek(g_fh[h].f, off, wh);
        long pos = ftell(g_fh[h].f);
        cpu->dx = (uint16_t)((uint32_t)pos >> 16); cpu->ax = (uint16_t)pos; set_cf(cpu, 0); break; }
    case 0x43: {
        char dn[300], hp[900]; int ex; read_asciiz(cpu, cpu->ds, cpu->dx, dn, sizeof dn); resolve_ci(dn, hp, sizeof hp, &ex);
        if (cpu->al == 0) { if (ex) { cpu->cx = 0x20; set_cf(cpu, 0); } else dos_err(cpu, 2); } else set_cf(cpu, 0);
        break; }
    case 0x44:
        if (cpu->al == 0) { cpu->dx = (cpu->bx < 5) ? 0x80D3 : 0x0002; set_cf(cpu, 0); }
        else if (cpu->al == 7 || cpu->al == 6) { cpu->al = 0xFF; set_cf(cpu, 0); }
        else if (cpu->al == 8) { cpu->ax = 1; set_cf(cpu, 0); }                   /* fixed media */
        else if (cpu->al == 9) { cpu->dx = 0; set_cf(cpu, 0); }
        else set_cf(cpu, 0);
        break;
    case 0x45: { uint16_t h = cpu->bx; if (h < MAXFH && g_fh[h].used) { int n = fh_alloc(g_fh[h].f, g_fh[h].name); if (n >= 0) { cpu->ax = (uint16_t)n; set_cf(cpu, 0); break; } } dos_err(cpu, 6); break; }
    case 0x47: mem_write8(cpu, cpu->ds, cpu->si, 0); set_cf(cpu, 0); break;
    case 0x48: {
        uint16_t seg, big = 0;
        if (mem_alloc(cpu->bx, &seg, &big)) { cpu->ax = seg; set_cf(cpu, 0); }
        else { cpu->bx = big; dos_err(cpu, 8); }
        break; }
    case 0x49: if (mem_free(cpu->es)) set_cf(cpu, 0); else dos_err(cpu, 9); break;
    case 0x4A: {
        uint16_t big = 0; int r = mem_resize(cpu->es, cpu->bx, &big);
        if (r == 1) set_cf(cpu, 0); else if (r == 0) { cpu->bx = big; dos_err(cpu, 8); } else dos_err(cpu, 9);
        break; }
    case 0x4C: rt_exit(cpu->al); break;
    case 0x4D: cpu->ax = 0; break;
    case 0x4E: {
        char dn[300]; read_asciiz(cpu, cpu->ds, cpu->dx, dn, sizeof dn);
        const char *base = dn; for (const char *p = dn; *p; p++) if (*p == '\\' || *p == '/' || *p == ':') base = p + 1;
        snprintf(g_find.pat, sizeof g_find.pat, "%s", base);
        { char hp[900]; int ex; char dir[300]; size_t l = (size_t)(base - dn); memcpy(dir, dn, l); dir[l] = 0; if (!l) strcpy(dir, ".");
          resolve_ci(dir, hp, sizeof hp, &ex); snprintf(g_find.dir, sizeof g_find.dir, "%s", hp); }
#ifndef _WIN32
        if (g_find.active && g_find.h) closedir((DIR *)g_find.h);
        g_find.h = opendir(g_find.dir);
        g_find.active = g_find.h != NULL;
#else
        g_find.h = NULL; g_find.active = 1;
#endif
        if (find_next(cpu)) set_cf(cpu, 0); else dos_err(cpu, 18);
        break; }
    case 0x4F: if (find_next(cpu)) set_cf(cpu, 0); else dos_err(cpu, 18); break;
    case 0x56: {
        char a[300], b[300], ha[900], hb[900]; int e1, e2;
        read_asciiz(cpu, cpu->ds, cpu->dx, a, sizeof a); read_asciiz(cpu, cpu->es, cpu->di, b, sizeof b);
        resolve_ci(a, ha, sizeof ha, &e1); resolve_ci(b, hb, sizeof hb, &e2);
        if (rename(ha, hb)) dos_err(cpu, 2); else set_cf(cpu, 0); break; }
    case 0x57: set_cf(cpu, 0); if (cpu->al == 0) { cpu->cx = 0; cpu->dx = 0x21; } break;
    case 0x62: cpu->bx = RT_PSP_SEG; break;
    default:
        if (g_cfg.trace) rt_log("[dos] unhandled INT 21h AH=%02X AL=%02X\n", ah, cpu->al);
        dos_err(cpu, 1);
        break;
    }
}

void dos_int21(CPU *cpu) { int21(cpu); }

/* ------------------------------------------------------- BIOS INTs */

void bios_int10(CPU *cpu)
{
    if (g_cfg.trace && (cpu->ah == 0x00 || cpu->ah == 0x10 || cpu->ah == 0x11 || cpu->ah == 0x12 || cpu->ah == 0x1A))
        rt_log("[bios] INT 10h AX=%04X BX=%04X CX=%04X DX=%04X\n", cpu->ax, cpu->bx, cpu->cx, cpu->dx);
    if (cpu->ah == 0x1A && cpu->al == 0x00 && g_cfg.adapter != 5) return;           /* no VGA display-combination service */
    if (cpu->ah == 0x12 && cpu->bl == 0x10 && g_cfg.adapter != 5 && g_cfg.adapter != 1) {   /* no EGA either */
        return;
    }
    vga_int10(cpu);
}

void bios_int16(CPU *cpu)
{
    uint16_t k;
    switch (cpu->ah) {
    case 0x00: case 0x10:
        while (!kq_pop(&k)) { rt_poll(cpu); plat_sleep_ms(1); }
        cpu->ax = k; break;
    case 0x01: case 0x11:
        if (g_kq_h != g_kq_t) { cpu->ax = g_kq[g_kq_h]; cpu->flags &= ~FLAG_ZF; }
        else { cpu->flags |= FLAG_ZF; }
        /* a polling loop must not starve the timer or window */
        rt_poll(cpu);
        break;
    case 0x02: case 0x12: cpu->al = g_shift_flags; break;
    default: break;
    }
}

void mouse_int33(CPU *cpu) { cpu->ax = 0; }                 /* no mouse driver */

void int_handler(CPU *cpu, int vec)
{
    switch (vec) {
    case 0x10: bios_int10(cpu); break;
    case 0x11: cpu->ax = 0x0061; break;                       /* 1 floppy, 80x25 color, no coproc */
    case 0x12: cpu->ax = 640; break;
    case 0x13:                                                /* disk: report success, nothing to do */
        cpu->ah = 0; set_cf(cpu, 0); break;
    case 0x15: cpu->ah = 0x86; set_cf(cpu, 1); break;         /* unsupported */
    case 0x16: bios_int16(cpu); break;
    case 0x1A:
        switch (cpu->ah) {
        case 0x00: { uint32_t t = bda_r32(cpu, 0x6C); cpu->cx = (uint16_t)(t >> 16); cpu->dx = (uint16_t)t; cpu->al = 0; break; }
        case 0x02: { time_t t = time(NULL); struct tm *tm = localtime(&t);
                     cpu->ch = (uint8_t)(((tm->tm_hour / 10) << 4) | (tm->tm_hour % 10));
                     cpu->cl = (uint8_t)(((tm->tm_min / 10) << 4) | (tm->tm_min % 10));
                     cpu->dh = (uint8_t)(((tm->tm_sec / 10) << 4) | (tm->tm_sec % 10)); cpu->dl = 0; set_cf(cpu, 0); break; }
        default: set_cf(cpu, 1); break;
        }
        break;
    case 0x33: mouse_int33(cpu); break;
    default:
        if (g_cfg.trace) rt_log("[bios] INT %02Xh AX=%04X ignored\n", vec, cpu->ax);
        break;
    }
}

/* ---------------------------------------------------------- ports */

static int g_vga_log, g_opl_log;
/* The lifted code runs far faster than a 4.77-12 MHz PC, so detection loops that wait for an
 * OPL timer (e.g. 200 status reads for an 80us timer) would finish before the wall clock
 * advances.  Every OPL port access therefore also advances a virtual clock by ~1.5 us (the
 * cost of an ISA I/O cycle); the chip timers run on wall time + that bonus. */
static uint64_t g_opl_bonus_us; static uint8_t g_opl_addr;
static uint64_t opl_clock(void) { return plat_ticks_us() + (g_opl_bonus_us * 3 >> 1); }
uint8_t port_in8(CPU *cpu, uint16_t port)
{
    uint8_t v;
    if (vga_port_in(port, &v)) { if (port == 0x3DA || port == 0x3BA) rt_poll(cpu); return v; }
    switch (port) {
    case 0x388: { g_opl_bonus_us++; opl_poll(opl_clock()); uint8_t st = opl_read_status(); if (0) rt_log("[opl] status read -> %02X\n", st); return st; }
    case 0x389: return 0xFF;
    case 0x60: return g_scan_latch;
    case 0x61: return g_p61;
    case 0x40: case 0x41: case 0x42: return 0;
    case 0x21: return 0;
    case 0x64: return 0;
    default: return 0xFF;
    }
}


void port_out8(CPU *cpu, uint16_t port, uint8_t val)
{
    (void)cpu;
    if (g_cfg.trace && ((port >= 0x3C0 && port <= 0x3CF) || port == 0x3D4 || port == 0x3D5) && g_vga_log++ < 60)
        rt_log("[vga] out %03X <- %02X\n", port, val);
    if (vga_port_out(port, val)) return;
    switch (port) {
    case 0x40: pit_write(0, val); break;
    case 0x42: pit_write(2, val); break;
    case 0x43: {
        int ch = (val >> 6) & 3, acc = (val >> 4) & 3;
        if (ch == 3) break;
        if (acc == 0) break;                                   /* latch command */
        g_pit_mode_lohi[ch] = (uint8_t)acc; g_pit_phase[ch] = 0;
        break; }
    case 0x388: g_opl_bonus_us++; g_opl_addr = val; opl_write(0, val); break;
    case 0x389: g_opl_bonus_us++; opl_write(1, val); if (g_cfg.trace && g_opl_log++ < 3000) rt_log("[opl] r%02X=%02X\n", g_opl_addr, val); break;
    case 0x61: g_p61 = val; speaker_update(); break;
    default:
        if (g_cfg.trace) { static uint8_t seen[65536 / 8]; if (!(seen[port >> 3] & (1 << (port & 7)))) { seen[port >> 3] |= (uint8_t)(1 << (port & 7)); rt_log("[port] first write to unhandled port %03X <- %02X\n", port, val); } }
        break;
    }
}

uint16_t port_in16(CPU *cpu, uint16_t port)
{
    return (uint16_t)(port_in8(cpu, port) | (port_in8(cpu, (uint16_t)(port + 1)) << 8));
}

void port_out16(CPU *cpu, uint16_t port, uint16_t val)
{
    port_out8(cpu, port, (uint8_t)val);
    port_out8(cpu, (uint16_t)(port + 1), (uint8_t)(val >> 8));
}

/* ---------------------------------------------------- VGA memory hook */

extern int  vga_mem_read8(CPU *cpu, uint32_t addr, uint8_t *out);
extern int  vga_mem_write8(CPU *cpu, uint32_t addr, uint8_t val);

int recomp_mem_read8(CPU *cpu, uint32_t addr, uint8_t *out)
{
    if (addr >= 0xA0000u && addr < 0xB0000u) return vga_mem_read8(cpu, addr, out);
    return 0;
}

int recomp_mem_write8(CPU *cpu, uint32_t addr, uint8_t val)
{
    if (addr >= 0xA0000u && addr < 0xB0000u) return vga_mem_write8(cpu, addr, val);
    return 0;
}

/* ----------------------------------------------------------- boot */

static int load_image(CPU *cpu, const char *path)
{
    FILE *f = fopen(path, "rb");
    if (!f) return -1;
    fseek(f, 0, SEEK_END); long sz = ftell(f); fseek(f, 0, SEEK_SET);
    uint8_t *buf = (uint8_t *)malloc((size_t)sz);
    if (!buf || fread(buf, 1, (size_t)sz, f) != (size_t)sz) { fclose(f); free(buf); return -2; }
    fclose(f);
    if (sz < 0x1C || buf[0] != 'M' || buf[1] != 'Z') { free(buf); return -3; }
    unsigned lastpage = buf[2] | (buf[3] << 8), pages = buf[4] | (buf[5] << 8);
    unsigned nrel = buf[6] | (buf[7] << 8), hdr = (buf[8] | (buf[9] << 8)) * 16u;
    unsigned roff = buf[0x18] | (buf[0x19] << 8);
    unsigned img = (pages - 1) * 512u + (lastpage ? lastpage : 512u) - hdr;
    if (hdr + img > (unsigned)sz) img = (unsigned)sz - hdr;
    memcpy(cpu->mem + RT_IMG_LIN, buf + hdr, img);
    for (unsigned i = 0; i < nrel; i++) {
        unsigned off = buf[roff + 4 * i] | (buf[roff + 4 * i + 1] << 8);
        unsigned seg = buf[roff + 4 * i + 2] | (buf[roff + 4 * i + 3] << 8);
        uint32_t a = RT_IMG_LIN + seg * 16u + off;
        uint16_t w = (uint16_t)(cpu->mem[a] | (cpu->mem[a + 1] << 8));
        w = (uint16_t)(w + RT_LOAD_SEG);
        cpu->mem[a] = (uint8_t)w; cpu->mem[a + 1] = (uint8_t)(w >> 8);
    }
    g_img_len = img;
    g_img_orig = (uint8_t *)malloc(img);
    if (g_img_orig) memcpy(g_img_orig, cpu->mem + RT_IMG_LIN, img);
    /* entry registers from the header (link-time values -> run-time) */
    unsigned ss = buf[0xE] | (buf[0xF] << 8), sp = buf[0x10] | (buf[0x11] << 8);
    cpu->ss = (uint16_t)(ss + RT_LOAD_SEG); cpu->sp = (uint16_t)sp;
    free(buf);
    return 0;
}

int rt_boot(const RtConfig *cfg)
{
    g_cfg = *cfg;
#ifdef RECOMP_TRACE
    g_seen_log = cfg->trace;
#endif
    snprintf(g_game_dir, sizeof g_game_dir, "%s", cfg->game_dir ? cfg->game_dir : ".");
    { size_t l = strlen(g_game_dir); while (l > 1 && (g_game_dir[l - 1] == '/' || g_game_dir[l - 1] == '\\')) g_game_dir[--l] = 0; }

#ifdef RECOMP_TRACE
    {   /* run the handler on its own stack: the usual crash is runaway recursion */
        static char altstk[65536];
        stack_t ss; ss.ss_sp = altstk; ss.ss_size = sizeof altstk; ss.ss_flags = 0;
        sigaltstack(&ss, NULL);
        struct sigaction sa; memset(&sa, 0, sizeof sa);
        sa.sa_handler = on_segv; sa.sa_flags = SA_ONSTACK;
        sigaction(SIGSEGV, &sa, NULL);
    }
#endif
    cpu_init(&g_cpu);
    if (cpu_alloc_mem(&g_cpu)) { rt_log("out of memory\n"); return 1; }
    CPU *cpu = &g_cpu;

    char path[900], hp[900]; int ex;
    snprintf(path, sizeof path, "AEPROG.EXE");
    resolve_ci(path, hp, sizeof hp, &ex);
    int rc = load_image(cpu, hp);
    if (rc) {
        rt_log("Cannot load '%s' (code %d).\nPut AEPROG.EXE, AE000.DAT and AE001.DAT from your copy of Ancient Empires in that folder\n"
               "(or pass --game-dir <folder>).\n", hp, rc);
        return 2;
    }

    /* interrupt vectors: every one points at a BIOS-ROM stub */
    for (int v = 0; v < 256; v++) ivt_set(cpu, v, 0xF000, (uint16_t)(0xFF00 + v));

    /* BIOS data area */
    bda_w16(cpu, 0x10, 0x0061);
    bda_w16(cpu, 0x13, 640);
    cpu->mem[0x449] = 3;
    bda_w16(cpu, 0x4A, 80);
    cpu->mem[0x484] = 24;
    bda_w16(cpu, 0x63, 0x3D4);

    /* environment block + PSP */
    {
        uint32_t env = 0x0EF0u << 4;
        const char *prog = "A:\\AEPROG.EXE";
        memset(cpu->mem + env, 0, 256);
        cpu->mem[env + 0] = 0; cpu->mem[env + 1] = 0;           /* empty env, double NUL */
        cpu->mem[env + 2] = 1; cpu->mem[env + 3] = 0;           /* one extra string */
        memcpy(cpu->mem + env + 4, prog, strlen(prog) + 1);
        uint32_t psp = (uint32_t)RT_PSP_SEG << 4;
        memset(cpu->mem + psp, 0, 256);
        cpu->mem[psp] = 0xCD; cpu->mem[psp + 1] = 0x20;
        cpu->mem[psp + 2] = (uint8_t)(ARENA_HI & 0xFF); cpu->mem[psp + 3] = (uint8_t)(ARENA_HI >> 8);
        cpu->mem[psp + 0x2C] = 0xF0; cpu->mem[psp + 0x2D] = 0x0E;  /* env segment 0x0EF0 */
        cpu->mem[psp + 0x80] = 0; cpu->mem[psp + 0x81] = 0x0D;     /* empty command tail */
    }
    mem_init_arena();

    if (cfg->adapter == 3) {                       /* Tandy 1000 BIOS signature */
        cpu->mem[0xFFFFE] = 0xFF; cpu->mem[0xFC000] = 0x21;
    }
    vga_init(cpu);
    opl_init();

    cpu->ds = cpu->es = RT_PSP_SEG;
    cpu->cs = RT_LOAD_SEG;
    cpu->flags = 0x0202;                                        /* IF set */
    cpu->dir = 0;

    if (!cfg->headless) { if (plat_init(0, cfg->scale, cfg->fullscreen)) { rt_log("platform init failed\n"); return 3; } }
    else plat_init(1, 1, 0);

    if (cfg->key_script) parse_key_script(cfg->key_script);
    g_start_ms = rt_now_ms();
    g_recomp_tick_budget = 4000;
    return 0;
}

void rt_run(void)
{
    fn_00000(&g_cpu);
    rt_log("[rt] guest returned from entry without exiting\n");
    rt_exit(0);
}

void rt_exit(int code)
{
    if (g_exited) exit(code);
    g_exited = 1;
    wav_finish();
    for (int i = 5; i < MAXFH; i++) if (g_fh[i].used) { fclose(g_fh[i].f); g_fh[i].used = 0; }
    if (g_cfg.trace) rt_log("[snd] ds:1778 sound driver = %d, adapter byte = %d\n", mem_read16(&g_cpu, 0x1FA3, 0x1778), mem_read8(&g_cpu, 0x1FA3, 0xBFCD));
    if (g_nmiss) rt_log("[rt] %d dispatch misses -> misses.txt\n", g_nmiss);
    plat_shutdown();
    exit(code);
}
