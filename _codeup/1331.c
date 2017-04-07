#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, b;
	long long sum;

	scanf("%d%d", &a, &b);
	sum = (long long)a + (long long)b;
	printf("%lld\n", sum);
	return 0;
}
