#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

void bubble_sort(int a[], int size)
{
	int i, j;

	for(i = 0; i < size - 1; ++i) {
		for(j = size - 1; j > i; --j) {
			if(a[j] < a[j - 1]) {
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}

int main()
{
	int a[200];
	int i = 0;
	int n;

	scanf("%d", &n);
	while(i < n) {
		scanf("%d", &a[i++]);
	}

	bubble_sort(a, n);

	for(i = 0; i < n; ++i) {
		printf("%d ", a[i]);	
	}
	printf("\n");

	return 0;
}
