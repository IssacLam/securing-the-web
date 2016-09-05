#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"
#include <s2n.h>

int main(int arc, char * const *argv){
        GUARD(s2n_init());
        GUARD(s2n_cleanup());
    return 0;
}
