#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "dchlist.h"

void test_dchlist()
{
	PDCHListHead plh;
	int i = 1;
	PDCHListNode node;

	plh = dchlist_create();
	assert(plh);
	
	while(i < 5) {
		assert(dchlist_insert(plh, NULL, i) == 0);
		++i;
	}

	dchlist_show(plh);
	dchlist_show1(plh);

	dchlist_remove(plh, NULL);
	dchlist_show(plh);

	node = dchlist_get_node(plh, 1);
	printf("node:%p value:%d\n", node, dchlist_get_node_value(plh, 1));

	dchlist_remove(plh, node);
	dchlist_show1(plh);

	dchlist_destroy(plh);
}

int main()
{
	test_dchlist();

	return 0;
}
