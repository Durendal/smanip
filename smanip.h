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
