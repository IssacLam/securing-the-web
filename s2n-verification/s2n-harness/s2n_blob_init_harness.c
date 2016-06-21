
void *malloc(__CPROVER_size_t);
uint32_t nondet_uint32();

int main(int argc, char * const *argv){
    struct s2n_blob *b;
    uint8_t *data;
    uint32_t size;
    int result;

    b = malloc(sizeof(struct s2n_blob));
    data = malloc(sizeof(uint8_t));
    size = nondet_uint32();

    __CPROVER_assume(size > 0);

    //for(int i = 0; i < size; i++)
      //      data[i] = nondet_uint8();

    result = s2n_blob_init(b, data, size);
    __CPROVER_assert(result == 0, "ERROR: s2n_blob_init");
    __CPROVER_assert(b->data == data && b->size == size, "ERROR: blob_init"); 
    
    return 0;
} 
