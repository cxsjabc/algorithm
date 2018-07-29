#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

int gcd(int m, int n)
{
	while(n) {
		int temp;
		temp = m % n;
		m = n;
		n = temp;
	}
	return m;
}

int lcm(int m, int n)
{
	return m * n / gcd(m, n);
}

int main()
{
	int m, n;

	INPUT2(m, n);
	printf("%d\n%d\n", gcd(m, n), lcm(m, n));
	return 0;
}
