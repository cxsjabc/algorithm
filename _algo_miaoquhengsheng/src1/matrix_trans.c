#include "common_local.h"

void input_matrix(int *arr, int r, int c)
{
	int i, j;
	for(i = 0; i < r; ++i) {
		for(j = 0; j < c; ++j) {
			scanf("%d", arr + i * c + j);
		}
	}
}

void output_matrix(int *arr, int r, int c)
{
	int i, j;
	for(i = 0; i < r; ++i) {
		for(j = 0; j < c; ++j) {
			printf("%d ", *(arr + i * c + j));
		}
		printf("\n");
	}
}

void trans_matrix(int *arr, int r, int c, int *out_arr)
{
	int i, j;
	for(i = 0; i < r; ++i) {
		for(j = 0; j < c; ++j) {
			*(out_arr + j * r + i) = *(arr + i * c + j);
		}
	}
}

int main()
{
	int arr[100][100], out_arr[100][100];

	input_matrix((int *)arr, 3, 4);	
	output_matrix((int *)arr, 3, 4);	
	trans_matrix((int *)arr, 3, 4, (int *)out_arr);
	output_matrix((int *)out_arr, 4, 3);	

    return 0;
}
