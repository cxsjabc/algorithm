#include "common_local.h"

void matrix_mul(int *arr, int i, int j, int *arr1, int j1, int k, int *out)
{
	int m, n, p;

	for(m = 0; m < i; ++m) {
		for(n = 0; n < k; ++n) {
			for(p = 0; p < j; ++p) {
				*(out + k * m + n) += *(arr + j * m + p) * *(arr1 + p * k + n);
			}
		}
	}	
}

int main()
{
	int arr[2][3] = {1, 2, 3, 4, 5, 6};
	int arr1[3][2] = {1, 2, 3, 4, 5, 6};
	int out[2][2] = {0};
	int i, j;

	matrix_mul((int *)arr, 2, 3, (int *)arr1, 3, 2, (int *)out);
	
	for(i = 0; i < 2; ++i) {
		for(j = 0; j < 2; ++j) {
			printf("%d ", out[i][j]);
		}
		printf("\n");
	}
	printf("\n");

    return 0;
}
