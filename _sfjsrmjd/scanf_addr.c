#include <stdio.h>

int main()
{
	char s[12];
	scanf("%s", s);
    printf("%s\n", s);

	scanf("%s", &s); // a warning, but running ok
    printf("%s\n", s);
    return 0;
}
