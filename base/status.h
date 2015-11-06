// Copyright (c) 2015 The CCUtil Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_STATUS_H_ 
#define BASE_STATUS_H_

#include <string>

namespace base
{

const std::string FlowInfo = "Now flow restrict!";
const std::string ActionFailedInfo = "Failed to do user action";


enum Code
{/*{{{*/
    kExitOk                 = 1,
    kOk                     = 0,
    kInvalidParam           = 2,

    kConnError              = 11,
    kSocketError            = 12,
    kBindError              = 13,
    kListenError            = 14,
    kReadError              = 15,
    kOpenError              = 16,
    kWriteError             = 17,
    kAcceptError            = 18,
    kConnectError           = 19,

    kNotFound               = 51,
    kTimeOut                = 52,
    kIOError                = 53,
    kFull                   = 54,
    kPollError              = 55,
    kIOCtlError             = 56,
    kGetIfsError            = 57,
    kForkFailed             = 58,
    kStatFailed             = 59,
    kRenameFailed           = 60,
    kEpollCreateFailed      = 61,
    kEpollFailed            = 62,
    kEpollCtlFailed         = 63,

    kCPUError               = 91,

    kPipeFailed             = 131,
    kFcntlFailed            = 132,
    kSetsockoptFailed       = 133,

    kPthreadCreateFailed    = 151,

    kStrtollFailed          = 181,
    kNoDigits               = 182,
    kNotAllDigits           = 183,

    kFlowRestrict           = 201,

    kDlopenFailed           = 211,
    kDlsymFailed            = 212,

    kMkdirFailed            = 231,

    kInvalidPbMessage       = 1001,
    kInvalidMessageType     = 1002,
};/*}}}*/

class Status
{/*{{{*/
    public:
        explicit Status(Code c) : code_(c) {}

        Status(const Status &status)
        {
            code_ = status.code_;
        }

        Status& operator= (const Status &status)
        {
            code_ = status.code_;
            return *this;
        }

        ~Status() {}

    private:
        Code code_;
};/*}}}*/

}

#endif
