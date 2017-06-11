#ifndef CHLIST_H
#define CHLIST_H

// circle single list with header node
typedef struct _CHList
{
	int v;
	struct _CHList *next;
} CHList;

typedef CHList 	*PCHList, *PCHListHead, *PCHListNode;
typedef CHList	CHListNode;

PCHListHead	chlist_create();

int			chlist_insert(PCHListHead lh, PCHListNode pln, int v);
int			chlist_remove(PCHListHead lh, PCHListNode pln);

PCHListNode	chlist_get_node(PCHListHead lh, int index);
int			chlist_get_node_value(PCHListHead lh, int index);

void		chlist_show(PCHListHead lh);

void		chlist_destroy(PCHListHead lh);

int			chlist_size(PCHListHead lh);

#endif
