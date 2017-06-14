#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "queue.h"

void test_queue()
{
	PQueue s;
	int i = 1;
	PQueueNode node;
	int v;

	s = queue_create();
	assert(s);
	
	while(i < 5) {
		assert(queue_enque(s, i) == 0);
		++i;
	}

	v = queue_peek(s);
	printf("peek:%d\n", v);
	queue_show(s);

	queue_deque(s);
	v = queue_peek(s);
	printf("peek:%d\n", v);
	queue_show(s);

	queue_enque(s, 100);
	v = queue_peek(s);
	printf("peek:%d\n", v);
	queue_show(s);

	queue_deque(s);
	v = queue_peek(s);
	printf("peek:%d\n", v);
	queue_show(s);

	queue_destroy(s);
}

int main()
{
	test_queue();

	return 0;
}
