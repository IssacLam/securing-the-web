
#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include <inttypes.h>
#include <fcntl.h>
#include <s2n.h>

#include <openssl/aes.h>

#include "crypto/s2n_drbg.h"

#include "utils/s2n_safety.h"
#include "utils/s2n_random.h"
#include "utils/s2n_timer.h"

#include "tls/s2n_config.h"

/* Test vectors are taken from http://csrc.nist.gov/groups/STM/cavp/documents/drbg/drbgtestvectors.zip
 * - drbgvectors_no_reseed/CTR_DRBG.txt :
 * [AES-128 no df]
 * [PredictionResistance = False]
 * [EntropyInputLen = 256]
 * [NonceLen = 0]
 * [PersonalizationStringLen = 256]
 * [AdditionalInputLen = 0]
 * [ReturnedBitsLen = 512]
 */

struct s2n_stuffer nist_reference_entropy;
const char nist_reference_entropy_hex[480];
int entropy_fd = -1;

const char nist_reference_personalization_strings_hex[480];

const char nist_reference_values_hex[720];

const char nist_reference_returned_bits_hex[960];

/* This function over-rides the s2n internal copy of the same function */
int nist_fake_urandom_data(struct s2n_blob *blob)
{
    /* At first, we use entropy data provided by the NIST test vectors */
    GUARD(s2n_stuffer_read(&nist_reference_entropy, blob));

    return 0;
}

int main(int argc, char **argv)
{
    uint8_t data[256] = { 0 };
    struct s2n_drbg drbg = {{ 0 }};
    struct s2n_blob blob = {.data = data, .size = 16 };
    struct s2n_timer timer;
    uint64_t drbg_nanoseconds;
    uint64_t urandom_nanoseconds;
    struct s2n_stuffer nist_reference_personalization_strings;
    struct s2n_stuffer nist_reference_returned_bits;
    struct s2n_stuffer nist_reference_values;
    struct s2n_config *config;

    config = s2n_config_new();
    __CPROVER_assert(config != NULL, "ERROR: s2n_config_new()");

    /* Open /dev/urandom */
    entropy_fd = open("/dev/urandom", O_RDONLY);

    /* Convert the hex entropy data into binary */
    GUARD(s2n_stuffer_alloc(&nist_reference_entropy, 480));
    GUARD(s2n_stuffer_alloc(&nist_reference_personalization_strings, 480));
    GUARD(s2n_stuffer_alloc(&nist_reference_returned_bits, 960));
    GUARD(s2n_stuffer_alloc(&nist_reference_values, 720));

    /* Check everything against the NIST vectors */
    for (int i = 0; i < 14; i++) {
        uint8_t ps[32];
        struct s2n_drbg nist_drbg = { .entropy_generator = nist_fake_urandom_data };
        struct s2n_blob personalization_string = {.data = ps, .size = 32};

        /* Read the next personalization string */
        GUARD(s2n_stuffer_read(&nist_reference_personalization_strings, &personalization_string));

        /* Instantiate the DRBG */
        GUARD(s2n_drbg_instantiate(&nist_drbg, &personalization_string));

        uint8_t nist_v[16];

        GUARD(s2n_stuffer_read_bytes(&nist_reference_values, nist_v, sizeof(nist_v)));

        /* Generate 512 bits (FIRST CALL) */
        uint8_t out[64];
        struct s2n_blob generated = {.data = out, .size = 64 };
        GUARD(s2n_drbg_generate(&nist_drbg, &generated));

        GUARD(s2n_stuffer_read_bytes(&nist_reference_values, nist_v, sizeof(nist_v)));

        /* Generate another 512 bits (SECOND CALL) */
        GUARD(s2n_drbg_generate(&nist_drbg, &generated));

        GUARD(s2n_stuffer_read_bytes(&nist_reference_values, nist_v, sizeof(nist_v)));

        uint8_t nist_returned_bits[64];
        GUARD(s2n_stuffer_read_bytes(&nist_reference_returned_bits, nist_returned_bits, sizeof(nist_returned_bits)));

        GUARD(s2n_drbg_wipe(&nist_drbg));
    }

    GUARD(s2n_drbg_instantiate(&drbg, &blob));

    /* Use the DRBG for 16MB of data */
    GUARD(s2n_timer_start(config, &timer));
    for (int i = 0; i < 1000000; i++) {
        GUARD(s2n_drbg_generate(&drbg, &blob));
    }
    GUARD(s2n_timer_reset(config, &timer, &drbg_nanoseconds));

    /* Use urandom for 16MB of data */
    GUARD(s2n_timer_start(config, &timer));
    for (int i = 0; i < 1000000; i++) {
        GUARD(s2n_get_urandom_data(&blob));
    }
    GUARD(s2n_timer_reset(config, &timer, &urandom_nanoseconds));

    /* NOTE: s2n_random_test also includes monobit tests for this DRBG */

    /* the DRBG state is 128 bytes, test that we can get more than that */
    blob.size = 129;
    for (int i = 0; i < 10; i++) {
        GUARD(s2n_drbg_generate(&drbg, &blob));
    }

    /* Move the DRBG to where it would be just before a reseed */
    drbg.bytes_used = S2N_DRBG_RESEED_LIMIT - 128;
    for (int i = 0; i < 10; i++) {
        GUARD(s2n_drbg_generate(&drbg, &blob));
    }

    GUARD(s2n_drbg_wipe(&drbg));

    GUARD(s2n_stuffer_free(&nist_reference_entropy));
    GUARD(s2n_stuffer_free(&nist_reference_personalization_strings));
    GUARD(s2n_stuffer_free(&nist_reference_returned_bits));
    GUARD(s2n_stuffer_free(&nist_reference_values));

//    END_TEST();
}
