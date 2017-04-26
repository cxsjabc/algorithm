#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

void encrypt(char *s)
{
	while(*s) {
		if(*s >= 'A' && *s <= 'Z') {
			*s += 4;
			if(*s > 'Z')
				*s = (*s - 'Z' + 3) + 'A';

		}
		if(*s >= 'a' && *s <= 'z') {
			*s += 4;
			if(*s > 'z')
				*s = (*s - 'z' + 3) + 'a';
		}

		++s;
	}
}

int main()
{
	char s[128];

	gets(s);
	encrypt(s);
	printf("%s\n", s);
	return 0;
}
