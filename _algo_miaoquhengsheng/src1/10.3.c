#include "common_local.h"

void print_sum_50()
{
	float sum = 0;
	float m = 2, n = 1;
	int i = 1;

	while(i <= 50) {
		int temp;
		sum += m / n;		
	
		temp = m + n;
		n = m;
		m = temp;
		++i;
	}

	printf("%f\n", sum);
}

int main()
{
	print_sum_50();
    return 0;
}
