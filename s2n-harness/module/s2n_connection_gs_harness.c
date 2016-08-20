#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include <s2n.h>
#include "tls/s2n_connection.h"
#include "tls/s2n_cipher_suites.h"

uint32_t nondet_uint32();
int nondet_int();

int main(int argc, char **argv)
{
	struct s2n_connection conn;
	const char server_name[256];
    struct s2n_blob blob = {.data=conn.alert_in_data, .size=S2N_ALERT_LENGTH};
    s2n_stuffer_alloc(&conn.alert_in, &blob);
    
    conn.active.cipher_suite = &s2n_null_cipher_suite;
    
    s2n_blinding blinding;
    __CPROVER_assume(blinding == S2N_BUILT_IN_BLINDING || blinding == S2N_SELF_SERVICE_BLINDING);
    
	GUARD(s2n_connection_set_config(&conn, &s2n_default_config));
	GUARD(s2n_connection_set_fd(&conn, nondet_int()));
	GUARD(s2n_connection_set_read_fd(&conn, nondet_int()));
	GUARD(s2n_connection_set_write_fd(&conn, nondet_int()));

    s2n_connection_prefer_throughput(&conn);
	s2n_connection_prefer_low_latency(&conn);

	GUARD(s2n_connection_set_blinding(&conn, blinding));
	s2n_connection_get_delay(&conn);
	
	GUARD(s2n_set_server_name(&conn, server_name));
	s2n_get_server_name(&conn);
	s2n_get_application_protocol(&conn);
	
	s2n_connection_get_wire_bytes_in(&conn);
 	s2n_connection_get_wire_bytes_out(&conn);
    s2n_connection_get_client_protocol_version(&conn);
 	s2n_connection_get_server_protocol_version(&conn);
 	s2n_connection_get_actual_protocol_version(&conn);
 	s2n_connection_get_client_hello_version(&conn);
 	s2n_connection_get_cipher(&conn);
 	s2n_connection_get_alert(&conn);

	return 0;
}