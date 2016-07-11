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
    
    for (uint8_t i = 0; i < MD2_DIGEST_SIZE; i++)
        md[i] = nondet_uint8();         //return not deterministic hmac value
    
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
    
    for (uint8_t i = 0; i < MD4_DIGEST_SIZE; i++)
        md[i] = nondet_uint8();         //return not deterministic hmac value

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
    
    for (uint8_t i = 0; i < MD5_DIGEST_SIZE; i++)
        md[i] = nondet_uint8();         //return not deterministic hmac value
    
    return 1;
};

unsigned char *CC_MD5(const void *data, CC_LONG len, unsigned char *md) { return NULL; };

// The property are captured according to US Secure Hash Algorithm 1 (SHA1) - rfc 3174

// dont need it any more
/*void SHA1Transform(CC_SHA1_CTX *c, const void *data){
        c->h0 = nondet_uint32();
        c->h1 = nondet_uint32();
        c->h2 = nondet_uint32();
        c->h3 = nondet_uint32();
        c->h4 = nondet_uint32();
}*/

// initialized with sha1 constant
int CC_SHA1_Init(CC_SHA1_CTX *c){
        __CPROVER_assert(c != NULL, "ERROR: CC_SHA1_Init c is null"); 
        
        *c = nondet_CC_SHA1_CTX(); //initialized with some values we don't care.

        /*
        c->h0 = 0x67452301;
        c->h1 = 0xEFCDAB89;
        c->h2 = 0x98BADCFE;
        c->h3 = 0x10325476;
        c->h4 = 0xC3D2E1F0;
        c->Nl = c->Nh = c->num = 0;
        */

        return 1; 
};



int CC_SHA1_Update(CC_SHA1_CTX *c, const void *data, CC_LONG len){
        __CPROVER_assert(c != NULL, "ERROR: CC_SHA1_Update c is null");
        __CPROVER_assert(data != NULL, "ERROR: CC_SHA1_Update data is null");

        uint8_t v = ((uint8_t *) data)[len-1]; // read something from data

        *c = nondet_CC_SHA1_CTX(); // update the context we are not instrested

        /*// calculate the message size
        // Nl = low bits, Nh = high bits
        uint32_t i, j;
        j = c->Nl;
        if((c->Nl += len << 3) < j) // if c->Nl overflow let Nh carry it
                c->Nh++;
        c->Nh += (len >> 29); // carry the high bit
        
        j = (j >> 3) & 63; // the remaining bit of previous hashed bits
        if ((j + len) > 63) { // update the state if it form a new block
                memcpy(&c->data[j], data, (i = 64 - j)); // copy part of data to form a new block 
                SHA1Transform(c, c->data); // computate the new state
                for (; i + 63 < len; i += 64) 
                        SHA1Transform(c, &data[i]); // continue until no more block can be formed
                j = 0;
        } else
                i = 0;

        memcpy(&c->data[j], &data[i], len - i); // copy the rest of the bits the data*/
        return 1; 
};

int CC_SHA1_Final(unsigned char *md, CC_SHA1_CTX *c){
        __CPROVER_assert(md != NULL, "ERROR: CC_SHA1_Final md is null");
        __CPROVER_assert(c != NULL, "ERROR: CC_SHA1_Final c is null");

        /*uint32_t i;
        uint8_t finalcount[8];

        // calculate the overall number of bits and turn trim them to char
        for (i = 0; i < 8; i++)
                finalcount[i] = (unsigned char) (((i >= 4 ? c->Nl : c->Nh) >> ((3 - (i & 3)) * 8)) & 255);        // Endian independent 
        
        // Padding 4.a & b
        CC_SHA1_Update(c, (uint8_t *) "\200", 1);
        
        // Padding 4.b
        while ((c->Nl & 504) != 448) 
                CC_SHA1_Update(c, (uint8_t *) "\0", 1);
        
        // Padding 4.c 
        // Should cause a SHA1_Transform();
        CC_SHA1_Update(c, finalcount, 8);*/

       *c = nondet_CC_SHA1_CTX(); // final update, we don't care about the value

        for (uint8_t i = 0; i < SHA1_DIGEST_SIZE; i++)
                md[i] = nondet_uint8();         //return not deterministic hmac value

        //Wipe variables 
        c->Nl = c->Nh = c->num = 0;
        c->h0 = c->h1 = c->h2 = c->h3 = c->h4 = 0;
        memset(c->data, 0, 8);

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
    
    for (uint8_t i = 0; i < SHA224_DIGEST_SIZE; i++)
        md[i] = nondet_uint8();         //return not deterministic hmac value
    
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
    
    for (uint8_t i = 0; i < SHA256_DIGEST_SIZE; i++)
        md[i] = nondet_uint8();         //return not deterministic hmac value
    
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
    
    for (uint8_t i = 0; i < SHA384_DIGEST_SIZE; i++)
        md[i] = nondet_uint8();         //return not deterministic hmac value
    
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
    
    for (uint8_t i = 0; i < SHA512_DIGEST_SIZE; i++)
        md[i] = nondet_uint8();         //return not deterministic hmac value
    
    return 1;
};

unsigned char *CC_SHA512(const void *data, CC_LONG len, unsigned char *md){ return NULL; };
