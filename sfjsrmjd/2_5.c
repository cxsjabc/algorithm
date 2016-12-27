#include <stdio.h>

int main()
{
	int n;
	int min, max; 
	double average;
	double sum = 0;
	int i = 0;
	
	// redirect stdin/stdout from file or to file
	freopen("2_5.in", "r", stdin);
	freopen("2_5.out", "w", stdout);

	while(scanf("%d", &n) == 1) {
		sum += n;
		if(i == 0) {
			min = max = n;
		} else {
			if(n < min)
				min = n;
			if(n > max)
				max = n;
		}				 
		++i;
	}
	average = sum / i;

    printf("min:%d, max:%d, average:%.3f\n", min, max, average);
    return 0;
}
