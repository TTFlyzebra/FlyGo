/*
 * load_lua.h
 *
 *  Created on: 2016年12月26日
 *      Author: flyzebra
 */

#ifndef LUA_LOADLUA_H_
#define LUA_LOADLUA_H_


#include <stdio.h>
#include <stdlib.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#include "../tool/tool_time.h"
#include "../log/flylog.h"
#include "luautils.h"

int runLua();

#endif /* LUA_LOADLUA_H_ */
