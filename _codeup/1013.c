#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n, v;
	int i;
	int sum, avg;
	int arr[51];
	int move;

	while(1) {
		scanf("%d", &n);
		if(n == 0)
			break;
		sum = 0;
		move = 0;
		for(i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		avg = sum / n;

		for(i = 0; i < n; ++i) {
			if(arr[i] > avg)
				move += (arr[i] - avg);	
		}
		printf("%d\n", move);
	}
	return 0;
}
