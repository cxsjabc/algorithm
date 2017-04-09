#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a[3][3];
	int i, j;

	for(i = 0; i < 3; ++i) {
		for(j = 0; j < 3; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	
	for(i = 0; i < 3; ++i) {
		for(j = 0; j < 3; ++j) {
			printf("%d", a[j][i]);
			if(j < 2)
				printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
