#define LOG_LEVEL 20 
#include "common.h"

int arr[1000][10];

int main()
{
	int n;
	while(1) {
	if(scanf("%d", &n) != 1)
		break;
	memset(arr, 0, sizeof(arr));
	arr[0][1] = 1;
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < 10; ++j) {
			arr[i][j] = arr[i - 1][j];			
			log_v("arr[%d][%d]=%d\n", i, j, arr[i][j]);
		}
		
		int value = i + 1;	
		while(value > 0) {
			arr[i][value % 10]++;
			value /= 10;
		}		
	}
	
	for(int i = 0; i < 10; ++i)
		printf("%d ", arr[n - 1][i]);
	printf("\n");
	}

    return 0;
}
