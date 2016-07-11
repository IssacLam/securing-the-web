#include <stdlib.h>
#include <string.h>
#include "stuffer/s2n_stuffer.h"
#include "crypto/s2n_hash.h"
#include "crypto/s2n_hmac.h"

void *malloc(__CPROVER_size_t);
void free(void *ptr);
uint8_t nondet_uint8();
uint64_t nondet_uint64();
s2n_hmac_algorithm nondet_s2n_hmac_algorithm();

//typedef enum { S2N_HMAC_NONE, S2N_HMAC_MD5, S2N_HMAC_SHA1, S2N_HMAC_SHA224, S2N_HMAC_SHA256, S2N_HMAC_SHA384,
//    S2N_HMAC_SHA512, S2N_HMAC_SSLv3_MD5, S2N_HMAC_SSLv3_SHA1
//} s2n_hmac_algorithm;

int main(int argc, char **argv){
    uint8_t digest_pad[256];
    uint8_t check_pad[256];
    uint8_t output_pad[256];
    struct s2n_stuffer output;
    uint8_t sekrit[] = "sekrit";
    uint8_t longsekrit[] = "This is a really really really long key on purpose to make sure that it's longer than the block size";
    uint8_t hello[] = "Hello world!";
    struct s2n_hmac_state hmac, copy;
    struct s2n_hmac_state cmac;
    
    
    
    s2n_hmac_digest_size(S2N_HMAC_MD5);
    s2n_hmac_init(&hmac, S2N_HMAC_MD5, sekrit, strlen((char *)sekrit));
    s2n_hmac_update(&hmac, hello, strlen((char *)hello));
    s2n_hmac_copy(&copy, &hmac);
    s2n_hmac_digest(&hmac, output_pad, 16);
    
    for (int i = 0; i < 16; i++) {
        s2n_stuffer_write_uint8_hex(&output, digest_pad[i]);
    }
    
    /* Reference value from python */
    memcmp(output_pad, "3ad68c53dc1a3cf35f6469877fae4585", 16 * 2), 0);

    
    
//        uint8_t digest_pad[256];
//        uint8_t check_pad[256];
//        uint8_t output_pad[256];
//        struct s2n_stuffer output;
    uint8_t sekrit[] = "sekrit";
    uint8_t longsekrit[] = "This is a really really really long key on purpose to make sure that it's longer than the block size";

//        uint8_t *msg;
//        uint64_t length;
    
        struct s2n_hmac_state hmac, copy;
//        struct s2n_hmac_state cmac;

//        struct s2n_blob out = {.data = output_pad, .size = sizeof(output_pad)};
    
        //length = nondet_uint8();
//        length = 1000;
//        __CPROVER_assume(length <= 1000);
//        msg = malloc(sizeof(uint8_t) * length);
//
//        for(uint64_t i = 0; i < length; i++)
//                msg[i] = nondet_uint8();

//        s2n_stuffer_init(&output, &out);
//        s2n_hmac_digest_size(S2N_HMAC_SHA1);
        s2n_hmac_init(&hmac, S2N_HMAC_SHA1, sekrit, strlen((char *) longsekrit));
        //s2n_hmac_update(&hmac, msg, length);
        //s2n_hmac_copy(&copy, &hmac);
        
        //s2n_hmac_digest(&hmac, digest_pad, 20);
        //s2n_hmac_reset(&hmac);
        
        // 2nd round
        //s2n_hmac_update(&hmac, msg, length);
        //s2n_hmac_digest(&hmac, digest_pad, 20);
        //s2n_hmac_reset(&hmac);


//        free(msg);
        return 0;
}
