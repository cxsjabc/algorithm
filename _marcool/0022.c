#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int	is_leap(long y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main()
{
	long y;
	scanf("%ld", &y);
	printf("%s\n", is_leap(y) ? "TRUE" : "FALSE");
	return 0;
}
