// Copyright (c) 2015 The CCUtil Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HTTP_HTTP_CLIENT_H_
#define HTTP_HTTP_CLIENT_H_

#include <string>

#include "http/http_proto.h"
#include "sock/tcp_client.h"

namespace base
{

class HttpClient
{
    public:
        HttpClient();
        ~HttpClient();

        Code Init();

        Code Perform(const std::string &url, const std::string post_params, std::string *result);

    private:
        TcpClient tcp_client_;
        HttpProto http_proto_;

};
    
}

#endif
