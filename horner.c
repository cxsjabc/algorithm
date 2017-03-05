#include <stdio.h>

#include "common_local.h"

// the array:  arr[0] + arr[1] x + arr[2] x^2 + ... + arr[cnt - 1] x ^ (cnt - 1)
int horner(int arr[], int cnt, int x)
{
	int result = 0;
	int i;

	for(i = cnt - 1; i >= 0; --i) {
		result = result * x + arr[i];
	}
	return result;
}

int main()
{
	int arr[] = {2, 1, 0, 8, 4};
	int size = ARR_SIZE(arr);
	PN(horner(arr, size, 3));
	
	return 0;
}
