/*
 * fly_sleep.c
 *
 *  Created on: 2016年11月11日
 *      Author: flyzebra
 */
#include "tool_sleep.h"

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
	printf("<waitting-%d-ms>",millis);
	fflush(stdout);
#ifdef WIN32
	Sleep(millis);
#else
	milliseconds_sleep(millis);
#endif
}


