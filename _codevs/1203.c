#include <stdio.h> 
#include <math.h> 

int main()
{
	double d1, d2;
	const char *p;

	scanf("%lf%lf", &d1, &d2);
	if(fabs(d1 - d2) <= 1e-8)
		p = "yes";
	else
		p = "no";

	printf("%s\n", p);	

    return 0;
}
