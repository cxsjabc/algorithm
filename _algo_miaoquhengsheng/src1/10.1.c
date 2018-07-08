#include "common_local.h"

void ignore_mul_blanks()
{
	int c;
	int last_blank = 0;

	while((c = getchar()) != EOF) {
		if(c != ' ') {
			putchar(c);
			last_blank = 0;
		}
		else {
			if(!last_blank) {
				putchar(c);
				last_blank = 1;
			}
		}
	}
}

int main()
{
	ignore_mul_blanks();
    return 0;
}
