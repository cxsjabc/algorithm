#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "dhlist.h"

void test_dhlist()
{
	PDHListHead plh;
	int i = 1;
	PDHListNode node;

	plh = dhlist_create();
	assert(plh);
	
	while(i < 5) {
		assert(dhlist_insert(plh, NULL, i) == 0);
		++i;
	}

	dhlist_show(plh);

	dhlist_remove(plh, NULL);
	dhlist_show(plh);

	node = dhlist_get_node(plh, 1);
	printf("node:%p value:%d\n", node, dhlist_get_node_value(plh, 1));

	dhlist_remove(plh, node);
	dhlist_show(plh);

	dhlist_destroy(plh);
}

int main()
{
	test_dhlist();

	return 0;
}
