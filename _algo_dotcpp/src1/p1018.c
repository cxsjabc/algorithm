#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

double get_result(int n)
{
	int i = 2, j = 1;
	double r = 0;

	while(n--) {
		int temp;
		r += (double)i / j;
		temp = i + j;
		j = i;
		i = temp;
	}
	return r;
}

int main()
{
	int n;

	INPUT(n);
	printf("%.2f\n", get_result(n));
	return 0;
}
