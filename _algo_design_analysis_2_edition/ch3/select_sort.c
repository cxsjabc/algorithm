#include "common_local.h"

void select_sort(int arr[], int size)
{
	int i, j;

	for(i = 0; i < size - 1; ++i) {
		int min = i;
		int temp;
		for(j = i + 1; j < size; ++j) {
			if(arr[j] < arr[min])
				min = j;
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

int main()
{
	int arr[] = {100, 2, 300, 28, 102, 78};
	int size = sizeof(arr) / sizeof(arr[0]);
	select_sort(arr, size);
	print_arr(arr, size);
	PD(is_arr_sorted(arr, size));

    return 0;
}
