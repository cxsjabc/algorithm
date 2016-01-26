#define _LOG_LEVEL	LOG_LEVEL_INFO

#include <stdio.h>

#include "common.h"
#include "array.h"

int main()
{
	PArray arr;
	int i;

	arr = array_create(2);
	LOG_V("after array create");

	for(i = 0; i < 100; ++i)
		array_push_back(arr, i * 10);

	LOG_V("after array push back");

	for(i = 0; i < 14; ++i)
		array_pop_back(arr);
	LOG_V("after array pop back");

	array_show(arr);
	LOG_V("after array show");

	array_free(arr);	
	LOG_V("after array free");

	return 0;
}
