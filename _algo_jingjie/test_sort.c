/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "sort.h"
#include "common_local.h"

void test_insert_sort()
{
	int a[] = {100, 90, 10, 1000, 1, 500};	
	int size = sizeof(a) / sizeof(a[0]);
	int ret;
	int a1[10000];
	int *pa;
	int loop_cnt = 100;
	unsigned long long record_exec_cnt = 0;
	unsigned long long record_exec_cnt1 = 0;

	pa = a1;
	size = sizeof(a1) / sizeof(a1[0]);

	// for test small array
	// size = 2;

	gen_basic_arr(pa, size, 1, 10000000);
	TS(loop_cnt)
		ret = insert_sort_int1(pa, size, 1, &record_exec_cnt);
		ret = insert_sort_int1(pa, size, 0, &record_exec_cnt1);
	TE
	printf("ret:%d, record_exec_cnt:%llu, record_exec_cnt1:%llu\n", ret, record_exec_cnt, record_exec_cnt1);

	//show_arr(pa, size);
	PN(is_arr_sorted(pa, size));
	
}

void test_sort()
{
	test_insert_sort();
}


int main()
{
	test_sort();

	return 0;
}
