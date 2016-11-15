/*
 * tool_string.c
 *
 *  Created on: 2016年11月13日
 *      Author: flyzebra
 */
#include "tool_string.h"

char* cut_string_with_start_mark(char* findStr, char* startMark, char *buffer){
	char *firstPos = findStr;
	char *endPos = NULL;
	buffer[0] = '\0';
	firstPos = strstr(findStr, startMark);
	if(firstPos==NULL){
		return NULL;
	}
	firstPos = firstPos+strlen(startMark);
	endPos = strstr(firstPos, startMark);
	if(endPos==NULL){
		memcpy(buffer,findStr,strlen(findStr));
		buffer[strlen(findStr)] = '\0';
	}else{
		memcpy(buffer,findStr,endPos-findStr);
		buffer[endPos-findStr] = '\0';
	}
	firstPos = findStr+strlen(buffer);
	return firstPos;
}

char* cut_string(char* findStr, char* markStr, char *startStr, char *endStr, char *buffer) {
	char *startPos = findStr;
	char *endPos = findStr;
	char *bufEndpos = buffer;
	buffer[0] = '\0';
	startPos = strstr(startPos, markStr);
	if (NULL != startPos) {
		startPos += strlen(markStr);
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

