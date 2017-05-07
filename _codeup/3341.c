#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <limits.h> 

int main()
{
	int i = 1;

	while(i <= INT_MAX) {
		int j = i;
		int a;
#if 0
		if(j % 10000 == 0)
			printf("run: %d\n", j);
#endif
		if(j % 8 == 1 && j % 17 == 4) {
			int k = j / 8;
			if(k % 8 == 1) {
				int m = k / 8;
				if(m % 8 == 7) {
					int n;
					a = m / 8;
					n = j / 17;
					if(n % 17 == 15 && n / 17 == 2 * a) {
						printf("%d\n", j);
					}
				}
			}
		}
		if(i == INT_MAX)
			break;
		++i;
	}
	return 0;
}
