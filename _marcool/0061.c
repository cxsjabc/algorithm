#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

long	get_str_word_cnt(const char *s, long *p_word_cnt)
{
	long total_len = 0;
	int i;
	int word_flag = 0;
	long wc = 0;

	while(*s) {
		if(word_flag && *s == ' ')
			++wc, word_flag = 0;
		if(*s != ' ' && !word_flag)
			word_flag = 1;
		if(*s != ' ')
			++total_len;
		++s;
	}
	if(word_flag)
		++wc;
	if(p_word_cnt)
		*p_word_cnt = wc;
	return total_len;
}

int main()
{
	char s[1025];
	long len, cnt;

	gets(s);
	len = get_str_word_cnt(s, &cnt);
	if(cnt > 0) {
		printf("%.2lf\n", (double)len / cnt);
	}

	return 0;
}
