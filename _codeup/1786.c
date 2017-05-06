#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

unsigned long long fac(int n)
{
	unsigned long long r = 1;
	int i = 2;

	while(i <= n)
		r *= i, ++i;
	return r;
}

int main()
{
	int n;
	
	while(scanf("%d", &n) != EOF) {
		printf("%llu\n", fac(n));
	}
	return 0;
}
