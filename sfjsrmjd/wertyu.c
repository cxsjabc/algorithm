#include <stdio.h>

char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";

int main()
{
	int c;
	int i;
	while((c = getchar()) != EOF) {
		for(i = 0; s[i] && s[i] != c; ++i) ;
		if(s[i] && s[i] == c)
			printf("%c", s[i - 1]);
	}
    return 0;
}
