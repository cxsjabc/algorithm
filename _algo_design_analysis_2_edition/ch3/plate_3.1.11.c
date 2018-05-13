#include "common_local.h"

void move_plate(int arr[], int size)
{
	int s = size - 1;
	int i = size - 1;

	while(s >= 0) {
		if(arr[s] == 0) {
			int temp = s;
			while(temp < i) {
				int temp1 = arr[temp];
				arr[temp] = arr[temp + 1];
				arr[temp + 1] = temp1;
				++temp;
			}
			if(s != temp)
				--i;
		}		

		--s;
	}
}

int main()
{
	int *arr;
	int n;
	int i;
	int size;

	scanf("%d", &n);
	if(n <= 0 || n % 2 != 0) {
		return -1;
	}

	arr = (int *)malloc(n * sizeof(int));
	assert(arr);

	// 0: black  1: white
	for(i = 0; i < n; i += 2) {
		arr[i] = 0;
		arr[i + 1] = 1;
	}	
	size = n;
	print_arr(arr, size);

	move_plate(arr, size);
	print_arr(arr, size);

	free(arr);
    return 0;
}
