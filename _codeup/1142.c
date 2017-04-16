#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int	is_leap_year(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main()
{
	int y;

	scanf("%d", &y);
	printf("%s\n", is_leap_year(y) ? "leap year" : "not leap year");
	return 0;
}
