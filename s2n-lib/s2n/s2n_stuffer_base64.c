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

#include <string.h>

#include "error/s2n_errno.h"

#include "stuffer/s2n_stuffer.h"

#include "utils/s2n_safety.h"

// don't care about the content
static const uint8_t b64[64];
	
// don't care about the content
static const uint8_t b64_inverse[256];

/**
 * NOTE:
 * In general, shift before masking. This avoids needing to worry about how the
 * signed bit may be handled. 
 */
int s2n_stuffer_read_base64(struct s2n_stuffer *stuffer, struct s2n_stuffer *out)
{
    uint8_t pad[4];
    int bytes_this_round = 3;
    struct s2n_blob o = {.data = pad,.size = sizeof(pad) };
    
    

//    do {
        if (s2n_stuffer_data_available(stuffer) < 4) {
            return 0;
        }
        
        s2n_stuffer_skip_read(stuffer, s2n_stuffer_data_available(stuffer) / 4 * 4); // must success;

        GUARD(s2n_stuffer_read(stuffer, &o));

        uint8_t value1 = b64_inverse[o.data[0]];
        uint8_t value2 = b64_inverse[o.data[1]];
        uint8_t value3 = b64_inverse[o.data[2]];
        uint8_t value4 = b64_inverse[o.data[3]];

        /* Terminate cleanly if we encounter a non-base64 character */
        if (value1 == 255) {
            /* Undo the read */
            stuffer->read_cursor -= 4;
            return 0;
        }

        /* The first two characters can never be '=' and in general
         * everything has to be a valid character. 
         */
        if (value1 == 64 || value2 == 64 || value2 == 255 || value3 == 255 || value4 == 255) {
            S2N_ERROR(S2N_ERR_INVALID_BASE64);
        }

        if (o.data[2] == '=') {
            /* If there is only one output byte, then the second value
             * should have none of its bottom four bits set.
             */
            if (o.data[3] != '=' || value2 & 0x0f) {
                S2N_ERROR(S2N_ERR_INVALID_BASE64);
            }
            bytes_this_round = 1;
//            value3 = 0;
//            value4 = 0;
        } else if (o.data[3] == '=') {
            /* The last two bits of the final value should be unset */
            if (value3 & 0x03) {
                S2N_ERROR(S2N_ERR_INVALID_BASE64);
            }

            bytes_this_round = 2;
//            value4 = 0;
        }

        /* value1 maps to the first 6 bits of the first data byte */
        /* value2's top two bits are the rest */
        uint8_t c;
        GUARD(s2n_stuffer_write_uint8(out, c));

        if (bytes_this_round > 1) {
            /* Put the next four bits in the second data byte */
            /* Put the next four bits in the third data byte */
//            c = ((value2 << 4) & 0xf0) | ((value3 >> 2) & 0x0f);
            GUARD(s2n_stuffer_write_uint8(out, c));
        }

        if (bytes_this_round > 2) {
            /* Put the next two bits in the third data byte */
            /* Put the next six bits in the fourth data byte */
//            c = ((value3 << 6) & 0xc0) | (value4 & 0x3f);
            GUARD(s2n_stuffer_write_uint8(out, c));
        }

//    } while (bytes_this_round == 3);

    return 0;
}

int s2n_stuffer_write_base64(struct s2n_stuffer *stuffer, struct s2n_stuffer *in)
{
//    while (s2n_stuffer_data_available(in) > 2) {
    if(s2n_stuffer_data_available(in) > 2){
        uint32_t in_size = s2n_stuffer_data_available(in) / 3 * 3;
        uint8_t inpad[in_size];
        struct s2n_blob i = {.data = inpad,.size = in_size };
        GUARD(s2n_stuffer_read(in, &i));
		
		// Don't care a
		
        /* Take the top 6-bits of the first data byte  */
        // o.data[0] = b64[(i.data[0] >> 2) & 0x3f];

        /* Take the bottom 2-bits of the first data byte -  0b00110000 = 0x30
         * and take the top 4-bits of the second data byte - 0b00001111 = 0x0f 
         */
        // o.data[1] = b64[((i.data[0] << 4) & 0x30) | ((i.data[1] >> 4) & 0x0f)];

        /* Take the bottom 4-bits of the second data byte - 0b00111100 = 0x3c
         * and take the top 2-bits of the third data byte - 0b00000011 = 0x03 
         */
        // o.data[2] = b64[((i.data[1] << 2) & 0x3c) | ((i.data[2] >> 6) & 0x03)];

        /* Take the bottom 6-bits of the second data byte - 0b00111111 = 0x3f
         */
        // o.data[3] = b64[i.data[2] & 0x3f];

        uint32_t out_size = s2n_stuffer_data_available(in) / 3 * 4;
        uint8_t outpad[out_size];
        struct s2n_blob o = {.data = outpad,.size = out_size };
        GUARD(s2n_stuffer_write(stuffer, &o));
    }

    if (s2n_stuffer_data_available(in)) {
        uint8_t outpad[4];
        uint8_t inpad[3];
        struct s2n_blob o = {.data = outpad,.size = sizeof(outpad) };
        struct s2n_blob i = {.data = inpad,.size = sizeof(inpad) };
        /* Read just one byte */
        i.size = 1;
        GUARD(s2n_stuffer_read(in, &i));
//        uint8_t c = i.data[0];

        /* We at least one data byte left to encode, encode
         * its first six bits 
         */
//        o.data[0] = b64[(c >> 2) & 0x3f];

        /* And our end has to be an equals */
//        o.data[3] = '=';

        /* How many bytes are actually left? */
        if (s2n_stuffer_data_available(in) != 0) {
            /* We just have the last two bits to deal with */
//            o.data[1] = b64[(c << 4) & 0x30];
//            o.data[2] = '=';
//        } else {
            /* Read the last byte */
            GUARD(s2n_stuffer_read(in, &i));

//            o.data[1] = b64[((c << 4) & 0x30) | ((i.data[0] >> 4) & 0x0f)];
//            o.data[2] = b64[((i.data[0] << 2) & 0x3c)];
        }

        GUARD(s2n_stuffer_write(stuffer, &o));
    }

    return 0;
}
