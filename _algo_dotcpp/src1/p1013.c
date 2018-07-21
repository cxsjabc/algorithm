#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int get_result(int n)
{
	int r = 2;
	int sum = 0;

	while(n > 0) {
		sum += r;
		r = r * 10 + 2;
		--n;
	}
	return sum;
}

int main()
{
	int n;

	scanf("%d", &n);

	printf("%d\n", get_result(n));
	return 0;
}
