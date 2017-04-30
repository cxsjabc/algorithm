#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n;
	int s = 1;
	int i = 1;

	scanf("%d", &n);
	
	while(i < n) {
		s = (s + 1) * 2;
		++i;
	}
	printf("%d\n", s);
	return 0;
}
