#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i, j, k;

	for(i = 'X'; i <= 'Z'; ++i) {
		for(j = 'X'; j <= 'Z'; ++j) {
			for(k = 'X'; k <= 'Z'; ++k) {
				if(i != 'X' && k != 'X' && k != 'Z' && i != j && j != k && i != k)	
					printf("A %c\n", i), printf("B %c\n", j), printf("C %c\n", k);
			}	
		}
	}	
	return 0;
}
