#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n;
	double s;

	scanf("%d", &n);
	if(n <= 150)
		s = 0.4463 * n;
	else if(n <= 400)	
		s = 0.4463 * 150 + (n - 150) * 0.4663;
	else {
		s = 0.4463 * 150 + 250 * 0.4663 + (n - 400) * 0.5663;
	}
	printf("%.1f\n", s);
	return 0;
}
