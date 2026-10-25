/* opl.h - AdLib (YM3812/OPL2) emulation, backed by ymfm (BSD-3, Aaron Giles). */
#ifndef EMPIRES_OPL_H
#define EMPIRES_OPL_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

void    opl_init(void);
void    opl_shutdown(void);
void    opl_write(int which, uint8_t v);         /* 0 = address port (388), 1 = data port (389) */
uint8_t opl_read_status(void);                   /* port 388 read */
void    opl_poll(uint64_t now_us);               /* fire expired chip timers */
/* Adds n mono samples (int32, ~16-bit range) to acc at the device rate. */
void    opl_mix(int32_t *acc, int n, int devrate);
int     opl_used(void);                          /* has the guest ever written a register? */

#ifdef __cplusplus
}
#endif
#endif
