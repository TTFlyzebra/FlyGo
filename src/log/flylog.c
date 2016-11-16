/*
 * flylog.c
 *
 *  Created on: 2016年11月16日
 *      Author: flyzebra
 */
#include "flylog.h"

void flylog(char *tag,char *format, ...) {
	va_list ap;
	va_start(ap, format);
	vprintf(format, ap);
	va_end(ap);
}
