#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define HEIGHT	30

int get_taotao_apples(int arr[], int size, int taotao_height)
{
	int cnt = 0;

	while(--size >= 0) {
		if(arr[size] <= taotao_height + HEIGHT)
			++cnt;
	}
	return cnt;
}

int main()
{
	int arr[10];
	int i, height;

	for(i = 0; i < 10; ++i)
		scanf("%d", &arr[i]);
	scanf("%d", &height);

	printf("%d\n", get_taotao_apples(arr, 10, height));
	return 0;
}
