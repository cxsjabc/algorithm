#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	unsigned int a = 4294967295;
	int b = -2;

	printf("%d,%o,%x,%u\n", a, a, a, a);
	printf("%d,%o,%x,%u\n", b, b, b, b);
	return 0;
}
