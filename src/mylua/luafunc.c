/*
 * luafunc.c
 *  Created on: 2016年12月28日
 *      Author: flyzebra
 */

#include "luafunc.h"
#include "../mycurl/curlutils.h"
#include "../log/flylog.h"
#include "../tool/tool_rand.h"

int DEBUG(lua_State *L) {
	int level = lua_tonumber(L, 1);
	flylog_set_debug(level);
	return 1;
}

int send_httpGet(lua_State *L) {
	char *url = NULL;
	char *savefile = NULL;
	size_t len1 = 0;
	size_t len2 = 0;
	int top;
	top = lua_gettop(L);
	url = (char *) luaL_tolstring(L, 1, &len1);
	if (top > 1) {
		savefile = (char *) luaL_tolstring(L, 2, &len2);
	}

	send_curl_http_get(url, savefile);
	return 1;
}

int send_httpPost(lua_State *L) {
	char *url = NULL;
	char *data = NULL;
	char *savefile = NULL;
	size_t len1 = 0;
	size_t len2 = 0;
	size_t len3 = 0;
	int top;
	top = lua_gettop(L);
	url = (char *) luaL_tolstring(L, 1, &len1);
	data = (char *) luaL_tolstring(L, 2, &len2);
	if (top > 2) {
		savefile = (char *) luaL_tolstring(L, 3, &len3);
	}
	send_curl_http_post(url, data, savefile);
	return 1;
}

int send_curlCmd(lua_State *L) {
	char *curlcmd = NULL;
	char *savefile = NULL;
	size_t len1 = 0;
	size_t len2 = 0;
	int top;
	top = lua_gettop(L);
	curlcmd = (char *) luaL_tolstring(L, 1, &len1);
	if (top > 1) {
		savefile = (char *) luaL_tolstring(L, 2, &len2);
	}
	send_curl_cmd(curlcmd, savefile);
	return 1;
}

int lua_url_encode(lua_State *L) {
	char buffer[1024];
	const char *str = NULL;
	size_t len1 = 0;
	int ilen = 0;
	str = luaL_tolstring(L, 1, &len1);
	ilen = (int) len1;
	url_encode(str, buffer, strlen(str), &ilen);
	lua_pushlstring(L, buffer, strlen(buffer));
	return 1;
}

int get_url_time(lua_State *L) {
	char buffer[48];
	char *time = flytime();
	int len = 0;
	url_encode(time, buffer, strlen(time), &len);
	lua_pushlstring(L, buffer, strlen(buffer));
	return 1;
}

int get_url_time1(lua_State *L) {
	char buffer[48];
	char *time = flytime();
	int len = 0;
	url_encode_char(time, buffer, strlen(time), &len, ' ');
	lua_pushlstring(L, buffer, strlen(buffer));
	return 1;
}
int get_random_string(lua_State *L) {
	char *str;
	int lenght;
	lenght = lua_tonumber(L, 1);
	str = getRandomString(lenght);
	lua_pushlstring(L, str, strlen(str));
	return 1;
}
