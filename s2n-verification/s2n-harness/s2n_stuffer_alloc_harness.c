#include "stuffer/s2n_stuffer.h"

void *malloc(__CPROVER_size_t);
uint32_t nondet_uint32();

int main(int argc, char * const *argv){
        struct s2n_stuffer *stuffer;
        uint32_t size;
        int result;

        stuffer = malloc(sizeof(struct s2n_stuffer));
        size = nondet_uint32();

       // __CPROVER_assume(stuffer != NULL);

        result = s2n_stuffer_alloc(stuffer, size);

        __CPROVER_assert( result == -1 || result == 0, "ERROR: s2n_stuffer_alloc result");
        __CPROVER_assert( stuffer != NULL, "ERROR: s2n_stuffer_alloc weak condition");
    
        if(result == 0)
            __CPROVER_assert(stuffer->blob.size == size &&
                             stuffer->wiped == 1 &&
                             stuffer->alloced == 1 &&
                             stuffer->growable == 0 &&
                             stuffer->tainted == 0 &&
                             stuffer->read_cursor == 0 &&
                             stuffer->write_cursor == 0, "ERROR: s2n_stuffer_alloc initialization");

        return 0;
}
