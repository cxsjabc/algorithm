
#define _LOG_LEVEL		DEBUG

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <limits.h> 

#include "common_local.h"


// ugly numbers: 1, 2, 3, 5, 6, 8, 9, 10, ... 

int		is_ugly(int n)
{
	int n1 = n;
	
	log_v("is_ugly:%d +\n", n1);
	if(n == 1)
		return 1;

	while(n != 1) {
		if(n % 2 == 0)
			n /= 2;
		else
			break;
	}
	log_v("after / 2:%d\n", n);
	while(n != 1) {
		if(n % 3 == 0)
			n /= 3;
		else
			break;
	}
	log_v("after / 3:%d\n", n);
	while(n != 1) {
		if(n % 5 == 0)
			n /= 5;
		else
			break;
	}
	log_v("after / 5:%d\n", n);
	log_v("is_ugly:%d, ret:%d\n", n1, n == 1);	
	return n == 1;
}

int		get_ugly_index(int index)
{
	int i = 1;
	int j = 1;

	if(index == 1)
		return 1;

	for(i = 2; i < INT_MAX; ++i) {
		if(is_ugly(i)) {
			++j;
			if(j == index)
				break;
		} 	
	}	
	return i;
}

