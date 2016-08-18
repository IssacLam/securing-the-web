#include <stdint.h>
#include "utils/s2n_timer.h"
#include "tls/s2n_config.h"

uint64_t nondet_uint64();

int mock_clock(void *in, uint64_t *out)
{
    *out = *(uint64_t *)in;
    return 0;
}

int main(int argc, char **argv)
{
    struct s2n_config config;
    struct s2n_timer timer;
    uint64_t nanoseconds;
    uint64_t mock_time;
    uint64_t elapsed;

    s2n_config_set_nanoseconds_since_epoch_callback(&config, mock_clock, &mock_time);

    mock_time = 0;
    s2n_timer_start(&config, &timer);

    elapsed = nondet_uint64();
    mock_time += elapsed;
    
    s2n_timer_reset(&config, &timer, &nanoseconds);
    __CPROVER_assert(nanoseconds == mock_time, "ERROR: s2n_timer_reset");

    elapsed = nondet_uint64();
    __CPROVER_assume(elapsed <= (UINT64_MAX - mock_time));
    mock_time += elapsed;

    s2n_timer_elapsed(&config, &timer, &nanoseconds);
    __CPROVER_assert(nanoseconds == elapsed, "ERROR:s2n_timer_reset");
}
