#include <string.h>
#include <stdio.h>

#include <s2n.h>

#include "tls/s2n_prf.h"

/*
 * Grabbed from gnutls-cli --insecure -d 9 www.example.com --ciphers AES --macs SHA --protocols TLS1.0
 *
 * |<9>| INT: PREMASTER SECRET[48]: 0301bebf2a5707c7bda6bfe5a8971a351a9ebd019de412212da021fd802e03f49f231d4e959c7352679f892f9d7f9748
 * |<9>| INT: CLIENT RANDOM[32]: 537eefc1e720b311ff8483d057ae750a3667af9d5b496cc0d2edfb0dd309a286
 * |<9>| INT: SERVER RANDOM[32]: 537eefc29f337c5eedacd00a1889b031261701872d666a74fa999dc13bcd8821
 * |<9>| INT: MASTER SECRET: c8c610686237cd024a2d8e0391f61a8a4464c2c9576ea2b5ccf3af68139ec07c6a1720097063de968f2341f77b837120
 */

uint8_t nondet_uint8();

int main(int argc, char **argv){
    uint8_t master_secret_hex_pad[96];
    char premaster_secret_hex_in[48];
    char client_random_hex_in[32];
    char server_random_hex_in[32];
    char master_secret_hex_in[48];
    
    struct s2n_stuffer client_random_in;
    struct s2n_stuffer server_random_in;
    struct s2n_stuffer premaster_secret_in;
    struct s2n_stuffer master_secret_hex_out;
    struct s2n_blob master_secret = {.data = master_secret_hex_pad,.size = sizeof(master_secret_hex_pad) };
    struct s2n_blob pms;
    
    struct s2n_connection *conn;
    
    conn = s2n_connection_new(S2N_SERVER);
    
    /* Check the most common PRF */
    conn->actual_protocol_version = nondet_uint8();
    __CPROVER_assume(conn->actual_protocol_version == S2N_TLS10 ||
                    conn->actual_protocol_version == S2N_TLS11 ||
                    conn->actual_protocol_version == S2N_TLS12 ||
                    conn->actual_protocol_version == S2N_SSLv2 ||
                    conn->actual_protocol_version == S2N_SSLv3);

   s2n_stuffer_alloc_ro_from_string(&client_random_in, client_random_hex_in);
   s2n_stuffer_alloc_ro_from_string(&server_random_in, server_random_hex_in);
   s2n_stuffer_alloc_ro_from_string(&premaster_secret_in, premaster_secret_hex_in);
    
   s2n_stuffer_init(&master_secret_hex_out, &master_secret);
    
    /* Parse the hex */
    //for (int i = 0; i < 48; i++) {
        conn->pending.rsa_premaster_secret[48 - 1] = nondet_uint8();
    //}
    //for (int i = 0; i < 32; i++) {
        conn->pending.client_random[32 - 1] = nondet_uint8();
    //}
    // for (int i = 0; i < 32; i++){
        conn->pending.server_random[32 - 1] = nondet_uint8();
    //}
    
    pms.data = conn->pending.rsa_premaster_secret;
    pms.size = sizeof(conn->pending.rsa_premaster_secret);
    s2n_prf_master_secret(conn, &pms);
    
    /* Convert the master secret to hex */
    //for (int i = 0; i < 48; i++) {
       conn->pending.master_secret[48 - 1] = nondet_uint8();
    //}
    
    //memcmp(master_secret_hex_pad, master_secret_hex_in, sizeof(master_secret_hex_pad));
    
    s2n_connection_free(conn);
    s2n_stuffer_free(&client_random_in);
    s2n_stuffer_free(&server_random_in);
    s2n_stuffer_free(&premaster_secret_in);

    return 0;
}
