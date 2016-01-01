#include <stdio.h>
#include <limits.h>

#include "common.h"

int input_num(int *n)
{
	int count = 3;
	int i = 0;

	while( i < count) {
		scanf("%d", n);
		if(*n < 0)
			++i;
		else
			break;
	}
	if(i == count)
		return 0;
	return 1;
}

int main()
{
	int ret, n = INT_MIN;
	ret = input_num(&n);
	PN(ret);
	PN(n);
	return 0;
}
