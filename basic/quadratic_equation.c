#include <stdio.h>

#include "common_local.h"


int main()
{
	int a, b, c;
	double n;
	double x1, x2;
	scanf("%d%d%d", &a, &b, &c);

	n = b * b - 4 * a * c;
	if(n > 0) {
		x1 = (-b + sqrt(n)) / (2 * a);
		x2 = (-b - sqrt(n)) / (2 * a);
		printf("x1:%f, x2:%f\n", x1, x2);
	} else if (n == 0) {
		x1 = -b / (2 * a);
		printf("x:%f\n", x1);
	} else {
		printf("No answer!\n");
	}

	return 0;
}
