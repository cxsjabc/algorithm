#include <stdio.h>
#include <limits.h>

#include "common_local.h"

//#define PN(n)	printf(#n " is %d\n", (n));

// just copied, not verified
int min_sub_seq_sum(int arr[], int cnt, int *start, int *end)
{
	int ret;
	int min = arr[0], temp_min;
	int i, j;

	*start = *end = 0;
	for(i = 0; i < cnt; ++i)
	{
		temp_min = arr[i];
		for(j = i; j < cnt; ++j)
		{	
			if(j > i) {
				temp_min += arr[j];
				if(temp_min > min) {
					*start = i;
					*end = j;
					min = temp_min;
				}
			} else {
				if(temp_min > min) {
					*start = i;
					*end = j;
					min = temp_min;
				}	
			}		
		}
	}
	return min;
}

// just copied, not verified
int min_sub_seq_sum1(int arr[], int cnt, int *ps, int *pe, int start, int end)
{
	int middle, min_left_sum, min_right_sum;
	int min_left_border_sum, min_right_border_sum;
	int left_border_sum, right_border_sum;
	int i, j;
	int min_ps_left, min_pe_left;
	int min_ps_right, min_pe_right;
	int min_ps_border, min_pe_border;
	int min_value;

	if(start == end) {
		return arr[start];
	}	

	middle = (start + end) / 2;
	min_left_sum = min_sub_seq_sum1(arr, cnt, &min_ps_left, &min_pe_left, start, middle);
	min_right_sum = min_sub_seq_sum1(arr, cnt, &min_ps_right, &min_pe_right, middle + 1, end);

	min_left_border_sum = arr[middle];
	left_border_sum = arr[middle];
	min_ps_border = middle;
	for(i = middle - 1; i >= start; --i) {	
		left_border_sum += arr[i];
		if(left_border_sum > min_left_border_sum) {
			min_left_border_sum = left_border_sum;
			min_ps_border = i;
		}
	}
	
	min_right_border_sum = arr[middle + 1];
	right_border_sum = arr[middle + 1];
	min_pe_border = middle + 1;
	for(i = middle + 2; i <= end; ++i) {	
		right_border_sum += arr[i];
		if(right_border_sum > min_right_border_sum) {
			min_right_border_sum = right_border_sum;
			min_pe_border = i;
		}
	}
	min_value = MAX3(min_left_sum, min_right_sum, min_left_border_sum + min_right_border_sum);
	if(min_value == min_left_sum)
		*ps = min_ps_left, *pe = min_pe_left;
	if(min_value == min_right_sum)
		*ps = min_ps_right, *pe = min_pe_right;
	if(min_value == min_left_border_sum + min_right_border_sum)
		*ps = min_ps_border, *pe = min_pe_border;
	return min_value;
}

int min_sub_seq_sum2(int arr[], int cnt)
{
	int min;
	int temp_min;
	int i;
	min = arr[0];
	temp_min = 0;

	for(i = 0; i < cnt; ++i) {
		temp_min += arr[i];
		if(temp_min < min)
			min = temp_min;
		else if(temp_min > 0)
			temp_min = 0;
	}
	return min;
}

// not ok
int min_positive_sub_seq_sum2(int arr[], int cnt)
{
	int min;
	int temp_min;
	int i;
	min = INT_MAX;
	temp_min = 0;

	for(i = 0; i < cnt; ++i) {
		temp_min += arr[i];
		if(temp_min < min && temp_min > 0)
			min = temp_min;
		else if(temp_min > 0)
			temp_min = 0;
	}
	return min;
}

int main()
{
	int arr[] = {12, -14, 1, 20, -34, 4, -5, 1};
	int cnt = sizeof(arr) / sizeof(arr[0]);
	int min, start, end;
#if 0
	min = min_sub_seq_sum(arr, cnt, &start, &end);
	PN(min);
	PN(start);
	PN(end);	
#endif

#if 0
	min = -1;
	start = end = -1;
	min = min_sub_seq_sum1(arr, cnt, &start, &end, 0, cnt - 1);
	PN(min);
	PN(start);
	PN(end);	
#endif

#if 0
	min = -1;
	start = end = -1;
	min = min_sub_seq_sum2(arr, cnt);
	PN(min);
#endif

	min = -1;
	start = end = -1;
	min = min_positive_sub_seq_sum2(arr, cnt);
	PN(min);

	return 0;
}
