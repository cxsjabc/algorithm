#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

unsigned long long get_result(int n)
{
	unsigned long long r = 0;
	unsigned long long t = 1;
	int i = 1;

	while(i <= n) {
		r += i * t;
		t = i * t;
		++i;
	}
	return r;
}

int main()
{
	int n;

	INPUT(n);
	printf("%llu\n", get_result(n));
	return 0;
}
