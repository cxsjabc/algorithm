#include <stdio.h>

int main()
{
	char c = '0';
	printf("A:%d\n", 'A');
	printf("0:%d\n", '0');
	for(; c <= 'Z'; ++c)
	    printf("%c %d\n", c, c);
    return 0;
}
