/*
 * tools.c
 *
 *  Created on: 2016年12月27日
 *      Author: flyzebra
 */

#include "luautils.h"
void runLuaFunC(lua_State *L, char *filePath, char *funcName) {
	flylog_4("Load lua file \"%s\"\n",filePath);
	luaL_dofile(L, filePath);
	lua_getglobal(L, funcName);
	lua_call(L, 0, 1);
}

void runLuaFile(lua_State *L, char *filePath) {
	flylog_4("Load lua file \"%s\"\n",filePath);
	luaL_dofile(L, filePath);
}
