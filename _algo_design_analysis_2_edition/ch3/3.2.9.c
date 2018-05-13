#include "common_local.h"

int	a_begin_b_end(const char *s)
{
	int sum = 0;
	int a_cnt = 0;
	
	while(*s) {
		if(*s == 'A')
			++a_cnt;
		else if(*s == 'B')
			sum += a_cnt;

		++s;
	}
	return sum;
}

int main()
{
	char s[128];

	while(1) {
		memset(s, 0, 128);
		scanf("%s", s);
		PD(a_begin_b_end(s));
	}
    return 0;
}
