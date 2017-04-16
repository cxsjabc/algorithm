#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int t;
	int n;

	scanf("%d", &t);
	while(t--) {
		int i, j;

		scanf("%d", &n);
		for(i = 0; i < n; ++i) {
			for(j = 0; j < n; ++j) {
				printf("%d", (i + 1) * (j + 1));
				if(j != n - 1)
					printf(" ");
			}
			putchar('\n');
		}
	}
	return 0;
}
