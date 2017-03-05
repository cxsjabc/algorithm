#include <stdio.h>

#include "common_local.h"


int main()
{
	FILE *fp;
	
	TIME_START(100)
	fp = fopen("file.in", "r");
	if(fp)
		fclose(fp);
	TIME_END
	
	return 0;
}
