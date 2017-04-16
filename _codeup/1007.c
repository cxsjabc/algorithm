#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int t, c;
	int n;
	
	scanf("%d", &t);
	while(t--) {
		while(scanf("%d", &c) == 1 && c > 0) {
			int sum = 0;
			while(c--) {
				scanf("%d", &n);
				sum += n;
			}
			printf("%d\n", sum);
			if(t != 0)
				printf("\n");
		}
	}
	return 0;
}
