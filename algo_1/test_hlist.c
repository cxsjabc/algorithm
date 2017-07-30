#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "hlist.h"

void test_hlist()
{
	PHListHead plh;
	int i = 1;
	PHListNode node;

	plh = hlist_create();
	assert(plh);
	
	while(i < 5) {
		assert(hlist_insert(plh, NULL, i) == 0);
		++i;
	}

	hlist_show(plh);

	hlist_remove(plh, NULL);
	hlist_show(plh);

	node = hlist_get_node(plh, 1);
	printf("node:%p value:%d\n", node, hlist_get_node_value(plh, 1));

	hlist_remove(plh, node);
	hlist_show(plh);

	hlist_destroy(plh);
}

int main()
{
	test_hlist();

	return 0;
}
