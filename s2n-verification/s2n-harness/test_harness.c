#include <string.h>

void *malloc(__CPROVER_size_t);
void free(void *ptr);

int main(int arc, char** argv){
        int *p;

        __CPROVER_assert(!p, "p is null");
        p = malloc(1000 * sizeof(int));
        
        free(p);
        return 0;
}
