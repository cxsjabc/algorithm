#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

double get_sqrt(double d)
{
	double xn = d;
	double xn_1;

	while(1) {
		xn_1 = (xn + d / xn) / 2;
		if(fabs(xn_1 - xn) < 1e-5)
			break;
		xn = xn_1;
	}
	return xn_1;
}

int main()
{
	double x;
	scanf("%lf", &x);
	printf("%.3f\n", get_sqrt(x));
	return 0;
}
