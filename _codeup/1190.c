#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i = 1, n = 100;
	int sum = 0;

loop:
	if(i <= n) {
		sum += i;
		++i;
		goto loop;
	}

	printf("%d\n", sum);

	return 0;
}
