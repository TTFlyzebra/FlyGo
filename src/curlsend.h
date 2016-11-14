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
#include "httpdata.h"
#include "tool/tool_string.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * 发送HTTP GET请求
 */
int http_get(char *url,char *savefile);

/**
 * 发送HTT POST请求
 */
int http_post(char *url,char *data,char *savefile);

/**
 * 发送HTTP请求
 * */
int send_shttpdata(SHttpData *sHttpData, char *savefile);

#ifdef __cplusplus
}
#endif
#endif /* CURLSEND_H_ */
