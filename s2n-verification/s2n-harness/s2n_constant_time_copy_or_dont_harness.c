#include "utils/s2n_safety.h"

void *malloc(__CPROVER_size_t);
uint8_t nondet_uint8();
uint32_t nondet_uint32();

int main(int argc, char * const *argv){
        uint8_t *a0, *a, *b, dont;
        uint32_t len;
        int result;

        a0 = malloc(sizeof(uint8_t));
        a = malloc(sizeof(uint8_t));
        b = malloc(sizeof(uint8_t));
        len = nondet_uint32();
        dont = nondet_uint8();

        __CPROVER_assume(len > 0 && len < 1000);

        for(int i = 0; i < len; i++){
                a[i] = a0[i] = nondet_uint8();
                b[i] = nondet_uint8();
        }

        result = s2n_constant_time_copy_or_dont(a, b, len, dont);

        __CPROVER_assert(result == 0, "ERROR: s2n_constant_time_copy_or_dont result");

        if(dont)
                __CPROVER_assert(__CPROVER_forall { int j; (j >= 0 && j < len) ==> a[j] == a[j] }, "ERROR: s2n_constant_time_copy");
        else
                __CPROVER_assert(__CPROVER_forall { int j; (j >= 0 && j < len) ==> a[j] == b[j] }, "ERROR: s2n_constant_time_dont");

        return 0;
}
