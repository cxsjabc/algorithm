#include "common_local.h"

#undef swap
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_arr_index(int arr[], int l, int r)
{
	while(l <= r) {
		printf("%d ", arr[l]);
		++l;
	}
	printf("\n");
}

/* bug ... */
int partition(int arr[], int l, int r)
{
	int q = arr[l];
	int i, j;

	i = l;
	j = r + 1;
	printf("init: l:%d, i:%d, j:%d\n", l, l, r);
	do {
		do { ++i; } while(arr[i] <= q && i < j);
		do { --j; } while(arr[j] >= q && j > i);
		printf("i:%d, j:%d\n", i, j);
		if(i < j)
			swap(&arr[i], &arr[j]);	
	} while(i < j);
	if(i != j)
		swap(&arr[l], &arr[j]);
	return j;
}

void quick_sort(int arr[], int l, int r)
{
	int m;

	if(l > r)
		return;

	m = partition(arr, l, r);
	print_arr_index(arr, l , r);
	printf("after partition: m:%d\n", m);
	sleep(1);
	if(m - 1 > l)
		quick_sort(arr, l, m - 1);
	if(r > m)
		quick_sort(arr, m + 1, r);
}

int main()
{
	int arr[] = {5, 3, 1, 9, 8, 2, 4, 7};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	print_arr(arr, size);
	quick_sort(arr, 0, size - 1);
	print_arr(arr, size);
    return 0;
}
