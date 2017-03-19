#include <stdio.h>

#include "common_local.h"

static int pow(int x, int n)
{
	if(n == 0)
		return 1;
	else if(n == 1)
		return x;
	else {
		if(n & 1)
			return pow(x * x, n / 2) * x;
		else
			return pow(x * x, n / 2);	
	}
}

static int pow1(int x, int n)
{
	int t = 1;
	int arr[33] = {0};
	int i;

	arr[0] = 1;
	arr[1] = x;

	for(i = 2; i < 33; ++i)	{
		arr[i] = arr[i - 1] * arr[i - 1];
	}	

	for(i = 1; i < 33; ++i) {
		if(n & (1 << (i - 1)))
			t *= arr[i];
	}

	return t;
}

int	is_2_power(int n)
{
	if(n == 1)
		return 1;
	return (n & (n - 1)) == 0;
}

int main()
{
	int i = 1;
	PN(pow1(2, 10));	
	PN(pow1(2, 20));	
	PN(pow1(2, 30));	

	for(; i < 100; ++i)
		if(is_2_power(i))
			printf("is_2_power:%d\n", i);
	return 0;
}
