#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

#define N	100

int arr[N][N];

void fill_arr(int arr[N][N], int n)
{
	int i;
	int v = 1;

	for(i = 0; i < n; ++i) {
		int j = i, k = 0;
		while(k <= i) {
			arr[j][k] = v++;
			--j, ++k;
		}
	}
}

void print_arr(int arr[N][N], int n)
{
	int i = 0;

	while(i < n) {
		int j = 0;
		while(j < (n - i))
			printf("%d ", arr[i][j]), ++j;
		printf("\n");
		++i;
	}
}

void show_result(int n)
{
	fill_arr(arr, n);	
	print_arr(arr, n);
}

int main()
{
	int n;

	while(INPUT(n) == 1)
		show_result(n);
	return 0;
}
