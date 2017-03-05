#include "common_local.h"

#include "list.h"

void test_list_merge()
{
	LHead list1;
	LHead list2;
	LHead list3;
	
	list1 = list_create(NULL);
	//printf("after list1 create\n");
	list2 = list_create(NULL);

	//printf("after list2 create\n");	
	list_insert(list1, NULL, 5);
	list_insert(list1, NULL, 1);
	list_show(list1);

	//printf("after list1 insert\n");	
	list_insert(list2, NULL, 4);
	list_insert(list2, NULL, 3);
	list_show(list2);

	//printf("after list2 insert\n");	

	list3 = list_merge(list1, list2);
	list_show(list3);

	//printf("after merge\n");	

	list_free(list1);
	list_free(list2);	
	list_free(list3);	
}

int main()
{
#if 0
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
#endif

#if 1
	test_list_merge();
#endif	
	return 0;
}

