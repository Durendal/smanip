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
#define EXCL 1
#define INCL 0
#define BEFORE 1
#define AFTER 0

 char *strtolower(const char *str, int);
 char *strtoupper(const char *str, int);
 int strpos(char *haystack, char *needle);
 char *substr(const char *str, int start, int len);
 char *str_replace (const char *, const char *, const char *);
 char *split_string(const char *, const char *, int, int);
 char *return_between(const char *, const char *, const char *, int);

#endif
