/*
 * tool_string.h
 *
 *  Created on: 2016年11月13日
 *      Author: flyzebra
 */

#ifndef TOOL_TOOL_STRING_H_
#define TOOL_TOOL_STRING_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <string.h>
char* cut_string(char* findStr, char* markStr, char *startStr, char *endStr,char *buffer);

#ifdef __cplusplus
}
#endif
#endif /* TOOL_TOOL_STRING_H_ */
