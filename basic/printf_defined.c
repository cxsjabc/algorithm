#include <stdio.h>

#include "common_local.h"


int main()
{
#ifdef printf
#warning "printf is defined!"
#else
#warning "printf is not defined!"
#endif	
	return 0;
}
