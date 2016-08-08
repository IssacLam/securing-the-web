/*
 * Copyright 2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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

#include "utils/s2n_timer.h"
#include "tls/s2n_config.h"

int mock_clock(void *in, uint64_t *out)
{
    *out = *(uint64_t *)in;
    return 0;
}

int main(int argc, char **argv)
{
    struct s2n_config *config;
    struct s2n_timer timer;
    uint64_t nanoseconds;
    uint64_t mock_time;

//    BEGIN_TEST();

//    EXPECT_NOT_NULL(config = s2n_config_new());
//    EXPECT_SUCCESS(s2n_config_set_nanoseconds_since_epoch_callback(config, mock_clock, &mock_time));
    config = (struct s2n_config*) s2n_config_new();
    s2n_config_set_nanoseconds_since_epoch_callback(config, mock_clock, &mock_time);

    mock_time = 0;
//    EXPECT_SUCCESS(s2n_timer_start(config, &timer));
    s2n_timer_start(config, &timer);

    mock_time = 10;
//    EXPECT_SUCCESS(s2n_timer_reset(config, &timer, &nanoseconds));
//    EXPECT_EQUAL(nanoseconds, 10);
    s2n_timer_reset(config, &timer, &nanoseconds);

    mock_time = 20;
//    EXPECT_SUCCESS(s2n_timer_elapsed(config, &timer, &nanoseconds));
//    EXPECT_EQUAL(nanoseconds, 10);
    s2n_timer_elapsed(config, &timer, &nanoseconds);

    mock_time = 30;
//    EXPECT_SUCCESS(s2n_timer_reset(config, &timer, &nanoseconds));
//    EXPECT_EQUAL(nanoseconds, 20);
    s2n_timer_reset(config, &timer, &nanoseconds);

    mock_time = 40;
//    EXPECT_SUCCESS(s2n_timer_elapsed(config, &timer, &nanoseconds));
//    EXPECT_EQUAL(nanoseconds, 10);
    s2n_timer_elapsed(config, &timer, &nanoseconds);

//    END_TEST();
}
