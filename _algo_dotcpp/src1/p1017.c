#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

void print_wanshu(int n)
{
	int i = 2;

	for(; i <= n; ++i) {
		int i1 = i;
		int j = 2;
		int v = 1;
		for(; j < i; ++j) {
			int k = j;
			if(i1 % k == 0)
				v += k;
		}
		if(v == i) {
			printf("%d its factors are 1 ", i);
			i1 = i;
			for(j = 2; j < i; ++j)
				if(i1 % j == 0)
					printf("%d ", j);
			printf("\n");
		}
	}	
}

int main()
{
	int n;

	INPUT(n);
	print_wanshu(n);
	return 0;
}
