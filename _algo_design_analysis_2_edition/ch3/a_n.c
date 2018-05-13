#include "common_local.h"

int a_n(int a, int n)
{
	int i = 0;
	int r = 1;

	while(i < n) {
		r *= a;
		++i;
	}

	return r;
	
}

int a_n_1(int a, int n)
{
	return pow(a, n);	
}


int main()
{
	PD(a_n(2, 4));
	PD(a_n_1(2, 4));
    return 0;
}
