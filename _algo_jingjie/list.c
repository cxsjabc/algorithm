#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"


PListHead	list_create()
{
	PListNode pln = (PListNode)malloc(sizeof(ListNode));
	if(!pln)
		return NULL;
	
	pln->v = 0xABCDABCD; // just a special value indicates header node
	pln->next = NULL;	

	return pln;
}

int		list_insert(PListHead lh, PListNode pln, int v)
{
	PListNode node = (PListNode)malloc(sizeof(ListNode));

	if(!node)
		return -1;

	if(!pln) {	// if pln is NULL, insert after header node.
		PListNode next = lh->next;
		node->v = v;
		node->next = next;
		lh->next = node;
		return 0;
	} else {
		PListNode next = pln->next; 
		node->v = v;
		node->next = next;
		pln->next = node;
		return 0;
	}
	
}

int			list_remove(PListHead lh, PListNode pln)
{
	PListNode node = lh->next;
	if(!pln) {	// pln is NULL, remove first node(not header node)
		if(!node)
			return -1;
		else {
			PListNode next = node->next;
			free(node);
			lh->next = next;
			return 0;
		}
	} else {
		PListNode next = pln->next;
		if(!next)
			return -2;
		else {
			PListNode nn = next->next;
			free(next);
			pln->next = nn;
			return 0;
		}
	}
}

PListNode	list_get_node(PListHead lh, int index)
{
	PListNode node = lh;
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

int			list_get_node_value(PListHead lh, int index)
{
	PListNode node = list_get_node(lh, index);
	if(!node)
		return -1;
	return node->v;
}

void		list_show(PListHead lh)
{
	PListNode node = lh->next;

	while(node) {
		printf("%d ", node->v);
		node = node->next;
	}	
	printf("\n");
}

void		list_destroy(PListHead lh)
{
	PListNode pln;
	PListNode node = lh;

	while(node) {
		pln = node->next;
		free(node);
		node = pln;
	}
}
