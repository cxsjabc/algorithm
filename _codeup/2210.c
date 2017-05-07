#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

void insert_to_arr(int a[], int size, int v)
{
	int i = 0;
	while(i <= size) {
		if(a[i] < v)
			++i;
		else
			break;
	}
	if(i == size)
		a[i] = v;
	else {
		int j = size - 1;
		while(j >= i) {
			a[j + 1] = a[j];
			--j;
		}
		a[i] = v;
	}		
}

int main()
{
	int a[10];
	int n = 9;
	int i = 0;
	int v;

	while(i < n) {
		scanf("%d", &a[i]);
		++i;
	}
	scanf("%d", &v);
	
	insert_to_arr(a, 9, v);
	for(i = 0; i < 10; ++i)
		printf("%d\n", a[i]);
	return 0;
}
