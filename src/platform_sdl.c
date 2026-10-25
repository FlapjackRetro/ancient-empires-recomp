/* platform_sdl.c - SDL2 window, keyboard, PC-speaker audio, clocks. */
#include "platform.h"
#include "opl.h"
#include "recomp/runtime.h"
#include <SDL.h>
#include <stdio.h>
#include <string.h>

static SDL_Window *g_win;
static SDL_Renderer *g_ren;
static SDL_Texture *g_tex;
static SDL_AudioDeviceID g_audio;
static int g_headless;
static volatile int g_hz;
static double g_phase;
static int g_aud_rate = 44100;

uint32_t plat_ticks_ms(void) { return SDL_GetTicks(); }
uint64_t plat_ticks_us(void) { return (uint64_t)(SDL_GetPerformanceCounter() * 1000000ull / SDL_GetPerformanceFrequency()); }
void plat_sleep_ms(uint32_t ms) { SDL_Delay(ms); }
void plat_speaker(int hz) { g_hz = hz; }

static void audio_cb(void *ud, Uint8 *stream, int len)
{
    (void)ud;
    int16_t *o = (int16_t *)stream; int n = len / 2; int hz = g_hz;
    int32_t acc[2048];
    if (n > 2048) n = 2048;
    for (int i = 0; i < n; i++) {
        int32_t v = 0;
        if (hz) {
            g_phase += (double)hz / g_aud_rate; if (g_phase >= 1.0) g_phase -= 1.0;
            v = (g_phase < 0.5) ? 4000 : -4000;
        } else g_phase = 0;
        acc[i] = v;
    }
    opl_mix(acc, n, g_aud_rate);
    for (int i = 0; i < n; i++) { int32_t v = acc[i]; o[i] = v > 32767 ? 32767 : v < -32768 ? -32768 : (int16_t)v; }
}

int plat_init(int headless, int scale, int fullscreen)
{
    g_headless = headless;
    if (SDL_Init(headless ? 0 : (SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) != 0) { fprintf(stderr, "SDL_Init: %s\n", SDL_GetError()); return 1; }
    if (headless) return 0;
    if (scale <= 0) scale = 2;
    g_win = SDL_CreateWindow("Ancient Empires (static recompilation)", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                             640 * scale / 1, 480 * scale / 1 * 0 + 400 * scale, SDL_WINDOW_RESIZABLE | (fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0));
    if (!g_win) { fprintf(stderr, "SDL_CreateWindow: %s\n", SDL_GetError()); return 1; }
    g_ren = SDL_CreateRenderer(g_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!g_ren) g_ren = SDL_CreateRenderer(g_win, -1, SDL_RENDERER_SOFTWARE);
    if (!g_ren) { fprintf(stderr, "SDL_CreateRenderer: %s\n", SDL_GetError()); return 1; }
    SDL_RenderSetLogicalSize(g_ren, 640, 480 * 0 + 400);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
    g_tex = SDL_CreateTexture(g_ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 640, 400);
    SDL_AudioSpec want, have; SDL_zero(want);
    want.freq = 44100; want.format = AUDIO_S16SYS; want.channels = 1; want.samples = 1024; want.callback = audio_cb;
    g_audio = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);
    if (g_audio) { g_aud_rate = have.freq; SDL_PauseAudioDevice(g_audio, 0); }
    return 0;
}

void plat_shutdown(void)
{
    if (g_audio) SDL_CloseAudioDevice(g_audio);
    if (g_tex) SDL_DestroyTexture(g_tex);
    if (g_ren) SDL_DestroyRenderer(g_ren);
    if (g_win) SDL_DestroyWindow(g_win);
    SDL_Quit();
}

void plat_present(const uint32_t *rgba, int w, int h)
{
    (void)h;
    if (g_headless || !g_tex) return;
    SDL_UpdateTexture(g_tex, NULL, rgba, w * 4);
    SDL_RenderClear(g_ren);
    SDL_RenderCopy(g_ren, g_tex, NULL, NULL);
    SDL_RenderPresent(g_ren);
}

