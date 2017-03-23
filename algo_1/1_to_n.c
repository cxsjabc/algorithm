#include "common_local.h"

int	get_1_to_n_bits(int bits)
{
	int i = 0;
	int num = 1;
	while(i++ < bits)
		num *= 10;
	return num - 1;
}

int main()
{
	PN(get_1_to_n_bits(5));
    return 0;
}
