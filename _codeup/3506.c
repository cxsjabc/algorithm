#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	double a, b;
	double res;
	char c;

	while(scanf("%lf %c %lf", &a, &c, &b) != EOF) {
		if(c == '+')
			res = a + b;
		else if(c == '-')
			res = a - b;
		else if(c == '*')
			res = a * b;
		else if(c == '/') {
			if(fabs(b) < 1e-15) {
				printf("Divide by zero.\n");
				continue;
			}
			else
				res = a / b;
		}
		printf("%.2f\n", res);
	}
	return 0;
}
