#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	unsigned long long i = 0;
	unsigned long long n = 200000;

	while(i <= n) {
		unsigned long long t = i * i;
		int d = 0;
		unsigned long long i1 = i;
		unsigned long long mod = 1;
		while(i1) {
			i1 /= 10;
			++d;
		}
		while(d--) {
			mod *= 10;
		}
		if((t - i) % mod == 0)		
			printf("%llu  ", i);

		++i;
	}
	return 0;
}
