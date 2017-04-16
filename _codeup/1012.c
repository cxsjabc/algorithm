#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double m;
	int n = 12;
	double exp_rate;
	double max_exp_rate = 0;

	scanf("%lf", &m);
	while(n--) {
		scanf("%lf", &exp_rate);
		if(exp_rate > max_exp_rate)
			max_exp_rate = exp_rate;
	}
	printf("%.2f\n", m * max_exp_rate);
	return 0;
}
