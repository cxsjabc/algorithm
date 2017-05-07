#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

// b <= a <= 10e100, so maybe needs big integer algo
int main()
{
	unsigned long long a, b;
	while(scanf("%llu%llu", &a, &b) != EOF) {
		printf("%llu\n", a - b);
	}
	return 0;
}
