#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "hlist.h"


PHListHead	hlist_create()
{
	PHListNode pln = (PHListNode)malloc(sizeof(HListNode));
	if(!pln)
		return NULL;
	
	pln->v = 0xABCDABCD; // just a special value indicates header node
	pln->next = NULL;	

	return pln;
}

int		hlist_insert(PHListHead lh, PHListNode pln, int v)
{
	PHListNode node = (PHListNode)malloc(sizeof(HListNode));

	if(!node)
		return -1;

	if(!pln) {	// if pln is NULL, insert after header node.
		PHListNode next = lh->next;
		node->v = v;
		node->next = next;
		lh->next = node;
		return 0;
	} else {
		PHListNode next = pln->next; 
		node->v = v;
		node->next = next;
		pln->next = node;
		return 0;
	}
	
}

int			hlist_remove(PHListHead lh, PHListNode pln)
{
	PHListNode node = lh->next;
	if(!pln) {	// pln is NULL, remove first node(not header node)
		if(!node)
			return -1;
		else {
			PHListNode next = node->next;
			free(node);
			lh->next = next;
			return 0;
		}
	} else {
		PHListNode next = pln->next;
		if(!next)
			return -2;
		else {
			PHListNode nn = next->next;
			free(next);
			pln->next = nn;
			return 0;
		}
	}
}

PHListNode	hlist_get_node(PHListHead lh, int index)
{
	PHListNode node = lh;
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

int			hlist_get_node_value(PHListHead lh, int index)
{
	PHListNode node = hlist_get_node(lh, index);
	if(!node)
		return -1;
	return node->v;
}

void		hlist_show(PHListHead lh)
{
	PHListNode node = lh->next;

	while(node) {
		printf("%d ", node->v);
		node = node->next;
	}	
	printf("\n");
}

void		hlist_destroy(PHListHead lh)
{
	PHListNode pln;
	PHListNode node = lh;

	while(node) {
		pln = node->next;
		free(node);
		node = pln;
	}
}

int			hlist_size(PHListHead lh)
{
	int size = 0;
	lh = lh->next;

	while(lh) {
		++size;
		lh = lh->next;
	}
	return size;
}
