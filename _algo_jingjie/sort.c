/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "sort.h"


int	compare_int(const void *d1, const void *d2)
{
	int n1 = *(int *)d1, n2 = *(int *)d2;
	int diff = n1 - n2;

	return (diff == 0 ? (0) : ((diff > 0) ? 1 : -1));
}

int	insert_sort(void *data, int data_cnt, int ele_size, compare com)
{
	char *p = (char *)data;
	int i, j;
	char *pback;

	for(i = 1; i < data_cnt; ++i) {
		char *pc = p + i * ele_size;
		for(j = 0; j < i; ++j) {
			char *pb = p + j * ele_size;
			if(com(pc, pb) <= 0) {
				// insert data[i] to data[j]
				// 1 backup data[i]
				pback = (char *)malloc(ele_size);
				if(!pback)
					return -1;
				memcpy(pback, pc, ele_size);	

				// 2 then, copy data[i - 1, ... ,j] to data[i, ... ,j + 1]
				memmove(pb + ele_size, pb, (i - j) * ele_size);
				// 3 copy pback to pb
				memcpy(pb, pback, ele_size);
				free(pback);

				break;
			}	
		}
	}
	return 0;
}


int	insert_sort_int(void *data, int data_cnt)
{
	return insert_sort(data, data_cnt, sizeof(int), compare_int);
}
