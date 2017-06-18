#ifndef HEAP_H
#define	HEAP_H

typedef struct _Heap
{
	int		size;
	int	*	tree;
} Heap;

typedef Heap * PHeap;

PHeap	heap_create();
void	heap_destroy(PHeap h);

int		heap_insert(PHeap h, int v);
int		heap_extract(PHeap h, int *pv);

#define heap_size(heap)	((heap)->size)
#define	heap_parent(pos)	(((pos) - 1) / 2)
#define	heap_left(pos)		((pos) * 2 + 1)
#define	heap_right(pos)		((pos) * 2 + 2)

void	heap_show(PHeap h);

#endif
