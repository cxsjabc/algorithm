/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "sort_ct.h"
#include "common_local.h"

#define ARRAY_A1_SIZE 	1003

void test_sort_ct()
{
	int a[] = {100, 90, 10, 1000, 1, 500};	
	int a1[ARRAY_A1_SIZE];
	int *pa;

	int ret;
	int size = sizeof(a) / sizeof(a[0]);

	int loop_cnt = 1;
	int i;

	pa = a1;
	size = sizeof(a1) / sizeof(a1[0]);

	gen_basic_arr(pa, size, 1, 2000);
#if 0 
	for(i = 0; i < ARRAY_A1_SIZE; ++i) {
		pa[i] = 100 - i;
	}	
#endif
	//show_arr(pa, size);

	TS(loop_cnt)
		ret = ct_sort(pa, size, 2001);
	TE

	//show_arr(pa, size);
	PN(is_arr_sorted(pa, size));
	
}

int main()
{
	test_sort_ct();

	return 0;
}
