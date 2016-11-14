/*
 * tool_file.c
 *
 *  Created on: 2016年11月13日
 *      Author: flyzebra
 */
#include <stdio.h>

char* read_all_file(char *filename,char*buffer) {
	FILE *fp;
	int file_size;
	fp = fopen(filename, "r");
	if(NULL==fp){
		return NULL;
	}
	fseek(fp, 0, SEEK_END);
	file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	fread(buffer, file_size, sizeof(char), fp);
	fclose(fp);
	return buffer;
}

