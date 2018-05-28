#include "common_local.h"

int horner(int arr[], int size, int x)
{
	int i = size - 1;
	int s = arr[size - 1];

	while(i > 0) {
		s = s * x + arr[i - 1];
		--i;
	}	
	return s;
}

int main()
{
	int arr[] = {-5, 1, -3, -1, 2};
	int size = ARR_SIZE(arr);

	PD(horner(arr, size, 3));
    return 0;
}
