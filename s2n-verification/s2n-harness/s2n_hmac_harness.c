#include <stdlib.h>
#include "stuffer/s2n_stuffer.h"
#include "crypto/s2n_hash.h"
#include "crypto/s2n_hmac.h"

void *malloc(__CPROVER_size_t);
void free(void *ptr);
uint8_t nondet_uint8();
uint64_t nondet_uint64();

int main(int argc, char **argv){
        uint8_t digest_pad[256];
        uint8_t check_pad[256];
        uint8_t output_pad[256];
        struct s2n_stuffer output;
        uint8_t sekrit[] = "sekrit";

        uint8_t *msg;
        uint64_t length;
        
        struct s2n_hmac_state hmac, copy;
        struct s2n_hmac_state cmac;

        struct s2n_blob out = {.data = output_pad, .size = sizeof(output_pad) };
        
        //length = nondet_uint8();
        length = 1000;
        __CPROVER_assume(length <= 1000);
        msg = malloc(sizeof(uint8_t) * length);

        for(uint64_t i = 0; i < length; i++)
                msg[i] = nondet_uint8();

        s2n_stuffer_init(&output, &out);
        s2n_hmac_digest_size(S2N_HMAC_SHA1);
        s2n_hmac_init(&hmac, S2N_HMAC_SHA1, sekrit, 7); //strlen((char *) sekrit));
        s2n_hmac_update(&hmac, msg, length);
        //s2n_hmac_copy(&copy, &hmac);
        
        s2n_hmac_digest(&hmac, digest_pad, 20);        
        s2n_hmac_reset(&hmac);
        
        // 2nd round
        //s2n_hmac_update(&hmac, msg, length);
        //s2n_hmac_digest(&hmac, digest_pad, 20);
        //s2n_hmac_reset(&hmac);


        free(msg);
        return 0;
}
