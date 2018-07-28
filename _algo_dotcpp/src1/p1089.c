#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n;	

	scanf("%d", &n);

	while(n--) {
		int n1;
		long long sum = 0;

		scanf("%d", &n1);
		while(n1--) {
			int a;
			
			scanf("%d", &a);
			sum += a;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
