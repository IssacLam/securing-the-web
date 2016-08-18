#include <stdlib.h>
#include <string.h>
#include <CommonCrypto/CommonDigest.h>

void *malloc(__CPROVER_size_t);
void free(void *ptr);
uint8_t nondet_uint8();
uint32_t nondet_uint32();

CC_MD2_CTX nondet_CC_MD2_CTX();
CC_MD4_CTX nondet_CC_MD4_CTX();
CC_MD5_CTX nondet_CC_MD5_CTX();
CC_SHA1_CTX nondet_CC_SHA1_CTX();
CC_SHA256_CTX nondet_CC_SHA256_CTX();
CC_SHA512_CTX nondet_CC_SHA512_CTX();

#define MD2_DIGEST_SIZE         16
#define MD4_DIGEST_SIZE         16
#define MD5_DIGEST_SIZE         16

#define SHA1_DIGEST_SIZE        20
#define SHA1_BLOCK_SIZE         64

#define SHA224_DIGEST_SIZE      28
#define SHA224_BLOCK_SIZE       64

#define SHA256_DIGEST_SIZE      32
#define SHA256_BLOCK_SIZE       64

#define SHA384_DIGEST_SIZE      48
#define SHA384_BLOCK_SIZE       128

#define SHA512_DIGEST_SIZE      64
#define SHA512_BLOCK_SIZE       128


int CC_MD2_Init(CC_MD2_CTX *c) {
        __CPROVER_assert(c != NULL, "ERROR: CC_MD2_Init c is null");
        *c = nondet_CC_MD2_CTX();
    
        return 1;
};

int CC_MD2_Update(CC_MD2_CTX *c, const void *data, CC_LONG len) {
    __CPROVER_assert(c != NULL, "ERROR: CC_MD2_Update c is null");
    __CPROVER_assert(data != NULL, "ERROR: CC_MD2_Update data is null");
    
    uint8_t v = ((uint8_t *) data)[len-1]; // read something from data
    
    *c = nondet_CC_MD2_CTX(); // update the context we are not instrested
    
    return 1;
};

int CC_MD2_Final(unsigned char *md, CC_MD2_CTX *c) {
    __CPROVER_assert(md != NULL, "ERROR: CC_MD2_Final md is null");
    __CPROVER_assert(c != NULL, "ERROR: CC_MD2_Final c is null");
    
    *c = nondet_CC_MD2_CTX(); // final update, we don't care about the value
    
   // for (uint8_t i = 0; i < MD2_DIGEST_SIZE; i++)
    md[MD2_DIGEST_SIZE - 1] = nondet_uint8();  // write something to the last index of an array
        
    return 1;
};

unsigned char *CC_MD2(const void *data, CC_LONG len, unsigned char *md) { return NULL; };

int CC_MD4_Init(CC_MD4_CTX *c) {
    __CPROVER_assert(c != NULL, "ERROR: CC_MD4_Init c is null");
    *c = nondet_CC_MD4_CTX();
    
    return 1;
};

int CC_MD4_Update(CC_MD4_CTX *c, const void *data, CC_LONG len) {
    __CPROVER_assert(c != NULL, "ERROR: CC_MD4_Update c is null");
    __CPROVER_assert(data != NULL, "ERROR: CC_MD4_Update data is null");
    
    uint8_t v = ((uint8_t *) data)[len-1]; // read something from data
    
    *c = nondet_CC_MD4_CTX(); // update the context we are not instrested
    
    return 1;
};

int CC_MD4_Final(unsigned char *md, CC_MD4_CTX *c) {
    __CPROVER_assert(md != NULL, "ERROR: CC_MD4_Final md is null");
    __CPROVER_assert(c != NULL, "ERROR: CC_MD4_Final c is null");
    
    *c = nondet_CC_MD4_CTX(); // final update, we don't care about the value
    
    md[MD4_DIGEST_SIZE - 1] = nondet_uint8();         //return not deterministic hmac value

    return 1;
};

unsigned char *CC_MD4(const void *data, CC_LONG len, unsigned char *md) { return NULL; };

int CC_MD5_Init(CC_MD5_CTX *c) {
    __CPROVER_assert(c != NULL, "ERROR: CC_MD5_Init c is null");
    *c = nondet_CC_MD5_CTX();
    
    return 1;
};

int CC_MD5_Update(CC_MD5_CTX *c, const void *data, CC_LONG len) {
    __CPROVER_assert(c != NULL, "ERROR: CC_MD5_Update c is null");
    __CPROVER_assert(data != NULL, "ERROR: CC_MD5_Update data is null");
    
    uint8_t v = ((uint8_t *) data)[len-1]; // read something from data
    
    *c = nondet_CC_MD5_CTX(); // update the context we are not instrested
    
    return 1;
};

int CC_MD5_Final(unsigned char *md, CC_MD5_CTX *c) {
    __CPROVER_assert(md != NULL, "ERROR: CC_MD5_Final md is null");
    __CPROVER_assert(c != NULL, "ERROR: CC_MD5_Final c is null");
    
    *c = nondet_CC_MD5_CTX(); // final update, we don't care about the value
    
    // for (uint8_t i = 0; i < MD5_DIGEST_SIZE; i++)
        md[MD5_DIGEST_SIZE - 1] = nondet_uint8();         //return not deterministic hmac value
    
    return 1;
};

unsigned char *CC_MD5(const void *data, CC_LONG len, unsigned char *md) { return NULL; };

