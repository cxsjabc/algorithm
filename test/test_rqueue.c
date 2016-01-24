#include "common.h"
#include "rqueue.h"

int main()
{
	PRQueue queue;

	queue = rqueue_create(3);
	if(!queue) {
		printf("rqueue_create failed!\n");
		return -1;
	}

	rqueue_enque(queue, 1);			
	rqueue_enque(queue, 2);			
	rqueue_show(queue);

#if 1
	rqueue_enque(queue, 3);
	rqueue_show(queue);

	rqueue_deque(queue);
	rqueue_show(queue);

	rqueue_deque(queue);
	rqueue_show(queue);

	rqueue_deque(queue);
	rqueue_show(queue);
#endif

	rqueue_free(queue);

	
	return 0;
}
