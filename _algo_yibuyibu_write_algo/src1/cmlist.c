/* bugs */
#include "common_local.h"

typedef struct _cmlist_node
{
	int 	v;
	struct _cmlist_node	*next;
}cmlist_node;

cmlist_node *	cmlist_alloc(int v)
{
	cmlist_node *l;

	l = (cmlist_node *)malloc(sizeof(cmlist_node));
	if(!l)
		return NULL;

	l->v = v;
	l->next = l;
	return l;
}

void	cmlist_free(cmlist_node *l)
{
	if(l) {
		cmlist_node *n = l;
		cmlist_node *nn = l->next;
		while(nn != n) {
			cmlist_node *temp = nn->next;
			free(nn);
			nn = temp;
		}
		free(n);
	}
}

cmlist_node	*cmlist_append(cmlist_node **pl, int v)
{
	if(*pl != NULL) {
		cmlist_node *n = *pl;
		cmlist_node *p;
		while(*pl != n->next)
			n = n->next;
		p = cmlist_alloc(v);
		if(!p)
			return NULL;
		p->next = *pl;
		n->next = p;
		return p;
	}
	else {
		cmlist_node *node;
		node = cmlist_alloc(v);
		if(!node)
			return NULL;
		node->next = node;
		*pl = node;
		return node;
	}	
}

int		cmlist_delete(cmlist_node **pl, int v)
{
	if(*pl) {
		cmlist_node *h = *pl, *p = *pl;
		if(h->v == v) {
			if(h->next == h) {
				free(h);
				*pl = NULL;
				return 1;
			} else {
				while(p->next != h)
					p = p->next;

				p->next = h->next;
				*pl = h->next;
				free(h);
				return 1;
			}
		}

		while(p->next->v != v && p->next != h)
			p = p->next;
		if(p->next->v == v) {	
			cmlist_node *temp = p->next;
			p->next = p->next->next;
			free(temp);	
			return 1; 
		}
	} 

	return 0;
}

void	cmlist_show(cmlist_node *l)
{
	cmlist_node *p = l, *n;
	if(!l)
		return;
	printf("%d ", p->v);
	n = p->next;

	while(n != p) {
		printf("%d ", n->v);
		n = n->next;	
	}
	printf("\n");
}

int main()
{
	cmlist_node *l, *l1;

	l = cmlist_alloc(10);
	assert(l);

	cmlist_append(&l, 1);
	cmlist_append(&l, 2);

	cmlist_show(l);
	cmlist_delete(&l, 1);
	cmlist_show(l);
	cmlist_free(l);

	l1 = NULL;
	cmlist_append(&l1, 5);
	cmlist_append(&l1, 6);
	cmlist_delete(&l1, 6);
	cmlist_show(l1);
	cmlist_free(l1);

    return 0;
}
