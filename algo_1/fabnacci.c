#define _LOG_LEVEL LOG_D
#include <stdio.h>

#include "common_local.h"

int fabnaci_arr[128];

void fabnaci(int n)
{
	int i = 0;
	fabnaci_arr[0] = fabnaci_arr[1] = 1;

	for(i = 2; i < 128; ++i) {
		fabnaci_arr[i] = fabnaci_arr[i - 1] + fabnaci_arr[i - 2];
	}
}

int fabnaci1(int n)
{
	int fab0 = 1, fab1 = 1;
	int i = 2;
	if(n == 0 || n == 1)
		return 1;
		
	while(i <= n) {
		int temp = fab1;
		fab1 = fab0 + fab1;
		fab0 = temp;
		log_v("fab1: %d, fab0:%d\n", fab1, fab0);	
		++i;
	}
	return fab1;
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
#if 0
	fabnaci(128);
	print_arr(fabnaci_arr, 128);

	// validate next element is not 2 times than the previous element
	PN(validate_smaller(fabnaci_arr, 128, 2));	
#endif

	PN(fabnaci1(128));
	return 0;
}
