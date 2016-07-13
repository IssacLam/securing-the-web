#include <stdlib.h>
#include "utils/s2n_mem.h"

void *malloc(__CPROVER_size_t);
uint32_t nondet_uint32();

int main(int argc, char * const * argv)
{
        struct s2n_blob *b;
        int result;

        b = malloc(sizeof(struct s2n_blob));
        b->data = malloc(sizeof(uint8_t));
        b->size = nondet_uint32();
        
        __CPROVER_assume(b != NULL);
        __CPROVER_assume(b->size >= 0);

        result = s2n_free(b);

        //__CPROVER_assert(result == 0, "ERROR: s2n_free result");
        __CPROVER_assert(result == -1 || (result == 0 && 
                        b->data == NULL &&
                        b->size == 0 &&
                        b->allocated == 0 &&
                        b->mlocked == 0), "ERROR: s2n_free");

        return 0;
}
