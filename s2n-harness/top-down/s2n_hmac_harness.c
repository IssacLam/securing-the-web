#include <stdlib.h>
#include <string.h>
#include "stuffer/s2n_stuffer.h"
#include "crypto/s2n_hash.h"
#include "crypto/s2n_hmac.h"

uint8_t nondet_uint8();
uint32_t nondet_uint32();
_Bool nondet_bool();
s2n_hmac_algorithm nondet_s2n_hmac_algorithm();

//typedef enum { S2N_HMAC_NONE, S2N_HMAC_MD5, S2N_HMAC_SHA1, S2N_HMAC_SHA224, S2N_HMAC_SHA256, S2N_HMAC_SHA384, S2N_HMAC_SHA512, S2N_HMAC_SSLv3_MD5, S2N_HMAC_SSLv3_SHA1 } s2n_hmac_algorithm;

int main(int argc, char **argv){
        uint8_t output_pad[256];

        uint32_t sekritSize = nondet_uint32();
        __CPROVER_assume(sekritSize > 0);

        uint32_t msgSize = nondet_uint32();
        __CPROVER_assume(msgSize > 0);

        uint8_t sekrit[sekritSize];
        uint8_t msg[msgSize];
        struct s2n_hmac_state hmac, copy;

        while(nondet_bool()){
                //s2n_hmac_algorithm alg = S2N_HMAC_SHA1;
                s2n_hmac_algorithm alg = nondet_s2n_hmac_algorithm();
                __CPROVER_assume(alg >= 0 && alg < 9);

                uint8_t digestSize = s2n_hmac_digest_size(alg);
                s2n_hmac_init(&hmac, alg, sekrit, sekritSize);
                s2n_hmac_update(&hmac, msg, msgSize);
                //s2n_hmac_copy(&copy, &hmac);
                s2n_hmac_digest(&hmac, output_pad, digestSize);

                // actually this check is meaningless, isn't it?
                // it only ensure digestSize - 1 <= 255
                if(alg != S2N_HMAC_NONE)
                    uint8_t t = output_pad[digestSize - 1];
        }
        return 0;
}
