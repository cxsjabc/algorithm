#ifndef QUEUE_H
#define QUEUE_H


struct queue_node;
typedef struct queue_node *LPNode;
typedef struct queue_node *LHead;
typedef struct queue_node  LNode;

struct queue_node
{
	int 	data;
	LPNode  next;
};

LHead 	queue_create(LPNode p);
int		queue_is_empty(LHead queue);
int		queue_is_last(LHead queue, LPNode node);

LPNode	queue_find(LHead queue, int data);

// insert a node before the node
LPNode	queue_insert(LHead queue, LPNode node, int data);

void	queue_delete(LHead queue, int data);
LPNode	queue_get_prev(LHead queue, LPNode node);

void 	queue_show(LHead queue);
void 	queue_free(LHead queue);

LPNode	queue_enque(LHead queue, int data);
int		queue_deque(LHead queue);

#endif
