#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <limits.h> 

int get_pencil_min()
{
	int n;
	int pn, pp;
	int min = INT_MAX;
	int i = 1;
	
	scanf("%d", &n);
	while(i <= 3) {
		scanf("%d%d", &pn, &pp);		
		if(n < pn && min >= pp) {
			min = pp;
		}
		else if(n % pn == 0) {
			if(n / pn * pp < min)
				min = n / pn * pp;
		} else {
			if((n + pn - 1) / pn * pp < min)
				min = (n + pn - 1) / pn * pp;
		}

		++i;
	}
	return min;
}

int main()
{
	printf("%d\n", get_pencil_min());
	return 0;
}
