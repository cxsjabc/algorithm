#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int process_money()
{
	int i = 1;
	int curr;
	int extra = 0;
	int year_extra = 0;

	while(i <= 12) {
		scanf("%d", &curr);	
		extra += 300;

		if(extra - curr >= 100)
			year_extra += ((extra - curr) / 100) * 100,
			extra -= ((extra - curr) / 100) * 100,
			extra -= curr;		
		else
			extra -= curr;
		
		if(extra < 0)
			return -i;
		++i;
	}
	return year_extra * 6 / 5 + extra;
}

int main()
{
	printf("%d\n", process_money());
	return 0;
}
