#ifndef _smanip_h
#define _smanip_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NOT_PRES -1

 char *strtolower(char *str, int strleng);
 char *strtoupper(char *str, int strleng);
 int strpos(char *haystack, char *needle);
 char *substr(char *str, int start, int len, int strleng);
 char *str_replace (const char *, const char *, const char *);

#endif
