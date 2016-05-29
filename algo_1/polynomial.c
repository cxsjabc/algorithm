#include <stdio.h>

#include "common.h"

double polynomial(double arr[], int cnt, double x)
{
	double ret = arr[cnt - 1];
	int i;

	for(i = cnt - 2; i >= 0; --i) 
	{
		ret = ret * x + arr[i];
	}
	return ret;
}


int main()
{
	double arr[4] = {1, 1, 1, 1};
	int x = 4;
	double ret = polynomial(arr, ARR_SIZE(arr), x);
	PD(ret);

	return 0;
}
