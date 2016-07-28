#include <openssl/rsa.h>

void free(void *);

// RSA_free() frees the RSA structure and its components. The key is erased before the memory is returned to the system. If rsa is NULL nothing is done.
// RSA_free() returns no value.
void RSA_free(RSA *rsa) {
        if (rsa != NULL)
                free(rsa);
        return;
};
