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

// merge a[s...sa+sa_size-1] and b[sb...sb+sb_size-1] to c[sc...]
int		merge_arr(int a[], int sa, int sa_size, int b[], int sb, int sb_size, int c[], int sc)
{
	int i, j;
	int k = sc;

	i = sa;
	j = sb;	
	while(i <= sa + sa_size - 1 && j <= sb + sb_size - 1) {
		if(a[i] < a[j]) {
			c[k++] = a[i];
			++i;
		} else {
			c[k++] = a[j];
			++j;
		}
	}

	if(i == sa + sa_size) {
		while(j <= sb + sb_size - 1)
			c[k++] = a[j++];
	}

	if(j == sb + sb_size) {
		while(i <= sa + sa_size - 1)
			c[k++] = a[i++];
	}
	return 0;
}

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
	merge_arr(a, e, m - i + 1, a, f, j - m, p, k);	
	
	memcpy(&a[i], p, sizeof(int) * (j - i + 1));

	free(p);	
	
	return 0;
}

int		merge_sort_int_norecursive_internal(int a[], int size, int i, int j)
{
	int step = 1;
	int *p;

	p = (int *)malloc(sizeof(int) * (j - i + 1));
	if(!p)
		return -1;
	while(step < size) {
		int m = 0;
		while(m <= size - 2 * step) {
			merge_arr(a, m, step, a, m + step, step, p, 0);			
			memcpy(&a[m], p, sizeof(int) * (step * 2));
			m += 2 * step;
			show_arr(a, m);
		}
		if(m < size) {
			merge_arr(a, 0, m, a, m, size - m, p, 0);	
			memcpy(&a[0], p, sizeof(int) * size);
		} else {
			// do nothing
		}
		show_arr(a, size);

		step *= 2;
	}	

	free(p);
	return 0;
}

int		merge_sort_int(int a[], int size)
{
	return merge_sort_int_internal(a, size, 0, size - 1);
}

int		merge_sort_int_norecursive(int a[], int size)
{
	return merge_sort_int_norecursive_internal(a, size, 0, size - 1);
}
