/*
 * curldata.c
 *
 *  Created on: 2016年11月12日
 *      Author: flyzebra
 */

#include "httpdata.h"
ListSHttpData* get_curl_http_data(char * curlStr, ListSHttpData* firstListSHttpData) {
	ListSHttpData* listSHttpData;
	ListSHttpData* newListSHttpData;
	char* startPos = curlStr;
	char* subStartPos;
	char buffer[4096];
	char subBuffer[4096];
	int i = 0;
	char *surl;

	while (startPos != NULL) {
		i++;
		startPos = cut_string(startPos, "", "", "\n", buffer);
		if (buffer[0] != '\0') {
			newListSHttpData = malloc(sizeof(ListSHttpData));

			if (firstListSHttpData == NULL) {
				firstListSHttpData = newListSHttpData;
			}

			if (listSHttpData == NULL) {
				listSHttpData = newListSHttpData;
			} else {
				listSHttpData->next = newListSHttpData;
				listSHttpData = listSHttpData->next;
			}

			//获取url
			subStartPos = buffer;
			subStartPos = cut_string(subStartPos, "curl", "'", "'", subBuffer);
			surl = listSHttpData->sHttpData.url;
			memcpy(surl, subBuffer, strlen(subBuffer));
//			printf("%d:%s\n",i,listSHttpData->sHttpData.url);
			//获取header
			subStartPos = buffer;
			surl = listSHttpData->sHttpData.header;
			memset(surl, 0, strlen(surl));
			while (subStartPos != NULL) {
				subStartPos = cut_string(subStartPos, "-H", "'", "'", subBuffer);
				strcat(surl, subBuffer);
				strcat(surl, "\n");
			}
//			printf("%d-----\n%s\n", i, listSHttpData->sHttpData.header);

			//获取data
			subStartPos = buffer;
			subStartPos = cut_string(subStartPos, "-data", "'", "'", subBuffer);
			surl = listSHttpData->sHttpData.postdata;
			memcpy(surl, subBuffer, strlen(subBuffer));
//			printf("%d:%s\n", i, listSHttpData->sHttpData.postdata);
		}
	}

	return firstListSHttpData;
}

void free_curl_http_data(ListSHttpData* listSHttpData) {
	ListSHttpData* freeListCurlData;
	freeListCurlData = listSHttpData;
	while (freeListCurlData != NULL) {
		listSHttpData = freeListCurlData->next;
		free(freeListCurlData);
		freeListCurlData = NULL;
		freeListCurlData = listSHttpData;
	}
}

