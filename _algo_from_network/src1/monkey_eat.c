#include "common_local.h"

int	get_peach_cnt()
{
	int i = 9;
	int sum = 1;

	while(i > 0) {
		sum = (sum + 1) * 2;	
		--i;
	}
	return sum;
}

int sum_peach(int day)
{
	if(day == 10)
		return 1;

	return 2 * sum_peach(day + 1) + 2;
}

int main()
{
	PD(get_peach_cnt());
	PD(sum_peach(1));
	PD(sum_peach(INT_MAX));
    return 0;
}
