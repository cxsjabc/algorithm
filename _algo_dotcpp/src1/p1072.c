#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

int get_result(int n)
{
	int r = 0;

	while(n > 1) {
		if(n == 2) {
			r++;
			break;
		}
		r += (n / 3);
		n = (n - n / 3 * 3) + n / 3;
	}
	return r;
}

int main()
{
	int n;

	while(scanf("%d", &n) == 1 && n != 0) {
		printf("%d\n", get_result(n));
	}

	return 0;
}
