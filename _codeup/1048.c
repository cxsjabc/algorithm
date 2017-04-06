#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
// Not right!
int main()
{
	int t;
	char s[1024];	

	scanf("%d", &t);
	while(t--) {
		int i = 0, j = 0;
		int k;
		scanf("%s", s);
		while(1) {
			if(s[j] == '\0')
				break;
			while(s[j] && s[j] != ' ') {
				++j;
			}
			for(k = j - 1; k >= i; --k)
				printf("%c", s[k]);
			printf(" ");
			i = j + 1, j += 1;
			while(s[j] == ' ')
				printf(" "), ++i, ++j;
		}
		for(k = j - 1; k >= i; --k)
			printf("%c", s[k]);
	}

	return 0;
}
