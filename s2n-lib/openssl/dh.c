#include <openssl/dh.h>

// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define ENV64BIT
#else
#define ENV32BIT
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENV64BIT
#else
#define ENV32BIT
#endif
#endif

void *malloc(__CPROVER_size_t);
void free(void *);
_Bool nondet_bool();
uint8_t nondet_uint8();
uint16_t nondet_uint16();

/* d2i_X509() attempts to decode len bytes at *out. If successful a pointer to the X509 structure is returned. If an error occurred then NULL is returned. If px is not NULL then the returned structure is written to *px. If *px is not NULL then it is assumed that *px contains a valid X509 structure and an attempt is made to reuse it. If the call is successful *out is incremented to the byte following the parsed data. */

DH *d2i_DHparams(DH **a, unsigned char **pp, long length) {
        return (nondet_bool())? malloc(sizeof(DH)) : NULL;
};

/* DH_size() returns the Diffie-Hellman prime size in bytes. It can be used to determine how much memory must be allocated for the shared secret computed by DH_compute_key(). */
// dh->p must not be NULL;
int DH_size(const DH *dh) {
#if define ENV64BIT
        return nondet_uint16();
#else
        return nondet_uint8();
#endif
};

/* DH_check() confirms that the Diffie-Hellman parameters dh are valid. The value of *codes is updated with any problems found. If *codes is zero then no problems were found, otherwise the following bits may be set:
 * DH_CHECK_P_NOT_PRIME : The parameter p is not prime.
 * DH_CHECK_P_NOT_SAFE_PRIME : The parameter p is not a safe prime and no q value is present.
 * DH_UNABLE_TO_CHECK_GENERATOR : The generator g cannot be checked for suitability.
 * DH_NOT_SUITABLE_GENERATOR : The generator g is not suitable.
 * DH_CHECK_Q_NOT_PRIME : The parameter q is not prime.
 * DH_CHECK_INVALID_Q_VALUE : The parameter q is invalid.
 * DH_CHECK_INVALID_J_VALUE : The parameter j is invalid.
 */
// DH_check() return 1 if the check could be performed, 0 otherwise.
int DH_check(DH *dh, int *codes) {
        return (nondet_bool())? 1 : 0;
};

/* DH_free() frees the DH structure and its components. The values are erased before the memory is returned to the system. If dh is NULL nothing is done. */
void DH_free(DH *dh) {
        if (dh != NULL)
                free(dh); 
        return;
};

/* 
 DH_generate_key() performs the first step of a Diffie-Hellman key exchange by generating private and public DH values. By calling DH_compute_key(), these are combined with the other party's public value to compute the shared key.
 
 DH_generate_key() expects dh to contain the shared parameters dh->p and dh->g. It generates a random private DH value unless dh->priv_key is already set, and computes the corresponding public value dh->pub_key, which can then be published. 
 */

/* DH_generate_key() returns 1 on success, 0 otherwise. */
int DH_generate_key(DH *dh) {
    return (nondet_bool())? 1 : 0;
}
