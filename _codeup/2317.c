#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

// joseph circle
int main()
{
	int n;
	int m = 3;
	int *p;
	int c;
	int i;

	scanf("%d", &n);
	p = (int *)malloc(sizeof(int) * n);
	if(!p) {
		printf("no memory!\n");
		return -1;
	}
	c = n;
	for(i = 0; i < n; ++i)
		p[i] = 1;

	i = 0;
	while(c > 1) {
		int t = 0;
		int find;
		while(t < m) {
			for( ; i < n; ++i) {
				//printf("c:%d,t:%d,i:%d, p[i]:%d\n", c, t, i, p[i]);
				if(p[i]) {
					//printf("%d ", i);
					if(t == m - 1)
						find = i;
					++i;
					if(i == n)
						i = 0;
					break;
				}
				else {
 					if(i == n - 1)
						i = -1;
				}
			}
			++t;			
		}
		p[find] = 0;
		--c;
		//printf("set to 0: %d\n", find);
	}

	for(i = 0; i < n; ++i)
		if(p[i])
			printf("%d\n", i + 1);
	free(p);
	return 0;
}
