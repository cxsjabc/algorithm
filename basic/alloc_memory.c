#include <stdio.h>

#include "common_local.h"


int main()
{
	char *p;

	p = (char *)malloc(128);  // Test on Mac for 3 times: is zero..
	if(p) {
		print_by_byte(p, 128);
		free(p);
	}
	
	return 0;
}
