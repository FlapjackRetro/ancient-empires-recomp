/* opl.cpp - thin C wrapper around ymfm's YM3812 with wall-clock chip timers. */
#include "opl.h"
#include "../third_party/ymfm/ymfm_opl.h"
#include <mutex>

namespace {

const uint32_t kClock = 3579545;   /* AdLib's crystal */

class Iface : public ymfm::ymfm_interface {
public:
    int64_t deadline_us[2] = {-1, -1};
    int64_t period_us[2] = {0, 0};
    uint64_t now = 0;

    void ymfm_set_timer(uint32_t tnum, int32_t clocks) override {
        if (tnum > 1) return;
        if (clocks < 0) { deadline_us[tnum] = -1; return; }
        period_us[tnum] = (int64_t)clocks * 1000000 / kClock;
        deadline_us[tnum] = (int64_t)now + period_us[tnum];
    }
    void poll(uint64_t t) {
        now = t;
        for (uint32_t i = 0; i < 2; i++) {
            int guard = 0;
            while (deadline_us[i] >= 0 && (int64_t)t >= deadline_us[i] && guard++ < 4) {
                int64_t due = deadline_us[i];
                deadline_us[i] = -1;
                now = (uint64_t)due;                 /* re-arm relative to the expiry, not to now */
                m_engine->engine_timer_expired(i);
            }
            now = t;
        }
    }
};

std::mutex g_mx;
Iface *g_if;
ymfm::ym3812 *g_chip;
uint8_t g_addr;
int g_used;
uint32_t g_rate;
double g_pos;
int32_t g_last, g_cur;

}

extern "C" {

void opl_init(void)
{
    std::lock_guard<std::mutex> l(g_mx);
    if (g_chip) return;
    g_if = new Iface;
    g_chip = new ymfm::ym3812(*g_if);
    g_chip->reset();
    g_rate = g_chip->sample_rate(kClock);
    g_pos = 0; g_last = g_cur = 0;
}

void opl_shutdown(void)
{
    std::lock_guard<std::mutex> l(g_mx);
    delete g_chip; delete g_if; g_chip = nullptr; g_if = nullptr;
}

void opl_write(int which, uint8_t v)
{
    std::lock_guard<std::mutex> l(g_mx);
    if (!g_chip) return;
    if (which == 0) { g_addr = v; g_chip->write_address(v); }
    else { g_chip->write_data(v); g_used = 1; }
}

uint8_t opl_read_status(void)
{
    std::lock_guard<std::mutex> l(g_mx);
    return g_chip ? g_chip->read_status() : 0xFF;
}

void opl_poll(uint64_t now_us)
{
    std::lock_guard<std::mutex> l(g_mx);
    if (g_if) g_if->poll(now_us);
}

int opl_used(void) { return g_used; }

void opl_mix(int32_t *acc, int n, int devrate)
{
    std::lock_guard<std::mutex> l(g_mx);
    if (!g_chip || !g_used) return;
    double step = (double)g_rate / (double)devrate;
    for (int i = 0; i < n; i++) {
        g_pos += step;
        while (g_pos >= 1.0) {
            ymfm::ym3812::output_data o;
            g_chip->generate(&o, 1);
            g_last = g_cur;
            g_cur = o.data[0];
            g_pos -= 1.0;
        }
        double f = g_pos;                                   /* linear interpolation between chip samples */
        acc[i] += (int32_t)((double)g_last * (1.0 - f) + (double)g_cur * f);
    }
}

}
