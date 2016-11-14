/*
 * tool_file.h
 *
 *  Created on: 2016年11月13日
 *      Author: flyzebra
 */

#ifndef TOOL_TOOL_FILE_H_
#define TOOL_TOOL_FILE_H_

/**
 * 函数功能：读取文件内容，以字符串形式返回所读取的文件内容
 * @filename:$in 文件名
 * @buffer:$in$out 读取文件内容的存放缓存
 * @return:成功返回指向所读取文件内容的字符串指针，失败返回NULL
 */
char* read_all_file(char*buffer,char *filename);

#endif /* TOOL_TOOL_FILE_H_ */
