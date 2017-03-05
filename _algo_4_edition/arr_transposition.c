#include "common_local.h"

void arr_transposition(int *arr, int row, int col)
{
	int i, j;
	int *trans_arr;

	trans_arr = (int *)malloc(col * row * sizeof(int));

	for(i = 0; i < row; ++i) {
		for(j = 0; j < col; ++j) {
			trans_arr[j * col + i] = arr[i * row + j];
		}
	}
	for(i = 0; i < col; ++i) {
		for(j = 0; j < row; ++j) {
			printf("%d ", trans_arr[i * col + j]);
		}
		printf("\n");
	}
	printf("\n");
	
}

int main()
{
	int arr[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	arr_transposition(arr, 4, 4);	

    return 0;
}