// The property are captured according to US Secure Hash Algorithm 1 (SHA1) - rfc 3174

// initialized with sha1 constant
int CC_SHA1_Init(CC_SHA1_CTX *c){
    /* ensure the pointer of c is valid */
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA1_Init c is null");
    
    /* assign a non-deterministic value to the variable c. */
    *c = nondet_CC_SHA1_CTX();
    return 1;
};

int CC_SHA1_Update(CC_SHA1_CTX *c, const void *data, CC_LONG len){
    /* ensure the parameters are valid */
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA1_Update c is null");
    __CPROVER_assert(data != NULL, "ERROR: CC_SHA1_Update data is null");
    __CPROVER_assert(len > 0, "ERROR: CC_SHA1_Update len is less than or equal to zero");
    
    /* read something from data */
    ((uint8_t *) data)[len-1];

    /* try to write something to the variable */
    *c = nondet_CC_SHA1_CTX();
    return 1;
};

int CC_SHA1_Final(unsigned char *md, CC_SHA1_CTX *c){
    /* ensure the pointers are valid */
    __CPROVER_assert(md != NULL, "ERROR: CC_SHA1_Final md is null");
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA1_Final c is null");

    /* try to write something to the variable */
    *c = nondet_CC_SHA1_CTX();

    /* try to access the output pointer */
    md[SHA1_DIGEST_SIZE - 1];
    return 1;
};

unsigned char *CC_SHA1(const void *data, CC_LONG len, unsigned char *md){ return NULL; };

int CC_SHA224_Init(CC_SHA256_CTX *c){
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA224_Init c is null");
    *c = nondet_CC_SHA256_CTX();
    
    return 1;
};

int CC_SHA224_Update(CC_SHA256_CTX *c, const void *data, CC_LONG len){
    CC_SHA256_Update(c, data, len);
    
    return 1;
};

int CC_SHA224_Final(unsigned char *md, CC_SHA256_CTX *c){
    __CPROVER_assert(md != NULL, "ERROR: CC_SHA224_Final md is null");
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA224_Final c is null");
    
    *c = nondet_CC_SHA256_CTX(); // final update, we don't care about the value
    
    md[SHA224_DIGEST_SIZE - 1] = nondet_uint8();         //return not deterministic hmac value
    return 1;
};

unsigned char *CC_SHA224(const void *data, CC_LONG len, unsigned char *md){ return NULL; };

int CC_SHA256_Init(CC_SHA256_CTX *c){
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA256_Init c is null");
    *c = nondet_CC_SHA256_CTX();
    
    return 1;
};

int CC_SHA256_Update(CC_SHA256_CTX *c, const void *data, CC_LONG len){
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA256_Update c is null");
    __CPROVER_assert(data != NULL, "ERROR: CC_SHA256_Update data is null");
    
    uint8_t v = ((uint8_t *) data)[len-1]; // read something from data
    
    *c = nondet_CC_SHA256_CTX(); // update the context we are not instrested
    
    return 1;
};

int CC_SHA256_Final(unsigned char *md, CC_SHA256_CTX *c){
    __CPROVER_assert(md != NULL, "ERROR: CC_SHA256_Final md is null");
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA256_Final c is null");
    
    *c = nondet_CC_SHA256_CTX(); // final update, we don't care about the value
    
    md[SHA256_DIGEST_SIZE - 1] = nondet_uint8();
    return 1;
};

unsigned char *CC_SHA256(const void *data, CC_LONG len, unsigned char *md){ return NULL; };

int CC_SHA384_Init(CC_SHA512_CTX *c){
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA384_Init c is null");
    *c = nondet_CC_SHA512_CTX();
    
    return 1;
};

int CC_SHA384_Update(CC_SHA512_CTX *c, const void *data, CC_LONG len){
    CC_SHA512_Update(c, data, len);
    
    return 1;
};

int CC_SHA384_Final(unsigned char *md, CC_SHA512_CTX *c){
    __CPROVER_assert(md != NULL, "ERROR: CC_SHA348_Final md is null");
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA348_Final c is null");
    
    *c = nondet_CC_SHA512_CTX(); // final update, we don't care about the value
    
    md[SHA384_DIGEST_SIZE - 1];
    
    return 1;
};

unsigned char *CC_SHA384(const void *data, CC_LONG len, unsigned char *md){ return NULL; };

int CC_SHA512_Init(CC_SHA512_CTX *c){
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA512_Init c is null");
    *c = nondet_CC_SHA512_CTX();
    
    return 1;
};

int CC_SHA512_Update(CC_SHA512_CTX *c, const void *data, CC_LONG len){
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA512_Update c is null");
    __CPROVER_assert(data != NULL, "ERROR: CC_SHA512_Update data is null");
    
    uint8_t v = ((uint8_t *) data)[len-1]; // read something from data
    
    *c = nondet_CC_SHA512_CTX(); // update the context we are not instrested
    
    return 1;
};

int CC_SHA512_Final(unsigned char *md, CC_SHA512_CTX *c){
    __CPROVER_assert(md != NULL, "ERROR: CC_SHA512_Final md is null");
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA512_Final c is null");
    
    *c = nondet_CC_SHA512_CTX(); // final update, we don't care about the value
    
    md[SHA512_DIGEST_SIZE - 1];         //return not deterministic hmac value
    
    return 1;
};

unsigned char *CC_SHA512(const void *data, CC_LONG len, unsigned char *md){ return NULL; };
