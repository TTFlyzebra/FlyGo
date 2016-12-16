/*
 * qqpostdata.h
 *
 *  Created on: 2016年11月3日
 *      Author: flyzebra
 */

#ifndef QQPOSTDATA_H_
#define QQPOSTDATA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qqpostdata.h"
#include "tool/tool_url.h"
#include "tool/tool_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

char * getPostData1(char *url,char *cmid,char *pid);
char * getPostData2(char *url,char *cmid,char *pid,char *vid);

#ifdef __cplusplus
}
#endif


#endif /* QQPOSTDATA_H_ */
