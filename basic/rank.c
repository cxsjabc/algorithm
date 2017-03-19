#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common_local.h"


void rank(int arr[], int cnt, int *rank_arr)
{
	int i, j;

	for(i = 0; i < cnt; ++i) {
		for(j = i + 1; j < cnt; ++j) {
			if(arr[j] < arr[i])
				++rank_arr[i];
			else
				++rank_arr[j];
		}
	}
	
}

int main()
{
	int arr[] = {4, 3, 9, 3, 7};
	int *rank_arr = (int *)malloc(sizeof(int) * ARR_SIZE(arr));
	memset(rank_arr, 0, sizeof(int) * ARR_SIZE(arr));
	rank(arr, ARR_SIZE(arr), rank_arr);

	print_arr(rank_arr, ARR_SIZE(arr));
	free(rank_arr);
	return 0;
}
