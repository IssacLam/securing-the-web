#include <sys/mman.h>

/* diff between _Bool vs int? */
_Bool nondet_bool();

int mlock(const void *addr, size_t len){ return (nondet_bool)? 0 : -1; }

int munlock(const void *addr, size_t len){ return (nondet_bool)? 0 : -1; }

int madvise(void *addr, size_t length, int advice){ return (nondet_bool)? 0 : -1; }
