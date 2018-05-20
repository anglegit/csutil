// Copyright (c) 2015 The CSUTIL Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HTTP_HTTP_PROTO_H_
#define HTTP_HTTP_PROTO_H_

#include <string>

#include <stdint.h>

#include "base/status.h"

namespace base
{

const int kHttpRspHeaderMinLen = 13; // EX: HTTP/1.1 200 
const int kHttpReqHeaderMinLen = 14; // EX: GET / HTTP/1.1
const int kHttpReqHeaderMaxLen = 2083; // EX: max size of request line 
const std::string kCRLF = "\r\n";

const std::string kTransferEncoding = "Transfer-Encoding";
const std::string kChunked = "Chunked";
const std::string kContentLength = "Content-Length";
const std::string kLocation = "Location";
const std::string kHost = "Host";

enum HttpStatus
{
    kHttpStatusOk                   = 200,
    kHttpStatusMoved                = 301,
    kHttpStatusRedirect             = 302,
    kHttpStatusRedirect_method      = 303,
    kHttpStatusNotModified          = 304,
    kHttpStatusRedirectKeepVerb     = 307,
    kHttpStatusForbidden            = 403,
    kHttpStatusNotFound             = 404,
    kHttpStatusInternalServerError  = 500,
    kHttpStatusServiceUnavail       = 503,
};

enum HttpType
{
    GET,
    POST,
    PUT,
    DELETE,
};


Code HttpReqProtoFunc(const char *src_data, int src_data_len, int *real_len);
Code HttpRespProtoFunc(const char *src_data, int src_data_len, int *real_len);


class HttpProto
{
    public:
        HttpProto();
        ~HttpProto();

    public:
        Code SetHttpType(enum HttpType http_type);

        Code ParseUrl(const std::string &url);

        Code GetHeader(std::string *header);
        Code PostHeader(std::string *header);

        Code EncodeToReq(const std::string &url, const std::string &post_params, std::string *post_stream_data, std::string *host, uint16_t *port);
        Code EncodeToReq(const std::string &url, std::string *get_stream_data, std::string *host, uint16_t *port);
        Code DecodeFromReq(const std::string &stream_data);


        Code DecodeFromResponse(const std::string &stream_data, std::string *user_data);
        Code GetRespStatus(const std::string &stream_data, uint16_t *ret_code, std::string *ret_msg);

        Code Clear();

    public:
        static Code GetMessageHeader(const std::string &upper_header, const std::string &msg_key, std::string *msg_value);
        static Code GetChunkedMsg(const std::string &body, uint32_t *real_body_len, std::string *chunked_msg);
        static Code CheckReqHeader(const std::string &stream_data);
        static Code CheckRespHeader(const std::string &stream_data);

    public:
        const HttpType& GetHttpType();
        const std::string& GetProtoVersion();
        const std::string& GetHost();
        const uint16_t GetPort();
        const std::string& GetRelativeUrl();
        const std::string& GetGetParams();
        const std::string& GetPostParams();

    private:
        HttpType http_type_;

        std::string proto_;         // http://
        std::string proto_version_; // HTTP/1.1
        std::string host_;
        uint16_t port_;
        std::string relative_url_;
        std::string get_params_;
        std::string post_params_;
        std::string user_agent_;
        std::string content_type_;
        std::string redirect_url_;
};

}

#endif
