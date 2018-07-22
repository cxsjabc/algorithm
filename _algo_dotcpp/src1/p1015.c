#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d%d%d", &(n1), &(n2), &(n3))

double get_result(int a, int b, int c)
{
	double r = 0;

	while(a >= 1)
		r += a, --a;
	while(b >= 1)
		r += b * b, --b;
	while(c >= 1)
		r += (1. / c), --c;
	return r;
}

int main()
{
	int a, b, c;

	INPUT3(a, b, c);

	printf("%.2f\n", get_result(a, b, c));
	return 0;
}
