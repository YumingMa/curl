#ifndef HEADER_CURL_VAUTH_H
#define HEADER_CURL_VAUTH_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 2014 - 2015, Steve Holme, <steve_holme@hotmail.com>.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at http://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/

#include <curl/curl.h>

struct SessionHandle;

/* This is used to build a SPN string */
#if !defined(USE_WINDOWS_SSPI)
char *Curl_sasl_build_spn(const char *service, const char *instance);
#else
TCHAR *Curl_sasl_build_spn(const char *service, const char *instance);
#endif

#if defined(HAVE_GSSAPI)
char *Curl_sasl_build_gssapi_spn(const char *service, const char *instance);
#endif

/* This is used to generate a base64 encoded PLAIN cleartext message */
CURLcode sasl_create_plain_message(struct SessionHandle *data,
                                   const char *userp,
                                   const char *passwdp,
                                   char **outptr, size_t *outlen);

/* This is used to generate a base64 encoded LOGIN cleartext message */
CURLcode sasl_create_login_message(struct SessionHandle *data,
                                   const char *valuep, char **outptr,
                                   size_t *outlen);

/* This is used to generate a base64 encoded EXTERNAL cleartext message */
CURLcode sasl_create_external_message(struct SessionHandle *data,
                                      const char *user, char **outptr,
                                      size_t *outlen);

#endif /* HEADER_CURL_VAUTH_H */