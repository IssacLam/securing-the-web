/* SHA1 initialization. Begins a SHA1 operation, writing a new context. */
int CC_SHA1_Init(SHA1_CTX *context)
{
	// context->bcount[0] = context->bcount[1] = 0; context->count = 0;

	/* Load magic initialization constants.  */
	// context->state[0] = 0x67452301UL; context->state[1] = 0xefcdab89UL;
	// context->state[2] = 0x98badcfeUL; context->state[3] = 0x10325476UL;
	// context->state[4] = 0xc3d2e1f0UL;
    
    /* ensure the pointer of c is valid */
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA1_Init c is null");
    
    /* assign a non-deterministic value to the variable c. */
    *c = nondet_CC_SHA1_CTX();
	
	return 1;
}