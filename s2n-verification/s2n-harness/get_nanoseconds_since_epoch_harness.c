// seems no needs a harness for this function

/*#include "tls/s2n_config.h"

void *malloc(__CPROVER_size_t);
uint64_t nondet_uint64();

extern int get_nanoseconds_since_epoch(void *data, uint64_t *nanoseconds);

int main(int argc, char * const *argv){
        void *data;
        uint64_t *nanoseconds;
        int result;

        nanoseconds = (uint64_t *) malloc(sizeof(uint64_t));
        
        result = get_nanoseconds_since_epoch(data, nanoseconds);
        
        __CPROVER_assert(result == 0, "ERROR: get_nanoseconds_since_epoch result");
        __CPROVER_assert(*nanoseconds != NULL, "ERROR: get_nanosecons_since_epoch");

        return 0;
}*/
