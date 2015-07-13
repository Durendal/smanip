// This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include "smanip.h"

char *strtolower(const char *str, int len)
{
	int i = 0;
	char lowerstr[strlen(str)+1];
	while(str[i] != '\0' && i < len)
	{
		lowerstr[i] = tolower(str[i]);
		i++;
	}
	lowerstr[i] = '\0';

	return strdup(lowerstr);
}

char *strtoupper(const char *str, int len)
{
	int i = 0;
	char lowerstr[strlen(str)+1];
	while(str[i] != '\0' && i < len)
	{
		lowerstr[i] = toupper(str[i]);
		i++;
	}
	lowerstr[i] = '\0';
	
	return strdup(lowerstr);
}

int strpos(char *haystack, char *needle)
{
	char *p = strstr(haystack, needle);
	if (p)
		return p - haystack;
	return NOT_PRES;
}

char *substr(const char *str, int start, int offset)
{
	if(strlen(str) < start + offset)
		exit(1);

	char str2[offset];
	strncpy(str2, str+start, offset);
	str2[offset] = '\0';

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

/*
	The following functions are based off of the LIB_parse.php library written by Michael Schrenk in his book Webbots, Spiders, and Screenscrapers (nostarch press).
	I have attempted to recreate them in C as well as I could. The original algorithms and all credit for authorship belong to Michael Schrenk.
*/

char *split_string(const char *string, const char *delineator, int desired, int type)
{
	char *lc_str = strtolower(string);
	char *marker = strtolower(delineator);
	char *parsed_string;

	int split_here;
	if(desired == BEFORE)
	{
		if(type == EXCL)
			split_here = strpos(lc_str, marker);
		else
			split_here = strpos(lc_str, marker)+strlen(marker);

		parsed_string = substr(string, 0, split_here);
	}
	else
	{
		if(type == EXCL)
			split_here = strpos(lc_str, marker) + strlen(marker);
		else
			split_here = strpos(lc_str, marker);

		parsed_string = substr(string, split_here, strlen(string)-split_here);
	}

	return strdup(parsed_string);
}

char *return_between(const char *string, const char *start, const char *stop, int type)
{
	char *temp = split_string(string, start, AFTER, type);
	return strdup(split_string(temp, stop, BEFORE, type));
}

