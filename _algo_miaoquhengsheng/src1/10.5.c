#include "common_local.h"

char *strcat1(char *s1, char *s2)
{
	char *p;
	char *r;

	p = (char *)malloc(strlen(s1) + strlen(s2) + 1);
	if(!p)
		return NULL;
	r = p;

	while((*p++ = *s1++) != '\0')
		;
	--p;
	while((*p++ = *s2++) != '\0')
		;
	--p;

	*p = '\0';
	return r;
}

int main()
{
	char *p;
	char s1[128], s2[128];

	scanf("%s%s", s1, s2);
	printf("s1:|%s|, s2:|%s|\n", s1, s2);
	p = strcat1(s1, s2);
	PS(p);
    return 0;
}
