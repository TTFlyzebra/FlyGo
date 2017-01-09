/*
 * tools.h
 *
 *  Created on: 2016年12月27日
 *      Author: flyzebra
 */

#ifndef LUA_LUAUTILS_H_
#define LUA_LUAUTILS_H_
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#include "../tool/tool_time.h"
#include "../log/flylog.h"

/**
 * 执行指定的lua脚本文件中的指定函数
 */
void runLuaFunC(lua_State *L,char *filePath,char *funcName);

/**
 * 执行指定的lua脚本文件
 */
void runLuaFile(lua_State *L, char *filePath);

#endif /* LUA_LUAUTILS_H_ */
