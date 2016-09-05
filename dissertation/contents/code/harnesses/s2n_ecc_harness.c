#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include <s2n.h>

#include "crypto/s2n_ecc.h"
#include "utils/s2n_mem.h"

int main(int argc, char **argv)
{
    /* Test generate->write->read->compute_shared with all supported curves */
    for (int i = 0; i < sizeof(s2n_ecc_supported_curves) / sizeof(s2n_ecc_supported_curves[0]); i++) {
        struct s2n_ecc_params server_params, client_params;
        struct s2n_stuffer wire;
        struct s2n_blob server_shared, client_shared, ecdh_params_sent, ecdh_params_received;

        GUARD(s2n_stuffer_growable_alloc(&wire, 1024));

        /* Server generates a key for a given curve */
        server_params.negotiated_curve = &s2n_ecc_supported_curves[i];
        GUARD(s2n_ecc_generate_ephemeral_key(&server_params));
        /* Server sends the public */
        GUARD(s2n_ecc_write_ecc_params(&server_params, &wire, &ecdh_params_sent));
        /* Client reads the public */
        GUARD(s2n_ecc_read_ecc_params(&client_params, &wire, &ecdh_params_received));

        /* Client sends its public */
        GUARD(s2n_ecc_compute_shared_secret_as_client(&client_params, &wire, &client_shared));
        /* Server receives it */
        GUARD(s2n_ecc_compute_shared_secret_as_server(&server_params, &wire, &server_shared));
        /* Shared is the same for the client and the server */
        __CPROVER_assert(client_shared.size == server_shared.size, "ERROR: Shared size are not the same.");
        
        int j;
        __CPROVER_assume(j >= 0 && j < client_shared.size);
        __CPROVER_assert(client_shared.data[j] == server_shared.data[j], "ERROR: Shared data are not the same." );

        /* Clean up */
        GUARD(s2n_stuffer_free(&wire));
        GUARD(s2n_free(&server_shared));
        GUARD(s2n_free(&client_shared));
        GUARD(s2n_ecc_params_free(&server_params));
        GUARD(s2n_ecc_params_free(&client_params));
    }
    return 0;
}

