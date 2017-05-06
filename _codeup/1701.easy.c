#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

unsigned long long get_sum(int n)
{
	const int a = 2;
	int v = 2;
	int i = 2;
	unsigned long long sum = a;

	while(i <= n) {
		v = 10 * v + a;
		sum += v;
		++i;
	}
	return sum;
} 

int main()
{
	int n;
	scanf("%d", &n);
	printf("%llu\n", get_sum(n));
	return 0;
}
