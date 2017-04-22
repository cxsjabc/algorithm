#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int is_prime(int n)
{
	int i;
	
	if(n < 2)
		return 0;

	for(i = 2; i <= n / 2; ++i)
		if(n % i == 0)
			return 0;
	return 1;
}

int main()
{
	int i;

	scanf("%d", &i);
	if(is_prime(i))
		printf("prime\n");
	else
		printf("not prime\n");

	return 0;
}
