#include "functions.h"

char * my_str_n_cat(char *dest, const char *src, int n) {
	while (*dest != '\0') {
		dest++;
	}
	for (int i = 0; i < n; i++) {
		if (*src == '\0') {
			break;
		} else {
			*dest = *src;
			dest++;
			src++;
		}
	}
	return dest;
}