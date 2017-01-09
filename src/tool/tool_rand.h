/*
 * utils.h
 *
 *  Created on: 2016年11月3日
 *      Author: flyzebra
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

extern char randStr[129];

char* getRandomString(int lenght);

char* getOldRandomString();

char* getRandomInteger(int length);

#ifdef __cplusplus
}
#endif
#endif /* UTILS_H_ */
