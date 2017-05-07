#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

const int d_in_m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int d_in_m_l[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int	is_leap_year(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main()
{
	int y, m, d;
	const int *pd_in_m;
	int i;
	int days = 0;

	pd_in_m = d_in_m;

	scanf("%d%d%d", &y, &m, &d);
	if(is_leap_year(y))
		pd_in_m = d_in_m_l;
	
	for(i = 0; i < m - 1; ++i)
		days += pd_in_m[i];
	days += d;

	printf("%d\n", days);
	return 0;
}
