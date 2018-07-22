#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

int gcd(int m, int n)
{
	while(n) {
		int r = m % n;
		m = n;
		n = r;
	}
	return m;
}

int lcm(int m, int n)
{
	return m * n / gcd(m, n);
}

int main()
{
	int a, b;

	INPUT2(a, b);
	printf("%d %d\n", gcd(a, b), lcm(a, b));
	return 0;
}
