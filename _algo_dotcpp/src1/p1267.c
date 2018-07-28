#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

void show_add()
{
	int m, n;

	INPUT2(m, n);
	printf("%d\n", m + n);
}

int main()
{
	show_add();
	return 0;
}
