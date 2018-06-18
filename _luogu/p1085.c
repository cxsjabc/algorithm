#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int	is_jinjin_happy()
{
	int t1, t2;
	int n = 0, i = 1;
	int s = -1;

	while(scanf("%d%d", &t1, &t2) == 2) {
		if(t1 + t2 > 8 && t1 + t2 > s) {
			s = t1 + t2, n = i;
		}
		++i;
	}
	return n;
}

int main()
{
	printf("%d\n", is_jinjin_happy());
	return 0;
}
