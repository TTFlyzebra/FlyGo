/*
 * timeutil.h
 *
 *  Created on: 2016年11月9日
 *      Author: flyzebra
 */
#ifndef TIMEUTIL_H_
#define TIMEUTIL_H_

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>


#ifdef __cplusplus
extern "C" {
#endif
char timebf[64];
char* get_current_time(char *buffer,int len, char* template);
char* flytime();

#ifdef __cplusplus
}
#endif
#endif /* TIMEUTIL_H_ */
