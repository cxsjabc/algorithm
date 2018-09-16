#include "common_local.h"

int	cmp(const void *s1, const void *s2)
{
	const int *i1 = (const int *)s1;
	const int *i2 = (const int *)s2;

	return *i1 - *i2;
}

int is_arr_unique(int arr[], int size)
{
	int i;

	qsort(arr, size, sizeof(int), cmp);
	for(i = 1; i < size; ++i) {
		if(arr[i] == arr[i - 1])
			return 0;
	}
	return 1;
}

void shuffle(int arr[], int size)
{
	int i;
	
	for(i = 0; i < size; ++i) {
		int temp = rand() % 54;
		SWAP(&arr[i], &arr[temp]);
	}	
}

int main()
{
	int arr[54];
	int i;

	for(i = 0; i < 54; ++i)
		arr[i] = i + 1;

	print_arr(arr, 54);
	PD(is_arr_unique(arr, 54));
	shuffle(arr, 54);
	print_arr(arr, 54);
	PD(is_arr_unique(arr, 54));
    return 0;
}
