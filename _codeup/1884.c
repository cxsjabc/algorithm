#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int is_in_out_circle(double x, double y)
{
	double dis;
	dis = sqrt(x * x + y * y);
	if(dis > 4.5)
		return 1;
	else if(fabs(dis - 4.5) < 1e-15)
		return 0;
	else
		return -1;
}

int main()
{
	double x, y;
	int ret;

	scanf("%lf%lf", &x, &y);
	ret = is_in_out_circle(x, y);
	if(ret == 0)
		printf("on\n");
	else if(ret == 1)
		printf("out\n");
	else if(ret == -1)
		printf("in\n");
	return 0;
}
