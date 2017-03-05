#include <stdio.h>

#include "common_local.h"


#if 0
#define DEFINE_A_FUNC
void DEFINE_A_FUNC() // CE
{
	
}
#endif

#if 1
void DEFINE_A_FUNC()
{
}
#define DEFINE_A_FUNC
// NCE	
#endif

int main()
{

#if 1
	DEFINE_A_FUNC();			
#endif

	return 0;
}
