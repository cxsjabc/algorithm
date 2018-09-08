#include "common_local.h"

void make_big_heap(int arr[], int s, int size)
{
	int i, j;

	for(i = size / 2; i >= s; --i) {
		int big;
		j = i;
		while(2 * j <= size) {
			int k = 2 * j;
			big = k;
			if(arr[k] > arr[j])
				big = k;
			if(k + 1 <= size) {
				if(arr[k + 1] > arr[big])
					big = k + 1;
			}
			if(arr[big] > arr[j])
				swap(&arr[j], &arr[big]);
			j = big;
		}
	}
}

void heap_sort(int arr[], int s, int size)
{
	make_big_heap(arr, s, size);	
	while(size > 1) {
		SWAP(&arr[s], &arr[size]);
		make_big_heap(arr, s, size - 1);
		--size;
	}
}

int main()
{
#define N	10
	int arr[N + 1];

	gen_basic_arr(arr + 1, N, 1, 100);
	print_arr(arr + 1, N);
	heap_sort(arr, 1, N);
	PD(is_arr_sorted(arr + 1, N));
	print_arr(arr + 1, N);
	
    return 0;
}
