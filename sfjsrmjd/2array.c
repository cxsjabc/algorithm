#include <stdio.h>

int main()
{
	int arr[2][2] = {1, 2, 3, 4};
	int **p = (int **)arr;
	int i;

	for(i = 0; i < 2; ++i) {
		printf("%d ", p[i]);
	}	
    printf("\n");
    return 0;
}
