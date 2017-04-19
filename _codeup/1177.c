#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double a, b, c;
	double t;

	scanf("%lf%lf%lf", &a, &b, &c);
	if(a > b)
		t = a, a = b, b = t;
	if(c < a)
		t = c, c = b, b = a, a = t;
	if(c < b)
		t = c, c = b, b = t;

	printf("%.2f %.2f %.2f\n", a, b, c);

	return 0;
}
