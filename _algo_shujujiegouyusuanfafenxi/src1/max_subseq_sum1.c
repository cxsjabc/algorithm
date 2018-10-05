#include "common_local.h"

int max_sum(int arr[], int size)
{
	int i, j;
	int max = arr[0];

	for(i = 0; i < size; ++i) {
		int temp = 0;
		for(j = i; j < size; ++j) {
			temp += arr[j];
			if(temp > max)
				max = temp;
		}
	}	
	return max;
}

int main()
{
#define	N 10
	int arr[N];

	gen_basic_arr(arr, N, -5, 10);
	print_arr(arr, N);
    printf("%d\n", max_sum(arr, ARR_SIZE(arr)));
    return 0;
}
