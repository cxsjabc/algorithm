#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double t = 100;
	int i = 1;
	int n;
	double s = 0;
	double rebound;

	scanf("%d", &n);
	while(i <= n) {
		s += t;		
		rebound = t / 2;
		if(i != n)
			s += rebound;

		t /= 2;
		++i;
	}

	printf("%.4f %.4f\n", s, rebound);
	return 0;
}
