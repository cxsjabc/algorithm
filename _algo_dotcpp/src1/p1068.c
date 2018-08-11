#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

int ctof(int c)
{
	return 32 + c * 9 / 5;
}

int main()
{
	int i = -100;

	while(i <= 150) {
		printf("c=%d->f=%d\n", i, ctof(i));
		i += 5;
	}
	return 0;
}
