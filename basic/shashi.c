#include <stdio.h>

#include "common.h"


int main()
{
	unsigned long long n = 0;
	int i = 0;

	while(i < 64) {
		n += (1 << i);
		++i;
	}		

	printf("n:%llu\n", n);
	return 0;
}
