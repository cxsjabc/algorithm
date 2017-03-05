#include "common_local.h"

void insert_sort(int arr[], int size)
{
	int i, j, k;
	for(i = 1; i < size; ++i) {
		for(j = i - 1; j >= 0; --j) {
			if(arr[i] >= arr[j])
				break;
		}
		if(j == -1)
			j = 0;
		int v = arr[i];
		for(k = i - 1; k >= j; --k)
			arr[k + 1] = arr[k];
		arr[j] = v;
	}	
}

int main()
{
	int arr[1000];
	int size = ARR_SIZE(arr);

	gen_basic_desc_arr(arr, size, 1, 10000);
	print_arr(arr, size);

	TS(1)
	insert_sort(arr, size);	
	TE

	print_arr(arr, size);
	PD(is_arr_sorted(arr, size));	

    return 0;
}
