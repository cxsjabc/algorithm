#include <stdio.h>

#include "common_local.h"

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

