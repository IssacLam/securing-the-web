#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include <s2n.h>
#include <string.h>

static char dhparams[] =
"-----BEGIN DH PARAMETERS-----\n"
"MIIBCAKCAQEAy1+hVWCfNQoPB+NA733IVOONl8fCumiz9zdRRu1hzVa2yvGseUSq\n"
"Bbn6k0FQ7yMED6w5XWQKDC0z2m0FI/BPE3AjUfuPzEYGqTDf9zQZ2Lz4oAN90Sud\n"
"luOoEhYR99cEbCn0T4eBvEf9IUtczXUZ/wj7gzGbGG07dLfT+CmCRJxCjhrosenJ\n"
"gzucyS7jt1bobgU66JKkgMNm7hJY4/nhR5LWTCzZyzYQh2HM2Vk4K5ZqILpj/n0S\n"
"5JYTQ2PVhxP+Uu8+hICs/8VvM72DznjPZzufADipjC7CsQ4S6x/ecZluFtbb+ZTv\n"
"HI5CnYmkAwJ6+FSWGaZQDi8bgerFk9RWwwIBAg==\n"
"-----END DH PARAMETERS-----\n";



int main(){
    struct s2n_config *config = s2n_config_new();
    __CPROVER_assert(config != NULL, "ERROR: s2n_config_new()");
    
    GUARD(s2n_config_add_dhparams(config, dhparams));
    GUARD(s2n_config_free(config));
	return 0;
}