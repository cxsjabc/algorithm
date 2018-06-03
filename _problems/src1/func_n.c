#include "common_local.h"

long f_n(long n)
{
	return (n % 2 == 0) ? n / 2 : (n - 1) / 2 - n;
}

int main()
{
	long n;

	while(scanf("%ld", &n) == 1) {
		PL(f_n(n));
	}
    return 0;
}
