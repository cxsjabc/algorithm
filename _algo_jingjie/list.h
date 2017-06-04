#ifndef LIST_H
#define LIST_H


typedef struct _List
{
	int v;
	struct _List *next;
} List;

typedef List 	*PList, *PListHead, *PListNode;
typedef List	ListNode;

PListHead	list_create();

int			list_insert(PListHead lh, PListNode pln, int v);
int			list_remove(PListHead lh, PListNode pln);

PListNode	list_get_node(PListHead lh, int index);
int			list_get_node_value(PListHead lh, int index);

void		list_show(PListHead lh);

void		list_destroy(PListHead lh);

#endif
