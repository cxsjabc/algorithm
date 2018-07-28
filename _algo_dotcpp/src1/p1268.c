#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

#define N	10000
long arr[N];

int cmp(const void *p1, const void *p2)
{
	const int *i1 = (const int *)p1;
	const int *i2 = (const int *)p2;

	return *i1 - *i2;
}

long get_result(int n, int k)
{
	qsort(arr, n, sizeof(long), cmp);
	return arr[n - k] - arr[k - 1];
}

int	is_prime(long n)
{
	long sq;

	if(n <= 1)
		return 0;

	sq = sqrt(n);
	
	while(sq >= 2) {
		if(n % sq == 0)
			return 0;
		--sq;
	}
	return 1;
}

int main()
{
	int n, k;
	int i;
	long m;

	INPUT2(n, k);

	for(i = 0; i < n; ++i)
		scanf("%ld", &arr[i]);	

	m = get_result(n, k);
	printf("%s\n%ld\n", is_prime(m) ? "YES" : "NO", m);

	return 0;
}
