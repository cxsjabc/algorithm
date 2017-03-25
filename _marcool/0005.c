#include <stdio.h> 

int loud_cnt[10002];	// loud count per second, max is 100

int main()
{
	int n, a[11], b;
	int i;
	int sum_loud = 0;

	scanf("%d", &n);
	for(i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &b);

	for(i = 1; i <= n; ++i) {
		int j;
		for(j = 0; j < b; ++j)
			loud_cnt[1 + a[i] * j] = 1;	
	}
	for(i = 0; i < 10002; ++i)
		sum_loud += loud_cnt[i];	

	printf("%d", sum_loud);

    return 0;
}
