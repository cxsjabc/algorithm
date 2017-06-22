/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "graph.h"


PGraph  graph_create(int vs, int es)
{
	PGraph g;
	int i, j, k;
	EdgeNode	*e;

	g = (PGraph)malloc(sizeof(Graph));
	if(!g)
		return NULL;

	g->num_vex = vs;
	g->num_edge = es;
	// vertex
	printf("Input vertex:");
	for(i = 0; i < vs; ++i) {
		scanf("%d", &g->adj_list[i].data);
		g->adj_list[i].fe = NULL;
	}	
	
	for(i = 0; i < g->num_edge; ++i) {
		printf("Input point index of edge (vi, vj)\n");	
		scanf("%d,%d", &j, &k);
		
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		assert(e);
		e->adjvex = k;
		e->next = g->adj_list[j].fe;
		g->adj_list[j].fe = e;
		//printf("Add edge:from vex:%d, adj_vex:%d, next:%d\n", j, e->adjvex, e->next ? g->adj_list[e->next->adjvex].data : -1);

		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		assert(e);
		e->adjvex = j;
		e->next = g->adj_list[k].fe;
		g->adj_list[k].fe = e;
		//printf("Add edge:ifrom vex:%d, adj_vex:%d, next:%d\n", k, e->adjvex, e->next ? g->adj_list[e->next->adjvex].data : -1);
	}	
	return g;
}

void	graph_destroy(PGraph g)
{
	int i, j;
	EdgeNode	*e, *ne;

	for(i = 0; i < g->num_vex; ++i) {
		e = g->adj_list[i].fe;
		while(e) {
			ne = e->next;
			free(e);
			e = ne;
		}
	}
	free(g);
}

void	graph_show(PGraph	g)
{
	int i, j;
	EdgeNode	*e, *ne;

	for(i = 0; i < g->num_vex; ++i) {
		j = i;
		e = g->adj_list[j].fe;
		printf("%d ", g->adj_list[j].data);

		while(e) {
			j = e->adjvex;
			printf("%d ", g->adj_list[j].data);
			e = e->next;
		}
		printf("\n");
	}	
}
