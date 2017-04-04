#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

// eg: n:12232, dig:2, the result: 3
int get_dig_cnt(int n, int dig) 
{
	int i = 0;
	int a[10] = {0};
	
	if(n == 0 && dig == 0)
		return 1;

	while(n != 0) {
		a[n % 10]++;
		n /= 10;
	}	
	return a[dig];
}

int main()
{
	int m, n;
	int i;
	int cnt = 0;

	scanf("%d%d", &m, &n);
	for(i = m; i <= n; ++i) {
		cnt += get_dig_cnt(i, 2);
	}	

	printf("%d\n", cnt);
	return 0;
}
