#include "common_local.h"

void merge_sorted_arr(int arr[], int size, int arr1_s, int arr1_e, int arr2_s, int arr2_e)
{
	int *temp_arr = (int *)malloc(sizeof(int) * size);
	int i = arr1_s, j = arr2_s;
	int k = 0;

	ASSERT(temp_arr);
	
	while(i <= arr1_e && j <= arr2_e) {
		if(arr[i] <= arr[j])
			temp_arr[k] = arr[i], ++i, ++k;
		else
			temp_arr[k] = arr[j], ++j, ++k;
	}

	while(i <= arr1_e)
		temp_arr[k++] = arr[i++];
	while(j <= arr2_e)
		temp_arr[k++] = arr[j++];

#define WRONG 0		// if 1, it means the algorithm is wrong! It's for test.
#if WRONG
	memcpy(arr, temp_arr, sizeof(int) * size);
#else
	memcpy(&arr[arr1_s], temp_arr, sizeof(int) * size);
#endif
	free(temp_arr);
}

void merge_sort_internal(int arr[], int s, int e)
{
	if(e < s + 2) {
		if(e == s + 1) {
			if(arr[s] > arr[e])
				SWAP(&arr[s], &arr[e]);
		}
	} else {
		int mid = (s + e) / 2;
		merge_sort_internal(arr, s, mid);
		merge_sort_internal(arr, mid + 1, e);
		merge_sorted_arr(arr, e - s + 1, s, mid, mid + 1, e);
	}
}

void merge_sort(int arr[], int size)
{
	merge_sort_internal(arr, 0, size - 1);
}

int main()
{
#define N					100
#define RAND_VALUE_MAX		100
	int arr[N], arr1[N];
	int size = ARR_SIZE(arr);

	gen_basic_arr(arr, size, 1, RAND_VALUE_MAX);
	print_arr(arr, size);

	memcpy(arr1, arr, N * sizeof(int));

	TS(1)
	merge_sort(arr, size);	
	TE

	print_arr(arr, size);
	PD(is_arr_sorted(arr, size));	

	PD(is_arr_equal_no_index(arr, N, arr1, N));	

    return 0;
}
