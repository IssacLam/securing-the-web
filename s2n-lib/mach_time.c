#include <mach/mach_time.h>

uint32_t nondet_uint32();
uint64_t nondet_uint64();


// If this is the first time we've run, get the timebase.
// We can use denom == 0 to indicate that sTimebaseInfo is
// uninitialised because it makes no sense to have a zero
// denominator is a fraction.

kern_return_t mach_timebase_info(mach_timebase_info_t info){
    info->numer = nondet_uint32();
    info->denom = nondet_uint32();
    __CPROVER_assume(info->denom > 0);
    return KERN_SUCCESS;
}

uint64_t mach_absolute_time(void) {
    return nondet_uint64();
}

