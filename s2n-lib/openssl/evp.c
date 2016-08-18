#include <openssl/evp.h>
#include <string.h>

void *malloc(__CPROVER_size_t);
void free(void *);
_Bool nondet_bool();
EVP_CIPHER_CTX nondet_evp_cipher();

/*struct evp_cipher_st
  {
  int nid;
  int block_size;
  int key_len;        // Default value for variable length ciphers
  int iv_len;
  unsigned long flags;    // Various flags
  int (*init)(EVP_CIPHER_CTX *ctx, const unsigned char *key, const unsigned char *iv, int enc);  // init key 
  int (*do_cipher)(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, unsigned int inl); // encrypt/decrypt data
  int (*cleanup)(EVP_CIPHER_CTX *); // cleanup ctx
  int ctx_size;       // how big ctx->cipher_data needs to be
  int (*set_asn1_parameters)(EVP_CIPHER_CTX *, ASN1_TYPE *); // Populate a ASN1_TYPE with parameters
  int (*get_asn1_parameters)(EVP_CIPHER_CTX *, ASN1_TYPE *); // Get parameters from a ASN1_TYPE
  int (*ctrl)(EVP_CIPHER_CTX *, int type, int arg, void *ptr); // Miscellaneous operations
  void *app_data;     // Application data 
  } // EVP_CIPHER ;
*/

/* EVP_CIPHER_CTX_init() initializes cipher contex ctx. */
/* 
 * EVP_CIPHER_CTX ctx;
 * EVP_CIPHER_CTX_init(&ctx);
 */
void EVP_CIPHER_CTX_init(EVP_CIPHER_CTX *ctx) {
        memset(ctx, 0, sizeof(EVP_CIPHER_CTX));
//        *a = nondet_evp_cipher();
        return;
}

/* EVP_EncryptInit_ex() sets up cipher context ctx for encryption with cipher type from ENGINE impl. ctx must be initialized before calling this function. type is normally supplied by a function such as EVP_des_cbc(). If impl is NULL then the default implementation is used. key is the symmetric key to use and iv is the IV to use (if necessary), the actual number of bytes used for the key and IV depends on the cipher. It is possible to set all parameters to NULL except type in an initial call and supply the remaining parameters in subsequent calls, all of which have type set to NULL . This is done when the default cipher parameters are not appropriate. */

/*
 * EVP_EncryptInit_ex(&ctx, EVP_aes_128_ecb(), 0, key, iv);
 */
int EVP_EncryptInit_ex(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *type, ENGINE *impl, unsigned char *key, unsigned char *iv) {
        return (nondet_bool())? 1 : 0;
}

// Return a object for EVP_EncryptInit_ex, doesn't matter. 
EVP_CIPHER *EVP_aes_128_ecb(void) {
        return NULL;
}

/* EVP_CIPHER_CTX_cleanup() clears all information from a cipher context and free up any allocated memory associate with it. It should be called after all operations using a cipher are complete so sensitive information does not remain in memory. */
/*
 * EVP_CIPHER_CTX_cleanup(&ctx);
 */
// EVP_CIPHER_CTX_cleanup() returns 1 for success and 0 for failure.
int EVP_CIPHER_CTX_cleanup(EVP_CIPHER_CTX *ctx) {
        if(ctx == NULL)
                return 0;
        memset(ctx, 0, sizeof(EVP_CIPHER_CTX));
//        free(a);
        return 1;
}

int EVP_EncryptUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl, unsigned char *in, int inl) {
    // read something from in
    in[inl-1];
    return (nondet_bool())? 1 : 0;
}


