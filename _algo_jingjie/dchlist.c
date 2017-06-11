#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dchlist.h"


PDCHListHead	dchlist_create()
{
	PDCHListNode pln = (PDCHListNode)malloc(sizeof(DCHListNode));
	if(!pln)
		return NULL;
	
	pln->v = 0xABCDABCD; // just a special value indicates header node
	pln->prev = pln;	
	pln->next = pln;	

	return pln;
}

int		dchlist_insert(PDCHListHead lh, PDCHListNode pln, int v)
{
	PDCHListNode node = (PDCHListNode)malloc(sizeof(DCHListNode));

	if(!node)
		return -1;

	if(!pln) {	// if pln is NULL, insert after header node.
		PDCHListNode next = lh->next;
		node->v = v;
		node->prev = lh;
		node->next = next;

		lh->next = node;
		if(next)
			next->prev = node;
		return 0;
	} else {
		PDCHListNode next = pln->next; 
		node->v = v;
		node->prev = pln;
		node->next = next;
		
		next->prev = node;

		pln->next = node;
		return 0;
	}
	
}

int			dchlist_remove(PDCHListHead lh, PDCHListNode pln)
{
	PDCHListNode node = lh->next;
	if(!pln) {	// pln is NULL, remove first node(not header node)
		if(node == lh)
			return -1;
		else {
			PDCHListNode next = node->next;
			free(node);
			lh->next = next;
			if(next)
				next->prev = lh;
			return 0;
		}
	} else {
		PDCHListNode next = pln->next;
		if(next == lh)
			return -2;
		else {
			PDCHListNode nn = next->next;
			free(next);
			pln->next = nn;
			if(nn)
				nn->prev = pln;
			return 0;
		}
	}
}

PDCHListNode	dchlist_get_node(PDCHListHead lh, int index)
{
	PDCHListNode node = lh->next;
	int i = 0;

	assert(index >= 0);

	while(i < index && node != lh) {
		node = node->next;
		++i;
	}
	if(i == index && node != lh)
		return node;
	else
		return NULL;
}

int			dchlist_get_node_value(PDCHListHead lh, int index)
{
	PDCHListNode node = dchlist_get_node(lh, index);
	if(!node)
		return -1;
	return node->v;
}

void		dchlist_show(PDCHListHead lh)
{
	PDCHListNode node = lh->next;

	while(node != lh) {
		printf("%d, prev:%p,data:%d\n", node->v, node->prev, (node->prev != lh ? node->prev->v : -1));
		node = node->next;
	}	
	printf("\n");
}

void		dchlist_destroy(PDCHListHead lh)
{
	PDCHListNode pln;
	PDCHListNode node = lh->next;

	while(node != lh) {
		pln = node->next;
		free(node);
		node = pln;
	}
	free(lh);
}

int			dchlist_size(PDCHListHead lh)
{
	int size = 0;
	PDCHListNode node = lh->next;

	while(node != lh) {
		++size;
		node = node->next;
	}
	return size;
}
