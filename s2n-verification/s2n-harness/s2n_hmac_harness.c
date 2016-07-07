#include "stuffer/s2n_stuffer.h"
#include "crypto/s2n_hash.h"
#include "crypto/s2n_hmac.h"
#include <string.h>

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

        struct s2n_blob out = {.data = output_pad, .size = sizeof(output_pad) };
        

        s2n_stuffer_init(&output, &out);
        s2n_hmac_digest_size(S2N_HMAC_SHA1);
        s2n_hmac_init(&hmac, S2N_HMAC_SHA1, hello, strlen((char *) hello));
        //s2n_hmac_copy(&copy, &hmac);
 //       s2n_hmac_digest(&hmac, digest_pad, 20);

        //for(int i = 0; i < 16; i++) 
          //  s2n_stuffer_write_uint8_hex(&output, digest_pad[i]);

        //s2n_hmac_digest_verify(digest_pad, check_pad, 16);
//        s2n_hmac_reset(&hmac);

        return 0;
}
