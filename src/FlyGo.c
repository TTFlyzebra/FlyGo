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
#include "curlsend.h"
#include "tool/tool_sleep.h"
#include "tool/tool_file.h"
#include "tool/tool_time.h"
#include "tool/tool_url.h"

int main(int argc, char** argv) {
	char replace_bf[256];
	char *crt_time;
	char filedata_bf[1024 * 512] = { 0 };
	char *filedata = NULL;

	char *filename = "set.sh";
	ListSHttpData *firstListSCurlData = NULL;
	ListSHttpData *temListSCurlData = NULL;

	int loopsum = 1;
	int looptime = 1;
	int i = 0;
	int newLen = 0;

	printf("###%s#program start!\n", flytime());

	if (argc > 3) {
		filename = argv[3];
		printf("filename=%s;\n", argv[3]);
	}

	if (argc > 2) {
		looptime = atoi(argv[2]);
		printf("looptime=%s;\n", argv[2]);
	}
	if (argc > 1) {
		loopsum = atoi(argv[1]);
		printf("loopsum=%s;\n", argv[1]);
	}

	if (1 > loopsum) {
		loopsum = 100000;
	}

	if (1 > looptime) {
		looptime = 1;
	}

	filedata = read_all_file(filename, filedata_bf);

	if (filedata != NULL) {
		printf("###%sread setting file succeed,start get httpdata......\n",	flytime());
		firstListSCurlData = get_curl_http_data(filedata, firstListSCurlData);
		printf("###%sget httpdate succeed, start send http......\n", flytime());
		for (i = 0; i < loopsum; i++) {
			temListSCurlData = firstListSCurlData;
			while (temListSCurlData != NULL) {
//
				memset(replace_bf, 0, strlen(replace_bf));
				crt_time = flytime();
				url_encode_char(crt_time, replace_bf, strlen(crt_time), &newLen,' ');
				replace_string(temListSCurlData->sHttpData.url,"2016-11-", replace_bf);

				replace_string_time(temListSCurlData->sHttpData.postdata,"2016%2D11%2D");

//				printf("%s\n", temListSCurlData->sHttpData.url);
//				printf("%s\n", temListSCurlData->sHttpData.postdata);

				send_shttpdata(&(temListSCurlData->sHttpData), NULL);
				fly_sleep(temListSCurlData->sHttpData.sleepTime * 1000);
				temListSCurlData = temListSCurlData->next;

			}
#ifdef WIN32
			printf("-- running loop %d/%d --\n", i + 1,loopsum);
#else
			printf("-- running loop %d/%d pid=%d --\n", i + 1, loopsum,
					getpid());
#endif
		}
		printf("###send http finished!\n");
		free_curl_http_data(firstListSCurlData);
		firstListSCurlData = NULL;
	} else {
		printf("###read setting file failed, file path = (%s) !\n", filename);
	}

	printf("###%s#program exit!\n", flytime());

	return EXIT_SUCCESS;
}
