#include <stdio.h>

int arr[1001] = {0};

int main()
{
	int n, k;
	int i, j;
	scanf("%d%d", &n, &k);

	for(i = 1; i <= k; ++i) {
		for(j = 1; j <= n; ++j) {
			if(j % i == 0)
				arr[j] = !arr[j];
		}
	}
	for(i = 1; i <= n; ++i) { 
    	if(arr[i])
			printf("%d ", i);
	}
	printf("\n");
    return 0;
}
