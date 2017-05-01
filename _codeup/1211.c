#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

double f(double x)
{
	return 2 * pow(x, 3) - 4 * x * x + 3 * x - 6;
}

int main()
{
	double x1 = -10, x2 = 10;
	double x;

	do {
		x = (x1 + x2) / 2;
		if(fabs(f(x)) < 1e-6)
			break;
		else if(f(x1) * f(x) < 0)
			x2 = x;
		else if(f(x) * f(x2) < 0)
			x1 = x;
	} while(1);

	printf("%.4f\n", x);
	return 0;
}
