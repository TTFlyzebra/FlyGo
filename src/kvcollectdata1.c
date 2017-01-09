/*
 * kvcollectdata1.c
 *
 *  Created on: 2016年12月15日
 *      Author: flyzebra
 */
#include "kvcollectdata1.h"
#include <stdio.h>
#include "json/cJSON.h"
#include "mycurl/curlutils.h"
#include "tool/tool_file.h"
#include "livemsg_getadlist.h"
static SKvData skvdata[6];
SKvData* getSKvData(int *sumtime) {
	char filedata_bf[512 * 1024] = { 0 };
	char *filedata = NULL;
	char *temp;
	int i;
	char *reporturl;
	flylog_4("start getSKvData!\n");
	send_curl_http_get(getadurl(), "adurl.txt");
//	memset(filedata_bf, 0, sizeof(filedata_bf));	
	filedata = read_all_file((char *)"adurl.txt",(char*)filedata_bf);
	if (NULL == filedata) {
		flylog_4("read_all_file retun NULL\r\n");
		return NULL;
	}
	filedata = filedata + strlen("lviewcb(");
	temp = filedata + strlen(filedata) - 1;
	*temp = '\0';
	//		flylog_4("%s\n",filedata);
	flylog_4("start parse json!\n");
	cJSON *pJson = cJSON_Parse(filedata);
	if (NULL == pJson) {
		flylog_4("parse faild!\n");
		return NULL;
	} else {
		cJSON * pSub = cJSON_GetObjectItem(pJson, "adList");
		cJSON *taskArry = cJSON_GetObjectItem(pSub, "item"); //取数组
		//		int arrySize = cJSON_GetArraySize(taskArry); //数组大小
		cJSON *tasklist = taskArry->child; //子对象
		*sumtime =  0;
		for(i=0;i<6;i++) {
			skvdata[i].kvtime = atoi(cJSON_GetObjectItem(tasklist, "duration")->valuestring);
			*sumtime=skvdata[i].kvtime +*sumtime;
			flylog_4("time = %d\n", skvdata[i].kvtime);
			cJSON *subtaskArry = cJSON_GetObjectItem(tasklist, "image"); //取数组
			//			int subarrySize = cJSON_GetArraySize(subtaskArry); //数组大小
			cJSON *subtasklist = subtaskArry->child; //子对象
			skvdata[i].kvurl[0] = '\0';
			if (subtasklist != NULL) {
				reporturl = cJSON_GetObjectItem(subtasklist, "url")->valuestring;
				strcat(skvdata[i].kvurl,reporturl);
				flylog_4("url = %s\n", reporturl);
			}
			tasklist = tasklist->next;
			//				getkvcollecturl();
		}
	}
	return skvdata;
}
