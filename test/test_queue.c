#include "common.h"
#include "queue.h"

int main()
{
	LNode node = {1, NULL};		
	LHead head;

	head = queue_create(&node);
	if(!head) {
		printf("queue_create failed!\n");
		return -1;
	}

	queue_enque(head, 1);			
	queue_enque(head, 2);			
	queue_show(head);
	queue_deque(head);
	queue_show(head);
	queue_free(head);

	
	return 0;
}
