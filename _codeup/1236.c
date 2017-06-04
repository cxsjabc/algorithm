#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int calc_age(int n, int k, int a)
{
	if(n == 1)
		return a;
	return calc_age(n - 1, k, a) + k;
}

int main()
{
	int n, k, a;
	int age;
	
	scanf("%d%d%d", &n, &k, &a);
	age = calc_age(n, k, a);
	printf("%d\n", age);
	return 0;
}
