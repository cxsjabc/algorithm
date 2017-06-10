#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dhlist.h"


PDHListHead	dhlist_create()
{
	PDHListNode pln = (PDHListNode)malloc(sizeof(DHListNode));
	if(!pln)
		return NULL;
	
	pln->v = 0xABCDABCD; // just a special value indicates header node
	pln->next = NULL;	

	return pln;
}

int		dhlist_insert(PDHListHead lh, PDHListNode pln, int v)
{
	PDHListNode node = (PDHListNode)malloc(sizeof(DHListNode));

	if(!node)
		return -1;

	if(!pln) {	// if pln is NULL, insert after header node.
		PDHListNode next = lh->next;
		node->v = v;
		node->next = next;
		lh->next = node;
		return 0;
	} else {
		PDHListNode next = pln->next; 
		node->v = v;
		node->next = next;
		pln->next = node;
		return 0;
	}
	
}

int			dhlist_remove(PDHListHead lh, PDHListNode pln)
{
	PDHListNode node = lh->next;
	if(!pln) {	// pln is NULL, remove first node(not header node)
		if(!node)
			return -1;
		else {
			PDHListNode next = node->next;
			free(node);
			lh->next = next;
			return 0;
		}
	} else {
		PDHListNode next = pln->next;
		if(!next)
			return -2;
		else {
			PDHListNode nn = next->next;
			free(next);
			pln->next = nn;
			return 0;
		}
	}
}

PDHListNode	dhlist_get_node(PDHListHead lh, int index)
{
	PDHListNode node = lh;
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

int			dhlist_get_node_value(PDHListHead lh, int index)
{
	PDHListNode node = dhlist_get_node(lh, index);
	if(!node)
		return -1;
	return node->v;
}

void		dhlist_show(PDHListHead lh)
{
	PDHListNode node = lh->next;

	while(node) {
		printf("%d ", node->v);
		node = node->next;
	}	
	printf("\n");
}

void		dhlist_destroy(PDHListHead lh)
{
	PDHListNode pln;
	PDHListNode node = lh;

	while(node) {
		pln = node->next;
		free(node);
		node = pln;
	}
}

int			dhlist_size(PDHListHead lh)
{
	int size = 0;
	lh = lh->next;

	while(lh) {
		++size;
		lh = lh->next;
	}
	return size;
}
