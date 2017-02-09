#include "common.h"

int str_1_cnt(const char *s)
{
	int cnt = 0;
	while(*s) {
		if(*s == '1')
			++cnt;
		++s;
	}
	return cnt;
}

int main()
{
	char s[128];
	while(1) {
		scanf("%s", s);
		if(s[0] == 'q')
			break;
		int cnt = str_1_cnt(s);
    	printf("1_cnt of %s is %d\n", s, cnt);
	}
    return 0;
}
