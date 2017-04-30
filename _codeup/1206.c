#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n = 20;
	int i1 = 2, j1 = 1;
	int i = 1;
	double s = 0;

	while(i <= n) {
		double t = 1.0 * i1 / j1;	
		int j2 = j1;
		s += t;

		j1 = i1;
		i1 = i1 + j2;
		++i;
	}

	printf("%.4f\n", s);
	return 0;
}
