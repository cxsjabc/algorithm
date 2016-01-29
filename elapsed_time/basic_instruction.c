#include <stdio.h>

#include "common.h"


int main()
{
	int i;

	TIME_START(10000)
	i = 100;
	TIME_END
	
	TIME_START(10000)
	i = 0;
	TIME_END

	return 0;
}
