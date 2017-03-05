#define LOG_LEVEL DEBUG
#include "common_local.h"

// arr[0...size - 1]    x4 x3 x2... x0
int horner(int arr[], int size, int x)
{
	int ret = 0;
	int i;
	for(i = 0; i < size; ++i) {
		ret = ret * x + arr[i];
		log_v("temp ret:%d\n", ret);
	}
	return ret;
}

int main()
{
	int arr[] = {2, -1, -3, 1, -5};
	int x = 3;
	int ret;

	ret = horner(arr, sizeof(arr) / sizeof(arr[0]), x);
	PD(ret);	
	
    return 0;
}
