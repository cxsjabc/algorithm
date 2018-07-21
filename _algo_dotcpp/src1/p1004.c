#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define N	55
int arr[N];

int get_cow_count(int n)
{
	int i;

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 4;

	for(i = 5; i <= n; ++i) {
		arr[i] = arr[i - 1] + arr[i - 3];
	}
	return arr[n];
}

int main()
{
	int n;
	
	while(scanf("%d", &n) > 0 && n != 0) {
		printf("%d\n", get_cow_count(n));
	}

	return 0;
}
