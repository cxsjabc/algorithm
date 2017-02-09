#include <stdio.h>
#include <string.h>

int is_arr_value(int arr[], int s, int e, int value)
{	
	int i = s;
	while(i <= e) {
		if(arr[i] != value)
			return 0;
		++i;
	}
	return 1;
}

int main()
{
	int j, k;
	int arr[10] = {0};
	for(int i = 123; i <= 329; ++i) {
		j = i * 2;
		k = i * 3;
		arr[i / 100]++;
		arr[i % 10]++;
		arr[i / 10 % 10]++;
		arr[j / 100]++;
		arr[j % 10]++;
		arr[j / 10 % 10]++;
		arr[k / 100]++;
		arr[k % 10]++;
		arr[k / 10 % 10]++;
		if(is_arr_value(arr, 1, 9, 1)) {
			printf("%d %d %d\n", i, j, k);
		}
		memset(arr, 0, sizeof(arr));
	}
	
    return 0;
}
