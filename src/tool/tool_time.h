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


#ifdef __cplusplus
extern "C" {
#endif

char* get_current_time(char *buffer,int len, char* template);

#ifdef __cplusplus
}
#endif
#endif /* TIMEUTIL_H_ */
