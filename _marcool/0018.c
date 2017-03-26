#include <stdio.h> 

int get_block_cnt(int level)
{
	int i = 2;
	int sum = 1;
	int prv = 1;

	while(i <= level) {
		prv += i;
		sum += prv;
		++i;
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", get_block_cnt(n));
	return 0;
}
