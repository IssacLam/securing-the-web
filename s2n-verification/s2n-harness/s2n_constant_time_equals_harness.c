
void *malloc(__CPROVER_size_t);
uint32_t nondet_uint32();
uint8_t nondet_uint8();

int main(int argc, char * const * argv){
        uint8_t *a, *b;
        uint32_t len;
        int result;

        a = malloc(sizeof(uint8_t));
        b = malloc(sizeof(uint8_t));
        len = nondet_uint32();

        __CPROVER_assume(len > 0 && len < 1000 && a != b);

        for(int i = 0; i < len; i++){
                a[i] = nondet_uint8();
                b[i] = nondet_uint8();
        }

        result = s2n_constant_time_equals(a, b, len);

        __CPROVER_assert((result == 0 && __CPROVER_exists { int j; (j >= 0 && j < len) ==> a[j] != b[j]}) ||
                        (result > 0 && __CPROVER_forall { int j; (j >= 0 && j < len) ==> a[j] == b[j] }), "ERROR: s2n_constant_time_equals"); 


        return 0;  
}
