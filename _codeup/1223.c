#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define N	10

int main()
{
	int a[N][N];
	int n;
	int i, j;
	int sum = 0;

	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		for(j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}	
	}

	for(i = 0; i < n; ++i)
		sum += a[i][i];
	printf("%d\n", sum);
	return 0;
}
