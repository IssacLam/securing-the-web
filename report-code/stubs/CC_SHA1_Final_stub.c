int CC_SHA1_Final(unsigned char *md, CC_SHA1_CTX *c){
    /* ensure the pointers are valid */
    __CPROVER_assert(md != NULL, "ERROR: CC_SHA1_Final md is null");
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA1_Final c is null");

    /* try to write something to the variable */
    *c = nondet_CC_SHA1_CTX();

    /* try to access the output pointer */
    md[SHA1_DIGEST_SIZE - 1];
    return 1;
};