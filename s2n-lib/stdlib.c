#include <stdlib.h>

#undef posix_memalign

void *malloc(__CPROVER_size_t);

int posix_memalign(void **memptr, size_t alignment, size_t size){
    if(size == 0) {
//        *memptr = NULL;
        return 1;
    }
    
    *memptr = malloc(size);
    return 0;
};
