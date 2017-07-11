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

int		prime(int g[][MAX_E], int n)
{
	int sum = 0;
	int i;
	int lowcost[MAX_E];
	int mst[MAX_E];

	// vertex index is from 1
	for(i = 2; i <= n; ++i) {
		lowcost[i] = g[1][i];
		mst[i] = 1;
	}
	mst[1] = 0;
		
	for(i = 2; i <= n; ++i) {
		int j;
		int min = INT_MAX;
		int minid;
		for(j = 2; j <= n; ++j) {
			if(lowcost[j] < min && lowcost[j] != 0) {
				minid = j;
				min = lowcost[j];
			}
		}
		
		printf("V%d-V%d=%d\n", mst[minid], minid, min);		
		sum += min;
		lowcost[minid] = 0;

		for(j = 2; j <= n; ++j) {
			if(g[minid][j] < lowcost[j]) {
				lowcost[j] = g[minid][j];
				mst[j] = minid;
			}
		}	
	}
	return sum;
}

int		mst_graph_input(int g[][MAX_E])
{
	int v_num, e_num;
	int i, j;
	int k;
	int cost;

	scanf("%d%d", &v_num, &e_num);
	for(i = 1; i <= v_num; ++i) {
		for(j = 1; j <= v_num; ++j) {
			g[i][j] = INT_MAX;
		}
	}	

	for(k = 1; k <= e_num; ++k) {
		scanf("%d%d%d", &i, &j, &cost);
		g[i][j] = g[j][i] = cost;
	}	

	for(i = 1; i <= v_num; ++i) {
		for(j = 1; j <= v_num; ++j) {
			printf("%4d ", g[i][j] == INT_MAX ? -1 : g[i][j]);
		}
		printf("\n");
	}

	return 0;
}

