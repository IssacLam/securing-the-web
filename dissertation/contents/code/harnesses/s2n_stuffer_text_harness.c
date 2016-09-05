#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include "stuffer/s2n_stuffer.h"

uint32_t nondet_uint32();
_Bool nondet_bool();

#define S2N_PEM_LINE_LENGTH 64

int main(int argc, char **argv)
{
    uint32_t text_size = nondet_uint32();
    __CPROVER_assume(text_size > 0 && text_size < 5120);
    
    uint32_t read_size = nondet_uint32();
    __CPROVER_assume(text_size > 0 && text_size < 5120);
    
    char c;
    char pad[5120], out[5120], text[text_size];
    char linepad[S2N_PEM_LINE_LENGTH + 1];
    
    struct s2n_blob line_blob = {.data = linepad, .size = sizeof(linepad)};
    struct s2n_blob pblob = {.data = pad, .size = sizeof(pad)};
    
    struct s2n_stuffer stuffer, line;
  
    GUARD(s2n_stuffer_init(&line, &line_blob));
    GUARD(s2n_stuffer_init(&stuffer, &pblob));
	
    GUARD(s2n_stuffer_write_text(&stuffer, text, sizeof(text)));
    GUARD(s2n_stuffer_peek_char(&stuffer, &c));
    GUARD(s2n_stuffer_read_text(&stuffer, out, read_size));
    GUARD(s2n_stuffer_read_char(&stuffer, &c));
    GUARD(s2n_stuffer_read_token(&stuffer, &line, '\n'));

    return 0;
}
