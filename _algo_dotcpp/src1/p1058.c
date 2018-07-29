#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

int main()
{
	int n;
	long long sum = 0;

	INPUT(n);
	while(n--) {
		int temp;
		INPUT(temp);
		if(temp % 2 == 0)
			sum += temp;
	}
	printf("%lld\n", sum);
	return 0;
}
