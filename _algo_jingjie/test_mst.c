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

#include "mst.h"

void	test_mst()
{
#define	N		100
	int		g[N][N];
	int sum;

	mst_graph_input(g);

	sum = prime(g, 6);

	printf("mst sum: %d\n", sum);	
}


int main()
{
	test_mst();
	return 0;
}
