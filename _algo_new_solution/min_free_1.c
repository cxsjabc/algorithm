#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define N		1000000
int f[N];

int	get_min_free(int a[], int size, int max)
{
	int *pf;
	int i;
	
	pf = f;
	if(max > N) {
		pf = (int *)malloc(max * sizeof(int));
		if(!f)
			return -1;
	} else
		max = N;

	for(i = 0; i < size; ++i) {
		pf[i] = 0;
	}		
	for(i = 0; i < size; ++i) {
		if(a[i] < max)
			pf[a[i]] = 1;
	}
	for(i = 0; i < max; ++i) {
		if(pf[i] == 0) {
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
