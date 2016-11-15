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

#ifdef __cplusplus
extern "C" {
#endif

char* cut_string_with_start_mark(char* findStr, char* startMark, char *buffer);
char* cut_string(char* findStr, char* markStr, char *startStr, char *endStr,char *buffer);
char* replace_string(char* findStr, char* markStr, char *startStr, char *endStr,char *buffer);

#ifdef __cplusplus
}
#endif
#endif /* TOOL_TOOL_STRING_H_ */
