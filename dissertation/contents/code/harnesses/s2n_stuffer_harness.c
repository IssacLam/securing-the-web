#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include "stuffer/s2n_stuffer.h"

uint32_t nondet_uint32();
uint64_t nondet_uint64();
_Bool nondet_bool();

int main(int argc, char **argv)
{
    uint8_t u8; uint16_t u16; uint32_t u32;
    
    uint32_t stuffer_size = nondet_uint32();
	__CPROVER_assume(stuffer_size > 0);
	
	uint32_t entropy_size = nondet_uint32();
	__CPROVER_assume(entropy_size > 0);
	
	uint8_t entropy[entropy_size];
    struct s2n_stuffer stuffer;
	
    GUARD(s2n_stuffer_alloc(&stuffer, stuffer_size));

    struct s2n_blob in = {.data = entropy,.size = entropy_size};
    GUARD(s2n_stuffer_write(&stuffer, &in));

	GUARD(s2n_stuffer_wipe(&stuffer));
	while(nondet_bool()) {
        GUARD(s2n_stuffer_write_uint8(&stuffer, nondet_uint64()));
    }

    while(nondet_bool()) {
        GUARD(s2n_stuffer_read_uint8(&stuffer, &u8));
    }

    GUARD(s2n_stuffer_wipe(&stuffer));
    while(nondet_bool()) {
        GUARD(s2n_stuffer_write_uint16(&stuffer, nondet_uint64()));
    }

    while(nondet_bool()) {
        GUARD(s2n_stuffer_read_uint16(&stuffer, &u16));
    }

    GUARD(s2n_stuffer_wipe(&stuffer));
    while(nondet_bool()) {
        GUARD(s2n_stuffer_write_uint24(&stuffer, nondet_uint64()));
    }

    while(nondet_bool()) {
        GUARD(s2n_stuffer_read_uint24(&stuffer, &u32));
    }

    GUARD(s2n_stuffer_wipe(&stuffer));
    while(nondet_bool()) {
        GUARD(s2n_stuffer_write_uint32(&stuffer, nondet_uint64()));
    }

    while(nondet_bool()) {
        GUARD(s2n_stuffer_read_uint32(&stuffer, &u32));
    }

    GUARD(s2n_stuffer_free(&stuffer));
}
