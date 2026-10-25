/*
 * runtime.h - host runtime surface the lifted Ancient Empires code calls into.
 *
 * The lifter emits a small set of escape hatches: software interrupts
 * (dos_int21 / bios_int10 / bios_int16 / int_handler), port I/O, indirect
 * call/jmp dispatch, a loop back-edge tick, and a planar-VGA memory hook.
 * Everything here models just enough of a PC/DOS machine for the game.
 *
 * CPU model and lifter: github.com/sp00nznet/pcrecomp (MIT).
 */
#ifndef EMPIRES_RUNTIME_H
#define EMPIRES_RUNTIME_H

#include "cpu.h"

/* ---- load layout (matches a real DOS load; Ghidra shows the same) ---- */
#define RT_LOAD_SEG   0x1000u            /* image segment; CS = 0x1000, DGROUP = 0x1FA3 */
#define RT_PSP_SEG    (RT_LOAD_SEG - 0x10)
#define RT_IMG_LIN    ((uint32_t)RT_LOAD_SEG << 4)

/* ---- interrupts the lifted code calls ---- */
void int_handler(CPU *cpu, int vec);
void dos_int21(CPU *cpu);
void bios_int10(CPU *cpu);
void bios_int16(CPU *cpu);
void mouse_int33(CPU *cpu);

/* ---- port I/O ---- */
uint8_t  port_in8(CPU *cpu, uint16_t port);
void     port_out8(CPU *cpu, uint16_t port, uint8_t val);
uint16_t port_in16(CPU *cpu, uint16_t port);
void     port_out16(CPU *cpu, uint16_t port, uint16_t val);

/* ---- indirect dispatch ----
 * recomp_dispatch: seg < 0x1000 is an image-space address (seg*16+off is an
 * offset into the loaded image); seg >= 0x1000 is a real run-time segment.
 * dispatch_near / dispatch_far: the lifted caller already pushed a dummy
 * return frame; a miss pops it again. */
int  recomp_dispatch(CPU *cpu, unsigned seg, unsigned off);
void dispatch_near(CPU *cpu, unsigned seg, unsigned off);
void dispatch_far(CPU *cpu, unsigned seg, unsigned off);
void recomp_div0(const char *kind);
/* Calls into cs:[0x39C,0xAFA) -- the graphics driver the game decompresses at
 * run time -- run the lifted copy of the driver that is actually loaded. */
void ovl_call(CPU *cpu, unsigned addr);

/* ---- machine bring-up (runtime.c) ---- */
typedef struct RtConfig {
    const char *game_dir;     /* folder holding AEPROG.EXE, AE000.DAT, AE001.DAT */
    int         headless;     /* no window, no audio */
    int         scale;        /* window scale (1..N), 0 = auto */
    int         fullscreen;
    double      max_seconds;  /* >0: quit after this much wall time (testing) */
    const char *frame_dir;    /* dump PPM frames here (testing) */
    int         frame_every;  /* ...every N presented frames */
    const char *key_script;   /* "t=KEYWORD,t=KEYWORD..." scripted key injection */
    int         trace;
    int         adapter;      /* what the game's video detection should find: 5=VGA (default), 1=EGA, 3=Tandy, 0=CGA */
} RtConfig;

int  rt_boot(const RtConfig *cfg);        /* load image, set up PSP/regs; 0 = ok */
void rt_run(void);                        /* run the lifted program (does not return) */
void rt_exit(int code);                   /* flush, report, shut down, exit */
void rt_poll(CPU *cpu);                   /* pump events / timers / present */
uint32_t rt_now_ms(void);

/* ---- input (platform -> runtime) ---- */
void rt_key_event(int scan, int ascii, int down);   /* PC set-1 scan code + ASCII */
void rt_request_quit(void);

/* ---- VGA (vga.c) ---- */
void vga_init(CPU *cpu);
void vga_set_mode(CPU *cpu, int mode, int clear);
int  vga_mode(void);
int  vga_port_in(uint16_t port, uint8_t *out);          /* 1 = handled */
int  vga_port_out(uint16_t port, uint8_t val);          /* 1 = handled */
/* Renders the current screen into rgba[640*400]; returns 1 if the picture
 * changed since the last call (or force != 0). */
int  vga_render(CPU *cpu, uint32_t *rgba, int force);
void vga_text_putc(CPU *cpu, uint8_t ch);               /* INT 10h/0Eh teletype */
void vga_int10(CPU *cpu);

/* ---- PC speaker (runtime.c -> platform) ---- */
void rt_speaker(int hz);

#endif
