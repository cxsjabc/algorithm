#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

void selection_sort(int a[], int size)
{
	int i, j;
	for(i = 0; i < size - 1; ++i) {
		int min = i;
		int temp;
		for(j = i + 1; j < size; ++j) {
			if(a[j] < a[min])
				min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}

int main()
{
	int n = 10;
	int i = 0;
	int a[10];

	while(i < n) {
		scanf("%d", &a[i]);
		++i;
	}
	selection_sort(a, n);
	for(i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
