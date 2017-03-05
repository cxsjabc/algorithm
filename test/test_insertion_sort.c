#include "common_local.h"
#include "insertion_sort.h"

int main()
{
	//int arr[] = {3, 15, -3};
	//int arr[] = {3, 15, -3, 1, 5, 100, 27, 250};
	int *arr1 = (int *)malloc(sizeof(int) * 10000);	

	TIME_START(1)
		init_reverse_basic_arr(arr1, 10000, 1);
		insertion_sort(arr1, 10000);
	TIME_END

	TIME_START(1)
		init_reverse_basic_arr(arr1, 1000, 1);
		insertion_sort(arr1, 1000);
	TIME_END

	//print_arr(arr, ARR_SIZE(arr));	

	free(arr1);

	return 0;
}
