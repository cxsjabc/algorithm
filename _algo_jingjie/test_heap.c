/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "heap.h"

void test_heap()
{
	PHeap h;
	int i = 1;
	int ret;
	int v;

	h = heap_create();
	assert(h);
	
	while(i < 15) {
		ret = heap_insert(h, i);
		assert(ret >= 0);
		++i;
	}

	heap_show(h);	

	ret = heap_extract(h, &v);
	printf("%d\n", v);
	heap_show(h);	

	ret = heap_extract(h, &v);
	printf("%d\n", v);
	heap_show(h);	

	heap_destroy(h);	
}

int main()
{
	test_heap();
	return 0;
}
