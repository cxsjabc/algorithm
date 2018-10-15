#include "common_local.h"

double x_n(int x, int n)
{
	if(n == 1)
		return x;
	if((n & 1) == 0) {
		double temp = x_n(x, n >> 1);
		return temp * temp;
	} else {
		double temp = x_n(x, (n - 1) >> 1);
		return temp * temp * x;
	}	
}

int main()
{
	int x, n;
	
	while(scanf("%d%d", &x, &n) == 2) {
    	printf("%f\n", x_n(x, n));
	}
    return 0;
}
