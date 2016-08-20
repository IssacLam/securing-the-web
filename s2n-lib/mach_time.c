#include <mach/mach_time.h>

uint64_t nondet_uint64();

_Bool nondet_bool();

// If this is the first time we've run, get the timebase.
// We can use denom == 0 to indicate that sTimebaseInfo is
// uninitialised because it makes no sense to have a zero
// denominator is a fraction.

kern_return_t mach_timebase_info(mach_timebase_info_t info){
    info->numer = (nondet_bool)? 1L : 1000000000L;
    info->denom = (nondet_bool)? 1L : 24965716L;
    return KERN_SUCCESS;
}

uint64_t mach_absolute_time(void) {
    uint64_t t = nondet_uint64();
    __CPROVER_assume(t > 0);
    return t;
}

