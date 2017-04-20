#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double p, w;
	int s;
	double c;

	scanf("%lf%lf%d", &p, &w, &s);
	if(s < 250)
		c = p * w * s;
	else if(s < 500)
		c = p * w * s * (1 - 0.02);
	else if(s < 1000)
		c = p * w * s * (1 - 0.05);
	else if(s < 2000)
		c = p * w * s * (1 - 0.08);
	else if(s < 3000)
		c = p * w * s * (1 - 0.1);
	else
		c = p * w * s * (1 - 0.15);

	printf("%.4f\n", c);

	return 0;
}
