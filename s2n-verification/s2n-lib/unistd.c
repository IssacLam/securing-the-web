#include <unistd.h>

long int nondet_long();

long int sysconf(int name){
    long int li = nondet_long();
    __CPROVER_assume(li >= 0);
    return li;
};
