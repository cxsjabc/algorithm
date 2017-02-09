#include <stdio.h>
#include <math.h>

#define PI  3.1415926

int main()
{
	double r, h;
	scanf("%lf%lf", &r, &h);
    printf("Area: %.3f\n", 2 * PI * r * r + 2 * PI * r * h);
    return 0;
}
