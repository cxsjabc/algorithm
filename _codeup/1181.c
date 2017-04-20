#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

// ax^2 + bx + c = 0
// return value: the root count, if return 1, the value is stored in v1.
int	get_equation_value(double a, double b, double c, 
						double *v1, double *v2, int *is_imaginary_root)
{
	double delta;
	int cnt;

	if(is_imaginary_root)
		*is_imaginary_root = 0;

	delta = b * b - 4 * a * c;
	if(delta < 0) {
		cnt = 2;
		if(is_imaginary_root)
			*is_imaginary_root = 1;
	}
	else if(fabs(delta) <= 1e-15)
		cnt = 1;
	else
		cnt = 2;

	if(cnt == 1)
		*v1 = -1 * b / (2 * a);
	else if(cnt == 2) {
		if(*is_imaginary_root == 1) {
			delta = -delta;
			*v1 = (-1. * b) / (2 * a);
			*v2 = sqrt(delta) / (2 * a);
			if(*v2 < 0)
				*v2 = -(*v2);
		} else {
			*v1 = (-b - sqrt(delta)) / (2 * a);
			*v2 = (-b + sqrt(delta)) / (2 * a);
		}
	}
	return cnt;	
}

int main()
{
	int a, b, c;
	int ret;
	double v1, v2;
	int is_imaginary_root;

	scanf("%d%d%d", &a, &b, &c);

	if(a == 0) {
		printf("not a quadratic\n");
		return 0;
	}
	
	ret = get_equation_value(a, b, c, &v1, &v2, &is_imaginary_root);
	if(ret == 0)
		printf("no answer\n");
	else if(ret == 1)
		printf("two equal roots:%.4f\n", v1);
	else if(ret == 2) {
		if(is_imaginary_root)
			printf("complex roots:%.4f+%.4fi %.4f-%.4fi\n", v1, v2, v1, v2);
		else
			printf("distinct real roots:%.4f %.4f\n", v1, v2);
	}
	
	return 0;
}
