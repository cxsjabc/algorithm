#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int is_fit_triangle(unsigned long long a, unsigned long long b, unsigned long long c)
{
	return (a + b > c) && (b + c > a) && (a + c > b);	
}

int main()
{
	long a, b, c;
	int ret;
	
	scanf("%ld%ld%ld", &a, &b, &c);
	ret = is_fit_triangle(a, b, c);
	printf("%s", ret == 1 ? "yes" : "no");
	return 0;
}
