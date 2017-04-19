#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int f(int x)
{
	if(x < 0)
		return -1;
	else if(x == 0)
		return 0;
	else
		return 1;
}

int main()
{
	int x;

	scanf("%d", &x);
	printf("%d\n", f(x));

	return 0;
}
