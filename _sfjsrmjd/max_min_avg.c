#include "common_local.h"

int main()
{
	int n;
	int cnt = 0;
	int max, min;
	long long sum = 0;	// for avoid overflow...

	scanf("%d", &n);
	++cnt;
	max = min = sum = n;

	while(scanf("%d", &n) == 1) {
		if(n > max)
			max = n;
		else if(n < min)
			min = n;

		++cnt;
		sum += n;
	}

	printf("max:%d, min:%d, avg:%f\n", max, min, 1.0 * sum / cnt);

    return 0;
}
