#include <stdio.h> 

#define 	N 		12
#define 	MONEY	300

int main()
{
	int arr[N];
	int i;
	int sum = 0;
	int curr = 0;
	int not_enough;

	for(i = 0; i < N; ++i)
		scanf("%d", &arr[i]);

	for(i = 0; i < N; ++i) {
		int temp = MONEY + curr - arr[i];
		if(temp < 0) {
			not_enough = i;
			printf("-%d\n", not_enough + 1);
			return 0;
		} else if(temp >= 100) {
			curr = temp % 100;
			sum += temp - curr;
		} else
			curr = temp;
	}
	
	sum += sum / 5;
	sum += curr;
	printf("%d\n", sum);
    return 0;
}
