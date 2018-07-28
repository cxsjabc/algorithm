#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a;
	int n;	

	while(scanf("%d", &n) == 1 && n > 0) {
		long long sum = 0;
		while(n--) {
			scanf("%d", &a);
			sum += a;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
