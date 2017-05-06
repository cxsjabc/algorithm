#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int prime[101];
	int i = 2;
	int k;
	
	prime[0] = prime[1] = 0;
	prime[2] = 1;
	for(k = 3; k < 101; ++k)
		prime[k] = 1;

	for( ; i < 101; ) {
		int k = 2;
		for(; k <= 100 / i; ++k)
			prime[i * k] = 0;
		for(k = i + 1; k <= 100; ++k)
			if(prime[k] == 1)
				break;
		i = k;
	}

	for(k = 1; k < 101; ++k)
		if(prime[k] == 1)
			printf("%d ", k);
	printf("\n");
	return 0;
}
