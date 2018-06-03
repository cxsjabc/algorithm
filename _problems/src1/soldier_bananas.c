#include "common_local.h"

long get_need_money(long k, long n, long w)
{
	long m;

	m = w * (w + 1) / 2 * k - n;
	if(m < 0)
		m = 0;

	return m;
}

int main()
{
	long k, n, w;

	scanf("%ld%ld%ld", &k, &n, &w);

	PL(get_need_money(k, n, w));
    return 0;
}
