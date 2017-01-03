/*
 * kvcollect.h
 *
 *  Created on: 2016年12月14日
 *      Author: flyzebra
 */

#ifndef TOOL_KVCOLLECT_H_
#define TOOL_KVCOLLECT_H_

#ifdef __cplusplus
extern "C" {
#endif

extern char kvbuffer[4096];
char *getkvcollecturl(char *url, int count, int time, int sumtime);

#ifdef __cplusplus
}

#endif
#endif /* TOOL_KVCOLLECT_H_ */
