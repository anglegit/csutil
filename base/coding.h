// Copyright (c) 2015 The CSUTIL Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_CODING_H_
#define BASE_CODING_H_

#include <string>

#include <stdint.h>

#include "status.h"

namespace base
{

Code EncodeFixed32(uint32_t num, std::string *out);
Code DecodeFixed32(const std::string &in, uint32_t *value);

Code EncodeFixed64(uint64_t num, std::string *out);
Code DecodeFixed64(const std::string &in, uint64_t *value);

// Example: 0x1 = > '1'
Code ToHex(uint8_t src_ch, uint8_t *dst_hex_ch);
// Example: '1' => 0x1
Code ToBin(uint8_t src_hex_ch, uint8_t *dst_ch);

// Example: 0xa1 => 'a''1'
Code BinToAscii(uint8_t src_ch, uint8_t *dst_high_ch, uint8_t *dst_low_ch);
// Example: 'a''1' => 0xa1
Code AsciiToBin(uint8_t src_high_ch, uint8_t src_low_ch, uint8_t *dst_bin_ch);

/**
 * Note: 1. Using standard of https://en.wikipedia.org/wiki/Percent-encoding
 *       2. As is known that Characters from the unreserved set never need to be percent-encoded!
 *          Unrserved characters are: 
 *          A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
 *          a b c d e f g h i j k l m n o p q r s t u v w x y z
 *          0 1 2 3 4 5 6 7 8 9 - _ . ~
 */
Code UrlEncode(const std::string &src, std::string *dst);

Code UrlDecode(const std::string &src, std::string *dst);


Code Base64Encode(const std::string &src, std::string *dst);
Code Base64Decode(const std::string &src, std::string *dst);
Code GetUnitVisibleChar(const char* unit_str, int size, uint8_t* num1, uint8_t* num2, uint8_t* num3, uint8_t *num4);
Code GetUnitInvisibleChar(const char* unit_str, int size, uint8_t* num1, uint8_t* num2, uint8_t* num3, uint8_t* invisible_size);
Code GetVisibleChar(uint8_t invisible_src, uint8_t *visible_dst);
Code GetInvisibleChar(uint8_t visible_src, uint8_t *invisible_dst);

}

#endif
