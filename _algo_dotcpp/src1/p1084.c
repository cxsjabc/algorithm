#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 
#include <assert.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

void show_results(int n)
{
	int *p;
	int i;

	p = (int *)malloc((n + 1) * sizeof(int));
	assert(p != NULL);
	for(i = 2; i <= n; ++i)
		p[i] = 1;

	for(i = 2; i <= n; ++i) {
		int j;
		for(j = i + 1; j <= n; ++j)
			if(j % i == 0)
				p[j] = 0;
	}

	for(i = 2; i <= n; ++i)
		if(p[i])
			printf("%d\n", i);
}

int main()
{
	int n;

	INPUT(n);
	show_results(n);
	return 0;
}
