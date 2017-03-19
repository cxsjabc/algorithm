#include <stdio.h>

#include "common_local.h"


void selection_sort(int arr[], int size)
{
	int i = size - 1;
	int temp_max_index;

	for(; i >= 0; --i) {
		temp_max_index = max_in_arr(arr, 0, i);
		swap_by_addr(&arr[i], &arr[temp_max_index]);
	}	
}

int main()
{
	int arr[] = {34, 0, 56, -4, 3, 100, 54};	
	selection_sort(arr, ARR_SIZE(arr));
	print_arr(arr, ARR_SIZE(arr));
	return 0;
}
