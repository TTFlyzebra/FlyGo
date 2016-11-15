/*
 * curldata.c
 *
 *  Created on: 2016年11月12日
 *      Author: flyzebra
 */

#include "httpdata.h"
ListSHttpData* get_curl_http_data(char * curlStr,
		ListSHttpData* firstListSHttpData) {
	ListSHttpData* listSHttpData = NULL;
	ListSHttpData* newListSHttpData = NULL;
	char* startPos = curlStr;
	char* subStartPos = NULL;
	char oneCurlBuffer[4096] = { 0 };
	char subBuffer[4096] = { 0 };
	char *surl = NULL;

	printf("###################start get_curl_http_data###################\n");

	while (startPos != NULL) {
		if (strlen(startPos) == 0) {
			return firstListSHttpData;
		}
		startPos = cut_string_with_start_mark(startPos, "curl", oneCurlBuffer);

//		printf("--------------------------start-------------------------------\n%s",buffer);
//		printf("---------------------------end----------------------------\n");
//		continue;

		if (oneCurlBuffer[0] == '\0') {
			return firstListSHttpData;
		}
		newListSHttpData = (ListSHttpData*) malloc(sizeof(ListSHttpData));
		memset(newListSHttpData, 0, sizeof(ListSHttpData));

		if (firstListSHttpData == NULL) {
			firstListSHttpData = newListSHttpData;
		}

		if (NULL == listSHttpData) {
			listSHttpData = newListSHttpData;
		} else {
			listSHttpData->next = newListSHttpData;
			listSHttpData = listSHttpData->next;
		}

		printf("----------------------HTTPDATA START----------------------\n");

		//获取url
		subStartPos = oneCurlBuffer;
		subStartPos = cut_string(subStartPos, "", "'", "'", subBuffer);
		if (subBuffer[0] != '\0') {
			surl = listSHttpData->sHttpData.url;
			memcpy(surl, subBuffer, strlen(subBuffer));
			printf("%s\n", listSHttpData->sHttpData.url);
		}

		//获取header
		subStartPos = oneCurlBuffer;
		surl = listSHttpData->sHttpData.header;
		memset(surl, 0, strlen(surl));
		while (subStartPos != NULL) {
			subStartPos = cut_string(subStartPos, "-H", "'", "'", subBuffer);
			if (subBuffer[0] != '\0') {
				strcat(surl, subBuffer);
				strcat(surl, "\n");
			}
		}

		printf("\n%s", listSHttpData->sHttpData.header);

		//获取data
		subStartPos = oneCurlBuffer;
		subStartPos = cut_string(subStartPos, "-data", "'", "'", subBuffer);
		if (subBuffer[0] != '\0') {
			surl = listSHttpData->sHttpData.postdata;
			memcpy(surl, subBuffer, strlen(subBuffer));
			printf("\n%s\n", listSHttpData->sHttpData.postdata);
		}

		//获取延时时间,SH文件中的sleep
		subStartPos = oneCurlBuffer;
		subStartPos = cut_string(subStartPos, "sleep", "", "\n", subBuffer);
		if (subBuffer[0] != '\0') {
			listSHttpData->sHttpData.sleepTime = atoi(subBuffer);
		} else {
			listSHttpData->sHttpData.sleepTime = 0;
		}
		printf("\nsleep=%d\n", listSHttpData->sHttpData.sleepTime);

		//获取时间，如果有的话
		subStartPos = oneCurlBuffer;
		subStartPos = cut_string(subStartPos, "time=2016", "", "&", subBuffer);
		if (subBuffer[0] != '\0') {
			surl = listSHttpData->sHttpData.creatTime;
			memcpy(surl, subBuffer, strlen(subBuffer));
			printf("\n%s\n", listSHttpData->sHttpData.creatTime);
		}

		printf("----------------------HTTPDATA END----------------------\n");
	}
	printf("###################finish get_curl_http_data###################\n");
	return firstListSHttpData;
}

void free_curl_http_data(ListSHttpData* listSHttpData) {
	ListSHttpData* freeListCurlData = NULL;
	freeListCurlData = listSHttpData;
	while (freeListCurlData != NULL) {
		listSHttpData = freeListCurlData->next;
		free(freeListCurlData);
		freeListCurlData = NULL;
		freeListCurlData = listSHttpData;
	}
}

