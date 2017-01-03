#include "curlsend.h"
#include "string.h"
//#include "vector.h"
//#include "iostream.h"

struct data {
	char trace_ascii; /* 1 or 0 */
};

static void dump(const char *text,
	FILE *stream, unsigned char *ptr, size_t size,
	char nohex)
{
	size_t i;
	size_t c;

	unsigned int width = 0x10;

	if (nohex)
		/* without the hex output, we can fit more on screen */
		width = 0x40;

	fprintf(stream, "%s, %10.10ld bytes (0x%8.8lx)\n",
		text, (long)size, (long)size);

	for (i = 0; i<size; i += width) {

		fprintf(stream, "%4.4lx: ", (long)i);

		if (!nohex) {
			/* hex not disabled, show it */
			for (c = 0; c < width; c++)
				if (i + c < size)
					fprintf(stream, "%02x ", ptr[i + c]);
				else
					fputs("   ", stream);
		}

		for (c = 0; (c < width) && (i + c < size); c++) {
			/* check for 0D0A; if found, skip past and start a new line of output */
			if (nohex && (i + c + 1 < size) && ptr[i + c] == 0x0D && ptr[i + c + 1] == 0x0A) {
				i += (c + 2 - width);
				break;
			}
			fprintf(stream, "%c",
				(ptr[i + c] >= 0x20) && (ptr[i + c]<0x80) ? ptr[i + c] : '.');
			/* check again for 0D0A, to avoid an extra \n if it's at width */
			if (nohex && (i + c + 2 < size) && ptr[i + c + 1] == 0x0D && ptr[i + c + 2] == 0x0A) {
				i += (c + 3 - width);
				break;
			}
		}
		fputc('\n', stream); /* newline */
	}
	fflush(stream);
}

static int my_trace(CURL *handle, curl_infotype type,
	char *data, size_t size,
	void *userp)
{
	struct data *config = (struct data *)userp;
	const char *text;
	(void)handle; /* prevent compiler warning */

	switch (type) {
	case CURLINFO_TEXT:
		fprintf(stderr, "== Info: %s", data);
	default: /* in case a new one is introduced to shock us */
		return 0;

	case CURLINFO_HEADER_OUT:
		text = "=> Send header";
		break;
	case CURLINFO_DATA_OUT:
		text = "=> Send data";
		break;
	case CURLINFO_SSL_DATA_OUT:
		text = "=> Send SSL data";
		break;
	case CURLINFO_HEADER_IN:
		text = "<= Recv header";
		break;
	case CURLINFO_DATA_IN:
		text = "<= Recv data";
		break;
	case CURLINFO_SSL_DATA_IN:
		text = "<= Recv SSL data";
		break;
	}

	dump(text, stderr, (unsigned char *)data, size, config->trace_ascii);
	return 0;
}

#ifdef RECV_IN_MEM
//用来保存response或者header，不能直接用std::string, 因为在设置CURLOPT_WRITEDATA和CURLOPT_WRITEHEADER时不能用c++类
struct userData {
	std::string data;
};

/**
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
* buf: 从服务器返回的buffer
* unit: buufer的单位
* bufSize: buffer的大小
* data: 保存从服务器返回的内容
* 注意这个函数会被调用多次
*/
size_t write_data(void *buf, size_t unit, size_t bufSize, struct userData * data) {
	int size = unit * bufSize;
	char * tmp = (char*)malloc(size + 1);
	memcpy(tmp, buf, size);
	tmp[size] = '\0';

	//把本次返回的内容加到自己的结构中
	data->data.append(tmp);
	free(tmp);
	return size;
}
#endif


int http_get(char *url, char *savefile) {
	CURL *curl = NULL;
	CURLcode res = CURL_LAST;
	struct curl_slist *headers = NULL;
	FILE *fp =NULL;
#ifdef RECV_IN_MEM
	struct userData response;
	struct userData header;
#endif
	struct data config;
	
	if (savefile != NULL) {
		fp = fopen(savefile, "w");
	}

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookie.txt");
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 60);
		//接受服务器的ssl证书而不管合不合法 （相当于命令行中的--insecure）
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);

		/*debug start */
		config.trace_ascii = 1; /* enable ascii tracing */
		curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, my_trace);
		curl_easy_setopt(curl, CURLOPT_DEBUGDATA, &config);
		/* the DEBUGFUNCTION has no effect until we enable VERBOSE */
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		/* http is redirected, so we tell libcurl to follow redirection */
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		/*debug end*/

		if (fp != NULL) {
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		}
#ifdef RECV_IN_MEM
		else {
			//指定response和header保存在哪里，以及如何处理它们
			curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, write_data);
			curl_easy_setopt(curl, CURLOPT_WRITEHEADER, &header);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
		}
#endif

		res = curl_easy_perform(curl);
		if (res != CURLE_OK){
			fprintf(stderr, "curl_easy_perform() failed: %s :%d\n",
				curl_easy_strerror(res), res);
		}
		
	}
	curl_slist_free_all(headers);
	curl_easy_cleanup(curl);
	if (fp != NULL) {
		fclose(fp);
	}
	return res;
}

int http_post(char *url, char *data, char *savefile) {
	CURL *curl;
	CURLcode res = CURLE_OK;
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
	CURL *curl = NULL;
	CURLcode res = CURL_LAST;
	struct curl_slist *headers = NULL;
	FILE *fp = NULL;
	char buffer[2048];
	char* startPos = NULL;

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
				startPos = cut_string(startPos, "", "", "\n", buffer);
				headers = curl_slist_append(headers, buffer);
			}
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
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
