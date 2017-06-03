#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define EP		1e-6

double f(double x)
{
	return x * x * x - 5 * x * x + 16 * x - 80;
}

int main()
{
	double x1, x2;
	double x;
	scanf("%lf%lf", &x1, &x2);
	
	while(1) {
		x = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
		if(fabs(f(x)) < EP)
			break;	
		if(f(x) * f(x1) > 0)
			x1 = x;
		else if(f(x) * f(x2) > 0)
			x2 = x;
	} 
	printf("%.4f\n", x);
	return 0;
}
