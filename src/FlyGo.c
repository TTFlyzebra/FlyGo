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
#include "kvcollectdata1.h"
#include "kvcollect.h"
#include "curl/curlsend.h"
#include "tool/tool_sleep.h"
#include "tool/tool_file.h"
#include "tool/tool_time.h"
#include "tool/tool_url.h"
#include "log/flylog.h"
#include "tool/tool_string.h"
#include "tool/tool_rand.h"
#include "tool/tool_utils.h"
#include "tool/cJSON.h"
#include "livemsg_getadlist.h"

int main(int argc, char** argv) {
	FLYLOG_DEBUG = 0xfff;
	flylog_set_debug(FLYLOG_DEBUG);
	printf("enter main func\r\n");
		char filedata_bf[512 * 1024] = { 0 };
	char *filedata = NULL;
	char replace_bf[256];
	char *crt_time;
	char *filename = "set.fly";
	ListSHttpData *firstListSCurlData = NULL;
	ListSHttpData *temListSCurlData = NULL;

	int loopsum = 10000;
	int looptime = 1;
	int i = 0;
	int j = 0;
	int newLen = 0;

	//定义要替换的字符串
//	char cmid1[33] = "57C4E6536D3EB53A6A5FB84B5A14CAA1";
//	char pid11[33] = "BA1BED5859995D2B8257E1E45DC9F572";
//	char pid12[33] = "BA1BED5859995D2B8257E1E45DC9F572";
//	char rid1[65] = "7545EA9A8B89DC37BCFC62E04A9EEDB1101EC85C";

	char cmid2[33];
	char pid21[33];
	char pid22[33];
	char rid2[65];
	char *tempPS;

	int sum;
	int sendcount;
	SKvData *skvdata;
	printf("start getSKvData file %s line:%d\r\n",__FILE__,__LINE__);
	//flylog("###[%s]#program start!\n", flytime());
	skvdata = getSKvData(&sum);
	if (skvdata != NULL) {
		printf("get skvdata \r\n");
	}
	else {
		printf("can not get skvdata exit\r\n");
		return -1;

	}

	for (i = 0; i < 100000; i++) {
		sendcount = 0;
		for (j = 0; j < 6; j++) {
			if (skvdata[j].kvtime != 0) {
				http_get(getkvcollecturl(skvdata[j].kvurl, 0, 0, 0), "ret1.txt");
				fly_sleep(skvdata[j].kvtime);				
				http_get(getkvcollecturl(skvdata[j].kvurl, sendcount, skvdata[j].kvtime,sum), "ret2.txt");				
				sendcount++;
			}
//			flylog("====time = %d\n", skvdata[j].kvtime);
//			flylog("====url = %s\n", skvdata[j].kvurl);
		}
		flylog("[%d/%d][pid=%d][%s]\n", i + 1, loopsum, getpid(),flytime());
	}
	flylog("###[%s]#program exit!\n", flytime());
	return EXIT_SUCCESS;

//	flylog("###[%s]#program start!\n", flytime());
//	if (argc > 4) {
//		FLYLOG_DEBUG = atoi(argv[4]);
//		flylog_set_debug(FLYLOG_DEBUG);
//	}
//
//	if (argc > 3) {
//		filename = argv[3];
//		flylog("filename=%s;\n", argv[3]);
//	}
//
//	if (argc > 2) {
//		looptime = atoi(argv[2]);
//		flylog("looptime=%s;\n", argv[2]);
//	}
//	if (argc > 1) {
//		loopsum = atoi(argv[1]);
//		flylog("loopsum=%s;\n", argv[1]);
//	}
//
//	if (1 > loopsum) {
//		loopsum = 100000;
//	}
//
//	if (1 > looptime) {
//		looptime = 1;
//	}
//
//	filedata = read_all_file(filename, filedata_bf);
//
//	if (filedata != NULL) {
//		flylog("###[%s]read setting file succeed,start get httpdata......\n",
//				flytime());
//		firstListSCurlData = get_curl_http_data(filedata, firstListSCurlData);
//		flylog("###[%s]get httpdate succeed, start send http......\n",	flytime());
//		srand(clock());
//		for (i = 0; i < loopsum; i++) {
//			//替换字符串,在每次任务开始生成随机字符串
//			tempPS = getRandomString(32);
//			memcpy(cmid2, tempPS, 32);
//			cmid2[32] = '\0';
//			flylog_1("replace cmid2=%s\n", cmid2);
//
//			tempPS = getRandomString(32);
//			memcpy(pid21, tempPS, 32);
//			pid21[32] = '\0';
//			flylog_1("replace pid21=%s\n", pid21);
//
//			memcpy(pid22, pid21, 32);
//			strlwr(pid22);
//			flylog_1("replace pid22=%s\n", pid22);
//
//			tempPS = getRandomString(40);
//			memcpy(rid2, tempPS, 40);
//			rid2[64] = '\0';
//			flylog_1("replace rid2=%s\n", rid2);
//
//			temListSCurlData = firstListSCurlData;
//			while (temListSCurlData != NULL) { //
//
//				//替换cimd
////				replace_string_start(temListSCurlData->sHttpData.url, cmid1,cmid2);
////				replace_string_start(temListSCurlData->sHttpData.url, pid11,pid21);
////				replace_string_start(temListSCurlData->sHttpData.url, pid12,pid22);
////				replace_string_start(temListSCurlData->sHttpData.url, rid1,rid2);
////
////				replace_string_start(temListSCurlData->sHttpData.postdata,cmid1, cmid2);
////				replace_string_start(temListSCurlData->sHttpData.postdata, pid11, pid21);
////				replace_string_start(temListSCurlData->sHttpData.postdata, pid12, pid22);
////				replace_string_start(temListSCurlData->sHttpData.postdata, rid1, rid2);
////				67FC1C4F594DD29C69839030931B16C8CCDB7121
//				memset(replace_bf, 0, strlen(replace_bf));
//				//替换时间
//				crt_time = flytime();
//				if (temListSCurlData->sHttpData.creatTime[0] != '\0') {
//					url_encode_char(crt_time, replace_bf, strlen(crt_time),	&newLen, ' ');
//					replace_string_start(temListSCurlData->sHttpData.url,"2016-12-", replace_bf);
//					replace_string_time(temListSCurlData->sHttpData.postdata,"2016%2D12%2D");
//					flylog_4("\n%s\n", temListSCurlData->sHttpData.creatTime);
//					flylog_4("%s\n", temListSCurlData->sHttpData.url);
//					flylog_4("%s\n", temListSCurlData->sHttpData.postdata);
//				} else {
//					flylog_4("\nNo time string in this httpata!\n");
//				}
//
//				send_shttpdata(&(temListSCurlData->sHttpData), "temp.curl");
//				fly_sleep(temListSCurlData->sHttpData.sleepTime * 1000);
//				temListSCurlData = temListSCurlData->next;
//
//			}
//			fly_sleep(looptime * 1000);
//#ifdef WIN32
//			flylog("[%d/%d][%s]\n", i + 1,loopsum,flytime());
//#else
//			flylog("[%d/%d][pid=%d][%s]\n", i + 1, loopsum, getpid(),flytime());
//#endif
////			memcpy(cmid1, cmid2, strlen(cmid2));
////			memcpy(pid11, pid21, strlen(pid21));
////			memcpy(pid12, pid22, strlen(pid22));
////			memcpy(rid1, rid2, strlen(rid2));
////			flylog_1("replace cmid1=%s\n", cmid1);
////			flylog_1("replace pid11=%s\n", pid11);
////			flylog_1("replace pid12=%s\n", pid12);
////			flylog_1("replace rid1=%s\n", rid1);
//		}
//		printf("###[%s]send http finished!\n", flytime());
//		free_curl_http_data(firstListSCurlData);
//		firstListSCurlData = NULL;
//	} else {
//		flylog("###[%s]read setting file failed, file path = (%s) !\n",
//				flytime(), filename);
//	}
//
//	flylog("###[%s]#program exit!\n", flytime());
//
//	return EXIT_SUCCESS;
}
