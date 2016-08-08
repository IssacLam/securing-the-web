# Current Status

s2n_3des_test run out of time? process killed by kernel.

Begin with the simplest test: s2n_tls_record_stuffer_harness, with the smallest size function call graph

# Plan

- [ ] Report : Restructure the Background
- [ ] Experiment : Turn Unit testing to formal verification analysis

# Turning Unit test to formal verification analysis

- [ ] s2n_3des_test.c
- [ ] s2n_aead_aes_test.c
- [ ] s2n_aes_test.c
- [ ] s2n_cbc_verify_test.c
- [ ] s2n_cipher_suite_match_test.c
- [ ] s2n_client_disabled_test.c
- [ ] s2n_client_extensions_test.c
- [ ] s2n_drbg_test.c
- [ ] s2n_ecc_test.c
- [ ] s2n_fragmentation_coalescing_test.c
- [ ] s2n_handshake_test.c
- [ ] s2n_hash_test.c
- [ ] s2n_hmac_test.c
- [ ] s2n_malformed_handshake_test.c
- [ ] s2n_override_openssl_random_test.c
- [ ] s2n_pem_rsa_dhe_test.c
- [ ] s2n_random_test.c
- [ ] s2n_rc4_test.c
- [ ] s2n_record_size.c
- [ ] s2n_record_test.c
- [ ] s2n_safety_test.c
- [ ] s2n_self_talk_alpn_test.c
- [ ] s2n_self_talk_test.c
- [ ] s2n_ssl_prf_test.c
- [ ] s2n_stuffer_base64_test.c
- [ ] s2n_stuffer_hex_test.c
- [ ] s2n_stuffer_test.c
- [ ] s2n_stuffer_text_test.c
- [ ] s2n_timer_test.c
- [ ] s2n_tls_prf_test.c
- [ ] s2n_tls_record_stuffer_test.c

cbmc -D__CPROVER_STRING_ABSTRACTION -I ./s2n -I ./s2n/api -I ./s2n/libcrypto-build/openssl/include ./s2n-harness/unit/s2n_timer_harness.c ./s2n/utils/s2n_timer.c ./s2n/tls/s2n_config.c ./s2n/utils/s2n_mem.c ./s2n-lib/mach_time.c ./s2n-lib/mman.c ./s2n-lib/stdlib.c

cbmc -D__CPROVER_STRING_ABSTRACTION -I ./s2n -I ./s2n/api -I ./s2n/tests -I ./s2n/libcrypto-build/openssl/include -I ./s2n/libcrypto-build/openssl/crypto/engine -I ./s2n/libcrypto-build/openssl/crypto -I ./s2n/libcrypto-build/openssl ./s2n-harness/unit/s2n_3des_harness.c ./s2n/utils/s2n_random.c ./s2n/utils/s2n_mem.c ./s2n/error/s2n_errno.c ./s2n/stuffer/s2n_stuffer.c ./s2n/crypto/s2n_drbg.c ./s2n/utils/s2n_blob.c ./s2n/tls/s2n_connection.c ./s2n/tls/s2n_record_write.c ./s2n/tls/s2n_record_read.c ./s2n/crypto/s2n_hmac.c ./s2n/utils/s2n_timer.c ./s2n/crypto/s2n_hash.c ./s2n/tls/s2n_aead.c ./s2n/crypto/s2n_rsa.c ./s2n/crypto/s2n_dhe.c ./s2n/crypto/s2n_ecc.c ./s2n/tls/s2n_cbc.c ./s2n/crypto/s2n_sequence.c ./s2n/utils/s2n_timer.c ./s2n/utils/s2n_safety.c ./s2n-lib/openssl/evp.c ./s2n-lib/openssl/engine.c ./s2n-lib/CommonCrypto/CommonDigest.c ./s2n-lib/mman.c ./s2n-lib/stdlib.c --unwind 1 2> test.txt

# Top-down command

