#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int main()
{
	char s[] = "I am a program";
	int size;
	int i;

	size = strlen(s);
	for(i = 0; i < size; ++i)
		putchar(s[i]);

	printf("\n");
	return 0;
}
