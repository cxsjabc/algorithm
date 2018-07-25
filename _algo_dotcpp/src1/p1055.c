#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

void print_oct(int n)
{
	if(n == 0)
		return;
	print_oct(n / 8);
	printf("%d", n % 8);
}

int main()
{
	int n;

	INPUT(n);
	if(n == 0)
		printf("%d\n", 0);
	else
		print_oct(n), printf("\n");
	return 0;
}
