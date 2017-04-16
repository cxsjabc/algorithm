#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int c;
	int n;

	while(scanf("%d", &c) == 1 && c > 0) {
		int sum = 0;
		while(c--) {
			scanf("%d", &n);
			sum += n;
		}
		printf("%d\n", sum);
	}
	return 0;
}
