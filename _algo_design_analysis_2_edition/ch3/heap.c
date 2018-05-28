#include "common_local.h"

// index 0: not used, if arr contains 9 elements, then size == 8.
void	make_heap(int arr[], int size)
{
	int i;

	for(i = size / 2; i >= 1; --i) {
		int j = i;
		int big;
		while(2 * j <= size) {
			int k = 2 * j;
			big = k;
			if(k + 1 <= size) {
				if(arr[k + 1] > arr[k])
					big = k + 1;
			}
			if(arr[j] < arr[big])
				SWAP(&arr[j], &arr[big]);
			j = big;
		}
	}
}

int main()
{
	int arr[] = {0, 2, 9, 7, 6, 5, 8};
	int size = ARR_SIZE(arr) - 1;

	show_arr(arr + 1, size);
	make_heap(arr, size);
	show_arr(arr + 1, size);
    return 0;
}
