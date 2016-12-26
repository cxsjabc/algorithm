#include <stdio.h>
#include <math.h>

int main()
{
	int i, j;
	for(i = 1; i < 10; ++i) {
		for(j = 0; j < 10; ++j) {
			int m = 1100 * i + 11 * j;
			int temp = (int)sqrt(m);
			if (temp * temp == m)
				printf("%d\n", m);
			
		}
	}

    return 0;
}
