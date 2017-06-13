#ifndef STACK_H
#define STACK_H

typedef struct _StackNode
{
	int v;
	struct _StackNode *next;
} StackNode;

typedef struct _Stack
{
	int			size;
	StackNode	*head;
}Stack;

typedef StackNode 	*PStackNode;
typedef Stack		*PStack;

PStack		stack_create();

int			stack_push(PStack s, int v);
int			stack_pop(PStack s);
int			stack_top(PStack s);

void		stack_show(PStack s);

void		stack_destroy(PStack s);

int			stack_size(PStack s);

#endif
