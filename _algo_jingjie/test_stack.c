#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "stack.h"

void test_stack()
{
	PStack s;
	int i = 1;
	PStackNode node;
	int v;

	s = stack_create();
	assert(s);
	
	while(i < 5) {
		assert(stack_push(s, i) == 0);
		++i;
	}

	v = stack_top(s);
	printf("top:%d\n", v);
	stack_show(s);

	stack_pop(s);
	v = stack_top(s);
	printf("top:%d\n", v);
	stack_show(s);

	stack_pop(s);
	v = stack_top(s);
	printf("top:%d\n", v);
	stack_show(s);

	stack_destroy(s);
}

int main()
{
	test_stack();

	return 0;
}
