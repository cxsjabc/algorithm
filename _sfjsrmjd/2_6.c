#include <stdio.h>

int main()
{
	double value = 0;
	double item = 1;
	int i = 1;
	int sign = 1;

	while(item >= 1e-6) {
		value += sign * item;
		
		sign *= -1;
		++i;
		item = 1.0 / (2 * i - 1);
	}
    printf("PI/4 == %lf\n", value);

    return 0;
}