cbmc -I ./s2n -I ./s2n/api -I ./s2n/libcrypto-build/openssl -I ./s2n/libcrypto-build/openssl/crypto -I ./s2n/libcrypto-build/openssl/crypto/engine -I ./s2n/libcrypto-build/openssl/include ./s2n-harness/s2n_test_harness.c ./s2n/utils/s2n_random.c ./s2n/crypto/s2n_drbg.c ./s2n/utils/s2n_mem.c ./s2n-lib/unistd.c ./s2n-lib/openssl/engine.c ./s2n-lib/fcntl.c --unwind 1 --unwindset __builtin___memcpy_chk.0:65,read.0:33,read.1:33,s2n_get_urandom_data.0:65,s2n_drbg_seed.0:33,s2n_drbg_bits.0:33,s2n_drbg_bits.1:33,s2n_drbg_bits.2:33,s2n_drbg_update.0:33,s2n_drbg_update.1:33,s2n_drbg_update.2:33,s2n_drbg_update.3:33


~~cbmc -I ./s2n -I ./s2n/api -I ./s2n/libcrypto-build/openssl/include ./s2n/tls/s2n_prf.c --function s2n_p_hash ./s2n-lib/openssl/*.c ./s2n/crypto/s2n_hmac.c ./s2n/crypto/s2n_hash.c --unwind 1~~

~~cbmc -I ./s2n -I ./s2n/api -I ./s2n/libcrypto-build/openssl/include ./s2n-harness/s2n_tls_prf_harness.c ./s2n/tls/s2n_connection.c ./s2n/stuffer/s2n_stuffer.c ./s2n/utils/s2n_mem.c ./s2n/utils/s2n_blob.c ./s2n/crypto/s2n_dhe.c ./s2n-lib/stdlib.c --show-loops >> ./s2n-loop-analysis/prf-loops-analysis.txt~~

- [X] ~~Create stub for CC_SHA_* & CC_MD_*~~

cbmc -I ./s2n -I ./s2n/api -I ./s2n/libcrypto-build/openssl/include ./s2n-harness/s2n_hash_harness.c ./s2n/crypto/s2n_hash.c ./s2n-lib/CommonCrypto/CommonDigest.c --unwindset main.0:3

cbmc -I ./s2n -I ./s2n/api -I ./s2n/libcrypto-build/openssl/include ./s2n-harness/s2n_hmac_harness.c ./s2n/crypto/s2n_hmac.c ./s2n/crypto/s2n_hash.c ./s2n-lib/CommonCrypto/CommonDigest.c --unwindset s2n_hmac_init.2:64,s2n_hmac_init.3:64,s2n_hmac_init.4:128,s2n_hmac_init.5:128,s2n_hmac_init.6:128,s2n_hmac_init.7:128,s2n_hmac_init.8:128,s2n_sslv3_mac_init.0:48,s2n_sslv3_mac_init.1:48,s2n_sslv3_mac_digest.0:48,__builtin___memcpy_chk.0:216,main.0:2

Success!

# Grep no body Functions
| grep -E "\*{4} WARNING:"

# Relink the dynamic library for executing s2n sample code

install_name_tool -change libs2n.dylib @executable_path/../lib/libs2n.dylib s2nc

install_name_tool -change libs2n.dylib @executable_path/../lib/libs2n.dylib s2nd

-----

# Pending - Buttom-up functions to verify:

- [ ] ./s2n/crypto/s2n_aead_cipher_aes_gcm.c : s2n_aead_cipher_aes_gcm_encrypt
- [ ] ./s2n/crypto/s2n_aead_cipher_aes_gcm.c : s2n_aead_cipher_aes_gcm_decrypt
- [ ] ./s2n/crypto/s2n_aead_cipher_aes_gcm.c : s2n_aead_cipher_aes128_gcm_get_encryption_key
- [ ] ./s2n/crypto/s2n_aead_cipher_aes_gcm.c : s2n_aead_cipher_aes256_gcm_get_encryption_key
- [ ] ./s2n/crypto/s2n_aead_cipher_aes_gcm.c : s2n_aead_cipher_aes128_gcm_get_decryption_key
- [ ] ./s2n/crypto/s2n_aead_cipher_aes_gcm.c : s2n_aead_cipher_aes256_gcm_get_decryption_key
- [ ] ./s2n/crypto/s2n_aead_cipher_aes_gcm.c : s2n_aead_cipher_aes_gcm_destroy_key
- [ ] ./s2n/crypto/s2n_cbc_cipher_3des.c : s2n_cbc_cipher_3des_encrypt
- [ ] ./s2n/crypto/s2n_cbc_cipher_3des.c : s2n_cbc_cipher_3des_decrypt
- [ ] ./s2n/crypto/s2n_cbc_cipher_3des.c : s2n_cbc_cipher_3des_get_decryption_key
- [ ] ./s2n/crypto/s2n_cbc_cipher_3des.c : s2n_cbc_cipher_3des_get_encryption_key
- [ ] ./s2n/crypto/s2n_cbc_cipher_3des.c : s2n_cbc_cipher_3des_destroy_key
- [ ] ./s2n/crypto/s2n_cbc_cipher_aes.c : s2n_cbc_cipher_aes_encrypt
- [ ] ./s2n/crypto/s2n_cbc_cipher_aes.c : s2n_cbc_cipher_aes_decrypt
- [ ] ./s2n/crypto/s2n_cbc_cipher_aes.c : s2n_cbc_cipher_aes128_get_decryption_key
- [ ] ./s2n/crypto/s2n_cbc_cipher_aes.c : s2n_cbc_cipher_aes128_get_encryption_key
- [ ] ./s2n/crypto/s2n_cbc_cipher_aes.c : s2n_cbc_cipher_aes256_get_decryption_key
- [ ] ./s2n/crypto/s2n_cbc_cipher_aes.c : s2n_cbc_cipher_aes256_get_encryption_key
- [ ] ./s2n/crypto/s2n_cbc_cipher_aes.c : s2n_cbc_cipher_aes_destroy_key
- [ ] ./s2n/crypto/s2n_dhe.c : s2n_check_p_g_dh_params
- [ ] ./s2n/crypto/s2n_dhe.c : s2n_check_all_dh_params
- [ ] ./s2n/crypto/s2n_dhe.c : s2n_pkcs3_to_dh_params
- [ ] ./s2n/crypto/s2n_dhe.c : s2n_dh_p_g_Ys_to_dh_params
- [ ] ./s2n/crypto/s2n_dhe.c : s2n_dh_params_to_p_g_Ys
- [ ] ./s2n/crypto/s2n_dhe.c : s2n_dh_compute_shared_secret_as_client
- [ ] ./s2n/crypto/s2n_dhe.c : s2n_dh_compute_shared_secret_as_server
- [ ] ./s2n/crypto/s2n_dhe.c : s2n_dh_params_check
- [ ] ./s2n/crypto/s2n_dhe.c : s2n_dh_params_copy
- [ ] ./s2n/crypto/s2n_dhe.c : s2n_dh_generate_ephemeral_key
- [ ] ./s2n/crypto/s2n_dhe.c : s2n_dh_params_free
- [ ] ./s2n/crypto/s2n_drbg.c : s2n_drbg_block_encrypt
- [ ] ./s2n/crypto/s2n_drbg.c : s2n_drbg_bits
- [ ] ./s2n/crypto/s2n_drbg.c : s2n_drbg_update
- [ ] ./s2n/crypto/s2n_drbg.c : s2n_drbg_seed
- [ ] ./s2n/crypto/s2n_drbg.c : s2n_drbg_instantiate
- [ ] ./s2n/crypto/s2n_drbg.c : s2n_drbg_generate
- [ ] ./s2n/crypto/s2n_drbg.c : s2n_drbg_wipe
- [ ] ./s2n/crypto/s2n_drbg.c : s2n_drbg_bytes_used
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_generate_own_key
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_blob_to_point
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_calculate_point_length
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_write_point_data_snug
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_write_point_with_length
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_compute_shared_secret
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_generate_ephemeral_key
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_write_ecc_params
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_read_ecc_params
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_compute_shared_secret_as_server
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_compute_shared_secret_as_client
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_params_free
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_generate_own_key
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_blob_to_point
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_calculate_point_length
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_write_point_data_snug
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_write_point_with_length
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_compute_shared_secret
- [ ] ./s2n/crypto/s2n_ecc.c : s2n_ecc_find_supported_curve
- [ ] ./s2n/crypto/s2n_hash.c : s2n_hash_digest_size
- [ ] ./s2n/crypto/s2n_hash.c : s2n_hash_init
- [ ] ./s2n/crypto/s2n_hash.c : s2n_hash_update
- [ ] ./s2n/crypto/s2n_hash.c : s2n_hash_digest
- [ ] ./s2n/crypto/s2n_hash.c : s2n_hash_reset
- [ ] ./s2n/crypto/s2n_hash.c : s2n_hash_copy
- [ ] ./s2n/crypto/s2n_hmac.c : s2n_hmac_digest_size
- [ ] ./s2n/crypto/s2n_hmac.c : s2n_sslv3_mac_init
- [ ] ./s2n/crypto/s2n_hmac.c : s2n_sslv3_mac_digest
- [ ] ./s2n/crypto/s2n_hmac.c : s2n_hmac_init
- [ ] ./s2n/crypto/s2n_hmac.c : s2n_hmac_update
- [ ] ./s2n/crypto/s2n_hmac.c : s2n_hmac_digest
- [ ] ./s2n/crypto/s2n_hmac.c : s2n_hmac_digest_two_compression_rounds
- [ ] ./s2n/crypto/s2n_hmac.c : s2n_hmac_reset
- [ ] ./s2n/crypto/s2n_hmac.c : s2n_hmac_digest_verify
- [ ] ./s2n/crypto/s2n_hmac.c : s2n_hmac_copy
- [ ] ./s2n/crypto/s2n_rsa.c : s2n_asn1der_to_rsa_public_key
- [ ] ./s2n/crypto/s2n_rsa.c : s2n_asn1der_to_rsa_private_key
- [ ] ./s2n/crypto/s2n_rsa.c : s2n_rsa_public_key_free
- [ ] ./s2n/crypto/s2n_rsa.c : s2n_rsa_private_key_free
- [ ] ./s2n/crypto/s2n_rsa.c : s2n_rsa_public_encrypted_size
- [ ] ./s2n/crypto/s2n_rsa.c : s2n_rsa_private_encrypted_size
- [ ] ./s2n/crypto/s2n_rsa.c : s2n_rsa_sign
- [ ] ./s2n/crypto/s2n_rsa.c : s2n_rsa_verify
- [ ] ./s2n/crypto/s2n_rsa.c : s2n_rsa_encrypt
- [ ] ./s2n/crypto/s2n_rsa.c : s2n_rsa_decrypt
- [ ] ./s2n/crypto/s2n_rsa.c : s2n_rsa_keys_match
- [X] ~~./s2n/crypto/s2n_sequence.c : s2n_increment_sequence_number~~
- [ ] ./s2n/crypto/s2n_stream_cipher_null.c : s2n_stream_cipher_null_endecrypt
- [ ] ./s2n/crypto/s2n_stream_cipher_null.c : s2n_stream_cipher_null_get_key
- [ ] ./s2n/crypto/s2n_stream_cipher_null.c : s2n_stream_cipher_null_destroy_key
- [ ] ./s2n/crypto/s2n_stream_cipher_rc4.c : s2n_stream_cipher_rc4_endecrypt
- [ ] ./s2n/crypto/s2n_stream_cipher_rc4.c : s2n_stream_cipher_rc4_get_key
- [ ] ./s2n/crypto/s2n_stream_cipher_rc4.c : s2n_stream_cipher_rc4_destroy_key
- [X] ~~./s2n/error/s2n_errno.c : s2n_strerror~~
- [X] ~~./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_init~~
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_alloc
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_growable_alloc
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_free
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_resize
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_rewrite
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_reread
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_wipe_n
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_wipe
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_skip_read
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_raw_read
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_read
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_erase_and_read
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_read_bytes
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_skip_write
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_raw_write
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_write
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_write_bytes
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_read_uint8
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_write_uint8
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_read_uint16
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_write_uint16
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_read_uint24
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_write_uint24
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_read_uint32
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_write_uint32
- [ ] ./s2n/stuffer/s2n_stuffer.c : s2n_stuffer_copy
- [ ] ./s2n/stuffer/s2n_stuffer_base64.c : s2n_stuffer_read_base64
- [ ] ./s2n/stuffer/s2n_stuffer_base64.c : s2n_stuffer_write_base64
- [ ] ./s2n/stuffer/s2n_stuffer_file.c : s2n_stuffer_recv_from_fd
- [ ] ./s2n/stuffer/s2n_stuffer_file.c : s2n_stuffer_send_to_fd
- [ ] ./s2n/stuffer/s2n_stuffer_file.c : s2n_stuffer_alloc_ro_from_fd
- [ ] ./s2n/stuffer/s2n_stuffer_file.c : s2n_stuffer_alloc_ro_from_file
- [ ] ./s2n/stuffer/s2n_stuffer_pem.c : s2n_stuffer_data_from_pem
- [ ] ./s2n/stuffer/s2n_stuffer_pem.c : s2n_stuffer_rsa_private_key_from_pem
- [ ] ./s2n/stuffer/s2n_stuffer_pem.c : s2n_stuffer_certificate_from_pem
- [ ] ./s2n/stuffer/s2n_stuffer_pem.c : s2n_stuffer_dhparams_from_pem
- [ ] ./s2n/stuffer/s2n_stuffer_text.c : s2n_stuffer_peek_char
- [ ] ./s2n/stuffer/s2n_stuffer_text.c : s2n_stuffer_skip_whitespace
- [ ] ./s2n/stuffer/s2n_stuffer_text.c : s2n_stuffer_read_token
- [ ] ./s2n/stuffer/s2n_stuffer_text.c : s2n_stuffer_alloc_ro_from_string
- [ ] ./s2n/tls/s2n_aead.c : s2n_aead_aad_init
- [ ] ./s2n/tls/s2n_alerts.c : s2n_process_alert_fragment
- [ ] ./s2n/tls/s2n_alerts.c : s2n_queue_writer_close_alert
- [ ] ./s2n/tls/s2n_alerts.c : s2n_queue_reader_unsupported_protocol_version_alert
- [ ] ./s2n/tls/s2n_cbc.c : s2n_verify_cbc
- [ ] ./s2n/tls/s2n_cipher_suites.c : s2n_cipher_suite_match
- [ ] ./s2n/tls/s2n_cipher_suites.c : s2n_set_cipher_as_client
- [ ] ./s2n/tls/s2n_cipher_suites.c : s2n_set_cipher_as_server
- [ ] ./s2n/tls/s2n_cipher_suites.c : s2n_set_cipher_as_sslv2_server
- [ ] ./s2n/tls/s2n_cipher_suites.c : s2n_set_cipher_as_tls_server
- [ ] ./s2n/tls/s2n_client_ccs.c : s2n_client_ccs_recv
- [ ] ./s2n/tls/s2n_client_ccs.c : s2n_client_ccs_send
- [ ] ./s2n/tls/s2n_client_extensions.c : s2n_server_name_rcv
- [ ] ./s2n/tls/s2n_client_extensions.c : s2n_signature_algorithms_rcv
- [ ] ./s2n/tls/s2n_client_extensions.c : s2n_alpn_rcv
- [ ] ./s2n/tls/s2n_client_extensions.c : s2n_status_request_rcv
- [ ] ./s2n/tls/s2n_client_extensions.c : s2n_elliptic_curves_rcv
- [ ] ./s2n/tls/s2n_client_extensions.c : s2n_ec_point_formats_rcv
- [ ] ./s2n/tls/s2n_client_extensions.c : s2n_client_extensions_send
- [ ] ./s2n/tls/s2n_client_extensions.c : s2n_client_extensions_recv
- [ ] ./s2n/tls/s2n_client_extensions.c : s2n_server_name_rcv
- [ ] ./s2n/tls/s2n_client_extensions.c : s2n_signature_algorithms_rcv
- [ ] ./s2n/tls/s2n_client_extensions.c : s2n_alpn_rcv
- [ ] ./s2n/tls/s2n_client_extensions.c : s2n_status_request_rcv
- [ ] ./s2n/tls/s2n_client_extensions.c : s2n_elliptic_curves_rcv
- [ ] ./s2n/tls/s2n_client_extensions.c : s2n_ec_point_formats_rcv
- [ ] ./s2n/tls/s2n_client_finished.c : s2n_client_finished_recv
- [ ] ./s2n/tls/s2n_client_finished.c : s2n_client_finished_send
- [ ] ./s2n/tls/s2n_client_hello.c : s2n_client_hello_recv
- [ ] ./s2n/tls/s2n_client_hello.c : s2n_client_hello_send
- [ ] ./s2n/tls/s2n_client_hello.c : s2n_sslv2_client_hello_recv
- [ ] ./s2n/tls/s2n_client_key_exchange.c : s2n_rsa_client_key_recv
- [ ] ./s2n/tls/s2n_client_key_exchange.c : s2n_dhe_client_key_recv
- [ ] ./s2n/tls/s2n_client_key_exchange.c : s2n_client_key_recv
- [ ] ./s2n/tls/s2n_client_key_exchange.c : s2n_dhe_client_key_send
- [ ] ./s2n/tls/s2n_client_key_exchange.c : s2n_rsa_client_key_send
- [ ] ./s2n/tls/s2n_client_key_exchange.c : s2n_client_key_send
- [X] ~~./s2n/tls/s2n_config.c : get_nanoseconds_since_epoch~~
- [ ] ./s2n/tls/s2n_config.c : s2n_config_new
- [ ] ./s2n/tls/s2n_config.c : s2n_config_free_cert_chain_and_key
- [ ] ./s2n/tls/s2n_config.c : s2n_config_free_dhparams
- [ ] ./s2n/tls/s2n_config.c : s2n_config_free
- [ ] ./s2n/tls/s2n_config.c : s2n_config_set_cipher_preferences
- [ ] ./s2n/tls/s2n_config.c : s2n_config_set_protocol_preferences
- [ ] ./s2n/tls/s2n_config.c : s2n_config_set_status_request_type
- [ ] ./s2n/tls/s2n_config.c : s2n_config_add_cert_chain_and_key
- [ ] ./s2n/tls/s2n_config.c : s2n_config_add_dhparams
- [ ] ./s2n/tls/s2n_config.c : s2n_config_set_nanoseconds_since_epoch_callback
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_new
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_free_keys
- [ ] ./s2n/tls/s2n_connection.c : s2n_shutdown
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_free
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_set_config
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_wipe
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_set_read_fd
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_set_write_fd
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_set_fd
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_get_wire_bytes_in
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_get_wire_bytes_out
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_get_cipher
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_get_client_protocol_version
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_get_server_protocol_version
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_get_actual_protocol_version
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_get_client_hello_version
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_get_alert
- [ ] ./s2n/tls/s2n_connection.c : s2n_set_server_name
- [ ] ./s2n/tls/s2n_connection.c : s2n_get_server_name
- [ ] ./s2n/tls/s2n_connection.c : s2n_get_application_protocol
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_set_blinding
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_get_delay
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_kill
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_get_ocsp_response
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_prefer_throughput
- [ ] ./s2n/tls/s2n_connection.c : s2n_connection_prefer_low_latency
- [ ] ./s2n/tls/s2n_handshake.c : s2n_handshake_write_header
- [ ] ./s2n/tls/s2n_handshake.c : s2n_handshake_finish_header
- [ ] ./s2n/tls/s2n_handshake.c : s2n_handshake_parse_header
- [ ] ./s2n/tls/s2n_handshake_io.c : s2n_conn_update_handshake_hashes
- [ ] ./s2n/tls/s2n_handshake_io.c : handshake_write_io
- [ ] ./s2n/tls/s2n_handshake_io.c : read_full_handshake_message
- [ ] ./s2n/tls/s2n_handshake_io.c : handshake_read_io
- [ ] ./s2n/tls/s2n_handshake_io.c : s2n_negotiate
- [ ] ./s2n/tls/s2n_ocsp_stapling.c : s2n_server_status_send
- [ ] ./s2n/tls/s2n_ocsp_stapling.c : s2n_server_status_recv
- [ ] ./s2n/tls/s2n_prf.c : s2n_sslv3_prf
- [ ] ./s2n/tls/s2n_prf.c : s2n_prf
- [ ] ./s2n/tls/s2n_prf.c : s2n_prf_master_secret
- [ ] ./s2n/tls/s2n_prf.c : s2n_sslv3_finished
- [ ] ./s2n/tls/s2n_prf.c : s2n_sslv3_client_finished
- [ ] ./s2n/tls/s2n_prf.c : s2n_sslv3_server_finished
- [ ] ./s2n/tls/s2n_prf.c : s2n_prf_client_finished
- [ ] ./s2n/tls/s2n_prf.c : s2n_prf_server_finished
- [ ] ./s2n/tls/s2n_prf.c : s2n_prf_key_expansion
- [ ] ./s2n/tls/s2n_record_read.c : s2n_sslv2_record_header_parse
- [ ] ./s2n/tls/s2n_record_read.c : s2n_record_header_parse
- [ ] ./s2n/tls/s2n_record_read.c : s2n_record_parse
- [ ] ./s2n/tls/s2n_record_write.c : overhead
- [ ] ./s2n/tls/s2n_record_write.c : s2n_record_max_write_payload_size
- [ ] ./s2n/tls/s2n_record_write.c : s2n_record_write
- [ ] ./s2n/tls/s2n_recv.c : s2n_read_full_record
- [ ] ./s2n/tls/s2n_recv.c : s2n_recv
- [ ] ./s2n/tls/s2n_send.c : s2n_flush
- [ ] ./s2n/tls/s2n_send.c : s2n_send
- [ ] ./s2n/tls/s2n_server_ccs.c : s2n_server_ccs_recv
- [ ] ./s2n/tls/s2n_server_ccs.c : s2n_server_ccs_send
- [ ] ./s2n/tls/s2n_server_cert.c : s2n_server_cert_recv
- [ ] ./s2n/tls/s2n_server_cert.c : s2n_server_cert_send
- [ ] ./s2n/tls/s2n_server_done.c : s2n_server_done_recv
- [ ] ./s2n/tls/s2n_server_done.c : s2n_server_done_send
- [ ] ./s2n/tls/s2n_server_extensions.c : s2n_server_recv_alpn
- [ ] ./s2n/tls/s2n_server_extensions.c : s2n_server_recv_status_request
- [ ] ./s2n/tls/s2n_server_extensions.c : s2n_server_extensions_send
- [ ] ./s2n/tls/s2n_server_extensions.c : s2n_server_extensions_recv
- [ ] ./s2n/tls/s2n_server_extensions.c : s2n_server_recv_alpn
- [ ] ./s2n/tls/s2n_server_extensions.c : s2n_server_recv_status_request
- [ ] ./s2n/tls/s2n_server_finished.c : s2n_server_finished_recv
- [ ] ./s2n/tls/s2n_server_finished.c : s2n_server_finished_send
- [ ] ./s2n/tls/s2n_server_hello.c : s2n_server_hello_recv
- [ ] ./s2n/tls/s2n_server_hello.c : s2n_server_hello_send
- [ ] ./s2n/tls/s2n_server_key_exchange.c : s2n_ecdhe_server_key_recv
- [ ] ./s2n/tls/s2n_server_key_exchange.c : s2n_dhe_server_key_recv
- [ ] ./s2n/tls/s2n_server_key_exchange.c : s2n_ecdhe_server_key_send
- [ ] ./s2n/tls/s2n_server_key_exchange.c : s2n_dhe_server_key_send
- [ ] ./s2n/tls/s2n_server_key_exchange.c : s2n_server_key_recv
- [ ] ./s2n/tls/s2n_server_key_exchange.c : s2n_ecdhe_server_key_recv
- [ ] ./s2n/tls/s2n_server_key_exchange.c : s2n_dhe_server_key_recv
- [ ] ./s2n/tls/s2n_server_key_exchange.c : s2n_server_key_send
- [ ] ./s2n/tls/s2n_server_key_exchange.c : s2n_ecdhe_server_key_send
- [ ] ./s2n/tls/s2n_server_key_exchange.c : s2n_dhe_server_key_send
- [X] ~~./s2n/utils/s2n_blob.c : s2n_blob_init~~
- [X] ~~./s2n/utils/s2n_blob.c : s2n_blob_zero~~
- [X] ~~./s2n/utils/s2n_mem.c : s2n_mem_init~~
- [X] __./s2n/utils/s2n_mem.c : s2n_alloc__
- [X] __./s2n/utils/s2n_mem.c : s2n_realloc__
- [X] ~~./s2n/utils/s2n_mem.c : s2n_free~~
- [X] ~~./s2n/utils/s2n_random.c : s2n_on_fork~~
- [ ] ./s2n/utils/s2n_random.c : s2n_defend_if_forked
- [ ] ./s2n/utils/s2n_random.c : s2n_get_public_random_data
- [ ] ./s2n/utils/s2n_random.c : s2n_get_private_random_data
- [ ] ./s2n/utils/s2n_random.c : s2n_get_public_random_bytes_used
- [ ] ./s2n/utils/s2n_random.c : s2n_get_private_random_bytes_used
- [ ] ./s2n/utils/s2n_random.c : s2n_get_urandom_data
- [ ] ./s2n/utils/s2n_random.c : s2n_public_random
- [ ] ./s2n/utils/s2n_random.c : s2n_openssl_compat_rand
- [X] ~~./s2n/utils/s2n_random.c : s2n_openssl_compat_status~~
- [X] ~~./s2n/utils/s2n_random.c : s2n_openssl_compat_init~~
- [ ] ./s2n/utils/s2n_random.c : s2n_init
- [ ] ./s2n/utils/s2n_random.c : s2n_cleanup
- [X] ~~./s2n/utils/s2n_safety.c : s2n_actual_getpid~~
- [X] ~~./s2n/utils/s2n_safety.c : s2n_constant_time_equals~~
- [X] ~~./s2n/utils/s2n_safety.c : s2n_constant_time_copy_or_dont~~
- [X] ~~./s2n/utils/s2n_timer.c : s2n_timer_start~~
- [X] ~~./s2n/utils/s2n_timer.c : s2n_timer_elapsed~~
- [X] ~~./s2n/utils/s2n_timer.c : s2n_timer_reset~~
