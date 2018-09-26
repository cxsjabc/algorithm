#include "common_local.h"

void print_queen_arr(int arr[])
{
	int i, j;

	for(i = 0; i < 8; ++i) {
		for(j = 0; j < 8; ++j) {
			if(arr[i] != j)
				printf("#");
			else
				printf("*");
		}
		printf("\n");
	}
	printf("\n");
}

int	check_pos(int arr[], int index, int i)
{
	int j;

	for(j = 0; j < index; ++j) {
		if(arr[j] == i)
			return 0;

		if(j + arr[j] == index + i)
			return 0;

		if(j - arr[j] == index - i)
			return 0;
	}	

	return 1;
}

void eight_queen(int arr[], int index)
{
	int i;

	if(index == 8) {
		print_queen_arr(arr);
		return;
	}

	for(i = 0; i < 8; ++i) {
		if(check_pos(arr, index, i)) {
			arr[index] = i;
			eight_queen(arr, index + 1);
			arr[index] = 0;
		}
	}
}

int main()
{
	// arr[i]: the queen index of row i 
	int arr[8] = {0};

	eight_queen(arr, 0);	
    return 0;
}
