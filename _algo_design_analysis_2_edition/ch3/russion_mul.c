#include "common_local.h"

int russion_mul(int a, int b)
{
	int s = 0;
	int extra = 0;

	if(a == 0 || b == 0)
		return 0;

	while(a > 1) {
		if((a & 1) == 0) {
			a = a >> 1;
			b = b << 1;
		} else {
			extra += b;
			a >>= 1;
			b <<= 1;
		}
	}
	return b + extra;
}

int main()
{
	int a, b;
	int s;
	
	while(scanf("%d%d", &a, &b) == 2) {
		TS(1000000)
		s = russion_mul(a, b);	// this is slower than below
		TE
		TS(1000000)
		s = a * b;
		TE
	}
    return 0;
}
