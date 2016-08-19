#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include "stuffer/s2n_stuffer.h"

#define S2N_PEM_LINE_LENGTH 64
uint32_t nondet_uint32();

int main(int argc, char **argv)
{
    uint32_t message_size = nondet_uint32();
    __CPROVER_assume(message_size > 0 && message_size < 49);
    
    char message[message_size];
//    __CPROVER_assume(message[message_size-1] == '\0');
    
    uint32_t base64_message_size = message_size * 4 / 3;
    uint32_t scratch_size = S2N_PEM_LINE_LENGTH + 1;
    
    struct s2n_stuffer stuffer, data, scratch;
    
    GUARD(s2n_stuffer_alloc(&stuffer, base64_message_size));
    
    /* Write our known data */
    GUARD(s2n_stuffer_alloc_ro_from_string(&data, message));

    GUARD(s2n_stuffer_write_base64(&stuffer, &data));
    GUARD(s2n_stuffer_free(&data));
    
    GUARD(s2n_stuffer_alloc(&scratch, scratch_size));
    GUARD(s2n_stuffer_read_base64(&stuffer, &scratch));
    
    GUARD(s2n_stuffer_free(&stuffer));
    GUARD(s2n_stuffer_free(&scratch));

	return 0;
}