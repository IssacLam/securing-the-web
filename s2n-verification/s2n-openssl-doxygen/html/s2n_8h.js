var s2n_8h =
[
    [ "S2N_SSLv2", "s2n_8h.html#a495735277344c9c306668f6027e3f077", null ],
    [ "S2N_SSLv3", "s2n_8h.html#a457805749bd152786e9e344a5b22ab67", null ],
    [ "S2N_TLS10", "s2n_8h.html#ab16c04a1d8479546aa124c4e52a1703f", null ],
    [ "S2N_TLS11", "s2n_8h.html#a2e4a51448d3a9ea14b506ac2573f9bae", null ],
    [ "S2N_TLS12", "s2n_8h.html#ab17e84046986d49ffd31571b8d32d24e", null ],
    [ "s2n_blinding", "s2n_8h.html#a364ad496c9dd42fd3117a2f9d3289e62", [
      [ "S2N_BUILT_IN_BLINDING", "s2n_8h.html#a364ad496c9dd42fd3117a2f9d3289e62a090459f0733b199be908d881d7db871f", null ],
      [ "S2N_SELF_SERVICE_BLINDING", "s2n_8h.html#a364ad496c9dd42fd3117a2f9d3289e62a1b0ee228485be6bb2d6e2129827d51d2", null ]
    ] ],
    [ "s2n_blocked_status", "s2n_8h.html#af70ca0b089daa98cd79a424d3f6af15d", [
      [ "S2N_NOT_BLOCKED", "s2n_8h.html#af70ca0b089daa98cd79a424d3f6af15da7afdc9e789b567fe89c7142f34ec3ebd", null ],
      [ "S2N_BLOCKED_ON_READ", "s2n_8h.html#af70ca0b089daa98cd79a424d3f6af15daf76a7c83e9548139b7b8d50bdd5ff323", null ],
      [ "S2N_BLOCKED_ON_WRITE", "s2n_8h.html#af70ca0b089daa98cd79a424d3f6af15daefb6db9aaec431d69fc4c1249bc432e3", null ]
    ] ],
    [ "s2n_error", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374", [
      [ "S2N_ERR_OK", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a65e9549d0d6ac5e31ba072024a1d90b6", null ],
      [ "S2N_ERR_KEY_INIT", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374aa6552a4aadc6ae8612fe8a1913b07227", null ],
      [ "S2N_ERR_ENCRYPT", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a9b46d2791a96308ba8676e62df00f479", null ],
      [ "S2N_ERR_DECRYPT", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a2242cf397568c29bfa830fb9193f59b8", null ],
      [ "S2N_ERR_MADVISE", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a964bdab8630956318e5cc0fdcbd3a62e", null ],
      [ "S2N_ERR_ALLOC", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374abc633cc681982dbcae6a882d6e440b59", null ],
      [ "S2N_ERR_MLOCK", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a7c451062808e1e9103be90527371fcf1", null ],
      [ "S2N_ERR_MUNLOCK", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374accf79bfdaea22b93ddce06b768a2ede5", null ],
      [ "S2N_ERR_FSTAT", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374abde844e98846fede82302b8fd5011a40", null ],
      [ "S2N_ERR_OPEN", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374aa974803af263a6b745dd91845c0d8d8f", null ],
      [ "S2N_ERR_MMAP", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a0ff34e4f61f50cdd411779a62c007ef9", null ],
      [ "S2N_ERR_NULL", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374aa855b2076e4277d53c6a4197e124f541", null ],
      [ "S2N_ERR_CLOSED", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374ab2b3c63db9e35ed79c3191161b6c9ccc", null ],
      [ "S2N_ERR_SAFETY", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a4069426741d8e86dcb3b20cacf4ca256", null ],
      [ "S2N_ERR_NOT_INITIALIZED", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374adecf0d429d255afc70afd5c1606cfa43", null ],
      [ "S2N_ERR_RANDOM_UNITIALIZED", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374af004c642762f48560f1aff9537eb2074", null ],
      [ "S2N_ERR_OPEN_RANDOM", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a3775b7d21a1f01da2b7c97a07bdf34e3", null ],
      [ "S2N_ERR_RESIZE_STATIC_STUFFER", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a53f8c3514daf58a4e77ab1afb5311038", null ],
      [ "S2N_ERR_RESIZE_TAINTED_STUFFER", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a65d494c13c6fd2dac7f1b085041da0f6", null ],
      [ "S2N_ERR_STUFFER_OUT_OF_DATA", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a672eb430928d83492972f19278d04e36", null ],
      [ "S2N_ERR_STUFFER_IS_FULL", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a8c493b24e7852c5f040974cb19e2e19c", null ],
      [ "S2N_ERR_INVALID_BASE64", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374ab2a194f5cf5937519b071c821384d77e", null ],
      [ "S2N_ERR_INVALID_PEM", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374ac81f6f52c3919d5dffecc2cb370a0148", null ],
      [ "S2N_ERR_DH_COPYING_PARAMETERS", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374ace9a340f09f59dab372078333649ad2f", null ],
      [ "S2N_ERR_DH_COPYING_PUBLIC_KEY", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374adec124ecb79d810d583a31e0fc33c9a6", null ],
      [ "S2N_ERR_DH_GENERATING_PARAMETERS", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a8d181b1ef77d0c168a4b43b49f15a3c0", null ],
      [ "S2N_ERR_DH_PARAMS_CREATE", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a4071d2b17d5b3c8525982aa983ddd2a2", null ],
      [ "S2N_ERR_DH_SERIAZING", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a90c39e8292b678318634f900d6672008", null ],
      [ "S2N_ERR_DH_SHARED_SECRET", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374abfabc3263311a9f4ddb11da41d1a3aaa", null ],
      [ "S2N_ERR_DH_WRITING_PUBLIC_KEY", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374aec7baf57d106bd52b114ec4c3fbf0568", null ],
      [ "S2N_ERR_DH_FAILED_SIGNING", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374aef5fa19836d37d5b82102bc68b6e41f0", null ],
      [ "S2N_ERR_DH_TOO_SMALL", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374acd8104497ab7863359d073815cfd9f96", null ],
      [ "S2N_ERR_DH_PARAMETER_CHECK", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374ac3ef5bd668265a693fc8ca3ad5ef5ed8", null ],
      [ "S2N_ERR_INVALID_PKCS3", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374af89c8a897fc5730787cd111eadd1ace8", null ],
      [ "S2N_ERR_HASH_DIGEST_FAILED", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374ac8edf416a19010bdd242d56cfb6fd172", null ],
      [ "S2N_ERR_HASH_INIT_FAILED", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a63636d2907034770b0e146a47c33ca5b", null ],
      [ "S2N_ERR_HASH_INVALID_ALGORITHM", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a715f2e3454809e6ff16921af3c6aff2d", null ],
      [ "S2N_ERR_HASH_UPDATE_FAILED", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a301c16cbb517ba116132cd91739f9fe5", null ],
      [ "S2N_ERR_HMAC_INVALID_ALGORITHM", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a88646132941fcdf8bfc5a2fa969ed504", null ],
      [ "S2N_ERR_SIZE_MISMATCH", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a602cb5165e354dd39c49af50bbbc1cb9", null ],
      [ "S2N_ERR_DECODE_CERTIFICATE", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a46d2327df07ab8f6863716b825d9b944", null ],
      [ "S2N_ERR_DECODE_PRIVATE_KEY", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a1ddd7522c0c7db02818a534493847b60", null ],
      [ "S2N_ERR_KEY_MISMATCH", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374ae6514507be52111cd6ff29ff8cd66492", null ],
      [ "S2N_ERR_NOMEM", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a62eafb08bfa7ff987c91a1e8c4149b69", null ],
      [ "S2N_ERR_SIGN", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a2e35fce779150b5c8db2cd5b2e1c0950", null ],
      [ "S2N_ERR_VERIFY_SIGNATURE", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374aad4bf04b3c6e0c5cef4973424d195099", null ],
      [ "S2N_ERR_ALERT_PRESENT", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a1470b8d4d31e2e9a192b9050189d9de2", null ],
      [ "S2N_ERR_ALERT", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374ad8f7a3c42828dada877dd5ec0e59621f", null ],
      [ "S2N_ERR_CBC_VERIFY", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a0afdacaa8f5d3e7ea6251cd45c64f823", null ],
      [ "S2N_ERR_CIPHER_NOT_SUPPORTED", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a24d9f899017e0ab819c0eccbe0d26625", null ],
      [ "S2N_ERR_BAD_MESSAGE", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374ad61ca0bcc8f9f8bf3e065de30ad547fb", null ],
      [ "S2N_ERR_INVALID_SIGNATURE_ALGORITHM", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374ac68dbe36d515759d6ba535808027ad8c", null ],
      [ "S2N_ERR_INVALID_KEY_EXCHANGE_ALGORITHM", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374ab49d8a75859caa8982ff6f02fec18aa1", null ],
      [ "S2N_ERR_NO_CERTIFICATE_IN_PEM", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374af827daeee4a4fdebd53208c6aa6838fc", null ],
      [ "S2N_ERR_NO_ALERT", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a41d4edb2db2b8a47bef1fc1cd2b1c28a", null ],
      [ "S2N_ERR_CLIENT_MODE", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a207a9f23900efd06b04b54f9cc02785d", null ],
      [ "S2N_ERR_SERVER_NAME_TOO_LONG", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374aa12e0d8c45892e39c3b136f3befc1c2d", null ],
      [ "S2N_ERR_CLIENT_MODE_DISABLED", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a7539b2b5bdba3331c219d1b1705a6d3f", null ],
      [ "S2N_ERR_HANDSHAKE_STATE", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374ae948d942ad6d03abc85d9f90cfae3d45", null ],
      [ "S2N_ERR_FALLBACK_DETECTED", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a5ba2e4d4c7878020b2c2c86ad3601d0d", null ],
      [ "S2N_ERR_INVALID_CIPHER_PREFERENCES", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a9ee4d3a497355312397dfe229b4308a6", null ],
      [ "S2N_ERR_APPLICATION_PROTOCOL_TOO_LONG", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a405ec87b8c6c043ec85ffce9c6b1f205", null ],
      [ "S2N_ERR_NO_APPLICATION_PROTOCOL", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a0dbaa6408e4de7b8a1c384037460c9a6", null ],
      [ "S2N_ERR_DRBG", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a0e644fc7fc778e87f32e4e9044d5a994", null ],
      [ "S2N_ERR_DRBG_REQUEST_SIZE", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a1cd170b6236f8a0a7af56463a1b0cfaa", null ],
      [ "S2N_ERR_ECDHE_GEN_KEY", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a59d438f8b9b73def7eeba529ff4bac9d", null ],
      [ "S2N_ERR_ECDHE_SHARED_SECRET", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a62aff74bf4b886c16f4e61fa3bd4d970", null ],
      [ "S2N_ERR_ECDHE_UNSUPPORTED_CURVE", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a05bae59c6e1cb8b82abdde7ee1ff5b74", null ],
      [ "S2N_ERR_ECDHE_SERIALIZING", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374a67be45a1131c05bc23d9ef60c273959b", null ],
      [ "S2N_ERR_SHUTDOWN_PAUSED", "s2n_8h.html#a64ed9ec59a957387654c5e5865325374ad5835c53ea39aa0c10935ca04519c98e", null ]
    ] ],
    [ "s2n_mode", "s2n_8h.html#a77a64e3b657f90d221c5faf99c643cdb", [
      [ "S2N_SERVER", "s2n_8h.html#a77a64e3b657f90d221c5faf99c643cdba6d8d11a87ee62316e49b1b166c2b2c52", null ],
      [ "S2N_CLIENT", "s2n_8h.html#a77a64e3b657f90d221c5faf99c643cdbac93ba9ce574a0b5893fe2a5960e1785d", null ]
    ] ],
    [ "s2n_status_request_type", "s2n_8h.html#a7d38e45340d223d0100a2d4bc0526635", [
      [ "S2N_STATUS_REQUEST_NONE", "s2n_8h.html#a7d38e45340d223d0100a2d4bc0526635aea0f05b257857adc1282f77c5414e35a", null ],
      [ "S2N_STATUS_REQUEST_OCSP", "s2n_8h.html#a7d38e45340d223d0100a2d4bc0526635a3e83f0e90eef54adc21b3d97a9a0d9b8", null ]
    ] ],
    [ "s2n_cleanup", "s2n_8h.html#a907fdf445e5fb1752f1b18f0ddf935b3", null ],
    [ "s2n_config_add_cert_chain_and_key", "s2n_8h.html#a315153a7f97b2568970c19f7bf1d372e", null ],
    [ "s2n_config_add_cert_chain_and_key_with_status", "s2n_8h.html#a0275e457e9c62cf1d5b9a1126e853003", null ],
    [ "s2n_config_add_dhparams", "s2n_8h.html#a82513564c95dc7a4174c3d04eb043564", null ],
    [ "s2n_config_free", "s2n_8h.html#a25b7d82e94f572b657be3936196222c3", null ],
    [ "s2n_config_free_cert_chain_and_key", "s2n_8h.html#acb820ee4c2c4978ddeb317d746ad1038", null ],
    [ "s2n_config_free_dhparams", "s2n_8h.html#a3bf1287851eae46189744a86b883a7da", null ],
    [ "s2n_config_new", "s2n_8h.html#a29ce06d12862218a283abdac554c8e19", null ],
    [ "s2n_config_set_cipher_preferences", "s2n_8h.html#a21b09fcd09e2d33e8ed9389a109f2ab2", null ],
    [ "s2n_config_set_key_exchange_preferences", "s2n_8h.html#a3ec6ccc7afb736fcc26669d2417e1b24", null ],
    [ "s2n_config_set_nanoseconds_since_epoch_callback", "s2n_8h.html#a55f4687b7def930a7ac41335d35d72ef", null ],
    [ "s2n_config_set_protocol_preferences", "s2n_8h.html#a9f5f2fca97444f9c039a3681c2351fb0", null ],
    [ "s2n_config_set_status_request_type", "s2n_8h.html#ae98f2b06b3311e7e845e938392d3505d", null ],
    [ "s2n_connection_free", "s2n_8h.html#a03ed084d7fb943c7d32b13075ed8eff7", null ],
    [ "s2n_connection_get_actual_protocol_version", "s2n_8h.html#a4cb9df94e1fe137f10040fbfc1ad98f9", null ],
    [ "s2n_connection_get_alert", "s2n_8h.html#a6726a1cbae275671f2751ac610dc5f0f", null ],
    [ "s2n_connection_get_cipher", "s2n_8h.html#a119c0252cf7edde4d4a5c65f8cd23721", null ],
    [ "s2n_connection_get_client_hello_version", "s2n_8h.html#a3d4e8c095c40ea7689f14022567cd3e9", null ],
    [ "s2n_connection_get_client_protocol_version", "s2n_8h.html#af15303e1d72a95320b6138edeef7a6ab", null ],
    [ "s2n_connection_get_delay", "s2n_8h.html#aebf38ba3c1ebd08e7fdd185d8f3ec521", null ],
    [ "s2n_connection_get_ocsp_response", "s2n_8h.html#a2b18cd3437636a7a21e10f3d5d09ff9d", null ],
    [ "s2n_connection_get_server_protocol_version", "s2n_8h.html#ae2ea6a2e6468883f56459431f2024b0f", null ],
    [ "s2n_connection_get_wire_bytes_in", "s2n_8h.html#a4d1194b561c825208d387b4660670b63", null ],
    [ "s2n_connection_get_wire_bytes_out", "s2n_8h.html#a43ef96c4123345ccc7952a387125409e", null ],
    [ "s2n_connection_new", "s2n_8h.html#acffb3a7098380db63bc23498482ee4b9", null ],
    [ "s2n_connection_prefer_low_latency", "s2n_8h.html#a332427237ca8907196034ac5768a65bf", null ],
    [ "s2n_connection_prefer_throughput", "s2n_8h.html#ab242f62c5824c72476844970b1ae7301", null ],
    [ "s2n_connection_set_blinding", "s2n_8h.html#a7b2423a701b89f7ca3a4de550c519d35", null ],
    [ "s2n_connection_set_config", "s2n_8h.html#a85ced5d91831da552d5c4997a3f30abb", null ],
    [ "s2n_connection_set_fd", "s2n_8h.html#a80776ecf7e726f52165cdec5e2652d1e", null ],
    [ "s2n_connection_set_read_fd", "s2n_8h.html#a098af174491e2fe62cb0635d1adab854", null ],
    [ "s2n_connection_set_write_fd", "s2n_8h.html#ab340fbb2459b04d8f6d2803483a14ab1", null ],
    [ "s2n_connection_wipe", "s2n_8h.html#aa869211ca9b49f497cdb5579935203de", null ],
    [ "s2n_get_application_protocol", "s2n_8h.html#a5a0e7b4549f38de84e325e221b596908", null ],
    [ "s2n_get_server_name", "s2n_8h.html#a541a5e22fc8b6295e4c6bb1692cdd850", null ],
    [ "s2n_init", "s2n_8h.html#abc620f8194383c6fcddd911edcf7d692", null ],
    [ "s2n_negotiate", "s2n_8h.html#a309d98d4c1adfd10c5dd62192f4c1051", null ],
    [ "s2n_recv", "s2n_8h.html#afede11e597a4db3024ec2b68733a643d", null ],
    [ "s2n_send", "s2n_8h.html#a6d221800840cc73c57109088dac2f467", null ],
    [ "s2n_set_server_name", "s2n_8h.html#a9b37f3c0364e6de9f0b534e624204f62", null ],
    [ "s2n_shutdown", "s2n_8h.html#a1cb034f97199a7f7d7888a447cf0fe67", null ],
    [ "s2n_strerror", "s2n_8h.html#ae437dde74e36e51acb16397be23df69b", null ],
    [ "s2n_errno", "s2n_8h.html#a40090b57614b9677d4cbcdd3c3276e7d", null ]
];