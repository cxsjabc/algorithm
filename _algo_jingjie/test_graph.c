/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "graph.h"

void	test_graph()
{
	PGraph	g;

	g = graph_create(4, 5);
	assert(g);

	graph_show(g);

	graph_destroy(g);		
}


int main()
{
	test_graph();
	return 0;
}
