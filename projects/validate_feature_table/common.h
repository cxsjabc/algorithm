#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>

#define TO_BOOL_STR(n)			(((n) != 0 ) ? "true" : "false")	

#define LOG_HERE		printf("[Log]Func:%s,Line:%d\n", __FUNCTION__, __LINE__)

#endif
