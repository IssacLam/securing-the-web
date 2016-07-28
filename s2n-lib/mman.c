#include <sys/mman.h>

int nondet_int();

int mlock(const void *addr, size_t len){ return 0; }

int munlock(const void *addr, size_t len){ return nondet_int(); }

int madvise(void *addr, size_t length, int advice){ return nondet_int(); }
