#define LOG_LEVEL 10

#include "common_local.h"

#define FORCE_TEST 1

const char *test_str = "abcabcabcabc";

int calc_period(const char *s)
{
	int len = strlen(s);
	int i, j;
	for(i = 1; i <= (len + 1) / 2; ++i) {	
	  	for(j = 0; j < len; ++j) {
			log_v("i:%d, j:%d, s[j]:%c, s[j %% i]:%c\n", i, j, s[j], s[j % i]);
	  		if(s[j] != s[j % i])
				break;
		}
		if(j == len)
			return i;
	}
	return -1;
}

int main()
{
	char s[81];
	#if !FORCE_TEST
		scanf("%s", s);
	#else 
		s[0] = '\0';
		strcpy(s, test_str);
	#endif
	
	int period;
	period = calc_period(s);

	if(period != -1)
		printf("period:%d\n", period);
	else
		printf("period:-1\n");
    return 0;
}
