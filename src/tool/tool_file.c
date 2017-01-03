/*
 * tool_file.c
 *
 *  Created on: 2016年11月13日
 *      Author: flyzebra
 */
#include <stdio.h>
#include "tool_file.h"
/**
 * 函数功能：读取文件内容，以字符串形式返回所读取的文件内容
 * @filename:$in 文件名
 * @buffer:$in$out 读取文件内容的存放缓存
 * @return:成功返回指向所读取文件内容的字符串指针，失败返回NULL
 */
char* read_all_file(char *filename, char*buffer) {
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

