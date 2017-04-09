#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, b;
	int max;

	scanf("%d,%d", &a, &b);
	max = (a > b) ? a : b;
	printf("max=%d\n", max);

	return 0;
}
