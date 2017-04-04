#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n, curr, min = 1000;
	int sum = 0;
	int i;

	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", &curr);
		if(curr < min)
			min = curr;
		sum += curr;
	}
	printf("%d\n", sum - min);
	return 0;
}
