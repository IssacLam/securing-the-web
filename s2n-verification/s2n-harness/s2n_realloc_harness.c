#include <stdlib.h>
#include "utils/s2n_mem.h"

void *malloc(__CPROVER_size_t);
uint32_t nondet_uint32();

int main(int argc, char * const * argv)
{
        struct s2n_blob *b, *b0;
        uint32_t size;
        int result;

        b0 = malloc(sizeof(struct s2n_blob));
        b0->data = malloc(sizeof(uint8_t));
        b0->size = nondet_uint32();
        b0->allocated = nondet_uint32();

        b = malloc(sizeof(struct s2n_blob));
        b->data = malloc(sizeof(uint8_t));
        b->size = b0->size;
        b->allocated = nondet_uint32();

        __CPROVER_assume(b->size >= 0 && b->size <= 1000);
        __CPROVER_assume(b->allocated >= b->size);

        for(uint32_t i = 0; i < b0->size; i++)
                b0->data[i] = b->data[i] = nondet_uint32();

        size = nondet_uint32();

        __CPROVER_assume(size >= 0 && size <= 1000);

        result = s2n_realloc(b, size);

        __CPROVER_assert(result == -1 || (result == 0 &&
                                ((b->size == 0 && b->data == NULL) ||
                                 __CPROVER_forall { int j; (j >= 0 && j < size) ==> b0[j] == b[j] }) && 
                                b->size == size &&
                                b->allocated >= b->size), "ERROR: s2n_realloc");

        return 0;
}
