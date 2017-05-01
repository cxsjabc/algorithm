#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int fab[40] = {1, 1};
	int n;
	int i;
	int k = 2;

	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		printf("%12d", fab[i]);
		if((i + 1) % 5 == 0)
			printf("\n");
		if(k < n)
			fab[k] = fab[k - 1] + fab[k - 2], ++k;
	}
	printf("\n");

	return 0;
}
