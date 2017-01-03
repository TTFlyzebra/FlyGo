/*
 * flylog.h
 *
 *  Created on: 2016年11月16日
 *      Author: flyzebra
 */

#ifndef LOG_FLYLOG_H_
#define LOG_FLYLOG_H_

#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif


extern int  FLYLOG_DEBUG;
void flylog(char *format, ...);
void flylog_1(char *format, ...);
void flylog_2(char *format, ...);
void flylog_3(char *format, ...);
void flylog_4(char *format, ...);
void flylog_set_debug(int mSetDebug);

#ifdef __cplusplus
}
#endif

#endif /* LOG_FLYLOG_H_ */
