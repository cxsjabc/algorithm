/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "pqueue.h"

void test_pqueue()
{
	PPQueue h;
	int i = 1;
	int ret;
	int v;

	h = pqueue_create();
	assert(h);
	
	while(i < 15) {
		ret = pqueue_insert(h, i);
		assert(ret >= 0);
		++i;
	}

	pqueue_show(h);	

	ret = pqueue_extract(h, &v);
	printf("%d\n", v);
	pqueue_show(h);	

	ret = pqueue_extract(h, &v);
	printf("%d\n", v);
	pqueue_show(h);	

	pqueue_destroy(h);	
}

int main()
{
	test_pqueue();
	return 0;
}
