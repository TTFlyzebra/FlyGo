/*
 * fly_sleep.h
 *
 *因winodw和linux的sleep不一样，定义fly_sleep代替sleep
 *  Created on: 2016年11月11日
 *      Author: flyzebra
 */

#ifndef TOOL_TOOL_SLEEP_H_
#define TOOL_TOOL_SLEEP_H_

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void fly_sleep(int millis);

#endif /* TOOL_TOOL_SLEEP_H_ */
