#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int	get_min_free(int a[], int size, int max)
{
	int *f;
	int i;

	f = (int *)malloc(max * sizeof(int));
	if(!f)
		return -1;
	for(i = 0; i < size; ++i) {
		f[i] = 0;
	}		
	for(i = 0; i < size; ++i) {
		if(a[i] < max)
			f[a[i]] = 1;
	}
	for(i = 0; i < max; ++i) {
		if(f[i] == 0) {
			free(f);
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
