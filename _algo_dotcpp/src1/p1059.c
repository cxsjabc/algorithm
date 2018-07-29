#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

long long get_result(int n)
{
	long long r = 2;
	long long temp = r;

	while(n > 1) {
		temp += 3;
		r += temp;
		--n;
	}
	return r;
}

int main()
{
	int n;

	INPUT(n);
	printf("%lld\n", get_result(n));
	return 0;
}
