/*
 * utils.c
 *
 *  Created on: 2016年11月3日
 *      Author: flyzebra
 */
#include "tool_rand.h"

char* getRandomString(char *str,int length) {
	int flag;
    int i;
	for (i = 0; i < length; i++) {
		flag = rand() % 3;
		switch (flag) {
		case 0:
			str[i] = 'A' + rand() % 26;
			break;
		case 1:
			str[i] = 'a' + rand() % 26;
			break;
		case 2:
			str[i] = '0' + rand() % 10;
			break;
		default:
			str[i] = 'x';
			break;
		}
	}
	str[length] = '\0';
	return str;
}
