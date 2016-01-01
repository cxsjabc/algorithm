#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "common.h"


int find_major_element(int arr[], int cnt, int *found)
{
	int *extra_arr;
	int extra_cnt;
	int i;
	int j = 0;
	int ret;
	
	if(cnt == 1) {
		*found = 1;
		return arr[0];
	}

	if(cnt == 2) {
		if(arr[0] == arr[1]) {
			*found = 1;
			return arr[0];
		}
		else {
			*found = 0;
			return INT_MIN;
		}
	}
	
	extra_cnt = cnt / 2;	
	if(cnt & 1)
		++extra_cnt;

	extra_arr = (int *)malloc(sizeof(int) * extra_cnt);
	for(i = 0; i < cnt; i += 2) {
		if(i != cnt - 1 && arr[i] == arr[i + 1])
			extra_arr[j++] = arr[i];
		else if(i == cnt - 1)
			extra_arr[j++] = arr[i];
	}
	
	ret = find_major_element(extra_arr, j, found);
	free(extra_arr);
	return ret;
}

int main()
{
	int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
	int arr1[] = {3, 3, 4, 2, 4, 4, 2, 4};
	int ret;
	int found;

	ret = -1;
	found = -2;
	ret = find_major_element(arr, ARR_SIZE(arr), &found);
	PN(found);
	PN(ret);

	found = -2;	
	ret = -1;
	ret = find_major_element(arr1, ARR_SIZE(arr1), &found);
	PN(found);
	PN(ret);

	return 0;
}
