#include <stdio.h>

#include "common_local.h"


int main()
{
	int i;
	for(i = 0; i < INT_MAX - 1; ++i)
 		if(is_square(i))
			printf("%d\n", i);	
	return 0;
}
