#include <iostream>
#include "common_local.h"

using namespace std;

template <class T>
void select_sort(T arr[], int size)
{
	int i, j;
	int min_index;
	for(i = 0; i < size - 1; ++i) {
		min_index = i;
		for(j = i + 1; j < size; ++j) {
			if(arr[j] < arr[min_index])
				min_index = j;
		}
		SWAP(&arr[i], &arr[min_index]);
	}	
}

int main() 
{
	int arr[1000];
	int size = ARR_SIZE(arr);

	gen_basic_desc_arr(arr, size, 1, 1000);

	select_sort(arr, size);

	print_arr(arr, size);
	PD(is_arr_sorted(arr, size));
	
	return 0;
}
