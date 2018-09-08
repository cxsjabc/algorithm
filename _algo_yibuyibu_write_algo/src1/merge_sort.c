#include "common_local.h"

void merge_data(int arr[], int s1, int e1, int s2, int e2)
{
	int i = 0, len;
	int *p;
	int start = s1;

	len = e1 - s1 + e2 - s2 + 2;
	p = (int *)malloc(sizeof(int) * len);
	assert(p);

	while(s1 <= e1 && s2 <= e2) {
		if(arr[s1] < arr[s2])
			p[i++] = arr[s1++];
		else
			p[i++] = arr[s2++];
	}
	if(s1 > e1) {
		memcpy(p + i, arr + s2, (e2 - s2 + 1) * sizeof(int));
	} else
		memcpy(p + i, arr + s1, (e1 - s1 + 1) * sizeof(int));
	memcpy(arr + start, p, len * sizeof(int));
}

void merge_sort(int arr[], int s, int e)
{
	int m;

	m = s + (e - s) / 2;
	if(s < m)
		merge_sort(arr, s, m);
	if(m + 1 < e)
		merge_sort(arr, m + 1, e);
	merge_data(arr, s, m, m + 1, e);
}

int main()
{
#define N	10
	int arr[N];

	gen_basic_arr(arr, N, 1, 100);
	print_arr(arr, N);
	merge_sort(arr, 0, N - 1);
	PD(is_arr_sorted(arr, N));
	print_arr(arr, N);
	
    return 0;
}
