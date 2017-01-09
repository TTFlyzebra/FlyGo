/*
 ============================================================================
 Name        : FlyGo.c
 Author      : FlyZebra
 Version     :
 Copyright   : FlyZebra
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "mylua/loadlua.h"


int main(int argc, char** argv) {
	int result = 0;
	//设置日志输出等级
	flylog("[%s] Program is start!\n", flytime());
	result = runLua();
	flylog("[%s] Program is end!\n", flytime());
	return result;
}
