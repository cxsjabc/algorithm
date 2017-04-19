#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double a, b, c;
	double p;

	scanf("%lf%lf%lf", &a, &b, &c);
	p = (a + b + c) / 2;

	printf("%.2f\n", sqrt(p * (p - a) * (p - b) * (p - c)));
	return 0;
}
