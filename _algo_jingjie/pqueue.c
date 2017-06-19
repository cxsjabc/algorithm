/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#include "pqueue.h"

PPQueue	pqueue_create()
{
	PPQueue h;

	h = (PPQueue)malloc(sizeof(PQueue));
	if(!h)
		return NULL;

	h->size = 0;
	h->tree = NULL;
	return h;
}

void	pqueue_destroy(PPQueue h)
{
	if(h->tree)
		free(h->tree);
	free(h);
}

int		pqueue_insert(PPQueue h, int v)
{
	int *p;
	int pos, ppos;

	p = (int *)realloc(h->tree, (h->size + 1) * sizeof(int));
	if(!p) {
		printf("Fatal Error, no memory!\n");
		return -1;
	}
	h->tree = p;

	h->tree[pqueue_size(h)] = v;
	pos = pqueue_size(h);
	ppos = pqueue_parent(pos);	

	while(pos > 0 && h->tree[ppos] < h->tree[pos]) {
		int temp = h->tree[ppos];
		h->tree[ppos] = h->tree[pos];
		h->tree[pos] = temp;

		pos = ppos;
		ppos = pqueue_parent(pos);
	}
	(h->size)++;
	return 0;
}

int		pqueue_extract(PPQueue h, int *pv)
{
	int v;
	int save;
	int *temp;
	int pos, lpos, rpos, mpos;

	if(pqueue_size(h) == 0)
		return -1;

	*pv = h->tree[0];
	save = h->tree[pqueue_size(h) - 1];
	if(pqueue_size(h) - 1 > 0) {
		temp = (int *)realloc(h->tree, (pqueue_size(h) - 1) * sizeof(int));
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
	lpos = pqueue_left(pos);
	rpos = pqueue_right(pos);

	while(1) {
		int temp;
		lpos = pqueue_left(pos);
		rpos = pqueue_right(pos);

		if(lpos < pqueue_size(h) && h->tree[lpos] > h->tree[pos])
			mpos = lpos;
		else
			mpos = pos;

		if(rpos < pqueue_size(h) && h->tree[rpos] > h->tree[mpos])
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

void	pqueue_show(PPQueue h)
{
	int i = 0;

	while(i < pqueue_size(h)) {
		printf("%d ", h->tree[i]);
		++i;
	}	
	printf("\n");
}
