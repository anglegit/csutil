// Copyright (c) 2015 The CCUtil Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_ALGO_H_
#define BASE_ALGO_H_

#include "base/status.h"

namespace base
{

// Note: Longest common sequence
Code LCS(const std::string &seq_first, const std::string &seq_second, std::string *lcs_str);

// Note: Longest common substring
Code LCSS(const std::string &seq_first, const std::string &seq_second, std::string *lcss_str);
}

#endif
