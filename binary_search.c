#include <stdio.h>
#include "common.h"


int binary_search(int arr[], int cnt, int value)
{
	int low, high;
	int middle;

	low = 0;
	high = cnt - 1;

	while(low <= high) {
		middle = (low + high) / 2;	

		if(arr[middle] == value)
			return middle;
		else if(arr[middle] > value) 
			high = middle - 1;
		else
			low = middle + 1;
	}
	return -1;
}

int main()
{	
	int arr[] = {10, 20, 30, 40, 50, 60};
	int arr1[] = {20, 30, 40, 50, 60};
	int index = -1;
	int size = sizeof(arr) / sizeof(arr[0]);

	index = binary_search(arr, size, 50);
	PN(index);

	index = -1;
	index = binary_search(arr1, size, 50);
	PN(index);

	index = -1;
	index = binary_search(arr1, size, 35);
	PN(index);

	return 0;
}
