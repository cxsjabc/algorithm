#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

int main()
{
	int h, arr[10];
	int i = 0;
	int cnt = 0;

	while(i < 10) {
		scanf("%d", &arr[i]);
		++i;
	}
	scanf("%d", &h);

	for(i = 0; i < 10; ++i)
		if(arr[i] <= 30 + h)
			++cnt;
	printf("%d\n", cnt);

	return 0;
}
