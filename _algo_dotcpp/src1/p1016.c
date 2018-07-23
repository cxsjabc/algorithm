#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

void print_shuixianhua()
{
	int i, j, k;

	for(i = 1; i <= 9; ++i) {
		for(j = 0; j <= 9; ++j) {
			for(k = 0; k <= 9; ++k) {
				if(i * i * i + j * j * j + k * k * k == 100 * i + 10 * j + k)
					printf("%d\n", 100 * i + 10 * j + k);
			}
		}
	}
}

int main()
{
	print_shuixianhua();
	return 0;
}
