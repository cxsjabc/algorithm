#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define PI	3.1415926

int main()
{
	double r, h;

	scanf("%lf%lf", &r, &h);

	printf("%.2f %.2f %.2f %.2f %.2f\n", 2 * PI * r, PI * r * r, PI * r * r * h,
			4 * PI * r * r, (4. / 3) * PI * r * r * r);
	return 0;
}
