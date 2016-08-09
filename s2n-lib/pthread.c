#include <pthread.h>

_Bool nondet_bool();

int pthread_atfork(void (*prepare)(void), void (*parent)(void), void (*child)(void)) {
	return (nondet_bool)? 0 : 1;
}