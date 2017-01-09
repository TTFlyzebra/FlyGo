/*
 * load_lua.c
 *
 *  Created on: 2016年12月26日
 *      Author: flyzebra
 */

#include "../mylua/loadlua.h"

#include "../json/lua_cjson.h"
#include "../mycurl/curlutils.h"
#include "../mylua/luafunc.h"
#include "../log/flylog.h"
/**
 * 成功返回0
 * 需要确认问题
 * 1,如果更新lua脚本文件失败，是继续执行以前的脚本文件，还是直接停止程序运行，或者做其它处理
 *
 *
 */
int runLua() {
	int res = 0;
	//初始化Lua运行环境
	lua_State *l = luaL_newstate();
	luaL_openlibs(l);

	//加载cjson
	luaopen_cjson(l);

	//注册C函数使其在LUA中可以调用
	lua_register(l, "DEBUG", DEBUG);
	lua_register(l, "SendHttpGet", send_httpGet);
	lua_register(l, "SendHttpPost", send_httpPost);
	lua_register(l, "SendCurlCmd", send_curlCmd);
	lua_register(l, "UrlEncode", lua_url_encode);
	lua_register(l, "getUrlTime", get_url_time);
	lua_register(l, "getUrlTime1", get_url_time1);
	lua_register(l, "getRandomStr", get_random_string);
	//调用指定Lua函数
//	runLuaFunC(L, "flygo.lua","runLua");
	//指定网址下载flygo.lua文件

	//此下为脚本更新部分，更新失败的处理
	res = send_curl_http_get("http://10.10.30.225:8080/phppro/FlyGoWeb/flygo.lua", "flygo.lua");
	if (res == 0) {
		if (remove("default.lua") == 0) {
			flylog_4("Removed %s.\n", "default.lua");
		} else {
			flylog_4("remove failed!\n");
		}
		rename("flygo.lua", "default.lua");
	}
	runLuaFile(l, "default.lua");

	//执行指定的lua脚本文件

	//结束Lua运行环境
	lua_close(l);
	return res;
}
