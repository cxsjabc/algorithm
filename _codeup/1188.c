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
	int a[4];
	int i = 0;
	int first = 1;

	while(i < 4) {
		scanf("%d", &a[i++]);
	}

	bubble_sort(a, 4);
	for(i = 0; i < 4; ++i) {
		if(first)
			first = !first;
		else
			printf(" ");
		printf("%d", a[i]);	
	}

	printf("\n");

	return 0;
}
