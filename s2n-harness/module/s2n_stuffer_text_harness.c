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
    struct s2n_blob pblob = { .data = pad, .size = sizeof(pad)};
	
//    GUARD(s2n_blob_init(&pblob, (uint8_t *)pad, sizeof(pad)));
    GUARD(s2n_stuffer_init(&stuffer, &pblob));
	
    GUARD(s2n_stuffer_write_text(&stuffer, text, sizeof(text)));


    GUARD(s2n_stuffer_skip_whitespace(&stuffer));

    GUARD(s2n_stuffer_peek_char(&stuffer, &c));

    GUARD(s2n_stuffer_read_text(&stuffer, out, 17));
    
    GUARD(s2n_stuffer_read_char(&stuffer, &c));

    GUARD(s2n_stuffer_read_token(&stuffer, &token, ','));

    return 0;
}
