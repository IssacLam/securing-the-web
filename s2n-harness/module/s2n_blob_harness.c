#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include "utils/s2n_blob.h"

uint32_t nondet_uint32();

int main(int argc, char **argv)
{
	uint32_t random_data_size = nondet_uint32();
	__CPROVER_assume(random_data_size > 0);
		
	uint8_t random_data[random_data_size];
	struct s2n_blob b = {.data = random_data, .size = sizeof(random_data)};
	
	/* no one does actully use this function */
	//	s2n_blob_init(&b, &random_data, sizeof(random_data));
	
	GUARD(s2n_blob_zero(&b));
	
	return 0;
}