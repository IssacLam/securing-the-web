#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include "utils/s2n_blob.h"

uint32_t nondet_uint32();

int main(int argc, char **argv)
{
	uint32_t data_size = nondet_uint32();
	__CPROVER_assume(data_size > 0);
		
	uint8_t data[data_size];
	struct s2n_blob b = {.data = data, .size = sizeof(data)};
	
	/* no function actully use this method */
	//	s2n_blob_init(&b, &data, sizeof(data));
	
	GUARD(s2n_blob_zero(&b));
	return 0;
}