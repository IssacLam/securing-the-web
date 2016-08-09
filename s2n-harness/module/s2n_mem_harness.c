#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include "utils/s2n_mem.h"
#include "utils/s2n_blob.h"

uint32_t nondet_uint32();

int main(int argc, char **argv)
{
	uint32_t blob_size = nondet_uint32();
	__CPROVER_assume(blob_size > 0);
		
	struct s2n_blob b;
	
	GUARD_PTR(s2n_alloc(&b, blob_size));
	
	blob_size = nondet_uint32();
	
	GUARD(s2n_realloc(&b, blob_size));
	GUARD(s2n_free(&b));
	
	return 0;
}