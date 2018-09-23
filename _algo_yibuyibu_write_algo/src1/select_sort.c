#include "common_local.h"

void select_sort(int arr[], int size)
{
	int i;

	for(i = 0; i < size - 1; ++i) {
		int j, k;
		k = i;
		for(j = i + 1; j < size; ++j) {
			if(arr[j] < arr[k])
				k = j;
		}
		SWAP(&arr[i], &arr[k]);
	}
}

int main()
{
#define	N	10
	int arr[N];

	gen_basic_arr(arr, N, 100, 200);
	print_arr(arr, N);

	select_sort(arr, N);

	print_arr(arr, N);
	PD(is_arr_sorted(arr, N));
    return 0;
}
