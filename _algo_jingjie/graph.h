#ifndef GRAPH_H
#define	GRAPH_H

#undef	N
#define	N		100

typedef struct _EdgeNode
{
	int 				adjvex;
	struct _EdgeNode	*next;
}EdgeNode;

typedef struct _Vertex
{
	int		data;
	struct	_EdgeNode	*fe;
} Vertex;


typedef struct _Graph
{
	Vertex	adj_list[N];	
	int num_vex;
	int num_edge;
} Graph;

typedef Graph 	*	PGraph;

PGraph  graph_create(int vs, int es);
void	graph_destroy(PGraph g);
void	graph_show(PGraph g);

#endif
