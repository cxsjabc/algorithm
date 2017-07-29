/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include "common_local.h"

static 	void	set_0_1_bag_arr(int *arr, int r, int c, int rc, int v)
{
	*(arr + r * rc + c) = v;
}

static 	int		get_0_1_bag_arr(int *arr, int r, int c, int rc)
{
	return *(arr + r * rc + c);
}

// seems bugs
void	dp_0_1_bag(const int cnt, const int W, int *arr, int *v, int *w)
{
	int i, j;

	memset(arr, 0, sizeof(int) * (cnt + 1) * W);

	for(i = 1; i <= cnt; ++i) {
		set_0_1_bag_arr(arr, i, 0, W, 0);
		//*(arr + (i * W)) = 0;
		for(j = 1; j <= W; ++j) {
			if(w[i - 1] > j)
				set_0_1_bag_arr(arr, i, j, W, get_0_1_bag_arr(arr, i - 1, j, W));
			else {
				int m1, m2;
				m1 = get_0_1_bag_arr(arr, i - 1, j - w[i - 1], W) + v[i - 1];
				m2 = get_0_1_bag_arr(arr, i - 1, j, W);
				if(m1 > m2)
					set_0_1_bag_arr(arr, i, j, W, m1);
				else
					set_0_1_bag_arr(arr, i, j, W, m2);
			}
				
		}
	}
	
}

int main()
{
	int cnt = 5;
	int W = 17;
	int v[] = {4, 5, 10, 11, 13};
	int w[] = {3, 4, 7, 8, 9};
	int arr[10][100];
	int i, j;
	int *p;

	p = (int *)arr;
	dp_0_1_bag(cnt, W, p, v, w);

	for(i = 0; i <= cnt; ++i) {
		for(j = 0; j <= W; ++j)
			log_d("%3d ", get_0_1_bag_arr(p, i, j, W));
		log_d("\n");
	}

    return 0;
}
