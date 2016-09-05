/* SHA1 finalization. Ends an SHA1 message-digest operation, writing the
 * the message digest and zeroizing the context. */
int CC_SHA1_Final(void *digest, SHA1_CTX *context)
{
	// unsigned char bits[8];
	// u_int32_t index = (context->bcount[1] >> 3) & 0x3f;

	/* Save number of bits */
	// Encode(bits, context->bcount, 8);

	/* Pad out to 56 mod 64. */
	// SHA1Update(context, PADDING, ((index < 56) ? 56 : 120) - index);

	/* Append length (before padding) */
	// SHA1Update(context, bits, 8);

	/* Store state in digest */
	// Encode(digest, context->state, 20);

	/* Zeroize sensitive information. */
	// memset(context, 0, sizeof (*context));
    
    /* ensure the pointers are valid */
    __CPROVER_assert(md != NULL, "ERROR: CC_SHA1_Final md is null");
    __CPROVER_assert(c != NULL, "ERROR: CC_SHA1_Final c is null");
    
    /* try to write something to the variable */
    *c = nondet_CC_SHA1_CTX();
    
    /* try to access the output pointer */
    md[SHA1_DIGEST_SIZE - 1];
	
	return 1;
}