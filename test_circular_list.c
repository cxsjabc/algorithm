#define _LOG_ENABLE 1
#define	_LOG_LEVEL LOG_LEVEL_INFO

#include "common.h"

#include "circular_list.h"

void test_clist_merge()
{
	LHead clist1;
	LHead clist2;
	LHead clist3;
	
	clist1 = clist_create(NULL);
	//printf("after clist1 create\n");
	clist2 = clist_create(NULL);

	//printf("after clist2 create\n");	
	clist_insert(clist1, NULL, 5);
	clist_insert(clist1, NULL, 1);
	clist_show(clist1);

	//printf("after clist1 insert\n");	
	clist_insert(clist2, NULL, 4);
	clist_insert(clist2, NULL, 3);
	clist_show(clist2);

	//printf("after clist2 insert\n");	

#if 1
	clist3 = clist_merge(clist1, clist2);
	clist_show(clist3);
	LOG_HERE;
#endif

	//printf("after merge\n");	

	clist_show(clist1);
	LOG_HERE;
	clist_show(clist2);
	LOG_HERE;

	clist_free(clist1);
	LOG_HERE;
	clist_free(clist2);	
	LOG_HERE;
#if 1
	clist_free(clist3);	
	LOG_HERE;
#endif
}

int main()
{
#if 0
	LNode node = {1, NULL};		
	LHead head;

	head = clist_create(&node);
	if(!head) {
		printf("clist_create failed!\n");
		return -1;
	}
			
	PN(clist_is_empty(head));
	clist_insert(head, head->next, 2);
	clist_insert(head, head->next, 3);
	clist_show(head);
	clist_delete(head, 2);
	clist_show(head);
	clist_free(head);

	head = clist_create(NULL);
	PN(clist_is_empty(head));
	clist_free(head);
#endif

#if 1
	test_clist_merge();
#endif	
	return 0;
}

