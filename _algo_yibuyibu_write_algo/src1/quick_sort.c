#include "common_local.h"

int get_middle1(int arr[], int s, int e)
{
	int v = arr[s];
	int i = s, j = e;
	int *buf;
	int m = 0, n = e - s;

	buf = (int *)malloc(sizeof(int) * (e - s + 1));
	assert(buf);
	++i;
	while(i <= j) {
		if(arr[i] < v)		
			buf[m++] = arr[i];
		else
			buf[n--] = arr[i];
		++i;
	}
	buf[m] = v;
	memcpy(arr + s, buf, sizeof(int) * (e - s + 1));
	free(buf);
	return m + s;
}

int get_middle(int arr[], int s, int e)
{
	int v = arr[s];
	int i = s, j = e;

	++i;
	while(i <= j) {
		int temp;
		if(arr[i] < v)
			arr[s++] = arr[i++];
		else
			temp = arr[e--], arr[j--] = arr[i], arr[i] = temp;
	}
	arr[j] = v;
	return j;
}

void quick_sort(int arr[], int s, int e)
{
	int m;

	if(s >= e)
		return;
	m = get_middle1(arr, s, e);
	//printf("m:%d\n", m);
	quick_sort(arr, s, m - 1);
	quick_sort(arr, m + 1, e);
}

int main()
{
#define N	10
	int arr[N];

	gen_basic_arr(arr, N, 1, 100);
	print_arr(arr, N);
	quick_sort(arr, 0, N - 1);
	PD(is_arr_sorted(arr, N));
	print_arr(arr, N);
	
    return 0;
}
