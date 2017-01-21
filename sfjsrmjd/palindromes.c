#include "common.h"
#include <stdio.h>
#include <string.h>

char mirror[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

int main()
{
	char s[32];
	int i;
	int len;
	int m = 1, p = 1;
	scanf("%s", s);

	len = strlen(s);
	for(i = 0; i < (len + 1) / 2; ++i) {
		if(s[i] != s[len - 1 - i]) {
			p = 0;
			log_d("p=0:i:%d, s[i]:%c, s[len - 1 - i]:%c\n", i, s[i], s[len - 1 - i]);
		}
		if(s[i] < 'A') {
			if(mirror[s[i] - '1' + 26] != s[len - 1 - i]) {
				m = 0;
				log_d("m=0:i:%d, s[i]:%c, s[len - 1 - i]:%c, mirror[s[i] - '0' + 26]:%c\n", i, s[i], s[len - 1 - i], mirror[s[i] - '1' + 26]);
			}
		} else {
			if(mirror[s[i] - 'A'] != s[len - 1 - i]) {
				m = 0;
				log_d("m=0:i:%d, s[i]:%c, s[len - 1 - i]:%c, mirror[s[i] - 'A']:%c\n", i, s[i], s[len - 1 - i], mirror[s[i] - 'A']);
			}
		}
	}
	
	if(m && p)
    	printf("%s is a mirrored palindrome!\n", s);
	else if(m)
    	printf("%s is a mirrored!\n", s);
	else if(p)
    	printf("%s is a palindrome!\n", s);
	else
    	printf("%s is a normal string!\n", s);

    return 0;
}
