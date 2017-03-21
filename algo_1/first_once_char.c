#include "common_local.h"

char 	get_first_once_char(const char *s)
{
	unsigned int char_table[1 << 8] = {0};
	int i = 0;

	while(*s) {
		char_table[(int)*s]++;
		++s;
	} 

	while(i < (1 << 8)) {
		if(char_table[i] == 1)
			return (char)i;
		++i;
	}
	return 0;	// not a meaningful char
}

int main()
{
	char s[128];

	while(scanf("%s", s) > 0) {
		char ch = get_first_once_char(s);
		if(ch != 0)
			printf("Find char:%c\n", ch);		
	}
    return 0;
}
