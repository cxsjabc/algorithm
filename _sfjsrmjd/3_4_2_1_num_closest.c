#include "common_local.h"

int main()
{
	int i, j;
	int arr[] = {100, 20, 6, 1, 1000, 999, 997};
	int size = sizeof(arr) / sizeof(arr[0]);
	int closest;

	if(size < 2)
		return -1;

	closest = abs(arr[1] - arr[0]);

	for(i = 0; i < size; ++i) {
		for(j = i + 1; j < size; ++j) {
			if(abs(arr[i] - arr[j]) < closest)
				closest = abs(arr[i] - arr[j]);
		}
	}

	printf("closest:%d\n", closest);

    return 0;
}
