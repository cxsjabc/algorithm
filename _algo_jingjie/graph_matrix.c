/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "graph_matrix.h"


PGraphMatrix  graph_matrix_create(int num_v)
{
	PGraphMatrix g;
	int i = 0;

	g = (PGraphMatrix)malloc(sizeof(GraphMatrix));
	if(!g)
		return NULL;

	g->m = (int **)malloc(num_v * sizeof(int *));
	if(!(g->m))
		goto err1;
	memset(g->m, 0, sizeof(num_v * sizeof(int *)));
	while(i < num_v) {
		g->m[i] = (int *)malloc(num_v * sizeof(int));
		if(!(g->m[i]))
			goto label_clean;
		memset(g->m[i], 0, num_v * sizeof(int));
		++i;
	}

	g->num_v = num_v;
	return g;

label_clean:
	i = 0;
	while(i < num_v) {
		if(g->m[i])
			free(g->m[i]);
		++i;
	}

err1:
	if(g)
		free(g);
	return NULL;	
}

void	graph_matrix_input_vertex(PGraphMatrix g)
{
	int i, j;
	int cnt;

	printf("enter input_vertex\n");
	while((cnt = scanf("%d,%d", &i, &j)) != EOF) {
		printf("i:%d,j:%d\n", i, j);
		if(i == -1 || j == -1)
			break;
		if(i < g->num_v && j < g->num_v) {
			g->m[i][j] = 1;
			g->m[j][i] = 1;
		}
	}
	printf("exit input_vertex\n");
}


int		graph_matrix_set_edge_connected(PGraphMatrix g, int v1, int v2, int value)
{
	int num_v = g->num_v;
	if(v1 >= num_v || v2 >= num_v)
		return -1;

	g->m[v1][v2] = value;
	g->m[v2][v1] = value;
	return 0;
}

void	graph_matrix_destroy(PGraphMatrix g)
{
	int i;
	if(!g)
		return;

	i = 0;
	while(i < g->num_v) {
		if(g->m[i])
			free(g->m[i]);
		++i;
	}

	free(g);
}

void	graph_matrix_show(PGraphMatrix g)
{
	int i = 0, j;
	
	//printf("enter show\n");
	j = 0;
	while(i < g->num_v) {
		j = 0;
		while(j < g->num_v) {
			printf("%d ", g->m[i][j]);
			++j;
		}			
		printf("\n");	
		++i;
	}
}
