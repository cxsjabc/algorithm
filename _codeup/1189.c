#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int is_in_tower(double x, double y)
{
	int xa[4] = {2, -2, 2, -2};
	int ya[4] = {2, 2, -2, -2};
	int i;
	int dis;
	int out_cnt = 0;

	for(i = 0; i < 4; ++i) {
		dis = (x - xa[i]) * (x - xa[i]) + (y - ya[i]) * (y - ya[i]);
		if(dis > 1) // if dis = sqrt(dis): then maybe fail
			++out_cnt;
	}
	
	if(out_cnt == 4)
		return 0;
	else
		return 1;
}

int main()
{
	double x, y;
	int t;

	scanf("%lf%lf", &x, &y);		
	t = is_in_tower(x, y);
	if(t)
		printf("%.2f\n", 10.);
	else
		printf("%.2f\n", 0.);

	return 0;
}
