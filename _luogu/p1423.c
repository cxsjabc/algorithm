#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int swim_steps(double dis)
{
	int step = 1;
	double d = 2;
	double s = d;

	while(s < dis) {
		d *= 0.98;		
		s += d;
		++step;
	}
	return step;
}

int main()
{
	double s;

	scanf("%lf", &s);
	printf("%d\n", swim_steps(s));
	return 0;
}
