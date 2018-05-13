#include "common_local.h"

int str_str1(const char *s, const char *p)
{
	const char *s1 = s;
	const char *p1 = p;
	int index = 0;
	
	while(*s1) {
		int i = 0;	
		const char *s2 = s1;
		const char *p2 = p1;

		while(s2[i] != '\0' && p2[i] != '\0' && s2[i] == p2[i]) {
			++s2;
			++p2;
			++i;
		}
		if(p2[i] == '\0')
			return index;

		++s1;
		++index;
	}
	return -1;
}

int	str_str(const char *s, int s_len, const char *p, int p_len)
{
	int i;
	int j;
	for(i = 0; i < s_len - p_len; ++i) {
		j = 0;
		while(j < p_len && s[i + j] == p[j]) {
			++j;
		}
		if(j == p_len)
			return i;
	}
	return -1;
}

int main()
{
	char s[128], p[128];
	int i, j;

	while(1) {
		int res;

		memset(s, 0, 128);
		memset(p, 0, 128);
		res = scanf("%s %s", s, p);
		if(res < 2)
			return -1;

		i = str_str(s, strlen(s), p, strlen(p));
		j = str_str1(s, p);
		PD(i);
		PD(j);
		assert(i == j);
	}	

    return 0;
}
