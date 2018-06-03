#include "common_local.h"

double get_lemon_percent()
{
	long n;
	long i = 0;
	double lemon, lemon_total = 0;

	scanf("%ld", &n);
	while(i < n) {
		scanf("%lf", &lemon);
		lemon_total += lemon;
		++i;
	}
	printf("%.12f\n", lemon_total / n);
	return lemon_total / n;
}

int main()
{
	get_lemon_percent();	
    return 0;
}
