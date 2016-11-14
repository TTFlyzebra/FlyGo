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

int http_get(char *url,char *savefile);

int http_post(char *url,char *data,char *savefile);

/**
 * 发送HTTP数据包
 */
int send_shttpdata(SHttpData *sHttpData, char *savefile);

#ifdef __cplusplus
}
#endif
#endif /* CURLSEND_H_ */
