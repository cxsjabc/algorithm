#ifndef QUEUE_H
#define QUEUE_H

typedef struct _QueueNode
{
	int v;
	struct _QueueNode *next;
} QueueNode;

typedef struct _Queue
{
	int			size;
	QueueNode	*head;
	QueueNode	*tail;
}Queue;

typedef QueueNode 	*PQueueNode;
typedef Queue		*PQueue;

PQueue		queue_create();

int			queue_enque(PQueue s, int v);
int			queue_deque(PQueue s);
int			queue_peek(PQueue s);

void		queue_show(PQueue s);

void		queue_destroy(PQueue s);

int			queue_size(PQueue s);

#endif
