#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n, m;
	long long h;
	
	scanf("%d%d", &n, &m);
	h = n * (1 << (m - 1));

	printf("%lld\n", h);
	return 0;
}
