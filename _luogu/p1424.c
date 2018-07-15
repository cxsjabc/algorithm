#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

long	get_swing_days(long x, long n)
{
	long remain, remain_week, extra;

	if(n + x <= 8) {
		if(x <= 5)
			return x + n - 1 > 5 ? 6 - x : n;
		else
			return 0;
	}
	remain = n - (8 - x);
	remain_week = remain / 7;
	extra = remain - remain_week * 7;
	if(extra > 5)
		extra = 5;
	if(x < 6)
		extra += (6 - x);

	return extra + remain_week * 5;
}

unsigned long long cal_swing_distance(long x, long n)
{
	long days;

	days = get_swing_days(x, n);
	return 250 * days;
}

int main()
{
	long x, n;

	scanf("%ld%ld", &x, &n);
	printf("%llu\n", cal_swing_distance(x, n));
	return 0;
}
