#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"


PStack	stack_create()
{
	PStack s;
	PStackNode node;

	s = (PStack)malloc(sizeof(Stack));
	if(!s)
		return NULL;
	
	node = (PStackNode)malloc(sizeof(StackNode));
	if(!node) {
		free(s);
		return NULL;
	}
	node->v = 0x12345678;
	node->next = NULL;

	s->head = node;
	s->size = 0;	

	return s;
}

int		stack_push(PStack s, int v)
{
	PStackNode node;
	PStackNode head;
	PStackNode next;

	node = (PStackNode)malloc(sizeof(StackNode));
	if(!node)
		return -1;
	
	head = s->head;
	next = head->next;

	node->v = v;
	node->next = next;

	head->next = node;
	++(s->size);
	return 0;
}

int			stack_pop(PStack s)
{
	PStackNode head;
	PStackNode n, nn;
	int v;

	if(s->size < 1)
		return -1;

	head = s->head;
	n = head->next;
	nn = n->next;

	v = n->v;

	free(n);
	head->next = nn;
	--(s->size);

	return 0;
}

int			stack_top(PStack s)
{
	int v;

	if(s->size < 1)
		return -1;

	v = s->head->next->v;

	return v;
}

void		stack_show(PStack s)
{
	PStackNode node = s->head;
	node = node->next;

	while(node) {
		printf("%d ", node->v);
		node = node->next;
	}	
	printf("\n");
}

void		stack_destroy(PStack s)
{
	PStackNode next;
	PStackNode node = s->head;

	while(node) {
		next = node->next;
		free(node);
		node = next;
	}
}

int			stack_size(PStack s)
{
	int size = 0;
	PStackNode node;

	node = s->head->next;

	while(node) {
		++size;
		node = node->next;
	}
	return size;
}
