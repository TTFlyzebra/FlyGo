/*
 * tool_string.c
 *
 *  Created on: 2016年11月13日
 *      Author: flyzebra
 */
#include "tool_string.h"
#include "../log/flylog.h"

char* cut_string_with_start_mark(char* findStr, char* startMark, char *buffer) {
	char *firstPos = findStr;
	char *endPos = NULL;
	buffer[0] = '\0';
	firstPos = strstr(findStr, startMark);
	if (firstPos == NULL) {
		return NULL;
	}
	firstPos = firstPos + strlen(startMark);
	endPos = strstr(firstPos, startMark);
	if (endPos == NULL) {
		memcpy(buffer, findStr, strlen(findStr));
		buffer[strlen(findStr)] = '\0';
	} else {
		memcpy(buffer, findStr, endPos - findStr);
		buffer[endPos - findStr] = '\0';
	}
	firstPos = findStr + strlen(buffer);
	return firstPos;
}

char* cut_string(char* findStr, char* markStr, char *startStr, char *endStr,
		char *buffer) {
	char *startPos = findStr;
	char *endPos = findStr;
	char *bufEndpos = buffer;
	buffer[0] = '\0';
	startPos = strstr(startPos, markStr);
	if (NULL != startPos) {
//		startPos += strlen(markStr);
		startPos = strstr(startPos, startStr);
		if (NULL != startPos) {
			startPos += strlen(startStr);
			endPos = strstr(startPos, endStr);
			if (NULL != endPos) {
				memcpy(buffer, startPos, endPos - startPos);
				bufEndpos = buffer + (endPos - startPos);
				*bufEndpos = '\0';
				startPos = endPos + strlen(endStr);
				return startPos;
			} else {
				return NULL;
			}
		} else {
			return NULL;
		}
	} else {
		return NULL;
	}
}

int replace_string_time(char* findStr, char* markStr) {
	char *startPos = NULL;
	int ret = 0;
	char *crt_time;
	char buffer[128] = { 0 };
	int newLen = 0;

	startPos = strstr(findStr, markStr);
	if (startPos != NULL) {
		ret = 1;
		crt_time = flytime();
		memset(buffer, 0, strlen(buffer));
		url_encode(crt_time, buffer, strlen(crt_time), &newLen);
		memcpy(startPos, buffer, strlen(buffer));
		startPos = startPos + strlen(buffer);
		startPos = strstr(startPos, markStr);
	}else{
		return 0;
	}
	while (startPos != NULL) {
		fly_sleep(100);
		crt_time = flytime();
		memset(buffer, 0, strlen(buffer));
		url_encode(crt_time, buffer, strlen(crt_time), &newLen);
		memcpy(startPos, buffer, strlen(buffer));
		startPos = startPos + strlen(buffer);
		startPos = strstr(startPos, markStr);
	}
	return ret;
}

/**
 * 函数功能: 替换字符串
 * 参数：@findStr _in_out 需要修改替换的字符串
 * 		@markStr _in 从出现这个字符串的位置开始替换
 * 		@replaceStr _in 替换的字符串
 * 返回:返回值没有意义
 * 注意：本函数字符串无越界检查
 **/
int replace_string_start(char* findStr, char* markStr, char *replaceStr) {
	char *startPos = NULL;
	int ret = 0;
	startPos = strstr(findStr, markStr);
	if (startPos != NULL) {
		ret = 1;
	}else{
		return 0;
	}
	while (startPos != NULL) {
		memcpy(startPos, replaceStr, strlen(replaceStr));
		startPos = startPos + strlen(replaceStr);
		startPos = strstr(startPos, markStr);
	}
//	replace_string_start(startPos,markStr,replaceStr);
	return ret;
}


/**
 * 函数功能: 替换字符串
 * 参数：@findStr _in_out 需要修改替换的字符串
 * 		@markStr _in 从出现这个字符串的位置开始替换
 * 		@replaceStr _in 替换的字符串
 * 返回:返回值没有意义
 * 注意：本函数字符串无越界检查
 **/
int replace_string_end(char* findStr, char* markStr, char *replaceStr) {
	char *startPos = NULL;
	int ret = 0;
	startPos = strstr(findStr, markStr);
	if (startPos != NULL) {
		ret = 1;
	}else{
		return 0;
	}
	while (startPos != NULL) {
		startPos = startPos + strlen(markStr);
		memcpy(startPos, replaceStr, strlen(replaceStr));
		startPos = startPos + strlen(replaceStr);
		startPos = strstr(startPos, markStr);
	}
//	replace_string_end(startPos,markStr,replaceStr);
	return ret;
}

/**
 * 函数功能:将字符串中的英文字符全部转换成小写
 * 参数：str _in_out 转换的字符串
 * 返回结果：将修改后的结果返回
 **/
char *strlwr(char *str){
    char *orign = str;
    for (; *str!='\0'; str++)
        *str = tolower(*str);
    return orign;
}

/**
 * 函数功能:将字符串中的英文字符全部转换成大写
 * 参数：str _in_out 转换的字符串
 * 返回结果：将修改后的结果返回
 **/
char *strupr(char *str){
    char *orign = str;
    for (; *str!='\0'; str++)
        *str = toupper(*str);
    return orign;
}

