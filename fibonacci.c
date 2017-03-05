#include <stdio.h>

#include "common_local.h"


int fibonacci(int n)
{
	if(n == 0 || n == 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacci1(int n)
{
	int n0 = 1;
	int n1 = 1;
	int i = 2;
	int ret;

	while(i <= n) {
		ret = n0 + n1;
		n0 = n1;
		n1 = ret;
		++i;		
	}
	return ret; 
}

int main()
{
	PN(fibonacci(8));	
	PN(fibonacci1(8));	
	return 0;
}
