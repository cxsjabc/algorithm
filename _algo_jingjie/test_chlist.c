#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "chlist.h"

void test_chlist()
{
	PCHListHead plh;
	int i = 1;
	PCHListNode node;

	plh = chlist_create();
	assert(plh);
	
	while(i < 5) {
		assert(chlist_insert(plh, NULL, i) == 0);
		++i;
	}

	chlist_show(plh);

	chlist_remove(plh, NULL);
	chlist_show(plh);

	node = chlist_get_node(plh, 1);
	printf("node:%p value:%d\n", node, chlist_get_node_value(plh, 1));

	chlist_remove(plh, node);
	chlist_show(plh);

	chlist_destroy(plh);
}

int main()
{
	test_chlist();

	return 0;
}
