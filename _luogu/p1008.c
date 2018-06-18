#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

void	get_1_2_3()
{
	int i = 123;
	int j, k;
	int a[10] = {0};

	while(i <= 329) {
		int m = 1;
		memset(a, 0, 10 * sizeof(int));

		j = i * 2;
		k = i * 3;	
		a[i % 10]++, a[i / 100]++, a[(i % 100) / 10]++;
		a[j % 10]++, a[j / 100]++, a[(j % 100) / 10]++;
		a[k % 10]++, a[k / 100]++, a[(k % 100) / 10]++;

		while(m < 10) {
			if(a[m] != 1)
				break;
			++m;
		}

		if(m == 10) {
			printf("%d %d %d\n", i, j, k);
		}	
		++i;
	}
}

int main()
{
	get_1_2_3();
	return 0;
}
