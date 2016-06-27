#include <stdlib.h>

#undef posix_memalign

void *malloc(__CPROVER_size_t);

int posix_memalign(void **memptr, size_t alignment, size_t size){
        *memptr = (size == 0) ? NULL : malloc(size);
        return 0;
};
