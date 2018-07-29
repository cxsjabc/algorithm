#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

void show_results(int n, int m)
{
	int s = 2;
	int sum = 0;
	int i = 0, j = 0;

	while(j < n) {
		sum += s;
		if((i + 1) % m == 0 || j == n - 1) {
			printf("%d ", sum / (i + 1));
			sum = 0;
			i = 0;
		} else {
			++i;
		}

		s += 2;
		++j;
	}	
	printf("\n");
}

int main()
{
	int n, m;

	while(INPUT2(n, m) == 2)
		show_results(n,m);
	return 0;
}
