#include <stdio.h>

int main()
{
	int num_count, n;
	int min, max; 
	double average;
	double sum;
	int i;
	int group = 0;
	
	// redirect stdin/stdout from file or to file
	freopen("2_5_1.in", "r", stdin);
	freopen("2_5_1.out", "w", stdout);

	while(scanf("%d", &num_count) == 1) {
		if(num_count == 0)
			break;
		sum = 0;
		for(i = 0; i < num_count; ++i) {
			scanf("%d", &n);
			sum += n;
			if(i == 0) {
				min = max = n;
			} else {
				if(n < min)
					min = n;
				if(n > max)
					max = n;
			}				
		} 
		average = sum / i;
		if(group)
			printf("\n");
    	printf("Case %d:%d %d %.3f\n", ++group, min, max, average);

	}
    return 0;
}
