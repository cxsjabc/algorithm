#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int k;
	int n1 = 100, n2 = 50, n3 = 10;
	double d = 0;
	
	k = 1;
	while(k <= n1) {
		d += k;
		++k;
	}
	
	k = 1;
	while(k <= n2) {
		d += (k * k);
		++k;
	}	

	k = 1;
	while(k <= n3) {
		d += (1. / k);
		++k;
	}	

	printf("%.4f\n", d);
	return 0;
}
