#ifndef DLIST_H
#define DLIST_H

// double linked list

// dlist without header node
typedef struct _DList
{
	int v;
	struct _DList *prev;
	struct _DList *next;
} DList;

typedef DList 	*PDList, *PDListHead, *PDListNode;
typedef DList	DListNode, DListHead;

PDListHead	dlist_create(PDListHead *plh);
PDListHead	dlist_create_by_input(PDListHead *plh);

// insert a node which value is v after pln
int			dlist_insert(PDListHead *lh, PDListNode pln, int v);
// remove a node which after pln, if pln is NULL, remove the first node
int			dlist_remove(PDListHead *lh, PDListNode pln);

PDListNode	dlist_get_node(PDListHead lh, int index);
int			dlist_get_node_value(PDListHead lh, int index);

void		dlist_show(PDListHead lh);

void		dlist_destroy(PDListHead *lh);

int			dlist_size(PDListHead lh);

#endif
