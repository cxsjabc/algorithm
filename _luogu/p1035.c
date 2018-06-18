#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int get_min_n(int k)
{
	double s = 0;
	int i = 1;

	while(1) {
		s += (1. / i);
		if(s > k)
			break;
	
		++i;
	}
	return i;
}

int main()
{
	int n;
	scanf("%d", &n);

	printf("%d\n", get_min_n(n));
	return 0;
}
