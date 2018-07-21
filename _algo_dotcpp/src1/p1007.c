#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

long long f(long long x)
{
	if(x < 1)
		return x;
	else if(x < 10)
		return 2 * x - 1;
	else
		return 3 * x - 11;
}

int main()
{
	long long x;

	scanf("%lld", &x);
	printf("%lld\n", f(x));
	return 0;
}
