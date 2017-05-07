#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

void reverse_arr(int a[], int size)
{
	int i = 0;
	for(; i < size / 2; ++i) {
		int temp = a[i];
		a[i] = a[size - 1 - i];
		a[size - 1 - i] = temp;
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
	reverse_arr(a, 10);
	for(i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
