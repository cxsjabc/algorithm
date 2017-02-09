#include "common.h"

int main()
{
	unsigned int a; // bugs if int a when input is negative integer
	while(1) {
		char s[32];
		int i = 0;
		scanf("%d", &a);
		if(a == 0)
			break;
		
		while(a != 0) {	// bugs if: a > 0 when a is negative integer
			s[i++] = a % 2 + '0';
			a /= 2;
		}
		i--;
		while(i >= 0) {
			putchar(s[i--]);
		}
		putchar('\n');
	}
    return 0;
}
