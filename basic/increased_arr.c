#include <stdio.h>

#include "common_local.h"

int is_increased_arr(int arr[], int cnt)
{
	int i;

	for(i = 0; i < cnt - 1; ++i) {
		if(arr[i] > arr[i + 1])
			return 0;
	}
	return 1;
}

int is_increased_arr1(int arr[], int cnt) {
	if(cnt < 2)
		return 1;
	if(arr[0] > arr[1])
		return 0;
	return is_increased_arr1(arr + 2, cnt - 2);
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};	
	int arr1[] = {1, 2, 3, 14, 50, 6, 7};	
	int ret;

	ret = is_increased_arr1(arr, ARR_SIZE(arr));
	PN(ret);
	ret = is_increased_arr1(arr1, ARR_SIZE(arr1));
	PN(ret);
	return 0;
}
