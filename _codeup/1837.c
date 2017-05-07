#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double m;
	int n;
	int i = 1;
	double sum;
	double rebound;

	scanf("%lf%d", &m, &n);
	sum += m;
	++i;
	rebound = m / 2;

	while(i <= n) {
		sum += m;
		m = m / 2;
		rebound = m / 2;
		++i;
	}
	printf("%.2f %.2f\n", rebound, sum);
	return 0;
}
