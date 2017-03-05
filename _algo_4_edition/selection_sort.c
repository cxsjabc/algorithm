#include "common_local.h"

void select_sort(int arr[], int size)
{
	int i, j;
	int min_index;
	for(i = 0; i < size - 1; ++i) {
		min_index = i;
		for(j = i + 1; j < size; ++j) {
			if(arr[j] < arr[min_index])
				min_index = j;
		}
		SWAP(&arr[i], &arr[min_index]);
	}	
}

int main()
{
	int arr[1000000];
	int size = ARR_SIZE(arr);

	gen_basic_desc_arr(arr, size, 1, 1000);
	//print_arr(arr, size);

	TS(1)
	select_sort(arr, 1);	
	TE
	gen_basic_desc_arr(arr, size, 1, 100);

	TS(1)
	select_sort(arr, 10);	
	TE
	gen_basic_desc_arr(arr, size, 1, 100);

	TS(1)
	select_sort(arr, 100);	
	TE
	gen_basic_desc_arr(arr, size, 1, 1000);

	TS(1)
	select_sort(arr, 1000);	
	TE

	gen_basic_desc_arr(arr, size, 1, 10000);	
	TS(1)
	select_sort(arr, 10000);	
	TE

	gen_basic_desc_arr(arr, size, 1, 100000);
	TS(1)
	select_sort(arr, 100000);	
	TE

	gen_basic_desc_arr(arr, size, 1, 1000000);
	TS(1)
	select_sort(arr, 1000000);	
	TE


	//print_arr(arr, size);
	//PD(is_arr_sorted(arr, size));	

    return 0;
}
