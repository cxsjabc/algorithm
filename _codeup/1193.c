#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int j = 100, k = 200;
	int i;

	for(i = j; i <= k; ++i)
		if(i % 3 != 0)
			printf("%d ", i);

	printf("\n");
	return 0;
}
