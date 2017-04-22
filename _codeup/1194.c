#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i = 1, j = 1;
	double pi_4 = 0;
	int flag = 1;	

	while(1) {
		double t = 1.0 * i / j * flag;

		if(fabs(t) < 1e-6)
			break;

		pi_4 += t;
		flag = -flag;
		j += 2;
	}

	pi_4 *= 4;
	printf("%.6f\n", pi_4);

	return 0;
}
