#include "common_local.h"

void shell_sort(int arr[], int size)
{
	int i, j;
	int H = 1;
	while(H < size / 3)
		H = H * 3 + 1;
	while(H >= 1) {
		// insert sort
		for(i = H; i < size; ++i)
			for(j = i; j >= H && arr[j] < arr[j - H]; j -= H)
				SWAP(&arr[j], &arr[j - H]);
		H /= 3;
	}	
}

int main()
{
	int arr[100];
	int size = ARR_SIZE(arr);

	gen_basic_arr(arr, size, 1, 10000);
	print_arr(arr, size);

	TS(1)
	shell_sort(arr, size);	
	TE

	print_arr(arr, size);
	PD(is_arr_sorted(arr, size));	

    return 0;
}
