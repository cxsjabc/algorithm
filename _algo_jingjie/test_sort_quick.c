/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "sort_quick.h"
#include "common_local.h"

#define ARRAY_A1_SIZE	10000

void test_sort_quick()
{
	int a[] = {100, 90, 10, 1000, 1, 500};	
	int size = sizeof(a) / sizeof(a[0]);
	int ret;
	int a1[ARRAY_A1_SIZE];
	int *pa;
	int loop_cnt = 1;

	pa = a1;
	size = sizeof(a1) / sizeof(a1[0]);

	gen_basic_arr(pa, size, 1, 10000000);
	//show_arr(pa, size);
	TS(loop_cnt)
		ret = quick_sort_int(pa, size);
	TE

	//show_arr(pa, size);
	PN(is_arr_sorted(pa, size));
	
}

int main()
{
	test_sort_quick();

	return 0;
}
