/* bugs */
#include "common_local.h"

void	select_data(int arr[], int size, int begin, int index, int num, int *p)
{
	if(index == num)
		print_arr(p, num);
	else {
		int i;

		for(i = begin; i <= size - num + index; ++i) {
			p[index] = arr[i];
			select_data(arr, size, i + 1, index + 1, num, p);
		}
	}
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int p[128];	

	select_data(arr, sizeof(arr) / sizeof(arr[0]), 0, 0, 4, p);	

    return 0;
}
