/*
 * flylog.c
 *
 *  Created on: 2016年11月16日
 *      Author: flyzebra
 */
#include "flylog.h"

int FLYLOG_DEBUG = 0xff;
void flylog(char *format, ...) {
	va_list ap;
	va_start(ap, format);
	vprintf(format, ap);
	va_end(ap);
}

void flylog_1(char *format, ...) {
	if (0 < FLYLOG_DEBUG) {
		va_list ap;
		va_start(ap, format);
		vprintf(format, ap);
		va_end(ap);
	}
}

void flylog_2(char *format, ...) {
	if (1 < FLYLOG_DEBUG) {
		va_list ap;
		va_start(ap, format);
		vprintf(format, ap);
		va_end(ap);
	}
}

void flylog_3(char *format, ...) {
	if (2 < FLYLOG_DEBUG) {
		va_list ap;
		va_start(ap, format);
		vprintf(format, ap);
		va_end(ap);
	}
}

void flylog_4(char *format, ...) {
	if (3 < FLYLOG_DEBUG) {
		va_list ap;
		va_start(ap, format);
		vprintf(format, ap);
		va_end(ap);
	}
}

void flylog_set_debug(int mSetDebug) {
	FLYLOG_DEBUG = mSetDebug;
}
