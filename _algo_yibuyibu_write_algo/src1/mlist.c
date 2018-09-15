#include "common_local.h"

typedef struct _mlist_node
{
	int 	v;
	struct _mlist_node	*next;
}mlist_node;

mlist_node *	mlist_alloc(int v)
{
	mlist_node *l;

	l = (mlist_node *)malloc(sizeof(mlist_node));
	if(!l)
		return NULL;

	l->v = v;
	l->next = NULL;
	return l;
}

void	mlist_free(mlist_node *l)
{
	if(l) {
		mlist_node *n = l->next;
		free(l);
		mlist_free(n);
	}
}

mlist_node	*mlist_append(mlist_node **pl, int v)
{
	if(*pl != NULL)
		return mlist_append(&((*pl)->next), v);
	else {
		mlist_node *node;
		node = (mlist_node *)malloc(sizeof(mlist_node));
		if(!node)
			return NULL;
		node->v = v;
		node->next = NULL;
		*pl = node;
		return node;
	}	
}

int		mlist_delete(mlist_node **pl, int v)
{
	if(*pl) {
		if((*pl)->v == v) {
			mlist_node *n = *pl;
			*pl = (*pl)->next;
			free(n);
			return 1; 
		} else {
			return mlist_delete(&((*pl)->next), v);
		}
	} 

	return 0;
}

void	mlist_show(mlist_node *l)
{
	if(l) {
		printf("%d ", l->v);
		mlist_show(l->next);
	} else
		printf("\n");
}

mlist_node *mlist_reverse(mlist_node *l)
{
	mlist_node *n, *p;
	if(!l)
		return NULL;

	n = l->next;
	l->next = NULL;

	while(n) {
		p = n;
		n = n->next;
		p->next = l;
		l = p;
	}
	return p;
}

int main()
{
	mlist_node *l, *l1;

	l = mlist_alloc(10);
	assert(l);

	mlist_append(&l, 1);
	mlist_append(&l, 2);

	mlist_show(l);
	l = mlist_reverse(l);
	mlist_show(l);
	mlist_delete(&l, 1);
	mlist_show(l);
	mlist_free(l);

	l1 = NULL;
	mlist_append(&l1, 5);
	mlist_append(&l1, 6);
	mlist_delete(&l1, 6);
	mlist_show(l1);
	mlist_free(l1);

    return 0;
}
