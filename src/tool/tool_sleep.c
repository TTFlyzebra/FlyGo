/*
 * fly_sleep.c
 *
 *  Created on: 2016年11月11日
 *      Author: flyzebra
 */
#include "tool_sleep.h"
#include <unistd.h>
#include "../log/flylog.h"
int n1;
#ifndef WIN32
void milliseconds_sleep(unsigned long mSec){
    struct timeval tv;
    tv.tv_sec=mSec/1000;
    tv.tv_usec=(mSec%1000)*1000;
    int err;
    do{
       err=select(0,NULL,NULL,NULL,&tv);
    }while(err<0 && errno==EINTR);
}
#endif

void fly_sleep(int millis){
	if(millis<=0){
		return;
	}
	n1 = millis/1000;
	if (n1 > 0) {
		flylog_2("[sleep(%d)s]", millis / 1000);
	}
	fflush(stdout);
#ifdef WIN32
	Sleep(millis);
#else
//	milliseconds_sleep(millis);
	usleep(millis*1000);
#endif
}


