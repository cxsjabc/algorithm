#include "common_local.h"

void bubble_sort(int arr[], int size)
{
	int i, j;

	for(i = 0; i < size - 1; ++i) {
		for(j = 1; j < size - i; ++j) {
			if(arr[j] < arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}

int main()
{
	int arr[] = {100, 2, 300, 28, 102, 78};
	int size = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, size);
	print_arr(arr, size);
	PD(is_arr_sorted(arr, size));

    return 0;
}
