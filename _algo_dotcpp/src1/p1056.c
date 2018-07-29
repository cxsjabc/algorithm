#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

double get_result(double f)
{
	return 5 * (f - 32) / 9;
}

int main()
{
	double f;

	scanf("%lf", &f);
	printf("%.2f\n", get_result(f));
	return 0;
}
