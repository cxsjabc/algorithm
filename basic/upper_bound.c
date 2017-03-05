#include <stdio.h>

#include "common_local.h"


int main()
{
	int d, upper_bound;
	int result;

	while(1) {
		char ch;
		printf("Input value and upper bound:");
		scanf("%d%d", &d, &upper_bound);
	
		result = (d + (upper_bound - 1) ) / upper_bound;
		printf("Result:%d\n", result);
		
		ch = getchar();
		if(ch == 'q')
			break;	
	}

	return 0;
}
