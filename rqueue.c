#include <stdio.h>
#include <stdlib.h>

#include "common_local.h"
#include "rqueue.h"

PRQueue	rqueue_create(int size)
{
	int *data;
	RQueue *queue;

	queue = (RQueue *)malloc(sizeof(RQueue));
	if(!queue)
		goto label_alloc_fail;

	data = (int *)malloc(sizeof(int) * size);
	if(!data)
		goto label_alloc_fail;

	queue->capacity = size;
	queue->size = 0;
	queue->front = 0;
	queue->rear = 0;
	queue->data = data;	
	
	return queue;

label_alloc_fail:
	if(data)
		free(data);
	if(queue)
		free(queue);
	return NULL;	
}

void 	rqueue_show(PRQueue rqueue)
{
	int front = rqueue->front;
	int rear  = rqueue->rear;
	int size = rqueue->size;
	
//	print_arr(rqueue->data + (rqueue->capacity - rqueue->size), size);	
	while(size) {
//		printf("front:%d\n", front);
		if(front == rqueue->capacity)
			front = 0;
		printf("%d ", rqueue->data[front]);
		++front;
		--size;
	}
	printf("\n");
}

void 	rqueue_free(PRQueue rqueue)
{
	if(rqueue->data)
		free(rqueue->data);

	if(rqueue)
		free(rqueue);
}

int		rqueue_enque(PRQueue rqueue, int data)
{
	int front = rqueue->front;
	int rear  = rqueue->rear;

	if(rqueue->size < rqueue->capacity) {
		if(rear == rqueue->capacity) // notice: not rqueue->size
			rear = 0;

		rqueue->data[rear] = data;
		
		++rear;
		rqueue->rear = rear;
		(rqueue->size)++;
		
		return 1;
	} else 
		return 0;
}

int		rqueue_deque(PRQueue rqueue)
{
	int front = rqueue->front;
	int rear  = rqueue->rear;

	if(front == rqueue->capacity)
		front = 0;
	else
		++front;

	rqueue->front = front;
	(rqueue->size)--;
	return 1;
}

