#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

void get_distance(int m, int n, double *d1, double *d2)
{
	double t = m;
	double first = t;

	while(n > 1) {
		t += first;
		first /= 2;
		--n;
	}
	if(d1)
		*d1 = t;
	if(d2)
		*d2 = first / 2;
}

int main()
{
	int m, n;
	double d1, d2;

	INPUT2(m, n);
	get_distance(m, n, &d1, &d2);
	printf("%.2f %.2f\n", d2, d1);

	return 0;
}
