#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void subsets(int arr[], int size, int start, int end, int *includes)
{
	int i;
	if(start == end) {
		printf("{");
		for(i = 0; i < size; ++i)
			if(includes[i])
				printf("%d", arr[i]);	
		printf("}");
		printf("\n");
		return;
	}

	includes[start] = 0;
	subsets(arr, size, start + 1, end, includes);
	includes[start] = 1;
	subsets(arr, size, start + 1, end, includes);
}

int main()
{
	int arr[] = {1, 2, 3, 4};
	int *includes;

	includes = (int *)malloc(sizeof(int) * ARR_SIZE(arr));
	subsets(arr, ARR_SIZE(arr), 0, ARR_SIZE(arr), includes);

	free(includes);
	
	return 0;
}
