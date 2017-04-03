#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int uni_speed[] = 
{
	7960, 11200, 16700, 115000, 2000000,
};

int main()
{
	long long v;
	int i = 0;
	int first = 0;

	scanf("%lld", &v);
	printf("%lld", v);
	while(i < sizeof(uni_speed) / sizeof(uni_speed[0])) {
		if(v >= uni_speed[i]) {
			if(!first)
				printf(" "), first = 1;
			printf("%d", i + 1);
		}
		else
			break;
		++i;
	}	
	if(i == 0)
		printf(" 0\n");
	else
		printf("\n");
	return 0;
}
