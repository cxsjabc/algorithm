#include "common.h"
#include "array.h"

// start_value: 4, size: 5 , arr: 4 5 6 7 8 
void	init_basic_arr(int arr[], int size, int start_value)
{
	int i;
	for(i = 0; i < size; ++i)
		arr[i] = start_value + i;
}

// reset_value: 3, size: 5, arr: 3 3 3 3 3 
void	reset_basic_arr(int arr[], int size, int reset_value)
{
	int i;
	for(i = 0; i < size; ++i)
		arr[i] = reset_value;
}

// start_value: 4, size: 5, arr: 8 7 6 5 4 
void	init_reverse_basic_arr(int arr[], int size, int start_value)
{
	int i;
	for(i = size - 1; i >= 0; --i)
		arr[i] = start_value + (size - i - 1);
}
