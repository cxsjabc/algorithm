#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n, m;
	int a[50][50];
	int i, j;

	scanf("%d%d", &n, &m);
	for(i = 0; i < n; ++i) {
		for(j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}

	for(i = 0; i < n; ++i) {
		for(j = 0; j < m; ++j) {
			int v = a[i][j];
			int k = -1, l = -1;
			for(k = 0; k < n; ++k) {
				if(k != i && a[k][j] < v)
					break;
			}
			if(k == n) {
				for(l = 0; l < m; ++l) {
					if(l != j && a[i][l] > v)
						break;
				}
			}	
			if(l == m)
				printf("%d %d %d\n", v, i, j);
		}
	}
	return 0;
}
