#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define N			1000000
#define INT_LEN		(sizeof(int) * 8)

int f[N / INT_LEN + 1];

void setbit(int *bits, int i)
{
	bits[i / INT_LEN] |= (1 << (i % INT_LEN));
}

void clearbit(int *bits, int i)
{
	bits[i / INT_LEN] &= ~(1 << (i % INT_LEN));
}

int testbit(int *bits, int i)
{
	int r = ((bits[i / INT_LEN] & (1 << (i % INT_LEN))) != 0) ? 1 : 0;
	return r;
}

int	get_min_free(int a[], int size, int max)
{
	int *pf;
	int i;
	int bit_max;
	
	pf = f;
	if(max > N) {
		bit_max = max / INT_LEN + 1;
		pf = (int *)malloc(bit_max * sizeof(int));
		if(!f)
			return -10;
	} else
		bit_max = N / INT_LEN + 1, max = N;

	memset(pf, 0, sizeof(int) * bit_max);
	for(i = 0; i < size; ++i) {
		if(a[i] < max)
			setbit(pf, a[i]);
	}
	for(i = 0; i < max; ++i) {
		//printf("bit%d=%d\n", i, testbit(pf, i));
		if(testbit(pf, i) == 0) {
			if(max > N)
				free(pf);
			return i;
		}
	}
	return -1;
}

int main()
{
	int a[] = {18, 4, 8, 9, 16, 1, 14, 7, 19, 3, 0, 5, 2, 11, 6};	
	int min;
	
	min = get_min_free(a, sizeof(a) / sizeof(a[0]), 100);
	printf("%d\n", min);
	return 0;
}
