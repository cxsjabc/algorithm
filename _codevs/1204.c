#include <stdio.h> 

int find_substr(const char *s, const char *p)
{
	int i = 0;
	const char *ps = s, *pp = p;
	const char *ps_start;

	while(*ps) {
		ps_start = ps;
		while(*pp) {
			if(*ps != *pp) {
				ps = ps_start;
				break;
			}
			else
				++ps, ++pp;
		}
		if(*pp == '\0')
			return ps_start - s;
		pp = p;
		++ps;
	}
	return -1;
}

int main()
{
	char s[128], p[128];
	int index;

	scanf("%s%s", s, p);
	index = find_substr(s, p);
 	printf("%d\n", index + 1);	
	return 0;
}
