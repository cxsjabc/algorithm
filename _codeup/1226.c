#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n;
	int i;
	int arr[20][20];

	scanf("%d", &n);
	for(i = 0; i < n; ++i) {	
		int j;
		for(j = 0; j <= i; ++j) {
			if(j == 0 || j == i)
				arr[i][j] = 1, printf("1 ");
			else
				printf("%d ", arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j]);
		}
		printf("\n");
	}
	return 0;
}
