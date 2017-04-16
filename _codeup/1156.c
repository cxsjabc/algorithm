#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double x, y;
	int a, b;

	scanf("%d%d%lf%lf", &a, &b, &x, &y);
	printf("%.6f\n", (float)(a + b) / 2 + (int)x % (int)y); 

	return 0;
}
