/*
 * livemsg_getadlist.c
 *
 *  Created on: 2016年12月14日
 *      Author: flyzebra
 */

#include "livemsg_getadlist.h"
#include "tool/tool_rand.h"
#include "tool/tool_time.h"
#include "log/flylog.h"
char *getadurl() {
	char timestr[32];

	strcat(adurl, "https://livew.l.qq.com/livemsg?ty=web&ad_type=LD|KB&pf=in&pt=0&pc=0&live=0&from=0&pu=-1&v=TencentPlayerV3.2.19.358&plugin=1.4.6&speed=0&adaptor=2&musictxt=&chid=0&st=0&resp_type=json");

	strcat(adurl, "&_t=");
	sprintf(timestr, "%d", get_current_time_sec());
	strcat(adurl, timestr);

	strcat(adurl, "&callback=lviewcb");
	strcat(adurl, "&rfid=");
	strcat(adurl, "&vid=8kO1XKH8Qfm");
	strcat(adurl, "&vptag=bl.zy.movie_ilcxi3gxzj12ksm.20161209");
	strcat(adurl, "&url=https%3A%2F%2Fv.qq.com%2Fx%2Fcover%2Filcxi3gxzj12ksm.html%3Fptag%3Dbl.zy.movie_ilcxi3gxzj12ksm.20161209");
	strcat(adurl, "&refer=");

	strcat(adurl, "&pid=");
	strcat(adurl, getRandomString(32));

	strcat(adurl, "&mbid=");
	strcat(adurl, getRandomString(32));

	strcat(adurl, "&oid=");
	strcat(adurl, "&guid=c4437c31ac304b73d962a6e646ea7384");
	strcat(adurl, "&coverid=ilcxi3gxzj12ksm");
//	flylog("adurl=%s\n", adurl);
	return adurl;
}
