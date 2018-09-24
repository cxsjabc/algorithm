#include "common_local.h"

int	pre_process(int *p, int size, int i)
{
	int j = 0;
	int k;
	int value = 1;

	while(j < i) {
		value *= 10;
		++j;
	}

	for(k = 0; k < size; ++k) {
		p[k] = (p[k] % value) / (value / 10);
	}

	for(k = 0; k < size; ++k)
		if(p[k])
			return 1;

	return 0;
}

void	sort_by_pos(int arr[], int size, int pos)
{
	int buckets[10] = {0};
	int i;
	int *temp;
		
	temp = (int *)malloc(size * sizeof(int));
	assert(temp);

	for(i = 0; i < size; ++i) {
		buckets[(arr[i] / pos) % 10]++;
	}

	for(i = 1; i < size; ++i)
		buckets[i] += buckets[i - 1];

	for(i = size - 1; i >= 0; --i) {
		temp[buckets[(arr[i] / pos) % 10] - 1] = arr[i];
		buckets[arr[i] / pos % 10]--;
	}

	for(i = 0; i < size; ++i)
		arr[i] = temp[i];
}

void radix_sort(int arr[], int size)
{
	int i, k;
	int *p;	
	
	p = (int *)malloc(size * sizeof(int));
	assert(p);
	memcpy(p, arr, size * sizeof(int));

	i = 1;
	k = 1;
	while(1) {
		int ret = pre_process(p, size, i);
		if(!ret)
			break;
		sort_by_pos(arr, size, k);
		
		memcpy(p, arr, size * sizeof(int));	
		++i;
		k *= 10;
	}	

	free(p);
}

int main()
{
#define	N	10
	int arr[N];

	gen_basic_arr(arr, N, 1, 1000);
	print_arr(arr, N);

	radix_sort(arr, N);

	print_arr(arr, N);
	PD(is_arr_sorted(arr, N));
    return 0;
}
