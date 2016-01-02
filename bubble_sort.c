#include <stdio.h>

#include "common.h"

void bubble_sort(int arr[], int size)
{
	int i, j;

	for(i = size - 1; i > 0; --i) {
		for(j = 0; j < i; ++j) {
			if(arr[j + 1] < arr[j])
				swap_by_addr(&arr[j + 1], &arr[j]);
		}
	}	
}

int main()
{
	int arr[] = {3, 5, 1, 7};
	bubble_sort(arr, ARR_SIZE(arr));	
	print_arr(arr, ARR_SIZE(arr));
	return 0;
}
