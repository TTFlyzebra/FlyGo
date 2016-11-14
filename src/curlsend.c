#include "curlsend.h"

int http_get(char *url, char *savefile) {
	CURL *curl;
	CURLcode res = CURL_LAST;
	struct curl_slist *headers = NULL;
	FILE *fp = fopen(savefile, "w");
	if (fp == NULL) {
		return res;
	}

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookie.txt");
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 60);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		res = curl_easy_perform(curl);
	}
	curl_slist_free_all(headers);
	curl_easy_cleanup(curl);
	fclose(fp);
	return res;
}

int http_post(char *url, char *data, char *savefile) {
	CURL *curl;
	CURLcode res = -1;
	FILE *fp;
	if ((fp = fopen(savefile, "w")) == NULL)
		return res;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookie.txt");
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 60);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		res = curl_easy_perform(curl);
	}
	curl_easy_cleanup(curl);
	fclose(fp);
	return res;
}

int send_shttpdata(SHttpData *sHttpData, char *savefile) {
	CURL *curl;
	CURLcode res = CURL_LAST;
	struct curl_slist *headers = NULL;
	FILE *fp;
	char buffer[1024];
	char* startPos;

	if (savefile != NULL) {
		fp = fopen(savefile, "w");
	} else {
		fp = NULL;
	}
	curl = curl_easy_init();
	if (curl) {
		if (sHttpData->header[0] != '\0') {
			startPos = sHttpData->header;
			while (startPos != NULL) {
				startPos = cut_string(startPos, "", "", "\n",	buffer);
				headers = curl_slist_append(headers, buffer);
			}
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);// 改协议头
		}
		curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookie.txt");
		if (sHttpData->postdata[0] != '\0') {
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, sHttpData->postdata);
		}
		curl_easy_setopt(curl, CURLOPT_URL, sHttpData->url);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 60);
		if (fp != NULL) {
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		}
		res = curl_easy_perform(curl);
//		printf("%d", res);
	}
	curl_slist_free_all(headers);
	curl_easy_cleanup(curl);
	if (fp != NULL) {
		fclose(fp);
	}
	return res;
}
