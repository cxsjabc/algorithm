#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n;
	int a, b;
	
	scanf("%d", &n);
	while(n-- > 0) {
		scanf("%d%d", &a, &b);
		printf("%llu\n", (unsigned long long)a + (unsigned long long)b);
	}
	return 0;
}
