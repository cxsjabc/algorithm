#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int max;
	int n;
	int first = 1;

	while(scanf("%d", &n) != EOF && n != -1) {
		if(first)
			max = n, first = 0;
		else {
			if(n > max)
				max = n;
		}
	}
	printf("%d\n", max);

	return 0;
}
