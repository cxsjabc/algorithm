#include "common.h"
#include "circular_list.h"


int	josephus(LHead list, int total, int unit)
{
	LPNode	node = list->next;
	int remain = total;
	int i;	
	LPNode	prv_node = list;

	while(remain > 1) {
		i = 0;
		while(i < unit - 1) {
			prv_node = node;
			node = node->next;
			if(node == list)
				node = list->next, prv_node = list;
			++i;
		}
		// remove the node	
		prv_node->next = node->next;
		printf("Remove:%d\n", node->data);
		free(node);	
		node = prv_node->next;
		
		--remain;
	}
	return 1;
}

int main()
{
	LHead clist = clist_create(NULL);
	int i;

	for(i = 1; i <= 10; ++i)
		clist_append(clist, i);

	josephus(clist, 10, 3);	
	
	return 0;
}
