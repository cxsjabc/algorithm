/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#ifdef _USE_COMMON_SRC
#include "common_local.h"
#endif

#include "sort_merge.h"

int		merge_sort_int_internal(int a[], int size, int i, int j)
{
	int m;
	int e, f;
	int *p;
	int ret;
	int k;

	if(i >= j) {
		return 0;
		
	}
	if(i + 1 == j) {
		if(a[i] > a[j])
			swap(&a[i], &a[j]);
		
		return 0;
	}	

	m = (i + j) / 2;
	ret = merge_sort_int_internal(a, size, i, m);
	if(ret < 0)
		return -1;
	ret = merge_sort_int_internal(a, size, m + 1, j);
	if(ret < 0)
		return -1;

	// merge the two part: i ~ m, (m + 1) ~ j	
	e = i;
	f = m + 1;
	p = (int *)malloc(sizeof(int) * (j - i + 1));	
	if(!p)
		return -2;
	
	k = 0;
	while(e <= m && f <= j) {
		if(a[e] < a[f]) {
			p[k++] = a[e];
			++e;
		} else {
			p[k++] = a[f];
			++f;
		}
	}

	if(e == m + 1) {
		while(f <= j)
			p[k++] = a[f], ++f;
	}

	if(f == j + 1) {
		while(e <= m)
			p[k++] = a[e], ++e;
	}
	

	memcpy(&a[i], p, sizeof(int) * (j - i + 1));

	free(p);	
	
	return 0;
}

int		merge_sort_int(int a[], int size)
{
	return merge_sort_int_internal(a, size, 0, size - 1);
}
