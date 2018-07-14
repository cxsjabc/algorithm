#include "common_local.h"

#define MAX_SIZE	16	

typedef struct _CirQueue
{
	int	data[MAX_SIZE];
	int	front;
	int rear;
}CirQueue;

void	InitCirQueue(CirQueue *q)
{
	q->front = q->rear = 0;
}

int		CirQueueLength(CirQueue *q)
{
	return (q->rear - q->front + MAX_SIZE) % MAX_SIZE;
}

int		CirQueueEmpty(CirQueue *q)
{
	return q->front == q->rear;
}

int		CirQueueFull(CirQueue *q)
{
	return (q->rear + 1) % MAX_SIZE == q->front;
}

int		CirQueueEnque(CirQueue *q, int v)
{
	if(CirQueueFull(q))
		return -1;

	q->data[q->rear] = v;
	q->rear = (q->rear + 1) % MAX_SIZE;
	return 0;		
}

int		CirQueueDeque(CirQueue *q, int *v)
{
	if(CirQueueEmpty(q))
		return -1;

	if(v)
		*v = q->data[q->front];
	q->front = (q->front + 1) % MAX_SIZE;
	return 0;
}


void	CirQueueDump(CirQueue *q)
{
	int front, rear;

	front = q->front;
	rear = q->rear;

	printf("q->front:%d, q->rear:%d:\n\t", q->front, q->rear);
	while(front != rear) {
		printf("%d ", q->data[front]);
		front = (front + 1) % MAX_SIZE;
	}
	printf("\n");
}

int main()
{
	CirQueue q;
	int i = 1;

	InitCirQueue(&q);	

	while(i <= 10) {
		CirQueueEnque(&q, i);
		++i;
	}

	i = 1;
	while(i <= 5) {
		CirQueueDeque(&q, NULL);
		++i;
	}

	i = 10;
	while(i <= 17) {
		CirQueueEnque(&q, i);
		++i;
	}

	CirQueueDump(&q);

    return 0;
}
