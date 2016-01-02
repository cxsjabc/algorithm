#include <stdio.h>

#include "common.h"

// typedef long short;  // it will cause Compile Error

int main()
{
	short s;
	PL(sizeof(s));
	PL(sizeof(short));
	PL(sizeof(long));
	
	return 0;
}
