#include "common_local.h"

int count_words1(const char *s)
{
	int state = 0; /*0: init; 1: word; 2: blank */
	int count = 0;	

	while(*s) {
		char ch = *s;

		switch(state) {
			case 0:
				if(ch == ' ') {
					state = 2;
				} else if(isalpha(ch)) {
					state = 1;
					++count;
				}
				break;

			case 1:
				if(ch == ' ')
					state = 2;
				else if(isalpha(ch)) {
					state = 1;
				}
				break;
			case 2:
				if(ch == ' ')
					state = 2;
				else if(isalpha(ch)) {
					state = 1;
					++count;
				}
				break;
			default:
				break;
		}

		++s;
	}
	return count;
}

int	count_words(const char *s)
{
	int flag = 0;
	int count = 0;

	while(*s) {
		char ch = *s;
		if(ch == ' ') {
			flag = 0;
		} else if(!flag && isalpha(ch)) {
			flag = 1;
			++count;
		}
		++s;
	}
	return count;
}

int main()
{
	char s[128];
	char *p;

	while((p = fgets(s, 128, stdin)) != NULL) {
    	printf("%d\n", count_words(s));
    	printf("%d\n", count_words1(s));
	}
    return 0;
}
