#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, b;
	
	while(scanf("%d%d", &a, &b) == 2) {
		printf("%llu\n", (unsigned long long)a + (unsigned long long)b);
	}
	return 0;
}
