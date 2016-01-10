#include "common.h"

#include "list.h"

int main()
{
	LNode node = {1, NULL};		
	LHead head;

	head = list_create(&node);
	if(!head) {
		printf("list_create failed!\n");
		return -1;
	}
			
	PN(list_is_empty(head));
	list_insert(head, head->next, 2);
	list_insert(head, head->next, 3);
	list_show(head);
	list_delete(head, 2);
	list_show(head);
	list_free(head);

	head = list_create(NULL);
	PN(list_is_empty(head));
	list_free(head);
	
	return 0;
}

