#include <stdlib.h>
#include <string.h>
#include <CommonCrypto/CommonDigest.h>

void *malloc(__CPROVER_size_t);
void free(void *ptr);
uint32_t nondet_uint32();

int CC_MD2_Init(CC_MD2_CTX *c) { return 1; };
int CC_MD2_Update(CC_MD2_CTX *c, const void *data, CC_LONG len) { return 1; };
int CC_MD2_Final(unsigned char *md, CC_MD2_CTX *c) { return 1; };
unsigned char *CC_MD2(const void *data, CC_LONG len, unsigned char *md) { return NULL; };

int CC_MD4_Init(CC_MD4_CTX *c) { return 1; };
int CC_MD4_Update(CC_MD4_CTX *c, const void *data, CC_LONG len) { return 1; };
int CC_MD4_Final(unsigned char *md, CC_MD4_CTX *c) { return 1; };
unsigned char *CC_MD4(const void *data, CC_LONG len, unsigned char *md) { return NULL; };

int CC_MD5_Init(CC_MD5_CTX *c) { return 1; };
int CC_MD5_Update(CC_MD5_CTX *c, const void *data, CC_LONG len) { return 1; };
int CC_MD5_Final(unsigned char *md, CC_MD5_CTX *c) { return 1; };
unsigned char *CC_MD5(const void *data, CC_LONG len, unsigned char *md) { return NULL; };

// The property are captured according to US Secure Hash Algorithm 1 (SHA1) - rfc 3174

void SHA1Transform(CC_SHA1_CTX *c, const void *data){
        c->h0 = nondet_uint32();
        c->h1 = nondet_uint32();
        c->h2 = nondet_uint32();
        c->h3 = nondet_uint32();
        c->h4 = nondet_uint32();
}

// initialized with sha1 constant
int CC_SHA1_Init(CC_SHA1_CTX *c){
        __CPROVER_assert(c != NULL, "ERROR: CC_SHA1_Init c is null"); 

        c->h0 = 0x67452301;
        c->h1 = 0xEFCDAB89;
        c->h2 = 0x98BADCFE;
        c->h3 = 0x10325476;
        c->h4 = 0xC3D2E1F0;
        c->Nl = c->Nh = c->num = 0;

        return 1; 
};

#define SHA1_DIGEST_SIZE        20

int CC_SHA1_Update(CC_SHA1_CTX *c, const void *data, CC_LONG len){
        __CPROVER_assert(c != NULL, "ERROR: CC_SHA1_Update c is null");
        __CPROVER_assert(data != NULL, "ERROR: CC_SHA1_Update data is null");

        // calculate the message size
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

        memcpy(&c->data[j], &data[i], len - i); // copy the rest of the bits the data
        return 1; 
};

int CC_SHA1_Final(unsigned char *md, CC_SHA1_CTX *c){
        __CPROVER_assert(md != NULL, "ERROR: CC_SHA1_Final md is null");
        __CPROVER_assert(c != NULL, "ERROR: CC_SHA1_Final c is null");

        uint32_t i;
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
        CC_SHA1_Update(c, finalcount, 8); 
        for (i = 0; i < SHA1_DIGEST_SIZE; i++)
                md[i] = (uint8_t) ((c->data[i >> 2] >> ((3 - (i & 3)) * 8)) & 255);

        //Wipe variables 
        i = 0;
        c->Nl = c->Nh = c->num = 0;
        c->h0 = c->h1 = c->h2 = c->h3 = c->h4 = 0;
        memset(c->data, 0, 8);
        memset(finalcount, 0, 8);

        return 1;
};

unsigned char *CC_SHA1(const void *data, CC_LONG len, unsigned char *md){ return NULL; };

int CC_SHA224_Init(CC_SHA256_CTX *c){ return 1; };
int CC_SHA224_Update(CC_SHA256_CTX *c, const void *data, CC_LONG len){ return 1; };
int CC_SHA224_Final(unsigned char *md, CC_SHA256_CTX *c){ return 1; };
unsigned char *CC_SHA224(const void *data, CC_LONG len, unsigned char *md){ return NULL; };

int CC_SHA256_Init(CC_SHA256_CTX *c){ return 1; };
int CC_SHA256_Update(CC_SHA256_CTX *c, const void *data, CC_LONG len){ return 1; };
int CC_SHA256_Final(unsigned char *md, CC_SHA256_CTX *c){ return 1; };
unsigned char *CC_SHA256(const void *data, CC_LONG len, unsigned char *md){ return NULL; };

int CC_SHA384_Init(CC_SHA512_CTX *c){ return 1; };
int CC_SHA384_Update(CC_SHA512_CTX *c, const void *data, CC_LONG len){ return 1; };
int CC_SHA384_Final(unsigned char *md, CC_SHA512_CTX *c){ return 1; };
unsigned char *CC_SHA384(const void *data, CC_LONG len, unsigned char *md){ return NULL; };

int CC_SHA512_Init(CC_SHA512_CTX *c){ return 1; };
int CC_SHA512_Update(CC_SHA512_CTX *c, const void *data, CC_LONG len){ return 1; };
int CC_SHA512_Final(unsigned char *md, CC_SHA512_CTX *c){ return 1; };
unsigned char *CC_SHA512(const void *data, CC_LONG len, unsigned char *md){ return NULL; };
