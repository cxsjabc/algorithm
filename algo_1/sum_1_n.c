#include "common_local.h"

int sum_1_n(int n)
{
	if(n == 1)
		return 1;
	return sum_1_n(n - 1) + n;
}

int main()
{
	PN(sum_1_n(100));
    return 0;
}
