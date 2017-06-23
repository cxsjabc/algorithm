/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "graph_matrix.h"

//#define	DEBUG

#ifdef	DEBUG 
#define LOG_HERE	printf("[%s@%d]\n", __func__, __LINE__);
#define	LH			LOG_HERE
#else
#define LOG_HERE	
#define	LH			LOG_HERE
#endif

void	test_graph_matrix()
{
	PGraphMatrix	g;
	int num_v;

	scanf("%d", &num_v);
	g = graph_matrix_create(num_v);
	assert(g);
	LH

	graph_matrix_input_vertex(g);
	printf("after intput vertex\n");  // **very strange: if marked this line, will crash **
	//printf("a");
	LH

	graph_matrix_show(g);
	//printf("after show\n");
	LH
	graph_matrix_destroy(g);		
}


int main()
{
	test_graph_matrix();
	return 0;
}
