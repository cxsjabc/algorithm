#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

#define	T	1000
#define	M	100

int time[M + 1];
int value[M + 1];
int arr[M + 1][T + 1];

#define max(a, b)	((a) > (b) ? (a) : (b))

int get_result(int t, int m)
{
	int i, j;

	for(i = 1; i <= m; ++i) {
		for(j = 1; j <= t; ++j) {
			if(j < time[i])
				arr[i][j] = arr[i - 1][j];
			else
				arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - time[i]] + value[i]);
		}
	}
	return arr[m][t];
}

int main()
{
	int t, m;
	int i = 1;

	INPUT2(t, m);
	while(i <= m) {
		scanf("%d%d", &time[i], &value[i]);
		++i;
	}	
	printf("%d\n", get_result(t, m));
	return 0;
}
