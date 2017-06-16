#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "hash.h"

void	test_hash()
{
	const char *s = "xiyimaomao";
	int hash;
	char s1[128];

	hash = bkdr_hash(s);
	printf("hash result: 0x%x\n", hash);


	while(1) {
		int ret;
		ret = scanf("%s", s1);	
		if(ret == -1)
			break;
		hash = bkdr_hash(s1);
		printf("hash result: 0x%x\n", hash);
		
	}
}


int main()
{
	test_hash();

	return 0;
}
