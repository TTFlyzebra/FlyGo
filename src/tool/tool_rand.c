/*
 * utils.c
 *
 *  Created on: 2016年11月3日
 *      Author: flyzebra
 */
#include "tool_rand.h"
char randStr[129];
/**
 * 函数功能:生成随机字符串
 * 参数：@length 生成的字符串长度
 * 返回：返回所生成的随机字符串
 **/
char* getRandomString(int length) {
	int flag;
    int i;
	for (i = 0; i < length; i++) {
		flag = rand() % 2;
		switch (flag) {
		case 0:
			randStr[i] = 'a' + rand() % 26;
			break;
		case 1:
			randStr[i] = '0' + rand() % 10;
			break;
		case 2:
			randStr[i] = 'A' + rand() % 26;
			break;
		default:
			randStr[i] = 'x';
			break;
		}
	}
	randStr[length] = '\0';
	return randStr;
}

char* getOldRandomString() {
	return randStr;
}
