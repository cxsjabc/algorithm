#ifndef DCHLIST_H
#define DCHLIST_H

// double circle linked list with header node

// dchlist with header node
typedef struct _DCHList
{
	int v;
	struct _DCHList *prev;
	struct _DCHList *next;
} DCHList;

typedef DCHList 	*PDCHList, *PDCHListHead, *PDCHListNode;
typedef DCHList	DCHListNode;

PDCHListHead	dchlist_create();

int			dchlist_insert(PDCHListHead lh, PDCHListNode pln, int v);
int			dchlist_remove(PDCHListHead lh, PDCHListNode pln);

PDCHListNode	dchlist_get_node(PDCHListHead lh, int index);
int			dchlist_get_node_value(PDCHListHead lh, int index);

void		dchlist_show(PDCHListHead lh);
void		dchlist_show1(PDCHListHead lh);

void		dchlist_destroy(PDCHListHead lh);

int			dchlist_size(PDCHListHead lh);

#endif
