#include <stdio.h>

int main()
{
	double sum = 0;
	int i;

	for(i = 0; ; ++i) {
		double temp = 1. / (2 * i + 1);
		if(i % 2 == 0)
			sum += temp;
		else
			sum -= temp;
		if(temp < 1e-6)
			break;
	}	

    printf("%.6f\n", sum);
    return 0;
}
