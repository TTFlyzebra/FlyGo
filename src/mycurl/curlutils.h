/*
 * curlutil.h
 *
 *  Created on: 2016年11月3日
 *      Author: flyzebra
 */

#ifndef CURLSEND_H_
#define CURLSEND_H_

#include <stdio.h>
#include <curl/curl.h>
#include "../tool/tool_string.h"
#include "../httpdata.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 发送HTTP GET请求
 */
int send_curl_http_get(char *url,char *savefile);

/**
 * 发送HTTP POST请求
 */
int send_curl_http_post(char *url,char *data,char *savefile);

/**
 * 发送CURL命令,如果参数中有cookie会读取cookie中的内容替换掉命令字符串中的内容
 */
int send_curl_cmd(char *curlcmd,char *savefile);

/**
 * 发送HTTP请求
 * */
int send_shttpdata(SHttpData *sHttpData, char *savefile);

#ifdef __cplusplus
}
#endif
#endif /* CURLSEND_H_ */
