#ifndef DHLIST_H
#define DHLIST_H

// dhlist with header node
typedef struct _DHList
{
	int v;
	struct _DHList *prev;
	struct _DHList *next;
} DHList;

typedef DHList 	*PDHList, *PDHListHead, *PDHListNode;
typedef DHList	DHListNode;

PDHListHead	dhlist_create();

int			dhlist_insert(PDHListHead lh, PDHListNode pln, int v);
int			dhlist_remove(PDHListHead lh, PDHListNode pln);

PDHListNode	dhlist_get_node(PDHListHead lh, int index);
int			dhlist_get_node_value(PDHListHead lh, int index);

void		dhlist_show(PDHListHead lh);

void		dhlist_destroy(PDHListHead lh);

int			dhlist_size(PDHListHead lh);

#endif
