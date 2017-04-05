#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i = 0;
	double sum = 0;
	double s;

	while(i < 12) {
		scanf("%lf", &s);
		sum += s;
		++i;
	}
	printf("￥%.2f\n", sum / 12);
	return 0;
}
