#ifndef HLIST_H
#define HLIST_H

// hlist with header node
typedef struct _HList
{
	int v;
	struct _HList *next;
} HList;

typedef HList 	*PHList, *PHListHead, *PHListNode;
typedef HList	HListNode;

PHListHead	hlist_create();

int			hlist_insert(PHListHead lh, PHListNode pln, int v);
int			hlist_remove(PHListHead lh, PHListNode pln);

PHListNode	hlist_get_node(PHListHead lh, int index);
int			hlist_get_node_value(PHListHead lh, int index);

void		hlist_show(PHListHead lh);

void		hlist_destroy(PHListHead lh);

int			hlist_size(PHListHead lh);

#endif
