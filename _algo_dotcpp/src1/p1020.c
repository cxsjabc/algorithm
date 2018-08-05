#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

int get_result(int n)
{
	int r = 1;

	while(n > 1) {
		r = (r + 1) * 2;
		--n;
	}
	return r;
}

int main()
{
	int n;

	INPUT(n);
	printf("%d\n", get_result(n));
	return 0;
}
