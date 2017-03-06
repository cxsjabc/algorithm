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

void insert_sort1(int arr[], int size)
{
	int i, j;
	for(i = 1; i < size; ++i) {
		#if 0
		for(j = i; j > 0; --j) {
			if(arr[j] < arr[j - 1])
				SWAP(&arr[j], &arr[j - 1]);
			else
				break;
		}
		#else
		for(j = i; j > 0 && arr[j] < arr[j - 1]; --j)
				SWAP(&arr[j], &arr[j - 1]);
			
		#endif
	}	
}

int main()
{
	int arr[1000];
	int size = ARR_SIZE(arr);

	gen_basic_desc_arr(arr, size, 1, 10000);
	print_arr(arr, size);

	TS(1)
	insert_sort1(arr, size);	
	TE

	print_arr(arr, size);
	PD(is_arr_sorted(arr, size));	

    return 0;
}
