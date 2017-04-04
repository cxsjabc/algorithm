#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int	is_equal_diff_or_ratio(int a[], int size, int *value)
{
	int i = 2;
	int diff = a[1] - a[0];
	int ratio = a[1] / a[0];
	int diff_cnt = 0, ratio_cnt = 0;

	while(i < size) {
		if(a[i] - a[i - 1] == diff)
			diff_cnt++;
		if(a[i] / a[i - 1] == ratio)
			ratio_cnt++;
		++i;
	}	
	
	if(diff_cnt == size - 2) {
		*value = diff;
		return 1;
	}
	if(ratio_cnt == size - 2) {
		*value = ratio;
		return 2;
	}
	return 0;
}

int main()
{
	int n;
	int i = 0;
	int a[10];
	int value;
	int ret;

	scanf("%d", &n);
	for(; i < n - 1; ++i)
		scanf("%d", &a[i]);

	ret = is_equal_diff_or_ratio(a, n - 1, &value);
	if(ret == 1) {
		a[n - 1] = a[n - 2] + value;
		for(i = 0; i < n - 1; ++i)
		   printf("%d ", a[i]);
		printf("%d\n", a[n - 1]);
	}
	else if(ret == 2) {
		a[n - 1] = a[n - 2] * value;
		for(i = 0; i < n - 1; ++i)
		   printf("%d ", a[i]);
		printf("%d\n", a[n - 1]);
	} else 
		printf("Fatal: not euqal diff or equal ratio!\n");
	return 0;
}
