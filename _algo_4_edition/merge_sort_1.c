#define _LOG_ENABLE 0

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

void merge_sort_1_internal(int arr[], int s, int e)
{
	int i, j;
	for(i = 1; i <= e; i = i + i ) {
		for(j = 0; j <= e - i; j = j + i + i ) {
			int temp = MIN(j + i + i - 1, e);
			log_v("step:%d, cur:%d,size: %d, s1:%d, e1:%d, s2:%d, e2:%d\n", i, j,
					temp - j + 1, j, j + i - 1, j + i, temp);
			merge_sorted_arr(arr, temp - j + 1, j, j + i - 1, j + i, temp);
		}
	}
}

void merge_sort_1(int arr[], int size)
{
	merge_sort_1_internal(arr, 0, size - 1);
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
	merge_sort_1(arr, size);	
	TE

	print_arr(arr, size);
	PD(is_arr_sorted(arr, size));	

	PD(is_arr_equal_no_index(arr, N, arr1, N));	

    return 0;
}
