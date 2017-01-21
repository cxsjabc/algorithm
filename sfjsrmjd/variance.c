#include "common.h"

int main()
{
	int cnt;
	int i;
	int arr[128];
	int j = 0;
	int sum = 0;
	double avg;
	double temp = 0;
	double variance;

	scanf("%d", &cnt);	
	i = cnt;
	while(i-- > 0) {
		scanf("%d", &arr[j]);
		sum += arr[j];
		++j;
	}

	avg = 1.0 * sum / cnt;
	for(i = 0; i < cnt; ++i) {
		temp += (arr[i] - avg) * (arr[i] - avg);
	}	

	variance = sqrt(temp / cnt);
	printf("variance:%f\n", variance);
    return 0;
}
