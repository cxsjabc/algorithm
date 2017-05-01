#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int m = 3, n = 4;
	int i, j;
	int a[m][n];
	int max;
	int max_i, max_j;

	for(i = 0; i < m; ++i) {
		for(j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}

	max = a[0][0];
	max_i = max_j = 0;
	for(i = 0; i < m; ++i) {
		for(j = 0; j < n; ++j) {
			if(a[i][j] > max)
				max = a[i][j], max_i = i, max_j = j;
		}
	}
	printf("%d %d %d\n", max, max_i, max_j);
	return 0;
}
