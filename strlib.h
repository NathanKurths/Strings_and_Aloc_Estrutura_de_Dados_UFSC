#include <stdlib.h>

#ifndef _strlib_
#define _strlib_

int 	str_length		(const char *str);
char*	str_duplicate	(const char *str);
int		str_compare		(const char *stra, const char *strb);
int 	str_reverse 	(char *str);
int		str_upper 		(char *str);
int		str_lower 		(char *str);
int 	str_copy		(char *dst, const char *src);
char* 	str_concatenate (const char *stra, const char *strb);
int 	str_find_first	(const char *str, const char c);
int 	str_find_last 	(const char *str, const char c);
int 	str_count_words (const char *str);

#endif