#include <stdio.h> 

int main()
{
	int level = 3;
    int i, j;
	
    for(i = 1; i <= level; ++i) {
		for(j = i; j < level; ++j)
			printf(" ");    
		for(j = 1; j <= 2 * i - 1; ++j)
			printf("*");    
		printf("\n");    
		
    }
    return 0;
}
