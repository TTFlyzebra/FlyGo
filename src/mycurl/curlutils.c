#include "curlutils.h"
#include "../log/flylog.h"

int TIME_OUT = 15;
int send_curl_http_get(char *url, char *savefile) {
	flylog_4("call send_curl_http_get()\nurl=%s\nsavefile=%s\n", url, savefile);
	CURL *curl;
	CURLcode res = -1;
	FILE *fp;

	if (savefile != NULL) {
		fp = fopen(savefile, "w");
	} else {
		fp = NULL;
	}

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_COOKIEJAR, "cookie.txt");
		curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookie.txt");
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIME_OUT);
		if (fp != NULL) {
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		}
		res = curl_easy_perform(curl);
		flylog_4("send curl http get result=%d.\n", res);
	}
//	curl_slist_free_all(headers);
	curl_easy_cleanup(curl);
	if (fp != NULL) {
		fclose(fp);
	}
	return res;
}

int send_curl_http_post(char *url, char *data, char *savefile) {
	flylog_4("call send_curl_http_post()\nurl=%s\nsavefile=%s\n", url, savefile);
	CURL *curl;
	CURLcode res = -1;
	FILE *fp;
	if ((fp = fopen(savefile, "w")) == NULL)
		return res;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_COOKIEJAR, "cookie.txt");
		curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookie.txt");
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIME_OUT);
		curl_easy_setopt(curl, CURLOPT_POST, 1); //设置问非0表示本次操作为post
		if (fp != NULL) {
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		}
		res = curl_easy_perform(curl);
	}
	curl_easy_cleanup(curl);
	if (fp != NULL) {
		fclose(fp);
	}
	return res;
}

int send_curl_cmd(char *curlcmd, char* savefile) {
	flylog_4("call send_curl_cmd()\ncurlcmd=%s\nsavefile=%s\n", curlcmd, savefile);
	CURL *curl = NULL;
	CURLcode res = CURL_LAST;
	struct curl_slist *headers = NULL;
	FILE *fp = NULL;
	char buffer[4096];
	char* startPos = NULL;

	if (savefile != NULL) {
		fp = fopen(savefile, "w");
	}

	curl = curl_easy_init();

	if (curl) {
		//获取url
		startPos = cut_string(curlcmd, "", "'", "'", buffer);
		if (buffer[0] != '\0') {
			curl_easy_setopt(curl, CURLOPT_URL, buffer);
			curl_easy_setopt(curl, CURLOPT_COOKIEJAR, "cookie.txt");
			curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookie.txt");
		} else {
			return 0;
		}

		//获取header
		startPos = (char *) curlcmd;
		while (startPos != NULL) {
			startPos = cut_string(startPos, "-H", "'", "'", buffer);
			if (buffer[0] != '\0') {
				headers = curl_slist_append(headers, buffer);
			}
		}
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

		//获取data
		startPos = cut_string(curlcmd, "-data", "'", "'", buffer);
		if (buffer[0] != '\0') {
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, buffer);
		}

		curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIME_OUT);

		if (fp != NULL) {
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		}
		res = curl_easy_perform(curl);
	}
	if (headers != NULL) {
		curl_slist_free_all(headers);
	}

	if (curl) {
		curl_easy_cleanup(curl);
	}

	if (fp != NULL) {
		fclose(fp);
	}

	fflush(stdout);
	flylog_4("\n---------------\n");
	return res;
}

int send_shttpdata(SHttpData *sHttpData, char *savefile) {
	CURL *curl = NULL;
	CURLcode res = CURL_LAST;
	struct curl_slist *headers = NULL;
	FILE *fp = NULL;
	char buffer[2048];
	char* startPos = NULL;

	if (savefile != NULL) {
		fp = fopen(savefile, "w");
	}
	curl = curl_easy_init();
	if (curl) {
		if (sHttpData->header[0] != '\0') {
			startPos = sHttpData->header;
			while (startPos != NULL) {
				startPos = cut_string(startPos, "", "", "\n", buffer);
				headers = curl_slist_append(headers, buffer);
			}
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		}
		curl_easy_setopt(curl, CURLOPT_COOKIEJAR, "cookie.txt");
		curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookie.txt");
		if (sHttpData->postdata[0] != '\0') {
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, sHttpData->postdata);
		}
		curl_easy_setopt(curl, CURLOPT_URL, sHttpData->url);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIME_OUT);
		if (fp != NULL) {
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		}
		res = curl_easy_perform(curl);
		if (savefile != NULL) {
			printf("%d", res);
		}
	}
	curl_slist_free_all(headers);
	curl_easy_cleanup(curl);
	if (fp != NULL) {
		fclose(fp);
	}
	fflush(stdout);
	return res;
}
