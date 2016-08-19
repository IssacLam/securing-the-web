#include <openssl/rsa.h>

void *malloc(__CPROVER_size_t);
void free(void *);
_Bool nondet_bool();

// RSA_free() frees the RSA structure and its components. The key is erased before the memory is returned to the system. If rsa is NULL nothing is done.
// RSA_free() returns no value.
void RSA_free(RSA *rsa) {
        if (rsa != NULL)
                free(rsa);
        return;
};

RSA * d2i_RSAPrivateKey(RSA **a, const unsigned char **pp, long length) {
    return (nondet_bool()) ? (RSA *) malloc(sizeof(RSA)) : NULL;
};