/* main.c - command line front end for the Ancient Empires static recompilation. */
#include "recomp/runtime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <SDL.h>

static void usage(const char *a0)
{
    printf("Ancient Empires - static recompilation\n"
           "usage: %s [options]\n"
           "  --game-dir <dir>     folder with AEPROG.EXE, AE000.DAT, AE001.DAT (default: .)\n"
           "  --scale <n>          window scale (default 2)\n"
           "  --fullscreen         start fullscreen (F11 toggles)\n"
           "  --headless           no window/audio (testing)\n"
           "  --max-seconds <s>    exit after s seconds (testing)\n"
           "  --frame-dir <dir>    write PPM screenshots (testing)\n"
           "  --frame-every <n>    ...every n presented frames (default 30)\n"
           "  --keys <script>      scripted keys, e.g. 2=ENTER,4=SPACE (testing)\n"
           "  --wav <file>         capture the game audio to a WAV file (testing)\n"
           "  --adapter <type>     video hardware the game detects: vga (default), ega, tandy, cga\n"
           "  --trace              log DOS file activity and unhandled services\n", a0);
}

int main(int argc, char **argv)
{
    RtConfig c; memset(&c, 0, sizeof c);
    c.game_dir = "."; c.scale = 2; c.frame_every = 30; c.adapter = 5;
    for (int i = 1; i < argc; i++) {
        const char *a = argv[i];
        #define NEXT() (i + 1 < argc ? argv[++i] : (usage(argv[0]), exit(2), ""))
        if (!strcmp(a, "--game-dir")) c.game_dir = NEXT();
        else if (!strcmp(a, "--scale")) c.scale = atoi(NEXT());
        else if (!strcmp(a, "--fullscreen")) c.fullscreen = 1;
        else if (!strcmp(a, "--headless")) c.headless = 1;
        else if (!strcmp(a, "--max-seconds")) c.max_seconds = atof(NEXT());
        else if (!strcmp(a, "--frame-dir")) c.frame_dir = NEXT();
        else if (!strcmp(a, "--frame-every")) c.frame_every = atoi(NEXT());
        else if (!strcmp(a, "--keys")) c.key_script = NEXT();
        else if (!strcmp(a, "--trace")) c.trace = 1;
        else if (!strcmp(a, "--wav")) c.wav_path = NEXT();
        else if (!strcmp(a, "--adapter")) { const char *v = NEXT();
            c.adapter = !strcmp(v, "vga") ? 5 : !strcmp(v, "ega") ? 1 : !strcmp(v, "tandy") ? 3 : !strcmp(v, "cga") ? 0 : atoi(v); }
        else { usage(argv[0]); return !strcmp(a, "--help") ? 0 : 2; }
    }
    int rc = rt_boot(&c);
    if (rc) {
#ifdef _WIN32
        MessageBoxA(NULL, "Could not start. Put AEPROG.EXE, AE000.DAT and AE001.DAT next to the program, or use --game-dir.", "Ancient Empires", MB_OK | MB_ICONERROR);
#endif
        return rc;
    }
    rt_run();
    return 0;
}
