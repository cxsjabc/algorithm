#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int get_matrix_max(int **a, int r)
{
	int max = a[0][0];
	int i, j;

	for(i = 0; i < r; ++i) {
		for(j = 0; j < 4; ++j) {
			if(a[i][j] > max)	// a[i][j] means: *(*(a + i) + j)
				max = a[i][j];
		}
	}
	return max;
}

int main()
{
	int a[3][4];
	int r = 3, c = 4;
	int i, j;
	int max;	

	for(i = 0; i < r; ++i) {
		for(j = 0; j < c; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	max = get_matrix_max(a, 3);
	printf("%d\n", max);
	return 0;
}
