#include "crypto/s2n_sequence.h"

void *malloc(__CPROVER_size_t);
uint32_t nondet_uint32();

int main(int argc, char * const * argv){
        struct s2n_blob *sequence_number0, *sequence_number;
        int result;

        sequence_number0 = malloc(sizeof(struct s2n_blob));
        sequence_number0->data = malloc(sizeof(uint8_t));
        sequence_number0->size = nondet_uint32();

        __CPROVER_assume(sequence_number0->size >= 0 && sequence_number0->size <= 1000);

        sequence_number = malloc(sizeof(struct s2n_blob));
        sequence_number->data = malloc(sizeof(uint8_t));
        sequence_number->size = sequence_number0->size;

        for(uint32_t i = 0; i < sequence_number->size; i++)
                sequence_number0->data[i] = sequence_number->data[i] = nondet_uint32();

        result = s2n_increment_sequence_number(sequence_number);

        __CPROVER_assert(result == 0, "ERROR: s2n_increment_sequence_number result");
        
        uint32_t diff = 0;
        for(uint32_t i = 0; i < sequence_number->size; i++)
                diff += sequence_number->data[i] - sequence_number0->data[i];

        __CPROVER_assert(diff == 1, "ERROR: s2n_increment_sequence_number");

        return 0;
}
