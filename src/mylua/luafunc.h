/*
 * luafunc.h
 *
 *  Created on: 2016年12月28日
 *      Author: flyzebra
 */

#ifndef LUA_LUAFUNC_H_
#define LUA_LUAFUNC_H_

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int DEBUG(lua_State *L);
/**
 * 发送Http Get请求
 */
int send_httpGet(lua_State *L);

/**
 * 发送Http Post请求
 */
int send_httpPost(lua_State *L);

/**
 * 执行CURL请求
 */
int send_curlCmd(lua_State *L);

/**
 * URL编码
 */
int lua_url_encode(lua_State *L);

/*
 * 获取当前时间url编码
 */
int get_url_time(lua_State *L);

/**
 * 获取当前时间url编码,特殊字符只对' '编码
 */
int get_url_time1(lua_State *L);

/**
 * 获取随机字符串由数字和字符混编
 */
int get_random_string(lua_State *L);


#endif /* LUA_LUAFUNC_H_ */
