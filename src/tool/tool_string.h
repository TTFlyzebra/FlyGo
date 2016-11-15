/*
 * tool_string.h
 *
 *  Created on: 2016年11月13日
 *      Author: flyzebra
 */

#ifndef TOOL_TOOL_STRING_H_
#define TOOL_TOOL_STRING_H_
#include <stdio.h>
#include <string.h>
#include "tool_sleep.h"
#include "tool_time.h"
#include "tool_url.h"

#ifdef __cplusplus
extern "C" {
#endif

char* cut_string_with_start_mark(char* findStr, char* startMark, char *buffer);
char* cut_string(char* findStr, char* markStr, char *startStr, char *endStr,char *buffer);
int replace_string(char* findStr, char* markStr, char *replaceStr);
int replace_string_time(char* findStr, char* markStr);

#ifdef __cplusplus
}
#endif
#endif /* TOOL_TOOL_STRING_H_ */
