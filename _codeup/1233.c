#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int strcmp_1(const char *s1, const char *s2)
{
	while(*s1 && *s2) {
		if(*s1 == *s2) {
			++s1, ++s2;
			continue;
		} else {
			return *s1 - *s2;
		}
	}
	return *s1 - *s2;
}

int main()
{
	char s1[128], s2[128];
	int ret;

	gets(s1);
	gets(s2);
	ret = strcmp_1(s1, s2);
	printf("%d\n", ret);
	return 0;
}
