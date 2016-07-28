#include <stdlib.h>
#include <string.h>
#include "stuffer/s2n_stuffer.h"
#include "crypto/s2n_hash.h"
#include "crypto/s2n_hmac.h"

uint32_t nondet_uint32();
_Bool nondet_bool();

s2n_hash_algorithm nondet_s2n_hash_algorithm();

//typedef enum { S2N_HASH_NONE, S2N_HASH_MD5, S2N_HASH_SHA1, S2N_HASH_SHA224, S2N_HASH_SHA256, S2N_HASH_SHA384, S2N_HASH_SHA512, S2N_HASH_MD5_SHA1 } s2n_hash_algorithm;

int main(int argc, char **argv){
        struct s2n_hash_state hash, copy;
        uint8_t output_pad[64];

        uint32_t length = nondet_uint32();
        __CPROVER_assume(length > 0);

        uint8_t msg[length];

        while(nondet_bool()){ // try to use the same s2n_hash_state multiple times.
            s2n_hash_algorithm alg = S2N_HASH_SHA1;
//                s2n_hash_algorithm alg = nondet_s2n_hash_algorithm();
                __CPROVER_assume(alg >= 0 && alg <= 7);
            
                uint8_t digestSize = s2n_hash_digest_size(alg);
            
//                if(alg != S2N_HASH_NONE)
//                    uint8_t output_pad0 = output_pad[digestSize - 1];
            
                // normal hash flow
                s2n_hash_digest_size(alg);
                s2n_hash_init(&hash, alg);
                s2n_hash_update(&hash, msg, length);
                // only the hash state is changed
                s2n_hash_copy(&copy, &hash);
                s2n_hash_digest(&hash, output_pad, digestSize);

                if(alg != S2N_HASH_NONE) {
                    uint8_t t = output_pad[digestSize - 1]; // try to read something
                    // __CPROVER_assert(t != op0, "ERROR: nothing changed.");
                }
        }
        return 0;
}
