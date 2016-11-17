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
#include "tool/tool_utils.h"

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
	char cmid1[33] = "677FCD000D3C0CEF61272F8885A6DCA1";
	char pid11[33] = "5F578D0C6F30787560B653E53035C8A9";
	char pid12[33] = "5f578d0c6f30787560b653e53035c8a9";
	char rid1[65] = "CC311E3F3BBFE6FF1589334602D31519B6DE5019";
	char cmid2[33];
	char pid21[33];
	char pid22[33];
	char rid2[65];

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
		srand(clock());
		for (i = 0; i < loopsum; i++) {

			//替换字符串,在每次任务开始生成随机字符串
			tempPS = getRandomString(32);
			memcpy(cmid2, tempPS, 32);
			cmid2[32] = '\0';
			flylog_1("replace cmid2=%s\n", cmid2);

			tempPS = getRandomString(32);
			memcpy(pid21, tempPS, 32);
			pid21[32] = '\0';
			flylog_1("replace pid21=%s\n", pid21);

			memcpy(pid22,pid21,32);
			strlwr(pid22);
			flylog_1("replace pid22=%s\n", pid22);

			tempPS = getRandomString(40);
			memcpy(rid2, tempPS, 40);
			rid2[64] = '\0';
			flylog_1("replace rid2=%s\n", rid2);

			temListSCurlData = firstListSCurlData;
			while (temListSCurlData != NULL) { //

				//替换cimd
				replace_string_start(temListSCurlData->sHttpData.url, cmid1,cmid2);
				replace_string_start(temListSCurlData->sHttpData.url, pid11,pid21);
				replace_string_start(temListSCurlData->sHttpData.url, pid12,pid22);
				replace_string_start(temListSCurlData->sHttpData.url, rid1,rid2);

				replace_string_start(temListSCurlData->sHttpData.postdata,cmid1, cmid2);
				replace_string_start(temListSCurlData->sHttpData.postdata, pid11, pid21);
				replace_string_start(temListSCurlData->sHttpData.postdata, pid12, pid22);
				replace_string_start(temListSCurlData->sHttpData.postdata, rid1, rid2);
//				67FC1C4F594DD29C69839030931B16C8CCDB7121

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
			printf("[%d/%d][pid=%d][%s]\n", i + 1, loopsum, getpid(),flytime());
#endif
			memcpy(cmid1,cmid2,strlen(cmid2));
			memcpy(pid11,pid21,strlen(pid21));
			memcpy(pid12,pid22,strlen(pid22));
			memcpy(rid1,rid2,strlen(rid2));
			flylog_1("replace cmid1=%s\n", cmid1);
			flylog_1("replace pid11=%s\n", pid11);
			flylog_1("replace pid12=%s\n", pid12);
			flylog_1("replace rid1=%s\n", rid1);
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
