#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, n;

	scanf("%d%d", &a, &n);
	printf("%d\n", a %= (n %= 2));

	return 0;
}
