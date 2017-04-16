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

int main()
{
	int m, n;

	scanf("%d%d", &m, &n);
	printf("%d\n", gcd(m, n));

	return 0;
}
