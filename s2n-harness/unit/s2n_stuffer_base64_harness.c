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
#include <string.h>
#include <s2n.h>

#include "stuffer/s2n_stuffer.h"
#include "utils/s2n_random.h"

uint32_t nondet_uint32();

int main(int argc, char **argv)
{
    uint32_t hello_world_length = nondet_uint32();
    __CPROVER_assume(hello_world_length > 0);
    
    uint32_t pad_length = nondet_uint32();
    __CPROVER_assume(pad_length > 0);
    
    
    
    char hello_world[hello_world_length];
//    uint8_t hello_world_base64[] = "SGVsbG8gd29ybGQhAA==";
    struct s2n_stuffer stuffer, known_data, scratch, entropy, mirror;
    
    uint8_t pad[pad_length];
    struct s2n_blob r = {.data = pad, .size = sizeof(pad)};

//    BEGIN_TEST();
    

    /* Create a 100 byte stuffer */
    GUARD(s2n_stuffer_alloc(&stuffer, nondet_uint32()));

    /* Write our known data */
    GUARD(s2n_stuffer_alloc_ro_from_string(&known_data, hello_world));
    GUARD(s2n_stuffer_write_base64(&stuffer, &known_data));
    GUARD(s2n_stuffer_free(&known_data));

    /* Check it against the known output */
//    EXPECT_EQUAL(memcmp(stuffer.blob.data, hello_world_base64, strlen((char *)hello_world)), 0);

    /* Check that we can read it again */
    GUARD(s2n_stuffer_alloc(&scratch, nondet_uint32()));
    GUARD(s2n_stuffer_read_base64(&stuffer, &scratch));
//    GUARD(memcmp(scratch.blob.data, hello_world, strlen(hello_world)));

    /* Now try with some randomly generated data. Make sure we try each boundary case,
     * where size % 3 == 0, 1, 2
     */
    GUARD(s2n_stuffer_alloc(&entropy, nondet_uint32()));
    GUARD(s2n_stuffer_alloc(&mirror, nondet_uint32()));

    for (int i = entropy.blob.size; i > 0; i--) {
        GUARD(s2n_stuffer_wipe(&stuffer));
        GUARD(s2n_stuffer_wipe(&entropy));
        GUARD(s2n_stuffer_wipe(&mirror));

        /* Get i bytes of random data */
        r.size = i;
        GUARD(s2n_get_urandom_data(&r));
        GUARD(s2n_stuffer_write_bytes(&entropy, pad, i));

        /* Write i bytes  it, base64 encoded */
        /* Read it back, decoded */
        GUARD(s2n_stuffer_write_base64(&stuffer, &entropy));

        /* Should be (i / 3) * 4 + a carry  */
//        EXPECT_EQUAL((i / 3) * 4 + ((i % 3) ? 4 : 0), s2n_stuffer_data_available(&stuffer));

        /* Read it back, decoded */
        GUARD(s2n_stuffer_read_base64(&stuffer, &mirror));

        /* Verify it's the same */
//        EXPECT_EQUAL(memcmp(mirror.blob.data, entropy.blob.data, i), 0);
        /* We dont't do the actual memcpy */
    }

    GUARD(s2n_stuffer_free(&stuffer));
    GUARD(s2n_stuffer_free(&scratch));
    GUARD(s2n_stuffer_free(&mirror));
    GUARD(s2n_stuffer_free(&entropy));

//    END_TEST();
}
