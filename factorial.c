#include <stdio.h>

#include "common.h"

int factorial(int n)
{
	if(n == 0 || n == 1)
		return 1;
	else 
		return n * factorial(n - 1);
}

int factorial1(int n)
{
	int ret = 1;
	int i = 1;

	while(i <= n) {
		ret *= i;
		++i;
	}
	return ret;
}

int main()
{
	PN(factorial(5));	
	PN(factorial1(5));	
	return 0;
}
