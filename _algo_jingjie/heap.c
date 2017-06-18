/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#include "heap.h"

PHeap	heap_create()
{
	PHeap h;

	h = (PHeap)malloc(sizeof(Heap));
	if(!h)
		return NULL;

	h->size = 0;
	h->tree = NULL;
	return h;
}

void	heap_destroy(PHeap h)
{
	if(h->tree)
		free(h->tree);
	free(h);
}

int		heap_insert(PHeap h, int v)
{
	int *p;
	int pos, ppos;

	p = (int *)realloc(h->tree, (h->size + 1) * sizeof(int));
	if(!p) {
		printf("Fatal Error, no memory!\n");
		return -1;
	}
	h->tree = p;

	h->tree[heap_size(h)] = v;
	pos = heap_size(h);
	ppos = heap_parent(pos);	

	while(pos > 0 && h->tree[ppos] < h->tree[pos]) {
		int temp = h->tree[ppos];
		h->tree[ppos] = h->tree[pos];
		h->tree[pos] = temp;

		pos = ppos;
		ppos = heap_parent(pos);
	}
	(h->size)++;
	return 0;
}

int		heap_extract(PHeap h, int *pv)
{
	int v;
	int save;
	int *temp;
	int pos, lpos, rpos, mpos;

	if(heap_size(h) == 0)
		return -1;

	*pv = h->tree[0];
	save = h->tree[heap_size(h) - 1];
	if(heap_size(h) - 1 > 0) {
		temp = (int *)realloc(h->tree, (heap_size(h) - 1) * sizeof(int));
		if(temp == NULL)
			return -2;
		else
			h->tree = temp;

		--(h->size);
	} else {
		free(h->tree);
		h->tree = NULL;
		h->size = 0;
		return 0;
	}	
	
	h->tree[0] = save;
	pos = 0;
	lpos = heap_left(pos);
	rpos = heap_right(pos);

	while(1) {
		int temp;
		lpos = heap_left(pos);
		rpos = heap_right(pos);

		if(lpos < heap_size(h) && h->tree[lpos] > h->tree[pos])
			mpos = lpos;
		else
			mpos = pos;

		if(rpos < heap_size(h) && h->tree[rpos] > h->tree[mpos])
			mpos = rpos;
	
		if(mpos == pos)
			break;
		else {
			temp = h->tree[pos];
			h->tree[pos] = h->tree[mpos];
			h->tree[mpos] = temp;

			pos = mpos;
		}	
	}
	
	return 0;
}

void	heap_show(PHeap h)
{
	int i = 0;

	while(i < heap_size(h)) {
		printf("%d ", h->tree[i]);
		++i;
	}	
	printf("\n");
}
