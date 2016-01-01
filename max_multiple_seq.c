#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#include "common.h"

//#define PN(n)	printf(#n " is %d\n", (n));
// just copied, not verified
int max_mul_seq_sum(int arr[], int cnt, int *start, int *end)
{
	int ret;
	int max = arr[0], temp_max;
	int i, j;

	*start = *end = 0;
	for(i = 0; i < cnt; ++i)
	{
		temp_max = arr[i];
		for(j = i; j < cnt; ++j)
		{	
			if(j > i) {
				temp_max += arr[j];
				if(temp_max > max) {
					*start = i;
					*end = j;
					max = temp_max;
				}
			} else {
				if(temp_max > max) {
					*start = i;
					*end = j;
					max = temp_max;
				}	
			}		
		}
	}
	return max;
}

// just copied, not verified
int max_mul_seq_sum1(int arr[], int cnt, int *ps, int *pe, int start, int end)
{
	int middle, max_left_sum, max_right_sum;
	int max_left_border_sum, max_right_border_sum;
	int left_border_sum, right_border_sum;
	int i, j;
	int max_ps_left, max_pe_left;
	int max_ps_right, max_pe_right;
	int max_ps_border, max_pe_border;
	int max_value;

	if(start == end) {
		return arr[start];
	}	

	middle = (start + end) / 2;
	max_left_sum = max_mul_seq_sum1(arr, cnt, &max_ps_left, &max_pe_left, start, middle);
	max_right_sum = max_mul_seq_sum1(arr, cnt, &max_ps_right, &max_pe_right, middle + 1, end);

	max_left_border_sum = arr[middle];
	left_border_sum = arr[middle];
	max_ps_border = middle;
	for(i = middle - 1; i >= start; --i) {	
		left_border_sum += arr[i];
		if(left_border_sum > max_left_border_sum) {
			max_left_border_sum = left_border_sum;
			max_ps_border = i;
		}
	}
	
	max_right_border_sum = arr[middle + 1];
	right_border_sum = arr[middle + 1];
	max_pe_border = middle + 1;
	for(i = middle + 2; i <= end; ++i) {	
		right_border_sum += arr[i];
		if(right_border_sum > max_right_border_sum) {
			max_right_border_sum = right_border_sum;
			max_pe_border = i;
		}
	}
	max_value = MAX3(max_left_sum, max_right_sum, max_left_border_sum + max_right_border_sum);
	if(max_value == max_left_sum)
		*ps = max_ps_left, *pe = max_pe_left;
	if(max_value == max_right_sum)
		*ps = max_ps_right, *pe = max_pe_right;
	if(max_value == max_left_border_sum + max_right_border_sum)
		*ps = max_ps_border, *pe = max_pe_border;
	return max_value;
}

int max_mul_seq_sum2(int arr[], int cnt)
{
	int i;
	int max, min;
	int *max_arr = (int *)malloc(sizeof(int) * cnt);
	int *min_arr = (int *)malloc(sizeof(int) * cnt);

	max_arr[0] = min_arr[0] = arr[0];
	max = min = arr[0];
	for(i = 1; i < cnt; ++i) {
		max_arr[i] = MAX3(arr[i], max_arr[i - 1] * arr[i], min_arr[i - 1] * arr[i]);		
		min_arr[i] = MIN3(arr[i], max_arr[i - 1] * arr[i], min_arr[i - 1] * arr[i]);		
		if(max_arr[i] > max)
			max = max_arr[i];
	}

	free(max_arr);
	free(min_arr);
	return max;
}

int main()
{
	int arr[] = {12, -14, 1, 20, -34, 0, 1};
	int cnt = sizeof(arr) / sizeof(arr[0]);
	int max, start, end;
#if 0
	max = max_mul_seq_sum(arr, cnt, &start, &end);
	PN(max);
	PN(start);
	PN(end);	
#endif

#if 0
	max = -1;
	start = end = -1;
	max = max_mul_seq_sum1(arr, cnt, &start, &end, 0, cnt - 1);
	PN(max);
	PN(start);
	PN(end);	
#endif

	max = -1;
	start = end = -1;
	max = max_mul_seq_sum2(arr, cnt);
	PN(max);


	return 0;
}
