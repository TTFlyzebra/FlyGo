/*
 * qqpostdata.c
 *
 *  Created on: 2016年11月3日
 *      Author: flyzebra
 */
#include "qqpostdata.h"
/**
 * 返回的字符串如果不再使用需要释放内存
 */
char * getPostData1(char *url, char *cmid, char *pid) {
	char str[4096];
	char buffer[1024];
	//此处目前为硬编码，将来需进一步修改增强功能
	strcat(str, "tpid=");

	strcat(str, "&url=");
	int len;
	strcat(str, url_encode(url, buffer,strlen(url), &len));

	strcat(str, "&cmid=");
	strcat(str, cmid);

	strcat(str, "&ptag=");

	strcat(str, "&emsg=%24%24");

	strcat(str, "&diaonlen=0%240%240");

	strcat(str, "&version=TencentPlayerV3%2E2%2E19%2E382");

	strcat(str, "&vurl=%24%24");

	strcat(str, "&pfversion=LNX%2E11%2E2");

	strcat(str, "&isfocustab=0%240%240");

	strcat(str, "&vid=%24%24");

	strcat(str, "&type=0%240%240");

	strcat(str, "&buffersize=0%240%240");

	strcat(str, "&preformat=0%240%240");

	strcat(str, "&isvisible=0%240%240");

	strcat(str, "&platform=1");

	strcat(str, "&rid=%24%24");

	strcat(str,	"&ua=Mozilla%252F5%2E0%2520%28X11%253B%2520Ubuntu%253B%2520Linux%2520x86%5F64%253B%2520rv%253A49%2E0%29%2520Gecko%252F20100101%2520Firefox%252F49%2E0");

	strcat(str, "&loadwait=0%240%240");

	strcat(str, "&bi=0%240%240");

	strcat(str, "&predefn=0%240%240");

	strcat(str, "&bufferwait=0%240%240");

	strcat(str, "&pid");
	strcat(str, pid);

	strcat(str, "&cpay=0");

	strcat(str, "&autoformat=1%241%241");

	strcat(str, "&pversion=");

	strcat(str, "&tpay=%24%24");

	strcat(str, "&val1=1%241%241");

	strcat(str, "&index=0%241%242");

	strcat(str, "&bt=0");

	strcat(str, "&val2=0%240%240");

	strcat(str, "&dltype=1%241%241");

	strcat(str, "&level=0%240%240");

	strcat(str, "&step=400%24401%24402");

	strcat(str, "&clspeed=0%240%240");

	strcat(str, "&adid=");

	strcat(str, "&iformat=%24%24");

	strcat(str,	"&ctime=2016%2D11%2D03%2010%3A36%3A46%20168%242016%2D11%2D03%2010%3A36%3A46%20367%242016%2D11%2D03%2010%3A36%3A46%20758");

	strcat(str, "&exid=0%240%240");

	strcat(str, "&BossId=2577");

	strcat(str, "&defn=%24%24");

	strcat(str, "&idx=0%240%240");

	strcat(str, "&ptime=0%240%240");

	strcat(str, "&head%5Fref=");

	strcat(str, "&vt=0%240%240");

	strcat(str, "&ispac=0%240%240");

	strcat(str, "&isvip=%2D1%24%2D1%24%2D1");

	return str;
}

/**
 * 返回的字符串如果不再使用需要释放内存
 */
char * getPostData2(char *url, char *cmid, char *pid, char *vid) {
	char *str;
	char buffer[1024];
	if ((str = (char*) malloc(4096)) == NULL) {
		printf("Malloc failed!\n");
		return NULL;
	}
	strcat(str,"tpid=");

	strcat(str,"&url=");
	int len;
	strcat(str, url_encode(url, buffer,strlen(url), &len));

	strcat(str,"&cmid=");
	strcat(str,cmid);

	strcat(str,"&ptag=");

	strcat(str,"&emsg=");

	strcat(str,"&diaonlen=1273");

	strcat(str,"&version=TencentPlayerV3%2E2%2E19%2E382");

	strcat(str,"&vurl=");

	strcat(str,"&pfversion=LNX%2E11%2E2");

	strcat(str,"&isfocustab=1");

	strcat(str,"&vid=");
	strcat(str,vid);

	strcat(str,"&type=0");

	strcat(str,"&buffersize=0");

	strcat(str,"&preformat=0");

	strcat(str,"&isvisible=1");

	strcat(str,"&platform=1");

	strcat(str,"&rid=");

	strcat(str,"&ua=Mozilla%252F5%2E0%2520%28X11%253B%2520Ubuntu%253B%2520Linux%2520x86%5F64%253B%2520rv%253A49%2E0%29%2520Gecko%252F20100101%2520Firefox%252F49%2E0");

	strcat(str,"&loadwait=0");

	strcat(str,"&bi=0");

	strcat(str,"&predefn=0");

	strcat(str,"&bufferwait=0");

	strcat(str,"&pid=");
	strcat(str,pid);

	strcat(str,"&cpay=0");

	strcat(str,"&autoformat=1");

	strcat(str,"&pversion=");

	strcat(str,"&tpay=");

	strcat(str,"&val1=0");

	strcat(str,"&index=3");

	strcat(str,"&bt=0");

	strcat(str,"&val2=0");

	strcat(str,"&dltype=1");

	strcat(str,"&level=0");

	strcat(str,"&step=3");

	strcat(str,"&clspeed=0");

	strcat(str,"&adid=");

	strcat(str,"&iformat=");

	strcat(str,"&ctime=2016%2D11%2D03%2010%3A36%3A46%20770");

	strcat(str,"&exid=0");

	strcat(str,"&BossId=2577");

	strcat(str,"&defn=");

	strcat(str,"&idx=0");

	strcat(str,"&ptime=0");

	strcat(str,"&head%5Fref=");

	strcat(str,"&vt=0");

	strcat(str,"&ispac=0");

	strcat(str,"&isvip=%2D1");
	//此处目前为硬编码，将来需进一步修改增强功能
	return str;
}
