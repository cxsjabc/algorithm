#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

double f(double x)
{
	return 2 * pow(x, 3) - 4 * x * x + 3 * x - 6;
}

double f1(double x)
{
	return 6 * pow(x, 2) - 8 * x + 3;
}	

int main()
{
	double x = 1.5;
	double x0;

	while(1) {
		x0 = x - f(x) / f1(x);
		if(f(x0) < 1e-5 || fabs(x - x0) < 1e-5)
			break;
		x = x0; 
	}
	printf("%.4f\n", x);
	return 0;
}
