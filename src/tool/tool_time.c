/*
 * timeutil.c
 *
 *  Created on: 2016年11月9日
 *      Author: flyzebra
 */
#include "tool_time.h"

char* get_current_time(char *buffer, int len, char* template) {
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, len, template, timeinfo);
	return buffer;
}
