#include <stdio.h>
#include <string.h>

#include "common.h"
#include "stack.h"

int is_balanced(const char *s)
{
	int i;
	int ret;
	STACK *stack = stack_create(1);

	for(i = 0; i < strlen(s); ++i) {
		char ch = s[i];
		if(stack_is_empty(stack))
			stack_push(stack, ch);
		else {
			int top = stack_top(stack);
			if(ch == ']' && top == '[')
				stack_pop(stack);
			else if(ch == '}' && top == '{')
				stack_pop(stack);
			else if(ch == ')' && top == '(')
				stack_pop(stack);
			else
				stack_push(stack, ch);
		}
	}
	
	ret = stack_is_empty(stack);
	stack_free(stack);

	return ret;

}

int main()
{
	char s[128] = {0};
	printf("Input the symbol:");
	scanf("%s", s);
	printf("Symbol:%s\n", s);

	PN(is_balanced(s));
	
	return 0;
}
