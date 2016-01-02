#include <stdio.h>

#include "common.h"

int max_sub(int arr[], int size)
{
	int i, j;
	int max = 0;
	i = j = 0;

	while(j < size) {
		if(arr[j] - arr[i] > max)
			max = arr[j] - arr[i];
		if(arr[j] < arr[i])
			i = j;
		++j;
	}
	return max;
}

int main()
{
	int arr[] = {8, 3, 10, 1, 100, 200};
	PN(max_sub(arr, ARR_SIZE(arr)));
	return 0;
}
