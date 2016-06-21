#include "stuffer/s2n_stuffer.h"

void *malloc(__CPROVER_size_t);
uint32_t nondet_uint32();

int main(int argc, char * const *argv){
        struct s2n_stuffer *stuffer;
        struct s2n_blob *in;
        int result;

        stuffer = malloc(sizeof(struct s2n_stuffer));
        in = malloc(sizeof(struct s2n_blob));
        in->data = malloc(sizeof(uint8_t));
        in->size = nondet_uint32();

        __CPROVER_assume(stuffer != NULL && in != NULL && in->data != NULL && in->size > 0);
        
        result = s2n_stuffer_init(stuffer, in);

        __CPROVER_assert(result == 0, "ERROR: s2n_stuffer_init result");
        __CPROVER_assert(stuffer != NULL && in != NULL && in->data != NULL && in->size > 0, "ERROR: s2n_stuffer_init weak condition");
        __CPROVER_assert(stuffer->blob.data == in->data &&
                        stuffer->blob.size == in->size &&
                        stuffer->wiped == 1 &&
                        stuffer->alloced == 0 &&
                        stuffer->growable == 0 &&
                        stuffer->tainted == 0 &&
                        stuffer->read_cursor == 0 &&
                        stuffer->write_cursor == 0, "ERROR: s2n_stuffer_init initialization");
        return 0;
}

