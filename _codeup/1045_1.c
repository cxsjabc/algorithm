#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int main()
{
	int t;
	char s[128];
	int n;

	scanf("%d", &t);
	while(t--) {
		int i = 0;
		memset(s, 0, 128);
		scanf("%s%d", s, &n);
		while(s[i]) {
			if(s[i] == '.')
				break;
			++i;
		}
		printf("%c\n", s[i + n]);
	}

	return 0;
}
