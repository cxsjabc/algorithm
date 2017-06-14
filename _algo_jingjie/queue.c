#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"


PQueue	queue_create()
{
	PQueue s;
	PQueueNode node;

	s = (PQueue)malloc(sizeof(Queue));
	if(!s)
		return NULL;
	
	node = (PQueueNode)malloc(sizeof(QueueNode));
	if(!node) {
		free(s);
		return NULL;
	}
	node->v = 0x12345678;
	node->next = NULL;

	s->head = node;
	s->tail = node;
	s->size = 0;	

	return s;
}

int		queue_enque(PQueue s, int v)
{
	PQueueNode node;
	PQueueNode tail;
	PQueueNode next;

	node = (PQueueNode)malloc(sizeof(QueueNode));
	if(!node)
		return -1;
	
	tail = s->tail;

	node->v = v;
	node->next = NULL;

	s->tail = node;
	tail->next = node;

	++(s->size);
	return 0;
}

int			queue_deque(PQueue s)
{
	PQueueNode head;
	PQueueNode n, nn;
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

int			queue_peek(PQueue s)
{
	int v;

	if(s->size < 1)
		return -1;

	v = s->head->next->v;

	return v;
}

void		queue_show(PQueue s)
{
	PQueueNode node = s->head;
	node = node->next;

	while(node) {
		printf("%d ", node->v);
		node = node->next;
	}	
	printf("\n");
}

void		queue_destroy(PQueue s)
{
	PQueueNode next;
	PQueueNode node = s->head;

	while(node) {
		next = node->next;
		free(node);
		node = next;
	}
}

int			queue_size(PQueue s)
{
	int size = 0;
	PQueueNode node;

	node = s->head->next;

	while(node) {
		++size;
		node = node->next;
	}
	return size;
}
