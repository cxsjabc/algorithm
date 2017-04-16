#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

// ax^2 + bx + c = 0
// return value: the root count, if return 1, the value is stored in v1.
int	get_equation_value(double a, double b, double c, double *v1, double *v2)
{
	double delta;
	int cnt;

	delta = b * b - 4 * a * c;
	if(delta < 0)
		cnt = 0;
	else if(fabs(delta) <= 1e-15)
		cnt = 1;
	else
		cnt = 2;

	if(cnt == 1)
		*v1 = -1 * b / (2 * a);
	else if(cnt == 2) {
		*v1 = (-1 * b - sqrt(delta)) / (2 * a);
		*v2 = (-1 * b + sqrt(delta)) / (2 * a);
	}
	return cnt;	
}

int main()
{
	int a, b, c;
	int ret;
	double v1, v2;

	scanf("%d%d%d", &a, &b, &c);

	ret = get_equation_value(a, b, c, &v1, &v2);
	if(ret == 0)
		printf("no answer\n");
	else if(ret == 1)
		printf("%.4f\n", v1);
	else if(ret == 2)
		printf("%.4f %.4f\n", v1, v2);

	return 0;
}
