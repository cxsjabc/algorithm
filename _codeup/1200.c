#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	char str[128];
	int cc = 0, bc = 0, nc = 0, oc = 0;
	char * s;

	gets(str);
	s = str;

	while(*s) {
		if(*s >= 'a' && *s <= 'z' || *s >= 'A' && *s <= 'Z')
			++cc;
		else if(*s == ' ')
			++bc;
		else if(*s >= '0' && *s <= '9')
			++nc;
		else
			++oc;

		++s;
	}
	printf("%d %d %d %d\n", cc, bc, nc, oc);
	return 0;
}
