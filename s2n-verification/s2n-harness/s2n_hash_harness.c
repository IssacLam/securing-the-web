#include <stdlib.h>
#include <string.h>
#include "stuffer/s2n_stuffer.h"
#include "crypto/s2n_hash.h"
#include "crypto/s2n_hmac.h"

uint32_t nondet_uint32();

s2n_hash_algorithm nondet_s2n_hash_algorithm();

//typedef enum { S2N_HASH_NONE, S2N_HASH_MD5, S2N_HASH_SHA1, S2N_HASH_SHA224, S2N_HASH_SHA256, S2N_HASH_SHA384,
//    S2N_HASH_SHA512, S2N_HASH_MD5_SHA1
//} s2n_hash_algorithm;

int main(int argc, char **argv){
    struct s2n_hash_state hash, copy;

    uint32_t length = nondet_uint32();
    __CPROVER_assume(length > 0);
    
    uint8_t msg[length];
    
    // the value does matter.
//    for(uint32_t i = 0; i < length; i++)
//        msg[i] = nondet_uint8();
    
    s2n_hash_algorithm alg = nondet_s2n_hash_algorithm();
    __CPROVER_assume(alg >= 0 && alg < 8);
    
    if(alg > 0 && alg < 8)
        uint8_t output_pad0[s2n_hash_digest_size(alg)], output_pad[s2n_hash_digest_size(alg)];
    
    s2n_hash_digest_size(alg);
    s2n_hash_init(&hash, alg);
    s2n_hash_update(&hash, msg, length);
    s2n_hash_copy(&copy, &hash);
    s2n_hash_digest(&hash, output_pad, s2n_hash_digest_size(alg));
    
    if (alg != S2N_HASH_NONE) {
        uint8_t t = output_pad[s2n_hash_digest_size(alg) - 1]; // try to read something
        
    // Z3 error: operator is applied to arguments of the wrong sort ????
//        uint32_t size = s2n_hash_digest_size(alg);
//        __CPROVER_assert(__CPROVER_exists { uint32_t j; j < size ==> output_pad0[j] != output_pad[j] }, "ERROR: s2n_hash_digest");
    }
    
    return 0;
}
