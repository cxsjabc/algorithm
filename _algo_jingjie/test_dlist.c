#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "dlist.h"

void test_dlist()
{
	PDListHead plh;
	int i = 1;
	PDListNode node;

	dlist_create(&plh);
	
	while(i < 5) {
		assert(dlist_insert(&plh, NULL, i) == 0);
		++i;
	}

	dlist_show(plh);

	dlist_remove(&plh, NULL);
	dlist_show(plh);

	node = dlist_get_node(plh, 1);
	//printf("node:%p value:%d\n", node, dlist_get_node_value(plh, 1));

	dlist_remove(&plh, node);
	dlist_show(plh);

	dlist_destroy(&plh);

	dlist_create_by_input(&plh);
	dlist_show(plh);
	dlist_destroy(&plh);
}

int main()
{
	test_dlist();

	return 0;
}
