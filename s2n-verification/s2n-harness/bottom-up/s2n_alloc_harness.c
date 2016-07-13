#include <stdlib.h>
#include "utils/s2n_mem.h"

void *malloc(__CPROVER_size_t);
uint32_t nondet_uint32();

int main(int argc, char * const * argv)
{
        struct s2n_blob *b;
        uint32_t size;
        int result;

        b = malloc(sizeof(struct s2n_blob));
        b->data = malloc(sizeof(uint8_t));
        b->size = nondet_uint32();

        size = nondet_uint32();

        //  __CPROVER_assume(b != NULL);
        __CPROVER_assume(b->size >= 0 && b->size <= 1000);
        __CPROVER_assume(size >= 0 && size <= 1000);

        result = s2n_alloc(b, size);

        // __CPROVER_assert(result == 0, "ERROR: s2n_alloc result");
        __CPROVER_assert(result == -1 || result == 0, "ERROR: s2n_alloc result");

        if(result == 0) {
                //if(size == 0)
                       // __CPROVER_assert(b->data == NULL, "ERROR: s2n_alloc null data"); // is data nondeterministic??
                //else
                  //      __CPROVER_assert(b->data != NULL, "ERROR: sen_alloc data");

                __CPROVER_assert(b->size == size && 
                                b->allocated >= b->size, "ERROR: s2n_alloc");

        }
        return 0;
}
