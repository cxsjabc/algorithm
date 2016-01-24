#include <stdio.h>

#include "common.h"
#include "stack.h"

int main()
{
	STACK *stack = stack_create(1);
	int i;

	stack_push(stack, 10);
	stack_push(stack, 20);
	stack_push(stack, 30);
	stack_push(stack, 40);
	stack_push(stack, 50);
	stack_push(stack, 60);
	stack_show(stack);

	stack_pop(stack);
	stack_show(stack);

	for(i = 0; i < 10000; ++i) {
		stack_push(stack, i * 10);
	}

	stack_show(stack);

	stack_free(stack);

	
	return 0;
}
