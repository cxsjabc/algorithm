#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n = 100;
	int i = 1;
	int sum = 0;

	while(i <= 100)
		sum += i, ++i;

	printf("%d\n", sum);
	return 0;
}
