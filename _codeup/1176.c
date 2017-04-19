#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double a, b;

	scanf("%lf%lf", &a, &b);
	if(a > b)
		printf("%.2f %.2f\n", b, a);
	else
		printf("%.2f %.2f\n", a, b);

	return 0;
}
