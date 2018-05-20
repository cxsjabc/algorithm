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

int a_n_2(int a, int n)
{
	int s, t;

	if(n == 0)
		return 1;
	if(n == 1)
		return a;

	if(n % 2 == 0) {
		t = a_n_2(a, n / 2);
		s = t * t;
		return s;
	} else {
		t = a_n_2(a, (n - 1) / 2);
		s = t * t * a;
		return s;
	}
}

int main()
{
	PD(a_n(2, 4));
	PD(a_n_1(2, 4));
	PD(a_n_2(2, 4));
    return 0;
}
