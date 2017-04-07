#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
// Not right!
int main()
{
	int t;
	char s[1024];	

	scanf("%d", &t);
	getchar();

	while(t--) {
		int i = 0, j = 0;
		int k;
	
		gets(s);
		while(1) {
			while(s[j] && s[j] != ' ') {
				++j;
			}
			for(k = j - 1; k >= i; --k)
				printf("%c", s[k]);
			while(s[j] && s[j] == ' ') {
				printf(" ");
				++j;
			}
			if(s[j] == '\0')
				break;
			i = j;
		}
		printf("\n");
	}

	return 0;
}
