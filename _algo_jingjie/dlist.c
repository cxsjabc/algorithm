#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dlist.h"


PDListHead	dlist_create()
{
	PDListNode pln = (PDListNode)malloc(sizeof(DListNode));
	if(!pln)
		return NULL;
	
	pln->v = 0xABCDABCD; // just a special value indicates header node
	pln->prev = NULL;	
	pln->next = NULL;	

	return pln;
}

int		dlist_insert(PDListHead lh, PDListNode pln, int v)
{
	PDListNode node = (PDListNode)malloc(sizeof(DListNode));

	if(!node)
		return -1;

	if(!pln) {	// if pln is NULL, insert after header node.
		PDListNode next = lh->next;
		node->v = v;
		node->prev = lh;
		node->next = next;

		lh->next = node;
		next->prev = node;
		return 0;
	} else {
		PDListNode next = pln->next; 
		node->v = v;
		node->next = next;
		next->prev = node;
		pln->next = node;
		node->prev = pln;
		return 0;
	}
	
}

int			dlist_remove(PDListHead lh, PDListNode pln)
{
	PDListNode node = lh->next;
	if(!pln) {	// pln is NULL, remove first node(not header node)
		if(!node)
			return -1;
		else {
			PDListNode next = node->next;
			free(node);
			lh->next = next;
			next->prev = lh;
			return 0;
		}
	} else {
		PDListNode next = pln->next;
		if(!next)
			return -2;
		else {
			PDListNode nn = next->next;
			free(next);
			pln->next = nn;
			return 0;
		}
	}
}

PDListNode	dlist_get_node(PDListHead lh, int index)
{
	PDListNode node = lh;
	int i = -1;

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
	PDListNode node = lh->next;

	while(node) {
		printf("%d ", node->v);
		node = node->next;
	}	
	printf("\n");
}

void		dlist_destroy(PDListHead lh)
{
	PDListNode pln;
	PDListNode node = lh;

	while(node) {
		pln = node->next;
		free(node);
		node = pln;
	}
}

int			dlist_size(PDListHead lh)
{
	int size = 0;
	lh = lh->next;

	while(lh) {
		++size;
		lh = lh->next;
	}
	return size;
}
