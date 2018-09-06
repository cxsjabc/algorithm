#include "common_local.h"

void shell_sort(int arr[], int size)
{
	int step;
	int i, j;

	step = size / 2;
	for(; step >= 1; step /= 2) {
		for(i = 0; i < step; ++i) {
			for(j = i; j < size; j += step) {
				if(j + step < size) {
					int k = j + step;
					while(k >= step && arr[k] < arr[k - step]) {
						int temp = arr[k];
						arr[k] = arr[k - step];
						arr[k - step] = temp;
						k -= step;
					}
				} else
					break;
			}
		}
		//print_arr(arr, size);
	}
}

int main()
{
#define N	10
	int arr[N];

	gen_basic_arr(arr, N, 1, 100);
	print_arr(arr, N);
	shell_sort(arr, N);
	PD(is_arr_sorted(arr, N));
	print_arr(arr, N);
	
    return 0;
}
