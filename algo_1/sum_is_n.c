#include "common_local.h"

int get_sum_is_n(int sorted_arr[], int size, int sum, int *first, int *second)
{
	int i = 0, j = size - 1;
	int *arr = sorted_arr;

	while(i < j && arr[i] + arr[j] != sum) {
		if(arr[i] + arr[j] > sum)
			--j;
		else if(arr[i] + arr[j] < sum)
			++i;
		
	}
	if(i < j) {
		*first = arr[i], *second = arr[j];
		return 1;
	}
	return 0;
}

int main()
{
	int arr[10];
	int v1, v2;
	int ret;
	int sum;
	
	while(1) {
		gen_basic_sorted_arr(arr, 10, 1, 100);
		scanf("%d", &sum);
		ret = get_sum_is_n(arr, 10, sum, &v1, &v2);
		show_arr(arr, 10);
		if(ret) {
			PN2(v1, v2);
		}
	}

    return 0;
}
