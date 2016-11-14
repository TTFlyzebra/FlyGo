/*
 * fly_sleep.c
 *
 *  Created on: 2016年11月11日
 *      Author: flyzebra
 */
#include "tool_sleep.h"

void fly_sleep(int millis){
#ifdef WIN32
	Sleep(millis);
#else
	sleep(millis/1000.0);
#endif
}

