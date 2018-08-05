#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

double get_result(double d)
{
	double x1 = d / 2, x2 = d;

	while(fabs(x1 - x2) >= 0.00001) {
		double temp = x2;
		x2 = (x1 + d / x1) / 2;
		x1 = temp;
	}
	return x2;
}

int main()
{
	double d;

	scanf("%lf", &d);
	printf("%.3f\n", get_result(d));
	return 0;
}
