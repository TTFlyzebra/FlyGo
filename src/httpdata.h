/*
 * curldata.h
 *
 *  Created on: 2016年11月12日
 *      Author: flyzebra
 */

#ifndef DATA_HTTPDATA_H_
#define DATA_HTTPDATA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tool/tool_string.h"
#include "tool/tool_url.h"

typedef struct SHTTPDATA{
	char url[2048];
	char header[2048];//参数之间以\r\n符号分隔
	char postdata[4096];
	char creatTime[256];
	int sleepTime;
}SHttpData,*pHttpData;

typedef struct LINKSHTTPDATA{
	SHttpData sHttpData;
	struct LINKSHTTPDATA *next;
}ListSHttpData,*pListSHttpData;

#ifdef __cplusplus
extern "C" {
#endif

ListSHttpData* get_curl_http_data(char * curlStr,ListSHttpData* listSHttpData);
void free_curl_http_data(ListSHttpData* listSHttpData);

#ifdef __cplusplus
}
#endif
#endif /* DATA_HTTPDATA_H_ */
