#include "smanip.h"

char *strtolower(char *str, int strleng)
{
	int i;
	char lowerstr[strleng];
	for(i = 0; i < strleng; i++)
		lowerstr[i] = tolower(str[i]);
	return strdup(lowerstr);
}

char *strtoupper(char *str, int strleng)
{
	int i;
	char upperstr[strleng];
	for(i = 0; i < strleng; i++)
		upperstr[i] = toupper(str[i]);
	return strdup(upperstr);
}

int strpos(char *haystack, char *needle)
{
	char *p = strstr(haystack, needle);
	if (p)
		return p - haystack;
	return NOT_PRES;
}

char *substr(char *str, int start, int len, int strleng)
{
	char str2[strleng];
	if(start+len > strleng)
		exit(1);
	strncpy(str2, str+start, len);
	str2[start+len] = '\0';

	return strdup(str2);
}
