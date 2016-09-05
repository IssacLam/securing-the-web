#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include <s2n.h>
#include <string.h>

static char certificate[10];
static char private_key[10];

int main(){
    struct s2n_config *config = s2n_config_new();
    __CPROVER_assert(config != NULL, "ERROR: s2n_config_new()");
    
    GUARD(s2n_config_add_cert_chain_and_key(config, certificate, private_key));
    GUARD(s2n_config_free(config));
	return 0;
}