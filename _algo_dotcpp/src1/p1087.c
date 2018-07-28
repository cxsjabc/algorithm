#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, b;
	
	while(scanf("%d%d", &a, &b) == 2) {
		if(a == 0 && b == 0)
			break;
		printf("%lld\n", (long long)a + (long long)b);
	}
	return 0;
}
