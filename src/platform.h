/* platform.h - the thin host layer (window, input, audio, clocks). */
#ifndef EMPIRES_PLATFORM_H
#define EMPIRES_PLATFORM_H
#include <stdint.h>

int      plat_init(int headless, int scale, int fullscreen);   /* 0 = ok */
void     plat_shutdown(void);
void     plat_pump(void);                                      /* events -> rt_key_event / rt_request_quit */
void     plat_present(const uint32_t *rgba, int w, int h);     /* 0xAARRGGBB pixels */
void     plat_speaker(int hz);                                 /* 0 = silent */
uint32_t plat_ticks_ms(void);
uint64_t plat_ticks_us(void);
void     plat_sleep_ms(uint32_t ms);

#endif
