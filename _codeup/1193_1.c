#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int j = 100, k = 200;
	int i;

	for(i = j; i <= k - 1; i += 3) {
		printf("%d %d ", i, i + 1);
	}

	printf("\n");
	return 0;
}
