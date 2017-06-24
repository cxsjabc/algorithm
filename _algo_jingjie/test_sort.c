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

	// for test small array
	// size = 2;

	ret = insert_sort_int(a, size);
	printf("ret:%d\n", ret);
	show_arr(a, size);
	PN(is_arr_sorted(a, size));
	
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
