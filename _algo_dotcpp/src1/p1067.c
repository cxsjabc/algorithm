#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

double get_result(double x)
{
	if(x < 0)
		return fabs(x);
	else if(x < 2)
		return sqrt(x + 1);
	else if(x < 4)
		return pow(x + 2, 5);
	else
		return 2 * x + 5;
}

int main()
{
	double d;

	scanf("%lf", &d);
	printf("%.2f\n", get_result(d));
	return 0;
}
