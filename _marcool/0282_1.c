#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int is_fit_triangle(double a, double b, double c)
{
	return (a + b > c) && (b + c > a) && (a + c > b);	
}

int main()
{
	double a, b, c;
	int ret;
	
	scanf("%lf%lf%lf", &a, &b, &c);
	ret = is_fit_triangle(a, b, c);
	printf("%s", ret == 1 ? "yes" : "no");
	return 0;
}
