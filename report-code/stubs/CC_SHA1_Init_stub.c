int CC_SHA1_Init(CC_SHA1_CTX *c){
    /* ensure the pointer of c is valid */
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA1_Init c is null");
    
    /* assign a non-deterministic value to the variable c. */
    *c = nondet_CC_SHA1_CTX();
    return 1;
};