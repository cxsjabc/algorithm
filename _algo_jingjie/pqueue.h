#ifndef PQUEUE_H
#define	PQUEUE_H

typedef struct _PQueue
{
	int		size;
	int	*	tree;
} PQueue;

typedef PQueue * PPQueue;

PPQueue	pqueue_create();
void	pqueue_destroy(PPQueue h);

int		pqueue_insert(PPQueue h, int v);
int		pqueue_extract(PPQueue h, int *pv);

#define pqueue_size(pqueue)	((pqueue)->size)
#define	pqueue_parent(pos)	(((pos) - 1) / 2)
#define	pqueue_left(pos)		((pos) * 2 + 1)
#define	pqueue_right(pos)		((pos) * 2 + 2)

void	pqueue_show(PPQueue h);

#endif
