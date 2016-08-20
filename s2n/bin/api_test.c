#include <s2n.h>

int harness(arc, char * const *argv){
        s2n_init();
        s2n_cleanup();

        struct s2n_config *config = s2n_config_new();

        s2n_config_free(config);
        s2n_config_free_dhparams(config);
        s2n_config_free_cert_chain_and_key(config);

        uint64_t mock_time;
        s2n_config_set_nanoseconds_since_epoch_callback(config, NULL, NULL);
        s2n_strerror(s2n_errno, "EN");

        s2n_config_add_cert_chain_and_key(config, NULL, NULL);


    
    
     s2n_config_add_cert_chain_and_key(config, NULL, NULL);
     s2n_config_add_cert_chain_and_key_with_status(config, NULL, NULL, NULL, 0);
     s2n_config_add_dhparams(config, NULL);
     s2n_config_set_key_exchange_preferences(config, NULL);
     s2n_config_set_cipher_preferences(config, NULL);
     s2n_config_set_protocol_preferences(config, NULL, 0);
    
     s2n_config_set_status_request_type(config, 0);
    struct s2n_connection *conn = s2n_connection_new(0);
    
    
     s2n_connection_set_config(conn, config);
    
     s2n_connection_set_fd(conn, readfd);
     s2n_connection_set_read_fd(conn, readfd);
     s2n_connection_set_write_fd(conn, readfd);
    
     s2n_connection_prefer_throughput(conn);
     s2n_connection_prefer_low_latency(conn);
    
     s2n_connection_set_blinding(conn, 0);
     int64_t s2n_connection_get_delay(conn);
    
     s2n_set_server_name(conn, NULL);
     s2n_get_server_name(conn);
     s2n_get_application_protocol(conn);
     s2n_connection_get_ocsp_response(conn, NULL);
    
     s2n_negotiate(conn, NULL);
     ssize_t s2n_send(conn, NULL, 0, NULL);
     ssize_t s2n_recv(conn,  NULL, 0, NULL);
    
     s2n_connection_wipe(conn);
     s2n_connection_free(conn);
     s2n_shutdown(conn, NULL);
    
     uint64_t s2n_connection_get_wire_bytes_in(conn);
     uint64_t s2n_connection_get_wire_bytes_out(conn);
     s2n_connection_get_client_protocol_version(conn);
     s2n_connection_get_server_protocol_version(conn);
     s2n_connection_get_actual_protocol_version(conn);
     s2n_connection_get_client_hello_version(conn);
     const char *s2n_connection_get_cipher(conn);
     s2n_connection_get_alert(conn);






        return 0;
}
