/*
 * kvcollect.c
 *
 *  Created on: 2016年12月14日
 *      Author: flyzebra
 */
#include "kvcollect.h"
#include "tool/tool_time.h"
#include "tool/tool_url.h"
#include "log/flylog.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char kvbuffer[4096];
char *getkvcollecturl(char *url, int count, int time, int sumtime) {
	char temp[1024];
	char replace_bf[256];
	char *crt_time;
	int newLen = 0;
//	char *find;
//	char *str;
//	str = kvbuffer;
//	find = strstr(str,"&");
//	while(find!=NULL){
//		memset(temp,0,sizeof(temp));
//		memcpy(temp,str,find-str);
//		flylog("strcat(kvbuffer,\"%s\");\n",temp);
//		str = find+1;
//		find = strstr(str,"&");
//	}
//	flylog("strcat(kvbuffer,\"%s\"\n",find);
	memset(kvbuffer, 0, sizeof(kvbuffer));
	strcat(kvbuffer, "http://btrace.video.qq.com/kvcollect?sIp=");
	strcat(kvbuffer, "&iQQ=");
	strcat(kvbuffer, "&sBiz=");
	strcat(kvbuffer, "&sOp=");
	strcat(kvbuffer, "&iSta=0");
	strcat(kvbuffer, "&iTy=2481");
	strcat(kvbuffer, "&iFlow=0");
	strcat(kvbuffer, "&sUrl=");
	strcat(kvbuffer, "&sRef=");
	strcat(kvbuffer, "&sPageId=");
	strcat(kvbuffer, "&sPos=");
	strcat(kvbuffer, "&step=2001");
	strcat(kvbuffer, "&val=web");
	strcat(kvbuffer, "&val1=");
	strcat(kvbuffer, "&val2=");
	strcat(kvbuffer, "&val3=");
	strcat(kvbuffer, "&val4=");
	strcat(kvbuffer, "&val5=");
	strcat(kvbuffer, "&apid=1.4.6");
	strcat(kvbuffer, "&pid=1.4.6");
	strcat(kvbuffer, "&vid=8kO1XKH8Qfm");
	strcat(kvbuffer, "&platform=3");
	strcat(kvbuffer, "&pversion=TencentPlayerV3.2.29.391");
	strcat(kvbuffer, "&version=1.4.6");
	strcat(kvbuffer, "&bi=");
	sprintf(temp, "%d", time);
	strcat(kvbuffer, temp);
	strcat(kvbuffer, "&bt=");
	sprintf(temp, "%d", sumtime);
	strcat(kvbuffer, temp);
	strcat(kvbuffer, "&idx=");
	sprintf(temp, "%d", count);
	strcat(kvbuffer, temp);
	strcat(kvbuffer, "&appid=0");
	strcat(kvbuffer, "&ua=");
	strcat(kvbuffer, "&adtype=0");
	//https://v.qq.com/x/cover/ilcxi3gxzj12ksm.html?ptag=bl.zy.movie_ilcxi3gxzj12ksm.20161209
	strcat(kvbuffer, "&vurl=");
	strcat(kvbuffer, url);
	strcat(kvbuffer, "&reporttime=");
	crt_time = flytime();
	url_encode_char(crt_time, replace_bf, strlen(crt_time), &newLen,' ');
	strcat(kvbuffer, replace_bf);
	strcat(kvbuffer, "&bdua=0");
	strcat(kvbuffer, "&admtype=0");
	strcat(kvbuffer, "&adid=4001");
	strcat(kvbuffer, "&guid=");
	strcat(kvbuffer, "&ispip=0");
	flylog_4("%s\n", kvbuffer);
	return kvbuffer;
}

