#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n;
	int t = 9;
	int max;

	scanf("%d", &max);
	while(t--) {
		scanf("%d", &n);
		if(n > max)
			max = n;
	}

	printf("%d\n", max);
	return 0;
}
