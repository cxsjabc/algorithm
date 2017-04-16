#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int	is_leap_year(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main()
{
	int i;

	for(i = 1900; i <= 2000; ++i) {
		if(is_leap_year(i))
			printf("%d\n", i);
	}

	return 0;
}
