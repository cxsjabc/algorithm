#include "common_local.h"

int	bi_search(int value, int arr[], int l, int r)
{
	int m;

	if(l == r) {
		if(value == arr[l])
			return l;
		else
			return -1;
	}

	m = l + (r - l) / 2;
	if(value == arr[m])
		return m;
	else if(value > arr[m])
		return bi_search(value, arr, m + 1, r);
	else
		return bi_search(value, arr, l, m - 1);
}

int main()
{
	int arr[10] = {1, 10, 20, 30, 50, 79, 90, 100};
	int size = ARR_SIZE(arr);
	int i;
	
	i = bi_search(90, arr, 0, size - 1);
	PD(i);
	i = bi_search(40, arr, 0, size - 1);
	PD(i);

    return 0;
}
