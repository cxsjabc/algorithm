#include "common_local.h"


typedef struct _Node
{
	int data;
	struct _Node *next;
}Node;

Node *_alloc_list_node(int data)
{
	Node *p;

	p = (Node *)malloc(sizeof(Node));
	if(!p)
		return NULL;

	p->data = data;
	p->next = NULL;
	return p;
}

Node *	mylist_create(Node *p)
{
	return p;
}

Node *	mylist_append(Node *p, int data)
{
	Node *h = p;
	Node *n;

	if(!p) {
		n = _alloc_list_node(data);
		assert(n);
		return n;	
	}

	while(h->next != NULL)
		h = h->next;

	n = _alloc_list_node(data);
	assert(n);

	h->next = n;	
	return p;
}

void mylist_show(Node *p)
{
	while(p) {
		printf("%d ", p->data);
		p = p->next;
	}
}

void	mylist_free(Node *p)
{
	Node *n;

	while(p) {
		n = p->next;
		free(p);	
		p = n;
	}
}

int main()
{
	Node *p;

	p = mylist_create(NULL);
	p = mylist_append(p, 10);
	p = mylist_append(p, 1);
	p = mylist_append(p, 0);

	mylist_show(p);

	mylist_free(p);

    return 0;
}