/* SDL scancode -> PC set-1 make code */
static int sc_to_set1(SDL_Scancode s)
{
    if (s >= SDL_SCANCODE_A && s <= SDL_SCANCODE_Z) {
        static const uint8_t az[26] = {0x1E,0x30,0x2E,0x20,0x12,0x21,0x22,0x23,0x17,0x24,0x25,0x26,0x32,0x31,0x18,0x19,0x10,0x13,0x1F,0x14,0x16,0x2F,0x11,0x2D,0x15,0x2C};
        return az[s - SDL_SCANCODE_A];
    }
    if (s >= SDL_SCANCODE_1 && s <= SDL_SCANCODE_9) return 0x02 + (s - SDL_SCANCODE_1);
    if (s >= SDL_SCANCODE_F1 && s <= SDL_SCANCODE_F10) return 0x3B + (s - SDL_SCANCODE_F1);
    switch (s) {
    case SDL_SCANCODE_0: return 0x0B; case SDL_SCANCODE_RETURN: return 0x1C; case SDL_SCANCODE_ESCAPE: return 0x01;
    case SDL_SCANCODE_BACKSPACE: return 0x0E; case SDL_SCANCODE_TAB: return 0x0F; case SDL_SCANCODE_SPACE: return 0x39;
    case SDL_SCANCODE_MINUS: return 0x0C; case SDL_SCANCODE_EQUALS: return 0x0D; case SDL_SCANCODE_LEFTBRACKET: return 0x1A;
    case SDL_SCANCODE_RIGHTBRACKET: return 0x1B; case SDL_SCANCODE_BACKSLASH: return 0x2B; case SDL_SCANCODE_SEMICOLON: return 0x27;
    case SDL_SCANCODE_APOSTROPHE: return 0x28; case SDL_SCANCODE_GRAVE: return 0x29; case SDL_SCANCODE_COMMA: return 0x33;
    case SDL_SCANCODE_PERIOD: return 0x34; case SDL_SCANCODE_SLASH: return 0x35;
    case SDL_SCANCODE_LSHIFT: return 0x2A; case SDL_SCANCODE_RSHIFT: return 0x36; case SDL_SCANCODE_LCTRL: case SDL_SCANCODE_RCTRL: return 0x1D;
    case SDL_SCANCODE_LALT: case SDL_SCANCODE_RALT: return 0x38;
    case SDL_SCANCODE_UP: case SDL_SCANCODE_KP_8: return 0x48; case SDL_SCANCODE_DOWN: case SDL_SCANCODE_KP_2: return 0x50;
    case SDL_SCANCODE_LEFT: case SDL_SCANCODE_KP_4: return 0x4B; case SDL_SCANCODE_RIGHT: case SDL_SCANCODE_KP_6: return 0x4D;
    case SDL_SCANCODE_HOME: case SDL_SCANCODE_KP_7: return 0x47; case SDL_SCANCODE_END: case SDL_SCANCODE_KP_1: return 0x4F;
    case SDL_SCANCODE_PAGEUP: case SDL_SCANCODE_KP_9: return 0x49; case SDL_SCANCODE_PAGEDOWN: case SDL_SCANCODE_KP_3: return 0x51;
    case SDL_SCANCODE_INSERT: case SDL_SCANCODE_KP_0: return 0x52; case SDL_SCANCODE_DELETE: case SDL_SCANCODE_KP_PERIOD: return 0x53;
    case SDL_SCANCODE_F11: return 0x57; case SDL_SCANCODE_F12: return 0x58;
    case SDL_SCANCODE_KP_ENTER: return 0x1C; case SDL_SCANCODE_KP_PLUS: return 0x4E; case SDL_SCANCODE_KP_MINUS: return 0x4A;
    default: return 0;
    }
}

static int ascii_for(SDL_Keycode k, int sc, Uint16 mod)
{
    int shift = (mod & KMOD_SHIFT) != 0, ctrl = (mod & KMOD_CTRL) != 0;
    if (k >= 'a' && k <= 'z') { if (ctrl) return k - 'a' + 1; return shift ? k - 32 : k; }
    if (k == SDLK_RETURN || k == SDLK_KP_ENTER) return 13;
    if (k == SDLK_ESCAPE) return 27;
    if (k == SDLK_BACKSPACE) return 8;
    if (k == SDLK_TAB) return 9;
    if (k == SDLK_SPACE) return ' ';
    if (sc >= 0x47 && sc <= 0x53 && sc != 0x4A && sc != 0x4E) return 0;   /* extended keys have no ASCII */
    if (k < 128 && k >= 32) {
        if (shift) {
            static const char *from = "1234567890-=[]\;',./`", *to = "!@#$%^&*()_+{}|:\"<>?~";
            const char *p = strchr(from, (int)k); if (p) return to[p - from];
        }
        return (int)k;
    }
    return 0;
}

void plat_pump(void)
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_QUIT: rt_request_quit(); break;
        case SDL_KEYDOWN: case SDL_KEYUP: {
            int down = e.type == SDL_KEYDOWN;
            if (down && e.key.keysym.sym == SDLK_F11 && g_win) {
                Uint32 f = SDL_GetWindowFlags(g_win) & SDL_WINDOW_FULLSCREEN_DESKTOP;
                SDL_SetWindowFullscreen(g_win, f ? 0 : SDL_WINDOW_FULLSCREEN_DESKTOP);
                break;
            }
            if (e.key.repeat && !down) break;
            int sc = sc_to_set1(e.key.keysym.scancode);
            if (!sc) break;
            rt_key_event(sc, ascii_for(e.key.keysym.sym, sc, e.key.keysym.mod), down);
            break; }
        default: break;
        }
    }
}
