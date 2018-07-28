#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n;	
	
	while(scanf("%d", &n) == 1) {
		long long sum = 0;
		while(n--) {
			int a;
			
			scanf("%d", &a);
			sum += a;
		}
		printf("%lld\n", sum);
	}

	return 0;
}
