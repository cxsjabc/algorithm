/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "heap_1.h"

void	test_heap_1()
{
	int a[] = {9,3,4,5,1,8,0,2,7,6};
	int size = sizeof(a) / sizeof(a[0]);

	heap_sort(a, size);
	heap_show(a, size);	
}

int main()
{
	test_heap_1();
	return 0;
}
