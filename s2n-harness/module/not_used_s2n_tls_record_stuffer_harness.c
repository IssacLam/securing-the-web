#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include "stuffer/s2n_stuffer.h"
#include "tls/s2n_record.h"
#include "utils/s2n_random.h"

int main(int argc, char **argv)
{
    
#if 0
    uint8_t plaintext_pad[S2N_TLS_MAXIMUM_RECORD_LENGTH + 1];
    uint8_t encrypted_pad[S2N_TLS_MAXIMUM_RECORD_LENGTH + 1];
    uint8_t entropy[S2N_TLS_MAXIMUM_RECORD_LENGTH + 1];
    struct s2n_record_stuffer writer;
    uint8_t protocol_version[2] = { 3, 0 };


    __CPROVER_assert(s2n_tls_record_stuffer_init(&writer, plaintext_pad, encrypted_pad, S2N_TLS_MAXIMUM_RECORD_LENGTH - 1, &error_message) != 0, "Should fail 1.");
    GUARD(s2n_tls_record_stuffer_init(&writer, plaintext_pad, encrypted_pad, S2N_TLS_MAXIMUM_RECORD_LENGTH + 1, &error_message));

    /* Record is too short */
    // EXPECT_FAILURE(s2n_tls_record_finalize(&writer, &error_message));

    /* Add a header */
    GUARD(s2n_tls_record_write_header(&writer, 1, protocol_version, &error_message));
    __CPROVER_assert(s2n_stuffer_data_available(&writer.plaintext_stuffer) == S2N_TLS_MINIMUM_RECORD_LENGTH, "SHOULD Success");

    /* Should now be finalizable */
    GUARD(s2n_tls_record_finalize(&writer, &error_message));

    // uint8_t expected[] = { 1, 3, 0, 0, 0 };
    // EXPECT_BYTEARRAY_EQUAL(plaintext_pad, expected, 5);

    /* Get some Random data */
    GUARD(s2n_get_random_data(entropy, sizeof(entropy), &error_message));

    /* Write our maximum record payload */
    GUARD(s2n_stuffer_write(&writer.plaintext_stuffer, entropy, S2N_TLS_MAXIMUM_FRAGMENT_LENGTH, &error_message));
    GUARD(s2n_tls_record_finalize(&writer, &error_message));
    // uint8_t expected2[] = { 1, 3, 0, 0x48, 0x00 };
    // EXPECT_BYTEARRAY_EQUAL(plaintext_pad, expected2, 5);

    /* Try one higher, make sure it fails */
    GUARD(s2n_stuffer_write(&writer.plaintext_stuffer, entropy, 1, &error_message));
    s2n_tls_record_finalize(&writer, &error_message);

    /* Try SSL2 now ... */
    GUARD(s2n_tls_record_stuffer_init(&writer, plaintext_pad, encrypted_pad, S2N_TLS_MAXIMUM_RECORD_LENGTH + 1, &error_message));

    /* Record is too short */
    s2n_ssl2_record_finalize(&writer, &error_message);

    /* Add a header */
    GUARD(s2n_ssl2_record_write_header(&writer, 1, protocol_version, &error_message));
    __CPROVER_assert(s2n_stuffer_data_available(&writer.plaintext_stuffer) == 5, "SHOULD Success 2");

    /* Still not finalizeable */
    s2n_ssl2_record_finalize(&writer, &error_message);

    /* Add the 22 bytes of mandatory header data */
    GUARD(s2n_stuffer_write_uint16(&writer.plaintext_stuffer, 0, &error_message));
    GUARD(s2n_stuffer_write_uint16(&writer.plaintext_stuffer, 0, &error_message));
    GUARD(s2n_stuffer_write_uint16(&writer.plaintext_stuffer, 16, &error_message));
    GUARD(s2n_stuffer_write(&writer.plaintext_stuffer, entropy, 16, &error_message));

    /* Now we can finalize */
    GUARD(s2n_ssl2_record_finalize(&writer, &error_message));

    // uint8_t expected3[] = { 0x80, 0x19, 1, 3, 0, 0, 0, 0, 0, 0, 16 };
    // EXPECT_BYTEARRAY_EQUAL(plaintext_pad, expected3, 11);

    /* Write our maximum record payload */
    GUARD(s2n_stuffer_write(&writer.plaintext_stuffer, entropy, S2N_SSL2_MAXIMUM_MESSAGE_LENGTH, &error_message));
    GUARD(s2n_ssl2_record_finalize(&writer, &error_message));

    // uint8_t expected4[] = { 0xbf, 0xfd, 1, 3, 0, 0, 0, 0, 0, 0, 16 };
    // EXPECT_BYTEARRAY_EQUAL(plaintext_pad, expected4, 11);

    /* Try one higher, make sure it fails */
    GUARD(s2n_stuffer_write(&writer.plaintext_stuffer, entropy, 1, &error_message));
   	s2n_ssl2_record_finalize(&writer, &error_message);
#endif
    return 0;
}
