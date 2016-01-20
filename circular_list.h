#ifndef LIST_H
#define LIST_H


struct clist_node;
typedef struct clist_node *LPNode;
typedef struct clist_node *LHead;
typedef struct clist_node  LNode;

struct clist_node
{
	int 	data;
	LPNode  next;
};

LHead 	clist_create(LPNode p);
int		clist_is_empty(LHead clist);
int		clist_is_last(LHead clist, LPNode node);

LPNode	clist_find(LHead clist, int data);

// insert a node before the node
LPNode	clist_insert(LHead clist, LPNode node, int data);

void	clist_delete(LHead clist, int data);
LPNode	clist_get_prev(LHead clist, LPNode node);

LPNode	clist_append(LHead clist, int data);

void 	clist_show(LHead clist);
void 	clist_free(LHead clist);

LHead	clist_merge(LHead clist1, LHead clist2);

#endif
