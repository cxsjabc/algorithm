#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

void fac(int n)
{
	int i = 1;
	static int f = 1;

	while(i <= n) {
		f *= i;
		printf("%d ", f);
		++i;		
	}
	printf("\n");
}

int main()
{
	int n;

	scanf("%d", &n);
	fac(n);	

	return 0;
}
