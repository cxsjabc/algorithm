#include "common_local.h"

void insert_sort(int arr[], int size)
{
	int i;
	int j;
	int k;

	for(i = 1; i < size; ++i) {
		j = 0;
		while(j < i && arr[i] >= arr[j])
			++j;
		if(j != i) {
			int temp = arr[i];
			for(k = i - 1; k >= j; --k)
				arr[k + 1] = arr[k];	
			arr[j] = temp;
		}
	}
}

int main()
{
	int arr[10];
	int size = ARR_SIZE(arr);

	gen_basic_arr(arr, size, 1, 100);
	print_arr(arr, size);
	insert_sort(arr, size);
	print_arr(arr, size);
	PD(is_arr_sorted(arr, size));

    return 0;
}
