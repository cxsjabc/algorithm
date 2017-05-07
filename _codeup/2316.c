#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n, m;
	int *p, *e;
	int i;
	int k = 0;

	scanf("%d", &n);
	p = (int *)malloc(sizeof(int) * n);
	if(!p) {
		printf("no memory!\n");
		return -1;
	}
	
	for(i = 0; i < n; ++i)	
		scanf("%d", &p[i]);

	scanf("%d", &m);
	e = (int *)malloc(sizeof(int) * m);
	if(!e) {
		printf("no memory when alloc extra memory!\n");
		free(p);
		return -2;
	}

	for(i = n - m; i <= n - 1; ++i)
		e[k++] = p[i];
	for(i = n - m - 1; i >= 0; --i)
		p[i + m] = p[i];
	for(i = 0; i < m; ++i)
		p[i] = e[i];
	for(i = 0; i < n; ++i)
		printf("%d ", p[i]);

	free(e);
	free(p);
	return 0;
}
