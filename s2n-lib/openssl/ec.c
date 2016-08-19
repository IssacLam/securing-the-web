#include <openssl/ec.h>
#include "crypto/ec/ec_lcl.h"

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
uint32_t nondet_uint32();
uint16_t nondet_uint16();
uint8_t nondet_uint8();
_Bool nondet_bool();

/* EC_GROUP_get_degree gets the degree of the field. For Fp fields this will be the number of bits in p. For F2^m fields this will be the value m. */
int EC_GROUP_get_degree(const EC_GROUP *group) {
#if defined(ENV64BIT)
        return nondet_uint16();
#else
        return nondet_uint8();
#endif
};


// refer to quic implementation, the return value should be equal to outlen
// ECDH_compute_key calculates the shared key between pub_key and priv_key. If kdf is not NULL, then it is called with the bytes of the shared key and the parameter out. When kdf returns, the value of *outlen becomes the return value. Otherwise, as many bytes of the shared key as will fit are copied directly to, at most, outlen bytes at out. It returns the number of bytes written to out, or -1 on error.
// https://commondatastorage.googleapis.com/chromium-boringssl-docs/ecdh.h.html
int ECDH_compute_key(void *out, size_t outlen, const EC_POINT *pub_key, EC_KEY *ecdh, void *(*KDF) (const void *in, size_t inlen, void *out, size_t *outlen)) {
        if (KDF == NULL)
                return -1;
        return outlen;
};

/* Calling EC_KEY_free() decrements the reference count for the EC_KEY object, and if it has dropped to zero then frees the memory associated with it. If key is NULL nothing is done. */
// Don't need to handle reference count, as EC_KEY_up_ref() never used.
void EC_KEY_free(EC_KEY *key) {
        if (key != NULL)
                free(key);
        return;
};

/* EC_KEY_new(), EC_KEY_new_by_curve_name() and EC_KEY_dup() return a pointer to the newly created EC_KEY object, or NULL on error. */
EC_KEY *EC_KEY_new_by_curve_name(int nid) {
        return (nondet_bool())? (EC_KEY *)
    malloc(sizeof(EC_KEY)) : NULL;
};

/* EC_KEY_generate_key() generates a new public and private key for the supplied eckey object. eckey must have an EC_GROUP object associated with it before calling this function. The private key is a random integer (0 < priv_key < order, where order is the order of the EC_GROUP object). The public key is an EC_POINT on the curve calculated by multiplying the generator for the curve by the private key. */
// return 1 on success or 0 on error.
int EC_KEY_generate_key(EC_KEY *key) {
        return (nondet_bool())? 1 : 0;
};

const EC_GROUP *EC_KEY_get0_group(const EC_KEY *key) {
        return malloc(sizeof(EC_GROUP));
};

// EC_POINT_new() return the newly allocated EC_POINT or NULL on error;
EC_POINT *EC_POINT_new(const EC_GROUP *group) {
        return (nondet_bool())? malloc(sizeof(EC_POINT)) : NULL;
};

// EC_POINT_oct2point() convert from and to EC_points for the format octet
// return 1 on success or 0 on error
int EC_POINT_oct2point(const EC_GROUP *group, EC_POINT *p, const unsigned char *buf, size_t len, BN_CTX *ctx) {
    if(len && nondet_bool()){
        buf[len - 1];
        return 1;
    }
    return 0;
};

void EC_POINT_free(EC_POINT *point) {
        free(point);
        return;
};

// EC_POINT_point2oct() return the length of the required buffer or 0 on error.
size_t EC_POINT_point2oct(const EC_GROUP *group, const EC_POINT *p, point_conversion_form_t form, unsigned char *buf, size_t len, BN_CTX *ctx) {
#if defined(ENV64BIT)
        return nondet_uint32();
#else
        return nondet_uint16();
#endif
};

const EC_POINT *EC_KEY_get0_public_key(const EC_KEY *key) {
    return key->pub_key;
};

// return 1 on success or 0 on error
int EC_KEY_set_public_key(EC_KEY *key, const EC_POINT *pub){
   return (nondet_bool())? 1 : 0;
};
