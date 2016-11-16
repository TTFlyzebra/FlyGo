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
#include "log/flylog.h"
#include "tool/tool_string.h"
#include "tool/tool_rand.h"
int main(int argc, char** argv) {
	char replace_bf[256];
	char *crt_time;
	char filedata_bf[1024 * 512] = { 0 };
	char *filedata = NULL;

	char *filename = "set.sh";
	ListSHttpData *firstListSCurlData = NULL;
	ListSHttpData *temListSCurlData = NULL;

	int loopsum = 10000;
	int looptime = 1;
	int i = 0;
	int newLen = 0;

	//定义要替换的字符串
	char cmid[33];
	char pid[33];
	char rid[65];

	char *tempPS;

//	flylog("file=%s,func=%s,line=%d\n",__FILE__,__FUNCTION__,__LINE__);
	printf("###%s#program start!\n", flytime());
	if (argc > 4) {
		FLYLOG_DEBUG = atoi(argv[4]);
		flylog_set_debug(FLYLOG_DEBUG);
	}

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
		printf("###%sread setting file succeed,start get httpdata......\n",
				flytime());
		firstListSCurlData = get_curl_http_data(filedata, firstListSCurlData);
		printf("###%sget httpdate succeed, start send http......\n", flytime());
		for (i = 0; i < loopsum; i++) {

			//替换字符串,在每次任务开始生成随机字符串
			tempPS = getRandomString(32);
			memcpy(cmid, tempPS, 32);
			cmid[32] = '\0';

			tempPS = getRandomString(32);
			memcpy(pid, tempPS, 32);
			pid[32] = '\0';

			tempPS = getRandomString(40);
			memcpy(rid, tempPS, 40);
			rid[64] = '\0';

			temListSCurlData = firstListSCurlData;
			while (temListSCurlData != NULL) { //

				//替换cimd
				replace_string_end(temListSCurlData->sHttpData.url, "677FCD000D3C0CEF61272F8885A6DCA1",cmid);
				replace_string_end(temListSCurlData->sHttpData.url,"F0F8997469C41EDBB4663B2DEAD619C9",pid);
				replace_string_end(temListSCurlData->sHttpData.url,"f0f8997469c41edbb4663b2dead619c9",pid);
				replace_string_end(temListSCurlData->sHttpData.url,"67FC1C4F594DD29C69839030931B16C8CCDB7121",rid);

				replace_string_end(temListSCurlData->sHttpData.postdata, "677FCD000D3C0CEF61272F8885A6DCA1",cmid);
				replace_string_end(temListSCurlData->sHttpData.postdata,"F0F8997469C41EDBB4663B2DEAD619C9",pid);
				replace_string_end(temListSCurlData->sHttpData.postdata,"f0f8997469c41edbb4663b2dead619c9",pid);
				replace_string_end(temListSCurlData->sHttpData.postdata, "67FC1C4F594DD29C69839030931B16C8CCDB7121",rid);
//				67FC1C4F594DD29C69839030931B16C8CCDB7121
				flylog_1("cmid=%s\n", cmid);

				memset(replace_bf, 0, strlen(replace_bf));
				//替换时间
				crt_time = flytime();
				if (temListSCurlData->sHttpData.creatTime[0] != '\0') {
					url_encode_char(crt_time, replace_bf, strlen(crt_time),
							&newLen, ' ');
					replace_string_start(temListSCurlData->sHttpData.url,
							"2016-11-", replace_bf);
					replace_string_time(temListSCurlData->sHttpData.postdata,
							"2016%2D11%2D");

					flylog_4("\n%s\n", temListSCurlData->sHttpData.creatTime);
					flylog_4("%s\n", temListSCurlData->sHttpData.url);
					flylog_4("%s\n", temListSCurlData->sHttpData.postdata);
				} else {
					flylog_4("\nNo time string in this httpata!\n");
				}

				send_shttpdata(&(temListSCurlData->sHttpData), NULL);
				fly_sleep(temListSCurlData->sHttpData.sleepTime * 1000);
				temListSCurlData = temListSCurlData->next;

			}
#ifdef WIN32
			printf("[%d/%d][%s]\n", i + 1,loopsum,flytime());
#else
			printf("[%d/%d][pid=%d][%s]\n", i + 1, loopsum, getpid(),
					flytime());
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
