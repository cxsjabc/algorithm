#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n = 4;
	int i;

	for(i = 1; i <= n; ++i) {
		int j = n - i;
		int k;
		for(k = 1; k <= j; ++k)
			printf(" ");
		for(k = 1; k <= 2 * i - 1; ++k)
			printf("*");
		printf("\n");
	}

	for(i = 1; i <= n - 1; ++i) {
		int j = i;
		int k;
		for(k = 1; k <= j; ++k)
			printf(" ");
		for(k = 1; k <= 2 * (n - j) - 1; ++k)
			printf("*");
		printf("\n");
	}
	return 0;
}
