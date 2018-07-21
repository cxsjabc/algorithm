#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int get_result(int n)
{
	if(n <= 100000)
		return n * 10 / 100;
	else if(n <= 200000)
		return 10000 + (n - 100000) * 15 / 200;
	else if(n <= 400000)
		return 10000 + 7500 + (n - 200000) * 5 / 100;
	else if(n <= 600000)
		return 10000 + 7500 + 10000 + (n - 400000) * 3 / 100;
	else if(n <= 1000000)
		return 10000 + 7500 + 10000 + 6000 + (n - 600000) * 3 / 200;
	else if(n > 1000000)
		return 10000 + 7500 + 10000 + 6000 + 6000 + (n - 1000000) / 100;
}
	

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d\n", get_result(n));
	return 0;
}
