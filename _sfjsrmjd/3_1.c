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

	for(j = i - 1; j >= 0; --j) {
		if(first) {
			printf(" ");
		} else {
			first = 1;
		}
		printf("%d", arr[j]);
	}
	printf("\n");

    return 0;
}
