#ifndef GRAPH_MATRIX_H
#define	GRAPH_MATRIX_H

#undef	N
#define	N		100



typedef struct _GraphMatrix
{
	int	** m;	
	int num_v;
} GraphMatrix;

typedef GraphMatrix 	*	PGraphMatrix;

PGraphMatrix  graph_matrix_create(int num_v);
void	graph_matrix_input_vertex(PGraphMatrix g);

int		graph_matrix_set_edge_connected(PGraphMatrix g, int v1, int v2, int value);

void	graph_matrix_destroy(PGraphMatrix g);

void	graph_matrix_show(PGraphMatrix g);

#endif
