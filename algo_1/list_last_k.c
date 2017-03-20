#include "common_local.h"

int main()
{
#define N	10
	int arr[128];
	LHead h;
	int index;
	scanf("%d", &index);
	
	gen_basic_sorted_arr(arr, N, 1, 100);
	h = list_create_from_arr(arr, N);
	if(h) {
		if(index < N) {
			int data, ret;
			ret = list_get(h, N - index, &data);
			if(ret == 1) {
				PN(data);
			}
		}
		list_show(h);
		list_free(h);
	}

    return 0;
}
