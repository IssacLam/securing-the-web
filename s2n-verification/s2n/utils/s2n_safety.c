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

#define _GNU_SOURCE             /* For syscall on Linux */
#undef _POSIX_C_SOURCE          /* For syscall() on Mac OS X */

#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <stdint.h>

/**
 * Get the process id
 *
 * Returns:
 *  The process ID of the current process
 */
pid_t s2n_actual_getpid()
{
#if defined(__GNUC__) && defined(SYS_getpid)
    /* http://yarchive.net/comp/linux/getpid_caching.html */
    return (pid_t) syscall(SYS_getpid);
#else
    return getpid();
#endif
}

int s2n_constant_time_equals(const uint8_t *a, const uint8_t *b, uint32_t len)
{
//	__CPROVER_assume(a != NULL && b != NULL && len > 0);
    uint8_t xor = 0;
    for (int i = 0; i < len; i++) {
        xor |= a[i] ^ b[i];
    }
//	__CPROVER_assert((xor > 0 && __CPROVER_exists { int j; (j >= 0 && j < len) ==> a[j] != b[j]}) ||
//	( xor == 0 && __CPROVER_forall { int j; (j >= 0 && j < len) ==> a[j] == b[j] }), "ERROR: s2n_constant_time_equals");
    return !xor;
}

int s2n_constant_time_copy_or_dont(uint8_t *a, const uint8_t *b, uint32_t len, uint8_t dont)
{	
//	__CPROVER_assume(a != NULL && b != NULL && len > 0 && dont >= 0);
    uint8_t mask = ~(0xff << ((!dont) * 8));

	__CPROVER_assert((dont > 0 && mask == 0x00) || (dont == 0 && mask == 0xff), "ERROR: mask");
    /* dont = 0 : mask = 0xff */
    /* dont > 0 : mask = 0x00 */

    for (int i = 0; i < len; i++) {
        uint8_t old = a[i];
        uint8_t diff = (old ^ b[i]) & mask;
        a[i] = old ^ diff;
    }
//	__CPROVER_assert(dont > 0 || (dont == 0 && __CPROVER_forall { int j; (j >= 0 && j < len) ==> a[j] == b[j]}), "ERROR: s2n_constant_time_copy_or_dont");
    return 0;
}
