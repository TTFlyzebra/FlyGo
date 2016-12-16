/*
 * timeutil.c
 *
 *  Created on: 2016年11月9日
 *      Author: flyzebra
 */
#include "tool_time.h"
/**
 * %Y-%m-%d %I:%M:%S\n
 */
char *get_time_ms(char* buffer, int ms) {
	char str[5];
	if (ms == 0) {
		buffer[0] = ' ';
		buffer[1] = '0';
		buffer[2] = '0';
		buffer[3] = '0';
		buffer[4] = '\0';
		return buffer;
	}
	if (ms > 99) {
		buffer[0] = ' ';
	} else if (ms > 9) {
		buffer[0] = ' ';
		buffer[1] = '0';
	} else if (ms > 0) {
		buffer[0] = ' ';
		buffer[1] = '0';
		buffer[2] = '0';
	}

	sprintf(str, "%d", ms);
	strcat(buffer, str);
	return buffer;
}

char* flytime() {
	char buffer[5] = { 0 };
#ifndef WIN32
	struct timeval tv;
	time_t tt;
	struct tm *today;
	gettimeofday(&tv, NULL);
	tt = tv.tv_sec;
	today = localtime(&tt);
	strftime(timebf, 100, "%Y-%m-%d %H:%M:%S", today);
	get_time_ms(buffer, (tv.tv_usec) / 1000);
	strcat(timebf, buffer);
	return timebf;
#else
	time_t rawtime;
	struct tm * timeinfo;
	memset(timebf,0,strlen(timebf));
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(timebf, 64, "%Y-%m-%d %H:%M:%S", timeinfo);
	get_time_ms(buffer,clock()%1000);
	strcat(timebf, buffer);
	return timebf;
#endif

}

int get_current_time_sec() {
    return time((time_t*)NULL);
}

