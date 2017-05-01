#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double a;
	double x1 = 1.0, x2;

	scanf("%lf", &a);
	do {
		x2 = x1;
		x1 = (x2 + a / x2) / 2;

		if(fabs(x1 - x2) < 1e-5)
			break;
	} while(1);

	printf("%.4f\n", x2);
	return 0;
}
