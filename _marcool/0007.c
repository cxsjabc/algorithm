#include <stdio.h> 

#define		N		15
int arr[N][N];
int get_leibnizs_triangle(int row, int col)	// row, col is from 0
{
	int i, j;
	for(i = 0; i < N; ++i) {
		arr[i][0] = i + 1;
		for(j = 1; j <= i; ++j) {
			arr[i][j] = arr[i][j - 1] * arr[i - 1][j - 1] / (arr[i][j - 1] - arr[i - 1][j - 1]);
		}
	}	
	return arr[row][col];
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	printf("1/%d\n", get_leibnizs_triangle(n - 1, m - 1));
    return 0;
}
