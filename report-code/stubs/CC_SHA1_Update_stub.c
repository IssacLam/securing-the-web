int CC_SHA1_Update(CC_SHA1_CTX *c, const void *data, CC_LONG len){
    /* ensure the parameters are valid */
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA1_Update c is null");
    __CPROVER_assert(data != NULL, "ERROR: CC_SHA1_Update data is null");
    __CPROVER_assert(len > 0, "ERROR: CC_SHA1_Update len is less than or equal to zero");
    
    /* read something from data */
    ((uint8_t *) data)[len-1];

    /* try to write something to the variable */
    *c = nondet_CC_SHA1_CTX();
    return 1;
};