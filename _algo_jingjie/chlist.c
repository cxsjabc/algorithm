#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "chlist.h"


PCHListHead	chlist_create()
{
	PCHListNode pln = (PCHListNode)malloc(sizeof(CHListNode));
	if(!pln)
		return NULL;
	
	pln->v = 0xABCDABCD; // just a special value indicates header node
	pln->next = pln;	

	return pln;
}

int		chlist_insert(PCHListHead lh, PCHListNode pln, int v)
{
	PCHListNode node = (PCHListNode)malloc(sizeof(CHListNode));

	if(!node)
		return -1;

	if(!pln) {	// if pln is NULL, insert after header node.
		PCHListNode next = lh->next;
		node->v = v;
		node->next = next;
		lh->next = node;
		return 0;
	} else {
		PCHListNode next = pln->next; 
		node->v = v;
		node->next = next;
		pln->next = node;
		return 0;
	}
	
}

int			chlist_remove(PCHListHead lh, PCHListNode pln)
{
	PCHListNode node = lh->next;
	if(!pln) {	// pln is NULL, remove first node(not header node)
		if(node == lh)
			return -1;
		else {
			PCHListNode next = node->next;
			free(node);
			lh->next = next;
			return 0;
		}
	} else {
		PCHListNode next = pln->next;
		if(next == lh)
			return -2;
		else {
			PCHListNode nn = next->next;
			free(next);
			pln->next = nn;
			return 0;
		}
	}
}

PCHListNode	chlist_get_node(PCHListHead lh, int index)
{
	PCHListNode node = lh->next;
	int i = 0;

	assert(index >= 0);

	while(i < index && node != lh) {
		node = node->next;
		++i;
	}
	if(i == index)
		return node;
	else
		return NULL;
}

int			chlist_get_node_value(PCHListHead lh, int index)
{
	PCHListNode node = chlist_get_node(lh, index);
	if(!node)
		return -1;
	return node->v;
}

void		chlist_show(PCHListHead lh)
{
	PCHListNode node = lh->next;

	while(node) {
		if(node == lh) {
			printf("End: Header Node:%d!\n", node->v);
			break;
		}
		printf("%d ", node->v);
		node = node->next;
	}	
	printf("\n");
}

void		chlist_destroy(PCHListHead lh)
{
	PCHListNode pln;
	PCHListNode node = lh->next;

	while(node != lh) {
		pln = node->next;
		free(node);
		node = pln;
	}
	free(lh);
}

int			chlist_size(PCHListHead lh)
{
	int size = 0;
	PCHListNode node = lh->next;

	while(node != lh) {
		++size;
		node = node->next;
	}
	return size;
}
