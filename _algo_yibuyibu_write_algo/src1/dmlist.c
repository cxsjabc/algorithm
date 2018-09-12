#include "common_local.h"

typedef struct _dmlist_node
{
	int 	v;
	struct _dmlist_node	*next;
	struct _dmlist_node	*prev;
}dmlist_node;

dmlist_node *	dmlist_alloc(int v)
{
	dmlist_node *l;

	l = (dmlist_node *)malloc(sizeof(dmlist_node));
	if(!l)
		return NULL;

	l->v = v;
	l->next = l->prev = NULL;
	return l;
}

void	dmlist_free(dmlist_node *l)
{
	if(l) {
		dmlist_node *n = l->next;
		free(l);
		dmlist_free(n);
	}
}

void	dmlist_free1(dmlist_node **l)
{
	if(*l) {
		dmlist_node *n = (*l)->next;
		free(*l);
		*l = n;
		dmlist_free1(l);	
	}
}

dmlist_node *dmlist_find(dmlist_node *l, int v)
{
	while(l) {
		if(l->v == v)
			return l;
		l = l->next;
	}
	return NULL;
}

dmlist_node	*dmlist_append(dmlist_node **pl, int v)
{
	if(*pl != NULL)
		return dmlist_append(&((*pl)->next), v);
	else {
		dmlist_node *node;
		node = (dmlist_node *)malloc(sizeof(dmlist_node));
		if(!node)
			return NULL;
		node->v = v;
		node->next = node->prev = NULL;
		*pl = node;
		return node;
	}	
}

dmlist_node	*dmlist_append1(dmlist_node **pl, int v)
{
	if(*pl == NULL) {
		*pl = dmlist_alloc(v);
		return *pl;
	}

	while((*pl)->next != NULL) {
		pl = &((*pl)->next);
	}
	(*pl)->next = dmlist_alloc(v);
	(*pl)->next->prev = *pl;
	return *pl;
}

int		dmlist_delete(dmlist_node **pl, int v)
{
	if(*pl) {
		if((*pl)->v == v) {
			dmlist_node *n = *pl;
			*pl = (*pl)->next;
			free(n);
			return 1; 
		} else {
			return dmlist_delete(&((*pl)->next), v);
		}
	} 

	return 0;
}

void	dmlist_show(dmlist_node *l)
{
	if(l) {
		printf("%d ", l->v);
		dmlist_show(l->next);
	} else
		printf("\n");
}

int main()
{
	dmlist_node *l, *l1;

	l = dmlist_alloc(10);
	assert(l);

	dmlist_append(&l, 1);
	dmlist_append(&l, 2);

	dmlist_show(l);
	dmlist_delete(&l, 1);
	dmlist_show(l);
	dmlist_free1(&l);

	l1 = NULL;
	dmlist_append(&l1, 5);
	dmlist_append(&l1, 6);
	dmlist_delete(&l1, 6);
	dmlist_show(l1);
	dmlist_free1(&l1);

    return 0;
}
