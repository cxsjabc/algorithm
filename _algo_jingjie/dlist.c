#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dlist.h"


PDListHead	dlist_create(PDListHead *l)
{
	*l = NULL;
	return NULL;
}

PDListHead	dlist_create_by_input(PDListHead *plh)
{
	int v;
	PDListNode node = NULL;
	int ret;

	*plh = NULL;

	while((ret = scanf("%d", &v)) != EOF) {
		int r;
		if(ret == 0) {	// flush stdin for unmatched input data
			char c;
			while((c = getchar()) != '\n') 
				;
			continue;
		}
		
		// insert the data 
		r = dlist_insert(plh, node, v);
		if(r != 0) {
			printf("insert node:%d error!\n", v);
			break;
		}

		// update the next insert node pointer
		if(node == NULL)
			node = *plh;
		else
			node = node->next;
	}	
	
	// means stdin error, then destory the dlist and return NULL
	if(ferror(stdin)) {
		dlist_destroy(plh);
	}
	return *plh;
}

int		dlist_insert(PDListHead *lh, PDListNode pln, int v)
{
	PDListNode node = (PDListNode)malloc(sizeof(DListNode));

	if(!node)
		return -1;

	if(!pln) {	
		if(!*lh) { // NULL header pointer
			node->v = v;
			node->prev = NULL;
			node->next = NULL;
			*lh = node;
			(*lh)->next = NULL;
			//printf("Set header pointer to:%p, value:%d\n", *lh, (*lh)->v);
			return 0;
		} {
			node->v = v;
			node->prev = NULL;
			node->next = *lh;

			(*lh)->prev = node;
			*lh = node;
			//printf("header pointer is:%p, value:%d, next_value:%d\n", *lh, (*lh)->v, (*lh)->next->v);
			return 0;
		}
	} else {
		PDListNode next = pln->next; 
		node->v = v;
		node->next = next;
		node->prev = pln;

		pln->next = node;
		if(next)
			next->prev = node;
		return 0;
	}
	
}

int			dlist_remove(PDListHead *plh, PDListNode pln)
{
	PDListHead lh = *plh;
	if(!pln) {	// pln is NULL, remove first node(not header node)
		PDListNode node;
		if(lh == NULL)
			return -2;
		node = lh->next;
		free(lh);
		*plh = node;
		if(node)
			node->prev = NULL;
		return 0;
	} else {
		PDListNode next = pln->next;
		if(!next)
			return -2;
		else {
			PDListNode nn = next->next;
			free(next);
			pln->next = nn;
			if(nn)
				nn->prev = pln;
			return 0;
		}
	}
}

PDListNode	dlist_get_node(PDListHead lh, int index)
{
	PDListNode node = lh;
	int i = 0;

	assert(index >= 0);

	while(i < index && node) {
		node = node->next;
		++i;
	}
	if(i == index)
		return node;
	else
		return NULL;
}

int			dlist_get_node_value(PDListHead lh, int index)
{
	PDListNode node = dlist_get_node(lh, index);
	if(!node)
		return -1;
	return node->v;
}

void		dlist_show(PDListHead lh)
{
	PDListNode node = lh;

	while(node) {
		printf("%d ,prv:%p, prv data:%d\n", node->v, node->prev, node->prev ? node->prev->v : -1);
		node = node->next;
	}	
	printf("\n");
}

void		dlist_destroy(PDListHead *plh)
{
	PDListNode pln;
	PDListNode node = *plh;

	while(node) {
		pln = node->next;
		free(node);
		node = pln;
	}
	*plh = NULL;
}

int			dlist_size(PDListHead lh)
{
	int size = 0;

	while(lh) {
		++size;
		lh = lh->next;
	}
	return size;
}
