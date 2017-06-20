/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

void	swap(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void	heap_process(int a[], int i, int size)
{
	int l, r, m;
	m = i;
	l = i * 2 + 1;
	r = i * 2 + 2;

	if(l < size && a[l] > a[i])
		m = l;
	if(r < size && a[r] > a[m])
		m = r;

	if(m != i) {
		swap(&a[i], &a[m]);
		heap_process(a, m, size);
	}
}

void	heap_sort(int a[], int size)
{
	int i;

	for(i = size / 2 - 1; i >= 0; --i) {
		heap_process(a, i, size);
	}

	for(i = size - 1; i >= 0; --i) {
		swap(&a[i], &a[0]);
		heap_process(a, 0, i);
	}
}

void heap_show(int a[], int size)
{
	int i = 0;
	for(; i < size; ++i)
		printf("%d ", a[i]);
	printf("\n");
}
