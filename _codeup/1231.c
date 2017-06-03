#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int encode(char c)
{
	if(c >= 'a' && c <= 'z')
		return 'a' + 'z' - c;
	if(c >= 'A' && c <= 'Z')
		return 'A' + 'Z' - c;
	return c;
}

int decode(char c)
{
	return encode(c);
}

int main()
{
	char ch[128];
	int i;
	int len;

	gets(ch);
	len = strlen(ch);
	for(i = 0; i < len; ++i)
		printf("%c", decode(ch[i]));
	printf("\n");

	return 0;
}
