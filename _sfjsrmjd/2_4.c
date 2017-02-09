#include <stdio.h>
#include <time.h>

int factorial_last_6(int n)
{
	long long value = 1;
	int i = 1;

	if(n > 25)	// optimize 
		n = 25;

	for(; i <= n; ++i) {
		value *= i;
		if(value >= 1000000)
			value %= 1000000;
	}
	return value;
}

int main()
{
	int n, i;
	int fac_last_6 = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) {
		int fac_temp_last_6 = factorial_last_6(i);
		fac_last_6 += fac_temp_last_6;
		if(fac_last_6 >= 1000000)
			fac_last_6 %= 1000000;
	}

    printf("%d, time:%.4f\n", fac_last_6, (double)clock() / CLOCKS_PER_SEC);
	
    return 0;
}
