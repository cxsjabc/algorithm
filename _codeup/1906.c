#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int m, n;
	
	while(scanf("%d%d", &m, &n) != EOF) {
		int sum = 0;
		while(m != 0) {
			int m1 = m % 10;
			int n0 = n;
			while(n0 != 0) {
				int n1 = n0 % 10;
				sum += m1 * n1;
				n0 /= 10;
			}
			m = m / 10;
		}
		printf("%d\n", sum);
	}

	return 0;
}
