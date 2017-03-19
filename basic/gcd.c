#include <stdio.h>

#define PN(n)	printf(#n "is %d\n", (n));

int gcd(int a, int b)
{
	int ret = a % b; // bugs: if b == 0
	while(ret != 0)
	{
		a = b;
		b = ret;
		ret = a % b; 
	}
	return b;
}

int gcd1(int a, int b)
{
	int r;
	while(b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main()
{
	PN(gcd(12, 8));	
	PN(gcd1(12, 8));	
	PN(gcd1(12, 4));	
	return 0;
}
