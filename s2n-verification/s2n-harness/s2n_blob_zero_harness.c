#include <string.h>

#include "error/s2n_errno.h"

#include "utils/s2n_safety.h"
#include "utils/s2n_blob.h"

#include <s2n.h>

uint32_t nondet_uint32();
uint8_t nondet_uint8();
void *malloc(__CPROVER_size_t);

int main(int argc, char * const *argv){
        struct s2n_blob *b;
        uint8_t *data;
        uint32_t size;
        int result;

        b = malloc(sizeof(struct s2n_blob));
        b->data = malloc(sizeof(uint8_t));
        b->size = nondet_uint32();

        __CPROVER_assume(size > 0);

        //for(int i = 0; i < size; i++)
        //      data[i] = nondet_uint8();

        result = s2n_blob_zero(b);
        __CPROVER_assert(result == 0, "ERROR: s2n_blob_zero");
        // for (uint32_t i = 0; i < b->size; i++)
        //     __CPROVER_assert(b->data[i] == 0, " ERROR: blob_zero"); 
       __CPROVER_assert(__CPROVER_forall { uint32_t i; i < b->size ==> b->data[i] == 0 }, "ERROR: blob_zero");

        return 0;
} 

