#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 


// i don't know why it can't pass the online judge!
int main()
{
	int a, b;
	long long sum;

	scanf("%d%d", &a, &b);
	sum = (long long)a + (long long)b;
	printf("%lld\n", sum);
	return 0;
}
