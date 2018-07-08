#include "common_local.h"

void print_chars(char *s, char *e)
{
	if(s < e) {
		printf("%c%c", *e - 32, *s);
		print_chars(s + 1, e - 1);
		printf("%c%c", *s - 32, *e);
	}
	else
		printf("%c%c", *s - 32, *s);
}

int main()
{
	char s[128];

	scanf("%s", s);
	print_chars(s, s + strlen(s) - 1);
    return 0;
}
