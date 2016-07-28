#include <string.h>

void *malloc(__CPROVER_size_t);
void free(void *ptr);
int nondet_int();

int main(int arc, char** argv){
        int *p;

        // __CPROVER_assert(p == NULL, "p is not initialized");

        p = malloc(1000 * sizeof(int));

        // __CPROVER_assert(p != NULL, "p is null");
        int j = nondet_int();
        __CPROVER_assume(j > 0 && j < 5);

        for(int i = 0; i < j; i++)
                p[i] = nondet_int();

       // memset(p, 0, 1000);

        //free(p);
        return 0;
}
