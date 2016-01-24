
#define _LOG_LEVEL LOG_LEVEL_WARNING


#include "common.h"

int main()
{
	int tree = 0x1888;	
	LOG_V("tree:%d", tree);	
	LOG_D("tree:%d", tree);	
	LOG_I("tree:%d", tree);	
	LOG_W("tree:%d", tree);	
	LOG_E("tree:%d", tree);	
	LOG_F("tree:%d", tree);	

	return 0;
}
