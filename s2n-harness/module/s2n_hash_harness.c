/*
 * Copyright 2014 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

//#include "s2n_test.h"

#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"

#include <string.h>

//#include "testlib/s2n_testlib.h"
#include "stuffer/s2n_stuffer.h"
#include "crypto/s2n_hash.h"
#include "utils/s2n_blob.h"

uint32_t nondet_uint32();
s2n_hash_algorithm nondet_s2n_hash_algorithm();

//typedef enum { S2N_HASH_NONE, S2N_HASH_MD5, S2N_HASH_SHA1, S2N_HASH_SHA224, S2N_HASH_SHA256, S2N_HASH_SHA384, S2N_HASH_SHA512, S2N_HASH_MD5_SHA1 } s2n_hash_algorithm;

int main(int argc, char **argv)
{
    struct s2n_hash_state hash, copy;
    uint8_t output_pad[64];
    
    uint32_t length = nondet_uint32();
    __CPROVER_assume(length > 0);
    
    uint8_t msg[length];
    

    s2n_hash_algorithm alg = nondet_s2n_hash_algorithm();
    __CPROVER_assume(alg >= 0 && alg <= 7);
        
    uint8_t digestSize = s2n_hash_digest_size(alg);
        
    // normal hash flow
    GUARD(s2n_hash_digest_size(alg));
    GUARD(s2n_hash_init(&hash, alg));
    GUARD(s2n_hash_update(&hash, msg, length));
    // only the hash state is changed
    GUARD(s2n_hash_digest(&hash, output_pad, digestSize));
    GUARD(s2n_hash_copy(&copy, &hash));
    return 0;
}
