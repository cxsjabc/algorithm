#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double sum = 0;
	int n = 100;
	int flag = 1;
	int i = 1;

	while(i <= n) {
		sum += (1. / i * flag);	
	
		flag = -flag;
		++i;
	}

	printf("%.8f\n", sum);
	return 0;
}
