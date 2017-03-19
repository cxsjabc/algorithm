#include "common_local.h"

int  is_ugly(int n)
{
	if(n == 1)
		return 1;
	while(n % 2 == 0)
		n /= 2;
	while(n % 3 == 0)
		n /= 3;
	while(n % 5 == 0)
		n /= 5;

	return n == 1;
}

int main()
{
	int i = 1;
	int cnt;
	int next_index = 1;
	int *ugly_nums;
	int *ugly_x2, *ugly_x3, *ugly_x5;

	scanf("%d", &cnt);		

	ugly_nums = (int *)malloc(sizeof(int) * cnt);
	ASSERT(ugly_nums);
	ugly_nums[0] = 1;
	ugly_x2 = ugly_x3 = ugly_x5 = ugly_nums;
	
	while(i < cnt) {
		int min = MIN3(*ugly_x2 * 2, *ugly_x3 * 3, *ugly_x5 * 5);
		ugly_nums[next_index] = min;

		while(*ugly_x2 * 2 <= min)
			++ugly_x2;
		while(*ugly_x3 * 3 <= min)
			++ugly_x3;
		while(*ugly_x5 * 5 <= min)
			++ugly_x5;

		++next_index;
		++i;	
	}

	int ugly = ugly_nums[next_index - 1];	
	printf("The %d ugly number is: %d\n", cnt, ugly);
	free(ugly_nums);
    return 0;
}
