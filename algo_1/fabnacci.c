#include <stdio.h>

#include "common.h"

int fabnaci_arr[128];

void fabnaci(int n)
{
	int i = 0;
	fabnaci_arr[0] = fabnaci_arr[1] = 1;

	for(i = 2; i < 128; ++i) {
		fabnaci_arr[i] = fabnaci_arr[i - 1] + fabnaci_arr[i - 2];
	}
}

int	validate_smaller(int arr[], int size, int multi)
{
	int i = 0;

	for(; i < size - 1; ++i) {
		if(arr[i] * multi > arr[i + 1])
			return 0;
	}
	return 1;
}

int main()
{
	fabnaci(128);
	print_arr(fabnaci_arr, 128);

	// validate next element is not 2 times than the previous element
	PN(validate_smaller(fabnaci_arr, 128, 2));	

	return 0;
}
