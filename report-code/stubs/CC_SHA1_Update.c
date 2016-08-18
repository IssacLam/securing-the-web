/*
 * SHA1 block update operation. Continues a SHA1 message-digest
 * operation, processing another message block, and updating the
 * context.
 */

int CC_SHA1_Update(SHA1_CTX *context, const void *inpp, size_t inputLen)
{
	u_int32_t i, index, partLen;
	const unsigned char *input = (const unsigned char *)inpp;

	if (inputLen == 0)
		return;

	/* Compute number of bytes mod 64 */
	index = (context->bcount[1] >> 3) & 0x3F;

	/* Update number of bits */
	if ((context->bcount[1] += (inputLen << 3)) < (inputLen << 3))
		context->bcount[0]++;
	context->bcount[0] += (inputLen >> 29);

	partLen = 64 - index;

	/* Transform as many times as possible. */
	i = 0;
	if (inputLen >= partLen) {
		if (index != 0) {
			memcpy(&context->buffer[index], input, partLen);
			SHA1Transform(context->state[0], context->state[1],
			    context->state[2], context->state[3],
			    context->state[4], context->buffer, context);
			i = partLen;
		}

		for (; i + 63 < inputLen; i += 64)
			SHA1Transform(context->state[0], context->state[1],
			    context->state[2], context->state[3],
			    context->state[4], &input[i], context);

		if (inputLen == i)
			return;

		index = 0;
	}

	/* Buffer remaining input */
	memcpy(&context->buffer[index], &input[i], inputLen - i);
	return 1;
}