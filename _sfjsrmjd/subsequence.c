#include <stdio.h>

int main()
{
	long long n, m;
	int i = 0;
	freopen("subsequence.in", "r", stdin);
	freopen("subsequence.out", "w", stdout);

	while(scanf("%lld%lld", &n, &m) == 2 && !(n == 0 && m == 0)) {
		double sum = 0;
		while(n <= m) {
			sum += (1.0 / (n * n));
			++n;
		}
		if(i)
			printf("\n");
		printf("Case %d: %.5f", i + 1, sum);
		++i;
	}
    return 0;
}
