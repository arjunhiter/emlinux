#include <stdio.h>
#include <string.h>

void main311(void)
{ 
	char string[10];
	char *str1 = "abcdefghi";
	strcpy(string, str1);
	printf("%s\n", string);

	char destination[25];
	char *blank = " ", *c = "C++", *Borland = "Borland";
	strcpy(destination, Borland);
	strcat(destination, blank);
	strcat(destination, c);
	printf("%s\n", destination);

	char *buf1 = "aaa", *buf2 = "bbb", *buf3 = "ccc";
	int ptr;
	ptr = strcmp(buf2, buf1);
	if (ptr > 0)
		printf("buffer 2 is greater than buffer 1\n");
	else
		printf("buffer 2 is less than buffer 1\n");
	ptr = strcmp(buf2, buf3);
	if (ptr > 0)
		printf("buffer 2 is greater than buffer 3\n");
	else
		printf("buffer 2 is less than buffer 3\n");
	
} 
