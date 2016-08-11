#include "crypto/s2n_dhe.h"

#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include "utils/s2n_random.h"
#include "utils/s2n_blob.h"

#include <openssl/engine.h>
#include <openssl/dh.h>
#include <s2n.h>

static uint8_t dhparams[] =
    "-----BEGIN DH PARAMETERS-----\n"
    "MIIBCAKCAQEAy1+hVWCfNQoPB+NA733IVOONl8fCumiz9zdRRu1hzVa2yvGseUSq\n"
    "Bbn6k0FQ7yMED6w5XWQKDC0z2m0FI/BPE3AjUfuPzEYGqTDf9zQZ2Lz4oAN90Sud\n"
    "luOoEhYR99cEbCn0T4eBvEf9IUtczXUZ/wj7gzGbGG07dLfT+CmCRJxCjhrosenJ\n"
    "gzucyS7jt1bobgU66JKkgMNm7hJY4/nhR5LWTCzZyzYQh2HM2Vk4K5ZqILpj/n0S\n"
    "5JYTQ2PVhxP+Uu8+hICs/8VvM72DznjPZzufADipjC7CsQ4S6x/ecZluFtbb+ZTv\n" "HI5CnYmkAwJ6+FSWGaZQDi8bgerFk9RWwwIBAg==\n" "-----END DH PARAMETERS-----\n";

int main(int argc, char **argv)
{
    struct s2n_stuffer dhparams_in, dhparams_out;
    struct s2n_dh_params dh_params;
    struct s2n_blob b;

    //BEGIN_TEST();

    __CPROVER_assert(s2n_get_private_random_bytes_used() == 0, "ERROR: s2n_get_private_random_bytes_used()");

    /* Parse the DH params */
    b.data = dhparams;
    b.size = sizeof(dhparams);
    GUARD(s2n_stuffer_alloc(&dhparams_in, sizeof(dhparams)));
    GUARD(s2n_stuffer_alloc(&dhparams_out, sizeof(dhparams)));
    GUARD(s2n_stuffer_write(&dhparams_in, &b));
    GUARD(s2n_stuffer_dhparams_from_pem(&dhparams_in, &dhparams_out));
    b.size = s2n_stuffer_data_available(&dhparams_out);
    b.data = s2n_stuffer_raw_read(&dhparams_out, b.size);
    GUARD(s2n_pkcs3_to_dh_params(&dh_params, &b));

    GUARD(s2n_dh_generate_ephemeral_key(&dh_params));
    
    /* Verify that our DRBG is called and that over-riding works */
    __CPROVER_assert(s2n_get_private_random_bytes_used() != 0, "ERROR: s2n_get_private_random_bytes_used()");

    GUARD(s2n_dh_params_free(&dh_params));
    GUARD(s2n_stuffer_free(&dhparams_out));
    GUARD(s2n_stuffer_free(&dhparams_in));

    // END_TEST();
}
