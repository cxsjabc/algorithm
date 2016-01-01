#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "common.h"


int *eratosthenes(int n, int *cnt)
{
	int *arr = (int *)malloc(sizeof(int) * n);
	int temp_cnt = 0;
	int i, j;
	
	arr[0] = arr[1] = 0;
	for(i = 2; i < n; ++i) {
		arr[i] = 1;
	}

	for(i = 2; i <= (int)sqrt(n); ++i) {
		if(arr[i] == 0)
			continue;
		for(j = i + 1; j < n; ++j) {
			
			if(j % i == 0)
				arr[j] = 0;
		}
	}

	return arr;
}

int main()
{
	int *arr = eratosthenes(100, NULL);
	int i = 0;
	for(; i < 100; ++i)
		if(arr[i])
			printf("%d ", i);
	printf("\n");

	free(arr);	
	return 0;
}
