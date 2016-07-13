#include <stdio.h>
#include <stdlib.h>
#include "crypto/s2n_hash.h"

int main(int arc, char** argv){
        printf("%lu\n", sizeof(struct s2n_hash_state));
        return 0;
}
