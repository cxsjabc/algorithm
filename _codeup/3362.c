#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n;
	int i, j;
	int sum = 0;

	scanf("%d", &n);
	i = 1, j = 1;
	while(i < n) {
		sum += i * i * i;
		if(sum >= n)
			break;
		++i;
	}
	if(sum > n)
		--i;
	printf("%d\n", i);
	return 0;
}
