/*
 ============================================================================
 Name        : FlyGo.c
 Author      : FlyZebra
 Version     :
 Copyright   : FlyZebra
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "httpdata.h"
#include "tool/tool_file.h"

int main(int argc, char** argv) {
	char filedata_bf[1024 * 1024];
	char *filedata = NULL;
	char *filename = "set.sh";
	ListSHttpData *firstListSCurlData = NULL;
	ListSHttpData *temListSCurlData = NULL;
	int loopsum = 0;
	int looptime = 0;
	int i;

	if (argc > 2) {
		looptime = atoi(argv[4]);
		printf("looptime=%s;\n", argv[4]);
	}
	if (argc > 1) {
		loopsum = atoi(argv[3]);
		printf("loopsum=%s;\n", argv[3]);
	}

	if (1 > loopsum) {
		loopsum = 100000;
	}

	if (1 > looptime) {
		looptime = 1;
	}

	filedata = read_all_file(filename, filedata_bf);
	if (filedata != NULL) {
		printf("read setting file finish!\n");
		firstListSCurlData = get_curl_http_data(filedata, firstListSCurlData);
		for (i = 0; i < loopsum; i++) {
			temListSCurlData = firstListSCurlData;
			while (temListSCurlData != NULL) {
//				if (*(temListSCurlData->sHttpData.url) != '\0')
//					printf("%s\n", temListSCurlData->sHttpData.url);
//				if (*(temListSCurlData->sHttpData.header) != '\0')
//					printf("%s", temListSCurlData->sHttpData.header);
//				if (temListSCurlData->sHttpData.postdata[0] != '\0')
//					printf("%s\n\n", temListSCurlData->sHttpData.postdata);
				send_shttpdata(&(temListSCurlData->sHttpData), NULL);
				temListSCurlData = temListSCurlData->next;
			}
#ifdef WIN32
			printf(" -- sleep %d --loop %d \n", looptime, i + 1);
#else
			printf(" -- sleep %d --loop %d pid=%d \n", looptime, i + 1, getpid());
#endif
			fly_sleep(looptime * 1000);
		}
		free_curl_http_data(firstListSCurlData);
		firstListSCurlData = NULL;
	} else {
		printf("read curl_data from file %s fail!\n", filename);
	}

	return EXIT_SUCCESS;
}
