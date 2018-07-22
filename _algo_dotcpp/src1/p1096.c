#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

#define M	100
#define N	100
char arr[M][N];
char out_arr[M][N];

void show_arr(char arr[M][N], int m, int n)
{
	int i, j;

	for(i = 0; i < m; ++i) {
		for(j = 0; j < n; ++j) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void cal_mine_count(char arr[M][N], int m, int n, char out_arr[M][N], int i, int j)
{
	int cnt = 0;

	if(arr[i][j] == '*') {
		out_arr[i][j] = '*';
		return;
	}
	out_arr[i][j] = 0;
	if(i - 1 >= 0 && i - 1 < m) {
		if(j - 1 >= 0 && j - 1 < n && arr[i - 1][j - 1] == '*')
			++cnt;
		if(j >= 0 && j < n && arr[i - 1][j] == '*')
			++cnt;
		if(j + 1 >= 0 && j + 1 < n && arr[i - 1][j + 1] == '*')
			++cnt;
	}
	if(i >= 0 && i < m) {
		if(j - 1 >= 0 && j - 1 < n && arr[i][j - 1] == '*')
			++cnt;
		if(j + 1 >= 0 && j + 1 < n && arr[i][j + 1] == '*')
			++cnt;
	}
	if(i + 1 >= 0 && i + 1 < m) {
		if(j - 1 >= 0 && j - 1 < n && arr[i + 1][j - 1] == '*')
			++cnt;
		if(j >= 0 && j < n && arr[i + 1][j] == '*')
			++cnt;
		if(j + 1 >= 0 && j + 1 < n && arr[i + 1][j + 1] == '*')
			++cnt;
	}
	out_arr[i][j] = cnt + '0';
}

void cal_mines_count(char arr[M][N], int m, int n, char out_arr[M][N])
{
	int i, j;

	for(i = 0; i < m; ++i) {
		for(j = 0; j < n; ++j) {
			cal_mine_count(arr, m, n, out_arr, i, j);
		}
	}
}

void show_mines_count(char arr[M][N], int m, int n, int index)
{
	int i, j;

	printf("Field #%d:\n", index);
	for(i = 0; i < m; ++i) {
		for(j = 0; j < n; ++j) {
			printf("%c", arr[i][j]);	
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int m, n;
	int i, j;
	int index = 0;

	while(INPUT2(m, n) == 2 && m != 0 && n != 0) {
		for(i = 0; i < m; ++i) {
			for(j = 0; j < n; ++j) {
				char c = getchar();
				if(c == '\n')
					c = getchar();
				arr[i][j] = c;
			}
		}
		//show_arr(arr, m, n);
		//exit(0);
		// calculate the mines count
		cal_mines_count(arr, m, n, out_arr);
		++index;
		show_mines_count(out_arr, m, n, index);
	}

	return 0;
}
