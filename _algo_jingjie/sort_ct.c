/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#ifdef _USE_COMMON_SRC
#define	LOG_LEVEL		LOG_LEVEL_VERBOSE
#include "common_local.h"
#endif

int		ct_sort(int *data, int size, int k)
{
	int *p;
	int i;
	int j;

	p = (int *)malloc(sizeof(int) * k);
	if(!p)
		return 0;
	memset(p, 0, sizeof(int) * k);
	
	j = 0;
	for(i = 0; i < size; ++i) {
		p[data[i]]++;
	}	

	for(i = 0; i < k; ++i) {
		while(p[i]-- > 0)
			data[j++] = i;	
	}	
	
	free(p);

	return 1;
}
