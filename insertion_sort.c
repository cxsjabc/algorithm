#include <stdio.h>

#include "common.h"

void insertion_sort(int arr[], int size)
{
	int i, j;

	for(i = 1; i < size; ++i) {
		int temp = arr[i];
		for(j = i - 1; j >= 0 && temp < arr[j]; --j) 
			arr[j + 1] = arr[j];
		arr[j + 1] = temp;
	}
}

int main()
{
	int arr[] = {3, 15, -3, 1, 5, 100, 27, 250};
	//int arr[] = {3, 15, -3};
	insertion_sort(arr, ARR_SIZE(arr));
	print_arr(arr, ARR_SIZE(arr));	
	return 0;
}
