#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

#define INPUT_D(n)		scanf("%lf", &(n))

double get_result(double n)
{
	if(n < 1)
		return n;
	else if(n < 10)
		return 2 * n - 1;
	else
		return 3 * n - 11;
}

int main()
{
	double n;

	INPUT_D(n);	
	printf("%.2f\n", get_result(n));
	return 0;
}
