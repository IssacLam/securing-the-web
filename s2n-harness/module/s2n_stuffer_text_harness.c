#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include "stuffer/s2n_stuffer.h"

uint32_t nondet_uint32();
uint64_t nondet_uint64();
_Bool nondet_bool();

int main(int argc, char **argv)
{
    char pad[5120];
    char text[] = "    This is some text\r\n\tmore text";
    char tokenpad[6];
	
	uint32_t fields_size = nondet_uint32();
    char fields[fields_size];
    char out[1024];
    char c;
    struct s2n_stuffer stuffer, token;
    struct s2n_blob pblob, tblob;


    /* Create a stuffer */
    GUARD(s2n_blob_init(&tblob, (uint8_t *)tokenpad, sizeof(tokenpad)));
    GUARD(s2n_stuffer_init(&token, &tblob));
	
    GUARD(s2n_blob_init(&pblob, (uint8_t *)pad, sizeof(pad)));
    GUARD(s2n_stuffer_init(&stuffer, &pblob));
	
    GUARD(s2n_stuffer_write_text(&stuffer, text, sizeof(text)));

    /* Skip 4 bytes of whitespace */
    // EXPECT_EQUAL(s2n_stuffer_skip_whitespace(&stuffer), 4);
	s2n_stuffer_skip_whitespace(&stuffer);

    /* Skip 4 bytes of whitespace */
    GUARD(s2n_stuffer_peek_char(&stuffer, &c));
    // EXPECT_EQUAL(c, 'T');

    /* Read the next 17 chars */
    GUARD(s2n_stuffer_read_text(&stuffer, out, 17));
    // EXPECT_EQUAL(memcmp(out, "This is some text", 17), 0);

    /* Skip 3 bytes of whitespace */
    // EXPECT_EQUAL(s2n_stuffer_skip_whitespace(&stuffer), 3);
	s2n_stuffer_skip_whitespace(&stuffer);

    /* Read the next 10 chars (including the terminating zero) */
    GUARD(s2n_stuffer_read_text(&stuffer, out, 10));
    // EXPECT_EQUAL(memcmp(out, "more text", 10), 0);

    /* Test end of stream behaviour */
    GUARD(s2n_stuffer_skip_whitespace(&stuffer));
    // EXPECT_FAILURE(s2n_stuffer_peek_char(&stuffer, &c));
    // EXPECT_FAILURE(s2n_stuffer_read_char(&stuffer, &c));

    /* Start a new buffer */
    GUARD(s2n_stuffer_init(&stuffer, &pblob));
    GUARD(s2n_stuffer_write_text(&stuffer, fields, fields_size));

    GUARD(s2n_stuffer_read_token(&stuffer, &token, ','));
    // EXPECT_EQUAL(memcmp("one", token.blob.data, 3), 0);

    GUARD(s2n_stuffer_init(&token, &tblob));
    GUARD(s2n_stuffer_read_token(&stuffer, &token, ','));
    // EXPECT_EQUAL(memcmp("two", token.blob.data, 3), 0);

    /* Check for end-of-stream termination */
    GUARD(s2n_stuffer_init(&token, &tblob));
    GUARD(s2n_stuffer_read_token(&stuffer, &token, ','));
    // EXPECT_EQUAL(memcmp("three", token.blob.data, 5), 0);

    return 0;
}
