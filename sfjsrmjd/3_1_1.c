#include <stdio.h>

int main()
{
	int arr[101];
	int i = 0, j;
	int n;
	int first = 0;

	while(scanf("%d", &n) == 1) {
		arr[i++] = n;
	}

	for(j = i - 1; j >= 1; --j) {
		printf("%d ", arr[j]);
	}
	printf("%d", arr[0]);
	printf("\n");

    return 0;
}
