#ifndef DLIST_H
#define DLIST_H


typedef struct _DList
{
	int v;
	struct _DList *prv;
	struct _DList *next;
} DList;

typedef DList 	*PDList, *PDListHead, *PDListNode;
typedef DList	DListNode;

PDListHead	dlist_create();

int			dlist_insert(PDListHead lh, PDListNode pln, int v);
int			dlist_remove(PDListHead lh, PDListNode pln);

PDListNode	dlist_get_node(PDListHead lh, int index);
int			dlist_get_node_value(PDListHead lh, int index);

void		dlist_show(PDListHead lh);

void		dlist_destroy(PDListHead lh);

int			dlist_size(PDListHead lh);

#endif
