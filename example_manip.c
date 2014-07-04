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
void test_func(char*);
int main(int argc, char *argv)
{
	printf("Starting...\n");
	char *sentence = "This is the sentence im using to test substr";
	char sentence2[] = "THIS IS ALL CAPS ZOMG!";
	
	
	int str1 = strpos(sentence, " is");
	printf("String Position: %d\n", str1);
	char *str2 = substr(sentence, strpos(sentence, " is")+1, 15);
	printf("Substr str2: %s\n", str2);
	char *str3 = strtolower(sentence2);
	printf("lowercase: %s\n", str3);
	
	printf("starting location: %d\n", str1);
	printf("The Substring: %s\n", str2);
	printf("%s\n", str3);
	printf("%s\n", substr(str3, 10, 10));
	printf("return_between: %s\n", return_between(sentence, "the", "im", EXCL));
	test_func(sentence);

	//These values must be freed explicitly
	free(str2);
	free(str3);

	char *string1 = substr(sentence, strpos(sentence, " is")+1, 15);
	char *string2 = strtolower(sentence2);
	char *string3 = strtoupper(sentence);
	
	printf("%s\n%s\n%s\n", string1, string2, string3);

	printf("%s\n", str_replace(sentence, "This", "Sith"));
	//These values must be freed explicitly
	free(string1);
	free(string2);
	free(string3);

	printf("With Tags: %s Without Tags: %s\n", return_between("1234567890", "3", "7", INCL), return_between("1234567890", "3", "7", EXCL));
	


	return 0;
}

void test_func(char *str)
{
	char *newstr = substr(str, 0, 10);
	printf("[test_func]: %s\n", newstr);
	newstr = str_replace(newstr, "is", "was");
	printf("[test_func]: %s\n", newstr);
}
