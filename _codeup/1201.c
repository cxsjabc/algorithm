#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, n;
	long long s = 0;
	int i = 1;
	int v;

	scanf("%d%d", &a, &n);
	v = a;
	while(i <= n) {
		s += v;
		v = v * 10 + a;
		//printf("i:%d, a:%d, %lld\n", i, a, s);
		++i;
	}	

	printf("%lld\n", s);
	return 0;
}
