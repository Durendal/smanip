//	example_manip.c
//
//	example_manip.c defines some basic strings to use
//	in manipulations, it then proceeds to demonstrate uses of
//	the substr, strpos, strtoupper, strtolower, and str_replace
//	functions. Please note that these functions return a pointer
//	to a block of memory, if you assign the returned value to
//	a variable, please remember to free it when you are finished.

#include "smanip.h"
#include <stdio.h>
void test_func(char*, int);
int main(int argc, char *argv)
{
	printf("Starting...\n");
	char sentence[] = "This is the sentence im using to test substr";
	char sentence2[] = "THIS IS ALL CAPS ZOMG!";

	int str1 = strpos(sentence, " is");
	char *str2 = substr(sentence, strpos(sentence, " is")+1, 15, sizeof(sentence));
	char *str3 = strtolower(sentence2, sizeof(sentence2));
	
	printf("strlen: %d\n", sizeof(sentence));
	printf("starting location: %d\n", str1);
	printf("The Substring: %s\n", str2);
	printf("%s\n", str3);

	test_func(sentence, sizeof(sentence));

	//These values must be freed explicitly
	free(str2);
	free(str3);

	char *string1 = substr(sentence, strpos(sentence, " is")+1, 15, sizeof(sentence));
	char *string2 = strtolower(sentence2, sizeof(sentence2));
	char *string3 = strtoupper(sentence, sizeof(sentence));
	
	printf("%s\n%s\n%s\n", string1, string2, string3);

	printf("%s\n", str_replace(sentence, "This", "Sith"));
	//These values must be freed explicitly
	free(string1);
	free(string2);
	free(string3);


	return 0;
}

void test_func(char *str, int strleng)
{
	char *newstr = substr(str, 0, 10, strleng);
	printf("[test_func]: %s\n", newstr);
}
