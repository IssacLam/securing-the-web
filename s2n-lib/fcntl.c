#include <stdint.h>
#include <fcntl.h>

uint8_t nondet_uint8();

int open(const char *pathname, int flags) {
        return 3;
};

//int open(const char *pathname, int flags, mode_t mode) {
//        return open(pathname, flags);
//};
