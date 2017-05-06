#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <ctype.h> 

int get_word_cnt(const char *s)
{
	int c = 0;
	int we = 1;

	while(*s) {
		if(we && isalnum(*s) && *s != ' ' && *s != '\n')
			++c, ++s, we = 0;
		else if(!we && (*s == ' ' || *s == '\n' || !isalnum(*s)))
			we = 1, ++s;
		else
			++s;
	}
	return c;
}

int main()
{
	char s[128];
	gets(s);

	printf("%d\n", get_word_cnt(s));
	return 0;
}
