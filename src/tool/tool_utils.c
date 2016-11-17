/*
 * tool_utils.c
 *
 *  Created on: 2016年11月17日
 *      Author: flyzebra
 */

#include "tool_utils.h"
void swap(char *p1,char* p2){
	char *temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}

char *strlwr(char *str){
    char *orign = str;
    for (; *str!='\0 '; str++)
        *str = tolower(*str);
    return orign;
}
