#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, b, c;
	int max;
	scanf("%d%d%d", &a, &b, &c);
	
	if(a >= b) {
		if(a > c)
			max = a;
		else
			max = c;
	} else {
		if(b >= c) 
			max = b;
		else {
			max = c;
		}
	}

	printf("%d\n", max);
	return 0;
}
