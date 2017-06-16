#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#include "hash.h"

int		bkdr_hash(const char *s)
{
	int hash = 0;
	char ch;

	while((ch = *s++) != '\0') {
		hash = hash * 131 + ch;
	}	
	return hash;
}
