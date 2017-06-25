/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "sort_quick.h"


int	quick_sort_partition(int a[], int i, int j)
{
	int m, n;
	int k;
	int temp;

	k = i;
	temp = a[k];
	m = i;
	n = j;

	//printf("enter partition:i:%d,j:%d\n", i, j);
	while(m < n) {
		while(n > m) {
			if(a[n] >= temp)
				--n;
			else
				break;
		}
		if(n > m) {
			a[m] = a[n];
			++m;
		}

		while(m < n) {
			if(a[m] < temp)
				++m;
			else
				break;
		}
		if(m < n) {
			a[n] = a[m];
			--n;
		}
	}	

	a[m] = temp;
	//printf("exit partition:i:%d,j:%d, m:%d\n", i, j, m);
	return m;
}


int	quick_sort_int_internal(int a[], int size, int i, int j)
{
	int ret;
	//printf("i:%d, j:%d\n", i, j);

	if(i >= j)
		return 0;
	ret = quick_sort_partition(a, i, j);
	if(ret < 0)
		return -1;

	//printf("i:%d, j:%d, partition:%d\n", i, j, ret);
	//show_arr(a, size);

	quick_sort_int_internal(a, size, i, ret - 1);
	quick_sort_int_internal(a, size, ret + 1, j);
	return 0;
}

int	quick_sort_int(int a[], int size)
{
	return quick_sort_int_internal(a, size, 0, size - 1);
}
