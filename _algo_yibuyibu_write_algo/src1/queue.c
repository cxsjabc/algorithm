#include "common_local.h"

#define REP(n)	for(i = 0; i < (n); ++i)

typedef struct _Queue
{
	int *p;
	int len;
	int cnt;
	int head;
	int tail;
}Queue;

Queue *	queue_alloc(int len)
{
	Queue *q;

	q = (Queue *)malloc(sizeof(Queue));
	if(!q)
		return NULL;

	if(len <= 0)
		goto err_len;
	q->p = (int *)malloc(sizeof(int) * len);
	if(!q->p)
		goto err_alloc_p;

	q->len = len;
	q->cnt = 0;
	q->head = q->tail = 0;

	return q;

err_alloc_p:
err_len:
	free(q);

	return NULL;
}

void	queue_dealloc(Queue *q)
{
	if(q) {
		free(q->p);
		free(q);
	}
}

int		queue_enque(Queue *q, int v)
{
	if(!q)
		return -1;
	if(q->cnt >= q->len - 1)
		return -2;
	q->p[q->tail] = v;
	q->tail = (q->tail + 1) % (q->len);
	q->cnt++;
	return 0;
}

int		queue_deque(Queue *q)
{
	int ret;

	if(!q)
		return -1;
	if(q->cnt < 1)
		return -2;

	ret = q->p[q->head];
	q->head = (q->head + 1) % (q->len);	
	q->cnt--;
	return ret;
}

void queue_show(Queue *q)
{
	if(q) {
		int head = q->head;
		int i = 0;
		while(i < q->cnt) {
			printf("%d ", q->p[head]);
			head = (head + 1) % (q->len);
			++i;
		}
		printf("\n");
	}
}

int		queue_empty(Queue *q)
{
	return q->head == q->tail;
}

int		queue_full(Queue *q)
{
	return (q->tail + 1) % (q->len) == q->head;
}

int main()
{
	Queue *q;
	int i = 1;
	int j = 10;
	q = queue_alloc(10);
	assert(q);

	PD(queue_empty(q));
	PD(queue_full(q));
	while(i <= 10)	
		queue_enque(q, j * i), ++i;
	queue_show(q);	
	PD(queue_empty(q));
	PD(queue_full(q));

	queue_show(q);	

	queue_enque(q, 1);
	REP(5)	
		queue_deque(q);
	REP(3)
		queue_enque(q, i * 100);
	queue_show(q);	

	queue_dealloc(q);
    return 0;
}
