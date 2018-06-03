#include "common_local.h"

int reverse_int(int n)
{
	return n % 10 * 100 + n / 10 % 10 * 10 + n / 100;
}

int main()
{
	PD(reverse_int(123));
	PD(reverse_int(900));
    return 0;
}
