#ifndef URL_H
#define URL_H

#include <ctype.h>

#ifdef __cplusplus
extern "C" {
#endif

int url_decode(char *str, int len);
char *url_encode(const char *s,char *buffer, int len, int *new_length);
char *url_encode_char(const char *s, char *buffer,int len, int *new_length,char nochar);

#ifdef __cplusplus
}
#endif

#endif /* URL_H */
