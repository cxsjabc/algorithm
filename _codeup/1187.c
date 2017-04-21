#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i;
	double t = 0;

	scanf("%d", &i);
	if(i <= 10e4)
		t = i * 0.1;
	else if(i <= 20e4)
		t = 10000 + (i - 10e4) * 0.075;
	else if(i <= 40e4)
		t = 10000 + 7500 + (i - 20e4) * 0.05;
	else if(i <= 60e4)
		t = 10000 + 7500 + 10000 + (i - 40e4) * 0.03;
	else if(i <= 100e4)
		t = 10000 + 7500 + 10000 + 6000 + (i - 60e4) * 0.015;
	else 
		t = 10000 + 7500 + 10000 + 6000 + 6000 + (i - 100e4) * 0.01;
	

	printf("%.2f\n", t);
	return 0;
}
