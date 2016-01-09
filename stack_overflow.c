#include <stdio.h>

#include "common.h"


int main()
{
	char name[4];
	printf("Input the name:");
	gets(name);	

	printf("Hello, %s\n", name);	
	print_by_byte(name, 4);
	return 0;
}
