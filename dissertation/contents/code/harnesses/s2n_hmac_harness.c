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

#include "error/s2n_errno.h"
#include "utils/s2n_safety.h"
//#include "s2n_test.h"

//#include "testlib/s2n_testlib.h"
#include "stuffer/s2n_stuffer.h"
#include "crypto/s2n_hash.h"
#include "crypto/s2n_hmac.h"
#include <string.h>

uint8_t nondet_uint8();
uint32_t nondet_uint32();
s2n_hmac_algorithm nondet_s2n_hmac_algorithm();

int main(int argc, char **argv)
{
    uint8_t output_pad[256];
    
    uint32_t sekritSize = nondet_uint32();
    __CPROVER_assume(sekritSize > 0 && sekritSize < 1 << 16);
    
    uint32_t msgSize = nondet_uint32();
    __CPROVER_assume(msgSize > 0);
    
    uint8_t sekrit[sekritSize];
    uint8_t msg[msgSize];
    struct s2n_hmac_state hmac, copy;

    s2n_hmac_algorithm alg = nondet_s2n_hmac_algorithm();
    __CPROVER_assume(alg >= 0 && alg < 8);
        
    uint8_t digestSize = s2n_hmac_digest_size(alg);
    GUARD(s2n_hmac_init(&hmac, alg, sekrit, sekritSize));
    GUARD(s2n_hmac_update(&hmac, msg, msgSize));
    GUARD(s2n_hmac_digest(&hmac, output_pad, digestSize));
        
    GUARD(s2n_hmac_copy(&copy, &hmac));
    return 0;
}
