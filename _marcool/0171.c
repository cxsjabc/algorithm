#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	char s[128];

	gets(s);
	printf("%s happy birthday!\n", s);
	return 0;
}
