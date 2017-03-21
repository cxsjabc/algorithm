#include <stdio.h>

#include "common_local.h"


int main()
{
#if 0
	int i = 10000;
	while(i) {
		int j;
		if(j == 0)
			printf("%d:j is 0!! Strange!\n", i);
		else
			printf("%d ", j);	// on mac: the un-assigned j is 32767! Always? 
		--i;
	}	
#endif

#if 1
	{
		char s[128];
		memset(s, '1', 128);
		scanf("%s", s);	// after scanf, s is terminated with nul.
		printf("%s\n", s);

	}
#endif
	return 0;
}
