#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, b, c;
	int max;

	scanf("%d%d%d", &a, &b, &c);
	if(a > b)
		max = a;
	else
		max = b;

	if(c > max)
		max = c;
	printf("%d\n", max);
	return 0;
}
