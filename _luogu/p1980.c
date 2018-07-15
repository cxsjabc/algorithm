#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int	get_digit_count(int n, int d)
{
	int cnt = 0;

	while(n) {
		if(n % 10 == d)
			++cnt;
		n /= 10;
	}
	return cnt;
}

int main()
{
	int n, x;
	int cnt = 0;

	scanf("%d%d", &n, &x);
	while(n >= 1) {
		cnt += get_digit_count(n, x);
		--n;
	}

	printf("%d\n", cnt);
	return 0;
}
