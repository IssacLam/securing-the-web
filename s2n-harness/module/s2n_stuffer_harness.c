#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include "stuffer/s2n_stuffer.h"

uint32_t nondet_uint32();
uint64_t nondet_uint64();
_Bool nondet_bool();

int main(int argc, char **argv)
{
    uint32_t stuffer_size = nondet_uint32();
	__CPROVER_assert(stuffer_size > 0);
	
	uint32_t entropy_size = nondet_uint32();
	__CPROVER_assert(entropy_size > 0);
	
	uint8_t entropy[entropy_size];
    struct s2n_stuffer stuffer;
	
    uint8_t u8;
    uint16_t u16;
    uint32_t u32;

    /* Create a 100 byte stuffer */
    GUARD(s2n_stuffer_alloc(&stuffer, stuffer_size));

    /* Try to write 101 bytes */
    struct s2n_blob in = {.data = entropy,.size = entropy_size};
    GUARD(s2n_stuffer_write(&stuffer, &in));

    /* Try to write 101 1-byte ints bytes */
	GUARD(s2n_stuffer_wipe(&stuffer));
	while(nondet_bool()) {
        GUARD(s2n_stuffer_write_uint8(&stuffer, nondet_uint64()));
    }

    /* Read those back, and expect the same results */
    while(nondet_bool()) {
        GUARD(s2n_stuffer_read_uint8(&stuffer, &u8));
        // EXPECT_EQUAL(value, u8);
    }

    /* Try to write 51 2-byte ints bytes */
    GUARD(s2n_stuffer_wipe(&stuffer));
    while(nondet_bool()) {
        GUARD(s2n_stuffer_write_uint16(&stuffer, nondet_uint64()));
    }

    /* Read those back, and expect the same results */
    while(nondet_bool()) {
        GUARD(s2n_stuffer_read_uint16(&stuffer, &u16));
        // EXPECT_EQUAL(value, u16);
    }

    /* Try to write 34 3-byte ints bytes */
    GUARD(s2n_stuffer_wipe(&stuffer));
    while(nondet_bool()) {
        GUARD(s2n_stuffer_write_uint24(&stuffer, nondet_uint64()));
    }

    /* Read those back, and expect the same results */
    while(nondet_bool()) {
        GUARD(s2n_stuffer_read_uint24(&stuffer, &u32));
        // EXPECT_EQUAL(value, u32);
    }

    /* Try to write 26 4-byte ints bytes */
    GUARD(s2n_stuffer_wipe(&stuffer));
    while(nondet_bool()) {
        GUARD(s2n_stuffer_write_uint32(&stuffer, nondet_uint64()));
    }

    /* Read those back, and expect the same results */
    while(nondet_bool()) {
        GUARD(s2n_stuffer_read_uint32(&stuffer, &u32));
    }

    GUARD(s2n_stuffer_free(&stuffer));
}
