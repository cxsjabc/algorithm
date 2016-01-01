#include <stdio.h>

#include "common.h"

void perm(int arr[], int cnt, int start, int end)
{
	int i;
	if(start == end) {
		for(i = 0; i < cnt; ++i)
			printf("%d", arr[i]);
		printf("\n");
		return;
	}

	for(i = start; i <= end; ++i) {
		swap_by_addr(&arr[start], &arr[i]);
		perm(arr, cnt, start + 1, end);	
		swap_by_addr(&arr[start], &arr[i]);
	}	
}

int main()
{
	int arr[] = {1, 2, 3, 4};	
	perm(arr, ARR_SIZE(arr), 0, ARR_SIZE(arr) - 1);
	return 0;
}
