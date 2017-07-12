#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "common_local.h"
#include "ugly.h"

#ifndef LOG_HERE
#define LOG_HERE	printf("[%s@%d]\n", __func__, __LINE__);
#endif

void 	test_ugly()
{
	while(1) {
		int index;
		int value;

		scanf("%d", &index);

		value = get_ugly_index(index);
		printf("the %d ugly num: %d\n", index, value);
	}
}

int main()
{
	test_ugly();

	return 0;
}
