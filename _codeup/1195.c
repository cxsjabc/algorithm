#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int f1 = 1, f2 = 1;	
	int i = 3, n = 40;

	printf("%d %d ", f1, f2);
	while(i <= 40) {
		int t = f1 + f2;
		printf("%d ", t);

		f1 = f2;
		f2 = t;
		++i;
	}
	printf("\n");
	return 0;
}
