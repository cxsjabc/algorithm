#include <stdio.h>

#include "common_local.h"

// each bit represents a number
// eg:  0 1 1 0 1 0 0 1   means numbers: 1 2 4 7
int print_bit_num(int arr[], int size)
{
	int i = 0;
	int cnt = 0;
	while(i < size) {
		int j = 7;
		while(j >= 0) {
			int value = arr[i] & (1 << j);
			if(value)
				++cnt, printf("%d ", i * 8 + (7 - j));
			--j;
		}
	
		++i;
	}	
	return cnt;
}

int main()
{
	// 0000 0001 0000 0010 0000 0011 0000 0100
	int arr[] = {1, 2, 3, 4};
	PN(print_bit_num(arr, ARR_SIZE(arr)));	
	return 0;
}
