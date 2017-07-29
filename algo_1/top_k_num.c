/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include "common_local.h"

int		top_k_num(const int arr[], const int k, int i, int j, int *out_arr)
{
	int max;
	int m, n;
	int c = 0;
	int p = 0;	
	int max_index;
	int *flag;

	flag = (int *)malloc((j + 1) * sizeof(int));
	if(!flag)
		return -1;
	memset(flag, 0, sizeof(int) * (j + 1));

	while(c < k) {
		for(m = i; m <= j; ++m) {
			if(!flag[m])
				break; 
		}
		if(m >= j + 1) {
			free(flag);
			ASSERT(m < j + 1);
		}

		max = arr[m];
		for(n = i; n <= j; ++n) {
			if(arr[n] > max && !flag[n]) {
				max = arr[n];
				max_index = n;
			}
		}

		if(m != max_index)
			flag[max_index] = 1;
		out_arr[p++] = max;
	
		++c;
	}
	
	free(flag);
	return 0;	
}

int main()
{
#define	N	1000
#define	N1	5
	int arr[N];
	int k = N1;	
	int out_arr[N1];
	int ret;

	//gen_basic_sorted_arr(arr, N, 1, 10000);
	gen_basic_arr(arr, N, 1, 1000);
	ret = top_k_num(arr, k, 0, N - 1, out_arr);
	assert(ret >= 0);	

	print_arr(arr, N);
	log_d("Out array:\n");
	print_arr(out_arr, N1);

    return 0;
}
