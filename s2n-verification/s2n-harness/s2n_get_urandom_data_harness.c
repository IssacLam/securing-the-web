#include "utils/s2n_random.h"

void *malloc(__CPROVER_size_t);
uint32_t nondet_uint32();

int main(int argc, char * const *argv){
        struct s2n_blob *b;
        int result;

        b = malloc(sizeof(struct s2n_blob));
        b->data = malloc(sizeof(uint8_t));
        b->size = nondet_uint32();

        __CPROVER_assume(b->size >= 0 && b->size <= 1000);

        for(int i = 0; i < b->size; i++)
                b->data[i] = nondet_uint32();
        
        s2n_init();
        result = s2n_get_urandom_data(b);
        
        __CPROVER_assert(result == -1 || result == 0, "ERROR: s2n_get_urandom_data result");
        
        if(result == 0)
                __CPROVER_assert(__CPROVER_forall { int i; (i >= 0 && i <= b->size) ==> b->data[i] >= 0 }, "ERROR: s2n_get_urandom_data");

        return 0;
}
