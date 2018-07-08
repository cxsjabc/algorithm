#include "common_local.h"

void reverse(char *s)
{
	int len;
	int i;

	len = strlen(s);
	for(i = 0; i < len / 2; ++i) {
		char ch = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = ch;
	}
	printf("%s\n", s);
}

void reverse1(char *s)
{
	int len;
	int i;

	len = strlen(s) - 1;
	i = 0;

	while(i < len) {
		char ch = s[i];
		s[i] = s[len];
		s[len] = ch;

		++i;
		--len;
	}
	printf("%s\n", s);
}
int main()
{
	char s[128];

	scanf("%s", s);
	reverse1(s);
    return 0;
}
