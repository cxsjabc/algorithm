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

void heap_del(int arr[], int size, int index)
{
	int i = index;
	int big;

	SWAP(&arr[index], &arr[size]);
	--size;

	while(i <= size) {
		big = i;
		int j = i * 2;
		if(j <= size && arr[j] > arr[i])
			big = j;
		if(j + 1 <= size && arr[j + 1] > arr[big])
			big = j + 1;
		if(big != i) {
			SWAP(&arr[big], &arr[i]);
			i = big; 	
		}
		else
			break;
	}	
}

void heap_sort(int arr[], int size)
{
	int i = 0;
	int ns = size;

	make_heap(arr, size);
	while(i < size) {
		heap_del(arr, ns, 1);
		--ns;
		++i;
	}
}

int main()
{
	int arr[] = {0, 2, 9, 7, 6, 5, 8};
	int size = ARR_SIZE(arr) - 1;

	show_arr(arr + 1, size);
	make_heap(arr, size);
	show_arr(arr + 1, size);

	heap_del(arr, size, 1);	
	show_arr(arr + 1, size - 1);
	heap_sort(arr, size);	
	show_arr(arr + 1, size - 1);

    return 0;
}
