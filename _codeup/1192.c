#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i = 0;
	int sum = 0;

	do {
		sum += i;
		++i;
	} while(i <= 100);
	printf("%d\n", sum);
	return 0;
}
