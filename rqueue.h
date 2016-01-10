#ifndef RQUEUE_H
#define RQUEUE_H


struct rqueue_node;
typedef struct rqueue_node *PRQueue;
typedef struct rqueue_node  RQueue;

struct rqueue_node
{
	int capacity;
	int size;
	int front;
	int rear;
	int	*data;
};

PRQueue	rqueue_create();

void 	rqueue_show(PRQueue rqueue);
void 	rqueue_free(PRQueue rqueue);

int		rqueue_enque(PRQueue rqueue, int data);
int		rqueue_deque(PRQueue rqueue);

#endif
