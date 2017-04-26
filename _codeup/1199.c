#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int gcd(int m, int n)
{
	int mod;

	if(n == 0)
		return m;

	mod = m % n;
	m = n;
	n = mod;

	return gcd(m, n);
}

int lmd(int m, int n)
{
	int g = gcd(m, n);
	return m * n / g;
}

int main()
{
	int m, n;

	scanf("%d%d", &m, &n);
	printf("%d %d\n", gcd(m, n), lmd(m, n));

	return 0;
}
