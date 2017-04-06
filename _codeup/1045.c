#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 


/* Not Right */
int main()
{
	int t;
	double d;
	int n;
	long long l;

	scanf("%d", &t);
	while(t--) {
		int i = 0;
		scanf("%lf%d", &d, &n);
		while(i++ < n) {
			d *= 10;
		}
		l = (long long)d;
		printf("%ld\n", l % 10);
	}

	return 0;
}
