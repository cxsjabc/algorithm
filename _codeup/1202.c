#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i = 1, n = 10;
	long long s = 0;
	long long v = 1;

	while(i <= n) {
		v *= i;
		s += v;
		
		++i;
	}
	printf("%lld\n", s);
	return 0;
}
