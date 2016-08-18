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

#include <stdlib.h>
#include <s2n.h>

int main(int argc, char **argv)
{
    struct s2n_connection *conn;

//    conn = s2n_connection_new(S2N_CLIENT);
//    __CPROVER_assert(conn == NULL, "ERROR: s2n_connection_new");

//    GUARD(setenv("S2N_ENABLE_CLIENT_MODE", "1", 0));
    conn = s2n_connection_new(S2N_CLIENT);
    
//    __CPROVER_assert(conn != NULL, "ERROR: s2n_connection_new");
    GUARD(s2n_connection_free(conn));

//    END_TEST();
}
