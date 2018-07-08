#include "common_local.h"

int sum(int n)
{
	if(n == 1)
		return 1;

	return n + sum(n - 1);
}

int sum1(int sum, int n)
{
	if(n == 1)
		return sum + 1;
	
	return sum1(sum + n, n - 1);
}

int main()
{
    printf("%d\n", sum(100));
    printf("%d\n", sum1(0, 100));
    return 0;
}
