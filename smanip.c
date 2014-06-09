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

/*
	This function was not written by me, I have borrowed it from the code
	written by chantra at http://coding.debuntu.org/c-implementing-str_replace-replace-all-occurrences-substring
	this is the 3rd posted version which includes updates by chantra and iandouglas.
*/

char *str_replace ( const char *string, const char *substr, const char *replacement )
{
	char *tok = NULL;
	char *newstr = NULL;
	char *oldstr = NULL;
	char *head = NULL;
 
	/* if either substr or replacement is NULL, duplicate string a let caller handle it */
	if ( substr == NULL || replacement == NULL ) 
		return strdup (string);

	newstr = strdup (string);
	head = newstr;

	while ( (tok = strstr ( head, substr )))
	{
		oldstr = newstr;
		newstr = malloc ( strlen ( oldstr ) - strlen ( substr ) + strlen ( replacement ) + 1 );
		/*failed to alloc mem, free old string and return NULL */
		if ( newstr == NULL )
		{
			free (oldstr);
			return NULL;
		}
		memcpy ( newstr, oldstr, tok - oldstr );
		memcpy ( newstr + (tok - oldstr), replacement, strlen ( replacement ) );
		memcpy ( newstr + (tok - oldstr) + strlen( replacement ), tok + strlen ( substr ), strlen ( oldstr ) - strlen ( substr ) - ( tok - oldstr ) );
		memset ( newstr + strlen ( oldstr ) - strlen ( substr ) + strlen ( replacement ) , 0, 1 );
		/* move back head right after the last replacement */
		head = newstr + (tok - oldstr) + strlen( replacement );
		free (oldstr);
	}
	return newstr;
}
