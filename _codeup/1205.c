#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i = 1, n = 1000;

	while(i <= n) {
		int j = i, k = i;
		int m = 1;
		int p = 0;
		int arr[1000] = {0};

		//printf("%d\n", i);
		while(m < j) {
			if(j % m == 0)
				k -= m, arr[p++] = m;
			++m;
		}
		if(k == 0) {
			int k = 0;
			printf("%d:", i);
			while(k < p) {
				printf(" %d", arr[k]);
				++k;
			}
			printf("\n");
		}
		++i;
	}
	return 0;
}
