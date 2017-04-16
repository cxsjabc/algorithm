#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int t;

	scanf("%d", &t);
	while(t--) {
		int n, k;
		int s[1000];
		int i;
		int c = 0;
	
		scanf("%d%d", &n, &k);
		for(i = 0; i < n; ++i)
			scanf("%d", &s[i]);		
		
		for(i = 0; i < n; ++i) {
			if(i != k - 1 && s[i] > s[k - 1])
				++c;		
		}

		printf("%d\n", c);
	}
	return 0;
}
