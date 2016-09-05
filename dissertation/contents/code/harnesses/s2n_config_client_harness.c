#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include <s2n.h>
#include <string.h>

int main(){
    s2n_status_request_type type;
    __CPROVER_assume(type == S2N_STATUS_REQUEST_NONE || type == S2N_STATUS_REQUEST_OCSP);
    
    struct s2n_config *config = s2n_config_new();
    __CPROVER_assert(config != NULL, "ERROR: s2n_config_new()");
    
    GUARD(s2n_config_set_status_request_type(config, type));
    GUARD(s2n_config_free(config));
    
	return 0;
}